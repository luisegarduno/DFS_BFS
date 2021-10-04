//
// Created by Luis on 6/7/2020.
//

#include "Search.h"


Search::Search() : parentNode(""){
}

Search::Search(map_Vertex universalValues) {
    vertexValues_InOrder = std::move(universalValues);
}

bool Search::isFlagsDisabled_BFS(const map_Vertex& aMap){
    for (auto & i : aMap) {
        cout << i.first << " : " << i.second << endl;
        if(i.second == 0){
            return true;
        }
    }
    return false;
}

void Search::resetVertexFlags_BFS(map_Vertex& aMap){
    for (auto & i : aMap) {
        if(i.second == 1){
            i.second = 0;
        }
    }
}

vector<map_Edges> Search::findBFS_at(string startNode, Graph<Vertex>* currentGraph) {
    parentNode = std::move(startNode);
    map_Vertex bfs_vertex_values,vertex1,vertex2;

    map_Edges edges;
    vector<map_Edges> bfs_sorted;
    auto children_original = currentGraph->getAllNodes(parentNode);

    for (auto & it : vertexValues_InOrder) {
        bfs_vertex_values[it.first] = 0;
    }

    int i = 1;

    bool flag = false;
    priority_queue <int, vector<int>, greater<>> magic_nodes;
    children_original.setLinkedList_iterator(children_original.getLinkedList_head());
    static int totalBetweeness_BFS;
    while(!flag){

        if(i == 1){
            bfs_vertex_values[parentNode] = i;
            magic_nodes.emplace(i);
            i++;
        }

        while(!magic_nodes.empty()){
            auto children_iterator = currentGraph->getAllNodes(getVectorValues(bfs_vertex_values,magic_nodes.top()));
            children_iterator.setLinkedList_iterator(children_iterator.getLinkedList_head());
            int n = children_iterator.getListSize();

            magic_nodes.pop();
            totalBetweeness_BFS = children_iterator.getIterator().getBetweeness();


            for(int it = 1; it <= n; it++){

                string theVertex_Child  = children_iterator.getIterator().getPredecessorNode();
                string theVertex_Parent = children_iterator.getIterator().getVertexNode();

                if(bfs_vertex_values[theVertex_Child] == 0){
                    children_iterator.getIterator().setBetweeness(totalBetweeness_BFS + 1);
                    bfs_vertex_values[theVertex_Child] = i;
                    magic_nodes.emplace(bfs_vertex_values[theVertex_Child]);

                    vertex1[theVertex_Parent] = bfs_vertex_values[theVertex_Parent];
                    vertex2[theVertex_Child] = bfs_vertex_values[theVertex_Child];
                    edges.first = vertex1;
                    edges.second = vertex2;

                    bfs_sorted.push_back(edges);

                    vertex1.clear();
                    vertex2.clear();
                    i++;
                }
                children_iterator.iterateForward();
            }
        }
        flag = true;
    }
    return bfs_sorted;
}

vector<map_Edges> Search::findDFS_at(string startNode, Graph<Vertex>* currentGraph) {
    map_Edges edges;
    vector<map_Edges> dfs_sorted;
    parentNode = std::move(startNode);
    stack <int, vector<int>> magic_nodes;
    map_Vertex dfs_vertex_values,vertex1,vertex2;
    auto children_original = currentGraph->getAllNodes(parentNode);

    for (auto & it : vertexValues_InOrder) {
        dfs_vertex_values[it.first] = 0;
    }

    int i = 1;

    bool flag = false;
    children_original.setLinkedList_iterator(children_original.getLinkedList_head());
    static int totalBetweeness_DFS;
    while(!flag){

        if(i == 1){
            dfs_vertex_values[parentNode] = i;
            magic_nodes.emplace(i);
            i++;
        }


        while(!magic_nodes.empty()){
            auto children_iterator = currentGraph->getAllNodes(getVectorValues(dfs_vertex_values,magic_nodes.top()));

            children_iterator.setLinkedList_iterator(children_iterator.getLinkedList_head());

            int n = children_iterator.getListSize();
            bool flag_Stack = false;

            totalBetweeness_DFS += children_iterator.getIterator().getBetweeness();
            for(int it = 1; it <= n; it++){

                string theVertex_Child  = children_iterator.getIterator().getPredecessorNode();
                string theVertex_Parent = children_iterator.getIterator().getVertexNode();

                children_iterator.getIterator().setBetweeness(totalBetweeness_DFS + 1);
                if(dfs_vertex_values[theVertex_Child] == 0){
                    children_iterator.getIterator().setBetweeness(totalBetweeness_DFS + 1);
                    flag_Stack = true;
                    dfs_vertex_values[theVertex_Child] = i;
                    magic_nodes.emplace(dfs_vertex_values[theVertex_Child]);

                    vertex2[theVertex_Child]  = dfs_vertex_values[theVertex_Child];
                    vertex1[theVertex_Parent] = dfs_vertex_values[theVertex_Parent];
                    edges.first = vertex1;
                    edges.second = vertex2;

                    dfs_sorted.push_back(edges);

                    vertex1.clear();
                    vertex2.clear();
                    i++;
                }

                if((it != n) && (!flag_Stack)){
                    children_iterator.iterateForward();
                    continue;
                }

                if((!theVertex_Child.empty()) && (dfs_vertex_values[theVertex_Child] != 0) && (magic_nodes.top() != 0)){
                    if((it == n) && (getVectorValues(dfs_vertex_values, magic_nodes.top()) == theVertex_Parent)){
                        magic_nodes.pop();
                    }
                    break;
                }
                children_iterator.iterateForward();
            }
        }
        flag = true;
    }
    return dfs_sorted;
}

string Search::getVectorValues(map_Vertex tempVector, int here){
    for(auto start = 1; start <= tempVector.size(); start++){
        if(tempVector[getOrder_StringAt(start)] == here){
            return getOrder_StringAt(start);
        }
    }
    return "";
}

string Search::getOrder_StringAt(int position){
    for(auto & start : vertexValues_InOrder){
        if(start.second == position){
            return start.first;
        }
    }
    return "";
}

int Search::getOrder_intAt(const string& here) {
    for(auto & start : vertexValues_InOrder){
        if(start.first == here){
            return start.second;
        }
    }
    return 0;
}
