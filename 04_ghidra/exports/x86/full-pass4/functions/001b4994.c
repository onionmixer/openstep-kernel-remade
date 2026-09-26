/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001b4994 */

void FUN_001b4994(int param_1,undefined4 param_2,int param_3,undefined4 param_4)

{
  byte bVar1;
  undefined4 uVar2;
  
  bVar1 = *(byte *)(param_3 + 6 + param_1);
  if ((bVar1 & 0x10) != 0) {
    _objc_msgSend(param_1,PTR_s__calcModBit_keyBits__001f9924,bVar1 & 0xf,param_4);
    if ((bVar1 & 0x20) == 0) {
      uVar2 = _objc_msgSend(*(undefined4 *)(param_1 + 0x4f8),PTR_s_eventFlags_001f9920,param_3,0,0,0
                            ,0);
      _objc_msgSend(*(undefined4 *)(param_1 + 0x4f8),PTR_s_keyboardEvent_flags_keyCode_char_001f991c
                    ,0xc,uVar2);
    }
    else {
      uVar2 = _objc_msgSend(*(undefined4 *)(param_1 + 0x4f8),PTR_s_eventFlags_001f9920);
      _objc_msgSend(*(undefined4 *)(param_1 + 0x4f8),PTR_s_updateEventFlags__001f9508,uVar2);
    }
  }
  return;
}

