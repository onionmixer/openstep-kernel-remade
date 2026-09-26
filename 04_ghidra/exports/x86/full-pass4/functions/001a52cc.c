/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001a52cc */

char * _strstr(char *param_1,char *param_2)

{
  char cVar1;
  char cVar2;
  char *pcVar3;
  char *pcVar4;
  char *local_c;
  
  do {
    do {
      pcVar4 = param_1;
      param_1 = pcVar4 + 1;
      if (*pcVar4 == '\0') {
        return (char *)0x0;
      }
    } while (*param_2 != *pcVar4);
    cVar2 = param_2[1];
    pcVar3 = param_2 + 2;
    local_c = pcVar4 + 2;
    if (*param_1 == cVar2) {
      do {
        if (cVar2 == '\0') {
          return pcVar4;
        }
        cVar2 = *pcVar3;
        cVar1 = *local_c;
        pcVar3 = pcVar3 + 1;
        local_c = local_c + 1;
      } while (cVar1 == cVar2);
    }
  } while (cVar2 != '\0');
  return pcVar4;
}

