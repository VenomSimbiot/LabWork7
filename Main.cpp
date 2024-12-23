#include <iostream>
#include "Task_1.h"
#include "Task_2.h"
#include "Task_3.h"
#include "Task_4.h"
#include "Task_5.h"

int main(){
    std::cout << "Добро пожаловать в 7 лабораторную работу по предмету Основы Алгоритмизации и Программирования\n";
    std::cout << "Выполнил студент группы 453502 Филиповский Владислав Вадимович\nВариант 5\n\n";
    std::string sc = "0";
    while (sc != "1")
    {
        std::cout << "Введите номер задания (1, 2, 3, 4, 5): ";
        int task;
        std::cin >> task;
        while (task < 1 or task > 5)
        {
            std::cout << "Пожалуйста, введите номер задания (1, 2, 3, 4, 5): ";
            std::cin >> task;;
        }
        switch (task)
        {
            case 1:
            {
                task1 task1(false);
                break;
            }
            case 2:
            {
                task2 task2(false);
                break;
            }
            case 3:
            {
                task3 task3(false);
                break;
            }
            case 4:
            {
                task4 task4(false);
                break;
            }
            case 5:
            {
                task5 task5(false);
                break;
            }
        }
        std::cout << "Введите 1 если хотите закончить и что либо другое для перезапуска программы: ";
        std::cin >> sc;
    }
    return 0;
}