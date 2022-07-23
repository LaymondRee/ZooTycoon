/**************************************************
 * Filename: blackbear.cpp
 * Author: Raymond Lee
 * Date: 5-9-2021
 * Description: Initializes values for Blackbear class
 * Input: None
 * Output: Values of Blackbear class
 **************************************************/

#include <iostream>
#include "blackbear.h"

using namespace std;

/**************************************************
 * Function: Blackbear
 * Description: Initializes Blackbear class
 * Pre-conditions: None
 * Post-conditions: Initialized Blackbear class
 **************************************************/
Blackbear::Blackbear(){
	*(get_age()) = 48;
	*(get_cost()) = 5000;
	*(get_babies()) = 2;
	*(get_food()) = 3;
	*(get_revenue()) = 500;
	*(get_sick()) = 0;
}
