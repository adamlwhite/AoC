#include <iostream>
#include <fstream>
#include <string>

int main()
{

    std::string line;
    std::string strDir;
    std::string strNum;
    int num;
    int point = 50;
    int countPoint = 0;
    int countClick = 0;
    int countClick2 = 0;

    std::ifstream fData("day1/data");

    if (fData.is_open()){
        while (getline(fData, line)){

                if (line != ""){
                strDir = line.front();
                strNum = line.substr(1);
                num = stoi(strNum);

                if (strDir == "L"){
                    if (point != 0){
                        point -= num;
                        //If point is 0 and +->100 then click will be incremented despite not passing 0
                        while (point < 0){
                            point += 100;
                            if (point != 0){
                                countClick++;
                            }
                        }
                    }
                    else if (point == 0){
                        point -= num;
                        //If point is 0 and +->100 then click will be incremented despite not passing 0
                        while (point < 0){
                            point += 100;
                            if (point != 0){
                                countClick++;
                            }
                            

                        }
                        countClick--;
                    }
                }
                else if (strDir == "R"){
                    point += num;
                    while (point > 99){
                        point -= 100;
                        if (point != 0){
                            countClick++;
                        }
                        
                    }

                }


                if (point == 0){
                    countPoint++;
                }
            }
            //std::cout << point << std::endl;
        }
        fData.close();
    }   

    std::cout << "Points: " << countPoint << std::endl;
    std::cout << "Clicks: " << countClick << std::endl;
    std::cout << "Total: " << countPoint + countClick << std::endl;

    return 0;
}