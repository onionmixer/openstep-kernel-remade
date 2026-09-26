/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00151910 */

void _ipc_splay_traverse_finish(undefined4 *param_1)

{
  if (param_1[1] != 0) {
    *param_1 = *(undefined4 *)(param_1[1] + 0x10);
    param_1[3] = param_1 + 2;
    param_1[5] = param_1 + 4;
  }
  return;
}

