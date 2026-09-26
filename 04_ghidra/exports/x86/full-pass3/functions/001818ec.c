/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001818ec */

undefined4 FUN_001818ec(int param_1,undefined4 param_2,undefined4 param_3,int param_4)

{
  char cVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  undefined4 uVar5;
  undefined *puVar6;
  undefined4 local_c;
  int local_8;
  
  iVar2 = _objc_msgSend(*(undefined4 *)(param_1 + 0x1c),PTR_s__lookupResourceWithKey__001f9348,
                        param_3);
  if (iVar2 == 0) {
    _printf(s__s__Couldn_t_locate_resource_obj_001e105f,param_3);
    uVar3 = 0;
  }
  else {
    uVar3 = _objc_msgSend(PTR_s_List_001f9d80,PTR_s_alloc_001f9210,PTR_s_init_001f924c);
    uVar3 = _objc_msgSend(uVar3);
    local_8 = param_4;
    if (param_4 != 0) {
      cVar1 = _objc_msgSend(param_1,PTR_s__isShared__001f9340,param_3);
      do {
        iVar4 = FUN_00180f48(local_8,&local_8,&local_c);
        if (iVar4 == 0) {
          return uVar3;
        }
        puVar6 = PTR_s_reserveItem__001f9350;
        if (cVar1 != '\0') {
          puVar6 = PTR_s_shareItem__001f934c;
        }
        uVar5 = _objc_msgSend(iVar2,puVar6,local_c);
        iVar4 = _objc_msgSend(uVar3,PTR_s_addObject__001f92c4,uVar5);
      } while (iVar4 != 0);
      _printf(s__s__Couldn_t_reserve__d_001e1084,param_3,local_c);
      uVar3 = _objc_msgSend(uVar3,PTR_s_freeObjects_001f92ec,PTR_s_free_001f921c);
      uVar3 = _objc_msgSend(uVar3);
    }
  }
  return uVar3;
}

