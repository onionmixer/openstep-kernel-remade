/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001a46e0 */

bool FUN_001a46e0(undefined4 param_1)

{
  int iVar1;
  
  iVar1 = _objc_msgSend(param_1,PTR_s_blockMajor_001f9ccc);
  if (iVar1 != -1) {
    _IORemoveFromBdevsw(iVar1);
    _objc_msgSend(param_1,PTR_s_setBlockMajor__001f9cd4,0xffffffff);
  }
  return iVar1 != -1;
}

