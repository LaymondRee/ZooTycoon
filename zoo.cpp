/**************************************************
 * Filename: zoo.cpp
 * Author: Raymond Lee
 * Date: 5-9-2021
 * Description: Contains all components of zoo tycoon style game
 * Input: choose_animal, choose_food
 * Output: Zoo tycoon game
 **************************************************/

#include <iostream>
#include <ctime>
#include <cstdlib>
#include "animals.h"
#include "zoo.h"

using namespace std;

/**************************************************
 * Function: Zoo
 * Description: Initializes Zoo class
 * Pre-conditions: None
 * Post-conditions: Initialized Zoo class
 **************************************************/
Zoo::Zoo(){
	money = 100000;
	n_sealions = 0;
	n_tigers = 0;
	n_blackbears = 0;
	sealions = new Sealion[1];
	tigers = new Tiger[1];
	blackbears = new Blackbear[1];
	base_food = 80;
	food_choice = 3;
	month = 0;
}

/**************************************************
 * Function: ~Zoo
 * Description: Deletes dynamic arrays
 * Pre-conditions: None
 * Post-conditions: Arrays deleted
 **************************************************/
Zoo::~Zoo(){
	delete[] sealions;
	delete[] tigers;
	delete[] blackbears;
}

/**************************************************
 * Function: get_money
 * Description: Gest value of money
 * Pre-conditions: None
 * Post-conditions: returns value of money
 **************************************************/
float Zoo::get_money(){
	return money;
}

/**************************************************
 * Function: add_sealion
 * Description: Adds sealion to new dynamic array
 * Pre-conditions: None
 * Post-conditions: New sealion array with added sealion
 **************************************************/
Sealion* Zoo::add_sealion(){
	n_sealions += 1;

	Sealion* new_sealions = new Sealion[n_sealions];

	//Initializes values for new array using values from original array
	for(int i = 0; i < n_sealions - 1; i++){
		new_sealions[i] = sealions[i];
	}
	delete[] sealions;

	Sealion new_sealion;

	new_sealions[n_sealions - 1] = new_sealion;

	return new_sealions;
}

/**************************************************
 * Function: kill_sealion
 * Description: removes sealion from array
 * Pre-conditions: None
 * Post-conditions: Array with sealion removed
 **************************************************/
void Zoo::kill_sealion(int index){
	n_sealions -= 1;
	
	//Moves all indexes back one starting from chosen animal
	for(int i = index; i < n_sealions - 1; i++){
		sealions[i] = sealions[i + 1];
	}
}

/**************************************************
 * Function: add_tiger
 * Description: Adds tiger to new dynamic array
 * Pre-conditions: None
 * Post-conditions: New tiger array with added tiger
 **************************************************/
Tiger* Zoo::add_tiger(){
	n_tigers += 1;

	Tiger* new_tigers = new Tiger[n_tigers];

	for(int i = 0; i < n_tigers - 1; i++){
		new_tigers[i] = tigers[i];
	}
	delete[] tigers;

	Tiger new_tiger;
	new_tigers[n_tigers - 1] = new_tiger;

	return new_tigers;
}

/**************************************************
 * Function: kill_tiger
 * Description: removes tiger from array
 * Pre-conditions: None
 * Post-conditions: Array with tiger removed
 **************************************************/
void Zoo::kill_tiger(int index){
	n_tigers -= 1;
	
	for(int i = index; i < n_tigers - 1; i++){
		tigers[i] = tigers[i + 1];
	}
}

/**************************************************
 * Function: add_blackbear
 * Description: Adds blackbear to new dynamic array
 * Pre-conditions: None
 * Post-conditions: New blackbear array with added blackbear
 **************************************************/
Blackbear* Zoo::add_blackbear(){
	n_blackbears += 1;

	Blackbear* new_blackbears = new Blackbear[n_blackbears];

	for(int i = 0; i < n_blackbears - 1; i++){
		new_blackbears[i] = blackbears[i];
	}
	delete[] blackbears;

	Blackbear new_blackbear;
	new_blackbears[n_blackbears - 1] = new_blackbear;

	return new_blackbears;
}

