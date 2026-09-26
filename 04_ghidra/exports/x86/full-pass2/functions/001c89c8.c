/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001c89c8 */

uint FUN_001c89c8(char *param_1,char *param_2,char *param_3)

{
  char cVar1;
  int iVar2;
  char *pcVar3;
  
  if (param_2 == param_3) {
    return 1;
  }
  cVar1 = *param_1;
  if (cVar1 != '*') {
    if ('*' < cVar1) {
      if (cVar1 != '@') {
        return 0;
      }
      cVar1 = _objc_msgSend(param_2,PTR_s_isEqual__001f9838,param_3);
      return (int)cVar1;
    }
    if (cVar1 != '%') {
      return 0;
    }
  }
  pcVar3 = param_3;
  if ((param_2 != (char *)0x0) && (pcVar3 = param_2, param_3 != (char *)0x0)) {
    if (*param_3 != *param_2) {
      return 0;
    }
    iVar2 = _strcmp(param_2,param_3);
    return (uint)(iVar2 == 0);
  }
  iVar2 = -1;
  do {
    if (iVar2 == 0) break;
    iVar2 = iVar2 + -1;
    cVar1 = *pcVar3;
    pcVar3 = pcVar3 + 1;
  } while (cVar1 != '\0');
  return (uint)(iVar2 == -2);
}

