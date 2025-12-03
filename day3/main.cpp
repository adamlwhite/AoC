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
    int total = 0;

    if (fData.is_open()){
        while(getline(fData,line)){
            batteries.push_back(line);
            //std::cout << batteries.back() << std::endl;
            joltages.push_back(std::string());
        }
        fData.close();
    }

    int cntr = 0;
    for(std::string bank : batteries){

        int max1 = 0;
        int maxPos1 = 0;

        for (int i=bank.length()-2;i>=0;i--){
            int num = stoi(bank.substr(i,1));
            if (num >= max1){
                max1 = num;
                maxPos1 = i;
            }
        }
        
        int max2 = 0;
        int maxPos2 = 0;
        for (int i=maxPos1+1;i<bank.length();i++){
            int num = stoi(bank.substr(i,1));
            if (num >= max2){
                max2 = num;
                maxPos2 = i;
            }
        }
        std::cout << bank << "   max: " << bank.substr(maxPos1,1) << bank.substr(maxPos2,1) << std::endl;
        joltages[cntr] = bank.substr(maxPos1,1) + bank.substr(maxPos2,1);
        total += stoi(joltages[cntr]);
        
    }
    std::cout << "Total: " << total << std::endl;

}