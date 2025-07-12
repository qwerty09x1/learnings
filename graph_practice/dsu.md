# DSU (Disjoint Set Union) Problem Sheet - C++

## Template Code

```cpp
class DSU {
private:
    vector<int> parent, rank;
    
public:
    DSU(int n) {
        parent.resize(n);
        rank.resize(n, 0);
        for(int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }
    
    int find(int x) {
        if(parent[x] != x) {
            parent[x] = find(parent[x]); // Path compression
        }
        return parent[x];
    }
    
    void unite(int x, int y) {
        int px = find(x), py = find(y);
        if(px == py) return;
        
        // Union by rank
        if(rank[px] < rank[py]) {
            parent[px] = py;
        } else if(rank[px] > rank[py]) {
            parent[py] = px;
        } else {
            parent[py] = px;
            rank[px]++;
        }
    }
    
    bool connected(int x, int y) {
        return find(x) == find(y);
    }
};
```

---

## Basic Problems

### 1. **Number of Connected Components**
**Difficulty:** Easy  
**Problem:** Given `n` nodes and a list of edges, find the number of connected components.

```cpp
int countComponents(int n, vector<vector<int>>& edges) {
    // Your code here
}
```

**Sample Input:**
```
n = 5
edges = [[0,1], [1,2], [3,4]]
```
**Expected Output:** `2`

---

### 2. **Check if Two Nodes are Connected**
**Difficulty:** Easy  
**Problem:** Given `n` nodes and a list of edges, answer `q` queries asking if two nodes are connected.

```cpp
vector<bool> areConnected(int n, vector<vector<int>>& edges, vector<vector<int>>& queries) {
    // Your code here
}
```

**Sample Input:**
```
n = 4
edges = [[0,1], [1,2]]
queries = [[0,2], [1,3]]
```
**Expected Output:** `[true, false]`

---

### 3. **Friend Circles**
**Difficulty:** Easy  
**Problem:** There are `n` people. If person `i` knows person `j`, then `M[i][j] = 1`, otherwise `M[i][j] = 0`. Find the number of friend circles.

```cpp
int findCircleNum(vector<vector<int>>& M) {
    // Your code here
}
```

---

## Intermediate Problems

### 4. **Redundant Connection**
**Difficulty:** Medium  
**Problem:** Given a graph with `n` nodes and `n` edges, find the edge that when removed makes the graph a tree.

```cpp
vector<int> findRedundantConnection(vector<vector<int>>& edges) {
    // Your code here
}
```

**Sample Input:**
```
edges = [[1,2], [1,3], [2,3]]
```
**Expected Output:** `[2,3]`

---

### 5. **Accounts Merge**
**Difficulty:** Medium  
**Problem:** Given a list of accounts with names and emails, merge accounts that belong to the same person.

```cpp
vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
    // Your code here
}
```

**Sample Input:**
```
accounts = [["John", "johnsmith@mail.com", "john00@mail.com"], 
           ["John", "johnnybravo@mail.com"], 
           ["John", "johnsmith@mail.com", "john_newyork@mail.com"]]
```

---

### 6. **Most Stones Removed**
**Difficulty:** Medium  
**Problem:** Stones are placed on a 2D plane. A stone can be removed if it shares a row or column with another stone. Find the maximum number of stones that can be removed.

```cpp
int removeStones(vector<vector<int>>& stones) {
    // Your code here
}
```

---

### 7. **Graph Connectivity After Queries**
**Difficulty:** Medium  
**Problem:** Given `n` nodes and `q` queries of type "add edge (u,v)" or "check if u and v are connected", process all queries.

```cpp
vector<bool> processQueries(int n, vector<vector<int>>& queries) {
    // queries[i] = [type, u, v] where type: 0=add edge, 1=check connection
    // Your code here
}
```

---

## Advanced Problems

### 8. **Minimum Spanning Tree (Kruskal's Algorithm)**
**Difficulty:** Medium-Hard  
**Problem:** Find the minimum spanning tree of a weighted graph using DSU.

```cpp
struct Edge {
    int u, v, weight;
    bool operator<(const Edge& other) const {
        return weight < other.weight;
    }
};

int kruskalMST(int n, vector<Edge>& edges) {
    // Your code here
}
```

---

### 9. **Number of Islands II**
**Difficulty:** Hard  
**Problem:** Given an `m x n` grid, process queries that add land at position `(i,j)`. After each query, return the number of islands.

```cpp
vector<int> numIslands2(int m, int n, vector<vector<int>>& positions) {
    // Your code here
}
```

---

### 10. **DSU with Rollback**
**Difficulty:** Hard  
**Problem:** Implement DSU that supports rollback operations to undo the last `k` union operations.

```cpp
class DSUWithRollback {
private:
    vector<int> parent, rank;
    stack<pair<int, int>> history; // stores (node, old_parent)
    
public:
    DSUWithRollback(int n) {
        // Your code here
    }
    
    int find(int x) {
        // Your code here (no path compression for rollback)
    }
    
    void unite(int x, int y) {
        // Your code here
    }
    
    void rollback(int steps) {
        // Your code here
    }
};
```

---

### 11. **Weighted DSU**
**Difficulty:** Hard  
**Problem:** Implement DSU where each node has a weight relative to its parent. Support queries to find the relative weight between two nodes.

```cpp
class WeightedDSU {
private:
    vector<int> parent, weight;
    
public:
    WeightedDSU(int n) {
        // Your code here
    }
    
    pair<int, int> find(int x) {
        // Returns {root, weight_to_root}
        // Your code here
    }
    
    void unite(int x, int y, int w) {
        // Unite such that weight[y] - weight[x] = w
        // Your code here
    }
    
    int getWeight(int x, int y) {
        // Returns weight[y] - weight[x] if connected, else -1
        // Your code here
    }
};
```

---

### 12. **Dynamic Connectivity**
**Difficulty:** Hard  
**Problem:** Given a sequence of edge additions and deletions, answer connectivity queries efficiently.

```cpp
class DynamicConnectivity {
public:
    void addEdge(int u, int v) {
        // Your code here
    }
    
    void removeEdge(int u, int v) {
        // Your code here
    }
    
    bool isConnected(int u, int v) {
        // Your code here
    }
};
```

---

## Challenge Problems

### 13. **Maximum XOR After Queries**
**Difficulty:** Very Hard  
**Problem:** Given an array and queries to unite indices, find the maximum XOR of any two elements in the same component after each query.

### 14. **Persistent DSU**
**Difficulty:** Very Hard  
**Problem:** Implement DSU that supports queries at any point in time (version control).

### 15. **DSU on Trees**
**Difficulty:** Very Hard  
**Problem:** Given a tree, for each node, find the number of distinct colors in its subtree using DSU optimization.

---

## Tips for Solving DSU Problems

1. **Identify the Pattern:** Look for problems involving grouping, connectivity, or merging sets
2. **Path Compression:** Always use path compression for efficiency
3. **Union by Rank:** Helps maintain balanced trees
4. **Count Components:** Keep track of the number of components if needed
5. **Size Information:** Sometimes you need to track the size of each component
6. **Edge Cases:** Handle self-loops and multiple edges between same nodes
7. **Optimization:** For advanced problems, consider techniques like DSU rollback or persistent DSU

## Time Complexity
- **Find:** O(α(n)) amortized, where α is the inverse Ackermann function
- **Union:** O(α(n)) amortized  
- **Space:** O(n)

Where α(n) is practically constant for all reasonable values of n.