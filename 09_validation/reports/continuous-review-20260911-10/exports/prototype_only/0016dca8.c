
int _kern_serv_panic(undefined4 param_1,char *param_2)

{
  int iVar1;
  undefined1 local_128 [3];
  char local_125;
  int local_124;
  undefined4 local_120;
  mach_port_t local_11c;
  undefined4 local_118;
  int local_114;
  int local_110;
  int local_10c;
  undefined4 local_108;
  char local_104 [255];
  undefined1 local_5;
  
  local_110 = 0x30000000;
  local_10c = 0x800000c;
  local_108 = 1;
  _strncpy(local_104,param_2,0x100);
  local_5 = 0;
  local_125 = '\x01';
  local_124 = 0x124;
  local_120 = 0x100;
  local_118 = param_1;
  local_11c = _mig_get_reply_port();
  local_114 = 200;
  iVar1 = _msg_rpc(local_128,0,0x20,0,0);
  if (iVar1 == 0) {
    if (local_114 == 300) {
      if (((local_124 == 0x20) && (local_125 == '\x01')) && (local_110 == 0x10012002)) {
        iVar1 = local_10c;
        if (local_10c == 0) {
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
    _mig_dealloc_reply_port();
  }
  return iVar1;
}

