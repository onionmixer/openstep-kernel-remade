
int _vm_allocate_EXTERNAL(undefined4 param_1,int *param_2,int param_3,undefined4 param_4)

{
  int iVar1;
  mach_port_t unaff_EBX;
  undefined1 local_34 [3];
  char local_31;
  int local_30;
  undefined4 local_2c;
  mach_port_t local_28;
  undefined4 local_24;
  int local_20;
  int local_1c;
  int local_18;
  int local_14;
  int local_10;
  undefined4 local_c;
  undefined4 local_8;
  
  local_1c = 0x10012002;
  local_18 = *param_2;
  local_14 = 0x10012002;
  local_10 = param_3;
  local_c = 0x10012000;
  local_8 = param_4;
  local_31 = '\x01';
  local_30 = 0x30;
  local_2c = 0x100;
  local_24 = param_1;
  local_28 = _mig_get_reply_port();
  local_20 = 0x7e5;
  iVar1 = _msg_rpc(local_34,0,0x28,0,0);
  if (iVar1 == 0) {
    if (local_20 == 0x849) {
      if ((((local_30 == 0x28) && (local_31 == '\x01')) ||
          ((local_30 == 0x20 && ((local_31 == '\x01' && (local_18 != 0)))))) &&
         (local_1c == 0x10012002)) {
        if (local_18 != 0) {
          return local_18;
        }
        if (local_14 == 0x10012002) {
          *param_2 = local_10;
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

