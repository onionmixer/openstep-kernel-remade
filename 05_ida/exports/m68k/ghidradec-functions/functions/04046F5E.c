
int _port_set_backup(int param_1,undefined4 param_2,uint param_3,uint *param_4)

{
  int iVar1;
  uint uVar2;
  uint uStack_c;
  undefined4 uStack_8;
  
  if (param_1 == 0) {
    iVar1 = 4;
  }
  else {
    if (param_3 == 0xffffffff) {
      uVar2 = 0;
    }
    else {
      uVar2 = 0;
      if (param_3 != 0) {
        uVar2 = param_3 | 1;
      }
    }
    iVar1 = _port_translate_compat(param_1,param_2,&uStack_8);
    if (iVar1 == 0) {
      _ipc_port_pdrequest(uStack_8,uVar2,&uStack_c);
      if (uStack_c != 0) {
        if ((uStack_c & 1) == 0) {
          _ipc_notify_send_once(uStack_c);
          uStack_c = 0;
        }
        else {
          uStack_c = uStack_c & 0xfffffffe;
        }
      }
      *param_4 = uStack_c;
      iVar1 = 0;
    }
  }
  return iVar1;
}
