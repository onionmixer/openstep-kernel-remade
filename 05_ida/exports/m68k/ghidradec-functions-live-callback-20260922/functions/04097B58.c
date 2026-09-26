
void _pmap_free_maps(undefined4 param_1,uint *param_2)

{
  uint *puVar1;
  int iVar2;
  uint *puVar3;
  uint *puVar4;
  
  iVar2 = 0;
  puVar4 = param_2;
  if (0 < _m68k_pt1_entries) {
    do {
      if (((byte)*puVar4 & 3) == _m68k_pt1_desctype) {
        puVar1 = (uint *)((*puVar4 >> 9) << (_m68k_pt1_l2ptr & 0x3f));
        puVar3 = puVar1;
        if (puVar1 < puVar1 + _m68k_pt2_entries) {
          do {
            if (((byte)*puVar3 & 3) == _m68k_pt2_desctype) {
              sub_40970C6(_pte_zone,(*puVar3 >> 7) << (_m68k_pt2_l3ptr & 0x3f));
            }
            puVar3 = puVar3 + 1;
          } while (puVar3 < puVar1 + _m68k_pt2_entries);
        }
        sub_40970C6(_pt_zone,puVar1);
      }
      iVar2 = iVar2 + 1;
      puVar4 = puVar4 + 1;
    } while (iVar2 < _m68k_pt1_entries);
  }
  sub_40970C6(_pt_zone,param_2);
  return;
}

