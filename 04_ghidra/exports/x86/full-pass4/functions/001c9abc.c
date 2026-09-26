/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001c9abc */

int FUN_001c9abc(int param_1,undefined4 param_2,uint param_3,int param_4)

{
  int iVar1;
  int *piVar2;
  
  if (param_4 == 0) {
    return 0;
  }
  if (param_3 < *(uint *)(param_1 + 8)) {
    piVar2 = (int *)(param_3 * 4 + *(int *)(param_1 + 4));
    iVar1 = *piVar2;
    *piVar2 = param_4;
    return iVar1;
  }
  return 0;
}

