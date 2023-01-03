#include <list>

namespace hdm
{
	template <class T, class Containce=list<T> >
	class queue
	{
	public:
		void push(const T& val)
		{
			_con.push_back(val);
		}
		void pop()
		{
			_con.pop_front();
		}
		const T& front()
		{
			return _con.front();
		}

		const T& back()
		{
			return _con.back();
		}
		size_t size()const
		{
			return _con.size();
		}

		bool empty() const 
		{
			return _con.empty();
		}

	private:
		Containce _con;
	};
}