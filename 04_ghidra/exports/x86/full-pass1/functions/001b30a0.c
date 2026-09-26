/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001b30a0 */

int FUN_001b30a0(int param_1,undefined4 param_2,int param_3,uint param_4,undefined4 param_5,
                undefined4 param_6,uint param_7,int param_8)

{
  int iVar1;
  undefined *puVar2;
  int local_14;
  undefined1 local_10 [2];
  undefined2 local_e;
  
  local_14 = -1;
  _bzero(local_10,0xc);
  _objc_msgSend(*(undefined4 *)(param_1 + 0x110),PTR_s_lock_001f9220);
  if (*(char *)(param_1 + 0x1d2) == '\0') {
    _objc_msgSend(*(undefined4 *)(param_1 + 0x110),PTR_s_unlock_001f9474);
    return param_1;
  }
  *(uint *)(*(int *)(param_1 + 0x168) + 0xc) =
       *(uint *)(*(int *)(param_1 + 0x168) + 0xc) & 0xff80ff80 | param_4 & 0x7f007f;
  if (*(char *)(param_1 + 0x1d3) == '\x01') {
    _objc_msgSend(param_1,PTR_s_forceAutoDimState__001f9a3c,0);
  }
  if (param_3 != 10) goto switchD_001b3152_caseD_4;
  puVar2 = PTR_s_audioVolume_001f9968;
  switch(param_6) {
  case 0:
    if ((param_4 & 0x1c0000) == 0) {
      iVar1 = _objc_msgSend(param_1,PTR_s_audioVolume_001f9968);
      _objc_msgSend(param_1,PTR_s_setAudioVolume__001f9984,iVar1 + 1);
      puVar2 = PTR_s_audioVolume_001f9968;
    }
    break;
  case 1:
    if ((param_4 & 0x1c0000) == 0) {
      iVar1 = _objc_msgSend(param_1,PTR_s_audioVolume_001f9968);
      _objc_msgSend(param_1,PTR_s_setAudioVolume__001f9984,iVar1 + -1);
      puVar2 = PTR_s_audioVolume_001f9968;
    }
    break;
  case 2:
    puVar2 = PTR_s_brightness_001f9a28;
    if ((param_4 & 0x1c0000) == 0) {
      iVar1 = _objc_msgSend(param_1,PTR_s_brightness_001f9a28);
      iVar1 = iVar1 + 1;
LAB_001b3206:
      _objc_msgSend(param_1,PTR_s_setBrightness__001f9a14,iVar1);
      puVar2 = PTR_s_brightness_001f9a28;
    }
    break;
  case 3:
    puVar2 = PTR_s_brightness_001f9a28;
    if ((param_4 & 0x1c0000) == 0) {
      iVar1 = _objc_msgSend(param_1,PTR_s_brightness_001f9a28);
      iVar1 = iVar1 + -1;
      goto LAB_001b3206;
    }
    break;
  default:
    goto switchD_001b3152_caseD_4;
  case 6:
    local_e = 1;
    _objc_msgSend(param_1,PTR_s_postEvent_at_atTime_withData__001f9a00,0xe,param_1 + 0x1a8,
                  param_7 >> 0x18 | param_8 << 8,local_10);
    goto switchD_001b3152_caseD_4;
  }
  local_14 = _objc_msgSend(param_1,puVar2);
switchD_001b3152_caseD_4:
  _objc_msgSend(*(undefined4 *)(param_1 + 0x110),PTR_s_unlock_001f9474);
  if (local_14 != -1) {
    _objc_msgSend(param_1,PTR_s_evSpecialKeyMsg_direction_flags__001f9980,param_6,param_3,param_4,
                  local_14);
  }
  return param_1;
}

