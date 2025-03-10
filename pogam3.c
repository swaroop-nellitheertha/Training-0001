#include <stdio.h>

void calculate_electricity_bill() {
    char customer_name[100];
    int customer_id;
    int units_consumed;
    float fixed_charge = 100.0;
    float bill_amount = fixed_charge;
    float surcharge = 0.0;

    printf("Enter Customer Name: ");
    scanf(" %s", customer_name); // Read name with spaces

    printf("Enter Customer ID: ");
    scanf("%d", &customer_id);

    printf("Enter Total Units Consumed: ");
    scanf("%d", &units_consumed);

    if (units_consumed <= 100) {
        bill_amount += units_consumed * 5.0;
    } else if (units_consumed <= 300) {
        bill_amount += 100 * 5.0 + (units_consumed - 100) * 7.0;
    } else {
        bill_amount += 100 * 5.0 + 200 * 7.0 + (units_consumed - 300) * 10.0;
    }

    if (bill_amount > 1000) {
        surcharge = bill_amount * 0.05;
        bill_amount += surcharge;
    }

    printf("\nCustomer Name: %s\n", customer_name);
    printf("Customer ID: %d\n", customer_id);
    printf("Units Consumed: %d\n", units_consumed);
    printf("Base Bill: ₹%.2f\n", bill_amount - surcharge > 0 ? bill_amount - surcharge : bill_amount); // Base bill before surcharge
    if (surcharge > 0) {
        printf("Surcharge: ₹%.2f\n", surcharge);
    }
    printf("Total Bill: ₹%.2f\n", bill_amount);
}

int main() {
    calculate_electricity_bill();
    return 0;
}
