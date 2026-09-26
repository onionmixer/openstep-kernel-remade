
void _proc_cache_clear(void)

{
  int iVar1;
  
  iVar1 = _freeproc;
  while (iVar1 != 0) {
    dword_40B317C = dword_40B317C + -1;
    _freeproc = *(int *)(iVar1 + 8);
    _zfree(_proc_zone,iVar1);
    iVar1 = _freeproc;
  }
  _freeproc = iVar1;
  return;
}

