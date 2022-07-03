#include <string>
#include <vector>

class Tools {
private:

protected:

public:
    static std::vector<size_t> sort_indexes(const std::vector<int> &v);
    static std::vector<std::string> split(const std::string& s, const std::string& delimiter);
    static std::string bstohs(const std::string& hs);
    static std::string ftoIEEE754s(float value);
    static std::string dtoIEEE754s(double value);
};