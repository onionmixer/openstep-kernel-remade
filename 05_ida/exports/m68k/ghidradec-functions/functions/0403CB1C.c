
void _ipc_hash_init(void)

{
  uint uVar1;
  undefined4 *puVar2;
  uint uVar3;
  
  if ((_ipc_hash_global_size == 0) &&
     (_ipc_hash_global_size = _ipc_tree_entry_max >> 8, _ipc_hash_global_size < 0x20)) {
    _ipc_hash_global_size = 0x20;
  }
  _ipc_hash_global_mask = _ipc_hash_global_size - 1;
  if ((_ipc_hash_global_mask & _ipc_hash_global_size) != 0) {
    uVar3 = 1;
    while( true ) {
      _ipc_hash_global_mask = uVar3 | _ipc_hash_global_mask;
      _ipc_hash_global_size = _ipc_hash_global_mask + 1;
      if ((_ipc_hash_global_mask & _ipc_hash_global_size) == 0) break;
      uVar3 = uVar3 * 2;
    }
  }
  puVar2 = (undefined4 *)_kalloc(_ipc_hash_global_size << 2);
  uVar1 = _ipc_hash_global_size;
  uVar3 = 0;
  _ipc_hash_global_table = puVar2;
  if (_ipc_hash_global_size != 0) {
    do {
      *puVar2 = 0;
      uVar3 = uVar3 + 1;
      puVar2 = puVar2 + 1;
    } while (uVar3 < uVar1);
  }
  return;
}

