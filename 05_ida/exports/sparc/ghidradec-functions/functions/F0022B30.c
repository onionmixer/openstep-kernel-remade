
/* WARNING: Removing unreachable block (ram,0xf0022b90) */
/* WARNING: Removing unreachable block (ram,0xf0022bd0) */
/* WARNING: Removing unreachable block (ram,0xf0022b64) */

undefined8 _unp_bind(undefined4 *param_1,int param_2)

{
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  int iVar1;
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
  undefined auStackX_0 [92];
  
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
  iVar1 = param_2 + *(int *)(param_2 + 4);
  if ((param_1[1] == 0) && (*(sword *)(param_2 + 8) != 0x70)) {
    *(undefined *)(iVar1 + *(sword *)(param_2 + 8)) = 0;
    _vattr_null((undefined *)((int)register0x00000038 + -0x48));
    *(undefined4 *)((int)register0x00000038 + -0x48) = 6;
    *(undefined2 *)((int)register0x00000038 + -0x44) = 0x1ff;
    iVar1 = iVar1 + 2;
    _vn_create(iVar1,1,(undefined *)((int)register0x00000038 + -0x48),1,0,
               (undefined *)((int)register0x00000038 + -0x4c));
    if (iVar1 == 0) {
      iVar1 = *(int *)((int)register0x00000038 + -0x4c);
      *(undefined4 *)(iVar1 + 0x20) = *param_1;
      param_1[1] = iVar1;
      iVar1 = param_2;
      _m_copy(param_2,0,1000000000);
      param_1[6] = iVar1;
      iVar1 = 0;
    }
    else if (iVar1 == 0x11) {
      iVar1 = 0x30;
    }
  }
  else {
    iVar1 = 0x16;
  }
  return CONCAT44(param_2,iVar1);
}
