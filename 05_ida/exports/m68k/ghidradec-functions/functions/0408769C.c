
undefined4 _snd_stream_await(int param_1,int param_2)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 0xc);
  if (iVar1 != param_1 + 0xc) {
    do {
      if (((*(byte *)(iVar1 + 0x2d) & 8) == 0) &&
         ((param_2 == 0 || (param_2 == *(int *)(iVar1 + 0x2e))))) break;
      iVar1 = *(int *)(iVar1 + 0x32);
    } while (iVar1 != param_1 + 0xc);
    if (iVar1 != param_1 + 0xc) {
      *(byte *)(iVar1 + 0x2c) = *(byte *)(iVar1 + 0x2c) | 2;
      *(byte *)(param_1 + 0x24) = *(byte *)(param_1 + 0x24) | 2;
      _thread_wakeup_prim(param_1,0,0);
      return 0;
    }
  }
  return 0x6c;
}
