/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0010ef4c */

void _ttylclose(int param_1)

{
  _ttywait(param_1);
  _ttyflush(param_1,1);
  *(undefined1 *)(param_1 + 0x47) = 0;
  return;
}

