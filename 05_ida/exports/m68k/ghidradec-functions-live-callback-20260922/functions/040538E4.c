
byte _thread_set_own_priority(uint param_1)

{
  int iVar1;
  char cVar2;
  char cVar3;
  char cVar4;
  char cVar5;
  byte bVar6;
  
  iVar1 = _active_threads;
  cVar5 = param_1 < *(uint *)(_active_threads + 0x50);
  if ((int)param_1 < (int)*(uint *)(_active_threads + 0x50)) {
    *(uint *)(_active_threads + 0x50) = param_1;
  }
  *(uint *)(iVar1 + 0x4c) = param_1;
  cVar2 = iVar1 < 0;
  cVar3 = iVar1 == 0;
  cVar4 = '\0';
  bVar6 = 0;
  _compute_priority(iVar1,1);
  return cVar5 << 4 | cVar2 << 3 | cVar3 << 2 | cVar4 << 1 | bVar6;
}

