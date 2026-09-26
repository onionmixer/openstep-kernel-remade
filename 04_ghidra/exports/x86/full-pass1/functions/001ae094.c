/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001ae094 */

void FUN_001ae094(int param_1,char param_2)

{
  int *piVar1;
  int *piVar2;
  int *piVar3;
  int iVar4;
  int *piVar5;
  int *piVar6;
  
  if (param_2 == '\0') {
    piVar5 = (int *)(param_1 + 0x1b0);
  }
  else {
    piVar5 = (int *)(param_1 + 0x1a8);
  }
  piVar1 = (int *)*piVar5;
  if (piVar5 == piVar1) {
    _IOLog("sdThreadDequeue: Empty queue!\n");
  }
  else {
    piVar2 = (int *)piVar1[0xb];
    piVar3 = (int *)piVar1[0xc];
    piVar6 = piVar5;
    if (piVar5 != piVar2) {
      piVar6 = piVar2 + 0xb;
    }
    piVar6[1] = (int)piVar3;
    if (piVar5 != piVar3) {
      piVar5 = piVar3 + 0xb;
    }
    *piVar5 = (int)piVar2;
    if (param_2 != '\0') {
      _objc_msgSend(*(undefined4 *)(param_1 + 0x1c0),PTR_s_lock_001f9220);
      *(int *)(param_1 + 0x1c4) = *(int *)(param_1 + 0x1c4) + 1;
      if (*piVar1 == 4) {
        *(undefined1 *)(param_1 + 0x1c8) = 1;
        _volCheckEjecting(param_1,2);
      }
      _objc_msgSend(*(undefined4 *)(param_1 + 0x1c0),PTR_s_unlockWith__001f9224,
                    *(undefined4 *)(param_1 + 0x1c4));
    }
    switch(*piVar1) {
    case 0:
    case 1:
    case 2:
    case 3:
      _objc_msgSend(*(undefined4 *)(param_1 + 0x1b8),PTR_s_unlock_001f9474);
      _objc_msgSend(param_1,PTR_s_doSdBuf__001f9a5c,piVar1);
      _objc_msgSend(*(undefined4 *)(param_1 + 0x1b8),PTR_s_lock_001f9220);
      break;
    case 4:
      _objc_msgSend(*(undefined4 *)(param_1 + 0x1b8),PTR_s_unlock_001f9474);
      _objc_msgSend(*(undefined4 *)(param_1 + 0x1c0),PTR_s_lockWhen__001f9218,1);
      _objc_msgSend(*(undefined4 *)(param_1 + 0x1c0),PTR_s_unlock_001f9474);
      _objc_msgSend(param_1,PTR_s_doSdBuf__001f9a5c,piVar1);
      _objc_msgSend(*(undefined4 *)(param_1 + 0x1b8),PTR_s_lock_001f9220);
      break;
    case 5:
      piVar5 = (int *)(param_1 + 0x1a8);
      piVar6 = *(int **)(param_1 + 0x1a8);
      while (piVar6 != piVar5) {
        iVar4 = *piVar5;
        piVar2 = *(int **)(iVar4 + 0x2c);
        piVar3 = *(int **)(iVar4 + 0x30);
        piVar6 = piVar5;
        if (piVar5 != piVar2) {
          piVar6 = piVar2 + 0xb;
        }
        piVar6[1] = (int)piVar3;
        piVar6 = piVar5;
        if (piVar5 != piVar3) {
          piVar6 = piVar3 + 0xb;
        }
        *piVar6 = (int)piVar2;
        _objc_msgSend(*(undefined4 *)(param_1 + 0x1b8),PTR_s_unlock_001f9474);
        *(undefined4 *)(iVar4 + 0x28) = 0xfffffbb2;
        if (*(int *)(iVar4 + 0x14) != 0) {
          *(undefined4 *)(*(int *)(iVar4 + 0x14) + 0x1c) = 0x10;
        }
        _objc_msgSend(param_1,PTR_s_sdIoComplete__001f9a6c,iVar4);
        _objc_msgSend(*(undefined4 *)(param_1 + 0x1b8),PTR_s_lock_001f9220);
        piVar6 = (int *)*piVar5;
      }
    case 6:
      piVar1[10] = 0;
      _objc_msgSend(param_1,PTR_s_sdIoComplete__001f9a6c,piVar1);
      break;
    case 7:
      _objc_msgSend(*(undefined4 *)(param_1 + 0x1b8),PTR_s_unlock_001f9474);
      piVar1[10] = 0;
      _objc_msgSend(param_1,PTR_s_sdIoComplete__001f9a6c,piVar1);
      _IOExitThread();
    }
    if (param_2 != '\0') {
      _objc_msgSend(*(undefined4 *)(param_1 + 0x1c0),PTR_s_lock_001f9220);
      *(int *)(param_1 + 0x1c4) = *(int *)(param_1 + 0x1c4) + -1;
      _objc_msgSend(*(undefined4 *)(param_1 + 0x1c0),PTR_s_unlockWith__001f9224,
                    *(undefined4 *)(param_1 + 0x1c4));
    }
  }
  return;
}

