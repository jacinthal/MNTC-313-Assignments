#include <iostream>
using namespace std;

int main()
{
    int weight, firstDepth, depthIncrements, numDepthValues, numKValues, firstK, kIncrements;
    
    // prompting and getting user input
    printf("Input rock unit weight (kN/m3):\n");
    scanf("%d", &weight);
    printf("Input number of depth values:\n");
    scanf("%d", &numDepthValues);
    printf("Input first depth value (m):\n");
    scanf("%d", &firstDepth);
    printf("Input depth increment (m):\n");
    scanf("%d", &depthIncrements);
    printf("Input number of k values:\n");
    scanf("%d", &numKValues);
    printf("Input first k value (m):\n");
    scanf("%d", &firstK);
    printf("Input k increment (m):\n");
    scanf("%d", &kIncrements);
    
    // declaring arrays
    float depthValueArray[numDepthValues];
    float verticalStress[numDepthValues];
    float kValueArray[numKValues];
    float horizontalStress[numDepthValues][numKValues];
     
    // opening file for writing
    string filename = "outputFileA.txt"; 
    FILE * fileOutput = fopen(filename.c_str(), "w");
 
    printf("Vertical stress values (kPa):\n");
    
    // for loop for the different depth values and vertical stress values
    for (int i = 0; i < numDepthValues; i++){
        depthValueArray[i] = firstDepth + depthIncrements * i; // calculate the depth values 
        
        verticalStress[i] = weight * depthValueArray[i]; // calculating the vertical stress using different depth values
        printf("%.0f\n", verticalStress[i]);
        fprintf(fileOutput, "%.0f,", depthValueArray[i]); // to print the first column of depth values
        
        // for loop for the k values and horizontal stress
        for(int j = 0; j < numKValues; j++){
            kValueArray[j] = firstK + kIncrements * j; 
            horizontalStress[i][j] = verticalStress[i] * kValueArray[j]; // calculate the horizontal stress
            
            // if statement to print a new line at the end of each row
            if(j == numKValues - 1){
                fprintf(fileOutput, "%.0f\n", horizontalStress[i][j]);
            }
            // to print a comma at the end of each horizontal stress value
            else{
                fprintf(fileOutput, "%.0f,", horizontalStress[i][j]);
            }
        }
        
    }
    
    fclose(fileOutput); // closing the file
}
