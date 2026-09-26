
byte _pmap_remove_all(undefined4 param_1)

{
  int *piVar1;
  undefined4 *puVar2;
  int *piVar3;
  byte bVar4;
  int iVar5;
  int iVar6;
  undefined4 *puVar7;
  int iVar8;
  bool bVar9;
  bool bVar10;
  bool bVar11;
  
  iVar5 = _vm_phys_to_vm_page(param_1);
  iVar6 = _pmap_phys_to_index(param_1);
  bVar11 = false;
  bVar10 = SBORROW4(-1,iVar6);
  iVar8 = -1 - iVar6;
  bVar9 = iVar6 == -1;
  if (!bVar9) {
    piVar1 = (int *)(_pv_head_table + iVar6 * 0xc);
    while( true ) {
      iVar6 = piVar1[1];
      bVar10 = false;
      bVar9 = true;
      iVar8 = 0;
      if (iVar6 == 0) break;
      if (iVar6 == _kernel_pmap) {
        _pflush_super();
      }
      else if (_active_threads != 0) {
        _pflush_user();
      }
      iVar8 = piVar1[2];
      puVar7 = (undefined4 *)_pmap_pte_valid(iVar6,iVar8);
      *(int *)(iVar6 + 0x10) = *(int *)(iVar6 + 0x10) + -1;
      if (_cpu_type == '\0') {
        bVar4 = *(byte *)((int)puVar7 + 3) & 0x20;
      }
      else {
        bVar4 = *(byte *)((int)puVar7 + 2) & 8;
      }
      if (bVar4 != 0) {
        *(int *)(iVar6 + 0x14) = *(int *)(iVar6 + 0x14) + -1;
      }
      piVar3 = (int *)*piVar1;
      if (piVar3 == (int *)0x0) {
        piVar1[1] = 0;
      }
      else {
        *piVar1 = *piVar3;
        piVar1[1] = piVar3[1];
        piVar1[2] = piVar3[2];
        _zfree(_pv_list_zone,piVar3);
      }
      puVar2 = puVar7 + _m68k_ptes_per_page;
      bVar11 = puVar2 < puVar7;
      if (puVar7 < puVar2) {
        do {
          if (((*(byte *)((int)puVar7 + 3) & 0x13) == 0x11) && (iVar5 != 0)) {
            *(byte *)(iVar5 + 0x1e) = *(byte *)(iVar5 + 0x1e) & 0xfb;
          }
          *puVar7 = 0;
          _pmap_collapse(iVar6,iVar8,puVar7);
          puVar7 = puVar7 + 1;
          iVar8 = _m68k_page_size + iVar8;
          bVar11 = puVar2 < puVar7;
        } while (!bVar11 && puVar2 != puVar7);
      }
    }
  }
  return bVar11 << 4 | (iVar8 < 0) << 3 | bVar9 << 2 | bVar10 << 1;
}
