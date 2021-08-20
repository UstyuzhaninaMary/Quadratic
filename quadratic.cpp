#include <stdio.h>
#include <cmath>
#include <TXLib.h>
main(){

    /*Объявление переменных*/
    float a;
    float b;
    float c;
    float desc;

    /*Получение коэффициентов*/

    printf("Введите уравнение(пример:ax*x+bx+c=0) \n");
    scanf("%fx*x%fx%f=0", &a, &b, &c);


    /*Вычисление дискриминанта*/
    desc = b*b-4*a*c;


    /*Нахождение корней*/
    if(a==0){
        if (b == 0){
            if(c == 0){
                printf("Корней бесконечно много\n");
            }
            else{
                printf("Корней нет\n");
            }
        }
        else{
            printf("Корень уравнения:\n%.5f\n", -c / b);
        }
    }
    else{
        if (desc > 0){
            printf("Корни уравнения:\n%.5f и %.5f\n", (-b + sqrt(desc)) / (2 * a), (-b - sqrt(desc)) / (2 * a));
        }
        if (desc == 0){
            printf("Корень уравнения:\n%.5f\n", -b / (2 * a));
        }
        if (desc<0){
            printf("Корней нет\n");
        }
    }
}
