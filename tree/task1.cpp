#include<iostream>
using namespace std;
#define MAX_NODES 10
#define MAX_CHILDREN 5

int data[MAX_NODES];
int children[MAX_NODES][MAX_CHILDREN];
int childCount[MAX_NODES];
int node_Count = 0;
int addNode(int value){
    data[node_Count] = value;
    childCount[node_Count] = 0;
    return node_Count++;  // return index then increase count...

}

void addChild(int parentIndex , int childIndex)
{
    int count= childCount[parentIndex];
    children[parentIndex][count] = childIndex;
    childCount[parentIndex]++;
}


void PrintTree(int root){
    cout<<"Tree Structure: ";
    for (int i = 0; i < node_Count; i++)
    {
       cout<<"Node" <<data[i] <<"->" <<endl;
       for (int j = 0; j < childCount[i]; j++)
       {
            cout<<data[children[i][j]]<<endl;
       }
       cout<<endl;
    }
}

int main()
{

int root = addNode(1);    
int n2= addNode(2);
int n3= addNode(3);
int n4= addNode(4);
int n5= addNode(5);
int n6= addNode(6);
int n7= addNode(7);

addChild(root, n2);
addChild(root, n3);
addChild(root, n4);
addChild(root, n5);
addChild(root, n6);
addChild(root, n7);

PrintTree(root);
return 0;
}

