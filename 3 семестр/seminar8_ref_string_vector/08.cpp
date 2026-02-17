#include <iostream>
#include <string>
#include <cctype>

void countLetters(const std::string& str, int& numLetters, int& numDigits)
{
    numLetters = 0;
    numDigits = 0;
    
    for (size_t i = 0; i < str.length(); ++i)
    {
        char ch = str[i];
        
        if(std::isalpha(ch))
        {
            numLetters++;
        }

        else if(std::isdigit(ch))
        {
            numDigits++;
        }
    }

}

int main()
{
    std::string str = "456d7f6879y80u9y8t7rysrterstcvghbjpuyo8ttyd";
    int letters, digits;
    
    countLetters(str, letters, digits);
    std::cout << "Буквы: " << letters << std::endl;
    std::cout << "Цифры: " << digits << std::endl;
}