// MAP OF THE HIGHEST PEAK
class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        // first locate all the water and land parts 
        // land = 0 , water = 1
        // i - row j - column

        queue<pair<int , int >> WaterTrave;
        for (int i = 0; i < isWater.size() ; i++){
            for (int j = 0 ; j < isWater[0].size() ; j++){
                if (isWater[i][j] == 1){
                    WaterTrave.push({i , j});
                    isWater[i][j] = 0;
                }

                else {
                    // land
                    isWater[i][j] = -3 ; // to differentiate trave and untrave
                }
            }
        }


        while(!WaterTrave.empty()){
            auto val = WaterTrave.front();
            int row = val.first;
            int col = val.second;

            int amt = isWater[row][col];

            if (row - 1 >= 0 && isWater[row - 1][col] < 0){
                isWater[row - 1][col] = amt + 1;
                WaterTrave.push({row - 1 , col });
            }

            if (row + 1 <  isWater.size() && isWater[row + 1][col] < 0){
                isWater[row + 1][col] = amt + 1;
                WaterTrave.push({row + 1 , col} );
            }

            if (col - 1 >= 0 && isWater[row][col - 1] < 0){
                isWater[row][col - 1] = amt + 1;
                WaterTrave.push({row  , col - 1} );
            }

            if (col + 1 <  isWater[0].size() && isWater[row][col + 1] < 0){
                isWater[row][col + 1] = amt + 1;
                WaterTrave.push({row  , col + 1} );
            }

            WaterTrave.pop();

        }

        return isWater; 
    
    }
};
