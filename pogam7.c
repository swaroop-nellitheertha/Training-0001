#include<stdio.h>
int main() { int productCount; int weight;
printf("Enter number of products:"); scanf("%d", &productCount);
int acceptedCount = 0; int rejectedCount = 0;
for(int I = 1; I <= productCount; I++) { printf("Enter weights (in grams):"); scanf("%d", &weight);
if (weight >= 950 && weight <= 1050) 
{ 
    acceptedCount++;
}
else
{
rejectedCount++;
}
}
printf("Accepted Products: %d\n", acceptedCount); 
printf("Rejected Products: %d", rejectedCount);
return 0;
}
