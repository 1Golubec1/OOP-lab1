#include <iostream>
#include <cmath>
#include <format>
//#include "add_std.h"
#include "struct_func.h"
#include "funcs_convert.h"
#include <algorithm>


void check_name(std:: string& name){
    auto check = [](char bk){ return std:: isdigit(bk); };
    if(std::all_of(name.begin(), name.end(), check)){
        throw std:: runtime_error("Incorrect sting incorrect name");
    }
}

bool dig(char bk){
    if(std:: isdigit(bk))
        return true;
    else 
        return false;
}

bool not_dig(char bk){
    if(std:: isdigit(bk))
        return false;
    return true;
}

void check_group(const std:: string& group){
    bool flag1 = true, flag2 = true;
    if(!std::any_of(group.begin(), group.end(), dig) || !std::any_of(group.begin(), group.end(), not_dig))
         throw std:: runtime_error("Incorrect sting incorrect group");
}

void check_grade(const std:: string& grade){
    if(std::all_of(grade.begin(), grade.end(), not_dig)){
        throw std:: runtime_error("Incorrect sting incorrect name");
    }
}

void get_nam(const std:: string& info, std:: string& name, auto& index_start, auto& index_end){
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
}

void get_other(const std:: string& info, std:: string& pr, auto& index_start, auto& index_end, std:: string str){
    index_end = info.find('=',index_start);
    if(index_end == std:: string:: npos)
        throw std:: runtime_error("Incorrect sting - not found second \'=\'");
    if(info.substr(index_start, index_end - index_start) != str)
        throw std:: runtime_error("Incorrect sting - not found \'student.group\'");
    index_start = index_end + 1;
    index_end = info.find('\n', index_start);
    if(index_end == std:: string:: npos)
        throw std:: runtime_error("Incorrect sting - not found second \'/n\'");
    pr = info.substr(index_start, index_end - index_start);
}


void out_strings(const std:: string& info, std:: string& name, std:: string& number, std:: string& score){
    if(info.length() < 49)
        throw std:: runtime_error("Incorrect sting - so tiny len");
    auto index_start = 0, index_end = 0;
    get_nam(info, name, index_start, index_end);
    get_other(info, number, index_start, index_end, "student.group");
    check_group(number);
    index_start = index_end + 1;
    get_other(info, score, index_start, index_end, "student.grade");
    check_grade(score);
    index_start = index_end + 1;
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
