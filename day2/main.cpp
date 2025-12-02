#include <fstream>
#include <iostream>
#include <vector>
#include <stdint.h>
#include <cstring>
#include <cmath>

std::ifstream fData("data/data");

std::string strData;

struct Range{
    std::string start;
    std::string end;
};



int main(){

    std::vector<Range> ranges;
    long num;
    int numLen;

    int count = 0;

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
        std::vector<int> factors;
        std::string strNum;
        //std::cout << range.start << std::endl;

        for(num = stol(range.start);num<=stol(range.end);num++){

            strNum = std::to_string(num);
            //std::cout << num << std::endl;

            int strLen = strNum.length();

            if (strLen % 2 == 0){
                //std::cout << strLen << std::endl;
                std::string sStart = strNum.substr(0, strLen/2);

                std::string sEnd = strNum.substr((strLen/2));
                
                if (sStart == sEnd){
                    std::cout << sStart << "," << sEnd << std::endl;
                    count += num;
                }
            }
        }

    }
    std::cout << count << std::endl;

}

