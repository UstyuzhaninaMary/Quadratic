#include "quadratic.hpp"

int SolveSquare(double a, double b, double c, double* x1, double* x2){

    //Checking input values
    assert( std::isfinite(a));
    assert( std::isfinite(b)); 
    assert( std::isfinite(c));
    assert( x1 != nullptr ); 
    assert( x2 != nullptr );
    assert(*x1 != *x2     );

    //Calculate discriminant
    double disc = b * b - 4 * a * c;

    //Check disc
    assert(std::isfinite(disc));

    //Find roots
    if(isEqual(a, 0)) { //Compare "a" with zero

        if(isEqual(b, 0)) {

            if(isEqual(c, 0)) {

                return INF;
            }
            else {

                return NOROOTS;
            }
        }
        else {

            *x1 = - c / b;
            return ONEROOT;
        }
    }
    else {

        if(disc > INACCURACY) {

            double sqrtDisc = sqrt(disc);
            *x1 = (-b + sqrtDisc) / (2 * a);
            *x2 = (-b - sqrtDisc) / (2 * a);

            return TWOROOTS;
        }
        else if(isEqual(disc, 0)) {

            *x1 = (-b / (2 * a));

            return ONEROOT;
        }
        else {

            return NOROOTS;
        }
    }
}

int printAnswer(int nRoots, double x1, double x2) {

    assert(!isnan(x1));
    assert(!isEqual(x1, x2));

    switch(nRoots) {
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

//Compare with 0
bool isEqual(double a, double b) {

    assert(!isnan(a));
    assert(!isnan(b));

    return (fabs(a - b) < INACCURACY);
}