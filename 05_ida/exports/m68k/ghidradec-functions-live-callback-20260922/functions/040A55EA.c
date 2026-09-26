
int _port_deallocate_EXTERNAL(undefined4 param_1,int param_2)

{
  int iVar1;
  undefined auStack_24 [3];
  char cStack_21;
  int iStack_20;
  undefined4 uStack_1c;
  undefined4 uStack_18;
  undefined4 uStack_14;
  int iStack_10;
  int iStack_c;
  int iStack_8;
  
  iStack_c = 0x2200018;
  iStack_8 = param_2;
  cStack_21 = '\x01';
  iStack_20 = 0x20;
  uStack_1c = 0x100;
  uStack_14 = param_1;
  uStack_18 = _mig_get_reply_port();
  iStack_10 = 0x81d;
  iVar1 = _msg_rpc(auStack_24,0,0x20,0,0);
  if (iVar1 == 0) {
    if (iStack_10 == 0x881) {
      if (((iStack_20 == 0x20) && (cStack_21 == '\x01')) && (iStack_c == 0x2200018)) {
        iVar1 = iStack_8;
        if (iStack_8 == 0) {
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

