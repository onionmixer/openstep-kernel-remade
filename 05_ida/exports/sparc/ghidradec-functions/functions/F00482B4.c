
/* WARNING: Removing unreachable block (ram,0xf00482d8) */
/* WARNING: Removing unreachable block (ram,0xf00482cc) */

undefined8 sub_F00482B4(int param_1,int *param_2,undefined4 param_3)

{
  int iVar1;
  undefined4 unaff_l0;
  int iVar2;
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
  iVar2 = *(int *)(param_1 + 0x30);
  iVar1 = *(int *)(iVar2 + 0x38);
  if (iVar1 == 0) {
    _getthetime((undefined *)((int)register0x00000038 + -0x10));
    _bzero(param_2,0x40);
    param_2[6] = *(int *)(iVar2 + 0x48);
    param_2[8] = *(int *)((int)register0x00000038 + -0x10);
    param_2[9] = *(int *)((int)register0x00000038 + -0xc);
    param_2[10] = *(int *)((int)register0x00000038 + -0x10);
    param_2[0xb] = *(int *)((int)register0x00000038 + -0xc);
    param_2[0xc] = *(int *)((int)register0x00000038 + -0x10);
    param_2[0xd] = *(int *)((int)register0x00000038 + -0xc);
    iVar1 = *(int *)(param_1 + 0x28);
  }
  else {
    (**(code **)(*(int *)(iVar1 + 0x1c) + 0x14))(iVar1,param_2,param_3);
    if (iVar1 != 0) goto locret_F00483B0;
    param_2[8] = *(int *)(iVar2 + 0x4c);
    param_2[9] = *(int *)(iVar2 + 0x50);
    param_2[10] = *(int *)(iVar2 + 0x54);
    param_2[0xb] = *(int *)(iVar2 + 0x58);
    param_2[0xc] = *(int *)(iVar2 + 0x5c);
    iVar1 = *param_2;
    param_2[0xd] = *(int *)(iVar2 + 0x60);
  }
  if (iVar1 == 3) {
    (**(code **)(*(int *)(param_1 + 0x1c) + 0x80))();
    param_2[7] = param_1;
  }
  else {
    if (iVar1 != 4) {
      iVar1 = 0;
      goto locret_F00483B0;
    }
    param_2[7] = 0x2000;
  }
  iVar1 = 0;
locret_F00483B0:
  return CONCAT44(param_2,iVar1);
}
