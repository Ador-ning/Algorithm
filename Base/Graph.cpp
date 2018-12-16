//
// Created by ning on 2018/11/23.
//

#include <map>
#include <iostream>
#include <string>
#include "Graph.h"

namespace Algorithm {
	template<typename T>
	Graph<T>::Graph(int size):n(size), edges(0), connectedCount(0), hasCycle(false), id(n, 0) {
		enodes = new ENode<T> *[n];


		for (int i = 0; i < n; ++i) {
			enodes[i] = nullptr;
		}

		// uf = new UnionFind(n);
	}

	template<typename T>
	Graph<T>::~Graph() {
		ENode<T> *p, *q;
		for (int i = 0; i < n; ++i) {
			p = enodes[i];
			while (p) {
				q = p;
				p = p->next;
				delete (q);
			}
		}
		delete[] enodes;
		delete[] id;
		// delete uf;
	}

	template<typename T>
	bool Graph::Insert(int u, int v, T w) {
		if (u < 0 || v < 0 || u > n - 1 || v > n - 1 || u == v)
			return false; // 顶点编号无效

		if (Exist(u, v)) {
			std::cout << "Duplicate." << std::endl;
			return false;
		} else {
			//将新边结点插在由指针enodes[u]所指示的单链表最前面
			ENode<T> *p = new ENode<T>(u, v, w, enodes[u]);
			enodes[u] = p;
			edges++;
			return true;
		}
	}

	template<typename T>
	bool Graph<T>::Exist(int u, int v) const {
		if (u < 0 || v < 0 || u > n - 1 || v > n - 1 || u == v)
			return false;

		ENode<T> *p = enodes[u];

		while (p && p->adjVex != v) {
			p = p->next;
		}
		if (p) {
			return true;
		} else {
			return false;
		}
	}

	template<typename T>
	bool Graph<T>::Remove(int u, int v) {
		if (u < 0 || v < 0 || u > n - 1 || v > n - 1 || u == v)
			return false;
		ENode<T> *p = enodes[u];
		ENode<T> *q = nullptr;
		while (p && p->adjVex != v) {
			q = p;
			p = p->next;
		}

		if (!p) {
			std::cout << "Not exist." << std::endl;
			return false;
		}

		edges--;
		if (p == enodes[u]) {
			q = p;
			enodes[u] = p->next;
			delete (q);
		} else {
			q->next = p->next;
			delete (p);
		}
		return true;
	}

	template<typename T>
	Graph<T> Graph<T>::Reverse() {
		Graph<T> R(n);
		for (int i = 0; i < n; ++i) {
			for (ENode<T> *it = enodes[i]; it; it = it->next)
				R.Insert(it->adjVex, i, it->weight);
		}
		return R;
	}

	template<typename T>
	void Graph<T>::DFS() {
		std::vector<bool> visited(n, false);

		for (int i = 0; i < n; i++) {
			if (!visited[i])
				DFS(i, visited);
		}
	}

	// 递归
	template<typename T>
	void Graph<T>::DFS(int v, std::vector<bool> &visited) {
		visited[v] = true;
		std::cout << v << " ";
		for (ENode<T> *it = enodes[v]; it; it = it->next) {
			if (!visited[it->adjVex]) {
				DFS(it->adjVex, visited);
			}
		}
	}

	template<typename T>
	void Graph<T>::BFS() {
		std::vector<bool> visited(n, false);

		for (int i = 0; i < n; ++i) {
			if (!visited[i])
				BFS(i, visited);
		}
	}

	// 递归
	template<typename T>
	void Graph<T>::BFS(int v, std::vector<bool> &visited) {
		visited[v] = true;
		std::cout << v << " ";

		std::queue<T> myQueue;
		myQueue.push(v);
		int s;
		while (!myQueue.empty()) {
			s = myQueue.size();
			myQueue.pop();
			for (ENode<T> *it = enodes[s]; it; it = it->next) {
				if (!visited[it->adjVex]) {
					visited[it->adjVex] = true;
					std::cout << it->adjVex << " ";
					myQueue.push(it->adjVex);
				}
			}
		}
	}

