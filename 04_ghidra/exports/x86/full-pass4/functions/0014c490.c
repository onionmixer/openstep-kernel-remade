/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0014c490 */

undefined4 _ipc_port_dnrequest(int param_1,int param_2,int param_3,int *param_4)

{
  int *piVar1;
  int *piVar2;
  int iVar3;
  undefined4 uVar4;
  
  piVar2 = *(int **)(param_1 + 0x2c);
  if ((piVar2 == (int *)0x0) || (iVar3 = *piVar2, iVar3 == 0)) {
    uVar4 = 3;
  }
  else {
    piVar1 = piVar2 + iVar3 * 2;
    *piVar2 = *piVar1;
    piVar1[1] = param_2;
    *piVar1 = param_3;
    *param_4 = iVar3;
    uVar4 = 0;
  }
  return uVar4;
}

