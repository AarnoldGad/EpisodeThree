template<typename T>
std::unique_ptr<T> Singleton<T>::s_instance = nullptr;

template<typename T>
T& Singleton<T>::Instance()
{
   if (!s_instance)
      s_instance.reset(new T);

   return *s_instance;
}

template<typename T>
void Singleton<T>::Delete()
{
   s_instance.reset();
}
