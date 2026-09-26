
int _pmap_is_modified(undefined4 param_1)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  int *piVar5;
  
  iVar4 = 0;
  iVar2 = _pmap_phys_to_index(param_1);
  if (iVar2 != -1) {
    piVar5 = (int *)(_pv_head_table + iVar2 * 0xc);
    while (piVar5[1] != 0) {
      uVar3 = _pmap_pte_valid(piVar5[1],piVar5[2]);
      uVar1 = uVar3 + _m68k_ptes_per_page * 4;
      for (; (iVar4 == 0 && (uVar3 < uVar1)); uVar3 = uVar3 + 4) {
        if ((*(byte *)(uVar3 + 3) & 0x10) != 0) {
          iVar4 = 1;
        }
      }
      piVar5 = (int *)*piVar5;
      if (piVar5 == (int *)0x0) {
        return iVar4;
      }
      if (iVar4 != 0) {
        return iVar4;
      }
    }
  }
  return iVar4;
}

