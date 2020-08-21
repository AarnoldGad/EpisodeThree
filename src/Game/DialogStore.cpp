#include <EpisodeThree/Game/DialogStore.hpp>
#include <iostream>
#include <stdexcept>

// TODO Should be loaded using extern files
std::map<std::string, std::vector<std::string> > const DialogStore::s_dialogs
{
   {
      "scene_1",
      {
         "test test test1",
         "test test test2",
      }
   }
};

std::string const& DialogStore::getLine(const std::string& dialogID, size_t index)
{
   try
   {
      return getDialog(dialogID).at(index);
   }
   catch (std::out_of_range& e)
   {
      std::cout << "no dialog for id " << dialogID << ":" << index << std::endl;
      exit(-1);
   }
}


size_t DialogStore::getLineCount(std::string const& dialogID)
{
   return getDialog(dialogID).size();
}

std::vector<std::string> const& DialogStore::getDialog(const std::string& identifier)
{
   try
   {
      return s_dialogs.at(identifier);
   }
   catch (std::out_of_range& e)
   {
      std::cout << "no dialog for id " << identifier << std::endl;
      exit(-1);
   }
}

