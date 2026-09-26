/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00146bc8 */

void _ipc_hash_local_insert(int param_1,uint param_2,undefined4 param_3)

{
  uint uVar1;
  
  uVar1 = (param_2 >> 6) % *(uint *)(param_1 + 0x18);
  while (*(int *)(*(int *)(param_1 + 0x14) + 0xc + uVar1 * 0x10) != 0) {
    uVar1 = uVar1 + 1;
    if (uVar1 == *(uint *)(param_1 + 0x18)) {
      uVar1 = 0;
    }
  }
  *(undefined4 *)(*(int *)(param_1 + 0x14) + 0xc + uVar1 * 0x10) = param_3;
  return;
}

