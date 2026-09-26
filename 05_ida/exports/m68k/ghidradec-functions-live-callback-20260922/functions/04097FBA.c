
void _pmap_collapse(int param_1,uint param_2,int param_3)

{
  uint uVar1;
  uint *puVar2;
  byte *pbVar3;
  uint uVar4;
  uint *puVar5;
  uint *puVar6;
  
  if ((param_1 != _kernel_pmap) && (_pmap_coll != 0)) {
    uVar4 = param_3 + ((_m68k_pte_mask & param_2) >> (_m68k_pte_shift & 0x3f)) * -4;
    uVar1 = uVar4 + _m68k_pte_entries * 4;
    for (; uVar4 < uVar1; uVar4 = uVar4 + 4) {
      if ((*(byte *)(uVar4 + 3) & 3) == 1) {
        return;
      }
    }
    puVar2 = (uint *)(*(int *)(param_1 + 8) +
                     ((_m68k_pt1_mask & param_2) >> (_m68k_pt1_shift & 0x3f)) * 4);
    puVar6 = (uint *)(((*puVar2 >> 9) << (_m68k_pt1_l2ptr & 0x3f)) +
                     ((_m68k_pt2_mask & param_2) >> (_m68k_pt2_shift & 0x3f)) * 4);
    sub_40970C6(_pte_zone,(*puVar6 >> 7) << (_m68k_pt2_l3ptr & 0x3f));
    *(byte *)((int)puVar6 + 3) = *(byte *)((int)puVar6 + 3) & 0xfc;
    puVar6 = puVar6 + -((_m68k_pt2_mask & param_2) >> (_m68k_pt2_shift & 0x3f));
    for (puVar5 = puVar6; puVar5 < puVar6 + _m68k_pt2_entries; puVar5 = puVar5 + 1) {
      if (_m68k_pt2_desctype == ((byte)*puVar5 & 3)) {
        return;
      }
    }
    sub_40970C6(_pt_zone,puVar6);
    pbVar3 = (byte *)((int)puVar2 + 3);
    *pbVar3 = *pbVar3 & 0xfc;
  }
  return;
}

