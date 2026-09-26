
/* WARNING: Removing unreachable block (ram,0xf00b4618) */

undefined8 _esp_ustart(int param_1,uint param_2)

{
  byte bVar1;
  sword sVar2;
  sword sVar3;
  int iVar4;
  int iVar5;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
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
  sVar3 = 0;
  if ((sword)param_2 == -1) {
    param_2 = 0;
  }
  if (*(uint *)(param_1 + 0x88) < *(uint *)(param_1 + 0x84)) {
    sVar2 = (sword)param_2;
    do {
      iVar4 = *(int *)(((int)(param_2 << 0x10) >> 0xe) + param_1 + 0xb8);
      if ((iVar4 == 0) || ((*(word *)(iVar4 + 0x5c) & 0x10) != 0)) {
        param_2 = param_2 + 1 & 0x3f;
      }
      else {
        sVar3 = sVar3 + 1;
      }
    } while ((sVar3 == 0) && ((sword)param_2 != sVar2));
    if (sVar3 != 0) {
      *(sword *)(param_1 + 0xb2) = (sword)param_2;
      bVar1 = *(byte *)(iVar4 + 0x2b);
      if (-1 < (char)bVar1) {
        iVar5 = (char)bVar1 * 4;
        *(int *)(_dk_xfer + iVar5) = *(int *)(_dk_xfer + iVar5) + 1;
        _dk_busy = _dk_busy | 1 << (bVar1 & 0x1f);
        if ((*(word *)(iVar4 + 0x5c) & 2) == 0) {
          *(int *)(_dk_read + iVar5) = *(int *)(_dk_read + iVar5) + 1;
        }
        *(uint *)(_dk_wds + iVar5) = *(int *)(_dk_wds + iVar5) + (*(uint *)(iVar4 + 0x40) >> 6);
      }
      _esp_startcmd(param_1);
      goto locret_F00B4624;
    }
  }
  param_1 = 0;
locret_F00B4624:
  return CONCAT44(param_2,param_1);
}

