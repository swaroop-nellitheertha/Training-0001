#include <stdio.h>
#include <string.h>
struct Fiction_t {
    char title[250];
    char author[125];
    float price;
};
typedef struct Fiction_t Fiction;

struct NonFiction_t {
    char title[250];
    char subject[500];
    float price;
};
typedef struct NonFiction_t NonFiction;

union BookType_t {
    Fiction fiction;
    NonFiction nonfiction;
};
typedef union BookType_t BookType;

struct Book_t {
    int type;
    BookType booktype;
};
typedef struct Book_t Book;

Book books[1000];
int bookCount;

void addBooks();
void displayBooks();

int main() {
    addBooks();
    displayBooks();
    return 0;
}

void addBooks() {
    printf("Enter the number of books: ");
    scanf("%d", &bookCount);

    for (int i = 0; i < bookCount; i++) {
        printf("Type of book (1-Fiction, 2-Non-fiction): ");
        scanf("%d", &books[i].type);

        switch (books[i].type) {
            case 1: {
                printf("Enter Fiction Book Details (Title, Author, Price): ");
                scanf(" %249[^\n] %124[^\n] %f", books[i].booktype.fiction.title, books[i].booktype.fiction.author, &books[i].booktype.fiction.price); 
                break;
            }
            case 2: {
                printf("Enter Non-Fiction Book Details (Title, Subject, Price): ");
                scanf(" %249[^\n] %499[^\n] %f", books[i].booktype.nonfiction.title, books[i].booktype.nonfiction.subject, &books[i].booktype.nonfiction.price);
                break;
            }
            default:
                printf("Invalid book type.\n");
                i--;
                break;
        }
    }
}

void displayBooks() {
    for (int i = 0; i < bookCount; i++) {
        switch (books[i].type) {
            case 1: {
                printf("Fiction Book: Title: %s, Author: %s, Price: $%.2f\n", books[i].booktype.fiction.title, books[i].booktype.fiction.author, books[i].booktype.fiction.price);
                break;
            }
            case 2: {
                printf("Non-Fiction Book: Title: %s, Subject: %s, Price: $%.2f\n", books[i].booktype.nonfiction.title, books[i].booktype.nonfiction.subject, books[i].booktype.nonfiction.price);
                break;
            }
        }
    }
}
