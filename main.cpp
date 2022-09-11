/** \file
 * Solves a quadratic equation or do unit-tests.
 * Asks to do unit-tests or solve the equation.
*/
//https://vk.com/away.php?to=https%3A%2F%2Fgithub.com%2FUstyuzhaninaMary%2FQuadratic&cc_key=
/**
 * \author Ustyuzhanina Maria
 * \version 1.0
 * \date The end of august 2021, september 2022
*/

#include "quadratic.hpp"
#include "quadroUnitTest.hpp"

#define SCAN_ERROR  -1
#define PRINT_ERROR -2

int main(void){

    printf("Do Unit test?(Y/N)\n");
    char result = 'x';

    if (scanf(" %c", &result) == 1) {

        if (result == 'Y') {

            printf("Number of failed test %d\n", RunUnitTest());
            return 0;
        }
        else if (result != 'N') {

            printf("Input error\n");
            return 0;
        }
    }
    else {
        
        printf("Input error. Incorrect quantity. Input : %c\n", result);
        return 0;
    }

    //Declaring variables
    double a  = NAN; //First coef.
    double b  = NAN; //Second coef.
    double c  = NAN; //Third coef.
    double x1 = NAN; //First root
    double x2 = NAN; //Second root

    //Input coefficient
    printf("Input values(Example: a b c)\n");
    if (scanf("%lg %lg %lg", &a, &b, &c ) != 3) {

        printf("Input error\n");
        return SCAN_ERROR;
    }
    
    //Solve
    int nRoots = SolveSquare(a, b, c, &x1, &x2);

    //Print roots
    if (printAnswer(nRoots, x1, x2)) return PRINT_ERROR;

    return 0;
}