/**************************************************
 * Filename: tiger.cpp
 * Author: Raymond Lee
 * Date: 5-9-2021
 * Description: Initializes values for Tiger class
 * Input: None
 * Output: Values of Tiger class
 **************************************************/

#include <iostream>
#include "tiger.h"

using namespace std;

/**************************************************
 * Function: Tiger
 * Description: Initializes Tiger class
 * Pre-conditions: None
 * Post-conditions: Initialized Tiger class
 **************************************************/
Tiger::Tiger(){
	*(get_age()) = 48;
	*(get_cost()) = 10000;
	*(get_babies()) = 3;
	*(get_food()) = 5;
	*(get_revenue()) = 1000;
	*(get_sick()) = 0;
}
