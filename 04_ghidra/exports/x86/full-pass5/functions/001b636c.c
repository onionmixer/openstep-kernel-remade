/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001b636c */

void FUN_001b636c(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  char cVar1;
  
  cVar1 = _objc_msgSend(param_1,PTR_s_isInputActive_001f98f8);
  if (cVar1 == '\0') {
    cVar1 = _objc_msgSend(param_1,PTR_s_isOutputActive_001f98f4);
    if (cVar1 == '\0') {
      _objc_msgSend(param_1,PTR_s__attemptToStartDMAForChannel_cha_001f98f0,param_3,0);
    }
  }
  return;
}

