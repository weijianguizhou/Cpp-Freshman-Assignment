#include"Classwork2.2.cpp"
using namespace std;

int main() {
	SqList<int> list(6);
	list.insert(3);
	list.display();
	list.insert(1,3);
	list.display();
	list.deleteValue(3);
	list.display();
	return 0;
}
