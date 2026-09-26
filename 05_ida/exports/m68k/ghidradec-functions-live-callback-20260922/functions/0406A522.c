
undefined4 _ev_unregister_screen(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  if (((_evg == 0) || (param_1 = param_1 + -0x100, param_1 < 0)) || (_screens <= param_1)) {
    uVar2 = 0xffffffff;
  }
  else {
    _evdispatch(1,_currentScreen,0);
    iVar1 = _evScreen;
    param_1 = param_1 * 0x28;
    *(undefined4 *)(_evScreen + 0x1c + param_1) = 0;
    *(undefined4 *)(iVar1 + 0x18 + param_1) = 0;
    *(undefined4 *)(iVar1 + 0x20 + param_1) = 0;
    *(undefined4 *)(iVar1 + 0x24 + param_1) = 0;
    _evdispatch(2,_currentScreen,0);
    uVar2 = 0;
  }
  return uVar2;
}

