/** \file
 * Check a quadratic equation.
 * Programm do UnitTests
*/


/**
 * \brief Struct of data for unit test.
 * \details Elements: a, b, c, amount of roots, x1, x2.
 */


/**
 * \brief Starting unit-test
 * \details Return amount failed unit tests
 */ 
int RunUnitTest();

/**
 * \brief Do one test.
 * \details Input: struct DataForUnitTest. Return failed test or not.
 */
int OneUnitTest(struct DataForUnitTest inputStruct);
