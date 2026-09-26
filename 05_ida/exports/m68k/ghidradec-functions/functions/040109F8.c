
void _ptsstop(int param_1,uint param_2)

{
  uint *puVar1;
  uint uVar2;
  
  puVar1 = *(uint **)((int)&dword_40B318E + (sword)(*(word *)(param_1 + 0x38) & 0xff) * 0xe);
  if (*(word *)(param_1 + 0x38) != 0) {
    if (param_2 == 0) {
      param_2 = 4;
      *puVar1 = *puVar1 | 0x10;
    }
    else {
      *puVar1 = *puVar1 & 0xffffffef;
    }
    *(byte *)(puVar1 + 3) = (byte)param_2 | *(byte *)(puVar1 + 3);
    uVar2 = 0;
    if ((param_2 & 1) != 0) {
      uVar2 = 2;
    }
    if ((param_2 & 2) != 0) {
      uVar2 = uVar2 | 1;
    }
    _ptcwakeup(param_1,uVar2);
  }
  return;
}

