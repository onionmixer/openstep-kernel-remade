
void * FUN_001cbc80(char *param_1)

{
  int iVar1;
  char cVar2;
  int *piVar3;
  void *pvVar4;
  uint uVar5;
  char *pcVar6;
  
  uVar5 = 0xffffffff;
  pcVar6 = param_1;
  do {
    if (uVar5 == 0) break;
    uVar5 = uVar5 - 1;
    cVar2 = *pcVar6;
    pcVar6 = pcVar6 + 1;
  } while (cVar2 != '\0');
  uVar5 = ~uVar5;
  if (uVar5 < 0xb5) {
    piVar3 = DAT_001e5568;
    if (DAT_001e5568 == (int *)0x0) {
      DAT_001e5568 = (int *)_simple_lock_alloc();
      *DAT_001e5568 = 0;
      piVar3 = DAT_001e5568;
    }
    do {
      do {
      } while (*piVar3 != 0);
      LOCK();
      iVar1 = *piVar3;
      *piVar3 = 1;
      UNLOCK();
    } while (iVar1 == 1);
    if (DAT_001e5564 < uVar5) {
      DAT_001e5564 = ((uVar5 + 0x167) / 0x168) * 0x168;
      DAT_001e5560 = (void *)_kalloc(DAT_001e5564);
    }
    pvVar4 = DAT_001e5560;
    _memmove(DAT_001e5560,param_1,uVar5);
    DAT_001e5560 = (void *)((int)DAT_001e5560 + uVar5);
    DAT_001e5564 = DAT_001e5564 - uVar5;
    LOCK();
    *DAT_001e5568 = 0;
    UNLOCK();
  }
  else {
    pvVar4 = (void *)_kalloc(uVar5);
    _memmove(pvVar4,param_1,uVar5);
  }
  return pvVar4;
}

