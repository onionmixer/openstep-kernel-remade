/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0019f0b8 */

int FUN_0019f0b8(int param_1)

{
  undefined4 uVar1;
  
  _objc_msgSend(*(undefined4 *)(param_1 + 0x124),PTR_s_lock_001f9220);
  if (*(int *)(param_1 + 0x128) != 0) {
    _objc_msgSend(*(int *)(param_1 + 0x128),PTR_s_free_001f921c);
  }
  uVar1 = _objc_msgSend(PTR_s_KeyMap_001f9da8,PTR_s_alloc_001f9210,
                        PTR_s_initFromKeyMapping_length_canFre_001f94e4,&DAT_001d554a,0x372,0);
  uVar1 = _objc_msgSend(uVar1);
  *(undefined4 *)(param_1 + 0x128) = uVar1;
  _objc_msgSend(uVar1,PTR_s_setDelegate__001f94e8,param_1);
  *(undefined4 *)(param_1 + 0x168) = 125000000;
  *(undefined4 *)(param_1 + 0x16c) = 0;
  *(undefined4 *)(param_1 + 0x170) = 500000000;
  *(undefined4 *)(param_1 + 0x174) = 0;
  _objc_msgSend(*(undefined4 *)(param_1 + 0x124),PTR_s_unlock_001f9474);
  return param_1;
}

