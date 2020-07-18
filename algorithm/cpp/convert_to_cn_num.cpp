#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <string>
using namespace std;
#define out(content) std::cout << content << std::endl;

std::string convertTh(uint16_t num) {  // convert num less than 10000
    static string DGT[] = {"零","一","二","三","四","五","六","七","八","九"};

    std::string result;
    result.reserve(7);

    uint8_t tho = num / 1000;
    uint8_t hun = num % 1000 / 100;
    uint8_t ten = num % 100 / 10;
    uint8_t one = num % 10;
    if (tho != 0) {
        result.append(DGT[tho]);
        result.append("千");
    }

    if (hun != 0) {
        result.append(DGT[hun]);
        result.append("百");
    } else if (tho != 0 && (ten != 0 || one != 0)) {
        result.append(DGT[hun]);
    }

    if (ten != 0) {
        if (tho !=0 || hun != 0 || ten != 1) {  // '十' or '一十'
            result.append(DGT[ten]);
        }
        result.append("十");
    } else if (hun != 0 && one != 0) {
        result.append(DGT[ten]);
    }

    if (one != 0) {
        result.append(DGT[one]);
    }
    return result;
}

std::string convertCn(uint64_t num) {
    std::string UNT[] = {"万","亿"};
    std::string result;
    int unit = -1;
    auto left = num;
    auto lastPart = 0;
    while (left > 0) {
        auto part = left % 10000;
        auto partCn = convertTh(part);
        if (part != 0) {
            if (lastPart < 1000 && !result.empty()) {
                result.insert(0, partCn + UNT[unit % 2] + "零");
            } else if (left == num) {  // first part
                result.append(partCn);
            } else {
                result.insert(0, partCn + UNT[unit % 2]);
            }
        }
        unit++;
        lastPart = part;
        left = left / 10000;
        if (left > 0 && part == 10) {  // '十' or '一十'
            result.insert(0, "一");
        }
    }
    return result.empty() ? "零" : result;
}

int main(int argc, char** argv) {
    std::vector<uint64_t> in{0, 10, 110, 100010010, 1000000000};
    for (auto& i : in) {
        auto result = convertCn(i);
        out(result);
    }

    return 0;
}
