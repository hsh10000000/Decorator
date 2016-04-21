#include"header.h"
using namespace std;

int main()
{
	Ship* ship1(new Iowa);
	Ship* ship2(new NorthCarolina);
	ship1->run();
	ship1->shot();
	cout << "----------------" << endl;
	ship2->run();
	ship2->shot();
	cout << "----------------" << endl;
	Ship* ship3(new Ammu(ship1));
	ship3->run();
	ship3->shot();
	cout << "----------------" << endl;
	Ship* ship4(new ScoutPlane(ship3));
	ship4->run();
	ship4->shot();
	cout << "----------------" << endl;
	Ship* ship5(new ScoutPlane(ship2));
	ship5->run();
	ship5->shot();
	system("pause");
	return 0;
}