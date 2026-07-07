#include <iostream>
#include <string>
#include <vector>

int main (){

    int n;
    std::cin >> n;
    std::vector<std::string> words(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> words[i];
        if (words[i].length() > 10) {
            words[i] = words[i][0] + std::to_string(words[i].length() - 2) + words[i][words[i].length() - 1];
        }
    }

    for (int i = 0; i < n; ++i){
        std::cout << words[i] << std::endl;
    }

}