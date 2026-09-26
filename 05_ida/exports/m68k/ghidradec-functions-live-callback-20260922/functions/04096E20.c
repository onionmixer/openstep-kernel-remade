
int _pmap_pte(int param_1,uint param_2)

{
  uint *puVar1;
  int iVar2;
  
  puVar1 = (uint *)(*(int *)(param_1 + 8) +
                   ((_m68k_pt1_mask & param_2) >> (_m68k_pt1_shift & 0x3f)) * 4);
  if (((byte)*puVar1 & 3) == _m68k_pt1_desctype) {
    puVar1 = (uint *)(((*puVar1 >> 9) << (_m68k_pt1_l2ptr & 0x3f)) +
                     ((_m68k_pt2_mask & param_2) >> (_m68k_pt2_shift & 0x3f)) * 4);
    if (((byte)*puVar1 & 3) == _m68k_pt2_desctype) {
      iVar2 = ((*puVar1 >> 7) << (_m68k_pt2_l3ptr & 0x3f)) +
              ((_m68k_pte_mask & param_2) >> (_m68k_pte_shift & 0x3f)) * 4;
    }
    else {
      iVar2 = -3;
    }
  }
  else {
    iVar2 = -4;
  }
  return iVar2;
}

