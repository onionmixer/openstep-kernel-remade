/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001b1e1c */

void FUN_001b1e1c(int param_1)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  int iStack_18;
  undefined *puStack_14;
  
  puStack_14 = PTR_s_lock_001f9220;
  iStack_18 = *(int *)(param_1 + 0x110);
  _objc_msgSend();
  piVar3 = (int *)&stack0xfffffff0;
  if (*(char *)(param_1 + 0x1d2) == '\0') goto LAB_001b1fc3;
  iVar1 = *(int *)(param_1 + 0x168);
  puStack_14 = (undefined *)(param_1 + 0x1f8);
  iStack_18 = 0x1b1e5a;
  _IOGetTimestamp();
  puStack_14 = (undefined *)(*(uint *)(param_1 + 0x1f8) >> 0x18 | *(int *)(param_1 + 0x1fc) << 8);
  if (puStack_14 == (undefined *)0x0) {
    puStack_14 = (undefined *)0x1;
  }
  *(undefined **)(iVar1 + 0x10) = puStack_14;
  if (*(char *)(param_1 + 0x209) == '\x01') {
    iStack_18 = param_1 + 0x1a8;
    _objc_msgSend(param_1,PTR_s__setCursorPosition_atTime__001f99ac);
  }
  puStack_14 = (undefined *)(iVar1 + 0x40);
  iStack_18 = 0x1b1ea6;
  iVar2 = _ev_try_lock();
  if (iVar2 != 0) {
    puStack_14 = (undefined *)(iVar1 + 0x14);
    iStack_18 = 0x1b1eba;
    iVar2 = _ev_try_lock();
    if (iVar2 != 0) {
      if ((*(int *)(iVar1 + 0x38) != *(int *)(iVar1 + 0x3c)) &&
         ((int)*(short *)(iVar1 + 0x4c) < *(int *)(iVar1 + 0x10) - *(int *)(iVar1 + 0x38))) {
        *(undefined1 *)(iVar1 + 0x48) = 1;
      }
      if (((*(char *)(iVar1 + 0x49) == '\0') || (*(char *)(iVar1 + 0x4a) == '\0')) ||
         (*(char *)(iVar1 + 0x48) == '\0')) {
        if (((*(int *)(iVar1 + 0x44) != 0) &&
            (*(uint *)(param_1 + 0x1e0) <= *(uint *)(param_1 + 0x1fc))) &&
           ((puStack_14 = PTR_s_hideWaitCursor_001f99a4,
            *(uint *)(param_1 + 0x1e0) != *(uint *)(param_1 + 0x1fc) ||
            (*(uint *)(param_1 + 0x1dc) <= *(uint *)(param_1 + 0x1f8))))) goto LAB_001b1f39;
      }
      else {
        puStack_14 = PTR_s_showWaitCursor_001f99a8;
        if (*(int *)(iVar1 + 0x44) == 0) {
LAB_001b1f39:
          iStack_18 = param_1;
          _objc_msgSend();
        }
      }
      if (((*(int *)(iVar1 + 0x44) != 0) &&
          (*(uint *)(param_1 + 0x1f0) <= *(uint *)(param_1 + 0x1fc))) &&
         ((*(uint *)(param_1 + 0x1f0) != *(uint *)(param_1 + 0x1fc) ||
          (*(uint *)(param_1 + 0x1ec) <= *(uint *)(param_1 + 0x1f8))))) {
        puStack_14 = PTR_s_animateWaitCursor_001f99a0;
        iStack_18 = param_1;
        _objc_msgSend();
      }
      puStack_14 = (undefined *)(iVar1 + 0x14);
      iStack_18 = 0x1b1f83;
      _ev_unlock();
      if ((*(uint *)(param_1 + 0x1a4) < *(uint *)(iVar1 + 0x10)) &&
         (*(char *)(param_1 + 0x1d3) == '\0')) {
        puStack_14 = PTR_s_doAutoDim_001f999c;
        iStack_18 = param_1;
        _objc_msgSend();
      }
    }
    puStack_14 = (undefined *)(iVar1 + 0x40);
    iStack_18 = 0x1b1fb3;
    _ev_unlock();
  }
  puStack_14 = PTR_s_scheduleNextPeriodicEvent_001f99f4;
  piVar3 = &iStack_18;
  iStack_18 = param_1;
  _objc_msgSend();
LAB_001b1fc3:
  *(undefined **)((int)piVar3 + -4) = PTR_s_unlock_001f9474;
  *(undefined4 *)((int)piVar3 + -8) = *(undefined4 *)(param_1 + 0x110);
  *(undefined4 *)((int)piVar3 + -0xc) = 0x1b1fd6;
  _objc_msgSend();
  return;
}

