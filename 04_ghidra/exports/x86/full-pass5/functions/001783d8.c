/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001783d8 */

void _vm_map_lookup_done(undefined4 param_1,int param_2)

{
  if ((*(byte *)(param_2 + 0x18) & 1) != 0) {
    _lock_done(*(undefined4 *)(param_2 + 0x10));
  }
  _lock_done(param_1);
  return;
}

