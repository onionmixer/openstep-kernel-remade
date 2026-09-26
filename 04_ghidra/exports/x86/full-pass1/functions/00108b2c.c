/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00108b2c */

void _ruadd(int param_1,int param_2)

{
  int *piVar1;
  int *piVar2;
  int iVar3;
  
  _timevaladd(param_1,param_2);
  _timevaladd(param_1 + 8,param_2 + 8);
  if (*(int *)(param_1 + 0x10) < *(int *)(param_2 + 0x10)) {
    *(int *)(param_1 + 0x10) = *(int *)(param_2 + 0x10);
  }
  piVar1 = (int *)(param_1 + 0x14);
  piVar2 = (int *)(param_2 + 0x14);
  iVar3 = 0xc;
  do {
    *piVar1 = *piVar1 + *piVar2;
    piVar2 = piVar2 + 1;
    piVar1 = piVar1 + 1;
    iVar3 = iVar3 + -1;
  } while (0 < iVar3);
  return;
}

