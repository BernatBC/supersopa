#ifndef BLOOMFILTER_HH
#define BLOOMFILTER_HH

#include <string>
#include <vector>
#include <cstring>
#include <math.h>
#include <set>
#include "board.hh"
using namespace std;

class Bloom {

    private:

    uint32_t MB;
    uint32_t MP;
    vector<bool> B; // words
    vector<bool> P; // prefixes of words

    int hash1(string s, bool firstModulus);
    int hash2(string s, bool firstModulus);
    int hash3(string s, bool firstModulus);
    int hash4(string s, bool firstModulus);
    int hash5(string s, bool firstModulus);
    int hash6(string s, bool firstModulus);

    inline uint32_t murmur32_scramble(uint32_t k);

    public:

    Bloom(vector<string>& s, unsigned int nPrefixes);

    void addWord(string s);
    bool checkWord(string s);
    void addPrefix(string s);
    bool checkPrefix(string s);

    void findWords(Board& board);
    void localSearch(Board& board, int i, int j, string& s, set<pair<int, int>>& visitats);
};

#endif