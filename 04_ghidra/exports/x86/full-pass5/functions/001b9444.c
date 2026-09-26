/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001b9444 */

undefined4 FUN_001b9444(int param_1,undefined4 param_2,undefined4 *param_3,undefined4 *param_4)

{
  undefined4 uVar1;
  longlong lVar2;
  
  _objc_msgSend(*(undefined4 *)(param_1 + 8),PTR_s__outputStartTime_001f9714);
  lVar2 = _objc_msgSend(*(undefined4 *)(param_1 + 8),PTR_s__lastInterruptTimeStamp_001f9710);
  if (lVar2 == 0) {
    *param_4 = 0;
    *param_3 = 0;
    uVar1 = 0;
  }
  else {
    uVar1 = __udivdi3(lVar2,1000,0);
    if (param_4 != (undefined4 *)0x0) {
      *param_4 = uVar1;
    }
    *param_3 = *(undefined4 *)(param_1 + 0x20);
    uVar1 = 1;
  }
  return uVar1;
}

