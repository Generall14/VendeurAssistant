#include <iostream>
#include "controller/MainStateMachine.hpp"

using namespace std;

int main()
{
	cout << "Start" << endl;

	MainStateMachine mst;
	mst.DoStateMachine();

	cout << "Koniec" << endl;
	return 0;
}
