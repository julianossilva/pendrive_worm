#include <string>
#include <iostream>
#include <fstream>
#include <filesystem>
#include <Windows.h>

int main()
{
    // Console reconhece UTF8
    SetConsoleOutputCP(CP_UTF8);

    // pasta para o vírus.
    std::string path = "C:\\virus";

    // representação do arquivo
    const auto entry = std::filesystem::directory_entry(path);

    // Cria a pasta se não existir ainda;
    if (!entry.exists())
    {
        bool suc = std::filesystem::create_directory(entry);
    }

    return 0;
}
