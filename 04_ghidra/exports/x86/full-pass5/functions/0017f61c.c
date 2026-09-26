/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0017f61c */

undefined4 FUN_0017f61c(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 uVar1;
  char cVar2;
  
  uVar1 = *(undefined4 *)(param_1 + 4);
  cVar2 = _objc_msgSend(uVar1,PTR_s_isKey__001f929c,param_4);
  if (cVar2 == '\0') {
    _objc_msgSend(uVar1,PTR_s_insertKey_value__001f9288,param_4,param_3);
  }
  else {
    param_3 = 0;
  }
  return param_3;
}

