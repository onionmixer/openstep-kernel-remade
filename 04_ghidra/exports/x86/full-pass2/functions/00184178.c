/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00184178 */

undefined4 _sgopen(short param_1)

{
  int iVar1;
  
  iVar1 = FUN_0018447c((int)param_1);
  if (iVar1 == 0) {
    return 6;
  }
  iVar1 = _objc_msgSend(iVar1,PTR_s_acquire__001f93e8,iVar1);
  if (iVar1 == 0) {
    return 0;
  }
  return 0x10;
}

