
int _tcp_disconnect(int param_1)

{
  int iVar1;
  
  iVar1 = *(int *)(*(int *)(param_1 + 0x20) + 0x18);
  if (*(sword *)(param_1 + 8) < 4) {
    iVar1 = _tcp_close(param_1);
  }
  else if ((*(char *)(iVar1 + 3) < '\0') && (*(sword *)(iVar1 + 4) == 0)) {
    iVar1 = _tcp_drop(param_1,0);
  }
  else {
    _soisdisconnecting(iVar1);
    _sbflush(iVar1 + 0x22);
    iVar1 = _tcp_usrclosed(param_1);
    if (iVar1 != 0) {
      _tcp_output(iVar1);
    }
  }
  return iVar1;
}

