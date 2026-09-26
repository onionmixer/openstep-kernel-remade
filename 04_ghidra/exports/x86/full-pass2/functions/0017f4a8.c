/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0017f4a8 */

undefined4 FUN_0017f4a8(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  undefined4 uVar2;
  
  uVar2 = 0;
  iVar1 = _objc_msgSend(DAT_001e7320,PTR_s_valueForKey__001f928c,param_3);
  if (iVar1 != 0) {
    uVar2 = _objc_msgSend(iVar1,PTR_s_valueForKey__001f928c,param_4);
  }
  return uVar2;
}

