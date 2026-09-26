
/* WARNING: Removing unreachable block (ram,0xf00b01e4) */
/* WARNING: Removing unreachable block (ram,0xf00b01d0) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 _prom_get_stdout_subunit(undefined2 *param_1,undefined4 param_2)

{
  byte bVar1;
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
  _prom_stdoutpath();
  if (param_1 != (undefined2 *)0x0) {
    _prom_get_path_option();
    goto locret_F00B026C;
  }
  if ((_obp_romvec_version != 0) && (param_1 = (undefined2 *)0x0, _obp_romvec_version != 2))
  goto locret_F00B026C;
  bVar1 = **(byte **)(__romp + 0x48);
  if (bVar1 == 2) {
loc_F00B0268:
    param_1 = &aB_0;
  }
  else {
    if (bVar1 < 3) {
      if (bVar1 != 1) {
        param_1 = (undefined2 *)0x0;
        goto locret_F00B026C;
      }
    }
    else if (bVar1 != 3) {
      if (bVar1 != 4) {
        param_1 = (undefined2 *)0x0;
        goto locret_F00B026C;
      }
      goto loc_F00B0268;
    }
    param_1 = &aA_0;
  }
locret_F00B026C:
  return CONCAT44(param_2,param_1);
}
