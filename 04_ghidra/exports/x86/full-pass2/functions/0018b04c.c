/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0018b04c */

int _argstrcpy(char *param_1,char *param_2)

{
  char cVar1;
  int iVar2;
  
  iVar2 = 0;
  for (; (((cVar1 = *param_1, cVar1 != ' ' && (cVar1 != '\0')) && (cVar1 != '\t')) && (cVar1 != ',')
         ); param_1 = param_1 + 1) {
    iVar2 = iVar2 + 1;
    *param_2 = cVar1;
    param_2 = param_2 + 1;
  }
  *param_2 = '\0';
  return iVar2;
}

