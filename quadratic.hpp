// TODO указывай имена в объявлениях функций, называй функции одинаково, почитай про структуры (struct {...}), придумай как переписать тестирование

/** \file
 * Solves a quadratic equation.
 * Programm calculates the roots of the quadratic equation given by the entered coefficients. the program provides for the possibility of unit testing.
*/

/**
 * \author Ustyuzhanina Maria
 * \version 1.0
 * \date The end of august 2021
 * \warning Be careful with your input
*/

#include <stdio.h>
#include <cmath>
#include <stdlib.h>
#include <assert.h>

/// For take into account the error when comparing
const double INACCURACY = 0.0001;

enum SolveStatus
{
    INF = -3,    ///< Used to denote an infinite number of solutions.
    NOROOTS = 0, ///< Used to denote the absence of roots in the equation.
    ONEROOT,     ///< Used to denote the presence of a single root.
    TWOROOTS,    ///< Used to denote the presence of two roots in the equation.
};

/**
 * \brief The function calculates the discriminant.
 * \details Input value: coef. a, b, c. Output: discriminant value.
 */
double discriminant( double a, double b, double c );

/**
 * \brief Comparison with zero of numbers of type double.
 * \details Input: Сompared value. Output: is value 0 or not.
*/
bool cmpWithZero( double value );

/**
 * \brief Function print answer.
 * \details Input: Amount of roots, first root, second root.
 */
int printAnswer( int nRoots, double x1, double x2 ); // nRoots, x1, x2

/**
 * \brief Starting unit-test
 * \details Return amount failed unit tests
 */ 
int RunUnitTest();

/**
 * \brief Do one test.
 * \details Input: a, b, c, amount of roots, x1, x2. Return failed test or not.
 */
int OneUnitTest( double a, double b, double c, int nRoots, double x1, double x2 );

/**
 * \brief Solve quadratic equation.
 * \details Input:a, b, c, *x1, *x2. Return amount of roots.
 */
int SolveSquare( double a, double b, double c, double* x1, double* x2 );
