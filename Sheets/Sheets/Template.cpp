#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <map>

using namespace std;

struct Rectangle {
    int x1, y1, x2, y2;
};

int main() {
    int n, t;
    cin >> n >> t;

    vector<Rectangle> sheets(n);
    set<int> x_coords, y_coords;

    // Read the input rectangles and store unique x and y coordinates
    for (int i = 0; i < n; ++i) {
        cin >> sheets[i].x1 >> sheets[i].y1 >> sheets[i].x2 >> sheets[i].y2;
        x_coords.insert(sheets[i].x1);
        x_coords.insert(sheets[i].x2);
        y_coords.insert(sheets[i].y1);
        y_coords.insert(sheets[i].y2);
    }

    // Map unique coordinates to a compressed index
    vector<int> x_sorted(x_coords.begin(), x_coords.end());
    vector<int> y_sorted(y_coords.begin(), y_coords.end());

    map<int, int> x_map, y_map;
    for (int i = 0; i < x_sorted.size(); ++i) x_map[x_sorted[i]] = i;
    for (int i = 0; i < y_sorted.size(); ++i) y_map[y_sorted[i]] = i;

    // Create a grid to mark covered areas
    vector<vector<int>> grid(x_sorted.size(), vector<int>(y_sorted.size(), 0));

    // Mark the grid with the rectangles
    for (const auto& rect : sheets) {
        for (int i = x_map[rect.x1]; i < x_map[rect.x2]; ++i) {
            for (int j = y_map[rect.y1]; j < y_map[rect.y2]; ++j) {
                grid[i][j] = 1;
            }
        }
    }

    // Calculate the area and circumference
    int area = 0, circumference = 0;
    int dx[] = { 1, 0, -1, 0 };
    int dy[] = { 0, 1, 0, -1 };

    for (int i = 0; i < x_sorted.size() - 1; ++i) {
        for (int j = 0; j < y_sorted.size() - 1; ++j) {
            if (grid[i][j] == 1) {
                // Calculate the area of the cell
                area += (x_sorted[i + 1] - x_sorted[i]) * (y_sorted[j + 1] - y_sorted[j]);

                // Check the edges for circumference
                for (int k = 0; k < 4; ++k) {
                    int ni = i + dx[k];
                    int nj = j + dy[k];

                    if (ni < 0 || ni >= x_sorted.size() - 1 || nj < 0 || nj >= y_sorted.size() - 1 || grid[ni][nj] == 0) {
                        // Add the length of the edge
                        if (k % 2 == 0) { // Horizontal edge
                            circumference += y_sorted[j + 1] - y_sorted[j];
                        }
                        else { // Vertical edge
                            circumference += x_sorted[i + 1] - x_sorted[i];
                        }
                    }
                }
            }
        }
    }

    // Output the results
    cout << area << endl;
    if (t == 2) {
        cout << circumference << endl;
    }

    return 0;
}