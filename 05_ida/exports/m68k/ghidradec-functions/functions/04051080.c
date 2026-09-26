
void _update_priority(int param_1)

{
  uint *puVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  
  uVar2 = _sched_tick - *(int *)(param_1 + 0x6c);
  *(int *)(param_1 + 0x6c) = _sched_tick;
  if (*(int *)(param_1 + 0x104) == *(int *)(param_1 + 0xf0)) {
    iVar3 = *(int *)(param_1 + 0xe8) - *(int *)(param_1 + 0x100);
    *(int *)(param_1 + 0x100) = *(int *)(param_1 + 0xe8);
  }
  else {
    iVar3 = _timer_delta(param_1 + 0xe8,param_1 + 0x100);
  }
  if (*(int *)(param_1 + 0xfc) == *(int *)(param_1 + 0xe0)) {
    iVar4 = *(int *)(param_1 + 0xd8) - *(int *)(param_1 + 0xf8);
    *(int *)(param_1 + 0xf8) = *(int *)(param_1 + 0xd8);
  }
  else {
    iVar4 = _timer_delta(param_1 + 0xd8,param_1 + 0xf8);
  }
  *(int *)(param_1 + 0x108) = iVar4 + iVar3 + *(int *)(param_1 + 0x108);
  *(int *)(param_1 + 0x10c) =
       *(int *)(*(int *)(param_1 + 0x178) + 0x168) * (iVar4 + iVar3) + *(int *)(param_1 + 0x10c);
  if (uVar2 < 0x1f) {
    *(int *)(param_1 + 100) = *(int *)(param_1 + 0x108) + *(int *)(param_1 + 100);
    *(int *)(param_1 + 0x68) = *(int *)(param_1 + 0x10c) + *(int *)(param_1 + 0x68);
    iVar3 = uVar2 * 8;
    puVar1 = (uint *)(_wait_shift + iVar3);
    uVar2 = *(uint *)(_wait_shift + iVar3 + 4);
    if ((int)uVar2 < 1) {
      *(uint *)(param_1 + 100) =
           (*(uint *)(param_1 + 100) >> (*puVar1 & 0x3f)) -
           (*(uint *)(param_1 + 100) >> (-uVar2 & 0x3f));
      *(uint *)(param_1 + 0x68) =
           (*(uint *)(param_1 + 0x68) >> (*puVar1 & 0x3f)) -
           (*(uint *)(param_1 + 0x68) >> (-*(int *)(_wait_shift + iVar3 + 4) & 0x3fU));
    }
    else {
      *(uint *)(param_1 + 100) =
           (*(uint *)(param_1 + 100) >> (uVar2 & 0x3f)) +
           (*(uint *)(param_1 + 100) >> (*puVar1 & 0x3f));
      *(uint *)(param_1 + 0x68) =
           (*(uint *)(param_1 + 0x68) >> (*(uint *)(_wait_shift + iVar3 + 4) & 0x3f)) +
           (*(uint *)(param_1 + 0x68) >> (*puVar1 & 0x3f));
    }
  }
  else {
    *(undefined4 *)(param_1 + 100) = 0;
    *(undefined4 *)(param_1 + 0x68) = 0;
  }
  *(undefined4 *)(param_1 + 0x108) = 0;
  *(undefined4 *)(param_1 + 0x10c) = 0;
  if ((*(int *)(param_1 + 0x5c) != 2) && (*(int *)(param_1 + 0x60) < 0)) {
    iVar3 = *(int *)(param_1 + 0x4c) - (*(uint *)(param_1 + 0x68) >> 0x19);
    if (iVar3 < 0) {
      iVar3 = 0;
    }
    *(int *)(param_1 + 0x54) = iVar3;
  }
  return;
}
