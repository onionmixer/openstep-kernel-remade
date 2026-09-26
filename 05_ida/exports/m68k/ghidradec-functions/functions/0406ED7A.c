
void _volume_notify(int param_1)

{
  word wVar1;
  int iVar2;
  undefined4 uVar3;
  uint uVar4;
  undefined4 uVar5;
  undefined auStack_5e [6];
  undefined auStack_58 [20];
  undefined auStack_44 [64];
  
  auStack_44[0] = 0;
  if ((*(uint *)(param_1 + 0x176) & 1) == 0) {
    uVar5 = 2;
  }
  else {
    uVar5 = 1;
    if ((*(uint *)(param_1 + 0x176) & 2) != 0) {
      uVar5 = 0;
    }
  }
  uVar4 = 1;
  if (*(int *)(param_1 + 0x172) != 0) {
    do {
      iVar2 = sub_406EE4E(uVar4);
      if (iVar2 < 0) {
        iVar2 = iVar2 + 0x3ff;
      }
      _sprintf(auStack_58,&aD,iVar2 >> 10);
      _strcat(auStack_44,auStack_58);
      uVar4 = uVar4 + 1;
    } while (uVar4 <= *(uint *)(param_1 + 0x172));
  }
  _sprintf(auStack_5e,&aFdD,*(undefined4 *)(param_1 + 0x10));
  uVar3 = 1;
  if ((*(byte *)(param_1 + 0x179) & 4) != 0) {
    uVar3 = 3;
  }
  wVar1 = (sword)*(undefined4 *)(param_1 + 0x10) << 3;
  _vol_notify_dev((int)(sword)(wVar1 | (sword)_fd_blk_major << 8),
                  (int)(sword)(wVar1 | (sword)_fd_raw_major << 8),auStack_44,uVar5,auStack_5e,uVar3)
  ;
  return;
}