/**************************************************
 * Function: kill_blackbear
 * Description: removes blackbear from array
 * Pre-conditions: None
 * Post-conditions: Array with blackbear removed
 **************************************************/
void Zoo::kill_blackbear(int index){
	n_blackbears -= 1;
	
	for(int i = index; i < n_blackbears - 1; i++){
		blackbears[i] = blackbears[i + 1];
	}
}

/**************************************************
 * Function: total_revenue
 * Description: Calculates total revenue
 * Pre-conditions: None
 * Post-conditions: Adds total revenue to money
 **************************************************/
int Zoo::total_revenue(){
	int revenue = 0;

	//Adds revenue produced by each animal
	if(n_sealions > 0){
		for(int i = 0; i < n_sealions; i++){
			revenue += sealions[i].actual_revenue();
		}
	}

	if(n_tigers > 0){
		for(int i = 0; i < n_tigers; i++){
			revenue += tigers[i].actual_revenue();
		}
	}

	if(n_blackbears > 0){
		for(int i = 0; i < n_blackbears; i++){
			revenue += blackbears[i].actual_revenue();
		}
	}
	cout << "Monthly revenue: $" << revenue << endl;
	money += revenue;
}

/**************************************************
 * Function: total_costs
 * Description: Calculates total costs
 * Pre-conditions: None
 * Post-conditions: Subtracts total costs from money
 **************************************************/
//Function longer than 20 lines because it wouldn't make sense to split this function
float Zoo::total_costs(){
	float costs = 0;
	float rate;
	srand(time(NULL));

	rate = ((rand() % 41) / 100.0) + 0.8;
	base_food *= rate;

	//Adds cost from each animal
	if(n_sealions > 0){
		for(int i = 0; i < n_sealions; i++){
			costs += *(sealions[i].get_food());
		}
	}

	if(n_tigers > 0){
		for(int i = 0; i < n_tigers; i++){
			costs += *(tigers[i].get_food());
		}
	}

	if(n_blackbears > 0){
		for(int i = 0; i < n_blackbears; i++){
			costs += *(blackbears[i].get_food());
		}
	}
	costs *= base_food;

	if(food_choice == 1){
		costs /= 2;
	}else if(food_choice == 3){
		costs *= 2;
	}

	cout << "Rate of food change: " << rate << "%" << endl;

	cout << "Monthly costs: $" << costs << endl;
	money -= costs;
}

/**************************************************
 * Function: add_month
 * Description: Adds 1 to all animal's age
 * Pre-conditions: None
 * Post-conditions: All animals aged up
 **************************************************/
void Zoo::add_month(){
	if(n_sealions > 0){
		for(int i = 0; i < n_sealions; i++){
			sealions[i].add_month();
		}
	}

	if(n_tigers > 0){
		for(int i = 0; i < n_tigers; i++){
			tigers[i].add_month();
		}
	}

	if(n_blackbears > 0){
		for(int i = 0; i < n_blackbears; i++){
			blackbears[i].add_month();
		}
	}
}

/**************************************************
 * Function: turn
 * Description: Runs all processes that occur in one month
 * Pre-conditions: None
 * Post-conditions: Plays one month of zoo tycoon
 **************************************************/
void Zoo::turn(){
	print_info();
	special_event();
	buy_animal();
	buy_food();
	print_results();

}

/**************************************************
 * Function: print_info
 * Description: Prints info about player possesions
 * Pre-conditions: None
 * Post-conditions: Info on money and animals owned
 **************************************************/
