#include <iostream>
#include <vector>        
#include <sstream>
#include <fstream>
#include <string>
int main(){
    std::string chaine="2,3,6,8,18,20,84";
    std:: string simplecharactere;
    std:: stringstream fluxCHaine(chaine);
    std::vector <int> vecDentiers;
    while(getline(fluxCHaine,simplecharactere,',')){
        vecDentiers.push_back(std::stoi(simplecharactere));
    }
    std::cout<<"vec d entiers=";
    for(auto val:vecDentiers)
    std::cout<<val;
    std::cout<<std::endl;
    return 0;
}