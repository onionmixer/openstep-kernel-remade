/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0019f35c */

int FUN_0019f35c(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = _IOGetObjectForDeviceName(s_PCKeyboard0_001e4890,param_1 + 300);
  if (iVar1 != 0) {
    uVar2 = _objc_msgSend(param_1,PTR_s_stringFromReturn__001f9490,iVar1);
    _IOLog(s_initKeyboard__Can_t_find_PCKeybo_001e489c,uVar2);
    param_1 = 0;
  }
  return param_1;
}

