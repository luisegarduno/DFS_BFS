//
// Created by Luis on 6/7/2020.
//

#include "SocialNetwork.h"

SocialNetwork::SocialNetwork(FileReader * commandList){
    /*
     cout << "mc " << commandList->getConnection_1() << " " << commandList->getConnection_2() << endl;
     commandList->checkDC() ? (cout << "dc" << endl) : (cout << endl) ;
     */

    readInputFile(commandList->getInputFile());

    if((commandList->getTotalBFSreq() != 0) || commandList->getTotalDFSreq() != 0){
        int outputFilename_size = commandList->getOutputFile().size();
        string backupControlFile = commandList->getOutputFile() + ".txt";

        string file_extension;
        file_extension += commandList->getOutputFile()[outputFilename_size - 4];
        file_extension += commandList->getOutputFile()[outputFilename_size - 3];
        file_extension += commandList->getOutputFile()[outputFilename_size - 2];
        file_extension += commandList->getOutputFile()[outputFilename_size - 1];

        if(file_extension != ".txt"){
            fout.open(backupControlFile.c_str(), ios::out);
            if(!fout.is_open()){
                cout << "'" << commandList->getOutputFile() << "' or '" << backupControlFile << "' could not be opened. Please check command line." << endl;
                exit(-1);
            }
        }
        else{
            fout.open(commandList->getOutputFile().c_str(),ios::out);
            if(!fout.is_open()){
                cout << "'" << commandList->getOutputFile() << "' could not be opened. Please check command line." << endl;
                exit(-1);
            }
        }

        Search newSearch(vertexOrder);

        if(commandList->getTotalDFSreq() != 0){
            find("DFS",commandList->getDfsNode(),newSearch);
        }

        if(commandList->getTotalBFSreq() != 0){
            find("BFS",commandList->getBfsNode(),newSearch);
        }

        fout.close();
    }
}

void SocialNetwork::readInputFile(const string& filename) {

    int outputFilename_size = filename.size();
    string backupControlFile = filename + ".txt";

    string file_extension;
    file_extension += filename[outputFilename_size - 4];
    file_extension += filename[outputFilename_size - 3];
    file_extension += filename[outputFilename_size - 2];
    file_extension += filename[outputFilename_size - 1];

    if(file_extension != ".txt"){
        fin.open(backupControlFile.c_str());
        if(!fin.is_open()){
            cout << "'" << filename << "' or '" << backupControlFile << "' could not be opened. Please check command line." << endl;
            exit(-1);
        }
    }
    else{
        fin.open(filename.c_str());
        if(!fin.is_open()){
            cout << "'" << filename << "' could not be opened. Please check command line." << endl;
            exit(-1);
        }
    }

    string vertexNode, vertexNode_1, vertexNode_2;
    int totalNumberOfVertex;
    char startBracket, endBracket;

    fin >> startBracket >> totalNumberOfVertex >> endBracket;

    for(int lineIterator = 0, vertexMap = 1; lineIterator < totalNumberOfVertex; lineIterator++, vertexMap++){
        if((lineIterator % 10 == 0)){
            fin  >> vertexNode;
            vertexOrder[vertexNode] = vertexMap;
            Vertex newVertexNode(vertexNode);
            networks.add(newVertexNode);
        }
        else{
            fin  >> vertexNode;
            Vertex newVertexNode(vertexNode);
            vertexOrder[vertexNode] = vertexMap;
            networks.add(newVertexNode);
        }
    }

    fin >> vertexNode;
    if(vertexNode == "[undirected]"){
        while(!fin.eof()){
            fin >> vertexNode;

            if(vertexNode != "-"){
                vertexNode_1 = vertexNode;
                fin >> vertexNode >> vertexNode_2;
                if(vertexNode_1 != vertexNode_2 ){
                    Vertex newVertexNode(vertexNode_1, vertexNode_2, 1, false);
                    networks.add(newVertexNode);

                    Vertex newReversedVertexNode(vertexNode_2, vertexNode_1, 1, false);
                    networks.add(newReversedVertexNode);
                }
                else{
                    cout << vertexNode << endl;
                }

            }
        }
    }

    while (!fin.eof()) {
        fin >> vertexNode;
    }

    fin.close();
}

void SocialNetwork::find(const string& searchType, const string& parentNode, Search newSearch){
    vector<map_Edges> map_Edges;
    if(searchType == "BFS"){
        map_Edges = newSearch.findBFS_at(parentNode, &networks);
        fout << "BreadthFirstSearch(" << parentNode << "){\n";
    }
    if(searchType == "DFS"){
        //cout << "searchType == DFS" << endl;
        map_Edges = newSearch.findDFS_at(parentNode, &networks);
        fout << "DepthFirstSearch(" << parentNode << "){\n";
    }

    for(auto & map_Edge : map_Edges){
        int counter = 0;
        for (auto & i : vertexOrder) {
            if (map_Edge.first[i.first] > counter) {
                counter = map_Edge.first[i.first];

                for(auto & vertexNodeValue : vertexOrder){
                    if (map_Edge.second[vertexNodeValue.first] != 0) {
                        if(map_Edge.second[vertexNodeValue.first] != map_Edge.first[vertexNodeValue.first]) {
                            fout << "\t" << i.first << "[" << map_Edge.first[i.first] << "] --> ";
                            fout << vertexNodeValue.first << "[" << map_Edge.second[vertexNodeValue.first] << "]" << endl;
                        }
                    }
                }
            }
        }
    }
    fout << "}" << endl << endl;
}

SocialNetwork::SocialNetwork() = default;
