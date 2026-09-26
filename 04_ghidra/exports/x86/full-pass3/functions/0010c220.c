/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0010c220 */

undefined4 _vlog(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  
  iVar1 = _prf(param_2,param_3,5,0);
  if (iVar1 != 0) {
    _logwakeup();
  }
  return 0;
}

