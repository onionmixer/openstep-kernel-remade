
void _fd_raw_rw(int param_1,undefined4 param_2,int param_3,undefined4 param_4,undefined4 param_5)

{
  undefined auStack_5e [90];
  
  _bzero(auStack_5e,0x5a);
  sub_406DCC0(param_1,auStack_5e,param_2,*(int *)(param_1 + 0x186) * param_3,param_4,param_5);
  _fd_command(param_1,auStack_5e);
  return;
}
