#include <iostream>
#include <chrono> 
#include <thread>
#include <deque>
using namespace std;
class cPlayer
{
public:
	int x, y;
	cPlayer(int width) { x = width / 2; y = 0; }

};
class cLane
{
private:
	deque<bool> cars;
public:
	cLane(int width)
	{
		for (int i = 0; i < width; i++)
			cars.push_front(false);
	}
	void Move()
	{
		if (rand() % 10 == 1)
			cars.push_front(true);
		else
			cars.push_front(false);
		cars.pop_back();
	}
	bool CheckPos(int pos) { return cars[pos]; }
};

class cGame
{
private:
	bool quit;
public:
	void Draw()
	{

	}
	void Input()
	{

	}
	void Logic()
	{

	}
	void Run()
	{
		while (!quit)
		{
			Input();
			Draw();
			Logic();
			std::this_thread::sleep_for(std::chrono::milliseconds(100));
		}
	}
};

int main()
{

	cLane lane1(20);
	for (int i = 0; i < 20; i++)
	{
		if (lane1.CheckPos(i))
			cout << "1";
		else
			cout << "0";
	}
	lane1.Move();
	cout << endl;
	for (int i = 0; i < 20; i++)
	{
		if (lane1.CheckPos(i))
			cout << "1";
		else
			cout << "0";
	}
	getchar();
	return 0;
}