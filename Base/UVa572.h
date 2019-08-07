//
// Created by ning on 2018/11/23.
//

#ifndef ALGORITHM_GRAPH_H
#define ALGORITHM_GRAPH_H

#include <iostream>
#include <queue>
#include <set>
#include <stack>
#include "../Base.h"


/*
 *  图分为无向图和有向图。
 *  在无向图中，若图中任意一对顶点都是连通的，则称此图是连通图。
 *  在有向图中，若任意一对顶点u和v间存在一条从u到v的路径和从v到u的路径，则称此图是强连通图。
 *  无向图的一个极大连通子图称为该图的一个连通分量。
 *  有向图的一个极大强连通子图称为该图的一个强连通分量。
 *  在图的每条边上加上一个数字作权，也称代价，带权的图称为网。
 * */

namespace Algorithm {

	// 边结点类
	template<typename T>
	class ENode {
	public:
		int vertex; // 端点号1
		int adjVex; // 端点号2
		T weight; // 边权值
		ENode<T> *next;

		ENode() : next(nullptr) {}

		ENode(int ver, int adj, T w, ENode<T> *next_) : vertex(ver), adjVex(adj),
		                                                weight(w), next(next_) {}

		operator T() const { return weight; }

		bool operator<(const ENode<T> &rhs) const {
			return this->weight > rhs.weight; // 最小值优先
		}
	};

	// 自定义优先队列 less 的比较函数
	// 函数对象  -- 重载 () 操作符
	template<typename T>
	class cmp {
	public:
		bool operator()(const ENode<T> &a, const ENode<T> &b) const {
			return a.weight > b.weight;
		}
	};

	// 图类
	template<typename T>
	class Graph {
	public:
		Graph(int size);

		~Graph();

		// 边u->v是否存在
		bool Exist(int u, int v) const;

		// 插入边u->v
		bool Insert(int u, int v, T w);

		// 删去边u->v
		bool Remove(int u, int v);

		//得到反向图
		Graph<T> Reverse();

		void DFS();

		void BFS();

		//判断是否有环
		bool HasCycle();

		//返回环
		std::stack<int> GetCycle();

		//通过递归调用DFSForReversePost来求得
		void CalReversePost();

		//拓扑排序
		void TopoSort();

		//用DFS来求拓扑序列
		void TopoSortByDFS();

		//返回DFS中顶点的逆后序序列
		std::stack<int> GetReversePost() {
			// 因为栈的特殊性,这里直接返回一个拷贝,以保证源栈不会因为外界操作而改变
			std::stack<int> temp(reversePost);
			return temp;
		}

		//求图的强连通分量
		void CalculateConnection();

		//得到强连通分量数
		int GetConnectedCount() {
			return connectedCount;
		}

		//v所在的强连通分量的标识符(1~connectedCount)
		int ConnectionID(int v) {
			return id[v];
		}

		//打印强连通分量
		void ShowConnection();

		//用tarjan算法求强连通分量
		void TarjanForConnection();


		//普里姆算法求无向图最小代价生成树,外部接口
		void Prim(int v0);

		//克鲁斯卡尔算法求无向图最小代价生成树,外部接口
		void Kruskal();

		//迪杰斯特拉算法解决单源最短路径问题
		void Dijkstra(int v0);

		//弗洛伊德算法求所有顶点之间的最短路径
		void Floyd();

		//获得边u-v的权值
		T GetWeight(int u, int v);


	private:
		void DFS(int v, std::vector<bool> &visited);

		void BFS(int v, std::vector<bool> &visited);

		//用DFS思想来判断环
		void DFSForCycle(int v, std::vector<bool> &visited, std::vector<bool> &onStack, std::vector<int> &edgeTo);

		//用DFS思想来求逆后序序列,用于求拓扑序列或者强连通分量
		void DFSForReversePost(int v, std::vector<bool> &visited);

		//用DFS思想来求强连通分量
		void DFSForConnection(int v, std::vector<bool> &visited);

		//用tarjan算法求强连通分量,其实也是运用了DFS思想
		void TarjanForConnection(int u, std::vector<bool> &visited, std::vector<int> &DFN, std::vector<int> &low,
		                         std::stack<int> *tarjanStack, std::vector<bool> &inStack, int &index);

		// 清空栈 cycle 中的记录
		void ClearCycle() {
			while (!cycle.empty())
				cycle.pop();
		}

		// 清空栈 reversePost 中的记录
		void ClearReversePost() {
			while (!reversePost.empty())
				reversePost.pop();
		}

		void ClearId() {
			for (int i = 0; i < id.size(); ++i)
				id[i] = 0;
		}

		// 计算所有顶点的入度
		void CalInDegree(std::vector<int> &inDegree);

		//普里姆算法求无向图最小代价生成树,私有,内部调用
		void Prim(int v0, int *nearest, T *lowcost);

		//克鲁斯卡尔算法求无向图最小代价生成树,私有,内部调用
		void Kruskal(std::priority_queue<ENode<T>> &pq);

		//迪杰斯特拉算法解决单源最短路径问题,私有,内部调用
		void Dijkstra(int v0, int *path, T *curShortLen);

		//Dijkstra算法的辅助函数,用于找出下一条最短路径的终点
		int FinMinLen(T *curShortLen, bool *mark);

		ENode<T> **enodes;
		int n;      // 顶点个数
		int edges;  // 边的个数
		int connectedCount; // 强连同通分量个数
		std::vector<int> id;    // 由定点索引的数组，存放顶点所属的连同分量标识符
		std::vector<int> *tarjanConnection; // tarjan 算法得到的强连通分量
		int connectedCountForTarJan; // 在tarjan算法中使用的强连通分量个数
		bool hasCycle; // 是否有环
		std::stack<int> cycle; // 有向环中的所有顶点（如果存在）
		std::stack<int> reversePost; //通过DFS得到的所有顶点的逆后序排列
		// UnionFind *uf;           //用于Kruskal算法,用来判断最小生成树森林中是否会构成回路
	};
}


#endif //ALGORITHM_GRAPH_H
