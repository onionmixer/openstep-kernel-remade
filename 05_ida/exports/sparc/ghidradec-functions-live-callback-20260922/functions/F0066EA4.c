
/* WARNING: Removing unreachable block (ram,0xf0066fe4) */
/* WARNING: Removing unreachable block (ram,0xf0066fb8) */
/* WARNING: Removing unreachable block (ram,0xf0066f4c) */
/* WARNING: Removing unreachable block (ram,0xf0066f04) */
/* WARNING: Removing unreachable block (ram,0xf0066f24) */
/* WARNING: Removing unreachable block (ram,0xf0066f8c) */
/* WARNING: Removing unreachable block (ram,0xf0066fd4) */
/* WARNING: Removing unreachable block (ram,0xf0066ff4) */
/* WARNING: Removing unreachable block (ram,0xf0066ebc) */

undefined8 _ipc_thread_terminate(int param_1,undefined4 param_2)

{
  int *piVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 uVar4;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
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
  do {
    do {
    } while (*(int *)(param_1 + 0xa8) != 0);
    piVar1 = (int *)(param_1 + 0xa8);
    _simple_lock_try();
  } while (piVar1 == (int *)0x0);
  iVar5 = *(int *)(param_1 + 0xac);
  if (iVar5 == 0) {
    *(undefined4 *)(param_1 + 0xa8) = 0;
    goto locret_F0066FFC;
  }
  *(undefined4 *)(param_1 + 0xac) = 0;
  *(undefined4 *)(param_1 + 0xa8) = 0;
  if (*(int *)(param_1 + 0xb0) == 0) {
loc_F0066F0C:
    iVar2 = *(int *)(param_1 + 0xb4);
  }
  else {
    if (*(int *)(param_1 + 0xb0) != -1) {
      _ipc_port_release_send();
      goto loc_F0066F0C;
    }
    iVar2 = *(int *)(param_1 + 0xb4);
  }
  if (iVar2 == 0) {
loc_F0066F2C:
    iVar2 = *(int *)(param_1 + 0xc0);
  }
  else {
    if (iVar2 != -1) {
      _ipc_port_release_send();
      goto loc_F0066F2C;
    }
    iVar2 = *(int *)(param_1 + 0xc0);
  }
  if (iVar2 == 0) {
loc_F0066F54:
    puVar3 = *(undefined4 **)(param_1 + 0xb8);
  }
  else {
    if (iVar2 != -1) {
      _ipc_port_dealloc_special(iVar2,_ipc_space_reply);
      goto loc_F0066F54;
    }
    puVar3 = *(undefined4 **)(param_1 + 0xb8);
  }
  if ((puVar3 != (undefined4 *)0x0) && (puVar3 != (undefined4 *)0xffffffff)) {
    param_1 = *(int *)(*(int *)(param_1 + 0xc) + 0x88);
    do {
      do {
      } while (*(int *)(param_1 + 8) != 0);
      piVar1 = (int *)(param_1 + 8);
      _simple_lock_try();
    } while (piVar1 == (int *)0x0);
    if (*(int *)(param_1 + 0xc) == 0) {
loc_F0066FE0:
      *(undefined4 *)(param_1 + 8) = 0;
    }
    else {
      iVar2 = param_1;
      _ipc_right_reverse(param_1,puVar3,(undefined *)((int)register0x00000038 + -0xc),
                         (undefined *)((int)register0x00000038 + -0x10));
      uVar4 = *(undefined4 *)((int)register0x00000038 + -0xc);
      if (iVar2 == 0) goto loc_F0066FE0;
      *puVar3 = 0;
      _ipc_right_destroy(param_1,uVar4,*(undefined4 *)((int)register0x00000038 + -0x10));
    }
    _ipc_port_release_send(puVar3);
  }
  _ipc_port_dealloc_special(iVar5,_ipc_space_kernel);
locret_F0066FFC:
  return CONCAT44(param_2,param_1);
}

