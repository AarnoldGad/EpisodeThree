#include <EpisodeThree/Graphics/DialogBox.hpp>
#include <EpisodeThree/Game/DialogStore.hpp>
#include <EpisodeThree/Core/ResourcesManager.hpp>
#include <cmath>
#include <iostream>

DialogBox::DialogBox()
   : m_charsPerSecond{}, m_onChars{}, m_currentLine{}
{
   m_text.setFont(ResourcesManager::Instance().get<sf::Font>("font"));
}

DialogBox::DialogBox(const std::string& dialogID, size_t charSize, float charsPerSecond, sf::Time skipCooldown)
   : m_charsPerSecond(charsPerSecond), m_onChars{}, m_skipCooldown(skipCooldown), m_dialogID(dialogID), m_currentLine{}
{
   m_text.setFont(ResourcesManager::Instance().get<sf::Font>("font"));
   m_text.setCharacterSize(charSize);
}

void DialogBox::update(sf::Time dt)
{
   m_accumTime += dt;
   m_charAccum += dt;

   if (lineFinished())
      m_text.setString(DialogStore::getLine(m_dialogID, m_currentLine));
   else if (m_charAccum.asSeconds() >= (1.f / m_charsPerSecond))
   {
      // TODO Better version (not totally working)
//       const float charsMore = std::floor(m_charAccum.asSeconds() / (1.f / m_charsPerSecond));
//       m_onChars += charsMore;
//       m_charAccum -= sf::seconds((1.f / m_charsPerSecond) * charsMore);

      // Simple version for usability
      m_onChars++;
      m_charAccum = sf::Time::Zero;

      m_text.setString(DialogStore::getLine(m_dialogID, m_currentLine).substr(0, m_onChars));
   }

//    std::cout << DialogStore::getLine(m_dialogID, m_currentLine).substr(0, m_onChars) << std::endl;
}

bool DialogBox::skip()
{
   if (dialogFinished())
      return false;

   // Instant draw all chars
   if (!lineFinished())
      m_onChars = DialogStore::getLine(m_dialogID, m_currentLine).size() - 1;
   // Skip line
   else if (m_accumTime >= m_skipCooldown)
   {
      m_currentLine++;
      m_onChars = 0;
      m_accumTime = sf::Time::Zero;
   }

   return false;
}

bool DialogBox::lineFinished()
{
   return !(m_onChars < DialogStore::getLine(m_dialogID, m_currentLine).size());
}

bool DialogBox::dialogFinished()
{
   return m_currentLine == (DialogStore::getLineCount(m_dialogID) - 1);
}

void DialogBox::setBackground(const sf::Texture& background)
{
   m_background.setTexture(background);
}

void DialogBox::setMargin(sf::Vector2f offset)
{
   m_text.setPosition(offset);
}

void DialogBox::setCharSize(size_t size)
{
   m_text.setCharacterSize(size);
}


void DialogBox::setDialogIdentifier(const std::string& identifier)
{
   m_dialogID = identifier;
   m_currentLine = 0;
   m_onChars = 0;
   m_accumTime = sf::Time::Zero;
}

void DialogBox::setCharsPerSecond(float charsPerSecond)
{
   m_charsPerSecond = charsPerSecond;
}

void DialogBox::setSkipCooldown(sf::Time cooldown)
{
   m_skipCooldown = cooldown;
}

void DialogBox::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
   states.transform *= getTransform();

   target.draw(m_background, states);
   target.draw(m_text, states);
}






