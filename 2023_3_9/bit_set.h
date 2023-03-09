#pragma once 

#include <iostream>
#include <vector>
using namespace std;
namespace hdm
{
	template <size_t N>
	class bit_set
	{
	public:
		bit_set()
		{
			_bits.resize(N / 8 + 1,0);
		}

		void set(size_t x)
		{
			size_t i = x / 8;
			size_t j = x % 8;
			
			_bits[i] |= (1 << j);
		}

		void reset(size_t x)
		{
			size_t i = x / 8;
			size_t j = x % 8;
			_bits[i] &= ~(1 << j);
		}

		bool test(size_t x)
		{
			size_t i = x / 8;
			size_t j = x % 8;
			return _bits[i] & (1 << j);
		}

	private:
		vector<char> _bits;
	};


	void test_bit_set()
	{
		//bit_set<100> bs1;
		//bit_set<-1> bs2;
		bit_set<0xffffffff> bs2;

		bs2.set(10);
		bs2.set(10000);
		bs2.set(8888);

		cout << bs2.test(10) << endl;
		cout << bs2.test(10000) << endl;
		cout << bs2.test(8888) << endl;
		cout << bs2.test(8887) << endl;
		cout << bs2.test(9999) << endl << endl;

		bs2.reset(8888);
		bs2.set(8887);

		cout << bs2.test(10) << endl;
		cout << bs2.test(10000) << endl;
		cout << bs2.test(8888) << endl;
		cout << bs2.test(8887) << endl;
		cout << bs2.test(9999) << endl;
	}

}