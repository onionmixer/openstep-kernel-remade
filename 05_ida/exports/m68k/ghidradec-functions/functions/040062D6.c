
void _newproc(undefined4 param_1)

{
  undefined4 uVar1;
  
  uVar1 = _alloc_posix_proc();
  _cloneproc(*_active_u,param_1,uVar1);
  return;
}
