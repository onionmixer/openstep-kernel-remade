
/* WARNING: Removing unreachable block (ram,0xf008a1b4) */
/* WARNING: Removing unreachable block (ram,0xf008a16c) */
/* WARNING: Removing unreachable block (ram,0xf008a12c) */
/* WARNING: Removing unreachable block (ram,0xf008a100) */
/* WARNING: Removing unreachable block (ram,0xf008a0ec) */
/* WARNING: Removing unreachable block (ram,0xf008a0c4) */
/* WARNING: Removing unreachable block (ram,0xf008a0a4) */
/* WARNING: Removing unreachable block (ram,0xf008a0b8) */
/* WARNING: Removing unreachable block (ram,0xf008a0d4) */
/* WARNING: Removing unreachable block (ram,0xf008a0f4) */
/* WARNING: Removing unreachable block (ram,0xf008a118) */
/* WARNING: Removing unreachable block (ram,0xf008a144) */
/* WARNING: Removing unreachable block (ram,0xf008a190) */
/* WARNING: Removing unreachable block (ram,0xf008a1cc) */
/* WARNING: Removing unreachable block (ram,0xf008a084) */

undefined8 _procdup(int param_1,int param_2)

{
  int iVar1;
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
  _flush_user_windows_to_stack();
  iVar1 = *(int *)(param_2 + 0x68);
  _task_create(iVar1,iVar1 != _kernel_task,(undefined *)((int)register0x00000038 + -0xc));
  if (iVar1 != 0) {
    _printf(aForkProcdupTas,iVar1);
  }
  *(undefined4 *)(param_1 + 0x68) = *(undefined4 *)((int)register0x00000038 + -0xc);
  _task_deallocate();
  iVar1 = *(int *)((int)register0x00000038 + -0xc);
  *(int *)(iVar1 + 0x3c) = param_1;
  _thread_create(iVar1,(undefined *)((int)register0x00000038 + -0x10));
  if (iVar1 != 0) {
    _printf(aForkProcdupThr,iVar1);
  }
  _thread_deallocate(*(undefined4 *)((int)register0x00000038 + -0x10));
  _compute_priority(*(undefined4 *)((int)register0x00000038 + -0x10),0);
  _bcopy(*(undefined4 *)(*(int *)(param_2 + 0x68) + 0x38),
         *(undefined4 *)(*(int *)((int)register0x00000038 + -0xc) + 0x38),0x294);
  _bzero(*(int *)(*(int *)((int)register0x00000038 + -0xc) + 0x38) + 0x244,0x18);
  iVar1 = *(int *)((int)register0x00000038 + -0xc);
  *(undefined4 *)(*(int *)(iVar1 + 0x38) + 0x158) = 0;
  iVar1 = *(int *)(iVar1 + 0x38);
  _expand_fdlist(iVar1,*(undefined4 *)(iVar1 + 0x154));
  _bcopy(*(undefined4 *)(*(int *)(*(int *)(param_2 + 0x68) + 0x38) + 0x14c),
         *(undefined4 *)(*(int *)(*(int *)((int)register0x00000038 + -0xc) + 0x38) + 0x14c),
         (*(int *)(*(int *)(*(int *)((int)register0x00000038 + -0xc) + 0x38) + 0x154) + 1) * 4);
  _bcopy(*(undefined4 *)(*(int *)(*(int *)(param_2 + 0x68) + 0x38) + 0x150),
         *(undefined4 *)(*(int *)(*(int *)((int)register0x00000038 + -0xc) + 0x38) + 0x150),
         *(int *)(*(int *)(*(int *)((int)register0x00000038 + -0xc) + 0x38) + 0x154) + 1);
  iVar1 = *(int *)((int)register0x00000038 + -0x10);
  **(int **)(*(int *)(iVar1 + 0xc) + 0x38) = param_1;
  _bzero(*(int *)(*(int *)(iVar1 + 0xc) + 0x38) + 0x16c,0x48);
  _bzero(*(int *)(*(int *)(*(int *)((int)register0x00000038 + -0x10) + 0xc) + 0x38) + 0x1b4,0x48);
  iVar1 = *(int *)((int)register0x00000038 + -0x10);
  *(undefined4 *)(*(int *)(*(int *)(iVar1 + 0xc) + 0x38) + 0x2c) = 0;
  return CONCAT44(param_2,iVar1);
}
