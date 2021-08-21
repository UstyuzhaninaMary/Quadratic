#include <stdio.h>
#include <cmath>
#include <TXLib.h>

/*���������� �������*/
float discriminant (float, float, float);
int roots(float, float, float, float);

int main(){

    /*���������� ����������*/
    float a;
    float b;
    float c;
    float disc;


    /*��������� �������������*/

    printf("������� ���������(������:ax*x+bx+c=0) \n");
    scanf("%fx*x%fx%f=0", &a, &b, &c);

    /*���������� �������������*/
    disc = discriminant(a, b, c);

     /*���������� ������ � ������ ������*/
     roots(a, b, c, disc);

}


/*���������� ������������� �� �������������*/
float discriminant(float a, float b, float c){

        return b * b - 4 * a * c;

}


/*���������� ������*/
int roots (float a, float b, float c, float disc) {

    if(a==0){  /*���� ��������, ����� � == 0*/
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

        if (disc > 0){
            printf("����� ���������:\n%.5f � %.5f\n", (-b + sqrt(disc)) / (2 * a), (-b - sqrt(disc)) / (2 * a));
        }

        if (disc == 0){
            printf("������ ���������:\n%.5f\n", -b / (2 * a));
        }

        if (disc<0){
            printf("������ ���\n");
        }
    }
}
