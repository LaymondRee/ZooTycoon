/**************************************************
 * Filename: zoo.h
 * Author: Raymond Lee
 * Date: 5-9-2021
 * Description: Contains all members of Zoo class
 **************************************************/

#ifndef ZOO_H
#define ZOO_H

#include "animals.h"
#include "sealion.h"
#include "tiger.h"
#include "blackbear.h"

class Zoo: public Animals{
	private:
		float money;
		int n_sealions;
		int n_tigers;
		int n_blackbears;
		int b_sealions;
		int b_tigers;
		int b_blackbears;
		Sealion* sealions;
		Tiger* tigers;
		Blackbear* blackbears;
		float base_food;
		int food_choice;
		int month;
		int event;

	public:
		Zoo();
		~Zoo();
		float get_money();
		Sealion* add_sealion();
		Tiger* add_tiger();
		Blackbear* add_blackbear();
		void kill_sealion(int);
		void kill_tiger(int);
		void kill_blackbear(int);
		int total_revenue();
		float total_costs();
		void add_month();
		void turn();
		void print_info();
		void buy_animal();
		void buy_food();
		void print_results();
		void special_event();
		void no_event();
		void sick_event();
		void birth_event();
		void attend_event();
	
};

#endif
