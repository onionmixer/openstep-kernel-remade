/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00161e7c */

void _enqueue_tail(int param_1,int *param_2)

{
  *param_2 = param_1;
  param_2[1] = *(int *)(param_1 + 4);
  *(int **)param_2[1] = param_2;
  *(int **)(param_1 + 4) = param_2;
  return;
}

