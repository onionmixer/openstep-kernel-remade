
/* WARNING: Removing unreachable block (ram,0xf0054a6c) */

undefined8 _ipc_hash_init(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
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
  if ((_ipc_hash_global_size == 0) &&
     (_ipc_hash_global_size = _ipc_tree_entry_max >> 8, _ipc_hash_global_size < 0x20)) {
    _ipc_hash_global_size = 0x20;
  }
  _ipc_hash_global_mask = _ipc_hash_global_size - 1;
  if ((_ipc_hash_global_size & _ipc_hash_global_mask) != 0) {
    uVar3 = 1;
    for (_ipc_hash_global_mask = _ipc_hash_global_mask | 1;
        _ipc_hash_global_size = _ipc_hash_global_mask + 1,
        (_ipc_hash_global_size & _ipc_hash_global_mask) != 0;
        _ipc_hash_global_mask = _ipc_hash_global_mask | uVar3) {
      uVar3 = uVar3 << 1;
    }
  }
  iVar1 = _ipc_hash_global_size << 3;
  _kalloc();
  uVar3 = _ipc_hash_global_size;
  uVar2 = 0;
  iVar4 = iVar1;
  _ipc_hash_global_table = iVar1;
  if (_ipc_hash_global_size != 0) {
    do {
      *(undefined4 *)(iVar1 + uVar2 * 8) = 0;
      *(undefined4 *)(iVar4 + 4) = 0;
      uVar2 = uVar2 + 1;
      iVar4 = iVar4 + 8;
    } while (uVar2 < uVar3);
  }
  return CONCAT44(param_2,param_1);
}

