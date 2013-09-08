//
//  Graph.cpp
//  AlgorithmTutorials
//
//  Created by Vishal Patel on 9/09/13.
//  Copyright (c) 2013 Vishal. All rights reserved.
//

#include "Graph.h"

Graph::Graph() {
}

Graph::Graph(int v) {
	this->V = v;
	this->adj = new list <int>[V];
}

void Graph::addEdge(int v, int w) {
	adj[v].push_back(w);
}

void Graph::dfsUtil(int v, bool *visisted) {
	visisted[v] = true;
	cout << v << " ";
    
	list <int>::iterator it;
	for (it = adj[v].begin(); it != adj[v].end(); it++) {
		if (visisted[*it] == false) {
			dfsUtil(*it, visisted);
		}
	}
}

void Graph::DFS() {
	bool *visited = new bool[V];
	for (int i = 0; i < V; i++) {
		visited[i] = false;
	}
    
	for (int i = 0; i < V; i++) {
		if (visited[i] == false)
			dfsUtil(i, visited);
	}
}

void Graph::BFS(int s) {
	bool *visited = new bool[V];
	list <int> queue;
	for (int i = 0; i < V; i++) {
		visited[i] = false;
	}
    
	visited[s] = true;
	queue.push_back(s);
    
	while (!queue.empty()) {
		s = queue.front();
		cout << s << " ";
		queue.pop_front();
		visited[s] = true;
		list <int>::iterator it;
		for (it = adj[s].begin(); it != adj[s].end(); it++) {
			if (visited[*it] == false) {
				queue.push_back(*it);
			}
		}
	}
}

void Graph::run() {
	Graph g(4);
	g.addEdge(0, 1);
	g.addEdge(0, 2);
	g.addEdge(1, 2);
	g.addEdge(2, 0);
	g.addEdge(2, 3);
	g.addEdge(3, 3);
    
	g.DFS();
	cout << endl;
    
	g.BFS(2);
	cout << endl;
}

Graph::~Graph() {
	// add clenaup code
}
