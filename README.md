# 🚀 File Transmission

## 📌 Overview
This project implements a **maximum path sum algorithm** for a **directed weighted graph**.  
Unlike the classical Dijkstra’s algorithm (which minimizes path length), this modified version finds the **maximum total weight path** between nodes.

The trick is simple:  
- **Negate all edge weights**, then run standard Dijkstra’s algorithm.  
- Since Dijkstra minimizes the total weight, minimizing the sum of negative weights is equivalent to **maximizing the sum of original weights**.  
- Finally, the result is converted back to positive by taking its negative.

---

## 🧠 Algorithm Idea
- Standard Dijkstra → finds the **shortest path**.  
- Modification:  
  1. Convert all edge weights `w` → `-w`.  
  2. Run Dijkstra’s algorithm to find the shortest path in the transformed graph.  
  3. Resulting distance = most negative sum → corresponds to **maximum sum in the original graph**.  

### Complexity
- **Time:** `O(E log V)` (using priority queue / min-heap)  
- **Space:** `O(V + E)`  

## 📁 Project Structure 
├── src/

│ └── max_path_sum.cpp # main implementation

├── data/

│ └── sample_input.txt # example input graph

├── README.md

└── LICENSE

#Applications

-Optimal route planning where total reward/weight is maximized
-Graph-based optimization in logistics & supply chains
-Game theory & AI pathfinding where score accumulation matters



