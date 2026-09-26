
int _port_set_allocate_EXTERNAL(undefined4 param_1,undefined4 *param_2)

{
  int iVar1;
  mach_port_t unaff_EBX;
  undefined1 local_2c [3];
  char local_29;
  int local_28;
  undefined4 local_24;
  mach_port_t local_20;
  undefined4 local_1c;
  int local_18;
  int local_14;
  int local_10;
  int local_c;
  undefined4 local_8;
  
  local_29 = '\x01';
  local_28 = 0x18;
  local_24 = 0x100;
  local_1c = param_1;
  local_20 = _mig_get_reply_port();
  local_18 = 0x820;
  iVar1 = _msg_rpc(local_2c,0,0x28,0,0);
  if (iVar1 == 0) {
    if (local_18 == 0x884) {
      if ((((local_28 == 0x28) && (local_29 == '\x01')) ||
          ((local_28 == 0x20 && ((local_29 == '\x01' && (local_10 != 0)))))) &&
         (local_14 == 0x10012002)) {
        if (local_10 != 0) {
          return local_10;
        }
        if (local_c == 0x10012002) {
          *param_2 = local_8;
          return 0;
        }
      }
      iVar1 = -300;
    }
    else {
      iVar1 = -0x12d;
    }
  }
  else if (iVar1 == -0xca) {
                    /* WARNING: Subroutine does not return */
    _mig_dealloc_reply_port(unaff_EBX);
  }
  return iVar1;
}

