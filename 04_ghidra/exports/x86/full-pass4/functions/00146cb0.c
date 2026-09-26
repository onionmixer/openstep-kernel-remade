/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00146cb0 */

void _ipc_hash_init(void)

{
  undefined4 *puVar1;
  uint uVar2;
  uint uVar3;
  
  if ((_ipc_hash_global_size == 0) &&
     (_ipc_hash_global_size = _ipc_tree_entry_max >> 8, _ipc_hash_global_size < 0x20)) {
    _ipc_hash_global_size = 0x20;
  }
  _ipc_hash_global_mask = _ipc_hash_global_size - 1;
  if ((_ipc_hash_global_mask & _ipc_hash_global_size) != 0) {
    uVar2 = 1;
    _ipc_hash_global_mask = _ipc_hash_global_mask | 1;
    while( true ) {
      _ipc_hash_global_size = _ipc_hash_global_mask + 1;
      if ((_ipc_hash_global_mask & _ipc_hash_global_size) == 0) break;
      uVar2 = uVar2 * 2;
      _ipc_hash_global_mask = _ipc_hash_global_mask | uVar2;
    }
  }
  puVar1 = (undefined4 *)_kalloc(_ipc_hash_global_size * 8);
  uVar2 = _ipc_hash_global_size;
  uVar3 = 0;
  _ipc_hash_global_table = puVar1;
  if (_ipc_hash_global_size != 0) {
    do {
      *puVar1 = 0;
      puVar1[1] = 0;
      puVar1 = puVar1 + 2;
      uVar3 = uVar3 + 1;
    } while (uVar3 < uVar2);
  }
  return;
}

