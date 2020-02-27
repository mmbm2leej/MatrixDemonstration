#include <iostream>
#include <windows.h>


int GetChar(int generate, char cBase, int range) {
	return (cBase + (generate % range));
}

int main() {
	HANDLE hConsole;
	//HANDLE: windows-specific type, refers to a Windows object, like a pointer does. 

	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, 2);
	//returns handle to the console window buffer

	char caRow[80];
	int a = 7, b = 2, c = 5, d = 1;

	while (true) {
		int i = 0;
		while (i < 80) {
			if (caRow[i] != ' ') {
				caRow[i] = GetChar(a + (i * i), 40, 130);
				if (((i * i + b) % 90) == 0) {
					SetConsoleTextAttribute(hConsole, 7);
				}
				else SetConsoleTextAttribute(hConsole, 2);
				//7 = light green, 2 = green
			}
			std::cout << caRow[i];
			i++;
			SetConsoleTextAttribute(hConsole, 2);


		}
		
		//randomize
		a += (rand() % 100) + 20;
		b += (rand() % 100) + 31;
		c += (rand() % 100) + 11;
		d += (rand() % 100) + 73;

		caRow[(a % 80)] = '-';
		caRow[(b % 80)] = ' ';
		caRow[(c % 80)] = '-';
		caRow[(d % 80)] = ' ';
		

		Sleep(14);
		//short delay
	}




	return 0;
}