/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00101e7c */

int _strcmp(char *param_1,char *param_2)

{
  char *pcVar1;
  char *pcVar2;
  
  pcVar1 = param_2;
  pcVar2 = param_1;
  if (*param_1 != '\0') {
    while (pcVar1 = param_2, pcVar2 = param_1, *param_1 == *param_2) {
      pcVar2 = param_1 + 1;
      pcVar1 = param_2 + 1;
      if ((*pcVar2 == '\0') || (*pcVar1 != *pcVar2)) break;
      pcVar2 = param_1 + 2;
      pcVar1 = param_2 + 2;
      if ((*pcVar2 == '\0') || (*pcVar1 != *pcVar2)) break;
      pcVar2 = param_1 + 3;
      pcVar1 = param_2 + 3;
      if ((*pcVar2 == '\0') || (*pcVar1 != *pcVar2)) break;
      pcVar2 = param_1 + 4;
      pcVar1 = param_2 + 4;
      if ((*pcVar2 == '\0') || (*pcVar1 != *pcVar2)) break;
      pcVar2 = param_1 + 5;
      pcVar1 = param_2 + 5;
      if ((*pcVar2 == '\0') || (*pcVar1 != *pcVar2)) break;
      pcVar2 = param_1 + 6;
      pcVar1 = param_2 + 6;
      if ((*pcVar2 == '\0') || (*pcVar1 != *pcVar2)) break;
      pcVar2 = param_1 + 7;
      pcVar1 = param_2 + 7;
      if ((*pcVar2 == '\0') || (*pcVar1 != *pcVar2)) break;
      param_1 = param_1 + 8;
      param_2 = param_2 + 8;
      pcVar1 = param_2;
      pcVar2 = param_1;
      if (*param_1 == '\0') break;
    }
  }
  return (int)*pcVar2 - (int)*pcVar1;
}

