/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00146f98 */

void _ipc_kmsg_rmqueue(int *param_1,int *param_2)

{
  int *piVar1;
  int *piVar2;
  
  piVar1 = (int *)*param_2;
  piVar2 = (int *)param_2[1];
  if (piVar1 == param_2) {
    *param_1 = 0;
  }
  else {
    if ((int *)*param_1 == param_2) {
      *param_1 = (int)piVar1;
    }
    piVar1[1] = (int)piVar2;
    *piVar2 = (int)piVar1;
  }
  return;
}

