/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001b7fe0 */

int FUN_001b7fe0(int param_1)

{
  undefined4 uVar1;
  uint uVar2;
  undefined4 uVar3;
  int iVar4;
  uint uVar5;
  
  uVar1 = _objc_msgSend(PTR_s_List_001f9d80,PTR_s_alloc_001f9210,PTR_s_init_001f924c);
  uVar1 = _objc_msgSend(uVar1);
  _objc_msgSend(*(undefined4 *)(param_1 + 0x10),PTR_s_lock_001f9220);
  uVar5 = 0;
  while( true ) {
    uVar2 = _objc_msgSend(*(undefined4 *)(param_1 + 0xc),PTR_s_count_001f92d8);
    if (uVar2 <= uVar5) break;
    uVar3 = _objc_msgSend(*(undefined4 *)(param_1 + 0xc),PTR_s_objectAt__001f92e8,uVar5);
    iVar4 = _objc_msgSend(uVar3,PTR_s_type_001f9764);
    if (iVar4 != 0) {
      _objc_msgSend(uVar1,PTR_s_addObject__001f92c4,uVar3);
    }
    uVar5 = uVar5 + 1;
  }
  _objc_msgSend(*(undefined4 *)(param_1 + 0x10),PTR_s_unlock_001f9474);
  uVar5 = 0;
  while( true ) {
    uVar2 = _objc_msgSend(uVar1,PTR_s_count_001f92d8);
    if (uVar2 <= uVar5) break;
    uVar3 = _objc_msgSend(uVar1,PTR_s_objectAt__001f92e8,uVar5);
    _objc_msgSend(param_1,PTR_s_removeStream__001f9760,uVar3);
    uVar5 = uVar5 + 1;
  }
  _objc_msgSend(uVar1,PTR_s_free_001f921c);
  return param_1;
}