	// 用DFS思想来求逆后序序列,用于求拓扑序列或者强连通分量
	template<typename T>
	void Graph<T>::DFSForReversePost(int v, std::vector<bool> &visited) {
		visited[v] = true;
		for (ENode<T> *it = enodes[v]; it; it = it->next) {
			if (!visited[it->adjVex])
				DFSForReversePost(it->adjVex, visited);
		}
		reversePost.push(v);  // ####
	}

	// 通过调用DFSForReversePost来求得
	template<typename T>
	void Graph<T>::CalReversePost() {
		ClearReversePost();
		std::vector<bool> visited(n, false);
		for (int i = 0; i < n; ++i) {
			if (!visited[i])
				DFSForReversePost(i, visited);
		}
	}


	// 用DFS思想来判断环
	template<typename T>
	void Graph<T>::DFSForCycle(int v, std::vector<bool> &visited,
	                           std::vector<bool> &onStack, std::vector<int> &edgeTo) {

		onStack[v] = true;
		visited[v] = true;

		for (ENode<T> *it = enodes[v]; it; it = it->next) {
			if (hasCycle)
				return;
			else if (!visited[it->adjVex]) {
				edgeTo[it->adjVex] = v;
				DFSForCycle(it->adjVex, visited, onStack, edgeTo);
			} else if (onStack[it->adjVex]) {
				// 此顶点已经在递归调用的栈上,再次访问说明出现环了
				// 用栈cycle将环上的点都保存起来
				for (int i = v; i != it->adjVex; i = edgeTo[i]) {
					cycle.push(i);
				}
				cycle.push(it->adjVex);
				cycle.push(v);
				hasCycle = true;
			}
		}

		// 消除在此递归调用栈上的记录,因为已经递归结束了
		onStack[v] = false;
	}

	template<typename T>
	bool Graph<T>::HasCycle() {
		std::vector<bool> visited(n, false);
		// 由顶点索引的数组,以标记递归调用栈上的所有顶点
		std::vector<bool> onStack(n, false);
		// edgeTo[i]存放指向i的边的点
		std::vector<int> edgeTo(n, -1);

		for (int i = 0; i < n; ++i) {
			if (!visited[i])
				DFSForCycle(i, visited, onStack, edgeTo);
		}
		return hasCycle;
	}

	template<typename T>
	void Graph<T>::CalInDegree(std::vector<int> &inDegree) {
		for (int i = 0; i < n; ++i) {
			for (ENode<T> *it = enodes[i]; it; it = it->next)
				inDegree[it->adjVex]++;
		}
	}

	// 拓扑排序
	template<typename T>
	void Graph<T>::TopoSort() {
		if (HasCycle()) {
			std::cout << "Cycle exists." << std::endl;
			return;
		}

		std::vector<int> inDegree(n, 0);
		CalInDegree(inDegree); // 计算各个顶点入度
		std::queue<int> que;

		// 将入度为 0 的顶点加入队列  -- 拓扑排序规则
		for (int i = 0; i < inDegree.size(); ++i) {
			if (inDegree[i] == 0)
				que.push(i);
		}

		int v, k;
		while (!que.empty()) {
			v = que.front();
			que.pop();
			std::cout << v << " ";
			for (ENode<T> *it = enodes[v]; it; it = it->next) {
				k = it->adjVex;

				// 所有由顶点v指出的邻接点入度-1
				inDegree[k]--;
				if (0 == inDegree[k])
					que.push(k);
			}
		}
	}

	// 用DFS来求拓扑序列
	// 一幅有向无环图的拓扑顺序即为DFS中所有顶点的逆后序排列,所以只要求该逆后序排列就好
	// 如果该图是有环的,就说明拓扑序列不存在,尽管该逆后序排列仍能求出来
	template<typename T>
	void Graph<T>::TopoSortByDFS() {
		if (HasCycle()) {       //存在环,直接返回
			std::cout << "Cycle exists." << std::endl;
			return;
		}
		CalReversePost();
	}

	// 用 DFS 求解强连通分量
	template<typename T>
	void Graph<T>::DFSForConnection(int v, std::vector<bool> &visited) {
		visited[v] = true;
		id[v] = connectedCount;
		for (ENode<T> *it = enodes[v]; it; it = it->next) {
			if (!visited[it->adjVex])
				DFSForConnection(it->adjVex, visited);
		}
	}

