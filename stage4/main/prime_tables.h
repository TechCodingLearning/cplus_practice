#ifndef MAIN_PRIME_TABLES_H_
#define MAIN_PRIME_TABLES_H_

#include <algorithm>

class PrimeTable {
public:
    virtual ~PrimeTable() = default;

    virtual bool IsPrime(int n) const = 0;

    virtual int GetNextPrime(int p) const = 0;
};

class OnTheFlyPrimeTable : public PrimeTable {
public:
    bool IsPrime(int n) const override {
        if (n <= 1) return false;
        for (int i = 2; i * i <= n; i++) {
            if ((n % i) == 0) return false;
        }
        return true;
    }

    int GetNextPrime(int p) const override {
        if (p < 0) return -1;

        for (int i = p + 1;; i++) {
            if (IsPrime(i)) return i;
        }
    }
};

class PreCalculatedPrimeTable : public PrimeTable {
public:
    // 显示初始化
    explicit PreCalculatedPrimeTable(int max)
        : is_prime_size_(std::max(1, max + 1))
        , is_prime_(new bool[static_cast<size_t>(is_prime_size_)]) {
        this->CalculatePrimesUpTo(is_prime_size_);
    }
    ~PreCalculatedPrimeTable() override {
        delete[] is_prime_;
    }

    bool IsPrime(int n) const override {
        if (n < 0 || n > is_prime_size_) return false;
        return is_prime_[n];
    }

    int GetNextPrime(int p) const override {
        for (int n = p + 1; n < is_prime_size_; n++) {
            if (is_prime_[n]) return n;
        }
        return -1;
    }

private:
    // Euler algorithm to cal primes; O(n)
    void CalculatePrimesUpTo(int max) {

        // Euler
        int primes[is_prime_size_]; // 素数数组
        bool is_marked[is_prime_size_]; // 标记数组
        memset(is_marked, false, sizeof(is_marked));
        memset(primes, -1, sizeof(primes));
        int count = 0; // 素数个数
        for (int i = 2; i < is_prime_size_; i++) {
            if (!is_marked[i]) {
                is_marked[i] = true;
                primes[count++] = i;
            }
            for (int j = 0; j < count && i * primes[j] <= is_prime_size_; j++) {
                is_marked[i * primes[j]] = true;
                if ((i % primes[j]) == 0) break;
            }
        }
        // copy
        memset(is_prime_, false, sizeof(is_prime_));
        for (int i = 0; i < count; i++) {
            is_prime_[primes[i]] = true;
        }
    }

    const int is_prime_size_;
    bool* const is_prime_;

    void operator=(const PreCalculatedPrimeTable& rhs); // 禁用赋值构造函数
};

#endif