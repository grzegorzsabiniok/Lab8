#include"Board.h"
#include<conio.h>
int main() {
	Board board;
	char decision;
	std::cout << "sterowanie: \n\tq-wyjscie\n\tw,s,a,d - poruszanie sie \n\nwczytac z pliku?(t/n)";
	std::cin >> decision;
	if (decision == 't') {
		board.Read("test");
	}
	else {
		board.RandomMap(20, 15, 2, 2, 2, 3);
	}
	board.Show();
	board.Start();
	board.Write("test");
	_getch();
}