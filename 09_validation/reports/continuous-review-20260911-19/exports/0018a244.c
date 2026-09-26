
undefined4 _suword(int param_1,undefined4 param_2)

{
  int in_FS_OFFSET;
  
  *(code **)(_active_threads + 0x74) = __analysis_fragment_0018a270;
  *(undefined4 *)(in_FS_OFFSET + param_1) = param_2;
  *(undefined4 *)(_active_threads + 0x74) = 0;
  return 0;
}

