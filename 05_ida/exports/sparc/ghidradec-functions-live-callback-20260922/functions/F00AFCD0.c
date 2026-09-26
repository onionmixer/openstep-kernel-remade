
/* WARNING: Removing unreachable block (ram,0xf00afd34) */
/* WARNING: Removing unreachable block (ram,0xf00afd5c) */
/* WARNING: Removing unreachable block (ram,0xf00afd2c) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 _prom_get_boot_dev_name(undefined *param_1,int param_2)

{
  int iVar1;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 uVar2;
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
  if (_obp_romvec_version == 0) {
    if (2 < param_2) {
      *param_1 = *(undefined *)(**(int **)(__romp + 0x80) + 0x84);
      uVar2 = 0;
      param_1[1] = *(undefined *)(**(int **)(__romp + 0x80) + 0x85);
      param_1[2] = 0;
      goto locret_F00AFD70;
    }
  }
  else {
    iVar1 = _obp_romvec_version;
    _prom_bootpath();
    _path_to_devi();
    if ((iVar1 != 0) && (2 < param_2)) {
      param_1[param_2 + -1] = 0;
      _strncpy(param_1,*(undefined4 *)(iVar1 + 0xc),param_2 + -1);
      uVar2 = 0;
      goto locret_F00AFD70;
    }
  }
  uVar2 = 0xffffffff;
locret_F00AFD70:
  return CONCAT44(param_2,uVar2);
}

