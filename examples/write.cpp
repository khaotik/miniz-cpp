#include <iostream>
#include <miniz.hpp>

int main(int argc, char *argv[]) {
    if(argc <= 1) {
        std::cout << "usage: " << argv[0] << " filename" << std::endl;
        return 1; }
    miniz::zip_file file;
    file.writestr("file1.txt", "this is file 1");
    file.writestr("file2.txt", "this is file 2");
    file.writestr("file3.txt", "this is file 3");
    file.writestr("file4.txt", "this is file 4");
    file.writestr("file5.txt", "this is file 5");
    
    file.save(argv[1]);
    
    return 0;
}
