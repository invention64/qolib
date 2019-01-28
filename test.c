//For testing functions in qolib
#include <stdlib.h>
#include <stdio.h>
#include "constants.h"
#include "qolib.h"
#include "qlist.h"
#include "qonum.h"
#include "qonet.h"

int main(void)
{
	TCPClient cli = OpenTCP(GenerateIPv4("1.1.1.1",80));
	return 420; // ecks dee
}
