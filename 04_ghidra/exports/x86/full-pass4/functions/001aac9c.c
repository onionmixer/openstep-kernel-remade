/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001aac9c */

char * FUN_001aac9c(int param_1,undefined4 param_2,char *param_3)

{
  char *pcVar1;
  int iVar2;
  char *pcVar3;
  char *pcVar4;
  bool bVar5;
  
  pcVar1 = *(char **)(param_1 + 0x144);
  do {
    if ((char *)(param_1 + 0x144) == pcVar1) {
      return (char *)0x0;
    }
    iVar2 = 6;
    bVar5 = true;
    pcVar3 = pcVar1;
    pcVar4 = param_3;
    do {
      if (iVar2 == 0) break;
      iVar2 = iVar2 + -1;
      bVar5 = *pcVar3 == *pcVar4;
      pcVar3 = pcVar3 + 1;
      pcVar4 = pcVar4 + 1;
    } while (bVar5);
    if (bVar5) {
      return pcVar1;
    }
    pcVar1 = *(char **)(pcVar1 + 8);
  } while( true );
}

