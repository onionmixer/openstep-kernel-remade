/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001adf7c */

void _sdIoThread(int param_1)

{
  char cVar1;
  int iVar2;
  
  do {
    _objc_msgSend(*(undefined4 *)(param_1 + 0x1b8),PTR_s_lockWhen__001f9218,1);
    iVar2 = *(int *)(param_1 + 0x1b0);
    while (iVar2 != param_1 + 0x1b0) {
      FUN_001ae094(param_1,0);
      iVar2 = *(int *)(param_1 + 0x1b0);
    }
    if (*(int *)(param_1 + 0x1a8) != param_1 + 0x1a8) {
      do {
        iVar2 = _objc_msgSend(param_1,PTR_s_lastReadyState_001f9c70);
        if (((iVar2 == 2) ||
            (iVar2 = _objc_msgSend(param_1,PTR_s_lastReadyState_001f9c70), iVar2 == 3)) ||
           (*(char *)(param_1 + 0x1c8) != '\0')) break;
        FUN_001ae094(param_1,1);
      } while (*(int *)(param_1 + 0x1a8) != param_1 + 0x1a8);
    }
    iVar2 = _objc_msgSend(param_1,PTR_s_lastReadyState_001f9c70);
    if ((*(int *)(param_1 + 0x1a8) == param_1 + 0x1a8) ||
       (((iVar2 != 1 || (cVar1 = _objc_msgSend(param_1,PTR_s_isRemovable_001f93c8), cVar1 == '\0'))
        && ((iVar2 != 2 && (*(char *)(param_1 + 0x1c8) == '\0')))))) {
      _objc_msgSend(param_1,PTR_s_unlockIoQLock_001f9a60);
    }
    else {
      _objc_msgSend(param_1,PTR_s_unlockIoQLock_001f9a60);
      _volCheckRequest(param_1,2);
    }
  } while( true );
}

