#pragma once

#include <chrono>
#include <random>
#include <iostream>
#include <string>

class LogDuration {
public:
    explicit LogDuration(const std::string &msg = "")
            : message(msg + ": "), start(std::chrono::steady_clock::now()) {
    }

    ~LogDuration() {
        auto finish = std::chrono::steady_clock::now();
        auto dur = finish - start;
        std::cerr << message
                  << std::chrono::duration_cast<std::chrono::milliseconds>(dur).count()
                  << " ms" << std::endl;
    }

private:
    std::string message;
    std::chrono::steady_clock::time_point start;
};

class RandMachine{
public:
    RandMachine(int lowest, int highest): gen(rd()), distrib(lowest, highest){}

    int rand_int(){
        return distrib(gen);
    }
private:
    std::random_device rd;
    std::mt19937 gen;
    std::uniform_int_distribution<> distrib;
};

int RandInt(int lowest, int highest) {
        std::random_device rd;  //Will be used to obtain a seed for the random number engine
        std::mt19937 gen(rd()); //Standard mersenne_twister_engine seeded with rd()
        std::uniform_int_distribution<> distrib(lowest, highest);
        return distrib(gen);
}


#define UNIQ_ID_IMPL(lineno) _a_local_var_##lineno
#define UNIQ_ID(lineno) UNIQ_ID_IMPL(lineno)

#define LOG_DURATION(message) \
  LogDuration UNIQ_ID(__LINE__){message}
