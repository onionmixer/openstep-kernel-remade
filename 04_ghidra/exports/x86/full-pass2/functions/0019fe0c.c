/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0019fe0c */

int FUN_0019fe0c(int param_1,undefined4 param_2,void *param_3,char *param_4,size_t param_5)

{
  void *pvVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  char *pcVar6;
  char *pcVar7;
  bool bVar8;
  int local_c;
  undefined *local_8;
  
  iVar5 = -0x2c2;
  iVar4 = 0x12;
  bVar8 = true;
  pcVar6 = param_4;
  pcVar7 = s_Evs_SetKeyMapping_001e49a7;
  do {
    if (iVar4 == 0) break;
    iVar4 = iVar4 + -1;
    bVar8 = *pcVar6 == *pcVar7;
    pcVar6 = pcVar6 + 1;
    pcVar7 = pcVar7 + 1;
  } while (bVar8);
  if (bVar8) {
    pvVar1 = (void *)_IOMalloc(param_5);
    _bcopy(param_3,pvVar1,param_5);
    _objc_msgSend(*(undefined4 *)(param_1 + 0x124),PTR_s_lock_001f9220);
    iVar4 = *(int *)(param_1 + 0x128);
    uVar2 = _objc_msgSend(PTR_s_KeyMap_001f9da8,PTR_s_alloc_001f9210,
                          PTR_s_initFromKeyMapping_length_canFre_001f94e4,pvVar1,param_5,1);
    iVar3 = _objc_msgSend(uVar2);
    *(int *)(param_1 + 0x128) = iVar3;
    if (iVar3 == 0) {
      *(int *)(param_1 + 0x128) = iVar4;
    }
    else {
      if (iVar4 != 0) {
        _objc_msgSend(iVar4,PTR_s_free_001f921c);
      }
      _objc_msgSend(*(undefined4 *)(param_1 + 0x128),PTR_s_setDelegate__001f94e8,param_1);
      iVar5 = 0;
    }
    _objc_msgSend(*(undefined4 *)(param_1 + 0x124),PTR_s_unlock_001f9474);
  }
  else {
    local_c = param_1;
    local_8 = PTR_s_IOEventSource_001fa040;
    iVar5 = _objc_msgSendSuper(&local_c,PTR_s_setCharValues_forParameter_count_001f9538,param_3,
                               param_4,param_5);
    if (iVar5 == -0x2c7) {
      iVar5 = -0x2c2;
    }
  }
  return iVar5;
}

