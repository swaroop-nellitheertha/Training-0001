#include <stdio.h>
#include <ctype.h> 
float calculateBill(char wardType, int days);

int main() {
    char patientName[50];
    char wardType;
    int days;
    float billBeforeDiscount, discount, finalBill;

    printf("Enter Patient Name: ");
    scanf(" %s", patientName);

    printf("Enter Ward Type (G/S/P): ");
    scanf(" %c", &wardType);
    wardType = toupper(wardType);
    printf("Enter Number of Days: ");
    scanf("%d", &days);

    billBeforeDiscount = calculateBill(wardType, days);

    if (days > 7) {
        discount = 0.05 * billBeforeDiscount;
        finalBill = billBeforeDiscount - discount;
    } else {
        discount = 0;
        finalBill = billBeforeDiscount;
    }

    printf("\nPatient Name: %s\n", patientName);
    printf("Total Bill Before Discount: ₹%.2f\n", billBeforeDiscount);
    printf("Discount Applied: ₹%.2f\n", discount);
    printf("Final Bill Amount: ₹%.2f\n", finalBill);

    return 0;
}

float calculateBill(char wardType, int days) {
    float bill = 0;

    switch (wardType) {
        case 'G':
            bill = 1000 * days;
            break;
        case 'S':
            bill = 2000 * days;
            break;
        case 'P':
            bill = 5000 * days;
            break;
        default:
            printf("Invalid ward type entered.\n");
            return 0;
    }
    return bill;
}
