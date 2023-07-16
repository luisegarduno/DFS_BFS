//
// Updated by Luis G. on 07/16/2023.
//

#ifndef DEPTHFIRSTSEARCH_BREADTHFIRST_GRAPH_H
#define DEPTHFIRSTSEARCH_BREADTHFIRST_GRAPH_H

#include "Node.h"
#include <fstream>
#include <iostream>
#include "Vertex.h"
#include "LinkedList.h"

using std::cout;
using std::endl;
using std::string;
using std::ofstream;

template<class T>
class Graph{

private:
    //ofstream fout;                  // Outputs to outputFile;
    //string filename;
    LinkedList< LinkedList<T> > graph;

public:
    Graph();
    void add(T);
    LinkedList<T> &checkListOfVertexNodes(const string &);
    bool checkNetworkConnections(const string&,const string&, const LinkedList<T>&);
    LinkedList<T> getAllNodes(const string&);


    //void setOutputFileName(const string&);
    //string getOutputFileName();
    void printGraph();
};

template <class T>
Graph<T>::Graph() = default;

template<class T>
void Graph<T>::add(T newNode){

    if(newNode.getPredecessorNode() != ""){

        LinkedList<T>* vertexLinkedList = &checkListOfVertexNodes(newNode.getVertexNode());

        if(vertexLinkedList != nullptr){

            bool dataExists = checkNetworkConnections(newNode.getVertexNode(), newNode.getPredecessorNode(), *vertexLinkedList);

            if(!dataExists){
                vertexLinkedList->append(newNode);                      // adds connection to Node
            }
        }

        else{
            LinkedList<T> newLinkedLinkedList;
            newLinkedLinkedList.append(newNode);
            graph.append(newLinkedLinkedList);                      // add this LinkedLinkedList to graph
        }
    }

    else{
        //cout << newNode.getVertexNode();
    }
}

template<class T>
LinkedList<T> & Graph<T>::checkListOfVertexNodes(const string &vertexValue) {
    Node< LinkedList<T> >* currentLinkedList = graph.getLinkedList_head();

    while(currentLinkedList != nullptr){
        if(currentLinkedList->getData()->getLinkedList_head()->getData()->getVertexNode() == vertexValue){
            return *(currentLinkedList->getData());
        }
        currentLinkedList = currentLinkedList->getNextNode();
    }

    LinkedList<T> *temp_val = nullptr;
    return *temp_val;
}

template<class T>
bool Graph<T>::checkNetworkConnections(const string& vertex, const string& predecessor, const LinkedList<T>& aNetworkLinkedList){
    auto tempIterator = aNetworkLinkedList;
    tempIterator.resetIterator();

    while(tempIterator.iteratorIsValid()){
        if(tempIterator.getIterator().getVertexNode() == predecessor){
            return true;
        }
        tempIterator.iterateForward();
    }
    return false;
}

template<class T>
LinkedList<T> Graph<T>::getAllNodes(const string& aVertex){

    Node< LinkedList<T> >* currentLinkedList = graph.getLinkedList_head();
    LinkedList<T> graphVertex = LinkedList<T>();
    currentLinkedList->getData()->resetIterator();

    while(currentLinkedList != nullptr){
        currentLinkedList->getData()->resetIterator();
        while(currentLinkedList->getData()->iteratorIsValid()){
            if(currentLinkedList->getData()->getIterator().getVertexNode() == aVertex){
                graphVertex.append(currentLinkedList->getData()->getIterator());
            }

            currentLinkedList->getData()->iterateForward();
        }

        currentLinkedList = currentLinkedList->getNextNode();
    }

    return graphVertex;
}
/*
template<class T>
void Graph<T>::setOutputFileName(const string& setfilename){
    filename = setfilename;
}
template<class T>
string Graph<T>::getOutputFileName(){
    return filename;
}
*/

template<class T>
void Graph<T>::printGraph(){

    Node< LinkedList<T> >* currentLinkedList = graph.getLinkedList_head();
    cout << "----------------------------------Directed Graph--------------------------------------------" << endl;
    cout << endl;
    cout << "--------------- Format: VertexNode(PredecessorNode, Betweeness, VisitedFlag) ---------------" << endl << endl;
    while(currentLinkedList != nullptr){
        cout << currentLinkedList->getData()->getLinkedList_head()->getData()->getVertexNode() << " --> ";
        currentLinkedList->getData()->print();
        currentLinkedList = currentLinkedList->getNextNode();
        if(currentLinkedList != nullptr){
            cout << endl;
        }
    }
    cout << "------------------------------------------------------------------------------------------- " << endl;
}

#endif // SHORTESTPATH_GRAPH_H
