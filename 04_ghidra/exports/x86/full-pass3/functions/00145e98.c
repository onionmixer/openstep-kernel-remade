/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00145e98 */

uint * _ipc_entry_lookup(int param_1,uint param_2)

{
  uint uVar1;
  uint *puVar2;
  
  if (param_2 >> 8 < *(uint *)(param_1 + 0x18)) {
    puVar2 = (uint *)(*(int *)(param_1 + 0x14) + (param_2 >> 8) * 0x10);
    uVar1 = *puVar2;
    if ((uVar1 & 0xff000000) == param_2 << 0x18) {
      if ((uVar1 & 0x1f0000) == 0) {
        return (uint *)0x0;
      }
      return puVar2;
    }
    uVar1 = uVar1 & 0x800000;
  }
  else {
    uVar1 = *(uint *)(param_1 + 0x38);
  }
  if (uVar1 == 0) {
    return (uint *)0x0;
  }
  puVar2 = (uint *)_ipc_splay_tree_lookup(param_1 + 0x20,param_2);
  return puVar2;
}

