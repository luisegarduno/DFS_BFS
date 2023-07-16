//
// Updated by Luis G. on 07/16/2023.
//

#ifndef SHORTESTPATH_VERTEX_H
#define SHORTESTPATH_VERTEX_H

#include <string>
#include <iostream>

using std::cout;
using std::endl;
using std::move;
using std::string;

class Vertex {
private:
    string vertex;
    string predecessor;
    int    betweeness{};
    bool   visitedFlag{};

public:
    Vertex();
    Vertex(string);
    Vertex(string,string,int,bool);
    Vertex(const Vertex&);
    Vertex& operator=(const Vertex&);
    Vertex* operator=(const Vertex*);

    void setVertexNode(string);
    void setPredecessorNode(string);
    void setBetweeness(int);
    void setVisitedFlag(bool);

    string getVertexNode();
    string getPredecessorNode();
    int    getBetweeness();
    bool   getVisitedFlag();
};


#endif // SHORTESTPATH_VERTEX_H
