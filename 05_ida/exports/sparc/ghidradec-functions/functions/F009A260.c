
/* WARNING: Removing unreachable block (ram,0xf009a280) */
/* WARNING: Removing unreachable block (ram,0xf009a350) */
/* WARNING: Removing unreachable block (ram,0xf009a310) */
/* WARNING: Removing unreachable block (ram,0xf009a340) */
/* WARNING: Removing unreachable block (ram,0xf009a2e0) */
/* WARNING: Removing unreachable block (ram,0xf009a2b4) */
/* WARNING: Removing unreachable block (ram,0xf009a290) */
/* WARNING: Removing unreachable block (ram,0xf009a2a0) */
/* WARNING: Removing unreachable block (ram,0xf009a2cc) */
/* WARNING: Removing unreachable block (ram,0xf009a32c) */
/* WARNING: Removing unreachable block (ram,0xf009a348) */
/* WARNING: Removing unreachable block (ram,0xf009a318) */
/* WARNING: Removing unreachable block (ram,0xf009a370) */
/* WARNING: Removing unreachable block (ram,0xf009a378) */
/* WARNING: Removing unreachable block (ram,0xf009a264) */

undefined8 _mb_mapfree(uint *param_1,uint *param_2)

{
  uint *puVar1;
  uint *puVar2;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  uint uVar3;
  uint *puVar4;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 unaff_i1;
  undefined4 unaff_i2;
  undefined4 unaff_i3;
  undefined4 unaff_i4;
  undefined4 unaff_i5;
  undefined4 unaff_fp;
  undefined4 unaff_i7;
  bool in_DECOMPILE_MODE;
  int in_CWP;
  
  if (!in_DECOMPILE_MODE) {
    *(undefined4 *)(in_CWP * 0x40 + 0x8000) = unaff_i0;
    *(undefined4 *)((in_CWP * 0x10 + 1) * 4 + 0x8000) = unaff_i1;
    *(undefined4 *)((in_CWP * 0x10 + 2) * 4 + 0x8000) = unaff_i2;
    *(undefined4 *)((in_CWP * 0x10 + 3) * 4 + 0x8000) = unaff_i3;
    *(undefined4 *)((in_CWP * 0x10 + 4) * 4 + 0x8000) = unaff_i4;
    *(undefined4 *)((in_CWP * 0x10 + 5) * 4 + 0x8000) = unaff_i5;
    *(undefined4 *)((in_CWP * 0x10 + 6) * 4 + 0x8000) = unaff_fp;
    *(undefined4 *)((in_CWP * 0x10 + 7) * 4 + 0x8000) = unaff_i7;
    *(undefined4 *)((in_CWP * 0x10 + 8) * 4 + 0x8000) = unaff_l0;
    *(undefined4 *)((in_CWP * 0x10 + 9) * 4 + 0x8000) = unaff_l1;
    *(undefined4 *)((in_CWP * 0x10 + 10) * 4 + 0x8000) = unaff_l3;
    *(undefined4 *)((in_CWP * 0x10 + 0xb) * 4 + 0x8000) = unaff_l3;
    *(undefined4 *)((in_CWP * 0x10 + 0xc) * 4 + 0x8000) = unaff_l4;
    *(undefined4 *)((in_CWP * 0x10 + 0xd) * 4 + 0x8000) = unaff_l5;
    *(undefined4 *)((in_CWP * 0x10 + 0xe) * 4 + 0x8000) = unaff_l6;
    *(undefined4 *)((in_CWP * 0x10 + 0xf) * 4 + 0x8000) = unaff_l7;
  }
  puVar1 = param_1;
  _splvm();
  uVar3 = *param_2;
  if (uVar3 == 0) {
    _printf(aMbMapfreeMr0);
  }
  else {
    *param_2 = 0;
    _splx(puVar1);
    puVar4 = (uint *)(uVar3 >> 0xc);
    puVar2 = puVar4;
    _map_addr_to_map(puVar4,param_1);
    puVar1 = puVar4;
    if (puVar2 != (uint *)0x0) {
      param_1 = puVar4;
      _iom_ptefind(puVar4,puVar2);
      if (param_1 == (uint *)0x0) {
        _panic(aMbMapfreeNoIop);
      }
      param_2 = (uint *)0x0;
      while (puVar1 = param_1, _get_iommu_entry(), ((uint)puVar1 & 2) != 0) {
        if (((*param_1 & 4) != 0) && (_iommu_info._0_4_ == 0)) {
          _pmap_vacflush(*param_1 >> 8);
        }
        _iom_pteunload(param_1);
        param_1 = param_1 + 1;
        param_2 = (uint *)((int)param_2 + 1);
      }
      _splvm();
      _rmfree(puVar2,(int)param_2 + 1,puVar4);
      _splx(puVar1);
    }
    _splvm();
    if (dword_F0131558 != 0) {
      sub_F009A4D4((int)puVar1 >> 8 & 0xf);
    }
  }
  _splx(puVar1);
  return CONCAT44(param_2,param_1);
}
