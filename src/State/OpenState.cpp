#include <EpisodeThree/State/OpenState.hpp>
#include <EpisodeThree/State/FirstSceneState.hpp>
#include <EpisodeThree/Outatime.hpp>
#include <EpisodeThree/Core/ResourcesManager.hpp>

OpenState::OpenState(Outatime& game)
 : State(game), m_fadeOutFlag(false)
{
   sf::Vector2f windowSize = static_cast<sf::Vector2f>(game.getWindow().getSize());

   sf::Texture& sfmlTexture = ResourcesManager::Instance().get<sf::Texture>("sfml");
   sf::Texture& box2DTexture = ResourcesManager::Instance().get<sf::Texture>("box2D");
   sf::Font& font = ResourcesManager::Instance().get<sf::Font>("font");

   m_sfmlLogo.setTexture(sfmlTexture);
   m_box2DLogo.setTexture(box2DTexture);
   m_studioName.setFont(font);

   m_sfmlLogo.setOrigin(static_cast<float>(sfmlTexture.getSize().x) / 2.f, 0);
   m_sfmlLogo.setPosition(windowSize.x / 4, windowSize.y / 2 + (static_cast<float>(box2DTexture.getSize().y - sfmlTexture.getSize().y)));

   m_box2DLogo.setOrigin(static_cast<float>(box2DTexture.getSize().x) / 2.f, 0);
   m_box2DLogo.setPosition(windowSize.x / 4 * 3, windowSize.y / 2);

   m_studioName.setCharacterSize(50);
   m_studioName.setString("Zucchini  Studio\n    Presents");
   m_studioName.setOrigin(m_studioName.getLocalBounds().width / 2, m_studioName.getLocalBounds().height / 2);
   m_studioName.setPosition(windowSize.x / 2, windowSize.y / 3);

   m_renderer.triggerFade(Transition::FADE_IN, sf::seconds(2));
}

void OpenState::update(sf::Time dt)
{
   m_renderer.update(dt);
   m_accumElapsed += dt;

   // After fade in and at least 4 seconds
   if (m_accumElapsed.asSeconds() >= 4.f && !m_fadeOutFlag)
   {
      m_fadeOutFlag = true;
      m_renderer.triggerFade(Transition::FADE_OUT, sf::seconds(2));
   }

   // Just after fade out
   if (m_fadeOutFlag && m_renderer.getFade().isDone())
//       m_game.stop();
   {
      m_game.pushState<FirstSceneState>();
      m_game.popState();
   }
}

void OpenState::onEvent(const sf::Event& event)
{

}

void OpenState::render(RenderMaster& master)
{
   m_renderer.submit(m_sfmlLogo);
   m_renderer.submit(m_box2DLogo);
   m_renderer.submit(m_studioName);
   master.submit(0, m_renderer);
}

