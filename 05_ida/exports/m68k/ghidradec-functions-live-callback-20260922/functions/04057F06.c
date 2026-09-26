
int _kern_serv_section_by_name
              (undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 *param_4,
              undefined4 *param_5)

{
  int iVar1;
  undefined auStack_44 [3];
  char cStack_41;
  int iStack_40;
  undefined4 uStack_3c;
  undefined4 uStack_38;
  undefined4 uStack_34;
  int iStack_30;
  int iStack_2c;
  int iStack_28;
  int iStack_24;
  undefined4 uStack_20;
  uint uStack_1c;
  undefined4 uStack_18;
  undefined auStack_14 [15];
  undefined uStack_5;
  
  iStack_2c = 0xc800018;
  _strncpy(&iStack_28,param_2,0x10);
  uStack_1c = uStack_1c & 0xffffff00;
  uStack_18 = 0xc800018;
  _strncpy(auStack_14,param_3,0x10);
  uStack_5 = 0;
  cStack_41 = '\x01';
  iStack_40 = 0x40;
  uStack_3c = 0x100;
  uStack_34 = param_1;
  uStack_38 = _mig_get_reply_port();
  iStack_30 = 0xc9;
  iVar1 = _msg_rpc(auStack_44,0,0x30,0,0);
  if (iVar1 == 0) {
    if (iStack_30 == 0x12d) {
      if ((((iStack_40 == 0x30) && (cStack_41 == '\x01')) ||
          ((iStack_40 == 0x20 && ((cStack_41 == '\x01' && (iStack_28 != 0)))))) &&
         (iStack_2c == 0x2200018)) {
        if (iStack_28 != 0) {
          return iStack_28;
        }
        if ((iStack_24 == 0x2200018) && (*param_4 = uStack_20, uStack_1c == 0x2200018)) {
          *param_5 = uStack_18;
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

