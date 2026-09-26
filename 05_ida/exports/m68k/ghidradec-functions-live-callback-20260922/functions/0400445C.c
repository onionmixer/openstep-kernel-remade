
int _ufalloc(int param_1)

{
  while( true ) {
    if (0xff < param_1) {
      *(undefined *)(dword_40B57D4 + 100) = 0x18;
      return -1;
    }
    _expand_fdlist(*(undefined4 *)(*(int *)(_active_threads + 0xc) + 0x30),param_1);
    if (*(int *)(*(int *)(_active_u + 0x146) + param_1 * 4) == 0) break;
    param_1 = param_1 + 1;
  }
  *(int *)(dword_40B57D4 + 0x5c) = param_1;
  *(undefined *)(param_1 + *(int *)(_active_u + 0x14a)) = 0;
  if (*(int *)(_active_u + 0x14e) < param_1) {
    *(int *)(_active_u + 0x14e) = param_1;
  }
  *(undefined4 *)(*(int *)(_active_u + 0x146) + param_1 * 4) = 0xffff0000;
  return param_1;
}

