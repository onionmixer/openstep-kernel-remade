
/* WARNING: Removing unreachable block (ram,0xf0071aac) */
/* WARNING: Removing unreachable block (ram,0xf0071ae0) */
/* WARNING: Removing unreachable block (ram,0xf0071a78) */

undefined8 _update_priority(int param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  byte bVar3;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  uint uVar4;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 unaff_i1;
  undefined4 unaff_i2;
  undefined4 unaff_i3;
  undefined4 unaff_i4;
  undefined4 unaff_i5;
  undefined4 unaff_fp;
  undefined4 unaff_i7;
  bool in_DECOMPILE_MODE;
  int in_CWP;
  
  iVar2 = _sched_tick;
  if (!in_DECOMPILE_MODE) {
    *(undefined4 *)(in_CWP * 0x40 + 0x8000) = unaff_i0;
    *(undefined4 *)((in_CWP * 0x10 + 1) * 4 + 0x8000) = unaff_i1;
    *(undefined4 *)((in_CWP * 0x10 + 2) * 4 + 0x8000) = unaff_i2;
    *(undefined4 *)((in_CWP * 0x10 + 3) * 4 + 0x8000) = unaff_i3;
    *(undefined4 *)((in_CWP * 0x10 + 4) * 4 + 0x8000) = unaff_i4;
    *(undefined4 *)((in_CWP * 0x10 + 5) * 4 + 0x8000) = unaff_i5;
    *(undefined4 *)((in_CWP * 0x10 + 6) * 4 + 0x8000) = unaff_fp;
    *(undefined4 *)((in_CWP * 0x10 + 7) * 4 + 0x8000) = unaff_i7;
    *(undefined4 *)((in_CWP * 0x10 + 8) * 4 + 0x8000) = unaff_l0;
    *(undefined4 *)((in_CWP * 0x10 + 9) * 4 + 0x8000) = unaff_l1;
    *(undefined4 *)((in_CWP * 0x10 + 10) * 4 + 0x8000) = unaff_l3;
    *(undefined4 *)((in_CWP * 0x10 + 0xb) * 4 + 0x8000) = unaff_l3;
    *(undefined4 *)((in_CWP * 0x10 + 0xc) * 4 + 0x8000) = unaff_l4;
    *(undefined4 *)((in_CWP * 0x10 + 0xd) * 4 + 0x8000) = unaff_l5;
    *(undefined4 *)((in_CWP * 0x10 + 0xe) * 4 + 0x8000) = unaff_l6;
    *(undefined4 *)((in_CWP * 0x10 + 0xf) * 4 + 0x8000) = unaff_l7;
  }
  iVar1 = *(int *)(param_1 + 0x70);
  *(int *)(param_1 + 0x70) = _sched_tick;
  uVar4 = iVar2 - iVar1;
  if (*(int *)(param_1 + 0x10c) == *(int *)(param_1 + 0xf8)) {
    iVar2 = *(int *)(param_1 + 0xf0) - *(int *)(param_1 + 0x108);
    *(int *)(param_1 + 0x108) = *(int *)(param_1 + 0xf0);
  }
  else {
    iVar2 = param_1 + 0xf0;
    _timer_delta(iVar2,param_1 + 0x108);
  }
  if (*(int *)(param_1 + 0x104) == *(int *)(param_1 + 0xe8)) {
    iVar1 = *(int *)(param_1 + 0xe0) - *(int *)(param_1 + 0x100);
    *(int *)(param_1 + 0x100) = *(int *)(param_1 + 0xe0);
  }
  else {
    iVar1 = param_1 + 0xe0;
    _timer_delta(iVar1,param_1 + 0x100);
  }
  iVar2 = iVar2 + iVar1;
  *(int *)(param_1 + 0x110) = *(int *)(param_1 + 0x110) + iVar2;
  umul(iVar2,*(undefined4 *)(*(int *)(param_1 + 400) + 0x178));
  *(int *)(param_1 + 0x114) = *(int *)(param_1 + 0x114) + iVar2;
  if (uVar4 < 0x1f) {
    iVar2 = uVar4 * 8;
    *(int *)(param_1 + 0x68) = *(int *)(param_1 + 0x68) + *(int *)(param_1 + 0x110);
    *(int *)(param_1 + 0x6c) = *(int *)(param_1 + 0x6c) + *(int *)(param_1 + 0x114);
    uVar4 = *(uint *)(param_1 + 0x68);
    bVar3 = (byte)*(int *)(_wait_shift + iVar2 + 4);
    if (*(int *)(_wait_shift + iVar2 + 4) < 1) {
      *(uint *)(param_1 + 0x68) =
           (uVar4 >> ((byte)*(undefined4 *)(_wait_shift + iVar2) & 0x1f)) -
           (uVar4 >> (-bVar3 & 0x1f));
      *(uint *)(param_1 + 0x6c) =
           (*(uint *)(param_1 + 0x6c) >> ((byte)*(undefined4 *)(_wait_shift + iVar2) & 0x1f)) -
           (*(uint *)(param_1 + 0x6c) >> (-(char)*(undefined4 *)(_wait_shift + iVar2 + 4) & 0x1fU));
    }
    else {
      *(uint *)(param_1 + 0x68) =
           (uVar4 >> ((byte)*(undefined4 *)(_wait_shift + iVar2) & 0x1f)) +
           (uVar4 >> (bVar3 & 0x1f));
      *(uint *)(param_1 + 0x6c) =
           (*(uint *)(param_1 + 0x6c) >> ((byte)*(undefined4 *)(_wait_shift + iVar2) & 0x1f)) +
           (*(uint *)(param_1 + 0x6c) >> ((byte)*(undefined4 *)(_wait_shift + iVar2 + 4) & 0x1f));
    }
  }
  else {
    *(undefined4 *)(param_1 + 0x68) = 0;
    *(undefined4 *)(param_1 + 0x6c) = 0;
  }
  *(undefined4 *)(param_1 + 0x110) = 0;
  *(undefined4 *)(param_1 + 0x114) = 0;
  if ((*(int *)(param_1 + 0x60) != 2) && (*(int *)(param_1 + 100) < 0)) {
    iVar2 = *(int *)(param_1 + 0x50) - (*(uint *)(param_1 + 0x6c) >> 0x19);
    if (iVar2 < 0) {
      iVar2 = 0;
    }
    *(int *)(param_1 + 0x58) = iVar2;
  }
  return CONCAT44(param_2,param_1);
}

