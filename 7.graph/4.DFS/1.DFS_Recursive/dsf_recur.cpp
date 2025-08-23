#include <iostream>
#include <vector>
using namespace std;

void DFS(int root , vector<vector<int>>& adj ,vector<bool>&visited) {
    visited[root] = true;
    cout << root << " ";
    for(int runner : adj[root]){
        if(!visited[runner]){
            DFS(runner,adj,visited);
        }
    }
}

int main() {
    vector<vector<int>> adj(5);
    adj[0] = {1,2};
    adj[1] = {2,0};
    adj[2] = {0,1,3};
    adj[3] = {1,2,4};
    adj[4] = {3};
    vector<bool>visited(5,false);
    DFS(0,adj,visited);
    return 0;
}