#pragma once 

#include <iostream>
#include <vector>
#include <bitset>
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



template <size_t N>
class twobitset
{
public:
	void set(size_t x)
	{
		//一次都没有出现
		if (_bs1.test(x) == 0 && _bs2.test(x) == 0)
		{
			_bs1.set(x);
		}
		//出现一次
		else if (_bs1.test(x) == 1 && _bs2.test(x) == 0)
		{
			_bs1.reset(x);
			_bs2.set(x);
		}
		else 
		{
			//出现两次或者两次以上
		}

	}
	void PirntOnce()
	{
		for (int i = 0; i < N; ++i)
		{
			if (_bs1.test(i) && !_bs2.test(i))
			{
				cout << i << endl;
			}
		}
	}
private:
	bitset<N> _bs1;
	bitset<N> _bs2;
};



void test_twobitset()
{
	twobitset<100> tbs;
	int a[] = { 3,1,1,2,2,4,5,5,6,6,7,8,9,10,10 };
	for (auto e : a)
	{
		tbs.set(e);
	}

	tbs.PirntOnce();
}



