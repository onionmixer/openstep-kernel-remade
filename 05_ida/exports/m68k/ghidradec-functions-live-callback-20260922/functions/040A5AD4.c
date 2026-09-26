
int _thread_set_special_port_EXTERNAL(undefined4 param_1,int param_2,undefined4 param_3)

{
  int iVar1;
  undefined auStack_2c [3];
  char cStack_29;
  int iStack_28;
  undefined4 uStack_24;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  int iStack_18;
  int iStack_14;
  int iStack_10;
  undefined4 uStack_c;
  undefined4 uStack_8;
  
  iStack_14 = 0x2200018;
  iStack_10 = param_2;
  uStack_c = 0x6200018;
  uStack_8 = param_3;
  cStack_29 = '\0';
  iStack_28 = 0x28;
  uStack_24 = 0x100;
  uStack_1c = param_1;
  uStack_20 = _mig_get_reply_port();
  iStack_18 = 0x814;
  iVar1 = _msg_rpc(auStack_2c,0,0x20,0,0);
  if (iVar1 == 0) {
    if (iStack_18 == 0x878) {
      if (((iStack_28 == 0x20) && (cStack_29 == '\x01')) && (iStack_14 == 0x2200018)) {
        iVar1 = iStack_10;
        if (iStack_10 == 0) {
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

