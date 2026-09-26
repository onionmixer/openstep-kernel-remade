
void _pmap_expand(int param_1,uint param_2,int param_3)

{
  uint uVar1;
  uint uVar2;
  uint *puVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  int unaff_A2;
  
  uVar4 = _m68k_pt1_mask & param_2;
  uVar1 = _m68k_pt1_shift & 0x3f;
  uVar5 = _m68k_pt2_mask & param_2;
  uVar2 = _m68k_pt2_shift & 0x3f;
  if (param_3 == -4) {
    unaff_A2 = sub_4096FD0(_pt_zone);
  }
  iVar6 = sub_4096FD0(_pte_zone);
  iVar7 = _pmap_pte(param_1,param_2);
  if (iVar7 < 1) {
    puVar3 = (uint *)(*(int *)(param_1 + 8) + (uVar4 >> uVar1) * 4);
    if (param_3 == -4) {
      *puVar3 = (unaff_A2 >> (_m68k_pt1_l2ptr & 0x3f)) << 9 | *puVar3 & 0x1ff;
      *(byte *)((int)puVar3 + 3) = (byte)*puVar3 & 0xfb | 8;
      *(byte *)((int)puVar3 + 3) = (byte)*puVar3 & 0xf8 | 8 | (byte)_m68k_pt1_desctype & 3;
    }
    else {
      unaff_A2 = (*puVar3 >> 9) << (_m68k_pt1_l2ptr & 0x3f);
    }
    puVar3 = (uint *)(unaff_A2 + (uVar5 >> uVar2) * 4);
    *puVar3 = (iVar6 >> (_m68k_pt2_l3ptr & 0x3f)) << 7 | *puVar3 & 0x7f;
    *(byte *)((int)puVar3 + 3) = (byte)*puVar3 & 0xfb | 8;
    *(byte *)((int)puVar3 + 3) = bRam040c97cf & 3 | (byte)*puVar3 & 0xf8 | 8;
  }
  else {
    if (param_3 == -4) {
      sub_40970C6(_pt_zone,unaff_A2);
    }
    sub_40970C6(_pte_zone,iVar6);
  }
  return;
}

