
/* WARNING: Removing unreachable block (ram,0xf0066d3c) */
/* WARNING: Removing unreachable block (ram,0xf0066cfc) */
/* WARNING: Removing unreachable block (ram,0xf0066cbc) */
/* WARNING: Removing unreachable block (ram,0xf0066cdc) */
/* WARNING: Removing unreachable block (ram,0xf0066d28) */
/* WARNING: Removing unreachable block (ram,0xf0066d4c) */
/* WARNING: Removing unreachable block (ram,0xf0066c74) */

undefined8 _ipc_task_terminate(int param_1,undefined4 param_2)

{
  int *piVar1;
  int iVar2;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  int iVar3;
  int iVar4;
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
    } while (*(int *)(param_1 + 100) != 0);
    piVar1 = (int *)(param_1 + 100);
    _simple_lock_try();
  } while (piVar1 == (int *)0x0);
  iVar4 = *(int *)(param_1 + 0x68);
  if (iVar4 == 0) {
    *(undefined4 *)(param_1 + 100) = 0;
    goto locret_F0066D54;
  }
  *(undefined4 *)(param_1 + 0x68) = 0;
  *(undefined4 *)(param_1 + 100) = 0;
  if (*(int *)(param_1 + 0x6c) == 0) {
loc_F0066CC4:
    iVar2 = *(int *)(param_1 + 0x70);
  }
  else {
    if (*(int *)(param_1 + 0x6c) != -1) {
      _ipc_port_release_send();
      goto loc_F0066CC4;
    }
    iVar2 = *(int *)(param_1 + 0x70);
  }
  if (iVar2 == 0) {
loc_F0066CE4:
    iVar2 = *(int *)(param_1 + 0x74);
  }
  else {
    if (iVar2 != -1) {
      _ipc_port_release_send();
      goto loc_F0066CE4;
    }
    iVar2 = *(int *)(param_1 + 0x74);
  }
  if ((iVar2 != 0) && (iVar2 != -1)) {
    _ipc_port_release_send();
  }
  iVar3 = 0;
  iVar2 = param_1;
  do {
    iVar3 = iVar3 + 1;
    if ((*(int *)(iVar2 + 0x78) != 0) && (*(int *)(iVar2 + 0x78) != -1)) {
      _ipc_port_release_send();
    }
    iVar2 = iVar2 + 4;
  } while (iVar3 < 4);
  _ipc_space_destroy(*(undefined4 *)(param_1 + 0x88));
  _ipc_port_dealloc_special(iVar4,_ipc_space_kernel);
locret_F0066D54:
  return CONCAT44(param_2,param_1);
}

