#include <iostream>
#include <cmath>

class task3{
public:
    task3(bool istest)
    {
        if (istest == false)
        {
            std::cout << "Пользователь вводит 3 целых числа в десятичной системе счисления.\nИз них первое - основание системы счисления, в которую будут переведены остальные 2. Затем  программа суммирует их и выводит\n";
            long long int system;
            std::string a, b;
            system = 0;
            while (system < 2)
            {
                system = vvod("Введите основание системы счисления (> 1): ");
            }
            std::cout << "Введите первое число: ";std::cin >> a;
            std::cout << "Введите второе число: ";std::cin >> b;
            int k1 = 0, k2 = 0;
            int max = a.length() > b.length() ? a.length() : b.length();
            max++;
            int *arr1 = strtoarrsys(a, max);
            int *arr2 = strtoarrsys(b, max);
            arr1 = toDopCode(arr1, max, system);
            arr2 = toDopCode(arr2, max, system);
            std::cout << "Сумма чисел в этой системе счисления: ";
            arr1 = sum(arr1, arr2, max, system);
            
            vivod(arr1, max);
            delete[] arr1;
            delete[] arr2;
            std::cout << std::endl;
        }
        
    }

    long long int vvod(std::string text){
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

    int* strtoarrsys(std::string str, int max){ //O(n)
        int *arr = new int[max];
        for (int i = 0; i <= str.length(); i++)
        {
            arr[max - 1 - i] = 0;
        }
        for (int i = 0; i < str.length(); i++)
        {
            if (str[i] >= 48 and str[i] <= 57)
            {
                arr[max - str.length() + i] = str[i] - 48;;
            }
            if (str[i] >= 58)
            {
                arr[max - str.length() + i] = str[i] - 65 + 10;
            }
        }
        if (str[0] == '-')
        {
            arr[0] = 1;
        }
        return arr;
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
            if (arr[c - 1 - i] >= system)
            {
                arr[c - i - 2] += 1;
                arr[c - 1 - i] -= system;
            }
            else if(arr[c - 1 - i] == -1){
                arr[c - i - 2]--;
                arr[c - 1 - i] = system - 1;
            }

            if (arr[0] == 2)
            {
                arr[0] = 0;
            }
        }
        return arr;
    }

    int* toDopCode(int* arr, int c, int system){ //O(n^2)
        if (arr[0] == 0)
        {
            
        }
        else{
            arr[c - 1]--;
            arr = othernum(arr, c, system);
            for (int i = 1; i < c; i++)
            {
                arr[i] = system - arr[i] - 1;
            }
        }
        return arr;
    }
    
    int* sum(int* arr1, int* arr2, int c, int system){ //O(n^2)
        
        for (int i = 0; i < c; i++)
        {
            arr1[c - 1 - i] += arr2[c - 1 - i];
        }
        arr1 = othernum(arr1, c, system);
        if (arr1[0] == 1)
        {
            arr1 = toDopCode(arr1, c, system);
        }
        
        return arr1;
    }

    void vivod(int* arr, int c){
        std::cout << arr[0] << ".";
        for (int i = 1; i < c; i++)
        {
            if (arr[i] >= 0 and arr[i] <= 9)
            {
                std::cout << arr[i];
            }
            else{
                char a = 65 + arr[i] - 10;
                std::cout << a;
            }
            std::cout << ".";
        }
        std::cout << std::endl;
    }
    

    
};