
# File Transmission Through a Router Network

> Compute the **maximum transmissible packet size** between two routers in a network modeled as a **weighted multi‑edge graph**.  
> Uses a **modified (widest-path) Dijkstra’s algorithm** running in **O(E log V)**.

---

## 🚀 Problem Statement

Given a network of routers where each link has a **maximum packet size (capacity)**, determine the largest packet that can be sent from a **source router** to a **destination router**.  
This is the classic **widest path / max–min bottleneck path** problem.

- **Vertices (V):** Routers  
- **Edges (E):** Links between routers (multi-edges allowed)  
- **Edge weight:** Maximum packet size that link can carry  
- **Goal:** Maximize the minimum edge weight along the path

---

## 🧠 Core Idea (Algorithm)

We adapt Dijkstra’s algorithm:

- Replace “distance sum” with “path capacity” = `min(edge weights on the path)`.
- Use a **max-heap** (priority queue) keyed by current best capacity to each node.
- Relaxation step: `new_cap = min(best[u], w)`; if `new_cap > best[v]`, update.

**Time Complexity:** `O(E log V)`

---

## 📁 Project Structure 
├── src/

│ └── router_net.cpp # main implementation

├── data/

│ └── sample_input.txt # example input

├── README.md

└── LICENSE




