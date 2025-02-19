#include <stdio.h>
void displayAges(short int* ages, int length, int index) {
    if (index >= length) {
        return;
    }
    printf("%d ", ages[index]);
    displayAges(ages, length, index + 1);
}
void travelBackwardAges(short int* ages, int length, int index) {
    if (index >= length) {
        return;
    }
    travelBackwardAges(ages, length, index + 1);
    printf("%d ", ages[index]);
}

int main() {
    short int ages[] = {45, 42, 14, 20, 70};
    
    printf("Ages in forward order: ");
    displayAges(ages, 5, 0);
    printf("\n");
    
    printf("Ages in backward order: ");
    travelBackwardAges(ages, 5, 0);
    printf("\n");
    
    return 0;
}
