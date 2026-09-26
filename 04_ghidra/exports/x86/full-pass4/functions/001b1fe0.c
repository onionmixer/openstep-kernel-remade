/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001b1fe0 */

int FUN_001b1fe0(int param_1,undefined4 param_2,short *param_3,undefined4 param_4)

{
  short sVar1;
  int iVar2;
  int iVar3;
  short sVar4;
  undefined4 uVar5;
  int local_8;
  
  local_8 = -1;
  iVar2 = *(int *)(param_1 + 0x168);
  if (*(int *)(param_1 + 0x188) == 0) {
    return param_1;
  }
  iVar3 = _ev_try_lock(iVar2 + 0x14);
  if (iVar3 == 0) {
    *(undefined1 *)(param_1 + 0x209) = 1;
    _objc_msgSend(param_1,PTR_s_scheduleNextPeriodicEvent_001f99f4);
    return param_1;
  }
  *(undefined1 *)(param_1 + 0x209) = 0;
  iVar3 = *(int *)(param_1 + 0x18c) * 0x14 + *(int *)(param_1 + 0x180);
  if (((((*param_3 < *(short *)(iVar3 + 0xc)) || (*(short *)(iVar3 + 0xe) <= *param_3)) ||
       (param_3[1] < *(short *)(iVar3 + 0x10))) || (*(short *)(iVar3 + 0x12) <= param_3[1])) &&
     (local_8 = _objc_msgSend(param_1,PTR_s_pointToScreen__001f9998,param_3), local_8 < 0)) {
    sVar1 = *param_3;
    sVar4 = *(short *)(param_1 + 400);
    if ((*(short *)(param_1 + 400) <= sVar1) && (sVar4 = sVar1, *(short *)(param_1 + 0x192) < sVar1)
       ) {
      sVar4 = *(short *)(param_1 + 0x192);
    }
    *param_3 = sVar4;
    sVar1 = param_3[1];
    sVar4 = *(short *)(param_1 + 0x194);
    if ((*(short *)(param_1 + 0x194) <= sVar1) &&
       (sVar4 = sVar1, *(short *)(param_1 + 0x196) < sVar1)) {
      sVar4 = *(short *)(param_1 + 0x196);
    }
    param_3[1] = sVar4;
  }
  *(undefined4 *)(param_1 + 0x1a8) = *(undefined4 *)param_3;
  if ((*param_3 == *(short *)(iVar2 + 0x18)) && (param_3[1] == *(short *)(iVar2 + 0x1a))) {
    _ev_unlock(iVar2 + 0x14);
    return param_1;
  }
  *(undefined4 *)(iVar2 + 0x18) = *(undefined4 *)param_3;
  if (local_8 < 0) {
    _objc_msgSend(param_1,PTR_s_moveCursor_001f9988);
  }
  else {
    _objc_msgSend(param_1,PTR_s_hideCursor_001f9a38);
    *(int *)(param_1 + 0x18c) = local_8;
    *(undefined4 *)(param_1 + 400) =
         *(undefined4 *)(*(int *)(param_1 + 0x180) + 0xc + local_8 * 0x14);
    *(undefined4 *)(param_1 + 0x194) =
         *(undefined4 *)(*(int *)(param_1 + 0x180) + 0x10 + local_8 * 0x14);
    *(short *)(param_1 + 0x192) = *(short *)(param_1 + 0x192) + -1;
    *(short *)(param_1 + 0x196) = *(short *)(param_1 + 0x196) + -1;
    _objc_msgSend(param_1,PTR_s_showCursor_001f99fc);
  }
  if (*(int *)(iVar2 + 0x34) != 0) {
    if (((*(uint *)(iVar2 + 0x34) & 0x40) == 0) || ((*(uint *)(iVar2 + 8) & 4) == 0)) {
      if (((char)*(undefined4 *)(iVar2 + 0x34) < '\0') && ((*(uint *)(iVar2 + 8) & 1) != 0)) {
        uVar5 = 7;
      }
      else {
        if ((*(uint *)(iVar2 + 0x34) & 0x20) == 0) goto LAB_001b220b;
        uVar5 = 5;
      }
    }
    else {
      uVar5 = 6;
    }
    _objc_msgSend(param_1,PTR_s_postEvent_at_atTime_withData__001f9a00,uVar5,param_3,param_4,0);
  }
LAB_001b220b:
  if ((*(char *)(iVar2 + 0x33) < '\0') &&
     (((((*param_3 < *(short *)(iVar2 + 0x28) || (*(short *)(iVar2 + 0x2a) <= *param_3)) ||
        (param_3[1] < *(short *)(iVar2 + 0x2c))) || (*(short *)(iVar2 + 0x2e) <= param_3[1])) &&
      (*(char *)(iVar2 + 0x33) < '\0')))) {
    _objc_msgSend(param_1,PTR_s_postEvent_at_atTime_withData__001f9a00,9,param_3,param_4,0);
    *(byte *)(iVar2 + 0x33) = *(byte *)(iVar2 + 0x33) & 0x7f;
  }
  _ev_unlock(iVar2 + 0x14);
  return param_1;
}

