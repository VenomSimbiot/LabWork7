#include <iostream>
#include <cmath>

class task4{
public:
    task4(bool istest)
    {
        if (istest == false)
        {
            std::cout << "Пользователь вводит число. Затем вводит 3 числа, на которые надо проверить делимость нашего числа. Программа переводит число в системы счисления и говорит делится или нет\n";
            long long int num, a = -1, b = -1, c = -1;
            num = vvod("Введите число: ");
            while (a<1)
            {
                a = vvod("Введите первое число на которое надо проверить делимость - натуральное: ");
                if (a == 0)
                {
                    std::cout << "Ошибка деления на 0" << std::endl;
                }
                std::cout << "Натуральное число" << std::endl;
            }
            while (b<1)
            {
                b = vvod("Введите второе число на которое надо проверить делимость: ");
                if (b == 0)
                {
                    std::cout << "Ошибка деления на 0" << std::endl;
                }
                std::cout << "Натуральное число" << std::endl;
            }
            while (c<1)
            {
                c = vvod("Введите третье число на которое надо проверить делимость: ");
                if (c == 0)
                {
                    std::cout << "Ошибка деления на 0" << std::endl;
                }
                std::cout << "Натуральное число" << std::endl;
            }
            int k1 = 0, k2 = 0;
            int c1 = countnum(num, a);
            int c2 = countnum(num, b);
            int c3 = countnum(num, c);
            int t1 = 0, t2 = 0, t3 = 0;
            int *arr1, *arr2, *arr3;
            if (a == 1)
            {
                t1++;
                arr1 = new int[c1];
                for (int i = 0; i < c1; i++)
                {
                    arr1[i] = 0;
                }
            }
            else{
                arr1 = newnum(num, a, c1, k1);
            }
            if (b == 1)
            {
                t2++;
                arr2 = new int[c2];
                for (int i = 0; i < c2; i++)
                {
                    arr2[i] = 0;
                }
            }
            else{
                arr2 = newnum(num, b, c2, k2);
            }
            if (c == 1)
            {
                t3++;
                arr3 = new int[c3];
                for (int i = 0; i < c3; i++)
                {
                    arr3[i] = 0;
                }
            }
            else{
                arr3 = newnum(num, c, c3, k2);
            }
            if (arr1[c1 - 1] == 0)
            {
                std::cout << num << " делится на " << a << "\n";
            }
            if (arr2[c2 - 1] == 0)
            {
                std::cout << num << " делится на " << b << "\n";
            }
            if (arr3[c3 - 1] == 0)
            {
                std::cout << num << " делится на " << c << "\n";
            }
            std::cout << std::endl;
            delete[] arr1;
            delete[] arr2;
            delete[] arr3;
        }
    }

    long long int vvod(std::string text){ //O(n^2)
        std::cout << text;
        std::string newint;
        long long int num;
        while (true)
        {
            bool m = false, k = false;
            std::cin >> newint;
            if (newint[0] == '-')
            {
                m = true;
                newint[0] = '0';
            }
            
            for (int i = 0; i < newint.length(); i++)
            {
                
                if ((newint[i] < 48 or newint[i] > 57))
                {
                    k = true;
                }
                
            }
            
            if (k)
            {
                std::cout << "Вводите только числа\n" << text;
                continue;
            }
            else{
                num = std::stoll(newint);
                if(m){
                    num = -num;
                }
                break;
            }
        }
        return num;
    }

    int countnum(long long int num, int system){ //O(log(num))
        int c = 0;
        while (num != 0)
        {
            num /= system;
            c++;
        }
        return c;
    }

    int* newnum(long long int num, int system, int c, int k){ //O(n^2)
        int *arr = new int[c];
        for (int i = 0; i < c; i++)
        {
            arr[i] = 0;
        }
        for (int i = 0; i < num; i++)
        {
            arr[c - 1]++;
            arr = othernum(arr, c, system);
        }
        if (k == 1)
        {
            arr[0] = 1;
        }
        
        return arr;

    }

    int* othernum(int* arr, int c, int system){ //O(n)
        for (int i = 0; i < c - 1; i++)
        {
            if (arr[0] == 2)
            {
                arr[0] = 0;
            }
            
            if (arr[c - 1 - i] == system)
            {
                arr[c - i - 2]++;
                arr[c - 1 - i] = 0;
            }
            else if(arr[c - 1 - i] == -1){
                arr[c - i - 2]--;
                arr[c - 1 - i] = system - 1;
            }
        }
        return arr;
    }
};