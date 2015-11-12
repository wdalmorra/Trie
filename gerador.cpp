#include <iostream>
#include <cstdlib>
#include <time.h>
using namespace std;
int main(int argc, char const *argv[])
{
	int sorteio;
	srand(time(NULL));

	for (int i = 0; i < 7500; ++i)
	{
		sorteio = rand();

		switch (sorteio%4)
		{
			case 0:
				cout<< "A";
				break;
			case 1:
				cout<< "C";
				break;
			case 2:
				cout<< "G";
				break;
			case 3:
				cout<< "T";
				break;
		}

		 // cout<< char(sorteio%26 + 'A');
	}
	return 0;
}