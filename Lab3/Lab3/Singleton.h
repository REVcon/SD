#pragma once
#include "Shape.h"
#include <memory>

template<typename T>
class Singleton
{
public:
	static std::shared_ptr<T> GetInstance();
	static void destroy();
private:

	Singleton(Singleton const&){};
	Singleton& operator=(Singleton const&){};

protected:
	static std::shared_ptr<T> m_instance;

	Singleton(){ m_instance = static_cast <std::shared_ptr<T>> (this); };
	~Singleton(){  };
};

template<typename T>
typename std::shared_ptr<T> Singleton<T>::m_instance = 0;

template<typename T>
std::shared_ptr<T> Singleton<T>::GetInstance()
{
	if (!m_instance)
	{
		Singleton<T>::m_instance = std::make_shared<T>(T());
	}
	return m_instance;
}

template<typename T>
void Singleton<T>::destroy()
{
	Singleton<T>::m_instance = nullptr;
}