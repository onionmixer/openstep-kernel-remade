
void _vnode_pager_truncate(uint param_1)

{
  int *piVar1;
  undefined4 uVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  sword sVar6;
  bool bVar7;
  undefined auStack_3e [20];
  int iStack_2a;
  
  iVar3 = (&unk_40B4E00)[param_1 >> 0x18];
  piVar1 = *(int **)(iVar3 + 8);
  param_1 = param_1 & 0xffffff;
  if ((*(int *)(iVar3 + 0x20) <= (int)param_1) && (_swapfs_enabled == 0)) {
    _lock_write(iVar3 + 0x34);
    for (; param_1 = param_1 - 1, -1 < (int)param_1; param_1 = param_1 & 0xffff0000) {
      do {
        uVar4 = param_1;
        if ((int)param_1 < 0) {
          uVar4 = param_1 + 7;
        }
        bVar7 = ((int)*(char *)(*(int *)(iVar3 + 0x10) + ((int)uVar4 >> 3)) &
                1 << (param_1 + ((int)uVar4 >> 3) * -8 & 0x1f)) != 0;
      } while ((!bVar7) &&
              (sVar6 = (sword)param_1 + -1, param_1 = CONCAT22((sword)(param_1 >> 0x10),sVar6),
              sVar6 != -1));
      if (bVar7) {
        *(uint *)(iVar3 + 0x20) = param_1;
        break;
      }
    }
    iVar5 = *(int *)(iVar3 + 0x20) + 1;
    if (((*(int *)(iVar3 + 0x1c) != 0) && (*(int *)(iVar3 + 0x1c) < iVar5)) &&
       ((uint)(iVar5 << (_page_shift & 0x3f)) <= *(uint *)(*piVar1 + 0x14))) {
      _vattr_null(auStack_3e);
      iStack_2a = iVar5 << (_page_shift & 0x3f);
      uVar2 = *(undefined4 *)(_active_u + 0x1a);
      *(undefined4 *)(_active_u + 0x1a) = *(undefined4 *)(*piVar1 + 0x2c);
      iVar5 = (**(code **)(piVar1[7] + 0x18))(piVar1,auStack_3e,*(undefined4 *)(*piVar1 + 0x2c));
      if (iVar5 != 0) {
        _printf(aVnodeDeallocpa,*(undefined4 *)(iVar3 + 0x28),iVar5);
      }
      *(undefined4 *)(_active_u + 0x1a) = uVar2;
    }
    _lock_done(iVar3 + 0x34);
  }
  return;
}
