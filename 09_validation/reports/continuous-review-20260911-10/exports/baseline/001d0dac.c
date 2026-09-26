
int _vm_protect_EXTERNAL
              (undefined4 param_1,int param_2,undefined4 param_3,undefined4 param_4,
              undefined4 param_5)

{
  int iVar1;
  mach_port_t unaff_EBX;
  undefined1 local_3c [3];
  char local_39;
  int local_38;
  undefined4 local_34;
  mach_port_t local_30;
  undefined4 local_2c;
  int local_28;
  int local_24;
  int local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  
  local_24 = 0x10012002;
  local_20 = param_2;
  local_1c = 0x10012002;
  local_18 = param_3;
  local_14 = 0x10012000;
  local_10 = param_4;
  local_c = 0x10012002;
  local_8 = param_5;
  local_39 = '\x01';
  local_38 = 0x38;
  local_34 = 0x100;
  local_2c = param_1;
  local_30 = _mig_get_reply_port();
  local_28 = 0x7e8;
  iVar1 = _msg_rpc(local_3c,0,0x20,0,0);
  if (iVar1 == 0) {
    if (local_28 == 0x84c) {
      if (((local_38 == 0x20) && (local_39 == '\x01')) && (local_24 == 0x10012002)) {
        iVar1 = local_20;
        if (local_20 == 0) {
          iVar1 = 0;
        }
      }
      else {
        iVar1 = -300;
      }
    }
    else {
      iVar1 = -0x12d;
    }
  }
  else if (iVar1 == -0xca) {
    _mig_dealloc_reply_port(unaff_EBX);
  }
  return iVar1;
}

