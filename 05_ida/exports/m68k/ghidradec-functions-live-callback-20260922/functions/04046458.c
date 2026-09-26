
int _mach_port_get_refs(int param_1,undefined4 param_2,uint param_3,undefined4 *param_4)

{
  int iVar1;
  undefined4 uStack_10;
  uint uStack_c;
  undefined4 uStack_8;
  
  if (param_1 == 0) {
    iVar1 = 0x10;
  }
  else if (param_3 < 5) {
    iVar1 = _ipc_right_lookup_write(param_1,param_2,&uStack_8);
    if ((iVar1 == 0) &&
       (iVar1 = _ipc_right_info(param_1,param_2,uStack_8,&uStack_c,&uStack_10), iVar1 == 0)) {
      if ((1 << (param_3 + 0x10 & 0x3f) & uStack_c) == 0) {
        *param_4 = 0;
      }
      else {
        if (param_3 < 4) {
          if (param_3 != 0) {
            *param_4 = 1;
            return 0;
          }
        }
        else if (param_3 != 4) {
                    /* WARNING: Subroutine does not return */
          _panic(aMachPortGetRef);
        }
        *param_4 = uStack_10;
      }
    }
  }
  else {
    iVar1 = 0x12;
  }
  return iVar1;
}

