#ifndef DIALOGSTORE_HPP
#define DIALOGSTORE_HPP

#include <string>
#include <vector>
#include <map>

// TODO Extremely experimental, I have no idea what i'm doing
// First : It should be using extern files to load dialogs and identifiers and informations like text speed etc... -> XML
class DialogStore
{
public:

   DialogStore() = delete;
   DialogStore(DialogStore const&) = delete;
   DialogStore& operator=(DialogStore const&) = delete;

   static std::string const& getLine(std::string const& identifier, size_t index);
   static size_t getLineCount(std::string const& identifier);

private:

   static std::vector<std::string> const& getDialog(std::string const& identifier);

   static std::map<std::string, std::vector<std::string> > const s_dialogs;
};

#endif // DIALOGSTORE_HPP
