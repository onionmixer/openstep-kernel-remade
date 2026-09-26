
void _ipc_space_release(int *param_1)

{
  int iVar1;
  
  iVar1 = *param_1;
  *param_1 = iVar1 + -1;
  if (iVar1 == 1) {
    _zfree(_ipc_space_zone,param_1);
  }
  return;
}
