#include <iostream>
#include <queue>
#include <map>
#include <vector>
#include "Dice.cpp"
#include "Player.cpp"
#include "Jumper.cpp"
using namespace std;

class Board {
	Dice d;
	queue<Player> nextTurn;
	vector<Jumper> snakes;
	vector<Jumper> ladders;
	map<int, int> currentPosition;
	int boardSize;

public:
	Board(Dice d, queue<Player> nextTurn, vector<Jumper> snakes, vector<Jumper> ladders, map<int, int> mp, int boardSize) {
		this->d = d;
		this->nextTurn = nextTurn;
		this->snakes = snakes;
		this->ladders = ladders;
		this->currentPosition = mp;
		this->boardSize = boardSize;
	}

	void PlayGame() {
		while(nextTurn.size() > 1) {
			Player p = nextTurn.front(); nextTurn.pop();
			int _id = p.id;
			int curr = currentPosition.at(_id);

			// Roll the dice
			int val = d.rollDice();

			int nextCell = curr + val;

			if(nextCell > boardSize) {
				nextTurn.push(p);
			}
			else if(nextCell == boardSize) {
				cout << p.name << " Wins!!";
				return;
			} 
			else {
				// find whether next cell has a snake or ladder or a normal cell
				int nextPosition = nextCell; 

				// for snake
				for(auto snake : snakes) {
					if(snake.start == nextPosition) {
						nextPosition = snake.end;
						break;
					}
				}

				if(nextCell != nextPosition) {
					cout << p.name << " Bitten by snake\n";
				}
				else {
					// for ladder
					for(auto ladder : ladders) {
						if(ladder.start == nextPosition) {
							nextPosition = ladder.end;
							break;
						}
					}

					if(nextCell != nextPosition) {
						cout << p.name << " found ladder\n";
					}
				}
				nextCell = nextPosition;

				if(nextCell == boardSize) {
					cout << p.name << " Wins!!";
					return;
				}
				else currentPosition[_id] = nextCell; // updating the curent pos

				nextTurn.push(p);
			}
			cout << p.name << " " << currentPosition[p.id] << '\n'; 
		}
		cout << "Some Error Occured";
	}
	
};