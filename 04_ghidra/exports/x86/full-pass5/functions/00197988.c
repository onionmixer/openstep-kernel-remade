/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00197988 */

char * _kmLocalizeString(char *param_1)

{
  char *pcVar1;
  int iVar2;
  undefined **ppuVar3;
  int iVar4;
  uint uVar5;
  
  uVar5 = _glLanguage;
  if (6 < _glLanguage) {
    uVar5 = 0;
  }
  if (_kmLocalizedStrings != (undefined *)0x0) {
    ppuVar3 = &_kmLocalizedStrings;
    iVar4 = 0;
    do {
      iVar2 = _strcmp(*ppuVar3,param_1);
      if (iVar2 == 0) {
        pcVar1 = *(char **)((int)&_kmLocalizedStrings + uVar5 * 4 + iVar4);
        if (pcVar1 == (char *)0x0) {
          return param_1;
        }
        return pcVar1;
      }
      ppuVar3 = ppuVar3 + 7;
      iVar4 = iVar4 + 0x1c;
    } while (*ppuVar3 != (undefined *)0x0);
  }
  return param_1;
}

