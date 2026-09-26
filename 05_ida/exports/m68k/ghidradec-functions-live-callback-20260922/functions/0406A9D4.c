
void sub_406A9D4(int param_1)

{
  int iVar1;
  
  iVar1 = 1;
  if (param_1 < 4) {
    iVar1 = param_1;
  }
  *(int *)(_evg + 0x1c) = iVar1;
  _evdispatch(3,_currentScreen,0);
  return;
}

