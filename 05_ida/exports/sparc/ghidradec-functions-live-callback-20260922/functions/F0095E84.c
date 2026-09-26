
void _swift_vac_ctxflush(undefined4 param_1,undefined4 param_2,int param_3)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  
  iVar4 = segment(4);
  iVar3 = segment(0x20);
  iVar1 = segment(4);
  uVar2 = *(undefined4 *)(iVar1 + 0x200);
  if ((*(uint *)(*(int *)(iVar4 + 0x100) * 0x10 + param_3 * 4 + iVar3) & 3) == 1) {
    iVar4 = segment(4);
    *(int *)(iVar4 + 0x200) = param_3;
  }
  iVar4 = 0x800;
  iVar3 = 0;
  do {
    iVar4 = iVar4 + -0x20;
    iVar1 = segment(0x13);
    *(undefined4 *)(iVar3 + iVar1) = 0;
    iVar1 = segment(0x13);
    *(undefined4 *)(iVar3 + 0x800 + iVar1) = 0;
    iVar1 = segment(0x13);
    *(undefined4 *)(iVar3 + 0x1000 + iVar1) = 0;
    iVar1 = segment(0x13);
    *(undefined4 *)(iVar3 + 0x1800 + iVar1) = 0;
    iVar1 = segment(0x13);
    *(undefined4 *)(iVar3 + 0x2010 + iVar1) = 0;
    iVar1 = segment(0x13);
    *(undefined4 *)(iVar3 + 0x2810 + iVar1) = 0;
    iVar1 = segment(0x13);
    *(undefined4 *)(iVar3 + 0x3010 + iVar1) = 0;
    iVar1 = segment(0x13);
    *(undefined4 *)(iVar3 + 0x3810 + iVar1) = 0;
    iVar3 = iVar3 + 0x20;
  } while (iVar4 != 0);
  iVar4 = segment(4);
  *(undefined4 *)(iVar4 + 0x200) = uVar2;
  return;
}

