
void _TermMouse(void)

{
  if (_screens != 0) {
    _evdispatch(1,_currentScreen,0);
  }
  return;
}
