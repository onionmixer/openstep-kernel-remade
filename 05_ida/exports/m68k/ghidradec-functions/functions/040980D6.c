
byte _pmap_copy_on_write(undefined4 param_1)

{
  undefined4 *puVar1;
  uint uVar2;
  int iVar3;
  undefined4 *puVar4;
  int iVar5;
  uint uVar6;
  byte *pbVar7;
  bool bVar8;
  bool bVar9;
  bool bVar10;
  
  iVar5 = _pmap_phys_to_index(param_1);
  bVar10 = false;
  bVar9 = SBORROW4(-1,iVar5);
  iVar3 = -1 - iVar5;
  bVar8 = iVar5 == -1;
  if (!bVar8) {
    puVar1 = (undefined4 *)(_pv_head_table + iVar5 * 0xc);
    bVar10 = false;
    puVar4 = (undefined4 *)puVar1[1];
    while( true ) {
      bVar9 = false;
      iVar3 = 0;
      bVar8 = true;
      if (puVar4 == (undefined4 *)0x0) break;
      iVar3 = puVar1[1];
      if (iVar3 == _kernel_pmap) {
        _pflush_super();
      }
      else if (_active_threads != 0) {
        _pflush_user();
      }
      uVar6 = _pmap_pte_valid(iVar3,puVar1[2]);
      uVar2 = uVar6 + _m68k_ptes_per_page * 4;
      bVar10 = uVar2 < uVar6;
      if (uVar6 < uVar2) {
        pbVar7 = (byte *)(uVar6 + 3);
        do {
          if ((*pbVar7 & 3) == 1) {
            *pbVar7 = *pbVar7 | 4;
          }
          pbVar7 = pbVar7 + 4;
          uVar6 = uVar6 + 4;
          bVar10 = uVar2 < uVar6;
        } while (!bVar10 && uVar2 != uVar6);
      }
      puVar1 = (undefined4 *)*puVar1;
      puVar4 = puVar1;
    }
  }
  return bVar10 << 4 | (iVar3 < 0) << 3 | bVar8 << 2 | bVar9 << 1;
}
