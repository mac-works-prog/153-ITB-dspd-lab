//Pavan Bokare-IT-B-153
/*AIM: Consider the undirected graph G, consisting of n nodes laid out in a 3 -by- 3 grid: Start searching at node 1, and break ties for exploring
the next node based on lower numerical order (i.e. add nodes to a queue low to high, add nodes to a stack high to low). (a) In what order are
nodes marked as explored by BFS? (b) In what order are nodes marked as explored by DFS?*/
#include <stdio.h>
#define MAX 10

int adj[10][10]; 
int visited[10];
int queue[MAX], front = -1, rear = -1;
int stack[MAX], top = -1;

void enqueue(int x) {
    if(rear == MAX - 1) return;
    if(front == -1) front = 0;
    queue[++rear] = x;
}

int dequeue() {
    if(front == -1 || front > rear) return -1;
    return queue[front++];
}

void push(int x) {
    if(top == MAX - 1) return;
    stack[++top] = x;
}

int pop() {
    if(top == -1) return -1;
    return stack[top--];
}

void createGraph() {
    int i;
    // 3x3 grid connections
    for(i = 1; i <= 9; i++) {
        if(i - 3 > 0) adj[i][i - 3] = 1; // up
        if(i + 3 <= 9) adj[i][i + 3] = 1; // down
        if(i % 3 != 1) adj[i][i - 1] = 1; // left
        if(i % 3 != 0) adj[i][i + 1] = 1; // right
    }
}

void BFS(int start) {
    for(int i = 1; i <= 9; i++) visited[i] = 0;
    front = rear = -1;
    enqueue(start);
    visited[start] = 1;
    printf("BFS Order: ");
    while(front <= rear) {
        int node = dequeue();
        printf("%d ", node);
        for(int j = 1; j <= 9; j++) {
            if(adj[node][j] && !visited[j]) {
                enqueue(j);
                visited[j] = 1;
            }
        }
    }
    printf("\n");
}

void DFS(int start) {
    for(int i = 1; i <= 9; i++) visited[i] = 0;
    top = -1;
    push(start);
    printf("DFS Order: ");
    while(top != -1) {
        int node = pop();
        if(!visited[node]) {
            printf("%d ", node);
            visited[node] = 1;
            // Push neighbors in decreasing order
            for(int j = 9; j >= 1; j--) {
                if(adj[node][j] && !visited[j])
                    push(j);
            }
        }
    }
    printf("\n");
}

int main() {
    createGraph();
    printf("Undirected Graph: 3x3 Grid (Nodes 1 to 9)\n");
    BFS(1);
    DFS(1);
    return 0;
}