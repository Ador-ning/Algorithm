//
// Created by ning on 2019/2/19.
//

#include <memory>
#include <iostream>
#include "Ptr.h"

using std::unique_ptr;
using std::shared_ptr;
using std::weak_ptr;
using std::cout;
using std::endl;

// 1. 它持有对对象的独有权——两个unique_ptr不能指向一个对象，即unique_ptr不共享它的所管理的对象
// 2. 无法复制到其他unique_ptr，无法通过值传递到函数
// 3. 只能移动 unique_ptr，即对资源管理权限可以实现转移 -- std::move()
// 内存资源所有权可以转移到另一个unique_ptr，并且原始 unique_ptr 不再拥有此资源
void test_uniquePtr() {
	unique_ptr<int> uptr(new int(10));
	//std::unique_ptr<int> uptr2 = uptr;  //不能賦值
	//std::unique_ptr<int> uptr2(uptr);  //不能拷貝
	std::unique_ptr<int> uptr2 = std::move(uptr); //轉換所有權
	uptr2.release(); //释放所有权
}

// 1. 共享所有权的智能指针，允许多个指针指向同一个对象
// 2. shared_ptr利用引用计数的方式实现了对所管理的对象的所有权的分享，即允许多个shared_ptr共同管理同一个对象
// 3. 注意避免循环引用，shared_ptr的一个最大的陷阱是循环引用，循环，循环引用会导致堆内存无法正确释放，导致内存泄漏
// 1）shared_ptr 对象除了包括一个所拥有对象的指针外，还必须包括一个引用计数代理对象的指针
//（2）时间上的开销主要在初始化和拷贝操作上， *和->操作符重载的开销跟auto_ptr是一样
void test_sharedPtr() {
	int a = 10;
	shared_ptr<int> ptra = std::make_shared<int>(a);
	shared_ptr<int> ptra2(ptra); // copy
	cout << ptra.use_count() << endl;

	int b = 20;
	int *pb;
	shared_ptr<int> ptrb = std::make_shared<int>(b);
	ptra2 = ptrb; // assign
	pb = ptrb.get();
	cout << ptra.use_count() << ' ' << ptrb.use_count() << endl;
}

// 1. weak_ptr是为了配合shared_ptr而引入的一种智能指针，它更像是shared_ptr的一个助手而不是智能指针
// 2. 没有重载operator*和->
// 3. 最大作用在于协助shared_ptr工作，可获得资源的观测权
// 4. weak_ptr只对shared_ptr 进行引用，而不改变其引用计数，当被观察的shared_ptr失效后，相应的weak_ptr也相应失效。
void test_weakPtr() {
	shared_ptr<int> sh_ptr = std::make_shared<int>(10);
	cout << sh_ptr.use_count() << endl;

	weak_ptr<int> wp(sh_ptr);
	cout << wp.use_count() << endl; // 可以观测资源的引用计数

	if (!wp.expired()) { // 功能等价于use_count() != 0
		shared_ptr<int> sh_ptr2 = wp.lock(); // 从被观测的shared_ptr获得一个可用的shared_ptr对象， 从而操作资源
		*sh_ptr2 = 100;
		cout << wp.use_count() << endl;
	}

	cout << *sh_ptr.get() << endl;
}

void test_loopReference() {
	weak_ptr<Parent> wpp;
	weak_ptr<Child> wpc;

	{
		shared_ptr<Parent> p(new Parent);
		shared_ptr<Child> c(new Child);
		p->setChild(c);
		c->setParent(p);
		wpp = p;
		wpc = c;

		cout << p.use_count() << endl; // 2
		cout << c.use_count() << endl; // 1
	}

	cout << wpp.use_count() << endl; // 0
	cout << wpc.use_count() << endl; // 0
}