void Zoo::print_info(){
	b_sealions = 0;
	b_tigers = 0;
	b_blackbears = 0;

	//Determines number of babies
	for(int i = 0; i < n_sealions; i++){
		if(*(sealions[i].get_age()) < 6){
			b_sealions += 1;
		}
	}

	for(int i = 0; i < n_tigers; i++){
		if(*(tigers[i].get_age()) < 6){
			b_tigers += 1;
		}
	}

	for(int i = 0; i < n_blackbears; i++){
		if(*(blackbears[i].get_age()) < 6){
			b_blackbears += 1;
		}
	}

	cout << "----------MONTH" << month << "----------" << endl;
	cout << "Money: $" << money << endl;
	cout << "Total Sealions: " << n_sealions << endl;
	cout << "Baby Sealions: " << b_sealions << endl;
	cout << "Total Tigers: " << n_tigers << endl;
	cout << "Baby Tigers: " << b_tigers << endl;
	cout << "Total Blackbears: " << n_blackbears << endl;
	cout << "Baby Blackbears: " << b_blackbears << endl << endl;
}

/**************************************************
 * Function: buy_animal
 * Description: Gives player option to buy animal
 * Pre-conditions: Choose and amount
 * Post-conditions: Skipped or animal added
 **************************************************/
//Function longer than 20 lines because it wouldn't make sense to split this function
void Zoo::buy_animal(){
	int choose;
	int amount;

	cout << "----------ANIMALS----------" << endl;
	cout << "Would you like to buy animals this month? (1 - Yes) (0 - No)" << endl;
	cin >> choose;

	if(choose == 1){
		cout << "Which of the animals would you like to buy: " << endl;
		cout << "Sealion for $800 (1)" << endl;
		cout << "Tiger for $10000 (2)" << endl;
		cout << "Blackbear for $5000 (3)" << endl;
		cin >> choose;
		cout << "How many would you like to buy? (1 or 2)" << endl;
		cin >> amount;
		cout << endl;

		if(choose == 1){
			money -= 800 * amount;
			for(int i = 0; i < amount; i++){
				sealions = add_sealion();
			}
		}else if(choose == 2){
			money -= 10000 * amount;
			for(int i = 0; i < amount; i++){
				tigers = add_tiger();
			}
		}else if(choose == 3){
			money -= 5000 * amount;
			for(int i = 0; i < amount; i++){
				blackbears = add_blackbear();
			}
		}
	}
}

/**************************************************
 * Function: buy_food
 * Description: Gives player choice between foods
 * Pre-conditions: Food_choice
 * Post-conditions: Food is chosen
 **************************************************/
void Zoo::buy_food(){
	cout << "----------FOODS----------" << endl;
	cout << "Which of the food options would you like to buy: " << endl;
	cout << "Cheap with a base cost of $40 (1)" << endl;
	cout << "Regular with a base cost of $80 (2)" << endl;
	cout << "Premium with a base cost of $160 (3)" << endl;
	cin >> food_choice;
	cout << endl;
}

/**************************************************
 * Function: print_results
 * Description: Prints results from the month
 * Pre-conditions: None
 * Post-conditions: Animal revenue and food costs printed
 **************************************************/
void Zoo::print_results(){
	cout << "----------RESULTS----------" << endl;
	total_revenue();
	total_costs();
	add_month();
	month += 1;
}

/**************************************************
 * Function: special_event
 * Description: Chooses which special event to run
 * Pre-conditions: None
 * Post-conditions: Special event chosen
 **************************************************/
void Zoo::special_event(){
	srand(time(NULL));

	event = rand() % 4;

	cout << "----------EVENT----------" << endl;

	if(event == 0){
		if(food_choice == 1){ //Increases chance of sickness if cheap food was bought
			sick_event();
		}else{
			no_event();
		}
	}else if(event == 1){
		if(food_choice == 3 && rand() % 2 == 1){ //Reduces chance of sickness if premium food was bought
			no_event();
		}else{
			sick_event();
		}
	}else if(event == 2){
		birth_event();
	}else if (event == 3){
		attend_event();
	}
}

/**************************************************
 * Function: no_event
 * Description: Runs processes of no event
 * Pre-conditions: Special event landed on 0
 * Post-conditions: Prints a no event statement
 **************************************************/
void Zoo::no_event(){
	cout << "No event this month" << endl << endl;
}

/**************************************************
 * Function: sick_event
 * Description: Runs processes of sick event
 * Pre-conditions: Special event landed on 1
 * Post-conditions: Subtract expenses from money or animal dies
 **************************************************/
