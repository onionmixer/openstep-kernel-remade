/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0014c650 */

int _ipc_port_dncancel(int param_1,undefined4 param_2,int param_3)

{
  int *piVar1;
  int *piVar2;
  int iVar3;
  
  piVar2 = *(int **)(param_1 + 0x2c);
  piVar1 = piVar2 + param_3 * 2;
  iVar3 = *piVar1;
  piVar1[1] = 0;
  *piVar1 = *piVar2;
  *piVar2 = param_3;
  return iVar3;
}

