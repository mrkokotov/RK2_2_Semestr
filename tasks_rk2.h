#include <utility>
#include <functional>
#include <iterator>
#include <string>
#include <cstring>
#include <iostream>

using namespace std;

//task1
struct Node {
    Node();
    Node(int nameNode);
    ~Node();

    Node* parent;
    std::list<Node*> listChilds;
    int name;
    static int countNodes;
};

class Graph {
    private :
        Node* head;
        int nodeNumber;
        void createNodesBFS(int countNodes,Node*currentNode);
        void createNodesDFS(int countNodes, Node* currentNode);
        void printNodesBFS(Node* currentNode, ofstream* myfile);
        void printNodesDFS(Node* currentNode, ofstream* myfile);
        bool findBFS(Node* currentNode, list<int> *path,int value);
        bool findDFS(Node* currentNode, list<int>* path, int value);
        //здесь можно писать любые функции, которые могут понадобиться
    public :
        Graph();
        Graph(int countNodes);
        ~Graph();
        /*
            output		:	-1 - если функция не реализована
                        :	положительное число -- число узлов
            author		:
            date		:
            version		:
        */
        int buildTreeBFS(int countNodes);
        /*
            output		:	-1 - если функция не реализована
                        :	положительное число -- число узлов
            author		:
            date		:
            version		:
        */
        int buildTreeDFS(int countNodes);
        /*
            description	:	обход графа и записи вершин в файл
            input		:
            output		:
            author		:
            date		:
            version		:
        */
        void BFS();
        void DFS();
        /*
            description	:	функция поиска узла по его имени,
                            DFS - № студ билет чётный
                            BSD - № студ билет нечётный
            input 		:	nameNode -- имя узла
            output		:	{bool -- узел найде, list<int> -- список имён узлов до необходимого}
            description	:	приставка DFS -- поиск в глубину, BSF -- поиск в ширину
            author		:
            date		:
            version		:
        */
        std::pair<bool, list<int>> searchDFS(int nameNode);
        std::pair<bool, list<int>> searchBFS(int nameNode);
};
//Task 2
pair<int ,int > binarySearch(int *array, int size, int searchValue);
//Task 3
template<class T>
class Filo
{
private:
    bool fixedSize = false;
    T* ar;	//массив
    int size;	//размер массива
    int countData;	//число элементов в массиве
public:
    Filo()
    {
        fixedSize = false;
        countData = 0;
        size = 0;
        ar = new T;
    }
    Filo(int _size)
    {
        fixedSize = true;
        countData = 0;
        size = _size;
        ar = new T[size];
    }
    ~Filo()
    {

    }
    /*
        input		:	элемент который надо добавить
        output		:	1 - элемент добавлен, 0 - элемент не добавлен
        description	:	добавление элемента в конец массива
    */
    int push_back(T el)
    {

        if (countData<size)
        {
            *(ar+countData) = el;
            countData++;
            return 1;
        }
        else if (fixedSize)
        {
            cout <<"Stack overflow\n";
            return 0;
        }
        else
        {
            int tempSize = size;
                        size++;
                        T* temp = new T[tempSize];
                        for (int i = 0; i < tempSize; i++)
                        {
                            *(temp + i) = *(ar + i);
                        }

                        ar = new T[size];
                        for (int i = 0; i < tempSize; i++)
                        {
                            *(ar + i)= *(temp + i);
                        }
                        *(ar + countData) = el;
                        countData++;
                        return 1;
        }
    }

    /*
        input		:	элемент который надо извлечь
        output		:	пара значений:
                            1ый аргумент пары -- 1 - элемент успешно извлечён, 0 - элементов в массиве нет
                            2ой аргумент пары -- это извлечённый элемент
        description	:	извлечение элемента из массива
    */
    pair<int, T> pop_back()
    {
        pair<int, T> temp;
        if (countData > 0)
        {
            --countData;
            --size;
            temp.second = *(ar+countData);
            temp.first = 1;
        }
        else
        {
            temp.first = 0;
            temp.second = 0;
        }
        return temp;
    }
    T top()
    {
        if (!isEmpty())
        {
            return ar[countData-1];
        }
    }
    bool isEmpty()
    {
        return (size == 0);
    }

};
//Task 4
ostream& operator<<(ostream& os, const pair<int, int>& intPair);
//Task 5
template<class T>
class CheckBrackets : public Filo<char> {
private:
    //можно объявляеть любые переменные и функции
public :
    CheckBrackets() : Filo<char>() { }
    ~CheckBrackets() {}
    /*
        input		:	строка со скобками
        output		:	0 - всё хорошо, -1 - скобок не хватает
        description	:	проверка скобок
    */

    int checkBrackets(const char* strBrackets)
    {
        int len = strlen(strBrackets);
        for (int i = 0; i < len; i++)
        {
            if (isEmpty())
            {
                push_back(strBrackets[i]);
            }

            else if ((top() == '(' && strBrackets[i] == ')') || (top() == '{' && strBrackets[i] == '}') || (top() == '[' && strBrackets[i] == ']'))
            {
                pop_back();
            }
            else
            {
                push_back(strBrackets[i]);
            }
        }
        if (isEmpty())
        {
            return 0;
        }
        return -1;
    }

};
