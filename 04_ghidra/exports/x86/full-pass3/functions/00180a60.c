/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00180a60 */

int FUN_00180a60(int param_1,undefined4 param_2,int *param_3,uint param_4,undefined4 param_5)

{
  char cVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  undefined4 uVar8;
  int iVar9;
  undefined *puVar10;
  uint uVar11;
  uint uVar12;
  int *local_1c;
  
  cVar1 = _objc_msgSend(param_1,PTR_s__isShared__001f9340,param_5);
  uVar2 = _objc_msgSend(param_1,PTR_s_resourcesForKey__001f9344,param_5);
  uVar3 = _objc_msgSend(PTR_s_List_001f9d80,PTR_s_alloc_001f9210,PTR_s_init_001f924c);
  uVar3 = _objc_msgSend(uVar3);
  uVar4 = _objc_msgSend(PTR_s_List_001f9d80,PTR_s_alloc_001f9210,PTR_s_init_001f924c);
  uVar4 = _objc_msgSend(uVar4);
  uVar12 = 0;
  if (param_4 != 0) {
    local_1c = param_3;
    do {
      iVar9 = *local_1c;
      for (uVar11 = 0; uVar5 = _objc_msgSend(uVar2,PTR_s_count_001f92d8), uVar11 < uVar5;
          uVar11 = uVar11 + 1) {
        iVar6 = _objc_msgSend(uVar2,PTR_s_objectAt__001f92e8,uVar11,PTR_s_item_001f933c);
        iVar7 = _objc_msgSend(iVar6);
        if (iVar9 == iVar7) goto LAB_00180b52;
      }
      iVar6 = 0;
LAB_00180b52:
      if (iVar6 == 0) {
        iVar9 = _objc_msgSend(*(undefined4 *)(param_1 + 0x1c),PTR_s__lookupResourceWithKey__001f9348
                              ,param_5);
        if (iVar9 == 0) {
LAB_00180c94:
          uVar2 = _objc_msgSend(uVar4,PTR_s_freeObjects_001f92ec,PTR_s_free_001f921c);
          _objc_msgSend(uVar2);
          _objc_msgSend(uVar3,PTR_s_free_001f921c);
          return 0;
        }
        if (cVar1 == '\0') {
          iVar6 = *local_1c;
          puVar10 = PTR_s_reserveItem__001f9350;
        }
        else {
          iVar6 = *local_1c;
          puVar10 = PTR_s_shareItem__001f934c;
        }
        iVar9 = _objc_msgSend(iVar9,puVar10,iVar6);
        if (iVar9 == 0) goto LAB_00180c94;
        _objc_msgSend(uVar4,PTR_s_addObject__001f92c4,iVar9);
        _objc_msgSend(uVar3,PTR_s_addObject__001f92c4,iVar9);
      }
      else {
        _objc_msgSend(uVar3,PTR_s_addObject__001f92c4,iVar6);
      }
      local_1c = local_1c + 1;
      uVar12 = uVar12 + 1;
    } while (uVar12 < param_4);
  }
  for (uVar12 = 0; uVar11 = _objc_msgSend(uVar2,PTR_s_count_001f92d8), uVar12 < uVar11;
      uVar12 = uVar12 + 1) {
    uVar8 = _objc_msgSend(uVar2,PTR_s_objectAt__001f92e8,uVar12);
    iVar9 = _objc_msgSend(uVar3,PTR_s_indexOf__001f92c0,uVar8);
    if (iVar9 == -1) {
      _objc_msgSend(uVar8,PTR_s_free_001f921c);
    }
  }
  _objc_msgSend(uVar2,PTR_s_empty_001f931c);
  _objc_msgSend(param_1,PTR_s_setResources_forKey__001f9338,uVar3,param_5);
  _objc_msgSend(uVar4,PTR_s_free_001f921c);
  return param_1;
}

