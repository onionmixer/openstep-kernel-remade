/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0011cb0c */

undefined4 _pn_getcomponent(int param_1,char *param_2)

{
  char *pcVar1;
  int iVar2;
  int iVar3;
  
  iVar2 = *(int *)(param_1 + 8);
  iVar3 = 0xff;
  for (pcVar1 = *(char **)(param_1 + 4); (0 < iVar2 && (*pcVar1 != '/')); pcVar1 = pcVar1 + 1) {
    iVar3 = iVar3 + -1;
    if (iVar3 < 0) {
      return 0x3f;
    }
    *param_2 = *pcVar1;
    param_2 = param_2 + 1;
    iVar2 = iVar2 + -1;
  }
  *(char **)(param_1 + 4) = pcVar1;
  *(int *)(param_1 + 8) = iVar2;
  *param_2 = '\0';
  return 0;
}

