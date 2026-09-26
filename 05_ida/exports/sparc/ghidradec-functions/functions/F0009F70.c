
undefined8 _gatherstats(undefined4 param_1,uint param_2)

{
  int iVar1;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 unaff_i1;
  uint uVar2;
  int iVar3;
  undefined4 unaff_i2;
  undefined *puVar4;
  undefined4 unaff_i3;
  byte bVar6;
  int iVar5;
  undefined4 unaff_i4;
  undefined4 unaff_i5;
  undefined4 unaff_fp;
  undefined4 unaff_i7;
  bool in_DECOMPILE_MODE;
  int in_CWP;
  
  iVar1 = _dk_busy;
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
  if ((param_2 & 0x40) == 0) {
    uVar2 = (uint)('\0' < *(char *)(*_active_u + 0x15));
  }
  else {
    uVar2 = 2;
    if (((*(uint *)(_active_threads + 0x4c) & 0x80) != 0) && ((param_2 & 0xf00) == 0)) {
      uVar2 = 3;
    }
  }
  iVar5 = 0;
  puVar4 = _dk_time;
  iVar3 = uVar2 * 4;
  *(int *)(_cp_time + iVar3) = *(int *)(_cp_time + iVar3) + 1;
  do {
    bVar6 = (byte)iVar5;
    iVar5 = iVar5 + 1;
    if ((iVar1 >> (bVar6 & 0x1f) & 1U) != 0) {
      *(int *)puVar4 = *(int *)puVar4 + 1;
    }
    puVar4 = (undefined *)((int)puVar4 + 4);
  } while (iVar5 < 4);
  return CONCAT44(iVar3,_cp_time);
}
