/*!
\file
\brief Заголовочный файл с описанием функций меню для работы программы

Данный файл содержит в себе определения основных 
функций для работы с меню
*/


#ifndef FUNCS_MENU_H
#define FUNCS_MENU_H

#include <string>

typedef struct Student Student;

namespace mn{
    /*!
    * @brief 
    * Функция для выбора режима работы
    * 
    * @throw
    * Такое же как в функции get_float объявленная в funcs_init.h
    * 
    * @return 
    * Целочисленное число <int>
    */
    int chose_func();

    /*!
    * @brief 
    * Функция для преобразвания строки в структуру
    * 
    * @throw
    * Такое же как в функции convert() объявленная в funcs_convert.h
    */

    void func_1();

    /*!
    * @brief 
    * Функция для преобразвания структуры в строку
    * 
    * @throw
    * Такое же как в функции convert() объявленная в funcs_convert.h
    */

    void func_2();
}


#endif