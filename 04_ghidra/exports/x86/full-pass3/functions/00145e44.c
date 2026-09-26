/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00145e44 */

undefined4 _ipc_entry_tree_collision(int param_1,uint param_2)

{
  undefined4 uVar1;
  uint local_c;
  uint local_8;
  
  _ipc_splay_tree_bounds(param_1 + 0x20,param_2,&local_8,&local_c);
  uVar1 = 0;
  if (((local_8 != 0xffffffff) && (local_8 >> 8 == param_2 >> 8)) ||
     ((local_c != 0 && (local_c >> 8 == param_2 >> 8)))) {
    uVar1 = 1;
  }
  return uVar1;
}

