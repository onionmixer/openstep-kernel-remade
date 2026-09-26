
int _fd_basic_cmd(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  undefined auStack_5e [2];
  undefined4 uStack_5c;
  undefined4 uStack_58;
  int iStack_20;
  
  _bzero(auStack_5e,0x5a);
  uStack_58 = param_2;
  uStack_5c = 10000;
  iVar1 = _fd_command(param_1,auStack_5e);
  if (iVar1 == 0) {
    iVar1 = iStack_20;
  }
  return iVar1;
}
