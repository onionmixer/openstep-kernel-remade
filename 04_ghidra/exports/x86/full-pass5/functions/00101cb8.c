/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00101cb8 */

char * _strcat(char *param_1,char *param_2)

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
  for (pcVar3 = param_2 + 1;
      (((cVar1 != '\0' && (cVar1 = *pcVar3, *pcVar4 = cVar1, cVar1 != '\0')) &&
       (cVar1 = pcVar3[1], pcVar4[1] = cVar1, cVar1 != '\0')) &&
      (((cVar1 = pcVar3[2], pcVar4[2] = cVar1, cVar1 != '\0' &&
        (cVar1 = pcVar3[3], pcVar4[3] = cVar1, cVar1 != '\0')) &&
       ((cVar1 = pcVar3[4], pcVar4[4] = cVar1, cVar1 != '\0' &&
        ((cVar1 = pcVar3[5], pcVar4[5] = cVar1, cVar1 != '\0' &&
         (cVar1 = pcVar3[6], pcVar4[6] = cVar1, cVar1 != '\0')))))))); pcVar3 = pcVar3 + 8) {
    cVar1 = pcVar3[7];
    pcVar4[7] = cVar1;
    pcVar4 = pcVar4 + 8;
  }
  return param_1;
}

