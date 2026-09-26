/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001a89b4 */

undefined4 FUN_001a89b4(int param_1,undefined4 param_2,uint param_3,char param_4)

{
  int iVar1;
  char cVar2;
  uint uVar3;
  undefined4 uVar4;
  int iVar5;
  undefined *puVar6;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  
  iVar1 = *(int *)(param_1 + 0x11c);
  uVar3 = _objc_msgSend(*(undefined4 *)(param_1 + 0x108),PTR_s_numInterrupts_001f9bcc);
  if (param_3 < uVar3) {
    if (*(int *)(iVar1 + 4) == 0) {
      uVar4 = _objc_msgSend(PTR_s_HashTable_001f9d74,PTR_s_alloc_001f9210,
                            PTR_s_initKeyDesc__001f9284,"i");
      uVar4 = _objc_msgSend(uVar4);
      *(undefined4 *)(iVar1 + 4) = uVar4;
    }
    iVar5 = _objc_msgSend(*(undefined4 *)(iVar1 + 4),PTR_s_valueForKey__001f928c,param_3);
    if (iVar5 == 0) {
      local_c = 3;
      local_10 = 0;
      uVar4 = _objc_msgSend(*(undefined4 *)(param_1 + 0x114),PTR_s_device_001f9bec,
                            PTR_s_interrupt__001f9bb8,param_3);
      iVar5 = _objc_msgSend(uVar4);
      _objc_msgSend(*(undefined4 *)(iVar1 + 4),PTR_s_insertKey_value__001f9288,param_3,iVar5);
      uVar4 = _objc_msgSend(*(undefined4 *)(param_1 + 0x114),PTR_s_resourcesForKey__001f9344,
                            "IRQ Levels",PTR_s_objectAt__001f92e8,param_3);
      uVar4 = _objc_msgSend(uVar4);
      cVar2 = _objc_msgSend(param_1,PTR_s_getHandler_level_argument_forInt_001f9bb4,&local_8,
                            &local_c,&local_10,param_3);
      if (cVar2 == '\0') {
        _objc_msgSend(iVar5,PTR_s_attachToBusInterrupt_withArgumen_001f9bac,uVar4,param_3 + 0x232325
                     );
      }
      else {
        _objc_msgSend(iVar5,PTR_s_attachToBusInterrupt_withSpecial_001f9bb0,uVar4,local_8,local_10,
                      local_c);
      }
    }
    puVar6 = PTR_s_suspend_001f92f4;
    if (param_4 != '\0') {
      puVar6 = PTR_s_resume_001f92f8;
    }
    _objc_msgSend(iVar5,puVar6);
    uVar4 = 0;
  }
  else {
    uVar4 = 0xfffffd3e;
  }
  return uVar4;
}

