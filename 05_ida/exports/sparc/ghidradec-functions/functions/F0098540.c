
/* WARNING: Removing unreachable block (ram,0xf00985e4) */
/* WARNING: Removing unreachable block (ram,0xf00985ec) */
/* WARNING: Removing unreachable block (ram,0xf00985ac) */

undefined8 _fill_machinfo(undefined4 param_1,undefined4 param_2)

{
  bool bVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  undefined *puVar4;
  int iVar5;
  uint uVar6;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
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
  DAT_f0112a3c = _sysname;
  _mach_info = 0x71;
  DAT_f0112a58._0_4_ = _mcname;
  _mcname[0] = 0;
  _mmc_info._0_4_ = 0xffffffff;
  uVar6 = 0;
  puVar4 = _modname;
  puVar2 = &_mod_info;
  do {
    puVar2[1] = puVar4;
    puVar4 = puVar4 + 0x28;
    uVar6 = uVar6 + 1;
    puVar2 = puVar2 + 0x1d;
  } while (uVar6 < 4);
  uVar3 = 0;
  _prom_nextnode(0);
  puVar4 = _sysname;
  iVar5 = 0x27;
  do {
    *puVar4 = 0;
    puVar4 = puVar4 + 1;
    bVar1 = 0 < iVar5;
    iVar5 = iVar5 + -1;
  } while (bVar1);
  _prom_getprop(uVar3,&_psname,DAT_f0112a3c);
  _fill_node(uVar3);
  return CONCAT44(param_2,param_1);
}
