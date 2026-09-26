
undefined4 _evclose(void)

{
  undefined4 uVar1;
  
  if (_evOpenCalled == 0) {
    uVar1 = 6;
  }
  else {
    _evOpenCalled = 0;
    _eventsOpen = 0;
    if (_autoDimmed != 0) {
      _UndoAutoDim();
    }
    if (dword_40B4F5E != 0) {
      _thread_deallocate(dword_40B4F5E);
    }
    dword_40B4F5E = 0;
    _TermMouse();
    if (dword_40B4F6A != 0) {
      _kmem_free(_kernel_map,dword_40B4F6A,~_page_mask & _page_mask + dword_40B4F66);
    }
    if (_evScreen != 0) {
      _kfree(_evScreen,_evScreenSize);
    }
    _screens = 0;
    _evScreen = 0;
    _evScreenSize = 0;
    _evg = 0;
    dword_40B4F6A = 0;
    _eventTask = 0;
    if (_eventPort != 0) {
      _port_release(_eventPort);
      _eventPort = 0;
    }
    uVar1 = 0;
  }
  return uVar1;
}
