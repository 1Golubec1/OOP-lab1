/*!
\file
\brief Заголовочный файл с описанием функций для из

Данный файл содержит в себе определения основных 
функций программы
*/

#ifndef FUNCS_CONVERT_H
#define FUNCS_CONVERT_H
#include <string>

typedef struct Student Student;

namespace cnv{
    
    /*!
    * @brief структура Student описанная в файле struct_func.cpp
    */


    /*!
    * @brief 
    * Функция преобразования структуру Student в строку
    * 
    * @warning
    * Функция возвращает строку определенного формата: 
    * student.name=""
    * student.group=""
    * student.grade=0
    * @throw
    * Такое же как функция stod()
    * @param student
    * Структура Student описанная в файле struct_func.cpp
    * @return 
    * Объект класса string
    */
    std::string convert(Student& student);


    /*!
    * @brief 
    * Функция преобразования строки в структуру Student
    * @warning
    * Функция принимает строку определенного формата: 
    * student.name=""
    * student.group=""
    * student.grade=0
    * В случае некоррекно переденной строки функция выдаст исключение
    * @throw 
    * runtime_error("Incorrect sting")
    * @param info 
    * Объект класса string
    * @return 
    * Структура Student описанная в файле struct_func.cpp
    */
    Student convert(const std:: string info);
}




#endif