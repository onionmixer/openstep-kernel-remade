
void _port_request_notification(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uStack_30;
  undefined4 uStack_2c;
  undefined4 uStack_28;
  undefined4 uStack_24;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  undefined4 uStack_18;
  undefined4 uStack_14;
  undefined4 uStack_10;
  undefined4 uStack_c;
  undefined4 uStack_8;
  
  uStack_30 = dword_40AFF54;
  uStack_2c = dword_40AFF58;
  uStack_28 = dword_40AFF5C;
  uStack_1c = dword_40AFF68;
  uStack_18 = dword_40AFF6C;
  uStack_c = dword_40AFF78;
  uStack_14 = param_1;
  uStack_10 = param_2;
  uStack_24 = 0;
  uStack_20 = _pn_register_port_k;
  uStack_8 = param_1;
  iVar1 = _msg_send_from_kernel(&uStack_30,1,0);
  if (iVar1 != 0) {
    _printf(aPortRequestNot,iVar1);
  }
  return;
}
