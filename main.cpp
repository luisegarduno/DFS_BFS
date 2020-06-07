//
// Created by Luis on 6/7/2020.
//

#include <iostream>
#include "FileReader.h"
#include "SocialNetwork.h"
#include "MissingFilesException.h"

using namespace std;

int main(int argc,char * argv[]) {

    try {
        // if argument counter != 2,throw custom exception
        if (argc != 2)
            throw missingFilesException{};

        else{
            FileReader * controlFile = new FileReader();
            controlFile->setCommands(argv[1]);


            SocialNetwork createNetwork(controlFile);

            delete controlFile;
        }
    }

        // catches custom exception message
    catch (missingFilesException& e) {
        cout << missingFilesException::what() << endl;
    }

    return 0;
}