
/* WARNING: Removing unreachable block (ram,0xf0066b98) */
/* WARNING: Removing unreachable block (ram,0xf0066b5c) */
/* WARNING: Removing unreachable block (ram,0xf0066af8) */
/* WARNING: Removing unreachable block (ram,0xf0066ad8) */
/* WARNING: Removing unreachable block (ram,0xf0066ae4) */
/* WARNING: Removing unreachable block (ram,0xf0066b08) */
/* WARNING: Removing unreachable block (ram,0xf0066b7c) */
/* WARNING: Removing unreachable block (ram,0xf0066ba4) */
/* WARNING: Removing unreachable block (ram,0xf0066ac0) */

undefined8 _ipc_task_init(int param_1,int param_2)

{
  int iVar1;
  int *piVar2;
  undefined4 uVar3;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  int iVar4;
  int iVar5;
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
  iVar1 = _ipc_table_entries;
  _ipc_space_create(_ipc_table_entries,(undefined *)((int)register0x00000038 + -0xc));
  if (iVar1 != 0) {
    _panic(aIpcTaskInit);
  }
  iVar1 = _ipc_space_kernel;
  _ipc_port_alloc_special();
  if (iVar1 == 0) {
    _panic(aIpcTaskInit_0);
  }
  *(undefined4 *)(param_1 + 100) = 0;
  *(int *)(param_1 + 0x68) = iVar1;
  _ipc_port_make_send();
  *(int *)(param_1 + 0x6c) = iVar1;
  *(undefined4 *)(param_1 + 0x88) = *(undefined4 *)((int)register0x00000038 + -0xc);
  if (param_2 == 0) {
    *(undefined4 *)(param_1 + 0x70) = 0;
    *(undefined4 *)(param_1 + 0x74) = 0;
    *(undefined4 *)(param_1 + 0x84) = 0;
    iVar1 = param_1 + 0xc;
    while (param_1 <= iVar1 + -4) {
      *(undefined4 *)(iVar1 + 0x74) = 0;
      iVar1 = iVar1 + -4;
    }
  }
  else {
    do {
      do {
      } while (*(int *)(param_2 + 100) != 0);
      piVar2 = (int *)(param_2 + 100);
      _simple_lock_try();
      iVar5 = 0;
      iVar1 = param_2;
      iVar4 = param_1;
    } while (piVar2 == (int *)0x0);
    do {
      uVar3 = *(undefined4 *)(iVar1 + 0x78);
      iVar5 = iVar5 + 1;
      _ipc_port_copy_send();
      *(undefined4 *)(iVar4 + 0x78) = uVar3;
      iVar1 = iVar1 + 4;
      iVar4 = iVar4 + 4;
    } while (iVar5 < 4);
    uVar3 = *(undefined4 *)(param_2 + 0x70);
    _ipc_port_copy_send();
    *(undefined4 *)(param_1 + 0x70) = uVar3;
    uVar3 = *(undefined4 *)(param_2 + 0x74);
    _ipc_port_copy_send();
    *(undefined4 *)(param_1 + 0x74) = uVar3;
    *(undefined4 *)(param_2 + 100) = 0;
  }
  return CONCAT44(param_2,param_1);
}

