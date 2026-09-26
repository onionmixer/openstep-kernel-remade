
undefined4 _getproc(void)

{
  undefined4 uVar1;
  
  if (dword_40B317C < _max_proc) {
    dword_40B317C = dword_40B317C + 1;
    uVar1 = _zalloc(_proc_zone);
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}

