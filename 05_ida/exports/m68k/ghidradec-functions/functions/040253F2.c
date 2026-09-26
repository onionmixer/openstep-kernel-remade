
int _tcp_usrclosed(int param_1)

{
  switch(*(undefined2 *)(param_1 + 8)) {
  case :
  case :
  case :
    *(undefined2 *)(param_1 + 8) = 0;
    param_1 = _tcp_close(param_1);
    break;
  case :
  case :
    *(undefined2 *)(param_1 + 8) = 6;
    break;
  case :
    *(undefined2 *)(param_1 + 8) = 8;
  }
  if ((param_1 != 0) && (8 < *(sword *)(param_1 + 8))) {
    _soisdisconnected(*(undefined4 *)(*(int *)(param_1 + 0x20) + 0x18));
  }
  return param_1;
}
