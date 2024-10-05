#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>

std::string reverseWords(const std::string& input) {
    std::stringstream ss(input); // Create a stringstream from the input string
    std::string word;
    std::vector<std::string> words;

    // Extract words from the string and store them in a vector
    while (ss >> word) {
        words.push_back(word);
    }

    // Reverse the order of the words in the vector
    std::reverse(words.begin(), words.end());

    // Join the words back into a single string
    std::string result;
    for (size_t i = 0; i < words.size(); ++i) {
        result += words[i];
        if (i != words.size() - 1) {
            result += " "; // Add space between words, but not after the last word
        }
    }

    return result;
}

int main() {
    std::string input = "I love my country";
    std::string reversed = reverseWords(input);

    std::cout << "Original: " << input << std::endl;
    std::cout << "Reversed: " << reversed << std::endl;

    return 0;
}
