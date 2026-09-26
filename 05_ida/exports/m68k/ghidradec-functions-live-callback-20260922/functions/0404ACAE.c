
void _lock_done(int param_1)

{
  byte bVar1;
  
  if (*(sword *)(param_1 + 4) == 0) {
    if ((*(word *)(param_1 + 6) & 0xfff) == 0) {
      bVar1 = *(byte *)(param_1 + 6);
      if ((char)bVar1 < '\0') {
        bVar1 = bVar1 & 0x7f;
      }
      else {
        bVar1 = bVar1 & 0xbf;
      }
      *(byte *)(param_1 + 6) = bVar1;
    }
    else {
      *(uint *)(param_1 + 6) =
           *(uint *)(param_1 + 6) & 0xf000ffff |
           ((word)(*(word *)(param_1 + 6) + 0xfff) & 0xfff) << 0x10;
    }
  }
  else {
    *(sword *)(param_1 + 4) = *(sword *)(param_1 + 4) + -1;
  }
  if ((*(uint *)(param_1 + 4) & 0xffff2000) == 0x2000) {
    *(byte *)(param_1 + 6) = *(byte *)(param_1 + 6) & 0xdf;
    _thread_wakeup_prim(param_1,0,0);
  }
  return;
}

