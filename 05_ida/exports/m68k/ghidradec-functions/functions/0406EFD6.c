
void sub_406EFD6(int param_1,undefined4 param_2)

{
  int iVar1;
  
  if ((*(byte *)(param_1 + 0x179) & 2) == 0) {
    iVar1 = _vol_panel_disk_num(sub_406F052,*(undefined4 *)(param_1 + 0x10),0,
                                *(undefined4 *)(param_1 + 8),param_1,param_2,param_1 + 0x138);
  }
  else {
    iVar1 = _vol_panel_disk_label
                      (sub_406F052,*(int *)(param_1 + 0x14) + 0xc,0,*(undefined4 *)(param_1 + 8),
                       param_1,param_2,param_1 + 0x138);
  }
  if (iVar1 != 0) {
    _printf(aFdAlertPanelVo,iVar1);
  }
  *(uint *)(param_1 + 0x124) = *(uint *)(param_1 + 0x124) | 8;
  return;
}
