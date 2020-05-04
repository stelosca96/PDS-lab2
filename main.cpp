#include <iostream>
#include "Directory.h"

int main() {
    std::shared_ptr<Directory> root = Directory::getRoot();
    root->addDirectory("Ciao");
    root->addDirectory("pippo");
    root->ls(0);
    auto alfa = root -> addDirectory( "alfa" );
    root -> addDirectory( "beta" )->addFile( "beta1" , 100 );
    root -> getDir( "beta" ) -> addFile( "beta2" , 200 );
    alfa -> getDir( ".." ) -> ls(0);
    root -> remove( "beta" );
    root -> ls(0);
    return 0;
}
