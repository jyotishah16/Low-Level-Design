#include <stdlib.h>

class Dice {
public:
	int rollDice() {
		return rand() % 6 + 1;
	}
};
