/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001c9b90 */

undefined4 FUN_001c9b90(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  uint uVar1;
  undefined4 uVar2;
  uint uVar3;
  
  uVar3 = 0;
  uVar1 = _objc_msgSend(param_3,PTR_s_count_001f92d8);
  if (uVar1 != 0) {
    do {
      uVar2 = _objc_msgSend(param_3,PTR_s_objectAt__001f92e8,uVar3);
      _objc_msgSend(param_1,PTR_s_addObject__001f92c4,uVar2);
      uVar3 = uVar3 + 1;
    } while (uVar3 < uVar1);
  }
  return param_1;
}

