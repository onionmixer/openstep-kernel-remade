
/* WARNING: Removing unreachable block (ram,0xf00afe64) */
/* WARNING: Removing unreachable block (ram,0xf00afeec) */
/* WARNING: Removing unreachable block (ram,0xf00afe50) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 _prom_get_stdin_dev_name(int param_1,int param_2)

{
  undefined3 *puVar1;
  int iVar2;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 uVar3;
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
  iVar2 = param_1;
  _prom_stdinpath();
  if ((iVar2 == 0) || (_path_to_devi(), iVar2 == 0)) {
    if ((_obp_romvec_version != 0) && (_obp_romvec_version != 2)) {
      uVar3 = 0xffffffff;
      goto locret_F00AFEFC;
    }
    if (4 < **(byte **)(__romp + 0x48)) {
      uVar3 = 0xffffffff;
      goto locret_F00AFEFC;
    }
    if (param_2 < 3) goto loc_F00AFEF8;
    puVar1 = &aZs;
    iVar2 = param_2;
  }
  else {
    if (param_2 < 3) {
loc_F00AFEF8:
      uVar3 = 0xffffffff;
      goto locret_F00AFEFC;
    }
    *(undefined *)(param_1 + param_2 + -1) = 0;
    puVar1 = *(undefined3 **)(iVar2 + 0xc);
    iVar2 = param_2 + -1;
  }
  uVar3 = 0;
  _strncpy(param_1,puVar1,iVar2);
locret_F00AFEFC:
  return CONCAT44(param_2,uVar3);
}
