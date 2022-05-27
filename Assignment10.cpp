data = dlmread('goldDataA.txt', ' ');
dataSize = size(data); %size of array is size of table 

    ID = data(:,1);
    length = data(:,2);
    radius = data(:,3);
    density = data(:,4);
    concentrationGold = data(:,5);
    concentrationSulfur = data(:,6);
    concentrationArsenic = data(:,7);
    
    %calculations to determine the mass of each sample 
    volume = 3.14 * radius^2 * length;
    massGold = depth * volume * concentrationGold;
    massSulfur = depth * volume * concentrationSulfur;
    massArsenic = depth * volume * concentrationArsenic;
    
    for i=0:dataSize(1)
        fprintf('%.0f', ID);
        fprintf('%.2f', massGold);
        fprintf('%.2f', massSulfur);
        fprintf('%.2', massArsenic);
        fprintf('\n');
        
    end
    

%sort the mass of gold going from highest to lowest values
[sortMassGold, idxMassGold] = sort(massGold, 'descend');

%for loop to go through each concentrations to determine cutoff grade
for i=1:dataSize(1)
    if concentrationGold < 1 || concentrationSulfur > 5 || concentrationArsenic > 1
        cutoffGrade = 'N';
    else
        cutoffGrade = 'Y';
        
    end
    
    fprintf('%d, %.2f, %c\n', idxMassGold(i), sortMassGold(i), gradeCutoff);
    
end
fprintf('Max mass: %.2f g at ID %.0f\n', sortMassGold(end), idxMassGold(end));
