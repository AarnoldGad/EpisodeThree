#include <EpisodeThree/State/ElectrocardiogramState.hpp>
#include <EpisodeThree/Core/ResourcesManager.hpp>

ElectrocardiogramState::ElectrocardiogramState(Outatime& game, float hbpm)
   : State(game), m_hbpm(hbpm)
{
   sf::Texture& ecFlat = ResourcesManager::Instance().loadFromFile<sf::Texture>("ecFlat", "assets/sprites/ec_flat.png", sf::IntRect());
   sf::Texture& ecStress = ResourcesManager::Instance().loadFromFile<sf::Texture>("ecStress", "assets/sprites/ec_stress.png", sf::IntRect());

   m_ecFlat.setTexture(ecFlat);
   m_ecFlat.setPosition({0, 0});

   m_ecStress.setTexture(ecStress);
   m_ecStress.setPosition({0, 0});
}

void ElectrocardiogramState::update(sf::Time dt)
{
   m_accumTime += dt;

   if (m_accumTime.asSeconds() >= (60.f / m_hbpm))
   {
      m_accumTime = sf::Time::Zero;
   }

   sf::Color color = m_ecStress.getColor();
   float alphaFactor = 255.f * (1.f - (m_accumTime.asSeconds() / (60.f / m_hbpm)));
   m_ecStress.setColor({color.r, color.g, color.b, static_cast<sf::Uint8>(alphaFactor)});
}

void ElectrocardiogramState::render(RenderMaster& master)
{
   m_renderer.submit(m_ecStress);
   m_renderer.submit(m_ecFlat);
   master.submit(0, m_renderer);
}

void ElectrocardiogramState::setHeartBeatPerMinute(float hbpm)
{
   m_hbpm = hbpm;
}
