#include "profile.h"
#include <algorithm>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <random>

using namespace std;

class RouteManager {
public:
    void AddRoute(int start, int finish) {
        reachable_lists_[start].insert(finish);
        reachable_lists_[start].insert(start);
        reachable_lists_[finish].insert(start);
        reachable_lists_[finish].insert(finish);
    }

    int FindNearestFinish(int start, int finish) const {
        if (reachable_lists_.find(start) == reachable_lists_.end()) {
            return abs(start - finish);
        }
        const auto &cur_set = reachable_lists_.at(start);
        auto nearest = cur_set.upper_bound(finish);
        if (nearest == cur_set.end()) {
            return finish - *next(nearest, -1);
        } else if (nearest == cur_set.begin()) {
            return *nearest - finish;
        } else {
            return min(finish - *next(nearest, -1), *nearest - finish);
        }
    }

//    void Test(){
//        LOG_DURATION("test");
//        std::random_device rd;  //Will be used to obtain a seed for the random number engine
//        std::mt19937 gen(rd()); //Standard mersenne_twister_engine seeded with rd()
//        std::uniform_int_distribution<> distrib(-1'000'000'000, 1'000'000'000);
//        for (int i = 0; i < 100'000; ++i) {
//            AddRoute(distrib(gen), distrib(gen));
//        }
//        for (int i = 0; i < 100'000; ++i) {
//            FindNearestFinish(distrib(gen), distrib(gen));
//        }
//    }

private:
    map<int, set<int>> reachable_lists_;
};


int main() {
//    {
//        LOG_DURATION("whole old foo");
//        for (int i = 0; i < 1'000'000'000; ++i) {
//            RandInt(1, 100'000'000);
//        }
//    }
//
//    {
//        LOG_DURATION("whole new foo");
//        RandMachine r(1, 100'000'000);
//        for (int i = 0; i < 1'000'000'000; ++i) {
//            r.rand_int();
//        }
//    }
//
//    {
//        LOG_DURATION("random device");
//        for (int i = 0; i < 1'000'000; ++i) {
//            std::random_device rd;
//        }
//    }
//
//    {
//        LOG_DURATION("generator");
//        for (int i = 0; i < 1'000'000; ++i) {
//            std::mt19937 gen;
//        }
//    }
//
//    {
//        LOG_DURATION("distributor");
//        for (int i = 0; i < 1'000'000; ++i) {
//            std::uniform_int_distribution<> distrib;
//        }
//    }
//    return 0;
    RouteManager routes;

//    routes.Test();
//
//    return 0;
    int query_count;
    cin >> query_count;

    for (int query_id = 0; query_id < query_count; ++query_id) {
        string query_type;
        cin >> query_type;
        int start, finish;
        cin >> start >> finish;
        if (query_type == "ADD") {
            routes.AddRoute(start, finish);
        } else if (query_type == "GO") {
            cout << routes.FindNearestFinish(start, finish) << "\n";
        }
    }

    return 0;
}
