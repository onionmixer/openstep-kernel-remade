/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001a8c78 */

void FUN_001a8c78(int param_1,undefined4 param_2,uint param_3,undefined4 param_4)

{
  undefined4 *puVar1;
  uint uVar2;
  int iVar3;
  
  puVar1 = *(undefined4 **)(param_1 + 0x11c);
  uVar2 = _objc_msgSend(*(undefined4 *)(param_1 + 0x108),PTR_s_numMemoryRanges_001f9ba8);
  if (param_3 < uVar2) {
    iVar3 = _objc_msgSend(*puVar1,PTR_s_valueForKey__001f928c,param_4);
    if (iVar3 != 0) {
      _objc_msgSend(*puVar1,PTR_s_removeKey__001f92a0,param_4);
      _objc_msgSend(iVar3,PTR_s_free_001f921c);
    }
  }
  return;
}

