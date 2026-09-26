
/* WARNING: Removing unreachable block (ram,0xf0059e98) */
/* WARNING: Removing unreachable block (ram,0xf0059ee0) */
/* WARNING: Removing unreachable block (ram,0xf0059e60) */
/* WARNING: Removing unreachable block (ram,0xf0059eb4) */
/* WARNING: Removing unreachable block (ram,0xf0059f10) */
/* WARNING: Removing unreachable block (ram,0xf0059f3c) */
/* WARNING: Removing unreachable block (ram,0xf0059e38) */

undefined8
_ipc_object_copyout_name(int param_1,int *param_2,int param_3,undefined4 param_4,int param_5)

{
  int *piVar1;
  uint *puVar2;
  undefined4 unaff_l0;
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
  iVar3 = param_1;
  _ipc_entry_alloc_name(param_1,param_5,(undefined *)((int)register0x00000038 + -0xc));
  if (iVar3 != 0) goto locret_F0059F4C;
  if (param_3 == 0x12) {
loc_F0059EAC:
    iVar3 = param_1;
    _ipc_right_inuse(param_1,param_5,*(undefined4 *)((int)register0x00000038 + -0xc));
    if (iVar3 != 0) {
      iVar3 = 0xd;
      goto locret_F0059F4C;
    }
    do {
      do {
      } while (*param_2 != 0);
      piVar1 = param_2;
      _simple_lock_try();
    } while (piVar1 == (int *)0x0);
    if (-1 < param_2[2]) {
      *param_2 = 0;
      _ipc_entry_dealloc(param_1,param_5,*(undefined4 *)((int)register0x00000038 + -0xc));
      *(undefined4 *)(param_1 + 8) = 0;
      iVar3 = 0x14;
      goto locret_F0059F4C;
    }
    *(int **)(*(int *)((int)register0x00000038 + -0xc) + 4) = param_2;
  }
  else {
    iVar3 = param_1;
    _ipc_right_reverse(param_1,param_2,(undefined *)((int)register0x00000038 + -0x10),
                       (undefined *)((int)register0x00000038 + -0x14));
    if (iVar3 == 0) goto loc_F0059EAC;
    puVar2 = *(uint **)((int)register0x00000038 + -0xc);
    if (param_5 != *(int *)((int)register0x00000038 + -0x10)) {
      *param_2 = 0;
      if ((*puVar2 & 0x1f0000) == 0) {
        _ipc_entry_dealloc(param_1,param_5);
      }
      *(undefined4 *)(param_1 + 8) = 0;
      iVar3 = 0x15;
      goto locret_F0059F4C;
    }
  }
  iVar3 = param_1;
  _ipc_right_copyout(param_1,param_5,*(undefined4 *)((int)register0x00000038 + -0xc),param_3,param_4
                     ,param_2);
  *(undefined4 *)(param_1 + 8) = 0;
locret_F0059F4C:
  return CONCAT44(param_2,iVar3);
}

