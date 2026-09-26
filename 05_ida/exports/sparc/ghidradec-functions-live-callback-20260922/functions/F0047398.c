
/* WARNING: Removing unreachable block (ram,0xf00474ec) */
/* WARNING: Removing unreachable block (ram,0xf00473dc) */
/* WARNING: Removing unreachable block (ram,0xf00473ec) */
/* WARNING: Removing unreachable block (ram,0xf00473f8) */
/* WARNING: Removing unreachable block (ram,0xf00474bc) */
/* WARNING: Removing unreachable block (ram,0xf00474fc) */
/* WARNING: Removing unreachable block (ram,0xf00473ac) */

undefined8 _specvp(int param_1,undefined4 param_2,undefined4 param_3)

{
  sword sVar3;
  int iVar1;
  int iVar2;
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
  sVar3 = (sword)param_2;
  iVar1 = (int)sVar3;
  sub_F00478C4(iVar1,param_1,param_3);
  if (iVar1 != 0) goto loc_F00474F8;
  if ((param_1 == 0) || (*(int *)(param_1 + 0x28) != 8)) {
    iVar1 = 0x68;
    _kalloc();
    _bzero();
    *(undefined **)(iVar1 + 0x20) = _spec_vnodeops;
    if (param_1 == 0) goto loc_F0047470;
    iVar2 = param_1;
    (**(code **)(*(int *)(param_1 + 0x1c) + 0x14))
              (param_1,(undefined *)((int)register0x00000038 + -0x48),
               *(undefined4 *)(_active_u + 0x1c));
    if (iVar2 == 0) {
      *(undefined4 *)(iVar1 + 0x4c) = *(undefined4 *)((int)register0x00000038 + -0x28);
      *(undefined4 *)(iVar1 + 0x50) = *(undefined4 *)((int)register0x00000038 + -0x24);
      *(undefined4 *)(iVar1 + 0x54) = *(undefined4 *)((int)register0x00000038 + -0x20);
      *(undefined4 *)(iVar1 + 0x58) = *(undefined4 *)((int)register0x00000038 + -0x1c);
      *(undefined4 *)(iVar1 + 0x5c) = *(undefined4 *)((int)register0x00000038 + -0x18);
      *(undefined4 *)(iVar1 + 0x60) = *(undefined4 *)((int)register0x00000038 + -0x14);
      goto loc_F0047470;
    }
    *(int *)(iVar1 + 0x38) = param_1;
  }
  else {
    iVar1 = param_1;
    _fifosp();
loc_F0047470:
    *(int *)(iVar1 + 0x38) = param_1;
  }
  *(sword *)(iVar1 + 0x42) = sVar3;
  *(sword *)(iVar1 + 0x30) = sVar3;
  *(undefined2 *)(iVar1 + 10) = 1;
  *(int *)(iVar1 + 0x34) = iVar1;
  if (param_1 == 0) {
    *(undefined4 *)(iVar1 + 0x2c) = 3;
    *(undefined4 *)(iVar1 + 0x28) = 0;
    *(int *)(iVar1 + 0x3c) = iVar1 + 4;
  }
  else {
    *(sword *)(param_1 + 6) = *(sword *)(param_1 + 6) + 1;
    *(undefined4 *)(iVar1 + 0x2c) = *(undefined4 *)(param_1 + 0x28);
    *(undefined4 *)(iVar1 + 0x28) = *(undefined4 *)(param_1 + 0x24);
    if (*(int *)(param_1 + 0x28) == 3) {
      iVar2 = (int)sVar3;
      _bdevvp();
      *(int *)(iVar1 + 0x3c) = iVar2;
      *(undefined4 *)(iVar1 + 0x48) = *(undefined4 *)(*(int *)(iVar2 + 0x30) + 0x48);
    }
  }
  sub_F00475C4(iVar1);
loc_F00474F8:
  _set_blocksize(iVar1,(int)sVar3);
  return CONCAT44(param_2,iVar1 + 4);
}

