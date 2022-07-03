#include "tools.h"

#include <bitset>
#include <climits>
#include <vector>
#include <numeric>
#include <unordered_map>
#include <algorithm>

using namespace std;

vector<size_t> Tools::sort_indexes(const vector<int> &v) {
    // initialize original index locations
    vector<size_t> idx(v.size());
    iota(idx.begin(), idx.end(), 0);
    // sort indexes based on comparing values in v
    // using std::stable_sort instead of std::sort
    // to avoid unnecessary index re-orderings
    // when v contains elements of equal values
    stable_sort(idx.begin(), idx.end(),
                [&v](size_t i1, size_t i2) {return v[i1] < v[i2];});
    return idx;
}

vector<string> Tools::split (const string& s, const string& delimiter) {
    size_t pos_start = 0, pos_end, delim_len = delimiter.length();
    string token;
    vector<string> res;

    while ((pos_end = s.find (delimiter, pos_start)) != string::npos) {
        token = s.substr (pos_start, pos_end - pos_start);
        pos_start = pos_end + delim_len;
        res.push_back (token);
    }

    res.push_back (s.substr (pos_start));
    return res;
}

string Tools::bstohs(const string& bs) {
    string hs = {};
    auto c = bs.rbegin();
    auto end = bs.rend();
    if (bs.rfind("0b", 0) == 0) {
        end -= 2;
    }
    int localSum = 0;
    while (end - c > 3) {
        localSum = (*c - '0') + ((*(c + 1) - '0') << 1) + ((*(c + 2) - '0') << 2) + ((*(c + 3) - '0') << 3);
        hs = (localSum > 9 ? string(1, 'a' + localSum - 10) : to_string(localSum)) + hs;
        c += 4;
    }
    localSum = 0;
    for (auto lst = c; end - lst > 0; lst++) {
        if (*lst != '0') {
            localSum += ((*lst - '0') << (lst - c));
        }
    }
    hs = to_string(localSum) + hs;
    return "0x" + hs.erase(0, min(hs.find_first_not_of('0'), hs.size() - 1));
}

string Tools::ftoIEEE754s(float value) {
    union {
        float input;   // assumes sizeof(float) == sizeof(int)
        int output;
    } data{};
    data.input = value;
    bitset<sizeof(float) * CHAR_BIT> bits(data.output);
    string resString = bits.to_string<char,
            char_traits<char>,
            allocator<char> >();
    return bstohs(resString);
}

string Tools::dtoIEEE754s(double value) {
    union {
        double input;   // assumes sizeof(float) == sizeof(int)
        long int output;
    } data{};
    data.input = value;
    bitset<sizeof(double) * CHAR_BIT> bits(data.output);
    string resString = bits.to_string<char,
            char_traits<char>,
            allocator<char> >();
    return bstohs(resString);
}