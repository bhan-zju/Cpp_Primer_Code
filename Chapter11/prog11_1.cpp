// prog11_1.cpp : 关联容器map和set
//

#include <iostream>
#include <map>
#include <set>

int main()
{
    // 使用 map 统计 输入流中 每个单词 出现的次数
    std::map<std::string, size_t> word_count;      // 关键字是string类型，值是size_t类型
    // 使用 set 保存想忽略的单词
    std::set<std::string>  exclude = { "The","But","And","Or","An","A",
                                        "the","but","and","or","an","a" };
    std::string word;
    while (std::cin >> word) {
        //只统计不在 exclude 中的单词
        if (exclude.find(word) == exclude.end())   // .find()返回一个跌倒器，如果给定关键字在set中，则迭代器指向该关键字，否则，返回 尾后迭代器
            ++word_count[word];                 // 如果word不再word_count中，下标运算符会创建一个新元素，其关键字为word，值为0
    }
    
    // 打印结果
    for (const auto& w : word_count)             // w是pair类型的对象
        std::cout << w.first << " occurs " << w.second << ((w.second > 1) ? " times" : " time") << std::endl;

    return 0;
}

// 