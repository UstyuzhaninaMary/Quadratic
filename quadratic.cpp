#include <stdio.h>
#include <cmath>
#include <TXLib.h>
main(){

    /*���������� ����������*/
    float a;
    float b;
    float c;
    float desc;

    /*��������� �������������*/

    printf("������� ���������(������:ax*x+bx+c=0) \n");
    scanf("%fx*x%fx%f=0", &a, &b, &c);


    /*���������� �������������*/
    desc = b*b-4*a*c;


    /*���������� ������*/
    if(a==0){
        if (b == 0){
            if(c == 0){
                printf("������ ���������� �����\n");
            }
            else{
                printf("������ ���\n");
            }
        }
        else{
            printf("������ ���������:\n%.5f\n", -c / b);
        }
    }
    else{
        if (desc > 0){
            printf("����� ���������:\n%.5f � %.5f\n", (-b + sqrt(desc)) / (2 * a), (-b - sqrt(desc)) / (2 * a));
        }
        if (desc == 0){
            printf("������ ���������:\n%.5f\n", -b / (2 * a));
        }
        if (desc<0){
            printf("������ ���\n");
        }
    }
}