	// 求图的强连通分量
	template<typename T>
	void Graph<T>::CalculateConnection() {
		connectedCount = 0;
		std::vector<bool> visited(n, false);
		ClearId();

		// 所有在同一个递归DFS调用中被访问到的顶点都在同一个强连通分量中
		Graph<T> R = this->Reverse();
		R.CalReversePost();
		std::stack<int> reversePost = R.GetReversePost();

		int j;
		while (!reversePost.empty()) {
			j = reversePost.top();
			reversePost.pop();
			if (!visited[j]) {
				connectedCount++;
				DFSForConnection(j, visited);
			}
		}
	}

	template<typename T>
	void Graph<T>::ShowConnection() {
		CalculateConnection();

		std::set<int> connections[connectedCount];
		for (int i = 0; i < n; ++i)
			connections[id[i] - 1].insert(i);

		std::set<int>::iterator it;
		for (int i = 0; i < connectedCount; ++i) {
			std::cout << "Connections " << i + 1 << " : ";
			for (it = connections[i].begin(); it != connections[i].end(); ++it)
				std::cout << *it << " ";
			std::cout << std::endl;
		}
	}

	/*
	 *
	 *
	 *
	 *
	 *
	 * */


	/* // 用 tarjan 算法求强连通分量,其实也是运用了DFS思想
    * visited[u]:顶点u是否被访问过
    * dfn[u]：DFS遍历时顶点u被搜索的次序,也即时间戳
    * low[u]：顶点u能够回溯到的最早位于栈中的顶点
    * tarjanStack：用于存放每次遍历时被搜索到的顶点
    * inStack[u]：u目前是否在栈中,要配合 tarjanStack 使用
    * index：时间戳,随着访问的结点而递增
    */
	template<typename T>
	void Graph<T>::TarjanForConnection(int u, std::vector<bool> &visited, std::vector<int> &dfn, std::vector<int> &low,
	                                   std::stack<int> *tarjanStack, std::vector<bool> &inStack, int &index) {

		dfn[u] = low[u] = ++index; // 为顶点 u 设置访问时间戳和 low 初值
		visited[u] = true; // 修改已访问
		tarjanStack->push(u); // 入栈
		inStack[u] = true;

		// 搜索从顶点 u 指出的每个顶点
		for (ENode<T> *it = enodes[u]; it; it = it->next) {
			if (!visited[it->adjVex]) {
				TarjanForConnection(it->adjVex, visited, dfn, low, tarjanStack, inStack, index);

				// 从上个递归函数返回后就是回溯过程,用u和v即w->adjVex的最小low值来更新low[u]。
				// 因为顶点v能够回溯到的已经在栈中的顶点,顶点u也一定能回溯到。
				// 因为存在从u到v的直接路径,所以v能够到达的顶点u也一定能够到达。
				low[u] = low[u] < low[it->adjVex] ? low[u] : low[it->adjVex];
			} else if (inStack[it->adjVex])
				// 用u的low值和v的DFN值中最小值来更新low[u]。
				// 如果DFN[v]<low[u],则根据low值的定义,即能够回溯到的最早已经在栈中的顶点,所以我们应该用DFN[v]来更新low[u]
				// 表示u能和v回溯到相同的最早顶点
				low[u] = low[u] < dfn[it->adjVex] ? low[u] : dfn[it->adjVex];
		}

		// 搜索完从顶点u指出的所有顶点后判断该结点的low值和DFN值是否相等。
		// 如果相等,则该结点一定是在深度遍历过程中该强连通图中第一个被访问过的顶点,因为它的low值和DFN值最小,不会被该强连通图中其他顶点影响。
		// 既然知道了该顶点是该强连通子树里的根,又根据栈的特性,则该顶点相对于同个连通图中其他顶点一定是在栈的最里面,
		// 所以能通过不断地弹栈来弹出该连通子树中的所有顶点,直到弹出根结点即该顶点为止。
		if (low[u] == dfn[u]) {
			connectedCountForTarJan++;  // 找到一个强连通分量,计数自增
			int x;
			do {
				x = tarjanStack->top();
				tarjanStack->pop();
				inStack[x] = false;     // 注意要和tarjanStack配套使用
				tarjanConnection[connectedCountForTarJan - 1].push_back(x);
			} while (x != u);
		} else {
			return;    // 不等则返回
		}
	}

