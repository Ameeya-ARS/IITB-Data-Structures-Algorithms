#include <bits/stdc++.h>
using namespace std;

#define ROW 9
#define COL 10

struct Point {
	int x, y;
};

struct Node {
	Point pt;
	int dist;
};

bool isValid(int row, int col)
{
	return (row >= 0) && (col >= 0)
		&& (row < ROW) && (col < COL);
}

int dRow[] = { -1, 0, 0, 1 };
int dCol[] = { 0, -1, 1, 0 };

void pathMoves(char data[][COL],
			Point start, Point finish)
{
	int d[ROW][COL];
	memset(d, -1, sizeof d);

	d[start.x][start.y] = 0;

	bool visited[ROW][COL];
	memset(visited, false, sizeof visited);

	visited[start.x][start.y] = true;

	queue<Node> q;

	Node s = { start, 0 };

	q.push(s);

	bool ok = false;

	while (!q.empty()) {

		Node curr = q.front();
		Point pt = curr.pt;

		if (pt.x == finish.x
			&& pt.y == finish.y) {

			int xx = pt.x, yy = pt.y;
			int dist = curr.dist;

			d[pt.x][pt.y] = dist;

			while (xx != start.x
				|| yy != start.y) {

				if (xx > 0 && d[xx - 1][yy] == dist - 1) {
                    cout << "(" << xx << "," << yy << ")" << " <-- ";
					xx--;
				}

				if (xx < ROW - 1
					&& d[xx + 1][yy]
						== dist - 1) {
                    cout << "(" << xx << "," << yy << ")" << " <-- ";
					xx++;
				}

				if (yy > 0 && d[xx][yy - 1] == dist - 1) {
                    cout << "(" << xx << "," << yy << ")" << " <-- ";
					yy--;
				}

				if (yy < COL - 1
					&& d[xx][yy + 1]
						== dist - 1) {
                    cout << "(" << xx << "," << yy << ")" << " <-- ";
					yy++;
				}
				dist--;
			}

			cout << "(" << start.x << "," << start.y << ")" << endl;
			ok = true;
			break;
		}

		q.pop();

		for (int i = 0; i < 4; i++) {
			int row = pt.x + dRow[i];
			int col = pt.y + dCol[i];

			if (isValid(row, col)
				&& (data[row][col] == '1'
					|| data[row][col] == 's'
					|| data[row][col] == 'd')
				&& !visited[row][col]) {

				visited[row][col] = true;

				Node adjCell
					= { { row, col }, curr.dist + 1 };
				q.push(adjCell);

				d[row][col] = curr.dist + 1;
			}
		}
	}

	if (!ok)
		cout << -1;
}

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
