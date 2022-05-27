#include <stdio.h>

struct payload
{
    // declare fields
    int numCustomers;
    float avgPrice;
    float avgWeight;

};

class econ
{
public:
    float transportCost = 4.70;
    float targetRevenue = 36000;
    
    // method for the number of customers served
    float numCustomersServed(int numCenters, payload customerData[])
    {
        int total = 0;
        for (int i = 0; i < numCenters; i++)
        {
            total += customerData[i].numCustomers;
        }
        return total;
        
    }
    
    // method for the total weight transported
    float weightTransported(int numCenters, payload customerData[])
    {
        float total = 0;
        for (int i = 0 ; i < numCenters; i++)
        {
            total += customerData[i].avgWeight * customerData[i].numCustomers;
            
        }
        return total;
    }
    
    // method for the total revenue
    float totalRevenue(int numCenters, payload customerData[])
    {
        float total = 0;
        for (int i = 0; i < numCenters; i++)
        {
            total += customerData[i].avgPrice * customerData[i].numCustomers;
        }
        total -= weightTransported(numCenters, customerData) * transportCost;
        return total;
    }
};

// main program
int main()
{ 
    // declare number of centers
    int numCenters;
    
    // recieve input
    printf("Input number of centers:\n");
    scanf("%d", &numCenters);
    
    // call structure
    payload customerData[numCenters];
     
    printf("Input customer data for all centers:\n");
    // for loop to get input for customer data
    for (int i = 0; i < numCenters; i++)
    {
        scanf("%d", &customerData[i].numCustomers);
    }
    
    printf("Input item average price data for all centers:\n");
    // for loop to get input for item average price
    for (int i = 0; i < numCenters; i++)
    {
        scanf("%f", &customerData[i].avgPrice);
    }
    
    printf("Input item average weight data for all centers:\n");
    // for loop to get input for the item average weight data 
    for (int i = 0; i < numCenters; i++)
    {
        scanf("%f", &customerData[i].avgWeight);
    }
    
    econ e;
    
    // print output
    printf("Total customers: %.0f\n", e.numCustomersServed(numCenters, customerData));
    printf("Total weight: %.0f kg\n", e.weightTransported(numCenters, customerData));
    printf("Total revenue: $%.0f\n", e.totalRevenue(numCenters, customerData));
    
    // calculate and print average revenue
    float avgRevenue = e.totalRevenue(numCenters, customerData) / numCenters;
    printf("Average revenue: $%.0f\n", avgRevenue);
	
    // if statement to determine if the company is profitable or not
    if (e.totalRevenue(numCenters, customerData) > e.targetRevenue)
    {
        printf("Company is profitable\n");
    }
    else {
        printf("Company is not profitable\n");
    }
}
