#include <iostream>
#include <vector>
#include <chrono>

using namespace std;
using namespace std::chrono;

struct coord
{
	int x;
	int y;
};

bool CheckIfSame(coord& A, coord& B) {

	bool a = A.x == B.x;
	bool b = A.y == B.y;

	return a && b;
	
}

void drawGrid(coord& Current, coord& Finish, coord& Start) {

	for (int i = 0; i <= 20; i++)
	{
		for (int j = 0; j <= 40; j++) {

			coord temp;
			temp.y = i;
			temp.x = j;
			
			if (CheckIfSame(temp,Start))
			{
				cout << "A";
			}
			else if (CheckIfSame(temp, Current))
			{
				cout << "X";
			}

			else if (CheckIfSame(temp, Finish))
			{
				cout << "B";
			}
			else
			{
				cout << "-";
			}


		}
		cout << endl;
	}

}

void OperationY(coord& Current, coord& Finish) {

	if (Current.y == Finish.y)
	{
		return;
	}
	else if (Current.y < Finish.y)
	{
		Current.y = Current.y + 1;
	}
	else if (Current.y > Finish.y)
	{
		Current.y = Current.y - 1;
	}


}

void OperationX(coord& Current, coord& Finish) {

	if (Current.x == Finish.x)
	{
		return;
	}
	else if (Current.x < Finish.x)
	{
		Current.x = Current.x + 1;
	}
	else if (Current.x > Finish.x)
	{
		Current.x = Current.x - 1;
	}

}

int main() {

	coord Start;
	coord Current;
	coord Finish;

	cout << "Unesite redak pocetne koordinate : ";
	cin >> Start.y;
	cout << "Unesite stupac pocetne koordinate : ";
	cin >> Start.x;
	
	Current = Start;

	cout << "Unesite redak zavrsne koordinate : ";
	cin >> Finish.y;
	cout << "Unesite stupac zavrsne koordinate : ";
	cin >> Finish.x;

	auto clock = high_resolution_clock::now();
	auto begin = std::chrono::high_resolution_clock::now();

	while (!CheckIfSame(Current,Finish))
	{
		system("CLS");
		

		OperationY(Current, Finish);
		OperationX(Current, Finish);

		auto end = std::chrono::high_resolution_clock::now();
		
		if (std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count() >= 100)
		{
			drawGrid(Current, Finish, Start);
			begin = std::chrono::high_resolution_clock::now();
		}
		

	}



	return 0;
}