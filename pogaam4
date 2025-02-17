#include <stdio.h>
#include <string.h>
#include <ctype.h>

float calculate_toll_tax(char vehicle_type[], int distance_traveled) {
    float base_charge;
    float discount = 0.0;

    // Convert vehicle type to lowercase for case-insensitive comparison
    for (int i = 0; vehicle_type[i]; i++) {
        vehicle_type[i] = tolower(vehicle_type[i]);
    }

    if (strcmp(vehicle_type, "car") == 0) {
        base_charge = 5.0 * distance_traveled;
    } else if (strcmp(vehicle_type, "truck") == 0) {
        base_charge = 10.0 * distance_traveled;
        if (distance_traveled > 500) {
            discount = base_charge * 0.1;
        }
    } else if (strcmp(vehicle_type, "bus") == 0) {
        base_charge = 8.0 * distance_traveled;
        if (distance_traveled > 300) {
            discount = base_charge * 0.05;
        }
    } else {
        return -1.0; // Indicate an invalid vehicle type
    }

    return base_charge - discount;
}

int main() {
    char vehicle_type[20]; // Array to store the vehicle type (adjust size as needed)
    int distance_traveled;

    printf("Enter Vehicle Type (Car/Truck/Bus): ");
    scanf("%19s", vehicle_type); // Read input with a limit to prevent buffer overflows

    printf("Enter Distance Traveled: ");
    scanf("%d", &distance_traveled);

    float total_toll = calculate_toll_tax(vehicle_type, distance_traveled);

    if (total_toll == -1.0) {
        printf("Invalid vehicle type\n");
    } else {
        float base_charge;
        if (strcmp(vehicle_type, "car") == 0) base_charge = 5.0 * distance_traveled;
        else if (strcmp(vehicle_type, "truck") == 0) base_charge = 10.0 * distance_traveled;
        else base_charge = 8.0 * distance_traveled;

        float discount = 0.0;
        if (strcmp(vehicle_type, "truck") == 0 && distance_traveled > 500) discount = base_charge * 0.1;
        else if (strcmp(vehicle_type, "bus") == 0 && distance_traveled > 300) discount = base_charge * 0.05;

        printf("Vehicle Type: %s\n", vehicle_type);
        printf("Distance Traveled: %d km\n", distance_traveled);
        printf("Base Charge: ₹%.2f\n", base_charge);
        printf("Discount: ₹%.2f\n", discount);
        printf("Total Toll Tax: ₹%.2f\n", total_toll);
    }

    return 0;
}
