
/* WARNING: Removing unreachable block (ram,0xf0039a50) */

undefined8 _nattr_to_vattr(int *param_1,int *param_2,int *param_3)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  undefined4 unaff_l0;
  int iVar4;
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
  iVar4 = param_1[0xc];
  *param_3 = *param_2;
  *(sword *)(param_3 + 1) = (sword)param_2[1];
  *(sword *)((int)param_3 + 6) = (sword)param_2[3];
  *(sword *)(param_3 + 2) = (sword)param_2[4];
  iVar1 = param_1[9];
  _vfs_fixedmajor();
  param_3[3] = (uint)(word)((word)(iVar1 << 8) |
                           (word)*(byte *)(*(int *)(param_1[9] + 0x128) + 0x2b));
  param_3[4] = param_2[10];
  *(sword *)(param_3 + 5) = (sword)param_2[2];
  iVar1 = *param_1;
  uVar3 = *(uint *)(iVar1 + 0x14);
  if ((uint)param_2[5] < uVar3) {
    if ((*(uint *)(iVar1 + 0x38) & 0x40000000) == 0) {
      if ((*(word *)(iVar4 + 0x60) & 0x10) == 0) {
        iVar2 = param_2[5];
        goto loc_F0039AD8;
      }
      param_3[6] = uVar3;
    }
    else {
      param_3[6] = uVar3;
    }
  }
  else {
    iVar2 = param_2[5];
loc_F0039AD8:
    param_3[6] = iVar2;
  }
  uVar3 = param_3[6];
  if (*(uint *)(iVar4 + 0x98) < uVar3) {
    *(uint *)(iVar4 + 0x98) = uVar3;
  }
  else {
    if ((*(word *)(iVar4 + 0x60) & 0x10) != 0) {
      iVar4 = param_2[0xb];
      goto loc_F0039B08;
    }
    *(uint *)(iVar4 + 0x98) = uVar3;
  }
  iVar4 = param_2[0xb];
loc_F0039B08:
  param_3[8] = iVar4;
  param_3[9] = param_2[0xc];
  param_3[10] = param_2[0xd];
  param_3[0xb] = param_2[0xe];
  param_3[0xc] = param_2[0xf];
  param_3[0xd] = param_2[0x10];
  *(sword *)(param_3 + 0xe) = (sword)param_2[7];
  param_3[0xf] = param_2[8];
  if (*param_2 == 3) {
    iVar4 = 0x800;
  }
  else {
    iVar4 = 0x2000;
    if (*param_2 != 4) {
      iVar4 = param_2[6];
    }
  }
  param_3[7] = iVar4;
  if ((*param_2 == 4) && (param_2[7] == -1)) {
    *param_3 = 8;
    *(undefined2 *)(param_3 + 0xe) = 0;
    *(word *)(param_3 + 1) = *(word *)(param_3 + 1) & 0xfff | 0x1000;
    param_3[7] = param_2[6];
  }
  return CONCAT44(param_2,iVar1);
}

