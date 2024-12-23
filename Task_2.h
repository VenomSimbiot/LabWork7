#include <iostream>
#include <cmath>

class task2{
public:
    task2(bool istest)
    {
        if (istest == false)
        {
            std::cout << "Пользователь вводит 2 целых числа в десятичной системе счисления. Программа переводит их в двоичную, в дополнительный код, затем суммирует и выводит\n";
            long long int a, b;
            a = vvod("Введите первое число: ");
            b = vvod("Введите второе число: ");
            int k1 = 0, k2 = 0;
            if (a < 0)
            {
                k1 = 1;
                a = -a;
            }
            if (b < 0)
            {
                k2 = 1;
                b = -b;
            }
            int c1 = countnum(a, 2);
            int c2 = countnum(b, 2);
            int max = c1 > c2 ? c1:c2;
            int c3 = countnum(max, 8);
            c3 = pow(8, c3) + 1;
            int *arr1 = newnum(a, 2, c3, k1);
            std::cout << "Первое число в прямом коде: ";
            vivod(arr1, c3);
            int *arr2 = newnum(b, 2, c3, k2);
            std::cout << "Второе число в прямом коде: ";
            vivod(arr2, c3);
            arr1 = toDopCode(arr1, c3, k1);
            arr2 = toDopCode(arr2, c3, k2);
            std::cout << "Первое число в дополнительном коде: ";
            vivod(arr1, c3);
            std::cout << "Второе число в дополнительном коде: ";
            vivod(arr2, c3);
            arr1 = sum(arr1, arr2, c3, k1, k2);
            std::cout << "Сумма чисел: ";
            vivod(arr1, c3);
            delete[] arr1;
            delete[] arr2;
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


    int countnum(long long int num, int system){ //O(log(n))
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

    int* toDopCode(int* arr, int c, int k){ //O(n^2)
        if (k == 0)
        {
            
        }
        else{
            arr[c - 1]--;
            arr = othernum(arr, c, 2);
            for (int i = 1; i < c; i++)
            {
                if (arr[i] == 1)
                {
                    arr[i] = 0;
                }
                else{
                    arr[i] = 1;
                }
            }
        }
        return arr;
    }
    
    int* sum(int* arr1, int* arr2, int c, int k1, int k2){ //O(n^2)
        if (k1 != 1 and k2 != 1)
        {
            for (int i = 0; i < c; i++)
            {
                arr1[c - 1 - i] += arr2[c - 1 - i];
                arr1 = othernum(arr1, c, 2);
            }
        }
        else
        {
            for (int i = 0; i < c; i++)
            {
                arr1[c - 1 - i] += arr2[c - 1 - i];
                arr1 = othernum(arr1, c, 2);
            }
            arr1 = toDopCode(arr1, c, k1);
        }
        
        return arr1;
    }

    void vivod(int* arr, int c){ //O(n)
        std::cout << arr[0] << ".";
        for (int i = 1; i < c; i++)
        {
            std::cout << arr[i];
        }
        std::cout << "\n";
    }
    

    
};