
#include "Dynamic_stack.h"


using namespace std;

int main()
{

	Dynamic_stack<int> dynamic_stack(100);
	auto n = dynamic_stack.capacity();
	dynamic_stack.push(45);
	dynamic_stack.push(45);
	auto j = dynamic_stack.pop();
	auto sdf = dynamic_stack.capacity();
	
	dynamic_stack.push(45);
	 dynamic_stack.push(46);
	 dynamic_stack.push(47);
	dynamic_stack.push(48);
	dynamic_stack.push(45);
	dynamic_stack.push(45);
	dynamic_stack.push(45);
	dynamic_stack.push(45);
	dynamic_stack.push(46);
	dynamic_stack.push(47);

	dynamic_stack.push(85);
	dynamic_stack.push(85);
	dynamic_stack.push(85);
	dynamic_stack.push(86);
	dynamic_stack.push(87);

	dynamic_stack.push(93);
	dynamic_stack.push(94);
	dynamic_stack.push(95);
	dynamic_stack.push(96);
	dynamic_stack.push(97);

	

	dynamic_stack.push(48);
	dynamic_stack.clear();
	dynamic_stack.push(25);
	//auto j =



	return 0;
}