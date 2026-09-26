/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00181360 */

int FUN_00181360(int param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  
  iVar1 = _objc_msgSend(*(undefined4 *)(param_1 + 0x10),PTR_s_valueForKey__001f928c,param_3);
  if (iVar1 == 0) {
    iVar1 = _objc_msgSend(*(undefined4 *)(param_1 + 4),PTR_s_valueForStringKey__001f9308,param_3);
    if (iVar1 != 0) {
      _objc_msgSend(*(undefined4 *)(param_1 + 0x10),PTR_s_insertKey_value__001f9288,param_3,iVar1);
    }
  }
  return iVar1;
}

