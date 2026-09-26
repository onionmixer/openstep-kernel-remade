/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001ccab0 */

bool __mapStrIsEqual(undefined4 param_1,char *param_2,char *param_3)

{
  char cVar1;
  int iVar2;
  char *pcVar3;
  bool bVar4;
  
  if (param_2 == param_3) {
    bVar4 = true;
  }
  else {
    pcVar3 = param_3;
    if ((param_2 == (char *)0x0) || (pcVar3 = param_2, param_3 == (char *)0x0)) {
      iVar2 = -1;
      do {
        if (iVar2 == 0) break;
        iVar2 = iVar2 + -1;
        cVar1 = *pcVar3;
        pcVar3 = pcVar3 + 1;
      } while (cVar1 != '\0');
      bVar4 = iVar2 == -2;
    }
    else if (*param_3 == *param_2) {
      iVar2 = _strcmp(param_2,param_3);
      bVar4 = iVar2 == 0;
    }
    else {
      bVar4 = false;
    }
  }
  return bVar4;
}

