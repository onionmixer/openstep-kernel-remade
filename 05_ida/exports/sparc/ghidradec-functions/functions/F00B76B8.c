
/* WARNING: Removing unreachable block (ram,0xf00b7794) */
/* WARNING: Removing unreachable block (ram,0xf00b7730) */

undefined8 _esp_sync_backoff(int param_1,int param_2)

{
  byte bVar1;
  char cVar2;
  int iVar3;
  undefined *puVar4;
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
  bVar1 = *(byte *)(param_2 + 9);
  iVar3 = param_1 + (uint)bVar1;
  if (*(char *)(iVar3 + 0x5e) == '\0') {
    cVar2 = *(char *)(param_1 + 0x31);
  }
  else {
    if (*(char *)(iVar3 + 0x6e) == '\0') {
      *(undefined *)(iVar3 + 0x6e) = 1;
      puVar4 = aTargetDDReduci;
    }
    else {
      *(undefined *)(iVar3 + 0x66) = 0;
      *(undefined *)(iVar3 + 0x5e) = 0;
      puVar4 = aTargetDDRevert;
      *(byte *)(param_1 + 0x7a) = *(byte *)(param_1 + 0x7a) | (byte)(1 << (bVar1 & 0x1f));
    }
    _esplog(param_1,3,puVar4,(uint)bVar1,*(undefined *)(param_2 + 10));
    *(byte *)(param_1 + 0x78) = *(byte *)(param_1 + 0x78) & ~(byte)(1 << (bVar1 & 0x1f));
    cVar2 = *(char *)(param_1 + 0x31);
  }
  if ((1 < (byte)(cVar2 - 3U)) && ((*(byte *)(param_1 + 0x32) & 0x80) == 0)) {
    *(byte *)(param_1 + 0x32) = *(byte *)(param_1 + 0x32) | 0x80;
    *(byte *)(*(int *)(param_1 + 0x9c) + 0x20) = *(byte *)(*(int *)(param_1 + 0x9c) + 0x20) | 0x80;
    _esplog(param_1,3,aRevertingToSlo);
  }
  return CONCAT44(param_2,param_1);
}
