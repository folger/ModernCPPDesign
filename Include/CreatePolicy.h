#pragma once

#include <cstdlib>
#include <cstdio>

template <typename T>
struct OpNewCreator
{
	static T* Create()
	{
		printf("OpNewCreator::Create()\n");
		return new T;
	}
	static void Destroy(T* pObj)
	{
		printf("OpNewCreator::Destroy()\n");
		delete pObj;
	}
protected:
	~OpNewCreator()
	{
		printf("OpNewCreator::~OpNewCreator()\n");
	}
};

template <typename T>
struct MallocCreator
{
	static T* Create()
	{
		printf("MallocCreator::Create()\n");
		void* buf = malloc(sizeof(T));
		if (nullptr == buf)
			return nullptr;
		return new(buf) T;
	}
	static void Destroy(T* pObj)
	{
		printf("MallocCreator::Destroy()\n");
		pObj->~T();
		free(pObj);
	}
protected:
	~MallocCreator()
	{
		printf("MallocCreator::~MallocCreator()\n");
	}
};

template <typename T>
struct PrototypeCreator
{
	PrototypeCreator(T* pObj = nullptr) : pPrototype_(pObj) {}
	T* Create()
	{
		printf("PrototypeCreator::Create()\n");
		return pPrototype_ ? pPrototype_->Clone() : nullptr;
	}
	static void Destroy(T* pObj)
	{
		printf("PrototypeCreator::Destroy\n");
		pObj->Destroy();
	}
	void GetPrototype() {return pPrototype_;}
	void SetPrototype(T* pObj) {pPrototype_ = pObj;}
private:
	T* pPrototype_;
protected:
	~PrototypeCreator()
	{
		printf("PrototypeCreator::~PrototypeCreator()\n");
	}
};

