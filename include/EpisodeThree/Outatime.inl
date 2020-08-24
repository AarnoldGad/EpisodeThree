template<typename StateType, typename... Args>
void Outatime::run(Args&&... args)
{
   m_running = true;
   pushState<StateType>(std::forward<Args>(args)...);
   mainGameLoop();

   m_states.clear();
}

template<typename StateType, typename... Args>
void Outatime::pushState(Args&&... args)
{
   m_states.emplace_back(new StateType(*this, std::forward<Args>(args)...));
}

template<typename StateType, typename... Args>
void Outatime::setState(Args&&... args)
{
   pushState<StateType>(std::forward<Args>(args)...);
   popState();
}
