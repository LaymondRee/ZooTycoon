/**************************************************
 * Filename: driver.cpp
 * Author: Raymond Lee
 * Date: 5-9-2021
 * Description: Plays zoo tycoon style game
 * Input: choose_animal, choose_food, play
 * Output: Zoo tycoon game
 **************************************************/

#include <iostream>
#include "zoo.h"

using namespace std;

int main(){
	int play = 1;
	Zoo game;

	while(play == 1){
		game.turn();

		if(game.get_money() < 0){
			cout << "You have no more money!" << endl;

			return 0;
		}

		cout << endl << "Would you like to coninue playing? (1 - Yes) (0 - No)" << endl;
		cin >>play;
	}

	return 0;
}
