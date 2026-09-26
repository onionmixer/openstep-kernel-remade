
void _swift_vac_pagectxflush(int param_1,undefined4 param_2,int param_3)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  
  iVar4 = segment(4);
  iVar1 = segment(0x20);
  iVar2 = segment(4);
  uVar3 = *(undefined4 *)(iVar2 + 0x200);
  if ((*(uint *)(*(int *)(iVar4 + 0x100) * 0x10 + param_3 * 4 + iVar1) & 3) == 1) {
    iVar4 = segment(4);
    *(int *)(iVar4 + 0x200) = param_3;
  }
  iVar4 = 0x200;
  do {
    iVar4 = iVar4 + -0x10;
    iVar1 = segment(0x10);
    *(undefined4 *)(param_1 + iVar1) = 0;
    iVar1 = segment(0x10);
    *(undefined4 *)(param_1 + 0x200 + iVar1) = 0;
    iVar1 = segment(0x10);
    *(undefined4 *)(param_1 + 0x400 + iVar1) = 0;
    iVar1 = segment(0x10);
    *(undefined4 *)(param_1 + 0x600 + iVar1) = 0;
    iVar1 = segment(0x10);
    *(undefined4 *)(param_1 + 0x800 + iVar1) = 0;
    iVar1 = segment(0x10);
    *(undefined4 *)(param_1 + 0xa00 + iVar1) = 0;
    iVar1 = segment(0x10);
    *(undefined4 *)(param_1 + 0xc00 + iVar1) = 0;
    iVar1 = segment(0x10);
    *(undefined4 *)(param_1 + 0xe00 + iVar1) = 0;
    param_1 = param_1 + 0x10;
  } while (iVar4 != 0);
  iVar4 = segment(4);
  *(undefined4 *)(iVar4 + 0x200) = uVar3;
  return;
}

