/**************************************************
 * Filename: animals.cpp
 * Author: Raymond Lee
 * Date: 5-9-2021
 * Description: Contains accessors for members in Animal class
 * Input: None
 * Output: members in Animal class
 **************************************************/

#include <iostream>
#include "animals.h"
#include "zoo.h"

using namespace std;

/**************************************************
 * Function: Animals
 * Description: Initializes Animal class
 * Pre-conditions: None
 * Post-conditions: Initialized Animal class
 **************************************************/
Animals::Animals(){
	age = 48;
	revenue = 0;
}

/**************************************************
 * Function: get_age()
 * Description: Gets value of age
 * Pre-conditions: None
 * Post-conditions: Returns value of age
 **************************************************/
int* Animals::get_age(){
	return &age;
}

/**************************************************
 * Function: get_cost()
 * Description: Gets value of cost
 * Pre-conditions: None
 * Post-conditions: Returns value of cost
 **************************************************/
int* Animals::get_cost(){
	return &cost;
}

/**************************************************
 * Function: get_babies()
 * Description: Gets value of babies
 * Pre-conditions: None
 * Post-conditions: Returns value of babies
 **************************************************/
int* Animals::get_babies(){
	return &babies;
}

/**************************************************
 * Function: get_food()
 * Description: Gets value of food
 * Pre-conditions: None
 * Post-conditions: Returns value of food
 **************************************************/
int* Animals::get_food(){
	return &food;
}

/**************************************************
 * Function: get_revenue()
 * Description: Gets value of revenue
 * Pre-conditions: None
 * Post-conditions: Returns value of revenue
 **************************************************/
int* Animals::get_revenue(){
	return &revenue;
}

/**************************************************
 * Function: get_sick()
 * Description: Gets value of sick
 * Pre-conditions: None
 * Post-conditions: Returns value of sick
 **************************************************/
bool* Animals::get_sick(){
	return &sick;
}

/**************************************************
 * Function: add_month()
 * Description: adds 1 to animal age
 * Pre-conditions: None
 * Post-conditions: animal age increses by 1
 **************************************************/
void Animals::add_month(){
	age += 1;
}

/**************************************************
 * Function: actual_revnue()
 * Description: Gets value of actual_revenue
 * Pre-conditions: None
 * Post-conditions: Returns value of actual revenue
 **************************************************/
int Animals::actual_revenue(){
	if(age < 6){
		return revenue * 2;
	}else{
		return revenue;
	}
}
