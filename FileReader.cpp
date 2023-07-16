//
// Created by Luis on 6/7/2020.
//

#include "FileReader.h"


// Default constructor
FileReader::FileReader(){
    numOfFiles = 0;                 // Total number of files (Should be 2)
    totalDFSreq = 0;                // Total number of Depth First Search request's
    totalBFSreq = 0;                // Total number of Breadth First Search request's


    dfsNode = "";                 // Node for Depth First Search
    bfsNode = "";                 // Node for Breadth First Search
    inputFile = "" ;               // Name of inputFile
    outputFile = "";              // Name of OutputFile
    controlFile = "";             // Name of file containing all commands
    makeConnection_1 = "";        // string of first connection (used with mc)
    makeConnection_2 = "";        // string of first connection (used with mc)

}

void FileReader::setCommands(const char argv[]) {
    setFileName(argv);

    string word;
    while (!cfin.eof()) {
        cfin >> word;

        if(word == "or"){
            cfin >> word;
            setInputFile(word);
        }

        if(word == "ow"){
            cfin >> word;
            setOutputFile(word);
        }

        if(word == "dfs"){
            cfin >> word;
            setDfsNode(word);
            totalDFSreq++;
        }

        if(word == "bfs"){
            cfin >> word;
            setBfsNode(word);
            totalBFSreq++;
        }

        if(word == "mc"){
            cfin >> word;
            setConnection_1(word);

            cfin >> word;
            setConnection_2(word);
        }

    }

    closeFiles();
}

void FileReader::setFileName(const char filename[]){
    controlFile = filename;

    int outputFilename_size = controlFile.size();
    string backupControlFile = controlFile + ".txt";

    string file_extension;
    file_extension += controlFile[outputFilename_size - 4];
    file_extension += controlFile[outputFilename_size - 3];
    file_extension += controlFile[outputFilename_size - 2];
    file_extension += controlFile[outputFilename_size - 1];

    if(file_extension != ".txt"){
        cfin.open(backupControlFile.c_str());
        if(!cfin.is_open()){
            cout << "'" << controlFile << "' or '" << backupControlFile << "' could not be opened. Please check command line." << endl;
            exit(-1);
        }
        controlFile = backupControlFile;
    }
    else{
        cfin.open(controlFile.c_str());
        if(!cfin.is_open()){
            cout << "'" << controlFile << "' could not be opened. Please check command line." << endl;
            exit(-1);
        }
    }

}

void FileReader::setInputFile(string file){
    inputFile = move(file);
}

string FileReader::getInputFile(){
    return inputFile;
}

void FileReader::setOutputFile(string file){
    outputFile = move(file);
}

string FileReader::getOutputFile(){
    return outputFile;
}

void FileReader::setDfsNode(string node){
    dfsNode = move(node);
}

string FileReader::getDfsNode(){
    return dfsNode;
}

void FileReader::setBfsNode(string node){
    bfsNode = move(node);
}

string FileReader::getBfsNode(){
    return bfsNode;
}

void FileReader::setDC(bool aDC){
    isDC = aDC;
}

bool FileReader::checkDC(){
    return isDC;
}

void FileReader::closeFiles(){
    cfin.close();
}

void FileReader::setConnection_1(string connect1){
    makeConnection_1 = move(connect1);
}

string FileReader::getConnection_1(){
    return makeConnection_1;
}

void FileReader::setConnection_2(string connect2){
    makeConnection_2 = move(connect2);
}

string FileReader::getConnection_2(){
    return makeConnection_2;
}

int FileReader::getTotalDFSreq(){
    return totalDFSreq;
}

int FileReader::getTotalBFSreq(){
    return totalBFSreq;
}


// FileReader destructor
FileReader::~FileReader()= default;
