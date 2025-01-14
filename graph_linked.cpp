#include <iostream>
using namespace std;

struct node{
    int vertex;
    node * next;
};

const int max_size = 10;

int stack[max_size];
int top = -1;
void push(int value){
    if (top == max_size - 1) {
        cout << "Stack Overflow\n";
        return;
    }
    stack[++top] = value;
}
int pop(){
    if (top == -1) {
        cout << "Stack Underflow\n";
        return -1;
    }
    return stack[top--];
}
bool isEmpty(){
    if(top == -1){
        return true;
    }
    return false;
}

int arr[max_size];
int front = -1, rear = -1;

void enqueue(int value){
    if(max_size <= rear)
     arr[++rear] = value;
     else{
        cout << "Overflow\n";
        return ;
     }
}
int dequeue(){
     if (front == -1 || front > rear) {
        cout << "Queue Underflow\n";
        return -1;
    }
    return arr[front++];
}
bool isempty(){
    if(front == -1 && rear == -1){
        return true;
    }
    return false;
}

class Graph{
private:

    int num_vertices;
    node** adjList;

public: 
    Graph(int vertices){
        num_vertices = vertices;
        adjList = new node*[num_vertices];
        for (int i = 0; i < num_vertices; i++){
            adjList[i] = NULL;
        }
    }
void insert_edge(int v1, int v2){
        if (v1 >= 0 && v1 < num_vertices && v2 >= 0 && v2 < num_vertices){
            node * new_node = new node;
            new_node->vertex = v2;
            new_node->next = adjList[v1];
            adjList[v1] = new_node;
            node * new_node2 = new node;
            new_node->vertex = v1;
            new_node->next = adjList[v2];
            adjList[v2] = new_node2;
        }
        else{
            cout << "Invalid Vertices\n";
        }
    }

void display(){
        for (int i = 0; i < num_vertices; i++){
            cout << "Vertex " << i << ":";
            node *temp;
            temp = adjList[i];
            while(temp != NULL){
                cout << temp->vertex << "->";
                temp = temp->next;
            }
            cout << "NULL\n";
        }
    }

void dfs(int source, int destination){
        bool found = false;
        bool visited[num_vertices];
        for(int i = 0 ; i < num_vertices; i++){
            visited[i] = false;
        }
        push(source);
        do{
            source = pop();
        if(source == destination){
            found = true;
            cout << "Vertex found in the graph\n";
            return;
        }
        else{
            node *temp = adjList[source];
            while(temp != NULL){
                if(!visited[temp->vertex]){
                push(temp->vertex);
                visited[temp->vertex] = true;
                }
                temp = temp->next;
            }
        }
        }while (!found && !isEmpty());
        if (!found){
            cout << "Vertex not found in the graph\n";
        }
    }
void bfs(int source, int destination){
        bool found = false;
        bool visited[num_vertices];
        for(int i = 0 ; i < num_vertices; i++){
            visited[i] = false;
        }
        enqueue(source);
        visited[source] = true;
        do{
            source = dequeue();
          if(source == destination){
                found = true;
                cout << "Vertex found in the graph\n";
                return ;
          }
          else {
            node * temp = adjList[source];
            while(temp != NULL){
                if(!visited[temp->vertex]){
                enqueue(temp->vertex);
                visited[temp->vertex] = true;
                }
                temp = temp->next;
            }
          }
        }while(!found && !isempty());
        cout << "Vertex not found in the graph\n";
    }
};
int main() {
    int vertices, choice, v1, v2, source, destination;
    cout << "Enter the number of vertices in the graph: ";
    cin >> vertices;

    Graph graph(vertices);

    do {
        cout << "\nMenu:\n";
        cout << "1. Insert Edge\n";
        cout << "2. Display Graph\n";
        cout << "3. Perform DFS\n";
        cout << "4. Perform BFS\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter two vertices to connect (v1 v2): ";
                cin >> v1 >> v2;
                graph.insert_edge(v1, v2);
                break;

            case 2:
                graph.display();
                break;

            case 3:
                cout << "Enter source and destination vertices for DFS (source destination): ";
                cin >> source >> destination;
                graph.dfs(source, destination);
                break;

            case 4:
                cout << "Enter source and destination vertices for BFS (source destination): ";
                cin >> source >> destination;
                graph.bfs(source, destination);
                break;

            case 5:
                cout << "Exiting...\n";
                break;

            default:
                cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 5);

    return 0;
}



