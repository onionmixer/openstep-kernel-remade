/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0016a30c */

int _timer_delta(int *param_1,int *param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  do {
    iVar1 = param_1[1];
    iVar2 = *param_1;
  } while (param_1[2] != iVar1);
  iVar3 = param_2[1];
  iVar4 = *param_2;
  param_2[1] = iVar1;
  *param_2 = iVar2;
  return ((iVar1 - iVar3) * 1000000 + iVar2) - iVar4;
}

