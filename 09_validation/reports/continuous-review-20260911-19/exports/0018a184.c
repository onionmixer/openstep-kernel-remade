
undefined4 _fuword(int param_1)

{
  undefined4 uVar1;
  int in_FS_OFFSET;
  
  *(code **)(_active_threads + 0x74) = __analysis_fragment_0018a1ac;
  uVar1 = *(undefined4 *)(in_FS_OFFSET + param_1);
  *(undefined4 *)(_active_threads + 0x74) = 0;
  return uVar1;
}

