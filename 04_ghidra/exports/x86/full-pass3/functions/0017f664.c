/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0017f664 */

int FUN_0017f664(int param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 uVar1;
  int iVar2;
  
  uVar1 = *(undefined4 *)(param_1 + 4);
  iVar2 = _objc_msgSend(uVar1,PTR_s_valueForKey__001f928c,param_3);
  if (iVar2 == 0) {
    iVar2 = 0;
  }
  else {
    _objc_msgSend(uVar1,PTR_s_removeKey__001f92a0,param_3);
  }
  return iVar2;
}

