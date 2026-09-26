
void _fd_get_status(undefined4 param_1,undefined2 *param_2)

{
  undefined auStack_5e [2];
  undefined4 uStack_5c;
  undefined4 uStack_58;
  undefined2 uStack_10;
  
  _bzero(auStack_5e,0x5a);
  uStack_58 = 5;
  uStack_5c = 10000;
  _fd_command(param_1,auStack_5e);
  *param_2 = uStack_10;
  return;
}
