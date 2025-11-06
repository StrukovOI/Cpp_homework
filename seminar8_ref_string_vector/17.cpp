#include <iostream>
#include <vector>
#include <cstdio>
#include <cctype>

std::vector<std::vector<std::size_t>> calculate_word_lengths(const std::string& name)
{
    std::vector<std::vector<std::size_t>> res;
    
    FILE* file = fopen(name.c_str(), "r");
    
    char mass[100];
    std::vector<std::size_t> len;
    std::size_t wlen = 0;
    bool fl = false;
    
    while (fgets(mass, sizeof(mass), file))
    {
        for (int i = 0; mass[i] != '\0'; ++i)
        {
            char c = mass[i];
            
            if (c == '\n')
            {
                if (fl)
                {
                    len.push_back(wlen);
                    wlen = 0;
                    fl = false;
                }
                
                if (!len.empty())
                {
                    res.push_back(len);
                    len.clear();
                }
            }

            else if (std::isspace(c))
            {
                if (fl)
                {
                    len.push_back(wlen);
                    wlen = 0;
                    fl = false;
                }
            }

            else
            {
                wlen++;
                fl = true;
            }
        }
    }
    
    if (fl)
    {
        len.push_back(wlen);
    }
    if (!len.empty())
    {
        res.push_back(len);
    }
    
    fclose(file);
    return res;
}


int main()
{
    std::vector<std::vector<std::size_t>> lenghts = calculate_word_lengths("words.txt");
}