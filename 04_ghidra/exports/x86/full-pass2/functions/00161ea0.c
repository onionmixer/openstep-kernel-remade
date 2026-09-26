/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00161ea0 */

int * _dequeue_head(int *param_1)

{
  int *piVar1;
  
  piVar1 = (int *)*param_1;
  if (piVar1 == param_1) {
    piVar1 = (int *)0x0;
  }
  else {
    *(int **)(*piVar1 + 4) = param_1;
    *param_1 = *piVar1;
  }
  return piVar1;
}

