#include <iostream>
#include <cmath>
using namespace std;

const float pi = 3.14;
const void print()
{
	cout << "Hello World" << endl;
}

int main(int argc, char* argv[])
{
	int itemid[5] = {1,2,3,4,5},quantity, inputid;
	float itemprice[5] = {10.0f,15.0f,20.0f,13.0f,32.0f}, discount = 0.2f;
	cout << "Enter item id: ";
	cin >> inputid;
	cout << "Enter quantity: ";
	cin >> quantity;

	for (int i = 0; i < sizeof(itemid)/sizeof(itemid[0]); i++)
	{
		if (inputid == i)
		{
			float amount = itemprice[i] * discount * quantity;
			cout << "The amount is: " << amount << endl;
		}
	}

	return 0;
}