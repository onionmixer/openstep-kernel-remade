/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00180cd0 */

int FUN_00180cd0(int param_1,undefined4 param_2,int param_3,uint param_4,undefined4 param_5)

{
  undefined4 uVar1;
  char cVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  uint uVar6;
  int iVar7;
  undefined4 uVar8;
  uint uVar9;
  longlong lVar10;
  undefined *puVar11;
  uint local_20;
  
  cVar2 = _objc_msgSend(param_1,PTR_s__isShared__001f9340,param_5);
  uVar3 = _objc_msgSend(param_1,PTR_s_resourcesForKey__001f9344,param_5);
  uVar4 = _objc_msgSend(PTR_s_List_001f9d80,PTR_s_alloc_001f9210,PTR_s_init_001f924c);
  uVar4 = _objc_msgSend(uVar4);
  uVar5 = _objc_msgSend(PTR_s_List_001f9d80,PTR_s_alloc_001f9210,PTR_s_init_001f924c);
  uVar5 = _objc_msgSend(uVar5);
  uVar9 = 0;
  if (param_4 != 0) {
    do {
      uVar8 = *(undefined4 *)(param_3 + uVar9 * 8);
      uVar1 = *(undefined4 *)(param_3 + 4 + uVar9 * 8);
      for (local_20 = 0; uVar6 = _objc_msgSend(uVar3,PTR_s_count_001f92d8), local_20 < uVar6;
          local_20 = local_20 + 1) {
        iVar7 = _objc_msgSend(uVar3,PTR_s_objectAt__001f92e8,local_20);
        lVar10 = _objc_msgSend(iVar7,PTR_s_range_001f9278);
        if (lVar10 == CONCAT44(uVar1,uVar8)) goto LAB_00180dce;
      }
      iVar7 = 0;
LAB_00180dce:
      if (iVar7 == 0) {
        iVar7 = _objc_msgSend(*(undefined4 *)(param_1 + 0x1c),PTR_s__lookupResourceWithKey__001f9348
                              ,param_5);
        if (iVar7 == 0) {
LAB_00180f0c:
          uVar3 = _objc_msgSend(uVar5,PTR_s_freeObjects_001f92ec,PTR_s_free_001f921c);
          _objc_msgSend(uVar3);
          _objc_msgSend(uVar4,PTR_s_free_001f921c);
          return 0;
        }
        puVar11 = PTR_s_reserveRange__001f9358;
        if (cVar2 != '\0') {
          puVar11 = PTR_s_shareRange__001f9354;
        }
        iVar7 = _objc_msgSend(iVar7,puVar11,uVar8,uVar1);
        if (iVar7 == 0) goto LAB_00180f0c;
        _objc_msgSend(uVar5,PTR_s_addObject__001f92c4,iVar7);
        _objc_msgSend(uVar4,PTR_s_addObject__001f92c4,iVar7);
      }
      else {
        _objc_msgSend(uVar4,PTR_s_addObject__001f92c4,iVar7);
      }
      uVar9 = uVar9 + 1;
    } while (uVar9 < param_4);
  }
  for (uVar9 = 0; uVar6 = _objc_msgSend(uVar3,PTR_s_count_001f92d8), uVar9 < uVar6;
      uVar9 = uVar9 + 1) {
    uVar8 = _objc_msgSend(uVar3,PTR_s_objectAt__001f92e8,uVar9);
    iVar7 = _objc_msgSend(uVar4,PTR_s_indexOf__001f92c0,uVar8);
    if (iVar7 == -1) {
      _objc_msgSend(uVar8,PTR_s_free_001f921c);
    }
  }
  _objc_msgSend(uVar3,PTR_s_empty_001f931c);
  _objc_msgSend(param_1,PTR_s_setResources_forKey__001f9338,uVar4,param_5);
  _objc_msgSend(uVar5,PTR_s_free_001f921c);
  return param_1;
}

