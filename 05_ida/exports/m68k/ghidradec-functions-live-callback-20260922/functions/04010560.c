
void _ptsstart(int param_1)

{
  uint *puVar1;
  
  puVar1 = *(uint **)((int)&dword_40B318E + (sword)(*(word *)(param_1 + 0x38) & 0xff) * 0xe);
  if ((*(word *)(param_1 + 0x38) != 0) && ((*(byte *)(param_1 + 0x40) & 1) == 0)) {
    if ((*puVar1 & 0x10) != 0) {
      *puVar1 = *puVar1 & 0xffffffef;
      *(undefined *)(puVar1 + 3) = 8;
    }
    _ptcwakeup(param_1,1);
  }
  return;
}

