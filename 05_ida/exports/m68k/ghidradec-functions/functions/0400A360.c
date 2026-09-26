
void _getthetime(int *param_1)

{
  int iVar1;
  
  do {
    iVar1 = _mtime[1];
  } while (_mtime[2] != *_mtime);
  *param_1 = _mtime[2];
  param_1[1] = iVar1;
  return;
}
