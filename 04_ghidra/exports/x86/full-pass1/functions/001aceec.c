/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001aceec */

int FUN_001aceec(char *param_1,char *param_2,int param_3,int param_4)

{
  bool bVar1;
  char *pcVar2;
  
  bVar1 = false;
  pcVar2 = param_2;
  do {
    while( true ) {
      if ((param_3 == 0) || (param_4 == 0)) {
        return (int)pcVar2 - (int)param_2;
      }
      if (*param_1 != '\0') break;
LAB_001acf20:
      param_1 = param_1 + 1;
      param_3 = param_3 + -1;
    }
    if (*param_1 == ' ') {
      if (bVar1) goto LAB_001acf20;
      bVar1 = true;
    }
    else {
      bVar1 = false;
    }
    *pcVar2 = *param_1;
    param_1 = param_1 + 1;
    pcVar2 = pcVar2 + 1;
    param_3 = param_3 + -1;
    param_4 = param_4 + -1;
  } while( true );
}

