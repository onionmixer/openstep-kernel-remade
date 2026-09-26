/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00161f10 */

void _insque(void *param_1,void *param_2)

{
  *(undefined4 *)param_1 = *(undefined4 *)param_2;
  *(void **)((int)param_1 + 4) = param_2;
  *(void **)(*(int *)param_2 + 4) = param_1;
  *(void **)param_2 = param_1;
  return;
}

