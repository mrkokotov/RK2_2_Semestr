//Запускается в режиме отладки//

#include <QCoreApplication>
#include <tasks_rk2.h>
#include <iostream>
void task_1()
{
    cout<<"----------------First task tests--------------"<<endl;
    Graph graph1(3);
    Graph graph2(3);

    int tempNumbBFS = graph1.buildTreeBFS(3);
    std::cout<<tempNumbBFS<<std::endl;
    std::pair<bool, list<int>> tempPair = graph1.searchBFS(10);
    cout<<"("<<tempPair.first<<",";
    auto listIt=tempPair.second;
    for(auto it = listIt.begin(); it != listIt.end(); it++)
    {
        cout<<*it<<" ";
    }
    cout<<")"<<endl;
    graph1.BFS();
    std::cout<<std::endl;
    int tempNumbDFS = graph2.buildTreeDFS(3);
    std::cout<<tempNumbDFS<<std::endl;
    std::pair<bool, list<int>> tempPair1 = graph2.searchDFS(14);
    cout<<"("<<tempPair1.first<<",";
    auto listIt1=tempPair1.second;
    for(auto it = listIt1.begin(); it != listIt1.end(); it++)
    {
        cout<<*it<<" ";
    }
    cout<<")"<<endl;
    graph2.DFS();
}
void task_2()
{
    cout<<"----------------Second task tests--------------"<<endl;
    int arr[9] = { 1,2,3,4,7,8,9,10,11};
        pair<int,int>myPair=binarySearch(arr, 9, 15);
        cout<<myPair<<endl;
        pair<int,int>myPair1=binarySearch(arr, 9, 8);
        cout<<myPair1<<endl;
        pair<int,int>myPair2=binarySearch(arr, 9, 7);
        cout<<myPair2<<endl;
        pair<int,int>myPair3=binarySearch(arr, 9, 10);
        cout<<myPair3<<endl;
        pair<int,int>myPair4=binarySearch(arr, 9, 11);
        cout<<myPair4<<endl;
        pair<int,int>myPair5=binarySearch(arr, 9, 4);
        cout<<myPair5<<endl;

}
void task_3()
{
    cout<<"----------------Third task tests--------------"<<endl;
    Filo<int> filo1;
    filo1.push_back(1);
    pair<int,int>testPair2=filo1.pop_back();
    cout << testPair2;
    filo1.push_back(10);
    filo1.push_back(2);
    filo1.push_back(3);
    filo1.push_back(4);
    filo1.push_back(5);

    filo1.pop_back();
    filo1.pop_back();
    pair<int,int>testPair5=filo1.pop_back();
    cout<<testPair5;
    filo1.pop_back();
    filo1.pop_back();
    pair<int, int>testPair1=filo1.pop_back();
    cout << testPair1<<endl;

    Filo<char> filo2(4);
    int test_push1=filo2.push_back('c');
    cout<<test_push1<<endl;
    int test_push2=filo2.push_back('a');
    cout<<test_push2<<endl;
    int test_push3=filo2.push_back('t');
    cout<<test_push3<<endl;
    int test_push4=filo2.push_back('c');
    cout<<test_push4<<endl;
    int test_push5=filo2.push_back('h');
    cout<<test_push5<<endl;

    filo2.pop_back();
    filo2.pop_back();
    filo2.pop_back();
    pair<int, char>testPair6=filo2.pop_back();
    cout << "("<<testPair6.first<<","<<testPair6.second<<")"<<endl;

    pair<int, char>testPair3=filo2.pop_back();
    cout << "("<<testPair3.first<<","<<testPair3.second<<")"<<endl;

    pair<int, char>testPair4=filo2.pop_back();
    cout << "("<<testPair4.first<<","<<testPair4.second<<")"<<endl;




}
void task_4()
{
    cout<<"----------------Fourth task tests--------------"<<endl;
    pair<int, int> testPair{ 55, 77 };
    cout << testPair<<endl;

    pair<int, int> testPair1{ 0, 10 };
    cout << testPair1<<endl;

    pair<int, int> testPair2{ 21, 20 };
    cout << testPair2<<endl;

}
void task_5()
{
    cout<<"----------------Fifth task tests--------------"<<endl;
    CheckBrackets<char> checkBr;
    int a=checkBr.checkBrackets("{{(})}");
    cout<<a<<endl;

    CheckBrackets<char> checkBr1;
    int b=checkBr1.checkBrackets("(([({}[()])]){}({(){}}))");
    cout<<b<<endl;

    CheckBrackets<char> checkBr2;
    int c=checkBr2.checkBrackets("{{[(){}(()){[]}]}}");
    cout<<c<<endl;

    CheckBrackets<char> checkBr3;
    int d=checkBr3.checkBrackets("(([({}[()])){}({(){}}))");
    cout<<d<<endl;

    CheckBrackets<char> checkBr4;
    int e=checkBr4.checkBrackets("()[(]{{}[]})");
    cout<<e<<endl;

    CheckBrackets<char> checkBr5;
    int f=checkBr5.checkBrackets("[()]{({(}){}}))");
    cout<<f<<endl;


}
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
        task_1();
        task_2();
        task_3();
        task_4();
        task_5();


        int debug =10;


        return 0;
    return a.exec();
}
