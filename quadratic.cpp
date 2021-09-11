#include "quadratic.hpp"


int SolveSquare( double a, double b, double c, double* x1, double* x2 )
{
    //Checking input values
    assert( std::isfinite( a ) );
    assert( std::isfinite( b ) ); 
    assert( std::isfinite( c ) );
    assert( x1 != nullptr ); 
    assert( x2 != nullptr );
    assert(*x1 != *x2     );

    double disc = NAN; //Discriminant

    //colculate discriminant
    disc = discriminant( a, b, c );

    //Check disc
    assert( std::isfinite( disc ) );

    //Find roots
    if( cmpWithNumber( a, 0 ) ) //Compare "a" with zero
    { 
        if( cmpWithNumber( b, 0 ) )
        {
            if( cmpWithNumber( c, 0) )
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

        else if( cmpWithNumber(disc, 0) )
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
    assert( !cmpWithNumber(x1, x2) );

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
bool cmpWithNumber( double value, double number )
{
    assert( !isnan(value) );
    if(( value < (number + INACCURACY) ) and ( value > (number - INACCURACY) ))
    {
        return true;
    } 
    return false;
}
