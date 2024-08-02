
#include <iostream>
#include <fstream>
#include <stdexcept>

// RAII class for file handling 
class FileHandle { 
public:
    FileHandle(const std::string& filename) { 
        file.open(filename);
        if ( !file.is_open() ) {
            throw std::runtime_error("Failed to open file");
        }
    }

    ~FileHandle() {
        if (file.is_open()) {
            file.close();
        }
    }

    std::ifstream& getFile() {
        return file;
    }

private:
    std::ifstream file;
};

int main() {
    try {
        FileHandle file("example.txt");
        std::string line;
        while (std::getline(file.getFile(), line)) {
            std::cout << line << std::endl;
        }
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}
