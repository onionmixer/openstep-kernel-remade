
int _vm_read_EXTERNAL(undefined4 param_1,int param_2,int param_3,undefined4 *param_4,
                     undefined4 *param_5)

{
  int iVar1;
  undefined auStack_34 [3];
  char cStack_31;
  int iStack_30;
  undefined4 uStack_2c;
  undefined4 uStack_28;
  undefined4 uStack_24;
  int iStack_20;
  int iStack_1c;
  int iStack_18;
  undefined4 uStack_14;
  int iStack_10;
  undefined4 uStack_c;
  undefined4 uStack_8;
  
  iStack_1c = 0x2200018;
  iStack_18 = param_2;
  uStack_14 = 0x2200018;
  iStack_10 = param_3;
  cStack_31 = '\x01';
  iStack_30 = 0x28;
  uStack_2c = 0x100;
  uStack_24 = param_1;
  uStack_28 = _mig_get_reply_port();
  iStack_20 = 0x7ea;
  iVar1 = _msg_rpc(auStack_34,0,0x30,0,0);
  if (iVar1 == 0) {
    if (iStack_20 == 0x84e) {
      if ((((iStack_30 == 0x30) && (cStack_31 == '\0')) ||
          ((iStack_30 == 0x20 && ((cStack_31 == '\x01' && (iStack_18 != 0)))))) &&
         (iStack_1c == 0x2200018)) {
        if (iStack_18 != 0) {
          return iStack_18;
        }
        if ((((byte)uStack_14 & 0xc) == 4) && (iStack_10 == 0x90008)) {
          *param_4 = uStack_8;
          *param_5 = uStack_c;
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
    _mig_dealloc_reply_port();
  }
  return iVar1;
}

