
/* WARNING: Removing unreachable block (ram,0xf00b0950) */
/* WARNING: Removing unreachable block (ram,0xf00b0920) */
/* WARNING: Removing unreachable block (ram,0xf00b08d0) */
/* WARNING: Removing unreachable block (ram,0xf00b08a0) */
/* WARNING: Removing unreachable block (ram,0xf00b0868) */
/* WARNING: Removing unreachable block (ram,0xf00b0808) */
/* WARNING: Removing unreachable block (ram,0xf00b0838) */
/* WARNING: Removing unreachable block (ram,0xf00b088c) */
/* WARNING: Removing unreachable block (ram,0xf00b08b4) */
/* WARNING: Removing unreachable block (ram,0xf00b0910) */
/* WARNING: Removing unreachable block (ram,0xf00b0934) */
/* WARNING: Removing unreachable block (ram,0xf00b0990) */
/* WARNING: Removing unreachable block (ram,0xf00b07f4) */

undefined8 sub_F00B07E4(int *param_1,undefined4 param_2)

{
  uint uVar1;
  undefined3 *puVar2;
  int iVar3;
  undefined *puVar4;
  undefined4 unaff_l0;
  uint uVar5;
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
  uVar5 = param_1[10];
  uVar1 = uVar5;
  _getlongprop(uVar5,&aName_1);
  param_1[3] = uVar1;
  puVar2 = &aZs_1;
  _strcmp();
  if (puVar2 == (undefined3 *)0x0) {
    iVar3 = dword_F011C478 + 1;
    param_1[0xb] = dword_F011C478;
    dword_F011C478 = iVar3;
  }
  uVar1 = uVar5;
  _getproplen(uVar5,&aIntr);
  if ((int)uVar1 < 1) {
    uVar1 = uVar5;
    _getproplen(uVar5,aInterrupts_0);
    if (0 < (int)uVar1) {
      param_1[6] = uVar1 >> 3;
      puVar4 = aInterrupts_1;
      goto loc_F00B088C;
    }
  }
  else {
    param_1[6] = uVar1 >> 3;
    puVar4 = (undefined *)&aIntr_0;
loc_F00B088C:
    uVar1 = uVar5;
    _getlongprop(uVar5,puVar4);
    param_1[7] = uVar1;
  }
  uVar1 = uVar5;
  _getproplen(uVar5,&aReg_0);
  if (0 < (int)uVar1) {
    .udiv();
    param_1[4] = uVar1;
    if (0 < (int)uVar1) {
      uVar1 = uVar5;
      _getlongprop(uVar5,&aReg_1);
      iVar3 = *param_1;
      param_1[5] = uVar1;
      if (((iVar3 != 0) && (0 < *(int *)(iVar3 + 0x30))) && (*(int *)(iVar3 + 0x34) != 0)) {
        _apply_range_to_reg(param_1[3],*(int *)(iVar3 + 0x30),*(int *)(iVar3 + 0x34),param_1[4]);
      }
    }
  }
  uVar1 = uVar5;
  _getproplen(uVar5,&aRanges_2);
  if ((int)uVar1 < 1) {
    if (*param_1 != 0) {
      iVar3 = *(int *)(*param_1 + 0x30);
loc_F00B09C4:
      param_1[0xc] = iVar3;
      param_1[0xd] = *(int *)(*param_1 + 0x34);
      goto locret_F00B09DC;
    }
    param_1[0xc] = 0;
  }
  else {
    .udiv();
    param_1[0xc] = uVar1;
    if (0 < (int)uVar1) {
      _getlongprop(uVar5,&aRanges_1);
      iVar3 = *param_1;
      param_1[0xd] = uVar5;
      if (((iVar3 != 0) && (0 < *(int *)(iVar3 + 0x30))) && (*(int *)(iVar3 + 0x34) != 0)) {
        _apply_range_to_range(param_1[3],*(int *)(iVar3 + 0x30),*(int *)(iVar3 + 0x34),param_1[0xc])
        ;
      }
      goto locret_F00B09DC;
    }
    if (*param_1 != 0) {
      iVar3 = *(int *)(*param_1 + 0x30);
      goto loc_F00B09C4;
    }
    param_1[0xc] = 0;
  }
  param_1[0xd] = 0;
locret_F00B09DC:
  return CONCAT44(param_2,param_1);
}
