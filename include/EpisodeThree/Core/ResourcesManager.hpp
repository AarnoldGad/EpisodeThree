#ifndef RESOURCESMANAGER_HPP
#define RESOURCESMANAGER_HPP

#include <memory>
#include <functional>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <EpisodeThree/Core/Singleton.hpp>
#include <EpisodeThree/Outatime.hpp>
#include <EpisodeThree/Core/ResourceHolder.hpp>

// TODO Want ability to add/remove holders at runtime dynamicly in an ideal world
class ResourcesManager : public Singleton<ResourcesManager>,
                         public ResourceHolder<sf::Shader>,
                         public ResourceHolder<sf::Texture>,
                         public ResourceHolder<sf::Font>,
                         public ResourceHolder<sf::SoundBuffer>
{
   friend class Singleton<ResourcesManager>;
   friend class Outatime;

public:

   // TODO Working pretty well but have to fulfil every arguments even defaulted ones
   template<typename ResourceType, typename Func, typename... Args>
   ResourceType& load(std::string const& identifier, Func loadFunc, Args&&... args)
   {
      ResourceType& resource = ResourceHolder<ResourceType>::add(identifier);

      if (!std::invoke(loadFunc, resource, std::forward<Args>(args)...))
      {
         std::cout << "resource loading error : " << identifier << std::endl;
         exit(-1);
      }

      return resource;
   }

   // Because we will mostly want to load from file
   // TODO Improve template deduction (of overloaded "loadFrom..." methods)
   template<typename ResourceType, typename... Args>
   ResourceType& loadFromFile(std::string const& identifier, Args&&... args)
   {
      return load<ResourceType>(identifier, &ResourceType::loadFromFile, std::forward<Args>(args)...);
   }

   template<typename ResourceType>
   bool isLoaded(std::string const& identifier) const
   {
      try
      {
         return ResourceHolder<ResourceType>::m_resources.at(identifier);
      }
      catch (std::out_of_range& e)
      {
         return false;
      }
   }

   template<typename ResourceType>
   ResourceType& get(std::string const& identifier) const
   {
      return ResourceHolder<ResourceType>::get(identifier);
   }

   template<typename ResourceType>
   void remove(std::string const& identifier)
   {
      ResourceHolder<ResourceType>::remove(identifier);
   }

   template<typename ResourceType>
   void clear()
   {
      ResourceHolder<ResourceType>::clear();
   }

private:

   void update(sf::Time dt)
   {
      // TODO Animated resources
   };

   ResourcesManager() = default;
};


#endif // RESOURCESMANAGER_HPP
