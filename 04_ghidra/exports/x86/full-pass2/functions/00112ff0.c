/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00112ff0 */

int _ndqb(int *param_1,uint param_2)

{
  char *pcVar1;
  int iVar2;
  undefined4 uVar3;
  char *pcVar4;
  int iVar5;
  
  uVar3 = _spltty();
  iVar2 = *param_1;
  if (iVar2 < 1) {
    iVar5 = -iVar2;
  }
  else {
    pcVar4 = (char *)param_1[1];
    iVar5 = ((uint)(pcVar4 + 0x34) & 0xffffffc0) - (int)pcVar4;
    if (iVar2 < iVar5) {
      iVar5 = iVar2;
    }
    if (param_2 != 0) {
      pcVar1 = pcVar4 + iVar5;
      for (; pcVar4 < pcVar1; pcVar4 = pcVar4 + 1) {
        if ((param_2 & (int)*pcVar4) != 0) {
          iVar5 = (int)pcVar4 - param_1[1];
          break;
        }
      }
    }
  }
  _splx(uVar3);
  return iVar5;
}

