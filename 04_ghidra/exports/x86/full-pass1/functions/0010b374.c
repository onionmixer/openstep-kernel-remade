/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0010b374 */

undefined4 _itimerdecr(int *param_1,int param_2)

{
  int iVar1;
  int iVar2;
  
  iVar2 = param_1[3];
  if (iVar2 < param_2) {
    if (param_1[2] == 0) {
      iVar2 = param_2 - iVar2;
      goto LAB_0010b3b8;
    }
    param_1[3] = iVar2 + 1000000;
    param_1[2] = param_1[2] + -1;
  }
  iVar1 = param_1[3];
  param_1[3] = iVar1 - param_2;
  iVar2 = 0;
  if ((param_1[2] != 0) || (iVar1 - param_2 != 0)) {
    return 1;
  }
LAB_0010b3b8:
  if ((*param_1 == 0) && (param_1[1] == 0)) {
    param_1[3] = 0;
  }
  else {
    param_1[2] = *param_1;
    param_1[3] = param_1[1];
    iVar2 = param_1[3] - iVar2;
    param_1[3] = iVar2;
    if (iVar2 < 0) {
      param_1[3] = iVar2 + 1000000;
      param_1[2] = param_1[2] + -1;
    }
  }
  return 0;
}

