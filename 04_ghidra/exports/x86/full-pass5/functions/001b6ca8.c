/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001b6ca8 */

void FUN_001b6ca8(undefined4 param_1,undefined4 param_2,int param_3,int param_4,uint param_5,
                 undefined4 param_6)

{
  undefined4 uVar1;
  uint uVar2;
  
  uVar2 = 0;
  if (param_5 != 0) {
    do {
      uVar1 = _objc_msgSend(param_1,PTR_s__intValueForParameter_forObject__001f97e0,
                            *(undefined4 *)(param_3 + uVar2 * 4),param_6);
      *(undefined4 *)(param_4 + uVar2 * 4) = uVar1;
      uVar2 = uVar2 + 1;
    } while (uVar2 < param_5);
  }
  return;
}

