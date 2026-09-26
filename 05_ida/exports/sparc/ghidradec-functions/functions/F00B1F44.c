
/* WARNING: Removing unreachable block (ram,0xf00b200c) */
/* WARNING: Removing unreachable block (ram,0xf00b1ff0) */
/* WARNING: Removing unreachable block (ram,0xf00b1fa0) */
/* WARNING: Removing unreachable block (ram,0xf00b1f80) */
/* WARNING: Removing unreachable block (ram,0xf00b1fc0) */
/* WARNING: Removing unreachable block (ram,0xf00b2004) */
/* WARNING: Removing unreachable block (ram,0xf00b2020) */
/* WARNING: Removing unreachable block (ram,0xf00b1f50) */

undefined8 _findcons(undefined *param_1,undefined4 *param_2)

{
  sword sVar1;
  int iVar2;
  undefined4 uVar3;
  uint uVar4;
  undefined *puVar5;
  undefined *puVar6;
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
  iVar2 = *(int *)(param_1 + 0xc);
  _strcmp(iVar2,&aOptions);
  if (iVar2 == 0) {
    param_2[2] = param_1;
  }
  else if (*(int *)(param_1 + 0x20) != 0) {
    iVar2 = *(int *)(param_1 + 0xc);
    _strncmp(iVar2,&aZs_2,2);
    if (iVar2 == 0) {
      iVar2 = *(int *)(param_1 + 0x28);
      _getprop(iVar2,aKeyboard_0,0);
      if (iVar2 == 0) {
        uVar4 = *(uint *)(param_1 + 0x28);
        _getprop(uVar4,&aFlags_0,0);
        if ((uVar4 & 0x100) == 0) goto locret_F00B2040;
        uVar3 = *(undefined4 *)(param_1 + 0x2c);
      }
      else {
        uVar3 = *(undefined4 *)(param_1 + 0x2c);
      }
      *param_2 = uVar3;
    }
    else {
      param_1 = DAT_f011d000;
      puVar5 = DAT_f011d000;
      if (DAT_f011d17a._0_2_ == -1) {
        _prom_stdout_is_framebuffer();
        puVar6 = DAT_f011d000;
        if (puVar5 != (undefined *)0x0) {
          _prom_stdoutpath();
          _path_to_devi();
          if (puVar6 != (undefined *)0x0) {
            sVar1 = 99;
            _finddev(99,puVar6);
            DAT_f011d17a._0_2_ = sVar1;
          }
        }
      }
      if (DAT_f011d17a._0_2_ != -1) {
        *(sword *)(param_2 + 1) = DAT_f011d17a._0_2_;
      }
    }
  }
locret_F00B2040:
  return CONCAT44(param_2,param_1);
}
