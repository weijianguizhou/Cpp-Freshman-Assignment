#include <iostream>
#include <vector>
#include <limits>
#include <iomanip> 

using namespace std;

const int MAX_VERTICES = 6;

const int INF = numeric_limits<int>::max();

void shortpath_dij(const int g[][MAX_VERTICES], int v0, vector<int>& dist, vector<int>& pre) {

    const int NUM = MAX_VERTICES;

    vector<bool> set(NUM, false);

    int src_index = v0 - 1;

    dist.resize(NUM);
    pre.resize(NUM, -1); 

    for (int i = 0; i < NUM; i++) {
        dist[i] = g[src_index][i];

        if (dist[i] != INF && i != src_index) {
            pre[i] = src_index;
        }
    }

    set[src_index] = true;
    dist[src_index] = 0; 
    pre[src_index] = src_index;

    for (int i = 1; i < NUM; i++) {
        int min_dist = INF;
        int v = -1; // 记录 V-U 中距离最小的顶点索引

        // 2.1 从 V-U 中挑选最小的 dist[w]
        for (int w = 0; w < NUM; w++) {
            // if(set[w] == 0 && dist[w] < min)
            if (set[w] == false && dist[w] < min_dist) {
                v = w;
                min_dist = dist[w];
            }
        }

        // 检查是否所有剩余顶点都不可达 (min_dist 仍然是 INF)
        if (v == -1) {
            break; // 算法结束
        }

        // 2.2 set[v]=1; // 将 v 加入 U 集合 (已确定最短路径)
        set[v] = true;

        // 2.3 更新 V-U 中的 dist[w] (松弛操作)
        for (int w = 0; w < NUM; w++) {
            // if(set[w] == 0 && dist[v] + g[v][w] < dist[w])
            // 确保 v 到 w 有边 (g[v][w] != INF) 并且没有溢出
            if (set[w] == false && g[v][w] != INF) {

                // 计算新的距离：dist[v] + g[v][w]
                long long new_dist = (long long)dist[v] + g[v][w];

                if (new_dist < dist[w]) {
                    // dist[w] = dist[v] + g[v][w];
                    dist[w] = (int)new_dist;

                    // pre[w]=v; // w 的来源（前驱）是 v
                    pre[w] = v;
                }
            }
        }
    }
} // shortpath_dij

// 打印路径的辅助函数
void print_path(int current_index, const vector<int>& pre, int src_index) {
    if (current_index == src_index) {
        cout << current_index + 1;
        return;
    }
    if (pre[current_index] == -1) { // 不可达
        cout << "不可达";
        return;
    }

    // 递归打印前驱
    print_path(pre[current_index], pre, src_index);
    cout << " -> " << current_index + 1;
}

// 主函数演示
int main() {
    const int NUM = MAX_VERTICES;
    const int G[NUM][NUM] = {
        { 0,    10,  INF, INF,  5,    INF },
        { INF,  0,    1,   INF, INF,  INF },
        { INF,  INF,  0,    4,   INF,  INF },
        { INF,  INF, INF,  0,    INF,  INF },
        { INF,  2,    INF, 9,    0,    2   },
        { INF,  INF,  6,   INF,  INF,  0   }
    };

    int source_vertex = 1; // 源点：顶点 1

    vector<int> distances;
    vector<int> predecessors;

    // 执行 Dijkstra 算法
    shortpath_dij(G, source_vertex, distances, predecessors);

    // 打印结果
    cout << "--- 基于邻接矩阵的 Dijkstra 算法结果 (源点: 顶点 " << source_vertex << ") ---" << endl;
    cout << setw(10) << "目标顶点" << setw(10) << "最短距离" << setw(15) << "最短路径" << endl;
    cout << "---------------------------------------------------------" << endl;

    for (int i = 0; i < NUM; ++i) {
        int target_vertex = i + 1;
        int src_index = source_vertex - 1;

        cout << setw(10) << target_vertex << setw(10);

        if (distances[i] == INF) {
            cout << "不可达";
            cout << setw(15) << "N/A" << endl;
        }
        else {
            cout << distances[i];

            cout << setw(15);
            print_path(i, predecessors, src_index);
            cout << endl;
        }
    }
    cout << "---------------------------------------------------------" << endl;

    return 0;
}