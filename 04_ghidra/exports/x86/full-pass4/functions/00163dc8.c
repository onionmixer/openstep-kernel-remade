/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00163dc8 */

void _update_priority(int param_1)

{
  int iVar1;
  int iVar2;
  byte bVar3;
  uint uVar4;
  
  uVar4 = _sched_tick - *(int *)(param_1 + 0x70);
  *(int *)(param_1 + 0x70) = _sched_tick;
  if (*(int *)(param_1 + 0x10c) == *(int *)(param_1 + 0xf8)) {
    iVar1 = *(int *)(param_1 + 0xf0) - *(int *)(param_1 + 0x108);
    *(int *)(param_1 + 0x108) = *(int *)(param_1 + 0xf0);
  }
  else {
    iVar1 = _timer_delta(param_1 + 0xf0,param_1 + 0x108);
  }
  if (*(int *)(param_1 + 0x104) == *(int *)(param_1 + 0xe8)) {
    iVar2 = *(int *)(param_1 + 0xe0) - *(int *)(param_1 + 0x100);
    *(int *)(param_1 + 0x100) = *(int *)(param_1 + 0xe0);
  }
  else {
    iVar2 = _timer_delta(param_1 + 0xe0,param_1 + 0x100);
  }
  *(int *)(param_1 + 0x110) = *(int *)(param_1 + 0x110) + iVar1 + iVar2;
  *(int *)(param_1 + 0x114) =
       *(int *)(param_1 + 0x114) + (iVar1 + iVar2) * *(int *)(*(int *)(param_1 + 0x180) + 0x178);
  if (uVar4 < 0x1f) {
    *(int *)(param_1 + 0x68) = *(int *)(param_1 + 0x68) + *(int *)(param_1 + 0x110);
    *(int *)(param_1 + 0x6c) = *(int *)(param_1 + 0x6c) + *(int *)(param_1 + 0x114);
    iVar1 = uVar4 * 8;
    bVar3 = (byte)*(int *)(&DAT_001df588 + iVar1);
    if (*(int *)(&DAT_001df588 + iVar1) < 1) {
      *(uint *)(param_1 + 0x68) =
           (*(uint *)(param_1 + 0x68) >> ((byte)*(undefined4 *)(&_wait_shift + iVar1) & 0x1f)) -
           (*(uint *)(param_1 + 0x68) >> (-bVar3 & 0x1f));
      iVar1 = (*(uint *)(param_1 + 0x6c) >> ((byte)*(undefined4 *)(&_wait_shift + iVar1) & 0x1f)) -
              (*(uint *)(param_1 + 0x6c) >> (-(char)*(undefined4 *)(&DAT_001df588 + iVar1) & 0x1fU))
      ;
    }
    else {
      *(uint *)(param_1 + 0x68) =
           (*(uint *)(param_1 + 0x68) >> ((byte)*(undefined4 *)(&_wait_shift + iVar1) & 0x1f)) +
           (*(uint *)(param_1 + 0x68) >> (bVar3 & 0x1f));
      iVar1 = (*(uint *)(param_1 + 0x6c) >> ((byte)*(undefined4 *)(&_wait_shift + iVar1) & 0x1f)) +
              (*(uint *)(param_1 + 0x6c) >> ((byte)*(undefined4 *)(&DAT_001df588 + iVar1) & 0x1f));
    }
    *(int *)(param_1 + 0x6c) = iVar1;
  }
  else {
    *(undefined4 *)(param_1 + 0x68) = 0;
    *(undefined4 *)(param_1 + 0x6c) = 0;
  }
  *(undefined4 *)(param_1 + 0x110) = 0;
  *(undefined4 *)(param_1 + 0x114) = 0;
  if ((*(int *)(param_1 + 0x60) != 2) && (*(int *)(param_1 + 100) < 0)) {
    iVar1 = *(int *)(param_1 + 0x50) - (*(uint *)(param_1 + 0x6c) >> 0x19);
    if (iVar1 < 0) {
      iVar1 = 0;
    }
    *(int *)(param_1 + 0x58) = iVar1;
  }
  return;
}

