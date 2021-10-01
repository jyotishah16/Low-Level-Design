#include <bits/stdc++.h>
using namespace std; 
class Player{
public:
	string name;
	int numericId;
	bool isWin;
	vector<pair<int, int>> movesList;
public:
    Player();
	Player(string &name, int id);

    void move(int i, int j);
};
