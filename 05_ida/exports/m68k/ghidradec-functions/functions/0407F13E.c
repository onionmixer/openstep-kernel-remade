
void sub_407F13E(int *param_1,undefined4 param_2)

{
  int iVar1;
  
  if ((param_1[2] & 0x84U) == 0x84) {
    iVar1 = _vol_panel_disk_label
                      (sub_407F1EE,*(int *)((int)param_1 + 0xd2) + 0xc,2,
                       (*param_1 + -0x40c5e78) * 0x5f02a3a1 >> 1,param_1,param_2,(int)param_1 + 0x12
                      );
  }
  else {
    iVar1 = _vol_panel_disk_num(sub_407F1EE,param_1[1],2,(*param_1 + -0x40c5e78) * 0x5f02a3a1 >> 1,
                                param_1,param_2,(int)param_1 + 0x12);
  }
  if (iVar1 != 0) {
    _printf(aSdAlertPanelVo,iVar1);
  }
  param_1[2] = param_1[2] | 8;
  return;
}
