
int _fuibyte(int param_1)

{
  char cVar1;
  int in_FS_OFFSET;
  
  *(code **)(_active_threads + 0x74) = __analysis_fragment_0018a22c;
  cVar1 = *(char *)(in_FS_OFFSET + param_1);
  *(undefined4 *)(_active_threads + 0x74) = 0;
  return (int)cVar1;
}

