#pragma once
#include <map>
/*
	USAGE:
	Factory<BaseClass> MyFactory;
	MyFactory.Register<DerivedType>("DerivedType");
	DerivedType* MyDerivedType = static_cast<DerivedType*>(MyFactory.Create("DerivedType"));
*/
template <typename T>
class Factory
{
	template <typename ChildOfT>
	static T* createFunction()
	{
		return new ChildOfT();
	}
	typedef T* (*PCreateFunction)();
	std::map<int, PCreateFunction> _createFunctions;

public:
	template <typename ChildOfT>
	void registerChildrenTypes(int i)
	{
		static_assert(std::is_base_of<T, ChildOfT>::value, "Bullshit");
		_createFunctions[i] = &createFunction<ChildOfT>;
	}
	virtual T* create(int i)
	{
		typename map<int, PCreateFunction>::const_iterator it= _createFunctions.find(i);
		if (it != _createFunctions.end())
		{
			auto r = it->second();
			return r;
		}
	}
};



