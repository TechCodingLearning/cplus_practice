#include<iostream>
#include<mutex>
#include<thread>
#include<atomic>
using namespace std;

mutex g_mutex;

const int a = 10000;
const int b = 100000000;

std::atomic_int g_count{0};

void func1(int) {
	for(int i = 0; i < 10000000; i++) {
		// lock_guard<mutex> lock(g_mutex); // 定义时构造函数加锁，出作用域后析构函数解锁
		unique_lock<mutex> ul_mutex(g_mutex); // 解决lock_guard锁粒度过大问题，自行Unlock解锁
		g_count = a;
		ul_mutex.unlock();
	}
}

void func2(int) {
	for(int i = 0; i < 100000000; i++) {
		lock_guard<mutex> lock(g_mutex);
		g_count = b;
	}
}

void func3(int) {
	for(int i = 0; i < 100000000; i++) {
		lock_guard<mutex> lock(g_mutex);
		if(g_count != a && g_count != b) {
			cout << "error!" << g_count << endl;
		}
	}
}

int main() {

	thread thr1(func1, 0);
	thread thr2(func2, 0);
	thread thr3(func3, 0);

	thr1.join();
	thr2.join();
	thr3.join();

	cout << "finish!" << endl;
	return 0;
}
