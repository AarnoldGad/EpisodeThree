#ifndef DIALOGBOX_HPP
#define DIALOGBOX_HPP

#include <SFML/Graphics.hpp>

// TODO Improvements probably
class DialogBox : public sf::Drawable, public sf::Transformable
{
public:

   explicit DialogBox(std::string const& dialogID = std::string(), size_t charSize = 24, float charsPerSecond = 0.f, sf::Time skipCooldown = sf::Time::Zero);

   void update(sf::Time dt);
   bool skip();
   bool lineFinished();
   bool dialogFinished();

   void setBackground(sf::Texture const& background);
   void setMargin(sf::Vector2f offset);
   void setCharSize(size_t size);

   void setDialogIdentifier(std::string const& identifier);
   inline std::string const& getDialogIdentifier() const { return m_dialogID; }

   void setCharsPerSecond(float charsPerSecond);
   inline float getCharsPerSecond() const { return m_charsPerSecond; }

   void setSkipCooldown(sf::Time cooldown);
   inline sf::Time getSkipCooldown() const { return m_skipCooldown; }

private:

   virtual void draw(sf::RenderTarget & target, sf::RenderStates states) const override;

   sf::Time m_charAccum;
   float m_charsPerSecond;
   size_t m_onChars;

   sf::Time m_accumTime;
   sf::Time m_skipCooldown;

   std::string m_dialogID;
   size_t m_currentLine;
   sf::Text m_text;
   sf::Sprite m_background;
};

#endif // DIALOGBOX_HPP
