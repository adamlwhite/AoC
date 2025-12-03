#include <fstream>
#include <iostream>
#include <vector>
#include <stdint.h>
#include <string>


int main()
{
    std::vector<std::string> batteries;
    std::vector<std::string> joltages;
    std::string line;
    std::ifstream fData("data/data");
    long total = 0;

    if (fData.is_open()){
        while(getline(fData,line)){
            batteries.push_back(line);
            joltages.push_back(std::string(""));
        }
        fData.close();
    }

    int cntr = 0;
    for(std::string bank : batteries){

        int maxPos1 = 0;
        int max1 = 0;
        std::vector<int> maxPos(12);

        for (int i=bank.length()-12;i>=0;i--){
            int num = stoi(bank.substr(i,1));
            if (num >= max1){
                max1 = num;
                maxPos1=i;
            }
        }
        maxPos[0] = maxPos1;
        std::cout << bank.substr(maxPos[0],1);

        if (maxPos[0] == bank.length()-12){
            joltages[cntr] = bank.substr(bank.length()-12);
        }
        else{        
            for (int k=1;k<12;k++){
                int maxPos2 = 0;
                int max2 = 0;
                for (int i=maxPos[k-1]+1;i<bank.length()-(11-k);i++){
                    int num = stoi(bank.substr(i,1));
                    if (num > max2){
                        max2 = num;
                        maxPos2 = i;
                    }
                }
                maxPos[k] = maxPos2;
                std::cout << bank.substr(maxPos[k],1);
            }
            std::cout << std::endl;
            
            for (int i=0;i<12;i++){
                joltages[cntr] = joltages[cntr] + bank.substr(maxPos[i],1);
            }
            std::cout << bank << "   max: " << joltages[cntr]<< std::endl;
            
        }
        
        total += stol(joltages[cntr]);
        cntr++;
    }
    std::cout << "Total: " << total << std::endl;

}