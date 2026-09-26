
void _init_task(void)

{
  char cVar1;
  int *piVar2;
  int iVar3;
  uint uVar4;
  size_t sVar5;
  char *pcVar6;
  
  uVar4 = 0xffffffff;
  pcVar6 = &DAT_001da02c;
  do {
    if (uVar4 == 0) break;
    uVar4 = uVar4 - 1;
    cVar1 = *pcVar6;
    pcVar6 = pcVar6 + 1;
  } while (cVar1 != '\0');
  sVar5 = 0x11;
  if (~uVar4 - 1 < 0x11) {
    sVar5 = ~uVar4;
  }
  _bcopy(&DAT_001da02c,(void *)(_active_u + 8),sVar5);
  piVar2 = DAT_001e875c;
  iVar3 = *(int *)(*(int *)(_active_threads + 0x28) + 0x70);
  if (iVar3 == 0) {
    iVar3 = _thread_user_state(_active_threads);
  }
  else {
    iVar3 = iVar3 + 0x84;
  }
  *piVar2 = iVar3;
  _load_init_program();
  _thread_exception_return();
  return;
}

