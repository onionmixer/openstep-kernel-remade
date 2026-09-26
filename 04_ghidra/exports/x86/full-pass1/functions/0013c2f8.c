/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0013c2f8 */

int _hashalloc(int param_1,int param_2,undefined4 param_3,undefined4 param_4,code *param_5)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  iVar1 = *(int *)(param_1 + 0x50);
  iVar2 = (*param_5)(param_1,param_2,param_3,param_4);
  if (iVar2 == 0) {
    iVar4 = param_2;
    for (iVar2 = 1; iVar3 = *(int *)(iVar1 + 0x2c), iVar2 < iVar3; iVar2 = iVar2 * 2) {
      iVar4 = iVar4 + iVar2;
      if (iVar3 <= iVar4) {
        iVar4 = iVar4 - iVar3;
      }
      iVar3 = (*param_5)(param_1,iVar4,0,param_4);
      if (iVar3 != 0) {
        return iVar3;
      }
    }
    iVar2 = (param_2 + 2) % *(int *)(iVar1 + 0x2c);
    iVar4 = 2;
    if (2 < *(int *)(iVar1 + 0x2c)) {
      do {
        iVar3 = (*param_5)(param_1,iVar2,0,param_4);
        if (iVar3 != 0) {
          return iVar3;
        }
        iVar2 = iVar2 + 1;
        if (iVar2 == *(int *)(iVar1 + 0x2c)) {
          iVar2 = 0;
        }
        iVar4 = iVar4 + 1;
      } while (iVar4 < *(int *)(iVar1 + 0x2c));
    }
    iVar2 = 0;
  }
  return iVar2;
}

