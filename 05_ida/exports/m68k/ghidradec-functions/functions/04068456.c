
void _evnewevents(void)

{
  if (dword_40B4F5E != 0) {
    _selwakeup(dword_40B4F5E,0);
    _thread_deallocate_interrupt(dword_40B4F5E);
    dword_40B4F5E = 0;
  }
  if (_eventPort != 0) {
    dword_40B4F62 = 1;
    _thread_wakeup_prim(&_eventMsg,0,0);
  }
  return;
}
