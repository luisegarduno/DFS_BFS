//
// Created by Luis on 6/7/2020.
//

#ifndef DEPTHFIRSTSEARCH_BREADTHFIRST_SEARCH_H
#define DEPTHFIRSTSEARCH_BREADTHFIRST_SEARCH_H


#include <queue>
#include <stack>
#include <string>
#include <vector>
#include "Graph.h"
#include <utility>
#include <iostream>
#include "Vertex.h"
#include <unordered_map>

using std::stack;
using std::pair;
using std::string;
using std::vector;
using std::greater;
using std::unordered_map;
using std::priority_queue;
using map_Vertex = unordered_map<string,int>;
using map_Edges = pair<map_Vertex,map_Vertex>;


class Search {
private:
    string parentNode;
    map_Vertex vertexValues_InOrder;

public:
    Search();
    explicit Search(map_Vertex);
    vector<map_Edges> findBFS_at(string, Graph<Vertex>*);
    vector<map_Edges> findDFS_at(string, Graph<Vertex>*);
    //vector<map_Edges> makeConnection(string,string);

    int    getOrder_intAt(const string&);
    string getOrder_StringAt(int);

    string getVectorValues(map_Vertex , int);

    static bool isFlagsDisabled_BFS(const map_Vertex&);
    static void resetVertexFlags_BFS(map_Vertex&);
};

#endif //DEPTHFIRSTSEARCH_BREADTHFIRST_SEARCH_H
