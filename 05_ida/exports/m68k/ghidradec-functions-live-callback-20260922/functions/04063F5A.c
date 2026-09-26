
void _vol_panel_disk_num(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4
                        ,undefined4 param_5,int param_6,undefined4 param_7)

{
  undefined4 uVar1;
  
  uVar1 = 0;
  if (param_6 != 0) {
    uVar1 = 2;
  }
  _vol_panel_request(param_1,uVar1,2,param_2,param_3,param_4,0,&unk_40A62E7,&unk_40A62E7,param_5,
                     param_7);
  return;
}

