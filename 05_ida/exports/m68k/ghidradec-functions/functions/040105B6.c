
void _ptcwakeup(int param_1,uint param_2)

{
  uint *puVar1;
  
  puVar1 = *(uint **)((int)&dword_40B318E + (sword)(*(word *)(param_1 + 0x38) & 0xff) * 0xe);
  if (*(word *)(param_1 + 0x38) != 0) {
    if ((param_2 & 1) != 0) {
      if (puVar1[1] != 0) {
        _selwakeup(puVar1[1],*puVar1 & 1);
        _selthreadclear(puVar1 + 1);
        *puVar1 = *puVar1 & 0xfffffffe;
      }
      _wakeup(param_1 + 0x1c);
    }
    if ((param_2 & 2) != 0) {
      if (puVar1[2] != 0) {
        _selwakeup(puVar1[2],*puVar1 & 2);
        _selthreadclear(puVar1 + 2);
        *puVar1 = *puVar1 & 0xfffffffd;
      }
      _wakeup(param_1 + 4);
    }
  }
  return;
}
