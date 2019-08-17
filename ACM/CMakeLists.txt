cmake_minimum_required(VERSION 3.1)

project(Algorithm)

set(CMAKE_CXX_STANDARD 17)
set(ACM_SRC
		Stack_Queue.cpp
		Tree.cpp
		# 动态规划 第九章
		9.1.cpp     # 数字三角形
		9.2.cpp     # DAG 上的动态规划
		9.3.cpp     # 背包问题

		# #### 更多经典模型
		9.4.1.cpp   # 线性结构上的动态规划
		9.4.2.cpp   # 凸多边形上的动态规划
		9.4.3.cpp   # 树上的动态规划
		9.4.4.cpp   # 复杂状态的动态规划

		# 图论算法 第十一章
		11.1.cpp
		11.2.cpp
		11.3.cpp  # Kruskal 最小生成树
		11.4.cpp  # Dijkstra 最短路径
		11.4-2.cpp # Bellman-Ford 最短路径
		11.4-3.cpp # Floyd 两点之间最短路径
		UVa506.cpp
		UVa572.cpp
		UVa816.cpp
		UVa1572.cpp
		UVa1599.cpp
		UVa12171.cpp
		UVa10305.cpp
		UVa10129.cpp
		UVa10562.cpp)

add_executable(acm ${ACM_SRC})