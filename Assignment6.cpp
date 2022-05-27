#include <stdio.h>

float stressCondition(float E, float e); // declare funtion stressCondition
int main()
{
	float elasticMod, strain;
	
	scanf("%f, %f", &elasticMod, &strain);
	//In the console, enter elastic modulus (MPa) and strain values on a single line separated by a comma and space. 
    
    float stress = stressCondition(elasticMod, strain); // call function stressCondition
}

float stressCondition(float E, float e) { // define function stressCondtion
    float compressiveStrength = 30;
    float tensileStrength = 5;
    float localStress = E * e; // stress calculation
    printf("Stress value: %.2f MPa\n", localStress);
    
    // determine if it is in tension
    if (e > 0) { 
        printf("Bridge deck in tension\n");
        
        // determine if tensile strength is exceeded
        if (localStress > tensileStrength) {
            printf("Danger: tensile strength exceeded\n");
            return 0;
        }
        else {
            printf("Bridge deck safe\n");
            return 0;
        }
    }
    
    // determine if it is in compression
    else if (e < 0) {
        printf("Bridge deck in compression\n");
        
        // determine if the compressive strength is exceeded
        if (localStress > compressiveStrength) {
            printf("Danger: compressive strength exceeded\n");
            return 0;
        }
        else  {
            printf("Bridge deck safe\n");
            return 0;
        }
    }
    else {
        printf("No stress in bridge\n");
        return 0;
    }
    
}
