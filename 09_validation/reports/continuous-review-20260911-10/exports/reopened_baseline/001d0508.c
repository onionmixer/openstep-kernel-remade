
int _port_deallocate_EXTERNAL(undefined4 param_1,int param_2)

{
  int iVar1;
  mach_port_t unaff_EBX;
  undefined1 local_24 [3];
  char local_21;
  int local_20;
  undefined4 local_1c;
  mach_port_t local_18;
  undefined4 local_14;
  int local_10;
  int local_c;
  int local_8;
  
  local_c = 0x10012002;
  local_8 = param_2;
  local_21 = '\x01';
  local_20 = 0x20;
  local_1c = 0x100;
  local_14 = param_1;
  local_18 = _mig_get_reply_port();
  local_10 = 0x81d;
  iVar1 = _msg_rpc(local_24,0,0x20,0,0);
  if (iVar1 == 0) {
    if (local_10 == 0x881) {
      if (((local_20 == 0x20) && (local_21 == '\x01')) && (local_c == 0x10012002)) {
        iVar1 = local_8;
        if (local_8 == 0) {
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

