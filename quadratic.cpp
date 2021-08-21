#include <stdio.h>
#include <cmath>
#include <TXLib.h>

/*Объявление функций*/
float discriminant (float, float, float);
int roots(float, float, float, float);

int main(){

    /*Объявление переменных*/
    float a;
    float b;
    float c;
    float disc;


    /*Получение коэффициентов*/

    printf("Введите уравнение(пример:ax*x+bx+c=0) \n");
    scanf("%fx*x%fx%f=0", &a, &b, &c);

    /*Нахождение дискриминанта*/
    disc = discriminant(a, b, c);

     /*Нахождение корней и печать ответа*/
     roots(a, b, c, disc);

}


/*Вычисление дискриминанта по коэффициентам*/
float discriminant(float a, float b, float c){

        return b * b - 4 * a * c;

}


/*Нахождение корней*/
int roots (float a, float b, float c, float disc) {

    if(a==0){  /*Учет ситуаций, когда а == 0*/
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

        if (disc > 0){
            printf("Корни уравнения:\n%.5f и %.5f\n", (-b + sqrt(disc)) / (2 * a), (-b - sqrt(disc)) / (2 * a));
        }

        if (disc == 0){
            printf("Корень уравнения:\n%.5f\n", -b / (2 * a));
        }

        if (disc<0){
            printf("Корней нет\n");
        }
    }
}
