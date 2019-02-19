//
// Created by ning on 2019/2/19.
//

#ifndef ALGORITHM_PTR_H
#define ALGORITHM_PTR_H

#include <string>
#include <iostream>
#include <memory>
#include <cassert>

void test_uniquePtr();

void test_sharedPtr();

void test_weakPtr();

void test_loopReference();

// 测试循环引用
class Child;

//class Parent;

class Parent {
public:
	Parent(const std::string str = "parent") : info(str) {}

	void setChild(std::shared_ptr<Child> child) {
		this->ChildPtr = child;
	}

	void doSomething() {
		//new shared_ptr
		if (this->ChildPtr.lock()) {
			auto ptr = ChildPtr.lock();
			// ------  有问题

		}
	}

	~Parent() {}

	void modifyInfo() {
		info += " modified.";
	}

private:
	std::weak_ptr<Child> ChildPtr; // weak_ptr
	std::string info;
};

class Child {
public:
	Child(const std::string str = "child") : info(str) {}

	void setParent(std::shared_ptr<Parent> parent) {
		this->ParentPtr = parent;
	}

	void doSomething() {
		// shared_ptr 管理对象还存在
		if (this->ParentPtr.use_count()) {
			auto p = ParentPtr.get();
			p->modifyInfo();
		}
	}

	~Child() {}

	void modifyInfo() {
		info += " modified.";
	}

private:
	std::shared_ptr<Parent> ParentPtr; // shared_ptr
	std::string info;
};

// shared_ptr
template<typename T>
class SmartPtr {
public:
	SmartPtr(T *ptr = nullptr) : ptr_(ptr) {
		if (ptr_) {
			count_ = new size_t(1);
		} else {
			count_ = new size_t(0);
		}
	}

	SmartPtr(const SmartPtr &ptr) {
		if (this != &ptr) {
			this->ptr_ = ptr.ptr_;
			this->count_ = ptr.count_;
			(*this->count_)++;
		}
	}

	SmartPtr &operator=(const SmartPtr &ptr) {
		// 同一个对象
		if (this == &ptr)
			return *this;

		if (this->ptr_) { // 本来有
			(*this->count_)--; // 1. 减
			if (this->count_ == 0) {
				delete this->ptr_; // 2. 释放
				delete this->count_;
			}
		}

		// new
		this->ptr_ = ptr.ptr_;
		this->count_ = ptr.count_;
		(*this->count_)++;
		return *this;
	}

	T &operator*() {
		assert(this->ptr_ == nullptr);
		return *(this->ptr_);
	}

	// get()
	T *operator->() {
		assert(this->ptr_ == nullptr);
		return this->ptr_;
	}

	T *get() const {
		return ptr_;
	}

	~SmartPtr() {
		(*this->count_)--;
		if (*this->count_ == 0) {
			delete this->ptr_;
			delete this->count_;
		}
	}

	size_t use_count() const {
		return *this->count_;
	}

private:
	T *ptr_;
	size_t *count_;
};

#endif //ALGORITHM_PTR_H
