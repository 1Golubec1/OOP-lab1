#include <iostream> 
#include "../header/struct_func.h"

Student stude::init_student(const std::string name,const std::string number, float score){
    return (Student){name, number, score};
}

std:: string stude::get_name(const Student& student){
    return student.name;
}

std:: string stude::get_number(const Student& student){
    return student.number;
}

float stude::get_score(const Student& student){
    return student.score;
}

void free_sudent(Student* student){
    if(student == nullptr)
        return ;
    delete student;
}

std:: ostream& operator<<(std:: ostream& os, const Student& student) {
	return std:: cout << student.name << std:: endl << student.number <<std:: endl << student.score << std:: endl;
}

// Student* operator>>(){
//     string name = get_string("enter name: "), nume = get_string("enter group: ");
//     float score = get_float("enter grade: ");
//     Student* student = init_student(name, num);
// }


bool stude::compar_students(Student& student1, Student& student2){
    if(student1.name == student2.name && student1.number == student2.number && student1.score == student2.score)
        return true;
    else
        return false;
}