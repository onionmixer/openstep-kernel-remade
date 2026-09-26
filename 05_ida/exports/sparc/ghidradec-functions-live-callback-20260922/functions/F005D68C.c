
/* WARNING: Removing unreachable block (ram,0xf005d854) */
/* WARNING: Removing unreachable block (ram,0xf005d7d8) */
/* WARNING: Removing unreachable block (ram,0xf005d830) */
/* WARNING: Removing unreachable block (ram,0xf005d6d4) */
/* WARNING: Removing unreachable block (ram,0xf005d724) */
/* WARNING: Removing unreachable block (ram,0xf005d7c4) */
/* WARNING: Removing unreachable block (ram,0xf005d7fc) */
/* WARNING: Removing unreachable block (ram,0xf005d868) */
/* WARNING: Removing unreachable block (ram,0xf005d6b0) */

undefined8 _ipc_right_rename(int param_1,undefined4 param_2,uint *param_3,int param_4,uint *param_5)

{
  int iVar1;
  int *piVar2;
  undefined4 unaff_l0;
  int *piVar3;
  undefined4 unaff_l1;
  uint uVar4;
  uint uVar5;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 uVar6;
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
  uVar5 = *param_3;
  uVar4 = param_3[2];
  piVar3 = (int *)param_3[1];
  if (uVar4 != 0) {
    iVar1 = param_1;
    _ipc_right_check(param_1,piVar3,param_2,param_3);
    if (iVar1 == 0) {
      *(int *)(piVar3[0xb] + uVar4 * 8 + 4) = param_4;
      *piVar3 = 0;
      param_3[2] = 0;
    }
    else {
      if ((uVar5 & 0x400000) != 0) {
        _ipc_entry_dealloc(param_1,param_4,param_5);
        *(undefined4 *)(param_1 + 8) = 0;
        uVar6 = 0xf;
        goto locret_F005D878;
      }
      uVar5 = *param_3;
      uVar4 = 0;
      piVar3 = (int *)0x0;
    }
  }
  if ((uVar5 & 0x200000) != 0) {
    _ipc_marequest_rename(param_1,param_2,param_4);
  }
  param_5[2] = uVar4;
  param_5[1] = (uint)piVar3;
  uVar4 = uVar5 & 0x1f0000;
  *param_5 = *param_5 | uVar5 & 0x7fffff;
  if (uVar4 == 0x30000) {
loc_F005D7EC:
    do {
      do {
      } while (*piVar3 != 0);
      piVar2 = piVar3;
      _simple_lock_try();
    } while (piVar2 == (int *)0x0);
    piVar3[4] = param_4;
    *piVar3 = 0;
    param_3[1] = 0;
  }
  else if (uVar4 < 0x30001) {
    if (uVar4 == 0x10000) {
      _ipc_hash_delete(param_1,piVar3,param_2,param_3);
      _ipc_hash_insert(param_1,piVar3,param_4,param_5);
      param_3[1] = 0;
    }
    else {
      if (uVar4 == 0x20000) goto loc_F005D7EC;
loc_F005D854:
      _panic(aIpcRightRename);
      param_3[1] = 0;
    }
  }
  else if (uVar4 == 0x80000) {
    do {
      do {
      } while (*piVar3 != 0);
      piVar2 = piVar3;
      _simple_lock_try();
    } while (piVar2 == (int *)0x0);
    piVar3[3] = param_4;
    *piVar3 = 0;
    param_3[1] = 0;
  }
  else {
    uVar5 = 0x100000;
    if (uVar4 < 0x80001) {
      uVar5 = 0x40000;
    }
    if (uVar4 != uVar5) goto loc_F005D854;
    param_3[1] = 0;
  }
  _ipc_entry_dealloc(param_1,param_2,param_3);
  *(undefined4 *)(param_1 + 8) = 0;
  uVar6 = 0;
locret_F005D878:
  return CONCAT44(param_2,uVar6);
}

