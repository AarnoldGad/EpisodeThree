#include <EpisodeThree/State/FirstSceneState.hpp>

FirstSceneState::FirstSceneState(Outatime& game)
   : ElectrocardiogramState(game, 30), m_box("scene_1", 40, 10.f)
{
   m_box.setPosition({100, 100});
}

void FirstSceneState::update(sf::Time dt)
{
   ElectrocardiogramState::update(dt);
   m_box.update(dt);
}

void FirstSceneState::onEvent(const sf::Event& event)
{
   if (event.type == sf::Event::KeyPressed)
      m_box.skip();
}

void FirstSceneState::render(RenderMaster& master)
{
   ElectrocardiogramState::render(master);
   m_renderer.submit(m_box);
   master.submit(0, m_renderer);
}
