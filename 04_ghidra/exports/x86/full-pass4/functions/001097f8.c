/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001097f8 */

void _gsignal(int param_1,undefined4 param_2)

{
  int iVar1;
  
  if (param_1 != 0) {
    iVar1 = _pgfind(param_1);
    if (iVar1 != 0) {
      _pgsignal(iVar1,param_2,0);
    }
  }
  return;
}

