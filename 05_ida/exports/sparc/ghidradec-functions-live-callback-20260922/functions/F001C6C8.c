
/* WARNING: Removing unreachable block (ram,0xf001c7f0) */
/* WARNING: Removing unreachable block (ram,0xf001c710) */
/* WARNING: Removing unreachable block (ram,0xf001c7e4) */
/* WARNING: Removing unreachable block (ram,0xf001c6cc) */

undefined8 _getc(int *param_1,undefined4 param_2)

{
  int *piVar1;
  int iVar2;
  byte *pbVar3;
  uint uVar4;
  undefined4 *puVar5;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  uint uVar6;
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
  piVar1 = param_1;
  _spltty();
  if (*param_1 < 1) {
    uVar6 = 0xffffffff;
    *param_1 = 0;
    param_1[2] = 0;
    param_1[1] = 0;
  }
  else {
    pbVar3 = (byte *)param_1[1];
    uVar6 = (uint)*pbVar3;
    iVar2 = (int)((uint)pbVar3 & 0x3f) >> 3;
    if (((int)*(char *)(iVar2 + ((uint)pbVar3 & 0xffffffc0) + 4) >>
         ((char)((uint)pbVar3 & 0x3f) + (char)iVar2 * -8 & 0x1fU) & 1U) != 0) {
      uVar6 = uVar6 | 0x100;
    }
    iVar2 = *param_1;
    param_1[1] = (int)(pbVar3 + 1);
    *param_1 = iVar2 + -1;
    if (iVar2 + -1 < 1) {
      param_1[2] = 0;
      puVar5 = (undefined4 *)(param_1[1] - 1U & 0xffffffc0);
      param_1[1] = 0;
      *puVar5 = _cfreelist;
      _cfreelist = puVar5;
    }
    else {
      uVar4 = param_1[1];
      if ((uVar4 & 0x3f) != 0) goto loc_F001C7F0;
      param_1[1] = *(int *)(uVar4 - 0x40) + 0xc;
      *(undefined4 **)(uVar4 - 0x40) = _cfreelist;
      _cfreelist = (undefined4 *)(uVar4 - 0x40);
    }
    _cfreecount = _cfreecount + 0x34;
    if (_cwaiting._0_1_ != '\0') {
      _wakeup(&_cwaiting);
      _cwaiting._0_1_ = '\0';
    }
  }
loc_F001C7F0:
  _splx(piVar1);
  return CONCAT44(param_2,uVar6);
}

