#include <bits/stdc++.h>
using namespace std;

#define ROW 9
#define COL 10

// Stores the coordinates
// of the matrix cell
struct Point {
	int x, y;
};

// Stores coordinates of
// a cell and its distance
struct Node {
	Point pt;
	int dist;
};

// Check if the given cell is valid or not
bool isValid(int row, int col)
{
	return (row >= 0) && (col >= 0)
		&& (row < ROW) && (col < COL);
}

// Stores the moves of the directions of adjacent cells
int dRow[] = { -1, 0, 0, 1 };
int dCol[] = { 0, -1, 1, 0 };

// Function to find the shortest path from the
// source to finishination in the given matrix
void pathMoves(char data[][COL],
			Point start, Point finish)
{
	// Stores the distance for each
	// cell from the source cell
	int d[ROW][COL];
	memset(d, -1, sizeof d);

	// Distance of source cell is 0
	d[start.x][start.y] = 0;

	// Initialize a visited array
	bool visited[ROW][COL];
	memset(visited, false, sizeof visited);

	// Mark source cell as visited
	visited[start.x][start.y] = true;

	// Create a queue for BFS
	queue<Node> q;

	// Distance of source cell is 0
	Node s = { start, 0 };

	// Enqueue source cell
	q.push(s);

	// Keeps track of whether
	// finishination is reached or not
	bool ok = false;

	// Iterate until queue is not empty
	while (!q.empty()) {

		// Deque front of the queue
		Node curr = q.front();
		Point pt = curr.pt;

		// If the finishination cell is
		// reached, then find the path
		if (pt.x == finish.x
			&& pt.y == finish.y) {

			int xx = pt.x, yy = pt.y;
			int dist = curr.dist;

			// Assign the distance of
			// finishination to the
			// distance datarix
			d[pt.x][pt.y] = dist;

			// Stores the smallest path
			string pathmoves = "";

			// Iterate until source is reached
			while (xx != start.x
				|| yy != start.y) {

				// Append D
				if (xx > 0 && d[xx - 1][yy] == dist - 1) {
					pathmoves += 'D';
                    cout << "(" << xx << "," << yy << ")" << " <-- ";
					xx--;
				}

				// Append U
				if (xx < ROW - 1
					&& d[xx + 1][yy]
						== dist - 1) {
					pathmoves += 'U';
                    cout << "(" << xx << "," << yy << ")" << " <-- ";
					xx++;
				}

				// Append R
				if (yy > 0 && d[xx][yy - 1] == dist - 1) {
					pathmoves += 'R';
                    cout << "(" << xx << "," << yy << ")" << " <-- ";
					yy--;
				}

				// Append L
				if (yy < COL - 1
					&& d[xx][yy + 1]
						== dist - 1) {
					pathmoves += 'L';
                    cout << "(" << xx << "," << yy << ")" << " <-- ";
					yy++;
				}
				dist--;
			}

			// Reverse the backtracked path
			reverse(pathmoves.begin(),
					pathmoves.end());

			cout << "(" << start.x << "," << start.y << ")" << endl;
            cout << pathmoves;
			ok = true;
			break;
		}

		// Pop the start of queue
		q.pop();

		// Explore all adjacent directions
		for (int i = 0; i < 4; i++) {
			int row = pt.x + dRow[i];
			int col = pt.y + dCol[i];

			// If the current cell is valid
			// cell and can be traversed
			if (isValid(row, col)
				&& (data[row][col] == '1'
					|| data[row][col] == 's'
					|| data[row][col] == 'd')
				&& !visited[row][col]) {

				// Mark the adjacent cells as visited
				visited[row][col] = true;

				// Enque the adjacent cells
				Node adjCell
					= { { row, col }, curr.dist + 1 };
				q.push(adjCell);

				// Update the distance
				// of the adjacent cells
				d[row][col] = curr.dist + 1;
			}
		}
	}

	// If the finishination
	// is not reachable
	if (!ok)
		cout << -1;
}

// Driver Code
int main()
{
	char data[ROW][COL] = {
		{ '1', '0', '1', '1', '1', '1', '0', '1', '1', '1' },
		{ '1', '0', '1', '0', '1', '1', '1', '0', '1', '1' },
		{ '1', '1', '1', '0', '1', '1', '0', '1', '0', '1' },
		{ '0', '0', '0', '0', '1', '0', '0', '0', '0', '1' },
		{ '1', '1', '1', '0', '1', '1', '1', '0', '1', '0' },
		{ '1', '0', '1', '1', '1', '1', '0', '1', '0', '0' },
		{ '1', '0', '0', '0', '0', '0', '0', '0', '0', '1' },
		{ '1', '0', '1', '1', '1', '1', '0', '1', '1', '1' },
		{ '1', '1', '0', '0', '0', '0', '1', '0', '0', '1' }
	};
	Point start = { 0, 0 };
	Point finish = { 3, 4 };

	pathMoves(data, start, finish);

	return 0;
}
