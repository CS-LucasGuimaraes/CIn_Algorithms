#include <bits/stdc++.h>

using namespace std;


int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int jobs, requirements;
    int prev, act;

    cin >> jobs; cin >> requirements;

    vector<vector<int>> adj(jobs+1);
    vector<bool> visited(jobs+1, false);
    queue<int> answer;
    vector<int> inDregree(jobs+1, 0);

    for (int i = 0; i < requirements; i++) {
        cin >> prev; cin >> act;
        adj[prev].push_back(act);
        inDregree[act]++;
    }

    priority_queue<int, vector<int>, greater<int>> operation_order;

    for (int i = 1; i < jobs+1; i++) {
        if (inDregree[i] == 0) {
            operation_order.push(i);
        }
    }

    while(!operation_order.empty()) {
        int i = operation_order.top();
        operation_order.pop();
        answer.push(i);

        for (auto e:adj[i]) {
            if (--inDregree[e] == 0) {
                operation_order.push(e);
            }
        }
    }
    
    int answer_size = answer.size();
    if (answer_size == jobs) {
        while (!answer.empty()) {
        cout << answer.front() << " ";
        answer.pop();
        }
    }
    else {
        cout << "Sandro fails.";
    }

    return 0;
}