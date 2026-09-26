
int _srmmu_mmu_probe(uint param_1)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  
  uVar4 = param_1 & 0xfffff000;
  iVar1 = segment(3);
  iVar3 = 0;
  if (*(int *)((uVar4 | 0x400) + iVar1) != 0) {
    iVar1 = segment(3);
    uVar2 = *(uint *)((uVar4 | 0x200) + iVar1);
    if ((uVar2 & 3) == 2) {
      iVar3 = uVar2 + (param_1 >> 0xc & 0xfff) * 0x100;
    }
    else {
      iVar1 = segment(3);
      uVar2 = *(uint *)((uVar4 | 0x100) + iVar1);
      if ((uVar2 & 3) == 2) {
        iVar3 = uVar2 + (param_1 >> 0xc & 0x3f) * 0x100;
      }
      else {
        iVar1 = segment(3);
        iVar3 = *(int *)(uVar4 + iVar1);
      }
    }
  }
  return iVar3;
}

