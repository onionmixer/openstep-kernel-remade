
/* WARNING: Removing unreachable block (ram,0xf005a0c4) */
/* WARNING: Removing unreachable block (ram,0xf005a068) */
/* WARNING: Removing unreachable block (ram,0xf005a08c) */
/* WARNING: Removing unreachable block (ram,0xf005a0a8) */
/* WARNING: Removing unreachable block (ram,0xf005a04c) */

undefined8 _ipc_object_rename(int param_1,int param_2,int param_3)

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
  iVar1 = param_1;
  _ipc_entry_alloc_name(param_1,param_3,(undefined *)((int)register0x00000038 + -0xc));
  if (iVar1 == 0) {
    iVar1 = param_1;
    _ipc_right_inuse(param_1,param_3,*(undefined4 *)((int)register0x00000038 + -0xc));
    if (iVar1 == 0) {
      if ((param_2 == param_3) || (iVar1 = param_1, _ipc_entry_lookup(param_1,param_2), iVar1 == 0))
      {
        _ipc_entry_dealloc(param_1,param_3,*(undefined4 *)((int)register0x00000038 + -0xc));
        *(undefined4 *)(param_1 + 8) = 0;
        iVar1 = 0xf;
      }
      else {
        _ipc_right_rename(param_1,param_2,iVar1,param_3,
                          *(undefined4 *)((int)register0x00000038 + -0xc));
        iVar1 = param_1;
      }
    }
    else {
      iVar1 = 0xd;
    }
  }
  return CONCAT44(param_2,iVar1);
}
