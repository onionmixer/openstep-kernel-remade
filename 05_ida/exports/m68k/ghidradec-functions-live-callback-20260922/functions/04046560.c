
int _old_mach_port_get_receive_status(undefined4 param_1,undefined4 param_2,undefined4 *param_3)

{
  int iVar1;
  undefined4 auStack_28 [2];
  undefined4 uStack_20;
  undefined4 uStack_1c;
  undefined4 uStack_18;
  undefined4 uStack_14;
  undefined4 uStack_10;
  undefined4 uStack_c;
  undefined4 uStack_8;
  
  iVar1 = _mach_port_get_receive_status(param_1,param_2,auStack_28);
  if (iVar1 == 0) {
    *param_3 = auStack_28[0];
    param_3[1] = uStack_20;
    param_3[2] = uStack_1c;
    param_3[3] = uStack_18;
    param_3[4] = uStack_14;
    param_3[5] = uStack_10;
    param_3[6] = uStack_c;
    param_3[7] = uStack_8;
    iVar1 = 0;
  }
  return iVar1;
}

