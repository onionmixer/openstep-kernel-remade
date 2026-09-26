/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0010c0d8 */

int _printf(char *param_1,...)

{
  int iVar1;
  
  iVar1 = _prf(param_1,&stack0x00000008,5,0);
  if (iVar1 != 0) {
    _logwakeup();
  }
  return 0;
}

