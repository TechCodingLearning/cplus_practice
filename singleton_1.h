
// // 懒汉式
// class Singleton{
// private:
// 	static Singleton* instance;
// 	Singleton(){}
// 	Singleton(const Singleton &tmp){}
// 	Singleton& operator=(const Singleton &tmp){}
// public:
// 	static Singleton* getInstance() {
// 		if(instance == nullptr) {
// 			instance = new Singleton();
// 		}
// 		return instance;
// 	}
// };

// Singleton* Singleton::instance=nullptr;
