#include <bits/stdc++.h>
using namespace std;
const int N = 100000;

vector<int> graph[N];
vector<int> cycles[N];

void dfs_cycle(int u, int p, int color[],
			int mark[], int par[], int& cyclenumber)
{

	if (color[u] == 2) {
		return;
	}

	if (color[u] == 1) {

		cyclenumber++;
		int cur = p;
		mark[cur] = cyclenumber;

		while (cur != u) {
			cur = par[cur];
			mark[cur] = cyclenumber;
		}
		return;
	}
	par[u] = p;

	color[u] = 1;

	for (int v : graph[u]) {

		if (v == par[u]) {
			continue;
		}
		dfs_cycle(v, u, color, mark, par, cyclenumber);
	}

	color[u] = 2;
}

void addEdge(int u, int v)
{
	graph[u].push_back(v);
	graph[v].push_back(u);
}

void printCycles(int edges, int mark[], int& cyclenumber)
{
	bool present;
	for (int i = 1; i <= edges; i++) {
		if (mark[i] != 0)
			cycles[mark[i]].push_back(i);
	}

	for (int i = 1; i <= cyclenumber; i++) {
        if(cycles[i].size()%2 !=0){
            cout << "Not Bipartite as odd cycle is present with vertices : ";
			present = true;
            for (int x : cycles[i])
			    cout << x << " ";
        }
		cout << endl;
	}
	if(!present){
		cout << "It is a Bipartite Graph";
	}
}

int main()
{

	// add edges
	addEdge(1, 2);
	addEdge(2, 3);
	addEdge(3, 4);
	addEdge(4, 6);
	addEdge(4, 7);
	addEdge(5, 6);
	addEdge(3, 5);
	addEdge(7, 8);
	addEdge(6, 10);
	addEdge(5, 9);
	addEdge(10, 11);
	addEdge(11, 12);
	addEdge(11, 13);
	addEdge(12, 13);

	int color[N];
	int par[N];

	int mark[N];

	int cyclenumber = 0;
	int edges = 13;

	dfs_cycle(1, 0, color, mark, par, cyclenumber);

	printCycles(edges, mark, cyclenumber);
}
