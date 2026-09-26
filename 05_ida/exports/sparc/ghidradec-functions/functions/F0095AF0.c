
void _srmmu_mmu_flushctx(undefined4 param_1,int param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  
  iVar1 = segment(4);
  iVar2 = segment(0x20);
  iVar3 = segment(4);
  uVar4 = *(undefined4 *)(iVar3 + 0x200);
  if ((*(uint *)(*(int *)(iVar1 + 0x100) * 0x10 + param_2 * 4 + iVar2) & 3) == 1) {
    iVar1 = segment(4);
    *(int *)(iVar1 + 0x200) = param_2;
  }
  iVar1 = segment(3);
  *(undefined4 *)(iVar1 + 0x300) = 0;
  iVar1 = segment(4);
  *(undefined4 *)(iVar1 + 0x200) = uVar4;
  return;
}
