#include <iostream>
#include "Directory.h"

int main() {
    std::shared_ptr<Directory> root = Directory::getRoot();
    root->addDirectory("Ciao");
    root->addDirectory("pippo");
    root->ls(2);
    return 0;
}
