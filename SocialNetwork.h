//
// Created by Luis on 6/7/2020.
//

#ifndef DEPTHFIRSTSEARCH_BREADTHFIRST_SOCIALNETWORK_H
#define DEPTHFIRSTSEARCH_BREADTHFIRST_SOCIALNETWORK_H

#include <map>
#include <string>
#include "Graph.h"
#include <fstream>
#include "Vertex.h"
#include "Search.h"
#include "FileReader.h"
#include <bits/stdc++.h>
#include <unordered_map>


using std::ios;
using std::map;
using std::string;
using std::fstream;
using std::ofstream;
using std::unordered_map;
using map_Vertex = unordered_map<string,int>;
using map_Edges = pair<map_Vertex,map_Vertex>;

class SocialNetwork {

private:
    ifstream fin;                   // Reads in from inputFile;
    ofstream fout;                  // Outputs to outputFile;
    Graph<Vertex> networks;
    map_Vertex vertexOrder;

public:
    SocialNetwork();

    void readInputFile(const string&);
    explicit SocialNetwork(FileReader *);
    void find(const string&, const string&, Search);
};


#endif //DEPTHFIRSTSEARCH_BREADTHFIRST_SOCIALNETWORK_H
