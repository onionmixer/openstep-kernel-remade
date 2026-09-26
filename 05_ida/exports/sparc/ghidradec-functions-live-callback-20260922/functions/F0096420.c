
void _vik_mmu_flushctx(undefined4 param_1,int param_2)

{
  int iVar1;
  uint *puVar2;
  undefined4 uVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  
  iVar1 = segment(4);
  iVar5 = *(int *)(iVar1 + 0x100);
  puVar2 = (uint *)segment(4);
  uVar4 = *puVar2;
  puVar2 = (uint *)segment(4);
  *puVar2 = uVar4 | 0x8000;
  iVar1 = segment(0x20);
  uVar6 = *(uint *)(iVar5 * 0x10 + param_2 * 4 + iVar1);
  puVar2 = (uint *)segment(4);
  *puVar2 = uVar4;
  iVar1 = segment(4);
  uVar3 = *(undefined4 *)(iVar1 + 0x200);
  if ((uVar6 & 3) == 1) {
    iVar1 = segment(4);
    *(int *)(iVar1 + 0x200) = param_2;
  }
  iVar1 = segment(3);
  *(undefined4 *)(iVar1 + 0x300) = 0;
  iVar1 = segment(4);
  *(undefined4 *)(iVar1 + 0x200) = uVar3;
  return;
}

