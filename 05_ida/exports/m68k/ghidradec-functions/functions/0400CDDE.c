
void _ttywflush(undefined4 param_1)

{
  _ttywait(param_1);
  _ttyflush(param_1,1);
  return;
}

