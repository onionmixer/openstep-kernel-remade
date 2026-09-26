/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0019fb5c */

int FUN_0019fb5c(int param_1,undefined4 param_2,void *param_3,char *param_4,uint *param_5)

{
  uint uVar1;
  uint uVar2;
  void *pvVar3;
  int iVar4;
  char *pcVar5;
  char *pcVar6;
  bool bVar7;
  int local_c;
  undefined *local_8;
  
  uVar1 = *param_5;
  iVar4 = 0x16;
  bVar7 = true;
  pcVar5 = param_4;
  pcVar6 = s_Evs_CurrentKeyMapping_001e4956;
  do {
    if (iVar4 == 0) break;
    iVar4 = iVar4 + -1;
    bVar7 = *pcVar5 == *pcVar6;
    pcVar5 = pcVar5 + 1;
    pcVar6 = pcVar6 + 1;
  } while (bVar7);
  if (bVar7) {
    _objc_msgSend(*(undefined4 *)(param_1 + 0x124),PTR_s_lock_001f9220);
    if (*(int *)(param_1 + 0x128) == 0) {
      iVar4 = -0x2d9;
    }
    else {
      uVar2 = _objc_msgSend(*(int *)(param_1 + 0x128),PTR_s_keyMappingLength_001f951c);
      if (uVar1 <= uVar2) {
        uVar2 = uVar1;
      }
      *param_5 = uVar2;
      pvVar3 = (void *)_objc_msgSend(*(undefined4 *)(param_1 + 0x128),PTR_s_keyMapping__001f952c,0);
      _bcopy(pvVar3,param_3,uVar2);
      iVar4 = 0;
    }
    _objc_msgSend(*(undefined4 *)(param_1 + 0x124),PTR_s_unlock_001f9474);
  }
  else {
    local_c = param_1;
    local_8 = PTR_s_IOEventSource_001fa040;
    iVar4 = _objc_msgSendSuper(&local_c,PTR_s_getCharValues_forParameter_count_001f9530,param_3,
                               param_4,param_5);
    if (iVar4 == -0x2c7) {
      iVar4 = -0x2c2;
    }
  }
  return iVar4;
}

