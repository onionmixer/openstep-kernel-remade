
void _fd_seek(int param_1,undefined4 param_2,undefined4 param_3)

{
  undefined auStack_5e [90];
  
  _bzero(auStack_5e,0x5a);
  _fd_gen_seek(*(undefined4 *)(param_1 + 0x17a),auStack_5e,param_2,param_3);
  _fd_command(param_1,auStack_5e);
  return;
}
