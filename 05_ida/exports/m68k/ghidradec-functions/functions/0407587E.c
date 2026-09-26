
void _od_go(int param_1)

{
  sword sVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  
  piVar2 = (int *)(param_1 + 0x18);
  if (piVar2 == (int *)*piVar2) {
                    /* WARNING: Subroutine does not return */
    _panic(aOdQueueEmpty);
  }
  iVar4 = _disksort_first(*piVar2);
  if (iVar4 == 0) {
                    /* WARNING: Subroutine does not return */
    _panic(aOdQueueEmpty);
  }
  sVar1 = *(sword *)(param_1 + 4);
  iVar3 = (uint)*(word *)((int)&DAT_40c3f9a +
                         (sword)(word)((uint)*(undefined4 *)(iVar4 + 0x1f) >> 0x1b) * 0xda) * 0x20;
  uVar5 = (uint)*(sword *)(*(int *)(_od_drive + iVar3 + 0x14) + 0xc);
  if (-1 < (int)uVar5) {
    _dk_busy = 1 << (uVar5 & 0x3f) | _dk_busy;
    *(int *)(_dk_xfer + uVar5 * 4) = *(int *)(_dk_xfer + uVar5 * 4) + 1;
    *(int *)(_dk_wds + uVar5 * 4) = (*(int *)(iVar4 + 0x14) >> 6) + *(int *)(_dk_wds + uVar5 * 4);
  }
  _od_setup(_od_ctrl + sVar1 * 0x28c,_od_drive + iVar3,iVar4);
  return;
}
