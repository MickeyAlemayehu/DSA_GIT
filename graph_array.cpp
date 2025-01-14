#include <iostream>
using namespace std;

const int max_size = 100;

class Graph{

private:
int vertices;
int adjMatrix[max_size][max_size];

public:
    Graph(int num_vertices){
        if(num_vertices < max_size){
        vertices =num_vertices;
        adjMatrix[vertices][vertices];
        }
        else{
            cout << "Number of vertices must not exceed 100";
            exit(1);
        }
        for (int i = 0; i < vertices; i++){
            for (int j = 0; j < vertices; j++){
                adjMatrix[i][j] = 0;
            }
        }
    }

    void insert_edge(int v1, int v2){
        if(v1 >= 0 && v1 < vertices && v2 >= 0 && v2 < vertices){
            adjMatrix[v1][v2] = 1;
            adjMatrix[v2][v1] = 1;
        }
        else
        cout << "Invalid vertices\n";
    }

    void display(){
        for (int i = 0; i < vertices; i++){
            for (int j = 0; j < vertices; j++){
                cout << adjMatrix[i][j] << " ";
            }
            cout << endl;
        }
    }   
};


