
/* WARNING: Removing unreachable block (ram,0x0406294c) */

void sub_40628FA(uint param_1)

{
  byte *pbVar1;
  int iVar2;
  uint uVar3;
  
  if ((char)(param_1 >> 0x18) != '\0') {
    iVar2 = (&unk_40B4E00)[param_1 >> 0x18];
    uVar3 = param_1 & 0xffffff;
    _lock_write(iVar2 + 0x34);
    if (*(int *)(iVar2 + 0x14) <= (int)uVar3) {
                    /* WARNING: Subroutine does not return */
      _panic(aVnodePagerDeal);
    }
    if ((int)uVar3 < *(int *)(iVar2 + 0x24)) {
      *(uint *)(iVar2 + 0x24) = uVar3;
    }
    pbVar1 = (byte *)(*(int *)(iVar2 + 0x10) + ((int)uVar3 >> 3));
    *pbVar1 = *pbVar1 & ~('\x01' << (param_1 & 7));
    *(int *)(iVar2 + 0x18) = *(int *)(iVar2 + 0x18) + 1;
    _lock_done(iVar2 + 0x34);
  }
  return;
}

