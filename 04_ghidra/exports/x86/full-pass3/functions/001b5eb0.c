/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001b5eb0 */

void FUN_001b5eb0(undefined4 param_1)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 local_40;
  undefined1 local_3c [4];
  undefined4 local_38;
  undefined4 local_30;
  int local_28;
  undefined4 local_20;
  undefined4 local_18;
  undefined4 local_10;
  
  uVar1 = _task_self(&local_40);
  iVar2 = _port_allocate_EXTERNAL(uVar1);
  if (iVar2 != 0) {
    _IOLog("Audio: port_allocate");
  }
  iVar2 = _objc_lookUpClass("EventDriver");
  if (iVar2 == 0) {
    _IOLog("Audio: objc_lookUpClass failure\n");
    _IOExitThread();
  }
  uVar1 = _objc_msgSend(iVar2,PTR_s_instance_001f9964);
  uVar3 = _objc_msgSend(uVar1,PTR_s_ev_port_001f9960);
  iVar2 = _objc_msgSend(uVar1,PTR_s_setSpecialKeyPort_keyFlavor_keyP_001f99e4,uVar3,0,local_40);
  if (iVar2 != 0) {
    _IOLog("Audio: SetSpecialKeyPort error %d\n",iVar2);
    _IOExitThread();
  }
  iVar2 = _objc_msgSend(uVar1,PTR_s_setSpecialKeyPort_keyFlavor_keyP_001f99e4,uVar3,1,local_40);
  if (iVar2 != 0) {
    _IOLog("Audio: SetSpecialKeyPort error %d\n",iVar2);
    _IOExitThread();
  }
  do {
    local_30 = local_40;
    local_38 = 0x38;
    iVar2 = _msg_receive(local_3c,0,0);
    if (iVar2 != 0) {
      _IOLog("Audio: keyThread msg_receive error: %d\n",iVar2);
      _IOExitThread();
    }
    if (local_28 != 0x536b6579) {
      _IOLog("Audio: unknown msg id %d in keyThread\n",local_28);
      _IOExitThread();
    }
    _objc_msgSend(param_1,PTR_s__keyOccurred_event_flags__001f9790,local_20,local_18,local_10);
  } while( true );
}

