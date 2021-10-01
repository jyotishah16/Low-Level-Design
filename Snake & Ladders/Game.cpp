#include <iostream>
#include <queue>
#include <map>
#include <vector>
#include <time.h>
#include <stdlib.h>
#include "Board.cpp"

using namespace std;

int main(){
	srand(time(0));

	Dice d; 
		
	Player p1("A", 100);
	Player p2("B", 200);

	queue<Player> nextTurn;
	nextTurn.push(p1);
	nextTurn.push(p2);

	Jumper pos1(43, 10); // snake positions
	Jumper pos2(23, 45); // ladder positions

	vector<Jumper> snakes; snakes.push_back(pos1);
	vector<Jumper> ladders; ladders.push_back(pos2);

	int boardSize = 50;

	map<int, int> currentPosition;
	currentPosition[100] = 0, currentPosition[200] = 0;

	Board b(d, nextTurn, snakes, ladders, currentPosition, boardSize);
	b.PlayGame();
	
	return 0;
}