
undefined4 _selthreadcache(int *param_1)

{
  int iVar1;
  
  iVar1 = *param_1;
  if (iVar1 != 0) {
    if ((*(int *)(iVar1 + 0x170) != 0) && (*(undefined4 **)(iVar1 + 0x38) == &_selwait)) {
      return 1;
    }
    *param_1 = 0;
    _thread_deallocate(iVar1);
  }
  iVar1 = _active_threads;
  _thread_reference(_active_threads);
  *param_1 = iVar1;
  return 0;
}
