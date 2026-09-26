
/* WARNING: Removing unreachable block (ram,0xf000b020) */
/* WARNING: Removing unreachable block (ram,0xf000aff4) */

undefined8 _fsetown(int param_1,int param_2)

{
  int *piVar1;
  sword sVar2;
  int iVar3;
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
  sVar2 = *(sword *)(param_1 + 0xc);
  *(int *)((int)register0x00000038 + 0x48) = param_2;
  if (sVar2 == 2) {
    piVar1 = (int *)(param_1 + 0x18);
    param_1 = 0;
    *(undefined2 *)(*piVar1 + 0x5a) = *(undefined2 *)((int)register0x00000038 + 0x4a);
  }
  else {
    iVar3 = -param_2;
    if (0 < param_2) {
      iVar3 = param_2;
      _pfind();
      if (iVar3 == 0) {
        param_1 = 3;
        goto locret_F000B02C;
      }
      iVar3 = (int)*(sword *)(iVar3 + 0x2e);
    }
    *(int *)((int)register0x00000038 + 0x48) = iVar3;
    _fioctl(param_1,0x80047476,(undefined *)((int)register0x00000038 + 0x48));
  }
locret_F000B02C:
  return CONCAT44(param_2,param_1);
}
