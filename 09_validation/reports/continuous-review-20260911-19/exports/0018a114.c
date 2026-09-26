
undefined4 _copyoutstr(char *param_1,int param_2,int param_3,int *param_4)

{
  char cVar1;
  int iVar2;
  bool bVar3;
  int in_FS_OFFSET;
  
  *(code **)(_active_threads + 0x74) = __analysis_fragment_0018a168;
  iVar2 = param_3;
  do {
    bVar3 = iVar2 < 1;
    iVar2 = iVar2 + -1;
    if (bVar3) break;
    cVar1 = *param_1;
    *(char *)(in_FS_OFFSET + param_2) = cVar1;
    param_2 = param_2 + 1;
    param_1 = param_1 + 1;
  } while (cVar1 != '\0');
  if (param_4 != (int *)0x0) {
    *param_4 = param_3 - iVar2;
  }
  *(undefined4 *)(_active_threads + 0x74) = 0;
  return 0;
}

