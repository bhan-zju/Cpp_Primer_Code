// prog11_2_1.cpp : 定义关联容器
//

#include <iostream>
#include <map>
#include <set>
#include <vector>

int main()
{
    std::map<std::string, size_t> word_count;   // 空容器
    // 列表初始化
    std::set<std::string> exclude = { "the","but","and","or","an","a"
                                      "The","But","And","Or","An","A" };
    std::map<std::string, std::string> authors = { {"Joyce","James"},
                                                   {"Austen","Jane"},
                                                   {"Dickens","Charles"} };

    // 初始化 multimap 和 multiset
    // 定义一个有20个元素的vector，保存0~9每个整数的两个拷贝
    std::vector<int> ivec;
    for (int i = 0; i != 10; ++i) {
        ivec.push_back(i);
        ivec.push_back(i);
    }
    std::set<int> iset(ivec.cbegin(), ivec.cend());
    std::multiset<int> miset(ivec.cbegin(), ivec.cend());
    std::cout << ivec.size() << std::endl;
    std::cout << iset.size() << std::endl;
    std::cout << miset.size() << std::endl;
}

// 