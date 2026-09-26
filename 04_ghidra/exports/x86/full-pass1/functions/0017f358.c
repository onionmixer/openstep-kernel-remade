/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0017f358 */

undefined4 FUN_0017f358(undefined4 param_1)

{
  undefined4 uVar1;
  
  if (DAT_001e731c == 0) {
    uVar1 = _objc_msgSend(PTR_s_HashTable_001f9d74,PTR_s_alloc_001f9210,PTR_s_initKeyDesc__001f9284,
                          &DAT_001e0fc8);
    DAT_001e731c = _objc_msgSend(uVar1);
  }
  if (DAT_001e7320 == 0) {
    uVar1 = _objc_msgSend(PTR_s_HashTable_001f9d74,PTR_s_alloc_001f9210,PTR_s_initKeyDesc__001f9284,
                          &DAT_001e0fca);
    DAT_001e7320 = _objc_msgSend(uVar1);
  }
  return param_1;
}

