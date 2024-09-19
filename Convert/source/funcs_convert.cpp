#include <iostream>
#include <cmath>
#include <format>
//#include "add_std.h"
#include "../../Student/header/struct_func.h"
#include "../header/funcs_convert.h"

void check_name(const std:: string& name){
    for(int i = 0; i < name.length(); i++)
        if(std:: isdigit(name[i]))
            throw std:: runtime_error("Incorrect sting incorrect name");
}

void check_group(const std:: string& group){
    bool flag1 = true, flag2 = true;
    for(int i = 0; i < group.length(); i++){
        if(std:: isdigit(group[i]))
            flag1 = false;
        else
            flag2 = false;
    }
    if(flag1 || flag2)
        throw std:: runtime_error("Incorrect sting incorrect group");
}


void check_grade(const std:: string& grade){
    bool flag = true;
    for(int i = 0; i < grade.length(); i++)
        if(std:: isdigit(grade[i]))
            flag = false;
    if(flag)
        throw std:: runtime_error("Incorrect sting incorrect grade");
}


void out_strings(const std:: string& info, std:: string& name, std:: string& number, std:: string& score){
    if(info.length() < 49)
        throw std:: runtime_error("Incorrect sting - so tiny len");
    auto index_start = 0, index_end = 0;
    index_start = info.find('=', index_start);
    if(index_start == std:: string:: npos)
        throw std:: runtime_error("Incorrect sting - not found first \'=\'");
    if(info.substr(0, index_start) != "student.name")
        throw std:: runtime_error("Incorrect sting - not found \'student.name\'");
    index_start += 1;
    index_end =  info.find('\n', index_start);
    if(index_end == std:: string:: npos)
        throw std:: runtime_error("Incorrect sting - not found first \'/n\'");
    name = info.substr(index_start, index_end - index_start);
    check_name(name);
    index_start = index_end + 1;
    index_end = info.find('=',index_start);
    if(index_end == std:: string:: npos)
        throw std:: runtime_error("Incorrect sting - not found second \'=\'");
    if(info.substr(index_start, index_end - index_start) != "student.group")
        throw std:: runtime_error("Incorrect sting - not found \'student.group\'");
    index_start = index_end + 1;
    index_end = info.find('\n', index_start);
    if(index_end == std:: string:: npos)
        throw std:: runtime_error("Incorrect sting - not found second \'/n\'");
    number = info.substr(index_start, index_end - index_start);
    check_group(number);
    index_start = index_end + 1;
    index_end = info.find('=', index_start);
    if(index_end == std:: string:: npos)
        throw std:: runtime_error("Incorrect sting - not found thrith \'=\'");
    if(info.substr(index_start, index_end - index_start) != "student.grade")
        throw std:: runtime_error("Incorrect sting - not found \'student.grade\'");
    index_start = index_end + 1;
    index_end = info.find('\n', index_start);
    if(index_end == std:: string:: npos)
        throw std:: runtime_error("Incorrect sting - not found thrith \'/n\'");
    score = info.substr(index_start, index_end - index_start);
    check_grade(score);
    if(index_end + 1 < info.size())
        throw std:: runtime_error("Incorrect sting <check_string>");
}

float float_from_str(const std:: string str){
    return std::stod(str);
}


std:: string cnv::convert(Student& student){
    return std:: format("student.name={}\nstudent.group={}\nstudent.grade={}\n", stude::get_name(student), stude::get_number(student), stude::get_score(student));
}

Student cnv::convert(const std:: string info){
    std:: string name, number, score;
    out_strings(info, name, number, score);
    return stude::init_student(name, number, float_from_str(score));
}
