#pragma once
#include <exception>

template <class T,
		 template <class> class CheckingPolicy,
		 template <class> class ThreadingModel>
class SmartPtr : public CheckingPolicy<T>, public ThreadingModel<T>
{
public:
	SmartPtr(T* pointee = nullptr) : pointee_(pointee)
	{
	}
	T* operator->()
	{
		typename ThreadingModel<T>::Lock guard(*pointee_);
		CheckingPolicy<T>::Check(pointee_);
		return pointee_;
	}
private:
	T* pointee_;
};

template <class T>
struct NoChecking
{
	static void Check(T*) {}
};

template <class T>
struct EnsureNotNull
{
	class NullPointerException : public std::exception
	{
	};
	static void Check(T* pObj)
	{
		if (nullptr == pObj)
			throw NullPointerException();
	}
};

template <class T>
struct SingleThread
{
	struct Lock
	{
		Lock(T&) {}
	};
};

