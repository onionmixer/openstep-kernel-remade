
void sub_406EC7C(int param_1,int param_2,undefined4 param_3)

{
  uint uVar1;
  
  _fd_assign_dv(param_1,(param_2 + -0x40c36fc) * -0x33333333 >> 3);
  *(undefined4 *)(param_1 + 8) = 1;
  uVar1 = *(uint *)(param_1 + 0x124);
  *(uint *)(param_1 + 0x124) = uVar1 & 0xfffffffb;
  if ((uVar1 & 8) != 0) {
    *(uint *)(param_1 + 0x124) = uVar1 & 0xfffffff3;
    _vol_panel_remove(*(undefined4 *)(param_1 + 0x138));
  }
  _fd_basic_cmd(param_3,0x80);
  *(undefined4 *)(param_2 + 0x10) = 0;
  return;
}
