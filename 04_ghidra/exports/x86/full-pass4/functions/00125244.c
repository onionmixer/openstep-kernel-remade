/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00125244 */

void _in_pcbdisconnect(int param_1)

{
  *(undefined4 *)(param_1 + 0xc) = 0;
  *(undefined2 *)(param_1 + 0x10) = 0;
  if ((*(byte *)(*(int *)(param_1 + 0x1c) + 6) & 1) != 0) {
    _in_pcbdetach(param_1);
  }
  return;
}

