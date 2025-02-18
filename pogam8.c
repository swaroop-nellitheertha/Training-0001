#include<stdio.h>
#include<string.h> 
int main()
{
    int vehicleCount;
    char vehicleType [10];
    printf("Enter number of vehicles: "); 
    scanf("%d", &vehicleCount);
    float collection = 0;
    for(int i = 1; i <= vehicleCount; i++) 
    { 
        printf("Enter vehicle type:"); 
        scanf("%s", vehicleType);
    if(strcmp(vehicleType, "car") == 0) 
    { 
        collection += 50;
    } 
    else if(strcmp(vehicleType, "truck") == 0) 
    { 
        collection += 100;
    } 
    else if(strcmp(vehicleType, "bike") == 0) 
    {
        collection += 20;
    }
}
printf("Total Toll Collection: %.2f\n", collection);
return 0;
}
