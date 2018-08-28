#include <exception>
#include <iostream>
#include <stack>
#include <string>


template<typename T>
class myqueue {
public:
	bool empty() const {
		return stack1.empty() && stack2.empty();
	}

	size_t size() const {
		return stack1.size() + stack2.size();
	}

	T front() {
		if (empty()) {
			throw  "queue is empty!";
		}

		T res;
		if (stack2.size() == 0) {
			while (!stack1.empty()) {
				stack2.push(stack1.top());
				stack1.pop();
			}
		}
		res = stack2.top();

		return res;
	}

	T back() {
		if (empty()) {
			throw  "queue is empty!";
		}

		T res;
		if (stack1.size() == 0) {
			while (!stack2.empty()) {
				stack1.push(stack2.top());
				stack2.pop();
			}
		}
		res = stack1.top();

		return res;
	}

	void push(const T& value) {
		stack1.push(value);
	}

	void pop() {
		if (empty()) {
			throw  "queue is empty!";
		}

		if (stack2.size() == 0) {
			while (!stack1.empty()) {
				stack2.push(stack1.top());
				stack1.pop();
			}
		}
		stack2.pop();
	}

private:
	std::stack<T> stack1; // used to push elements
	std::stack<T> stack2; // used to pop elements
};

int main(int argc, char const *argv[])
{
	myqueue<int> q;
  
	q.push(1);
	q.push(2);
	q.push(3);

	std::cout << "q.top(): " << q.front() << std::endl;
	std::cout << "q.back(): " << q.back() << std::endl;
	
	q.pop();

	std::cout << "q.top(): " << q.front() << std::endl;
	std::cout << "q.back(): " << q.back() << std::endl;

	q.push(4);
	q.push(5);

	std::cout << "q.top(): " << q.front() << std::endl;
	std::cout << "q.back(): " << q.back() << std::endl;

	return 0;
}