/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0018a034 */

undefined4 _copystr(char *param_1,char *param_2,int param_3,int *param_4)

{
  char cVar1;
  int iVar2;
  bool bVar3;
  
  *(undefined **)(_active_threads + 0x74) = &DAT_0018a088;
  iVar2 = param_3;
  do {
    bVar3 = iVar2 < 1;
    iVar2 = iVar2 + -1;
    if (bVar3) break;
    cVar1 = *param_1;
    *param_2 = cVar1;
    param_1 = param_1 + 1;
    param_2 = param_2 + 1;
  } while (cVar1 != '\0');
  if (param_4 != (int *)0x0) {
    *param_4 = param_3 - iVar2;
  }
  *(undefined4 *)(_active_threads + 0x74) = 0;
  return 0;
}

