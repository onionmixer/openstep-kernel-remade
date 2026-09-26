/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001a8b48 */

undefined4
FUN_001a8b48(int param_1,undefined4 param_2,uint param_3,undefined4 *param_4,char param_5,
            undefined4 param_6)

{
  int *piVar1;
  uint uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  int iVar5;
  int iVar6;
  
  piVar1 = *(int **)(param_1 + 0x11c);
  uVar2 = _objc_msgSend(*(undefined4 *)(param_1 + 0x108),PTR_s_numMemoryRanges_001f9ba8);
  if (param_3 < uVar2) {
    uVar3 = _objc_msgSend(*(undefined4 *)(param_1 + 0x114),PTR_s_resourcesForKey__001f9344,
                          "Memory Maps",PTR_s_objectAt__001f92e8,param_3);
    uVar3 = _objc_msgSend(uVar3);
    if (param_5 == '\0') {
      uVar4 = _current_task_EXTERNAL(param_6);
      iVar5 = _objc_msgSend(uVar3,PTR_s_mapToAddress_inTarget_cache__001f9ba0,*param_4,uVar4);
    }
    else {
      uVar4 = _current_task_EXTERNAL(param_6);
      iVar5 = _objc_msgSend(uVar3,PTR_s_mapInTarget_cache__001f9ba4,uVar4);
    }
    if (iVar5 == 0) {
      uVar3 = 0xfffffd43;
    }
    else {
      uVar3 = _objc_msgSend(iVar5,PTR_s_address_001f9b9c);
      *param_4 = uVar3;
      if (*piVar1 == 0) {
        uVar3 = _objc_msgSend(PTR_s_HashTable_001f9d74,PTR_s_alloc_001f9210,
                              PTR_s_initKeyDesc__001f9284,"i");
        iVar6 = _objc_msgSend(uVar3);
        *piVar1 = iVar6;
      }
      _objc_msgSend(*piVar1,PTR_s_insertKey_value__001f9288,*param_4,iVar5);
      uVar3 = 0;
    }
  }
  else {
    uVar3 = 0xfffffd3e;
  }
  return uVar3;
}

