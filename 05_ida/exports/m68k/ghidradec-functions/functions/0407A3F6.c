
void _od_zero_fill(int param_1,int param_2,int param_3)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  uint uVar5;
  word wVar6;
  sword sVar7;
  
  iVar1 = *(int *)(param_2 + 0xae);
  uVar5 = *(uint *)(param_1 + 0x214);
  *(int *)(param_1 + 0x244) = param_3;
  param_3 = param_3 + -1;
  if (param_3 != -1) {
    do {
      for (iVar2 = *(int *)(iVar1 + 0x5c); iVar2 != 0; iVar2 = iVar2 - iVar4) {
        uVar3 = _pmap_resident_extract(*(undefined4 *)(param_1 + 0x218),uVar5);
        iVar4 = _m68k_page_size - (_m68k_page_mask & uVar5);
        if (iVar2 < iVar4) {
          iVar4 = iVar2;
        }
        _bzero(uVar3,iVar4);
        uVar5 = iVar4 + uVar5;
      }
      wVar6 = (word)((uint)param_3 >> 0x10);
      sVar7 = (sword)param_3 + -1;
      param_3 = CONCAT22(wVar6,sVar7);
    } while ((sVar7 != -1) || (param_3 = (uint)wVar6 * 0x10000 + -1, wVar6 != 0));
  }
  return;
}
