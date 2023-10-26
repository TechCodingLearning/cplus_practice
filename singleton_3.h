
// class Singleton{
// private:
// 	static Singleton* instance;
// 	static pthread_mutex_t mutex;
// 	Singleton(){}
// 	Singleton(const Singleton &tmp){}
// 	Singleton& operator=(const Singleton &tmp){}
// public:
// 	static Singleton* getInstance() {
// 		pthread_mutex_lock(&mutex);
// 		if(instance == nullptr) {
// 			instance = new Singleton();
// 		}
// 		pthread_mutex_unlock(&mutex);
// 		return instance;
// 	}
// };

// Singleton* Singleton::instance=nullptr;
// pthread_mutex_t Singleton::mutex;