//Function longer than 20 lines because it wouldn't make sense to split this function
void Zoo::sick_event(){
	srand(time(NULL));
	int n_animals;
	int chosen_animal;
	int sick_cost;

	n_animals = n_sealions + n_tigers + n_blackbears;

	if(n_animals == 0){
		no_event();
		return;
	}

	chosen_animal = rand() % n_animals;

	cout << "Sick event this month" << endl;

	if(chosen_animal < n_sealions){
		sick_cost = 400;
		cout << "One of your sealions is sick!" << endl;

		if(sick_cost > money){
			cout << "You do not have enough money to save it, sealion dies!" << endl << endl;
			kill_sealion(chosen_animal);

		}else{
			money -= sick_cost;
			cout << "Expense: $400" << endl << endl;
		}

	}else if(chosen_animal < n_sealions + n_tigers){
		sick_cost = 5000;
		cout << "One of your tigers is sick!" << endl;

		if(sick_cost > money){
			cout << "You do not have enough money to save it, tiger dies!" << endl << endl;
			kill_tiger(chosen_animal - n_sealions);

		}else{
			money -= sick_cost;
			cout << "Expense: $5000" << endl << endl;
		}
	}else{
		sick_cost = 2500;
		cout << "One of your blackbears is sick!" << endl;

		if(sick_cost > money){
			cout << "You do not have enough money to save it, blackbear dies!" << endl << endl;
			kill_blackbear(chosen_animal - n_sealions - n_tigers);

		}else{
			money -= sick_cost;
			cout << "Expense: $2500" << endl << endl;
		}
	}
}

/**************************************************
 * Function: birth_event
 * Description: runs processes of birth event
 * Pre-conditions: Special event landed on 2
 * Post-conditions: Adds babies to array
 **************************************************/
//Function longer than 20 lines because it wouldn't make sense to split this function
void Zoo::birth_event(){
	srand(time(NULL));
	int n_animals;
	int chosen_animal;

	n_animals = n_sealions + n_tigers + n_blackbears;

	if(n_animals == 0){
		no_event();
		return;
	}

	chosen_animal = rand() % n_animals;

	if(chosen_animal < n_sealions){
		if(*(sealions[chosen_animal].get_age()) < 48){ //No event occurs if animal is not an adult
			no_event();
		}else{
			cout << "Birth event this month" << endl;
			cout << "One of your sealions gave birth!" << endl << endl;

			sealions = add_sealion();
			*(sealions[n_sealions - 1].get_age()) = 0;
		}
	}else if(chosen_animal < n_sealions + n_tigers){
		if(*(tigers[chosen_animal - n_sealions].get_age()) < 48){
			no_event();
		}else{
			cout << "Birth event this month" << endl;
			cout << "One of your tigers gave birth!" << endl << endl;

			for(int i = 0; i < 3; i++){
				tigers = add_tiger();
				*(tigers[n_tigers - 1].get_age()) = 0;
			}
		}
	}else{
		if(*(blackbears[chosen_animal - n_sealions - n_tigers].get_age()) < 48){
			no_event();
		}else{
			cout << "Birth event this month" << endl;
			cout << "One of your blackbears gave birth!" << endl << endl;

			for(int i = 0; i < 2; i++){
				blackbears = add_blackbear();
				*(blackbears[n_blackbears - 1].get_age()) = 0;
			}
		}
	}
}

/**************************************************
 * Function: attend_event
 * Description: Runs processes of attend event
 * Pre-conditions: Special event landed on 3
 * Post-conditions: Add bonus revenue to money
 **************************************************/
void Zoo::attend_event(){
	srand(time(NULL));
	int bonus = 0;

	//Generates random number from 150-400 for each sealion
	for(int i = 0; i < n_sealions; i++){
		bonus += (rand() % 251) + 150;
	}

	money += bonus;

	cout << "Attendance event this month" << endl;
	cout << "Bonus: $" << bonus << endl << endl;
}
