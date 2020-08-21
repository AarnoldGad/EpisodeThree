#ifndef RESOURCESMANAGER_HPP
#define RESOURCESMANAGER_HPP

#include <memory>
#include <functional>
#include <SFML/Graphics.hpp>
#include <EpisodeThree/Core/Singleton.hpp>
#include <EpisodeThree/Outatime.hpp>
#include <EpisodeThree/Core/ResourceHolder.hpp>

// TODO Want ability to add/remove holders at runtime dynamicly in a ideal world
class ResourcesManager : public Singleton<ResourcesManager>,
                         public ResourceHolder<sf::Shader>,
                         public ResourceHolder<sf::Texture>,
                         public ResourceHolder<sf::Font>
{
   friend class Singleton<ResourcesManager>;
   friend class Outatime;

public:

   // TODO Working pretty well but have to fulfil every arguments even defaulted ones
   template<typename Resource, typename Func, typename... Args>
   Resource& load(std::string const& identifier, Func loadFunc, Args&&... args)
   {
      Resource& resource = ResourceHolder<Resource>::add(identifier);

      if (!std::invoke(loadFunc, resource, std::forward<Args>(args)...))
      {
         std::cout << "resource loading error : " << identifier << std::endl;
         exit(-1);
      }

      return resource;
   }

   // Because we will mostly want to load from file
   // TODO Improve template deduction (of overloaded methods)
   template<typename Resource, typename... Args>
   Resource& loadFromFile(std::string const& identifier, Args&&... args)
   {
      return load<Resource>(identifier, &Resource::loadFromFile, std::forward<Args>(args)...);
   }

   template<typename Resource>
   bool isLoaded(std::string const& identifier) const
   {
      try
      {
         return ResourceHolder<Resource>::m_resources.at(identifier);
      }
      catch (std::out_of_range& e)
      {
         return false;
      }
   }

   template<typename Resource>
   Resource& get(std::string const& identifier) const
   {
      return ResourceHolder<Resource>::get(identifier);
   }

   template<typename Resource>
   void remove(std::string const& identifier)
   {
      ResourceHolder<Resource>::remove(identifier);
   }

   template<typename Resource>
   void clear()
   {
      ResourceHolder<Resource>::clear();
   }

private:

   void update(sf::Time dt)
   {

   };

   ResourcesManager() = default;
};


#endif // RESOURCESMANAGER_HPP
