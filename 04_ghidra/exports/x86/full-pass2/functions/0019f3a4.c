/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0019f3a4 */

void FUN_0019f3a4(int param_1,undefined4 param_2,undefined4 param_3,uint param_4,undefined4 param_5,
                 undefined4 param_6,undefined4 param_7,undefined4 param_8,undefined4 param_9)

{
  undefined4 uVar1;
  
  uVar1 = _objc_msgSend(param_1,PTR_s_owner_001f94f8,PTR_s_keyboardEvent_flags_keyCode_char_001f94fc
                        ,param_3,param_4 | *(uint *)(param_1 + 0x148),param_5,param_6,param_7,
                        param_8,param_9,(int)*(char *)(param_1 + 0x14e),
                        *(undefined4 *)(param_1 + 0x158),*(undefined4 *)(param_1 + 0x15c));
  _objc_msgSend(uVar1);
  _objc_msgSend(param_1,PTR_s_setRepeat_forCode__001f9500,param_3,param_5);
  return;
}

