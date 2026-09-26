
int _kern_serv_section_by_name
              (undefined4 param_1,char *param_2,char *param_3,undefined4 *param_4,
              undefined4 *param_5)

{
  int iVar1;
  undefined1 local_44 [3];
  char local_41;
  int local_40;
  undefined4 local_3c;
  mach_port_t local_38;
  undefined4 local_34;
  int local_30;
  int local_2c;
  int local_28;
  int local_24;
  undefined4 local_20;
  uint local_1c;
  undefined4 local_18;
  char local_14 [15];
  undefined1 local_5;
  
  local_2c = 0x1001800c;
  _strncpy((char *)&local_28,param_2,0x10);
  local_1c = local_1c & 0xffffff;
  local_18 = 0x1001800c;
  _strncpy(local_14,param_3,0x10);
  local_5 = 0;
  local_41 = '\x01';
  local_40 = 0x40;
  local_3c = 0x100;
  local_34 = param_1;
  local_38 = _mig_get_reply_port();
  local_30 = 0xc9;
  iVar1 = _msg_rpc(local_44,0,0x30,0,0);
  if (iVar1 == 0) {
    if (local_30 == 0x12d) {
      if ((((local_40 == 0x30) && (local_41 == '\x01')) ||
          ((local_40 == 0x20 && ((local_41 == '\x01' && (local_28 != 0)))))) &&
         (local_2c == 0x10012002)) {
        if (local_28 != 0) {
          return local_28;
        }
        if ((local_24 == 0x10012002) && (*param_4 = local_20, local_1c == 0x10012002)) {
          *param_5 = local_18;
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
    _mig_dealloc_reply_port();
  }
  return iVar1;
}

