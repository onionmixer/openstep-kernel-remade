
int _mach_port_request_notification
              (int param_1,undefined4 param_2,int param_3,int param_4,int param_5,uint *param_6)

{
  int iVar1;
  undefined4 uStack_10;
  uint uStack_c;
  undefined4 uStack_8;
  
  if (param_1 == 0) {
    return 0x10;
  }
  if (param_5 == -1) {
    return 0x14;
  }
  if (param_3 == 0x46) {
    iVar1 = _ipc_object_translate(param_1,param_2,1,&uStack_10);
    if (iVar1 != 0) {
      return iVar1;
    }
    _ipc_port_nsrequest(uStack_10,param_4,param_5,param_6);
loc_4046A62:
    iVar1 = 0;
  }
  else {
    if (param_3 < 0x47) {
      if ((param_3 == 0x45) && (param_4 == 0)) {
        iVar1 = _ipc_object_translate(param_1,param_2,1,&uStack_8);
        if (iVar1 != 0) {
          return iVar1;
        }
        _ipc_port_pdrequest(uStack_8,param_5,&uStack_c);
        if ((uStack_c != 0) && ((uStack_c & 1) != 0)) {
          _ipc_port_release_send(uStack_c & 0xfffffffe);
          uStack_c = 0;
        }
        *param_6 = uStack_c;
        goto loc_4046A62;
      }
    }
    else if (param_3 == 0x48) {
      iVar1 = _ipc_right_dnrequest(param_1,param_2,-(int)-(param_4 != 0),param_5,param_6);
      if (iVar1 != 0) {
        return iVar1;
      }
      goto loc_4046A62;
    }
    iVar1 = 0x12;
  }
  return iVar1;
}
