
void _getpid(void)

{
  int iVar1;
  int iVar2;
  
  iVar2 = *(int *)(_active_threads + 0x80);
  iVar1 = *_active_u;
  *(int *)(iVar2 + 0x5c) = (int)*(sword *)(iVar1 + 0x30);
  *(int *)(iVar2 + 0x60) = (int)*(sword *)(iVar1 + 0x32);
  return;
}
