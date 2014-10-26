#pragma once

#include <memory>

template <typename T>
struct OpNewCreator
{
	static T* Create()
	{
		return new T;
	}
	static void Destroy(T* pObj)
	{
		delete pObj;
	}
};

template <typename T>
struct MallocCreator
{
	static T* Create()
	{
		void* buf = std::malloc(sizeof(T));
		if (nullptr == buf)
			return nullptr;
		return new(buf) T;
	}
	static void Destroy(T* pObj)
	{
		pObj->~T();
		std::free(pObj);
	}
};

template <typename T>
struct PrototypeCreator
{
	PrototypeCreator(T* pObj = nullptr) : pPrototype_(pObj) {}
	T* Create()
	{
		return pPrototype_ ? pPrototype_->Clone() : nullptr;
	}
	static void Destroy(T* pObj)
	{
		pObj->Destroy();
	}
	void GetPrototype() {return pPrototype_;}
	void SetPrototype(T* pObj) {pPrototype_ = pObj;}
private:
	T* pPrototype_;
};

