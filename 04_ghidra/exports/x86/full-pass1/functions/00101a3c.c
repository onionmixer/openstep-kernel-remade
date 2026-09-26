/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00101a3c */

char * _strrchr(char *param_1,int param_2)

{
  char *pcVar1;
  char *pcVar2;
  
  pcVar2 = (char *)0x0;
  while( true ) {
    if (*param_1 == param_2) {
      pcVar2 = param_1;
    }
    if (*param_1 == '\0') {
      return pcVar2;
    }
    if (param_1[1] == param_2) {
      pcVar2 = param_1 + 1;
    }
    if (param_1[1] == '\0') {
      return pcVar2;
    }
    if (param_1[2] == param_2) {
      pcVar2 = param_1 + 2;
    }
    if (param_1[2] == '\0') {
      return pcVar2;
    }
    if (param_1[3] == param_2) {
      pcVar2 = param_1 + 3;
    }
    if (param_1[3] == '\0') {
      return pcVar2;
    }
    if (param_1[4] == param_2) {
      pcVar2 = param_1 + 4;
    }
    if (param_1[4] == '\0') break;
    if (param_1[5] == param_2) {
      pcVar2 = param_1 + 5;
    }
    if (param_1[5] == '\0') {
      return pcVar2;
    }
    if (param_1[6] == param_2) {
      pcVar2 = param_1 + 6;
    }
    if (param_1[6] == '\0') {
      return pcVar2;
    }
    pcVar1 = param_1 + 7;
    if (*pcVar1 == param_2) {
      pcVar2 = param_1 + 7;
    }
    param_1 = param_1 + 8;
    if (*pcVar1 == '\0') {
      return pcVar2;
    }
  }
  return pcVar2;
}

