#include <iostream>

#include "struct_func.h"
#include "funcs_init.h"
#include "funcs_convert.h"

int chose_func(){
    return inits::get_float("1 - Program convert struct to string\n2 - Program convert string to struct\n");
}

Student create_student(){
    std::string name = inits::get_string("enter name: "),number = inits::get_string("enter group: ");
    float score = inits::get_float("enter grade: ");
    std::cout << "name: " << name << "\nnumber: " << number << "\ngrade: " << score << std::endl << std::endl; 
    return stude::init_student(name, number, score);
}


void func_1(){
    Student student = create_student();
    std::string str = cnv::convert(student);
    std:: cout << "string: " <<std:: endl << str <<std:: endl;
    std:: cout << "student: " <<std:: endl << student <<std:: endl;
}

void func_2(){
    std:: string str = inits::get_string("enter string info: ");
    Student student = cnv::convert(str);
    std:: cout << "student: " <<std:: endl << "\"" << student << "\"" <<std:: endl;
    std:: cout << "string: " <<std:: endl << "\"" << str << "\"" <<std:: endl;

}


int main(){
    int chose = 0;
    try{
        chose = chose_func();
    }
    catch(const std:: exception &e){
        std:: cerr << e.what() <<std:: endl;
    }
    try{
        if(chose == 1)
            func_1();
        if(chose == 2)
            func_2();
    }
    catch(const std:: exception &e){
        std:: cerr << e.what() <<std:: endl;
    }
    return 0;
}