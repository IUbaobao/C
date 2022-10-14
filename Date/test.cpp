#include"Date.h"

int main()
{
	Date d1(2022, 10, 11);
	Date d2(2022, 10, 12);

	//cout << (d1 != d2) << endl;
	//cout << (d1 > d2) << endl;
	//cout << (d1 >= d2) << endl;
	//cout << (d1 < d2) << endl;
	//cout << (d1 <= d2) << endl;

	 const Date d3(d1);
	//d3 += 1000;
	//d3.Print();
	//d3 -= 1000;
	//d3.Print();

	//(d3--).Print();
	//(--d3).Print();
	//(d3++).Print();
	//(++d3).Print();

	//cout << (d3 - d1) << endl;
	//cout << d3 << d1;
	//cin  >> d1;
	//cout << d3 << d1;

	 Date d5;
	 d5 = d1;

	 cout << d5;

	return 0;
}