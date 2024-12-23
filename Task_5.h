#include <iostream>
#include <cmath>

class task5{
public:
    task5(bool istest)
    {
        if (istest == false)
        {
            std::cout << "Программа находит 1 отравленую бочку вина средни 240 используя 5 рабов и 2 суток\n";
            int* yadTut = new int[5]{0,0,0,0,0};
            int poison = 0;
            while (poison < 1 or poison > 240)
            {
                poison = vvod("Введите номер бочки с отравленным вином (1 - 240): ");
            }
            int k1 = 0;
            int **arr = new int*[240];
            for (int i = 0; i < 240; i++)
            {
                int c = 5;
                arr[i] = newnum(i, 3, c, k1);
            }
            int checker = 0;
            std::cout << "День 1:\n";
            if(poison > 80 and poison <= 161){
                yadTut[0] = 1;
                std::cout << "Раб 1 погиб\n";
                checker++;
            }
            if((poison >= 27 and poison <= 53) or (poison >= 108 and poison <= 134) or (poison >=189 and poison <= 215)){
                yadTut[1] = 1;
                std::cout << "Раб 2 погиб\n";
                checker++;
            }
            for(int i = 0; i < 240; i++){
                if(arr[i][2] == 1){
                    if (i == poison)
                    {
                        yadTut[2] = 1;
                        std::cout << "Раб 3 погиб\n";
                        checker++;
                        break;
                    }
                    
                }
            }
            for(int i = 0; i < 240; i++){
                if(arr[i][3] == 1){
                    if (i == poison)
                    {
                        yadTut[3] = 1;
                        std::cout << "Раб 4 погиб\n";
                        checker++;
                        break;
                    }
                    
                }
            }
            if((poison - 1)%3 == 0){
                yadTut[4] = 1;
                std::cout << "Раб 5 погиб\n";
                checker++;
            }
            if (checker == 0)
            {
                std::cout << "Все рабы остались живы\n";
            }
            
            checker = 0;
            std::cout << "День 2:\n";
            
            if(poison > 161){
                yadTut[0] = 2;
                std::cout << "Раб 1 погиб\n";
                checker++;
            }
            for(int i = 0; i < 240; i++){
                if(arr[i][1] == 2){
                    if (i == poison)
                    {
                        yadTut[1] = 2;
                        std::cout << "Раб 2 погиб\n";
                        checker++;
                        break;
                    }
                    
                }
            }
            for(int i = 0; i < 240; i++){
                if(arr[i][2] == 2){
                    if (i == poison)
                    {
                        yadTut[2] = 2;
                        std::cout << "Раб 3 погиб\n";
                        checker++;
                        break;
                    }
                    
                }
            }
            for(int i = 0; i < 240; i++){
                if(arr[i][3] == 2){
                    if (i == poison)
                    {
                        yadTut[3] = 2;
                        std::cout << "Раб 4 погиб\n";
                        checker++;
                        break;
                    }
                    
                }
            }
            if((poison - 2)%3 == 0){
                yadTut[4] = 2;
                std::cout << "Раб 5 погиб\n";
                checker++;
            }
            if (checker == 0)
            {
                std::cout << "Все рабы остались живы\n";
            }
            std::cout << "Отравленная бочка - " << yadd(yadTut) << "\n";
            std::cout << std::endl;
            for (int i = 0; i < 240; i++)
            {
                delete[] arr[i];
            }
            delete[] arr;
            delete[] yadTut;
            
        }
    }

    int yadd(int* arr){ //O(n)
        int k = 0;
        for (int i = 0; i < 5; i++)
        {
            k += arr[i]*pow(3, 4-i);
        }
        return k;
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