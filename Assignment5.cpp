#include <stdio.h>
#include <math.h>
#define N 12 //Number of coordinate values

int main()
{
	float coordinates[N][2]; //Initialize array
    float sumx, sumy, avgX, avgY;
    float avgDist[N], sumDist;
    
	for (int i = 0; i < N; i++)
	{
		scanf("%f,%f", &coordinates[i][0],&coordinates[i][1]);
        
	}
	//In the console, enter the 12 coordinate values on a single line separated by comma and by spaces (ie. 1.1,5.6 5.5,8.2 etc.)
	
    // for loop for each coordinate
    for (int i = 0; i < N; i++) {  
        
            printf("(%.1f,%.1f)", coordinates[i][0], coordinates[i][1]); // print coordinate values
            
            // print "," after each coordinate except last one
            if (i < 11) { 
                printf(","); 
            }
            // new line after the sixth coordinate print statement
            if (i == 5){  
                printf("\n");
            }
            
            sumx += coordinates[i][0]; // add all the x coordinates
            sumy += coordinates [i][1]; // add all the y coordinates
            
        }
        printf("\n");
        avgX = sumx / N; // calculate average x coordinate
        avgY = sumy / N; // calculate average y coordinate
        printf("\nAverage center: (%.1f,%.1f)\n\n", avgX, avgY);
        
        // for loop for point being measured from
        for (int j = 0; j < N; j++) { 
            printf("Distance from point %d to\n", j + 1);
            sumDist = 0; // initialize sum distance
        
            // for loop for the point and distance
            for (int i = 0; i < N; i++) { 
                float dist = sqrt(pow(coordinates[i][1] - coordinates[j][1], 2) + pow(coordinates[i][0] - coordinates[j][0], 2)); // calculate distance
                printf("%d.- %.1f", i + 1, dist);
                
                if (i < N-1) {
                    printf(", "); // "," after each distance of point except the last one
                }
                if (i == N-1) {
                    printf("\n"); // print space after last distance 
                }
                
                sumDist += dist; // calculate distance sum 
            
            }
            avgDist[j] = sumDist / (N - 1); // calculate average distance for each distance sum 
            
        }
        
        printf("\n");
        
        for (int i = 0; i < N; i++) {
            printf("Average distance from point %d: %.1f km\n", i + 1, avgDist[i]); // print average distance of each point 
        }
        
    }
