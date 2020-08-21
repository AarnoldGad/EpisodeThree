#ifndef RESOURCEHOLDER_HPP
#define RESOURCEHOLDER_HPP

#include <stdexcept>
#include <iostream>
#include <string>
#include <map>
#include <memory>

template<typename ResourceType>
class ResourceHolder
{
protected:

   ResourceHolder() = default;
   virtual ~ResourceHolder() = default;

   ResourceType& add(std::string const& identifier)
   {
      return *m_resources.try_emplace(identifier, std::make_unique<ResourceType>()).first->second;
   }

   ResourceType& get(std::string const& identifier) const
   {
      try
      {
         return *m_resources.at(identifier);
      }
      catch (std::out_of_range& e)
      {
         std::cout << "resource not found : " << identifier << std::endl;
         exit(-1);
      }
   }

   void remove(std::string const& identifier)
   {
      m_resources.erase(identifier);
   }

   void clear()
   {
      m_resources.clear();
   }

   std::map<std::string, std::unique_ptr<ResourceType> > m_resources;
};

#endif // RESOURCEHOLDER_HPP
