
/* WARNING: Removing unreachable block (ram,0xf0048454) */

undefined8 _spec_setattr(int param_1,int param_2,undefined4 param_3)

{
  int iVar1;
  int iVar2;
  undefined4 unaff_l0;
  int iVar3;
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
  char cVar4;
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
  iVar3 = *(int *)(param_1 + 0x30);
  iVar2 = *(int *)(iVar3 + 0x38);
  if (iVar2 == 0) {
    iVar2 = 0;
  }
  else {
    *(undefined4 *)(param_2 + 0x18) = 0xffffffff;
    (**(code **)(*(int *)(iVar2 + 0x1c) + 0x18))(iVar2,param_2,param_3);
  }
  if (iVar2 == 0) {
    cVar4 = *(int *)(param_2 + 0x28) != -1;
    if ((bool)cVar4) {
      *(int *)(iVar3 + 0x54) = *(int *)(param_2 + 0x28);
      *(undefined4 *)(iVar3 + 0x58) = *(undefined4 *)(param_2 + 0x2c);
      iVar1 = *(int *)(param_2 + 0x20);
    }
    else {
      iVar1 = *(int *)(param_2 + 0x20);
    }
    if (iVar1 != -1) {
      *(int *)(iVar3 + 0x4c) = iVar1;
      cVar4 = cVar4 + '\x01';
      *(undefined4 *)(iVar3 + 0x50) = *(undefined4 *)(param_2 + 0x24);
    }
    if (cVar4 != '\0') {
      _getthetime((undefined *)((int)register0x00000038 + -0x10));
      *(undefined4 *)(iVar3 + 0x5c) = *(undefined4 *)((int)register0x00000038 + -0x10);
      *(undefined4 *)(iVar3 + 0x60) = *(undefined4 *)((int)register0x00000038 + -0xc);
    }
  }
  return CONCAT44(param_2,iVar2);
}
