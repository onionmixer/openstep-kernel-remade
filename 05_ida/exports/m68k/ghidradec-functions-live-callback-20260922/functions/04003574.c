
void _gatherstats(undefined4 param_1,uint param_2)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  undefined *puVar4;
  
  if ((param_2 & 0x2000) == 0) {
    iVar3 = 0;
    if ('\0' < *(char *)(*_active_u + 0x15)) {
      iVar3 = 1;
    }
  }
  else {
    iVar3 = 2;
    if ((*(char *)(_active_threads + 0x4b) < '\0') && ((param_2 & 0x700) == 0)) {
      iVar3 = 3;
    }
  }
  *(int *)(_cp_time + iVar3 * 4) = *(int *)(_cp_time + iVar3 * 4) + 1;
  uVar1 = _dk_busy;
  uVar2 = 0;
  puVar4 = _dk_time;
  do {
    if ((uVar1 & 1 << (uVar2 & 0x1f)) != 0) {
      *(int *)puVar4 = *(int *)puVar4 + 1;
    }
    puVar4 = (undefined *)((int)puVar4 + 4);
    uVar2 = uVar2 + 1;
  } while ((int)uVar2 < 4);
  return;
}

