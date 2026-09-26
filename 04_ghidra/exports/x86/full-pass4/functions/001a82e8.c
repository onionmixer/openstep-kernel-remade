/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001a82e8 */

void FUN_001a82e8(undefined4 param_1)

{
  int iVar1;
  undefined4 uVar2;
  undefined *puVar3;
  uint uVar4;
  uint local_8;
  
LAB_001a82f4:
  iVar1 = _objc_msgSend(param_1,PTR_s_waitForInterrupt__001f9b98,&local_8);
  puVar3 = PTR_s_receiveMsg_001f9b94;
  if (iVar1 != -0x2e1) {
    if (iVar1 != 0) {
      uVar2 = _objc_msgSend(param_1,PTR_s_deviceKind_001f9cc4,iVar1);
      uVar2 = _objc_msgSend(param_1,PTR_s_name_001f9228,uVar2);
      _IOLog("%s: %s thread: waitForInterrupt: returns %d\n",uVar2);
      goto LAB_001a82f4;
    }
    puVar3 = PTR_s_commandRequestOccurred_001f9b8c;
    if (local_8 != 0x232324) {
      if ((int)local_8 < 0x232325) {
        puVar3 = PTR_s_timeoutOccurred_001f9b90;
        if (local_8 == 0x232323) goto LAB_001a838e;
LAB_001a83ac:
        puVar3 = PTR_s_otherOccurred__001f9b84;
        uVar4 = local_8;
        if (local_8 - 0x232325 < 0x10) {
          puVar3 = PTR_s_interruptOccurredAt__001f9bd0;
          uVar4 = local_8 - 0x232325;
        }
        _objc_msgSend(param_1,puVar3,uVar4);
        goto LAB_001a82f4;
      }
      puVar3 = PTR_s_interruptOccurred_001f9b88;
      if (local_8 != 0x232325) {
        if (local_8 != 0x232336) goto LAB_001a83ac;
        _IOExitThread();
        goto LAB_001a82f4;
      }
    }
  }
LAB_001a838e:
  _objc_msgSend(param_1,puVar3);
  goto LAB_001a82f4;
}

