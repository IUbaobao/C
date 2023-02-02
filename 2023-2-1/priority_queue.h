#include <vector>


namespace hdm
{
	template<class T>
	class less
	{
	public:
		bool operator()(const T& left, const T&right)
		{
			return left < right;
		}
	};

	template<class T>
	class greater
	{
	public:
		bool operator()(const T& left, const T&right)
		{
			return left > right;
		}
	};

	template <class T, class Container = vector<T>,class Compare=less<T>>
	class priority_queue
	{
	public:
		priority_queue(){}
		
		template <class InputIterator>
		priority_queue(InputIterator first, InputIterator last)
		{
			while (first != last)
			{
				push(*first);
				++first;
			}
		}

		void push(const T& val)
		{
			con.push_back(val);
			AdjustUp(con.size() - 1);
		}

		void pop()
		{
			swap(con[0], con[con.size() - 1]);
			con.pop_back();
			AdjustDown(0);
		}

		T& top()
		{
			return con.front();
		}

		void AdjustDown(int parent)
		{
			int child = parent * 2 + 1;
			while (child<con.size())
			{
				//Ä¬ÈÏ´ó¶Ñ
				//if (child + 1 < con.size() && con[child] < con[child + 1])
				if (child + 1 < con.size() && Compare()(con[child],con[child+1]))
				{
					child++;
				}
				//if (con[parent] < con[child])
				if (Compare()(con[parent], con[child]))
				{
					swap(con[parent], con[child]);
					parent = child;
					child = parent * 2 + 1;
				}
				else
				{
					break;
				}
			}
		}

		size_t size()const
		{
			return con.size();
		}

		bool empty() const
		{
			return con.empty();
		}

		void AdjustUp(int child)
		{
			int parent = (child - 1) / 2;
			while (child>0)
			{
				//if (con[parent] < con[child])
				if (Compare()(con[parent], con[child]))
				{
					swap(con[parent], con[child]);
					child = parent;
					parent = (child - 1) / 2;
				}
				else
				{
					break;
				}
			}

		}
	protected:
		Container con;
	};
}
