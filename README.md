# OOP-lab1
<лабораторная работа1>

Проект OOP lab1 предназначен для тестирования написанной библиотеки Convert, которая предостваляет функции позволяющие конвертировать структуру Student
в строку формата  java properties и обратно.

Проект использует систему сборки cmake (версией 3.16) и работает с 13 версии компилятора g++/gcc, а так же в нем есть отдельный файл для тестирования, написанный на фреймворк тестирования Catch2. Поэтому, чтобы
программа могла работать с тестовым файлом необходимо установить данный фреймворк. Если вы работаете на системе windows вам после утсновки
фреймворка нужно будет указать путь его утсновки в файле test.cpp за место имеющегося (catch/cathc2.hpp) , для линукса будет достаточно только утсновки фреймовка.

Чтобы запустить основную программу необходимо перейти в CmakeList проекта и указать flag-у значение TRUE, если хотите запустить тестирование
нужно присвоить значение FALSE.

Для реализованных функций была написана отдельная документация

Проект полезен в качестве ознакомления как не стоит писать программы)

Написан и поддерживается студентом из МИФИ
