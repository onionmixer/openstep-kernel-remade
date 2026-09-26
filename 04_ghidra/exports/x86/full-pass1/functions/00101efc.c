/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00101efc */

int _strncmp(char *param_1,char *param_2,size_t param_3)

{
  size_t sVar1;
  char *pcVar2;
  char *pcVar3;
  
  while( true ) {
    if ((int)param_3 < 1) {
      return 0;
    }
    sVar1 = param_3;
    pcVar2 = param_1;
    pcVar3 = param_2;
    if ((*param_1 == '\0') || (*param_1 != *param_2)) break;
    pcVar2 = param_1 + 1;
    pcVar3 = param_2 + 1;
    sVar1 = param_3 - 1;
    if ((int)sVar1 < 1) {
      return 0;
    }
    if ((*pcVar2 == '\0') || (*pcVar3 != *pcVar2)) break;
    pcVar2 = param_1 + 2;
    pcVar3 = param_2 + 2;
    sVar1 = param_3 - 2;
    if ((int)sVar1 < 1) {
      return 0;
    }
    if ((*pcVar2 == '\0') || (*pcVar3 != *pcVar2)) break;
    pcVar2 = param_1 + 3;
    pcVar3 = param_2 + 3;
    sVar1 = param_3 - 3;
    if ((int)sVar1 < 1) {
      return 0;
    }
    if ((*pcVar2 == '\0') || (*pcVar3 != *pcVar2)) break;
    pcVar2 = param_1 + 4;
    pcVar3 = param_2 + 4;
    sVar1 = param_3 - 4;
    if ((int)sVar1 < 1) {
      return 0;
    }
    if ((*pcVar2 == '\0') || (*pcVar3 != *pcVar2)) break;
    pcVar2 = param_1 + 5;
    pcVar3 = param_2 + 5;
    sVar1 = param_3 - 5;
    if ((int)sVar1 < 1) {
      return 0;
    }
    if ((*pcVar2 == '\0') || (*pcVar3 != *pcVar2)) break;
    pcVar2 = param_1 + 6;
    pcVar3 = param_2 + 6;
    sVar1 = param_3 - 6;
    if ((int)sVar1 < 1) {
      return 0;
    }
    if ((*pcVar2 == '\0') || (*pcVar3 != *pcVar2)) break;
    pcVar2 = param_1 + 7;
    pcVar3 = param_2 + 7;
    sVar1 = param_3 - 7;
    if ((int)sVar1 < 1) {
      return 0;
    }
    if ((*pcVar2 == '\0') || (*pcVar3 != *pcVar2)) break;
    param_1 = param_1 + 8;
    param_2 = param_2 + 8;
    param_3 = param_3 - 8;
  }
  if ((int)sVar1 < 1) {
    return 0;
  }
  return (int)*pcVar2 - (int)*pcVar3;
}

