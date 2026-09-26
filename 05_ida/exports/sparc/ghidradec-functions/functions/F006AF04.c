
/* WARNING: Removing unreachable block (ram,0xf006af94) */
/* WARNING: Removing unreachable block (ram,0xf006af60) */
/* WARNING: Removing unreachable block (ram,0xf006af48) */
/* WARNING: Removing unreachable block (ram,0xf006afd0) */
/* WARNING: Removing unreachable block (ram,0xf006afb8) */
/* WARNING: Removing unreachable block (ram,0xf006af2c) */

undefined8 sub_F006AF04(int param_1,int param_2)

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
  if (*(int *)(param_2 + 0xc) == 0) {
    *(int *)((int)register0x00000038 + -0xc) = _active_threads;
  }
  else {
    iVar1 = *(int *)(_active_threads + 0xc);
    _thread_create(iVar1,(undefined *)((int)register0x00000038 + -0xc));
    if (iVar1 != 0) {
      iVar1 = 7;
      goto locret_F006AFE8;
    }
    _thread_deallocate(*(undefined4 *)((int)register0x00000038 + -0xc));
  }
  iVar2 = param_1 + 8;
  iVar1 = *(int *)((int)register0x00000038 + -0xc);
  sub_F006AFF0(iVar1,iVar2,*(int *)(param_1 + 4) + -8);
  if (iVar1 == 0) {
    if (*(int *)(param_2 + 0xc) == 0) {
      iVar1 = _active_threads;
      sub_F006B058(_active_threads,iVar2,*(int *)(param_1 + 4) + -8,param_2 + 8);
      if ((iVar1 != 0) ||
         (iVar1 = _active_threads,
         sub_F006B0C4(_active_threads,iVar2,*(int *)(param_1 + 4) + -8,param_2 + 4), iVar1 != 0))
      goto locret_F006AFE8;
    }
    else {
      _thread_resume(*(undefined4 *)((int)register0x00000038 + -0xc),iVar2);
    }
    iVar1 = 0;
    *(int *)(param_2 + 0xc) = *(int *)(param_2 + 0xc) + 1;
  }
locret_F006AFE8:
  return CONCAT44(param_2,iVar1);
}
