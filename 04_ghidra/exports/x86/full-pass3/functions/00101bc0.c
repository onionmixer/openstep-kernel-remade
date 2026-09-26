/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00101bc0 */

char * _strncpy(char *param_1,char *param_2,size_t param_3)

{
  uint uVar1;
  size_t sVar2;
  char *pcVar3;
  char *pcVar4;
  
  pcVar3 = param_1;
  if (0 < (int)param_3) {
    do {
      sVar2 = param_3;
      pcVar4 = pcVar3;
      if (*param_2 == '\0') break;
      *pcVar3 = *param_2;
      if ((int)(param_3 - 1) < 1) {
        return param_1;
      }
      sVar2 = param_3 - 1;
      pcVar4 = pcVar3 + 1;
      if (param_2[1] == '\0') break;
      pcVar3[1] = param_2[1];
      if ((int)(param_3 - 2) < 1) {
        return param_1;
      }
      sVar2 = param_3 - 2;
      pcVar4 = pcVar3 + 2;
      if (param_2[2] == '\0') break;
      pcVar3[2] = param_2[2];
      if ((int)(param_3 - 3) < 1) {
        return param_1;
      }
      sVar2 = param_3 - 3;
      pcVar4 = pcVar3 + 3;
      if (param_2[3] == '\0') break;
      pcVar3[3] = param_2[3];
      if ((int)(param_3 - 4) < 1) {
        return param_1;
      }
      sVar2 = param_3 - 4;
      pcVar4 = pcVar3 + 4;
      if (param_2[4] == '\0') break;
      pcVar3[4] = param_2[4];
      if ((int)(param_3 - 5) < 1) {
        return param_1;
      }
      sVar2 = param_3 - 5;
      pcVar4 = pcVar3 + 5;
      if (param_2[5] == '\0') break;
      pcVar3[5] = param_2[5];
      if ((int)(param_3 - 6) < 1) {
        return param_1;
      }
      sVar2 = param_3 - 6;
      pcVar4 = pcVar3 + 6;
      if (param_2[6] == '\0') break;
      pcVar3[6] = param_2[6];
      if ((int)(param_3 - 7) < 1) {
        return param_1;
      }
      sVar2 = param_3 - 7;
      pcVar4 = pcVar3 + 7;
      if (param_2[7] == '\0') break;
      pcVar3[7] = param_2[7];
      param_2 = param_2 + 8;
      pcVar3 = pcVar3 + 8;
      param_3 = param_3 - 8;
      sVar2 = param_3;
      pcVar4 = pcVar3;
    } while (0 < (int)param_3);
    if (0 < (int)sVar2) {
      uVar1 = -sVar2 & 3;
      if (uVar1 != 0) {
        if (uVar1 < 3) {
          if (uVar1 < 2) {
            *pcVar4 = '\0';
            pcVar4 = pcVar4 + 1;
            sVar2 = sVar2 - 1;
          }
          *pcVar4 = '\0';
          pcVar4 = pcVar4 + 1;
          sVar2 = sVar2 - 1;
        }
        *pcVar4 = '\0';
        pcVar4 = pcVar4 + 1;
        sVar2 = sVar2 - 1;
        if ((int)sVar2 < 1) {
          return param_1;
        }
      }
      do {
        *pcVar4 = '\0';
        pcVar4[1] = '\0';
        pcVar4[2] = '\0';
        pcVar4[3] = '\0';
        pcVar4 = pcVar4 + 4;
        sVar2 = sVar2 - 4;
      } while (0 < (int)sVar2);
    }
  }
  return param_1;
}

