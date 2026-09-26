
/* WARNING: Removing unreachable block (ram,0xf006aea8) */
/* WARNING: Removing unreachable block (ram,0xf006aec8) */
/* WARNING: Removing unreachable block (ram,0xf006ae84) */

undefined8 sub_F006AE50(int param_1,int param_2)

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
  int iVar3;
  undefined4 unaff_i1;
  undefined4 unaff_i2;
  undefined4 unaff_i3;
  undefined4 unaff_i4;
  undefined4 unaff_i5;
  undefined4 unaff_fp;
  undefined4 unaff_i7;
  bool in_DECOMPILE_MODE;
  int in_CWP;
  
  iVar1 = _active_threads;
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
  if (*(int *)(param_2 + 0xc) == 0) {
    iVar2 = param_1 + 8;
    iVar3 = _active_threads;
    sub_F006B058(_active_threads,iVar2,*(int *)(param_1 + 4) + -8,param_2 + 8);
    if (((iVar3 == 0) &&
        (iVar3 = iVar1, sub_F006B0C4(iVar1,iVar2,*(int *)(param_1 + 4) + -8,param_2 + 4), iVar3 == 0
        )) && (sub_F006AFF0(iVar1,iVar2,*(int *)(param_1 + 4) + -8), iVar3 = iVar1, iVar1 == 0)) {
      iVar3 = 0;
      *(uint *)(param_2 + 0x10) = *(uint *)(param_2 + 0x10) | 0x80000000;
      *(int *)(param_2 + 0xc) = *(int *)(param_2 + 0xc) + 1;
    }
  }
  else {
    iVar3 = 4;
  }
  return CONCAT44(param_2,iVar3);
}
