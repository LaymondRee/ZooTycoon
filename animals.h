/**************************************************
 * Filename: animals.h
 * Author: Raymond Lee
 * Date: 5-9-2021
 * Description: Contains all members of Animals class
 **************************************************/

#ifndef ANIMALS_H
#define ANIMALS_H

class Animals{
	private:
		int age;
		int cost;
		int babies;
		int food;
		int revenue;
		bool sick;
	public:
		Animals();
		int* get_age();
		int* get_cost();
		int* get_babies();
		int* get_food();
		int* get_revenue();
		bool* get_sick();
		void add_month();
		int actual_revenue();
};

#endif
