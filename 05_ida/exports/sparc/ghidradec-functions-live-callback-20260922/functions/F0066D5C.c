
/* WARNING: Removing unreachable block (ram,0xf0066dbc) */
/* WARNING: Removing unreachable block (ram,0xf0066d7c) */
/* WARNING: Removing unreachable block (ram,0xf0066d98) */
/* WARNING: Removing unreachable block (ram,0xf0066dd0) */
/* WARNING: Removing unreachable block (ram,0xf0066d64) */

undefined8 _ipc_thread_init(int param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 *puVar2;
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
  iVar1 = _ipc_space_kernel;
  _ipc_port_alloc_special();
  if (iVar1 == 0) {
    _panic(aIpcThreadInit);
    *(int *)(param_1 + 0x90) = param_1;
  }
  else {
    *(int *)(param_1 + 0x90) = param_1;
  }
  *(int *)(param_1 + 0x94) = param_1;
  *(undefined4 *)(param_1 + 0xa4) = 0;
  *(undefined4 *)(param_1 + 0xa8) = 0;
  *(int *)(param_1 + 0xac) = iVar1;
  _ipc_port_make_send();
  *(int *)(param_1 + 0xb0) = iVar1;
  *(undefined4 *)(param_1 + 0xb4) = 0;
  *(undefined4 *)(param_1 + 0xbc) = 0;
  *(undefined4 *)(param_1 + 0xc0) = 0;
  iVar1 = *(int *)(*(int *)(param_1 + 0xc) + 0x88);
  _ipc_port_alloc_compat
            (iVar1,(undefined *)((int)register0x00000038 + -0xc),
             (undefined *)((int)register0x00000038 + -0x10));
  if (iVar1 != 0) {
    _panic(aIpcThreadInit_0);
  }
  puVar2 = *(undefined4 **)((int)register0x00000038 + -0x10);
  puVar2[7] = puVar2[7] + 1;
  puVar2[1] = puVar2[1] + 1;
  *puVar2 = 0;
  *(undefined4 **)(param_1 + 0xb8) = puVar2;
  return CONCAT44(param_2,param_1);
}

