#include <iostream>
#include <fstream> //file stream
#include <string>


int main(int argc, char** argv)
{
    if (argc != 4)
    {
        std::cerr << "Usage: ./sed_is_for_losers <filename> <s1> <s2>" << std::endl;
        return 1;
    }
    
    std::string filename = argv[1];
    std::string s1 = argv[2];
    std::string s2 = argv[3];
    if (s1.empty())
    {
        std::cerr << "Error: s1 must not be empty" <<std::endl;
        return 1;
    }
    
    std::ifstream   myReadFile(filename.c_str());//Returns a C-style \0 null-terminated string(required by ifstream)
    if (!myReadFile)
    {
        std::cerr << "Error: cannot open file" << std::endl;
        return 1;
    }

    std::string content;
    std::string line;
    while (std::getline(myReadFile, line))
    {
        content += line;
        if (!myReadFile.eof())
            content += '\n';
    }

    std::string result;
    size_t      position = 0;
    size_t      found;
    while (true)
    {
        found = content.find(s1, position);
        if (found == std::string::npos)
            break ;
        result.append(content.substr(position, found - position));
        result.append(s2);
        position = found + s1.length();
    }
    result.append(content.substr(position));

    
    std::ofstream myWriteFile((filename + ".replace").c_str());
    if (!myWriteFile)
    {
        std::cerr << "Error: cannot create file" << std::endl;
        return 1;
    }
    myWriteFile << result;
    myWriteFile.close();

    return 0;
}
