#include <iostream>
#include <string>
using namespace std;

class Stack {
	char* ptr;
	int maxSize;
	int current;

public:
	Stack(int size = 200);
	Stack(const Stack& other);
	~Stack();
	Stack& operator=(const Stack& other) = delete;

	void push(char value);
	void pop();
	char top();
	bool empty() const;
	int size() const;
};

Stack::Stack(int size) : maxSize(size), current(-1)
{
	ptr = new char[maxSize];
}

Stack::Stack(const Stack& other)
{
	maxSize = other.maxSize;
	current = other.current;
	ptr = new char[maxSize];
	for (int i = 0; i <= current; i++) {
		ptr[i] = other.ptr[i];
	}
}

Stack::~Stack()
{
	delete[] ptr;
}


void Stack::push(char value) {
	if (current >= maxSize - 1) {
		maxSize *= 2;
		char* temp = new char[maxSize];
		for (int i = 0; i <= current; i++)
			temp[i] = ptr[i];
		delete[] ptr;
		ptr = temp;
	}
	ptr[++current] = value;
}

void Stack::pop()
{
	if (!empty()) current--;
}

char Stack::top()
{
	if (empty()) {
		cout << "Exception: stack is empty\n";
		exit(-1);
	}
	return ptr[current];
}

bool Stack::empty() const
{
	return current == -1;
}

int Stack::size() const
{
	return current + 1;
}

bool isOpening(char c) {
	return c == '(' || c == '[' || c == '{';
}

bool isClosing(char c) {
	return c == ')' || c == ']' || c == '}';
}

bool matches(char open, char close) {
	return (open == '(' && close == ')') ||
		   (open == '[' && close == ']') ||
		   (open == '{' && close == '}');
}

int main() {
	string s;
	cout << "Enter expression: ";
	getline(cin, s);

	Stack st;

	for (int i = 0; i < s.size(); i++) {
		char c = s[i];
		if (c == '.') break;

		if (isOpening(c)) {
			st.push(c);
		}
		else if (isClosing(c)) {
			if (st.empty()) {
				cout << "Error: closing bracket '" << c
					<< "' without opening one. Position: " << i + 1 << endl;
				return 0;
			}
			char top = st.top();
			if (!matches(top, c)) {
				cout << "Error: mismatched brackets '" << top
					<< "' and '" << c << "'. Position: " << i + 1 << endl;
				return 0;
			}
			st.pop();
		}
	}

	if (!st.empty()) {
		cout << "Error: some opening brackets not closed"
			<< "Last unclosed: '" << st.top() << "'" << endl;
	}
	else {
		cout << "Expression is correct! All brackets properly matched" << endl;
	}
}