/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001ccf18 */

void _objc_getOrigClass(undefined4 param_1)

{
  int iVar1;
  
  iVar1 = 0;
  if (DAT_001e55b0 != 0) {
    iVar1 = _NXMapGet(DAT_001e55b0,param_1);
  }
  if (iVar1 == 0) {
    _objc_getClass(param_1);
  }
  return;
}

