

/** \file
 * Check a quadratic equation.
 * Programm do UnitTests
*/

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
