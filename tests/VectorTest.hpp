#include "../vector/Vector.hpp"
#include <vector>

template<class T>
class VectorTest
{
private:
	ft::vector<T> _ftVec;
	std::vector<T> _stdVec;

public:
	void reset();
	void push_back(T& value);
	void pop();
};
