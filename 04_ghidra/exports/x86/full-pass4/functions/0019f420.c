/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0019f420 */

void FUN_0019f420(int param_1,undefined4 param_2,undefined4 param_3,uint param_4,undefined4 param_5,
                 int param_6)

{
  undefined4 uVar1;
  
  uVar1 = _objc_msgSend(param_1,PTR_s_owner_001f94f8,PTR_s_keyboardSpecialEvent_flags_keyCo_001f9504
                        ,param_3,param_4 | *(uint *)(param_1 + 0x148),param_5,param_6,
                        *(undefined4 *)(param_1 + 0x158),*(undefined4 *)(param_1 + 0x15c));
  _objc_msgSend(uVar1);
  if (param_6 != 4) {
    _objc_msgSend(param_1,PTR_s_setRepeat_forCode__001f9500,param_3,param_5);
  }
  return;
}

