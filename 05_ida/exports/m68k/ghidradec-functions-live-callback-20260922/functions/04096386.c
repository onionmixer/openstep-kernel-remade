
void _kdebug_send(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  
  iVar1 = dword_40C8F00;
  *(undefined4 *)(dword_40C8F00 + 0x2a) = param_2;
  _en_send(param_1,iVar1,0x242);
  return;
}

