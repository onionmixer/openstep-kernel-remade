
byte _pmap_clear_reference(undefined4 param_1)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  byte *pbVar4;
  int *piVar5;
  bool bVar6;
  bool bVar7;
  bool bVar8;
  bool bVar9;
  
  iVar2 = _pmap_phys_to_index(param_1);
  bVar9 = false;
  bVar8 = SBORROW4(-1,iVar2);
  bVar6 = -1 - iVar2 < 0;
  bVar7 = iVar2 == -1;
  if (!bVar7) {
    piVar5 = (int *)(_pv_head_table + iVar2 * 0xc);
    do {
      iVar2 = piVar5[1];
      bVar6 = iVar2 < 0;
      bVar8 = false;
      bVar7 = true;
      if (iVar2 == 0) break;
      uVar3 = _pmap_pte_valid(iVar2,piVar5[2]);
      uVar1 = uVar3 + _m68k_ptes_per_page * 4;
      bVar9 = uVar1 < uVar3;
      if (uVar3 < uVar1) {
        pbVar4 = (byte *)(uVar3 + 3);
        do {
          *pbVar4 = *pbVar4 & 0xf7;
          pbVar4 = pbVar4 + 4;
          uVar3 = uVar3 + 4;
          bVar9 = uVar1 < uVar3;
        } while (!bVar9 && uVar1 != uVar3);
      }
      piVar5 = (int *)*piVar5;
      bVar8 = false;
      bVar6 = (int)piVar5 < 0;
      bVar7 = piVar5 == (int *)0x0;
    } while (!bVar7);
  }
  return bVar9 << 4 | bVar6 << 3 | bVar7 << 2 | bVar8 << 1;
}

