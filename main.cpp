//
// Updated by Luis G. on 07/16/2023.
//

#include <iostream>
#include "FileReader.h"
#include "MissingFilesException.h"

using namespace std;

int main(int argc,char * argv[]) {

    try {
        // if argument counter != 2,throw custom exception
        if (argc != 2)
            throw MissingFilesException{};

        else{
            FileReader * controlFile = new FileReader();
            controlFile->setCommands(argv[1]);

            delete controlFile;
        }
    }

        // catches custom exception message
    catch (MissingFilesException& e) {
        cout << MissingFilesException::what() << endl;
    }

    return 0;
}