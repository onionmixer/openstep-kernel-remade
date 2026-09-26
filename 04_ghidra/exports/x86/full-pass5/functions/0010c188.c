/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0010c188 */

int _sprintf(char *param_1,char *param_2,...)

{
  char *local_8;
  
  local_8 = param_1;
  _prf(param_2,&stack0x0000000c,8,&local_8);
  *local_8 = '\0';
  return (int)(local_8 + (1 - (int)param_1));
}

