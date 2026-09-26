/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001aa550 */

undefined4 FUN_001aa550(int param_1,undefined4 param_2,byte *param_3)

{
  int iVar1;
  
  if (((*param_3 & 1) != 0) && (*(char *)(param_1 + 0x129) == '\0')) {
    iVar1 = 0;
    do {
      if (param_3[iVar1] != 0xff) {
        _objc_msgSend(*(undefined4 *)(param_1 + 0x138),PTR_s_lock_001f9220);
        iVar1 = _objc_msgSend(param_1,PTR_s_searchMulti__001f9b48,param_3);
        _objc_msgSend(*(undefined4 *)(param_1 + 0x138),PTR_s_unlock_001f9474);
        if (iVar1 != 0) {
          return 0;
        }
        return 1;
      }
      iVar1 = iVar1 + 1;
    } while (iVar1 < 6);
  }
  return 0;
}

