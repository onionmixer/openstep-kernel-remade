
/* WARNING: Removing unreachable block (ram,0xf0059dd4) */
/* WARNING: Removing unreachable block (ram,0xf0059da8) */
/* WARNING: Removing unreachable block (ram,0xf0059d50) */
/* WARNING: Removing unreachable block (ram,0xf0059d6c) */
/* WARNING: Removing unreachable block (ram,0xf0059e04) */
/* WARNING: Removing unreachable block (ram,0xf0059d80) */
/* WARNING: Removing unreachable block (ram,0xf0059d10) */

undefined8
_ipc_object_copyout(int param_1,int *param_2,int param_3,undefined4 param_4,undefined4 *param_5)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
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
  do {
    do {
    } while (*(int *)(param_1 + 8) != 0);
    piVar1 = (int *)(param_1 + 8);
    _simple_lock_try();
  } while (piVar1 == (int *)0x0);
  iVar2 = *(int *)(param_1 + 0xc);
  while (iVar2 != 0) {
    iVar2 = param_1;
    if ((param_3 != 0x12) &&
       (iVar3 = param_1,
       _ipc_right_reverse(param_1,param_2,(undefined *)((int)register0x00000038 + -0xc),
                          (undefined *)((int)register0x00000038 + -0x10)), iVar3 != 0))
    goto loc_F0059DF4;
    iVar3 = param_1;
    _ipc_entry_get(param_1,(undefined *)((int)register0x00000038 + -0xc),
                   (undefined *)((int)register0x00000038 + -0x10));
    if (iVar3 == 0) goto loc_F0059D98;
    _ipc_entry_grow_table();
    if (iVar2 != 0) goto locret_F0059E24;
    iVar2 = *(int *)(param_1 + 0xc);
  }
  *(undefined4 *)(param_1 + 8) = 0;
  iVar2 = 0x10;
locret_F0059E24:
  return CONCAT44(param_2,iVar2);
loc_F0059D98:
  do {
    do {
    } while (*param_2 != 0);
    piVar1 = param_2;
    _simple_lock_try();
  } while (piVar1 == (int *)0x0);
  uVar4 = *(undefined4 *)((int)register0x00000038 + -0xc);
  if (param_2[2] < 0) {
    *(int **)(*(int *)((int)register0x00000038 + -0x10) + 4) = param_2;
loc_F0059DF4:
    _ipc_right_copyout(param_1,*(undefined4 *)((int)register0x00000038 + -0xc),
                       *(undefined4 *)((int)register0x00000038 + -0x10),param_3,param_4,param_2);
    *(undefined4 *)(param_1 + 8) = 0;
    if (iVar2 == 0) {
      *param_5 = *(undefined4 *)((int)register0x00000038 + -0xc);
    }
  }
  else {
    *param_2 = 0;
    _ipc_entry_dealloc(param_1,uVar4,*(undefined4 *)((int)register0x00000038 + -0x10));
    *(undefined4 *)(param_1 + 8) = 0;
    iVar2 = 0x14;
  }
  goto locret_F0059E24;
}
