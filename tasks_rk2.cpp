#include <iostream>
#include <map>
#include <list>
#include <fstream>
#include "tasks_rk2.h"

using namespace std;
//task1
Node::Node()
{

}
Node::Node(int nameNode)
{
    name = nameNode;
}
Node::~Node()
{
}

Graph::Graph()
{
    nodeNumber = 0;
}
Graph::Graph(int countNodes)
{
    nodeNumber = 0;
    head = new Node(0);
    head->parent = NULL;
}
Graph::~Graph()
{
}
void Graph::createNodesBFS(int countNodes, Node* currentNode)
{
    list<Node*> queue;
    list<Node*> queueChild;
    queue.push_back(currentNode);
    Node* currNode = currentNode;
    while (countNodes > 0)
    {

        while (!queue.empty())
        {
            currNode = queue.front();
            queue.pop_front();
            for (int i = 0; i < countNodes; i++)
            {
                nodeNumber++;
                Node* tempNode = new Node(nodeNumber);
                tempNode->parent = currNode;
                currNode->listChilds.push_back(tempNode);
                queueChild.push_back(tempNode);
            }
        }
        queue = queueChild;
        queueChild.clear();
        countNodes--;
    }
}
void Graph::createNodesDFS(int countNodes, Node* currentNode)
{
    if (countNodes == 0)
    {
        return;
    }
    for (int i = 0; i < countNodes; i++)
    {
        nodeNumber++;
        Node* tempNode = new Node(nodeNumber);
        tempNode->parent = currentNode;
        currentNode->listChilds.push_back(tempNode);
        createNodesDFS(countNodes - 1, tempNode);
    }
}
void Graph::printNodesBFS(Node* currentNode, ofstream* myfile)
{
    list<int> visitedVertexes;
    list<Node*> queue;
    visitedVertexes.clear();
    queue.clear();
    queue.push_back(currentNode);

    while (!queue.empty()) {
        auto currVertex = queue.front();
        queue.pop_front();

        if (!currVertex->listChilds.empty())
        {
            *myfile << currVertex->name << "{";
            for (auto it = currVertex->listChilds.begin(); it != currVertex->listChilds.end(); ++it) {
                int adjVertex = (*it)->name;
                if (std::find(visitedVertexes.begin(), visitedVertexes.end(), adjVertex) == visitedVertexes.end())
                {
                    visitedVertexes.push_back(adjVertex);
                    if (it != currVertex->listChilds.begin())
                    {
                        *myfile << ",";
                    }
                    *myfile << (*it)->name;
                    queue.push_back(*it);
                }
            }
            *myfile << "}" << endl;
        }
    }

}
void Graph::printNodesDFS(Node* currentNode, ofstream* myfile)
{

    if (currentNode->listChilds.size() == 0)
    {
        return;
    }
    if(currentNode==head)
    {
        *myfile << currentNode->name;
    }
    auto childList = currentNode->listChilds;
    *myfile << "{";
        for (auto it = childList.begin(); it != childList.end(); it++)
        {
            if (it != childList.begin())
            {
                *myfile << ",";
            }
            *myfile << (*it)->name;
            printNodesDFS(*it,myfile);

        }
        *myfile << "}";


}
bool Graph::findBFS(Node* currentNode, list<int> *path, int value)
{
    static bool isFound = false;
    if (currentNode->listChilds.size() == 0 || isFound)
    {
        return isFound;
    }
    auto childList = currentNode->listChilds;
    if(currentNode==head)
        path->push_back(currentNode->name);

    for (auto it = childList.begin(); it != childList.end(); it++)
    {
        path->push_back((*it)->name);
        if (value == (*it)->name)
        {
            isFound = true;
            return isFound;
        }

    }

    for (auto it = childList.begin(); it != childList.end(); it++)
    {
        isFound = findBFS(*it, path, value);
            if (isFound)
                return isFound;
    }
}

bool Graph::findDFS(Node* currentNode, list<int>* path, int value)
{
    static bool isFoundDFS = false;
    if (currentNode->listChilds.size() == 0 || isFoundDFS)
    {
        return isFoundDFS;
    }
    auto childList = currentNode->listChilds;

    for (auto it = childList.begin(); it != childList.end(); it++)
    {
        if (value == (*it)->name)
        {
            auto foundNode = (*it);
            while (foundNode->parent != NULL)
            {
                path->push_front(foundNode->name);
                foundNode = foundNode->parent;
                if (foundNode == head)
                {
                    path->push_front(foundNode->name);
                }
            }
            isFoundDFS = true;
            return isFoundDFS;
        }
        isFoundDFS = findDFS(*it, path,value);
        if (isFoundDFS)
            return isFoundDFS;
    }
}
int Graph::buildTreeBFS(int countNodes)
{
    nodeNumber = 0;
    createNodesBFS(countNodes, head);
    return nodeNumber;
}
int Graph::buildTreeDFS(int countNodes)
{
    nodeNumber = 0;
    createNodesDFS(countNodes, head);
    return nodeNumber;
}
void Graph::BFS()
{
    ofstream myfile;
    myfile.open("bfs_res.txt");
    printNodesBFS(head, &myfile);
}
void Graph::DFS()
{
    ofstream myfile;
    myfile.open("dfs_res.txt");
    printNodesDFS(head,&myfile);
}
std::pair<bool, list<int>> Graph::searchBFS(int nameNode)
{
    std::pair<bool, list<int>> tempPair;
    auto isFound = findBFS(head, &tempPair.second, nameNode);

    if (isFound)
    {
        tempPair.first = true;
    }
    else
    {
        tempPair.second.clear();
    }
    return tempPair;
}
std::pair<bool, list<int>> Graph::searchDFS(int nameNode)
{
    std::pair<bool, list<int>> tempPair;
    auto isFound = findDFS(head, &tempPair.second, nameNode);
    if (isFound)
    {
        tempPair.first = true;
    }
    else
    {
        tempPair.second.clear();
    }
    return tempPair;
}


//Task 2
pair<int ,int > binarySearch(int *array, int size, int searchValue)
{
    pair<int, int>tempPair;
    static int count = 0;

    if (size >= 1)
    {
        count=0;
        int mid = (size - 1) / 2;
        if (array[mid] == searchValue)
        {
            count++;
            tempPair.first = mid;
            tempPair.second = count;
            return tempPair;
        }
        if (array[mid] > searchValue)
        {
            count++;
            return binarySearch(array, mid, searchValue);
        }
        if (array[mid] < searchValue)
        {

            tempPair = binarySearch(array + mid + 1, size - (mid + 1), searchValue);
            if (tempPair.first == -1)
            {
            count++;
            tempPair.second = count;
            return tempPair;
            }
            count++;
            tempPair.first = mid + tempPair.first + 1;
            tempPair.second = count;
            return tempPair;
        }
    }
    count++;
    tempPair.first = -1;
    tempPair.second = count;
    return tempPair;
}

//Task3


//Task 4
ostream& operator<<(ostream& os, const pair<int, int>& intPair)
{
    os << "(";
    os << intPair.first << ","
        << intPair.second << ")\n";
    return os;
}
