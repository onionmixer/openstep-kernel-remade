/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001b5d68 */

void FUN_001b5d68(undefined4 param_1)

{
  char cVar1;
  undefined4 uVar2;
  int iVar3;
  undefined *puVar4;
  undefined1 local_1c [4];
  undefined4 local_18;
  undefined4 local_10;
  int local_8;
  
LAB_001b5d78:
  while( true ) {
    while( true ) {
      local_18 = 0x18;
      local_10 = _objc_msgSend(param_1,PTR_s__devicePortSet_001f97a0);
      uVar2 = _objc_msgSend(param_1,PTR_s__timeout_001f9878);
      iVar3 = _msg_receive(local_1c,0x100,uVar2);
      if (iVar3 == -0xcb) goto LAB_001b5e30;
      if (iVar3 == 0) break;
      uVar2 = _objc_msgSend(param_1,PTR_s_deviceKind_001f9cc4,iVar3);
      uVar2 = _objc_msgSend(param_1,PTR_s_name_001f9228,uVar2);
      _IOLog("%s: %s thread: msg_receive returns %d\n",uVar2);
      _IOExitThread();
    }
    puVar4 = PTR_s__interruptOccurred_001f979c;
    if (local_8 == 0x232325) break;
    puVar4 = PTR_s__inputChannel_001f9908;
    if ((local_8 == 0x385) || (puVar4 = PTR_s__outputChannel_001f9900, local_8 == 900)) {
      uVar2 = _objc_msgSend(param_1,puVar4);
      _objc_msgSend(param_1,PTR_s__dataPendingOccurred__001f9798,uVar2);
    }
    else {
      puVar4 = PTR_s__commandOccurred_001f9794;
      if (local_8 == 0x386) break;
      _IOLog("Audio: unknown message id %d\n",local_8);
    }
  }
LAB_001b5e62:
  _objc_msgSend(param_1,puVar4);
  goto LAB_001b5d78;
LAB_001b5e30:
  cVar1 = _objc_msgSend(param_1,PTR_s_isInputActive_001f98f8);
  puVar4 = PTR_s_timeoutOccurred_001f9b90;
  if ((cVar1 == '\0') &&
     (cVar1 = _objc_msgSend(param_1,PTR_s_isOutputActive_001f98f4),
     puVar4 = PTR_s_timeoutOccurred_001f9b90, cVar1 == '\0')) goto LAB_001b5d78;
  goto LAB_001b5e62;
}

