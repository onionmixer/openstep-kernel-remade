/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00101af8 */

size_t _strlen(char *param_1)

{
  char *pcVar1;
  char *pcVar2;
  char *pcVar3;
  
  pcVar2 = param_1;
  while ((((pcVar3 = pcVar2 + 1, *pcVar2 != '\0' && (pcVar3 = pcVar2 + 2, pcVar2[1] != '\0')) &&
          (pcVar3 = pcVar2 + 3, pcVar2[2] != '\0')) &&
         ((pcVar3 = pcVar2 + 4, pcVar2[3] != '\0' && (pcVar3 = pcVar2 + 5, pcVar2[4] != '\0'))))) {
    pcVar3 = pcVar2 + 6;
    if ((pcVar2[5] == '\0') ||
       ((pcVar1 = pcVar2 + 7, pcVar3 = pcVar1, pcVar2[6] == '\0' ||
        (pcVar2 = pcVar2 + 8, pcVar3 = pcVar2, *pcVar1 == '\0')))) break;
  }
  return (size_t)(pcVar3 + (-1 - (int)param_1));
}

