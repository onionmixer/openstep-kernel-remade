
/* WARNING: Removing unreachable block (ram,0xf005bf2c) */
/* WARNING: Removing unreachable block (ram,0xf005bf10) */
/* WARNING: Removing unreachable block (ram,0xf005bf24) */
/* WARNING: Removing unreachable block (ram,0xf005bf50) */
/* WARNING: Removing unreachable block (ram,0xf005beb8) */

undefined8 _ipc_right_check(undefined4 param_1,int *param_2,undefined4 param_3,uint *param_4)

{
  int *piVar1;
  undefined4 unaff_l0;
  uint uVar2;
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
  do {
    do {
    } while (*param_2 != 0);
    piVar1 = param_2;
    _simple_lock_try();
  } while (piVar1 == (int *)0x0);
  if (param_2[2] < 0) {
    uVar3 = 0;
  }
  else {
    *param_2 = 0;
    uVar2 = *param_4;
    if ((uVar2 & 0x10000) != 0) {
      if ((uVar2 & 0x200000) != 0) {
        uVar2 = uVar2 & 0xffdfffff;
        _ipc_marequest_cancel(param_1,param_3);
      }
      _ipc_hash_delete(param_1,param_2,param_3,param_4);
    }
    _ipc_object_release(param_2);
    if ((uVar2 & 0x400000) == 0) {
      uVar2 = uVar2 & 0xffe0ffff | 0x100000;
      if (param_4[2] != 0) {
        param_4[2] = 0;
        uVar2 = uVar2 + 1;
      }
      *param_4 = uVar2;
      param_4[1] = 0;
      uVar3 = 1;
    }
    else {
      param_4[2] = 0;
      param_4[1] = 0;
      _ipc_entry_dealloc(param_1,param_3,param_4);
      uVar3 = 1;
    }
  }
  return CONCAT44(param_2,uVar3);
}

