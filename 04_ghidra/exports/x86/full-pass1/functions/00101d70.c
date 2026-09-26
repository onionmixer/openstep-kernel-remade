/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00101d70 */

char * _strncat(char *param_1,char *param_2,size_t param_3)

{
  char cVar1;
  char *pcVar2;
  char *pcVar3;
  char *pcVar4;
  
  pcVar3 = param_1 + 1;
  pcVar4 = pcVar3;
  if (*param_1 != '\0') {
    while ((((pcVar4 = pcVar3 + 1, *pcVar3 != '\0' && (pcVar4 = pcVar3 + 2, pcVar3[1] != '\0')) &&
            (pcVar4 = pcVar3 + 3, pcVar3[2] != '\0')) &&
           ((pcVar4 = pcVar3 + 4, pcVar3[3] != '\0' && (pcVar4 = pcVar3 + 5, pcVar3[4] != '\0')))))
    {
      pcVar4 = pcVar3 + 6;
      if ((pcVar3[5] == '\0') ||
         ((pcVar2 = pcVar3 + 7, pcVar4 = pcVar2, pcVar3[6] == '\0' ||
          (pcVar3 = pcVar3 + 8, pcVar4 = pcVar3, *pcVar2 == '\0')))) break;
    }
  }
  cVar1 = *param_2;
  pcVar4[-1] = cVar1;
  pcVar2 = param_2 + 1;
  pcVar3 = pcVar4 + -1;
  while( true ) {
    if (cVar1 == '\0') {
      return param_1;
    }
    pcVar4 = pcVar3 + 1;
    if ((int)(param_3 - 1) < 0) break;
    cVar1 = *pcVar2;
    *pcVar4 = cVar1;
    pcVar4 = pcVar3 + 2;
    if (cVar1 == '\0') {
      return param_1;
    }
    if ((int)(param_3 - 2) < 0) break;
    cVar1 = pcVar2[1];
    *pcVar4 = cVar1;
    pcVar4 = pcVar3 + 3;
    if (cVar1 == '\0') {
      return param_1;
    }
    if ((int)(param_3 - 3) < 0) break;
    cVar1 = pcVar2[2];
    *pcVar4 = cVar1;
    pcVar4 = pcVar3 + 4;
    if (cVar1 == '\0') {
      return param_1;
    }
    if ((int)(param_3 - 4) < 0) break;
    cVar1 = pcVar2[3];
    *pcVar4 = cVar1;
    pcVar4 = pcVar3 + 5;
    if (cVar1 == '\0') {
      return param_1;
    }
    if ((int)(param_3 - 5) < 0) break;
    cVar1 = pcVar2[4];
    *pcVar4 = cVar1;
    pcVar4 = pcVar3 + 6;
    if (cVar1 == '\0') {
      return param_1;
    }
    if ((int)(param_3 - 6) < 0) break;
    cVar1 = pcVar2[5];
    *pcVar4 = cVar1;
    pcVar4 = pcVar3 + 7;
    if (cVar1 == '\0') {
      return param_1;
    }
    if ((int)(param_3 - 7) < 0) break;
    cVar1 = pcVar2[6];
    *pcVar4 = cVar1;
    pcVar4 = pcVar3 + 8;
    if (cVar1 == '\0') {
      return param_1;
    }
    param_3 = param_3 - 8;
    if ((int)param_3 < 0) break;
    cVar1 = pcVar2[7];
    *pcVar4 = cVar1;
    pcVar2 = pcVar2 + 8;
    pcVar3 = pcVar4;
  }
  pcVar4[-1] = '\0';
  return param_1;
}

