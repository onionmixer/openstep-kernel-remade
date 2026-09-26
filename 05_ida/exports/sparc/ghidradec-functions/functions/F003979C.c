
/* WARNING: Removing unreachable block (ram,0xf00397a4) */

undefined8 sub_F003979C(int param_1,undefined4 param_2)

{
  uint uVar1;
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
  iVar4 = *(int *)(param_1 + 0x30);
  _getthetime((undefined *)((int)register0x00000038 + -0x10));
  *(undefined4 *)(iVar4 + 0xc0) = *(undefined4 *)((int)register0x00000038 + -0x10);
  *(undefined4 *)(iVar4 + 0xc4) = *(undefined4 *)((int)register0x00000038 + -0xc);
  uVar3 = *(int *)((int)register0x00000038 + -0x10) - *(int *)(iVar4 + 0xa8) >> 4;
  if (*(int *)(param_1 + 0x28) == 2) {
    iVar2 = *(int *)(*(int *)(param_1 + 0x24) + 0x128);
    uVar1 = *(uint *)(iVar2 + 0x68);
    if (uVar1 <= uVar3) {
      uVar1 = *(uint *)(iVar2 + 0x6c);
loc_F0039814:
      if (uVar3 <= uVar1) {
        iVar2 = *(int *)(iVar4 + 0xc0);
        goto loc_F0039828;
      }
    }
  }
  else {
    iVar2 = *(int *)(*(int *)(param_1 + 0x24) + 0x128);
    uVar1 = *(uint *)(iVar2 + 0x60);
    if (uVar1 <= uVar3) {
      uVar1 = *(uint *)(iVar2 + 100);
      goto loc_F0039814;
    }
  }
  iVar2 = *(int *)(iVar4 + 0xc0);
  uVar3 = uVar1;
loc_F0039828:
  *(uint *)(iVar4 + 0xc0) = iVar2 + uVar3;
  return CONCAT44(param_2,param_1);
}
