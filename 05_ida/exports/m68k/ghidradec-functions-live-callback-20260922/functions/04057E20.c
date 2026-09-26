
int _kern_serv_panic(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  undefined auStack_128 [3];
  char cStack_125;
  int iStack_124;
  undefined4 uStack_120;
  undefined4 uStack_11c;
  undefined4 uStack_118;
  int iStack_114;
  int iStack_110;
  int iStack_10c;
  undefined4 uStack_108;
  undefined auStack_104 [255];
  undefined uStack_5;
  
  iStack_110 = 0xc;
  iStack_10c = 0xc0800;
  uStack_108 = 1;
  _strncpy(auStack_104,param_2,0x100);
  uStack_5 = 0;
  cStack_125 = '\x01';
  iStack_124 = 0x124;
  uStack_120 = 0x100;
  uStack_118 = param_1;
  uStack_11c = _mig_get_reply_port();
  iStack_114 = 200;
  iVar1 = _msg_rpc(auStack_128,0,0x20,0,0);
  if (iVar1 == 0) {
    if (iStack_114 == 300) {
      if (((iStack_124 == 0x20) && (cStack_125 == '\x01')) && (iStack_110 == 0x2200018)) {
        iVar1 = iStack_10c;
        if (iStack_10c == 0) {
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
                    /* WARNING: Subroutine does not return */
    _mig_dealloc_reply_port();
  }
  return iVar1;
}

