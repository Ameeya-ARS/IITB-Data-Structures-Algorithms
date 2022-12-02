#include <iostream>
#include <stdlib.h>
using namespace std;
void Graph(int edges, int vertices)
{
    int i, j, edge[edges][2], count;
    i = 0;
    while (i < edges)
    {
        edge[i][0] = rand() % vertices + 1;
        edge[i][1] = rand() % vertices + 1;
        if (edge[i][0] == edge[i][1])
            continue;
        else
        {
            for (j = 0; j < i; j++)
            {
                if ((edge[i][0] == edge[j][0] &&
                     edge[i][1] == edge[j][1]) ||
                    (edge[i][0] == edge[j][1] &&
                     edge[i][1] == edge[j][0]))
                    i--;
            }
        }
        i++;
    }
    cout << "\nDetails of the random graph: ";
    for (i = 0; i < vertices; i++)
    {
        count = 0;
        cout << "\n\t" << i + 1 << "-> { ";
        for (j = 0; j < edges; j++)
        {
            if (edge[j][0] == i + 1)
            {
                cout << edge[j][1] << " ";
                count++;
            }
            else if (edge[j][1] == i + 1)
            {
                cout << edge[j][0] << " ";
                count++;
            }
            else if (j == edges - 1 && count == 0)
                cout << "Isolated Vertex!";
        }
        cout << "}";
    }
}
int main()
{
    int N;
    cout << "Enter the number of vertices for the graph : ";
    cin >> N;
    Graph(N * 2, N);
}