/**************************************************
 * Filename: sealion.cpp
 * Author: Raymond Lee
 * Date: 5-9-2021
 * Description: Initializes values of Sealion class
 * Input: None
 * Output: Values for Sealion class
 **************************************************/

#include <iostream>
#include "sealion.h"

using namespace std;

/**************************************************
 * Function: Sealion
 * Description: Initializes Sealion class
 * Pre-conditions: None
 * Post-conditions: Initialized Sealion class
 **************************************************/
Sealion::Sealion(){
	*(get_age()) = 48;
	*(get_cost()) = 800;
	*(get_babies()) = 1;
	*(get_food()) = 1;
	*(get_revenue()) = 160;
	*(get_sick()) = 0;
}
