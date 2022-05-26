#include <stdio.h>
#include <math.h>

int main()
{
	float initialHeight, tankRad, pipeRad;
	int finalT;
    float outletVel, heightAfter30Min, averageVel, velocity, heightAfter30min, initialVolume, volumeLost, currentVolume, currentHeight, heightAfter3600;
	
	scanf("%f, %f, %f, %d", &initialHeight, &tankRad, &pipeRad, &finalT);
	//In the console, enter initial height, tank radius, pipe radius and final time separated by a comma and a space
    
    //outletVel = 0.5 * sqrt(2 * 9.81 * initialHeight); // calulate the outlet velocity
    
    initialVolume = 3.14 * pow(tankRad, 2) * initialHeight; // find initial volume using initial height
    
    for (int t = 0; t <= finalT; t++) { // for loop for t 
        
        outletVel = pipeRad * sqrt(2 * 9.81 * initialHeight); // using equation given
        velocity += outletVel; // total velocity 
        
        volumeLost = outletVel * 3.14 * pow(pipeRad, 2) * 1; // equation given
        currentVolume = initialVolume - volumeLost; // find current volume 
        currentHeight = currentVolume / (3.14 * pow(tankRad, 2)); // rearrange volume = pi*r^2 to find height
        initialHeight = currentHeight; 
        initialVolume = currentVolume;
        
        if (t == 1800) {
            heightAfter30min = currentHeight;
        }
        
        if (t == finalT) {
            heightAfter3600 = currentHeight;
        }
    }
    
    averageVel = velocity / finalT;
    printf("Average velocity value: %.2f m/s\n", averageVel);
    
    printf("Height value after 30 min: %.2f m\n", heightAfter30min);
    printf("Height value after %d seconds: %.2f m\n", finalT, heightAfter3600);
    
    if (currentHeight <= (initialHeight/2)) {
        printf("Tank half drained\n");
    }
    
    else {
        printf("Tank still not half drained\n");
    }
    
}
