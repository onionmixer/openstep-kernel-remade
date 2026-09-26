/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00104c2c */

int _execv(char *param_1,char **param_2)

{
  int iVar1;
  int iVar2;
  char *unaff_EBP;
  char **unaff_retaddr;
  
  *(undefined4 *)(*(int *)(DAT_001e875c + 0x24) + 8) = 0;
  iVar1 = _execve(unaff_EBP,unaff_retaddr,(char **)param_1);
  iVar2 = DAT_001e875c;
  *(char *)(DAT_001e875c + 0x68) = (char)iVar1;
  return iVar2;
}

