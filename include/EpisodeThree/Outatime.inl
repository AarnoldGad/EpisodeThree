template<typename S, typename... Args>
void Outatime::run(Args&&... args)
{
   m_running = true;
   pushState<S>(std::forward<Args>(args)...);
   mainGameLoop();
}

template<typename S, typename... Args>
void Outatime::pushState(Args&&... args)
{
   m_states.emplace(new S(*this, std::forward<Args>(args)...));
}
