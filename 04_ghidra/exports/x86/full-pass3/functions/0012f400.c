/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0012f400 */

void _setdiropargs(void *param_1,undefined4 param_2,int param_3)

{
  _bcopy((void *)(*(int *)(param_3 + 0x30) + 0x40),param_1,0x20);
  *(undefined4 *)((int)param_1 + 0x20) = param_2;
  return;
}

