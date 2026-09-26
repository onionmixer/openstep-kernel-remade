
/* WARNING: Removing unreachable block (ram,0xf0039880) */
/* WARNING: Removing unreachable block (ram,0xf0039840) */

undefined8 sub_F0039838(int *param_1,int param_2)

{
  uint uVar1;
  undefined4 unaff_l0;
  int iVar2;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 uVar3;
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
  iVar2 = param_1[0xc];
  _getthetime((undefined *)((int)register0x00000038 + -0x10));
  if (*(int *)(iVar2 + 0xc0) <= *(int *)((int)register0x00000038 + -0x10)) {
    if (*(int *)((int)register0x00000038 + -0x10) != *(int *)(iVar2 + 0xc0)) {
      uVar3 = 0;
      goto locret_F00398E4;
    }
    if (*(int *)(iVar2 + 0xc4) <= *(int *)((int)register0x00000038 + -0xc)) {
      uVar3 = 0;
      goto locret_F00398E4;
    }
  }
  _memcpy(param_2,iVar2 + 0x80,0x40);
  *(uint *)(param_2 + 0xc) = *(uint *)(*(int *)(param_1[9] + 0x128) + 0x28) | 0xff00;
  uVar1 = *(uint *)(*param_1 + 0x14);
  if (*(uint *)(param_2 + 0x18) < uVar1) {
    if ((*(uint *)(*param_1 + 0x38) & 0x40000000) == 0) {
      uVar3 = 1;
      if ((*(word *)(iVar2 + 0x60) & 0x10) == 0) goto locret_F00398E4;
      *(uint *)(param_2 + 0x18) = uVar1;
    }
    else {
      *(uint *)(param_2 + 0x18) = uVar1;
    }
  }
  uVar3 = 1;
locret_F00398E4:
  return CONCAT44(param_2,uVar3);
}
