#include <algorithm>
#include <string>
#include <vector>
#include <set>
#include "profile.h"

using namespace std;

class Learner {
private:
    set<string> dict;

public:
    int Learn(const vector<string> &words) {
        int newWords = 0;
        for (const auto &word : words) {
            const auto&[iter, is_new] = dict.insert(word);
            if (is_new)
                ++newWords;
        }
        return newWords;
    }

    vector<string> KnownWords() {
        return {dict.begin(), dict.end()};
    }
};

int main(){
    {
        LOG_DURATION("dsdsd");
        for (size_t i = 0; i < 600'000'000; ++i);
    }
    return 0;
}