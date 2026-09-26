/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001a469c */

bool FUN_001a469c(undefined4 param_1)

{
  int iVar1;
  
  iVar1 = _objc_msgSend(param_1,PTR_s_characterMajor_001f9cd0);
  if (iVar1 != -1) {
    _IORemoveFromCdevsw(iVar1);
    _objc_msgSend(param_1,PTR_s_setCharacterMajor__001f9cd8,0xffffffff);
  }
  return iVar1 != -1;
}

