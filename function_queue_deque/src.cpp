#include<iostream>
#include<stack>
#include<queue>
#include<deque>

using namespace std;

int main() {
	// stack (LILO)

	printf("%s\n", "stack LILO");
	stack<string> stk;
	stk.push("엄");
	stk.push("준");
	stk.push("식");
	stk.push("화");
	stk.push("이");
	stk.push("팅");

	while (stk.size()) {
		cout << stk.top() << endl;
		stk.pop();
	}

	// queue (LIFO)
	printf("%s\n", "quere LIFO");
	queue<int> q;
	q.push(1);
	cout << q.front() << endl;
	q.pop();
	cout << q.size() << endl;


	// deque
	printf("%s\n", "deque FIFO & LIFO");
	deque<int> dq;
	dq.push_front(2);
	dq.push_front(1);
	dq.push_back(3);
	for (int i = 0; i < dq.size(); i++)
	{
		cout << dq[i] << endl;
	}
	printf("%s\n", "deque method");
	cout << dq.front() << endl;
	cout << dq.back() << endl;
	printf("%s\n", "deque size");
	cout << dq.size() << endl;
	dq.pop_back();
	dq.pop_front();
	cout << dq.size() << endl;
	return 0;
};