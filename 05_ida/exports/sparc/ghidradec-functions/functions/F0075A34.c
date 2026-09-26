
/* WARNING: Removing unreachable block (ram,0xf0075a5c) */
/* WARNING: Removing unreachable block (ram,0xf0075a44) */
/* WARNING: Removing unreachable block (ram,0xf0075a50) */
/* WARNING: Removing unreachable block (ram,0xf0075a78) */
/* WARNING: Removing unreachable block (ram,0xf0075a3c) */

undefined8 _kernel_thread(undefined4 param_1,undefined4 param_2,undefined4 param_3)

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
  _thread_create(param_1,(undefined *)((int)register0x00000038 + -0xc));
  _thread_deallocate(*(undefined4 *)((int)register0x00000038 + -0xc));
  _thread_start(*(undefined4 *)((int)register0x00000038 + -0xc),param_2);
  *(undefined4 *)(*(int *)((int)register0x00000038 + -0xc) + 0xc4) = param_3;
  _thread_doswapin();
  iVar1 = *(int *)((int)register0x00000038 + -0xc);
  *(undefined4 *)(iVar1 + 0x54) = 0x1f;
  *(undefined4 *)(iVar1 + 0x50) = 0x18;
  *(undefined4 *)(iVar1 + 0x58) = 0x18;
  _thread_resume();
  return CONCAT44(param_2,*(undefined4 *)((int)register0x00000038 + -0xc));
}

