#include <iostream> 
#include <limits>
#include "../include/funcs_init.h"
void check_cin(const std::istream& stream, bool& flag){
    if(stream.eof()){
        flag = true;
        throw std:: runtime_error("EOF");
    }
    else if(stream.fail())
        std::cout << "incorrect input" << std::endl;
    else
        flag = true;
}

std::string inits::get_string(std::string info){
    std:: string str;
    bool flag = false;
    while(!flag){
        std:: cout << info <<std:: endl;
        std:: getline(std:: cin, str, ';');
        check_cin(std:: cin, flag);
        if(!flag){
            std::cin.clear();
            std:: cin.ignore(std:: numeric_limits<std:: streamsize>:: max(), '\n');
        }
    }
    std:: cin.clear();
    std:: cin.ignore(std:: numeric_limits<std:: streamsize>:: max(), '\n');
    return str;
}


float inits::get_float(std:: string info){
    float nume = 0.0;
    bool flag = false;
    while(!flag){
        std:: cout << info;
        std:: cin >> nume;
        check_cin(std:: cin, flag);
        if(!flag){
            std:: cin.clear();
            std:: cin.ignore(std:: numeric_limits<std:: streamsize>:: max(), '\n');
        }
    }
    std:: cin.clear();
    std:: cin.ignore(std:: numeric_limits<std:: streamsize>:: max(), '\n');
    return nume;
}