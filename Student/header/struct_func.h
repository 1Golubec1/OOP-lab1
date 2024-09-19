/*!
\file
\brief Заголовочный файл с описанием функций структуры Student

Данный файл содержит в себе определения основных 
функций для работы со структурой
*/


#ifndef STRUCT_FUNC_H
#define STRUCT_FUNC_H
#include <string>
/*!
* @brief структура Student описанная в файле struct_func.cpp
*/

typedef struct Student{
    std:: string name;
    std:: string number;
    float score;
}Student;

namespace stude{
    /*!
    * @brief 
    * Функция присваивания занчений структуре
    * 
    * @param name
    * 
    * Объект класса string
    * @param number
    * Объект класса string
    * 
    * @param score
    * 
    * Число с плавающей запятой
    * @return 
    * Ссылка на структуру
    */

    Student init_student(const std::string name,const std::string number, float score);

    /*!
    * @brief 
    * Функция для вывода одного из полей структуры <name>
    * 
    * @param student
    * 
    * Ссылка на структуру
    * @return 
    * Объект класса string
    */

    std:: string get_name(const Student& student);

    /*!
    * @brief 
    * Функция для вывода содержимого одного из полей структуры <number>
    * 
    * 
    * @param student
    * Ссылка на структуру
    * 
    * 
    * @return 
    * Объект класса string
    */

    std:: string get_number(const Student& student);

    /*!
    * @brief 
    * Функция для вывода содержимого одного из полей структуры <score>
    * 
    * @param student
    * Ссылка на структуру
    * 
    * @return 
    * Число с плавающей запятой <float>
    */
    float get_score(const Student& student);

    /*!
    * @brief 
    * Функция для сравнения содержимого полей двух структур
    * 
    * @param student1
    * 
    * Ссылка на структуру
    * @param student2
    * 
    * Ссылка на структуру
    * @return 
    * Логическая переменная типа bool
    */

    bool compar_students(Student& student1, Student& student2);
}

std:: ostream& operator<<(std:: ostream& os, const Student& student);

#endif