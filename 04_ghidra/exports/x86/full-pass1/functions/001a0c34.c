/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001a0c34 */

undefined4 FUN_001a0c34(int param_1,undefined4 param_2,int *param_3,char *param_4)

{
  int iVar1;
  char *pcVar2;
  char *pcVar3;
  bool bVar4;
  
  iVar1 = 0xb;
  bVar4 = true;
  pcVar2 = param_4;
  pcVar3 = s_Resolution_001e4b4e;
  do {
    if (iVar1 == 0) break;
    iVar1 = iVar1 + -1;
    bVar4 = *pcVar2 == *pcVar3;
    pcVar2 = pcVar2 + 1;
    pcVar3 = pcVar3 + 1;
  } while (bVar4);
  if (bVar4) {
    iVar1 = *(int *)(param_1 + 300);
  }
  else {
    iVar1 = 9;
    bVar4 = true;
    pcVar2 = s_Inverted_001e4b59;
    do {
      if (iVar1 == 0) break;
      iVar1 = iVar1 + -1;
      bVar4 = *param_4 == *pcVar2;
      param_4 = param_4 + 1;
      pcVar2 = pcVar2 + 1;
    } while (bVar4);
    if (!bVar4) {
      return 0xfffffd39;
    }
    iVar1 = (int)*(char *)(param_1 + 0x130);
  }
  *param_3 = iVar1;
  return 0;
}

