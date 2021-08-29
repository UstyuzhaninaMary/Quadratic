#include "quadratic.hpp"


int SolveSquare( double a, double b, double c, double* x1, double* x2 )
{
    //Checking input values
    assert( std::isfinite( a ) );
    assert( std::isfinite( b ) ); 
    assert( std::isfinite( c ) );
    assert( x1 != nullptr ); 
    assert( x2 != nullptr );
    assert( x1 != x2 );

    double disc = NAN; //Discriminant

    //colculate discriminant
    disc = discriminant( a, b, c );

    //Check disc
    assert( std::isfinite( disc ) );

    //Find roots
    if( cmpWithZero( a ) ) //Compare "a" with zero
    { 
        if( cmpWithZero( b ) )
        {
            if( cmpWithZero( c ) )
            {
                return INF;
            }
            else
            {
                return NOROOTS;
            }
        }
        else
        {
            *x1 = - c / b;
            return ONEROOT;
        }
    }
    else
    {
        if( disc > INACCURACY )
        {
            *x1 = (-b + sqrt(disc)) / (2 * a);
            *x2 = (-b - sqrt(disc)) / (2 * a);

            return TWOROOTS;
        }

        else if( cmpWithZero(disc) )
        {
            *x1 = (-b / (2 * a));

            return ONEROOT;
        }

        else
        {
            return NOROOTS;
        }
    }
}

int printAnswer( int nRoots, double x1, double x2 )
{
    assert( !isnan(x1) );
    assert( x1 != x2 );

    switch( nRoots )
    {
    case NOROOTS:
        printf ( "No roots\n" );
        return 0;
    case ONEROOT:
        printf( "One root: %g\n", x1 );
        return 0;
    case TWOROOTS:
        printf( "Two roots: %g and %g\n", x1, x2 );
        return 0;
    case INF: 
        printf( "Infintry of roots\n" );
        return 0;
    default:
        printf( "Error in printAnswer()\n" );
        return 1;
    }
}

//colculate discriminant
double discriminant ( double a, double b, double c )
{
     return b * b - 4 * a * c;
}

//Compare with 0
bool cmpWithZero( double value )
{
    assert( !isnan(value) );
    if ( fabs( value ) < INACCURACY )
    {
        return true;
    } 
    return false;
}

int RunUnitTest()
{
    int fail = 0;

    if( OneUnitTest( 0,  0,  0, INF,     0,  0) ) fail++;//Test1
    if( OneUnitTest( 0,  0, -4, NOROOTS, 0,  0) ) fail++;//Test2
    if( OneUnitTest( 0,  2, -4, 1,       2,  0) ) fail++;//Test3
    if( OneUnitTest( 2,  2, -4, 2,       1, -2) ) fail++;//Test4
    if( OneUnitTest( 1, -2,  0, 2,       0,  2) ) fail++;//Test5
    if( OneUnitTest( 1, -2,100, NOROOTS, 1, -2) ) fail++;//Test6
    if( OneUnitTest( 1, -2,  1, 1,       1, -2) ) fail++;//Test7

    //return 0;
    return fail;
}
 
int OneUnitTest( double a, double b, double c, int real_nRoots, double real_x1, double real_x2 )
{
    static int num = 1;
    double x1 = NAN;
    double x2 = NAN;
    int nRoots = SolveSquare(a, b, c, &x1, &x2);
    if( (nRoots == real_nRoots) && (((nRoots == 1) && (x1 == real_x1)) || (nRoots == INF) 
        || (nRoots == 0) || ((nRoots == 2) && ((x1 == real_x1) && (x2 == real_x2)) 
        || ((x2 == real_x1) && (x1 == real_x2)))) )
        {
            num++;
            return 0;
        }
    printf("Error in test %d nRoots=%d real_nRoots=%d, a=%lf b=%lf, c=%lf\n", num, nRoots, real_nRoots, a, b, c);
    num ++;
    return 1;
}