	//用tarjan算法求强连通分量
	template<typename T>
	void Graph<T>::TarjanForConnection() {
		connectedCountForTarJan = 0;
		std::vector<bool> visited(n, false);
		std::vector<int> dfn(n, 0);
		std::vector<int> low(n, 0);
		std::vector<bool> inStack(n, false);
		std::stack<int> *tarjanStack = new std::stack<int>;

		int index = 0;

		for (int i = 0; i < n; ++i) {
			if (!visited[i])
				TarjanForConnection(i, visited, dfn, low, tarjanStack, inStack, index);
		}

		for (int i = 0; i < connectedCountForTarJan; ++i) {
			std::cout << "connection " << i + 1 << " : ";
			for (auto item : tarjanConnection[i])
				std::cout << item << " ";
			std::cout << std::endl;
		}
	}



}

/*
 * 题目描述：给出若干人之间的通话长度（视为无向边），这些通话将他们分为若干组。每个组的
 * 总边权设为该组内的所有通话的长度之和，而每个人的点权设为该人参与的通话长度之和。现在
 * 给定一个阈值 K，且只要一个组的总边权超过 K，而且成员人数超过2，将该组视为犯罪团伙（Gang）
 * ,而且该组内点权最大的人视为头目。
 *
 * 要求：输出犯罪团伙的个数，并且按照姓名字典从小到大的顺序输出每个犯罪团伙的头目姓名和
 * 成员人数
 */
const int maxn = 2010;

std::map<int, std::string> intToString; // 编号->姓名
std::map<std::string, int> stringToInt; // 姓名->编号
std::map<std::string, int> Gang; // head->人数   输出

int G[maxn][maxn] = {0}; // 邻接矩阵
int weight[maxn] = {0}; // 点权
bool visit[maxn] = {false};
int n, k, numPerson = 0;    // 边数n、下限k、总人数 numPerson

void DFS(int nowVisit, int &head, int &numMember, int &totalValue) {
	numMember++;
	visit[nowVisit] = true;

	if (weight[nowVisit] > weight[head])    // 头目  --   点权
		head = nowVisit;
	// 枚举所有人
	for (int i = 0; i < numPerson; i++) {
		if (G[nowVisit][i] > 0) { // nowVisit -> i  通话
			totalValue += G[nowVisit][i];
			G[nowVisit][i] = G[i][nowVisit] = 0;    // 清除

			if (visit[i] == false)  // 深度递归搜索
				DFS(i, head, numMember, totalValue);
		}
	}
}

void DFStrave() {
	for (int i = 0; i < numPerson; i++) {
		if (visit[i] == false) {
			int head = 0;
			int numMember = 0;
			int totalNumber = 0;
			DFS(i, head, numMember, totalNumber);   // 遍历 i 连通块

			if (numMember > 2 && totalNumber > k) {
				Gang[intToString[head]] = numMember;
			}
		}
	}
}

// 返回 姓名 str对应的编号
int change(std::string str) {
	if (stringToInt.find(str) != stringToInt.end()) { // 姓名出现过
		return stringToInt[str];
	} else {
		stringToInt[str] = numPerson; // str -> numPerson
		intToString[numPerson] = str;
		return numPerson++; // 总人数++
	}
}

int test_Gang() {
	int w;
	std::cin >> n >> k;
	std::string str1, str2;
	for (int i = 0; i < n; i++) {
		std::cin >> str1 >> str2 >> w;   // 端点 权值
		int id1 = stringToInt[str1];
		int id2 = stringToInt[str2];
		weight[id1] += w;
		weight[id2] += w;
		G[id1][id2] = w;
		G[id2][id1] = w;
	}

	DFStrave();
	std::cout << Gang.size() << std::endl;

	std::map<std::string, int>::iterator it;

	for (it = Gang.begin(); it != Gang.end(); it++) {
		std::cout << it->first << ' ' << it->second << std::endl;
	}

	return 0;
}
