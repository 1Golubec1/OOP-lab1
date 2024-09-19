/*!
\file
\brief Заголовочный файл с объявлением функций ввода из стандартного потока
*/



#ifndef FUNCS_INIT_H
#define FUNCS_INIT_H
#include <string>



namespace inits{
    /*!
    * @brief 
    * Функция для ввода строки из стандартного потока ввода
    * 
    * @warning
    * Функция выкидывает исключение в случае прожатия клавиш <Ctrl + D> = EOF
    * Чтобы закончить ввод необходимо ввести <;> 
    * @throw 
    * runtime_error("EOF")
    * @param info
    * Объект класса string, нужен для вывода содержимого передаваеомого аргумента в стандартный поток вывода
    * @return 
    * Объект класса string
    */
    std::string get_string(std::string info);

    /*!
    * @brief 
    * Функция для ввода числа с плавающей запятой из стандартного потока ввода
    * 
    * @warning
    * Функция выкидывает исключение в случае прожатия клавиш <Ctrl + D> = EOF
    * @throw
    * runtime_error("EOF")
    * @param info
    * Объект класса string, нужен для вывода содержимого передаваеомого аргумента в стандартный поток вывода
    * @return 
    * Число с плавающей запятой
    */
    float get_float(std::string info);
}

#endif