
/* WARNING: Removing unreachable block (ram,0xf0054cc4) */
/* WARNING: Removing unreachable block (ram,0xf0054cb4) */
/* WARNING: Removing unreachable block (ram,0xf0054ca0) */
/* WARNING: Removing unreachable block (ram,0xf0054c7c) */
/* WARNING: Removing unreachable block (ram,0xf0054c30) */
/* WARNING: Removing unreachable block (ram,0xf0054be8) */
/* WARNING: Removing unreachable block (ram,0xf0054bc4) */
/* WARNING: Removing unreachable block (ram,0xf0054c04) */
/* WARNING: Removing unreachable block (ram,0xf0054c50) */
/* WARNING: Removing unreachable block (ram,0xf0054c94) */
/* WARNING: Removing unreachable block (ram,0xf0054cac) */
/* WARNING: Removing unreachable block (ram,0xf0054cbc) */
/* WARNING: Removing unreachable block (ram,0xf0054ccc) */
/* WARNING: Removing unreachable block (ram,0xf0054ba8) */

undefined8 _ipc_bootstrap(undefined4 param_1,undefined4 param_2)

{
  undefined4 uVar1;
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
  _ipc_port_multiple_lock_data = 0;
  _ipc_port_timestamp_lock_data = 0;
  _ipc_port_timestamp_data = 0;
  uVar1 = 0x48;
  _zinit(0x48,_ipc_space_max * 0x48,0x48,0,aIpcSpaces);
  _ipc_space_zone = uVar1;
  _zchange();
  uVar1 = 0x20;
  _zinit(0x20,_ipc_tree_entry_max << 5,0x20,0,aIpcTreeEntries);
  _ipc_tree_entry_zone = uVar1;
  _zchange();
  uVar1 = 0x50;
  _zinit(0x50,_ipc_port_max * 0x50,0x50,0,aIpcPorts);
  _ipc_object_zones = uVar1;
  _zchange();
  uVar1 = 0x1c;
  _zinit(0x1c,_ipc_pset_max * 0x1c,0x1c,0,aIpcPortSets);
  DAT_f013bf04 = uVar1;
  _zchange();
  _ipc_space_create_special(&_ipc_space_kernel);
  _ipc_space_create_special(&_ipc_space_reply);
  _ipc_table_init();
  _ipc_notify_init();
  _ipc_hash_init();
  _ipc_marequest_init();
  return CONCAT44(param_2,param_1);
}

