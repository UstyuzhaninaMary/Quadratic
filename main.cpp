#include "quadratic.hpp"
#include "quadroUnitTest.hpp"

int main()
{
    printf( "Do Unit tect?(Y/N)\n" );
    char result = 'x';
    if ( scanf( " %c", &result ) == 1 )
    {
        if ( result == 'Y' )
        {
            printf( "%d\n", RunUnitTest() );
            return 0;
        }
        else if ( result != 'N' )
        {
            printf( "Input error\n" );
            return 0;
        }
    }
    else
    {
        printf( "Input error. Incorrect quantity. Input : %c\n", result );
        return 0;
    }

    //Declaring variables
    double a  = NAN; //First coef.
    double b  = NAN; //Second coef.
    double c  = NAN; //Third coef.
    double x1 = NAN; //First root
    double x2 = NAN; //Second root

    //Input coefficient
    printf( "Input values(Example: a b c)\n" );
    if (scanf( "%lg %lg %lg", &a, &b, &c ) != 3 )
    {
        printf("Input error\n");
        return 1;
    }
    
    //Solve
    int nRoots = SolveSquare( a, b, c, &x1, &x2 );

    //Print roots
    if ( !printAnswer( nRoots, x1, x2 ) ) return 0;
    return 1;
}
