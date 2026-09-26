
undefined4 _setprivexec(void)

{
  int *piVar1;
  
  piVar1 = *(int **)(dword_40B57D4 + 0x24);
  *(int *)(*(int *)(_active_threads + 0x80) + 0x5c) = *(int *)(*_active_u + 0x16) >> 0x1f;
  *(byte *)(*_active_u + 0x16) = *(byte *)(*_active_u + 0x16) & 0x7f | (*piVar1 != 0) << 7;
  return 0;
}

