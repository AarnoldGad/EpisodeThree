#ifndef FIRSTSCENESTATE_HPP
#define FIRSTSCENESTATE_HPP

#include <EpisodeThree/State/ElectrocardiogramState.hpp>
#include <EpisodeThree/Graphics/DialogBox.hpp>

class FirstSceneState : public ElectrocardiogramState
{
public:

   explicit FirstSceneState(Outatime& game);

   void update(sf::Time dt) override;
   void onEvent(const sf::Event & event) override;
   void render(RenderMaster & master) override;

private:

   DialogBox m_box;
   Renderer m_renderer;
};

#endif // FIRSTSCENESTATE_HPP
