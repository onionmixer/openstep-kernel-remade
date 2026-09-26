
undefined4 _logselect(undefined4 param_1,int param_2)

{
  if (param_2 == 1) {
    if (*(int *)(_pmsgbuf + 8) != *(int *)(_pmsgbuf + 4)) {
      return 1;
    }
    _selthreadcache(&dword_40B67E8);
  }
  return 0;
}

