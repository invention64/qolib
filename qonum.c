#include "qonum.h"
#include "constants.h"

int isPrime(unsigned long long possiblePrime) {
	if(possiblePrime % 2 == 0) {
		return False;
	}

	for(unsigned long x = 3; x < possiblePrime/2; x+=2) {
		if(possiblePrime % x == 0) {
			return False;
		}
	}

	return True;
}