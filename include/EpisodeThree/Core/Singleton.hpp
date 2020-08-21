#ifndef SINGLETON_HPP
#define SINGLETON_HPP

#include <memory>

template<typename T>
class Singleton
{
public:

   static T& Instance();
   static void Delete();

protected:

   Singleton() = default;
   Singleton(Singleton&) = delete;
   void operator=(Singleton&) = delete;
   virtual ~Singleton() = default;

private:

   static std::unique_ptr<T> s_instance;
};

#include "Singleton.inl"

#endif // SINGLETON_HPP
