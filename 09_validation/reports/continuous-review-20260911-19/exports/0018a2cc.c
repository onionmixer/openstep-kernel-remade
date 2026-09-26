
undefined4 _suibyte(int param_1,undefined1 param_2)

{
  int in_FS_OFFSET;
  
  *(code **)(_active_threads + 0x74) = __analysis_fragment_0018a2f8;
  *(undefined1 *)(in_FS_OFFSET + param_1) = param_2;
  *(undefined4 *)(_active_threads + 0x74) = 0;
  return 0;
}

