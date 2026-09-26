/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001b2e60 */

int FUN_001b2e60(int param_1,undefined4 param_2,undefined4 param_3,short *param_4,char param_5,
                undefined1 param_6,undefined4 param_7,uint param_8,int param_9)

{
  uint uVar1;
  undefined4 uVar2;
  undefined1 local_10 [12];
  
  uVar1 = param_8 >> 0x18 | param_9 << 8;
  _objc_msgSend(*(undefined4 *)(param_1 + 0x110),PTR_s_lock_001f9220);
  if (*(char *)(param_1 + 0x1d2) == '\0') {
    uVar2 = *(undefined4 *)(param_1 + 0x110);
    goto LAB_001b2fc8;
  }
  *(undefined1 *)(param_1 + 0x1c0) = param_6;
  if (((*param_4 != *(short *)(param_1 + 0x1a8)) || (param_4[1] != *(short *)(param_1 + 0x1aa))) &&
     (*(undefined4 *)(param_1 + 0x1a8) = *(undefined4 *)param_4, *(char *)(param_1 + 0x209) == '\0')
     ) {
    _objc_msgSend(param_1,PTR_s__setCursorPosition_atTime__001f99ac,param_1 + 0x1a8,uVar1);
  }
  if (*(char *)(param_1 + 0x1c1) == param_5) {
LAB_001b2f52:
    if (param_5 == '\x01') {
      _objc_msgSend(param_1,PTR_s__setButtonState_atTime__001f9970,param_3,uVar1);
    }
  }
  else if (param_5 == '\x01') {
    *(uint *)(*(int *)(param_1 + 0x168) + 0xc) = *(uint *)(*(int *)(param_1 + 0x168) + 0xc) | 0x80;
    _bzero(local_10,0xc);
    _objc_msgSend(param_1,PTR_s_postEvent_at_atTime_withData__001f9a00,0xc,param_1 + 0x1a8,uVar1,
                  local_10);
    goto LAB_001b2f52;
  }
  if ((*(char *)(param_1 + 0x1c1) != param_5) && (param_5 == '\0')) {
    *(uint *)(*(int *)(param_1 + 0x168) + 0xc) =
         *(uint *)(*(int *)(param_1 + 0x168) + 0xc) & 0xffffff7f;
    _bzero(local_10,0xc);
    _objc_msgSend(param_1,PTR_s_postEvent_at_atTime_withData__001f9a00,0xc,param_1 + 0x1a8,uVar1,
                  local_10);
  }
  *(char *)(param_1 + 0x1c1) = param_5;
  uVar2 = *(undefined4 *)(param_1 + 0x110);
LAB_001b2fc8:
  _objc_msgSend(uVar2,PTR_s_unlock_001f9474);
  return param_1;
}

