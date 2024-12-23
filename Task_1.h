#include <iostream>
#include <cmath>

class task1{
public:
    task1(bool istest)
    {
        if (istest == false)
        {
            std::cout << "Пользователь вводит число в десятичной системе счисления. Программа выводит число в прямом и обратном коде\n";
            long long int num = vvod("Введите целое число: ");
            int system = 2;
            std::cout << "Число в прямом коде: \n";
            int k = 1;
            if (num < 0)
            {
                std::cout << "1.";
                num = -num;
                k = 2;
            }
            else{
                std::cout << "0.";
            }
            int c = countnum(num, system);
            int *arr = newnum(num, system, c);
            vivod(arr, c);
            std::cout << "\nОбратный код: ";
            arr = toRevCode(arr, c, k);
            vivod(arr, c);
            delete[] arr;
            std::cout << std::endl;
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

    int* newnum(long long int num, int system, int c){ //O(n^2)
        int *arr = new int[c];
        for (int i = 0; i < c; i++)
        {
            arr[i] = 0;
        }
        if (num == 0)
        {
            return arr;
        }
        
        for (int i = 0; i < num; i++)
        {
            arr[c - 1]++;
            arr = othernum(arr, c, system);
        }
        return arr;
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
    
    int* othernum(int* arr, int c, int system){ //O(n)
        for (int i = 0; i < c - 1; i++)
        {
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

    void vivod(int* arr, int c){ //O(n)
        int k = countnum(c, 8);
        for (int i = 0; i < pow(8, k) - c; i++)
        {
            std::cout << "0.";
        }
        for (int i = 0; i < c; i++)
        {
            std::cout << arr[i] << ".";
        }
    }

    int* toRevCode(int* arr, int c, int k){ //O(n)
        for (int i = 1; i < c; i++)
        {
            if (arr[i] == 1)
            {
                if (i == 0 and k == 1)
                {
                }
                else{
                    arr[i] = 0;
                }
                
            }
            else{
                arr[i] = 1;
            }
        }
        return arr;
    }
};