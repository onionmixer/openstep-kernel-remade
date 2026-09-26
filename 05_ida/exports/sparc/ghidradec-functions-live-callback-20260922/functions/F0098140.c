
/* WARNING: Removing unreachable block (ram,0xf009818c) */
/* WARNING: Removing unreachable block (ram,0xf0098154) */
/* WARNING: Removing unreachable block (ram,0xf00981b4) */
/* WARNING: Removing unreachable block (ram,0xf0098148) */

undefined8 _map_wellknown_devices(undefined4 param_1,undefined4 param_2)

{
  undefined6 *puVar1;
  undefined4 unaff_l0;
  undefined6 **ppuVar2;
  undefined4 unaff_l1;
  int iVar3;
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
  iVar3 = 0;
  _prom_nextnode(0);
  sub_F00981D0();
  ppuVar2 = &off_F0112DF4;
  puVar1 = (undefined6 *)DAT_f0112dfc._0_4_;
  if (off_F0112DF4 != (undefined6 *)0x0) {
    while( true ) {
      if (((uint)puVar1 & 6) == 0) {
        iVar3 = iVar3 + 1;
        _prom_printf(aRequiredDevice,*ppuVar2);
      }
      if (ppuVar2[3] == (undefined6 *)0x0) break;
      puVar1 = ppuVar2[5];
      ppuVar2 = ppuVar2 + 3;
    }
  }
  if (iVar3 != 0) {
    _panic(aMapWellknownDe);
  }
  _utimersp = 0xfeff9000;
  return CONCAT44(param_2,param_1);
}

