
void _vol_panel_disk_label
               (undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
               undefined4 param_5,int param_6,undefined4 param_7)

{
  undefined4 uVar1;
  
  uVar1 = 1;
  if (param_6 != 0) {
    uVar1 = 3;
  }
  _vol_panel_request(param_1,uVar1,2,0,param_3,param_4,0,param_2,&unk_40A62E7,param_5,param_7);
  return;
}

