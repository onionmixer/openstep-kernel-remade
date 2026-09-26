/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001c9f10 */

void FUN_001c9f10(undefined4 param_1,undefined4 param_2,int param_3,undefined4 param_4)

{
  undefined4 uVar1;
  
  if (param_3 == 0) {
    uVar1 = _sel_getName(param_2,0);
    _objc_msgSend(param_1,PTR_s_error__001f9d20,"method %s given invalid selector %s",uVar1);
  }
  else {
    _objc_msgSend(param_1,param_3,param_4);
  }
  return;
}

