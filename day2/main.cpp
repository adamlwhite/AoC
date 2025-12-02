#include <fstream>
#include <iostream>
#include <vector>
#include <stdint.h>
#include <cstring>
#include <cmath>
#include <algorithm>

std::ifstream fData("data/data");

std::string strData;

struct Range{
    std::string start;
    std::string end;
};



int main(){

    std::vector<Range> ranges;
    long long num;
    int numLen;

    long count = 0;

    while (fData.is_open()){
        int i = 0;
        while(getline(fData,strData, ',')){
            ranges.push_back(Range());
            int del = strData.find('-');
            //std::cout << ranges[i].startLen << "." << ranges[i].endLen << std::endl;
            ranges[i].start = strData.substr(0,del);
            ranges[i].end = strData.substr(del+1);

            //std::cout << ranges[i].start << "_" << ranges[i].end <<std::endl;
            i++;
        }
        fData.close();
    }

    for(Range range : ranges){
        std::string strNum;
        //std::cout << range.start << std::endl;

        long long rStart = stol(range.start);
        long long rEnd = stol(range.end);
        bool isTrue = false;
        for(num = rStart;num<=rEnd;num++){
            std::vector<int> factors;
            strNum = std::to_string(num);
            //std::cout << num << std::endl;

            int strLen = strNum.length();

            for(int j=1;j<=strLen;j++){
                if (strLen%j==0){
                    factors.push_back(j);
                    //std::cout << j << std::endl;
                }
            }


            for (int factor : factors){
                //std::cout << strLen << std::endl;
                if(factor !=strLen){
                    std::vector<std::string> sStrings;
                    for (int i = 0; i<(strLen/factor); i++){
                        sStrings.push_back(strNum.substr(i*factor, factor));
                    }
                    if ( std::adjacent_find( sStrings.begin(), sStrings.end(), std::not_equal_to<>() ) == sStrings.end() ){
                        isTrue = true;
                    }

                }
            }
            if (isTrue){
                count += num;
                isTrue = false;
            }
        
        }

    }
    std::cout << count << std::endl;

}

