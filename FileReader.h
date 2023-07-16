//
// Created by Luis on 6/7/2020.
//

#ifndef DEPTHFIRSTSEARCH_BREADTHFIRST_FILEREADER_H
#define DEPTHFIRSTSEARCH_BREADTHFIRST_FILEREADER_H

#include <iostream>
#include <fstream>
#include <utility>

using std::cout;
using std::endl;
using std::move;
using std::string;
using std::ifstream;
using std::ofstream;

class FileReader {
public:
    // Default constructor
    FileReader();

    // Used as constructor
    void setCommands(const char []);

    void setInputFile(string);      // setter for inputFile


    string getDfsNode();            // (getter) returns DFS node as string
    string getBfsNode();            // (getter) returns BFS node as string
    string getInputFile();          // (getter) returns inputFile
    string getOutputFile();         // (getter) returns outputFile
    string getConnection_1();       // (getter) returns makeConnection_1;
    string getConnection_2();       // (getter) returns makeConnection_2;
    bool checkDC();

    int getTotalDFSreq();
    int getTotalBFSreq();

    void closeFiles();              // closes all open files

    ~FileReader();

private:
    int numOfFiles;                 // Total number of files (Should be 2)
    int totalDFSreq;                // Total number of Depth First Search request's
    int totalBFSreq;                // Total number of Breadth First Search request's

    ifstream cfin;                  // Reads in from controlFile;

    string dfsNode;                 // Node for Depth First Search
    string bfsNode;                 // Node for Breadth First Search
    string inputFile;               // Name of inputFile
    string outputFile;              // Name of OutputFile
    string controlFile;             // Name of file containing all commands
    string makeConnection_1;        // string of first connection (used with mc)
    string makeConnection_2;        // string of first connection (used with mc)

    void setDfsNode(string);        // setter for DFS node
    void setBfsNode(string);        // setter for BFS node
    void setOutputFile(string);     // setter for outputFile
    void setConnection_1(string);   // First node for mc
    void setConnection_2(string);   // Second node for mc
    void setFileName(const char []);// setter name for ControlFile
    void setDC(bool);
    bool isDC;

};


#endif //DEPTHFIRSTSEARCH_BREADTHFIRST_FILEREADER_H
