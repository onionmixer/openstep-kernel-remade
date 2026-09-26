
undefined4 _od_lock(int param_1)

{
  word wVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  sword sVar5;
  undefined4 *puVar6;
  undefined *puVar7;
  char *pcVar8;
  undefined4 *puVar9;
  
  wVar1 = *(word *)(*(int *)(*(int *)(_active_threads + 0xc) + 0x34) + 0x30);
  if (((param_1 == 0x2000640f) && (_od_lock_pid != 0)) ||
     ((param_1 == 0x20006410 && (wVar1 != _od_lock_pid)))) {
    uVar2 = 0x10;
  }
  else {
    _od_lock_pid = wVar1;
    if (param_1 == 0x20006410) {
      puVar7 = _od_drive;
      do {
        if ((((*(word *)((int)puVar7 + 0x18) & 0xc000) == 0xc000) &&
            (iVar4 = *(int *)((int)puVar7 + 8), iVar4 != 0)) &&
           ((*(byte *)(iVar4 + 0xd8) & 0x20) != 0)) {
          sVar5 = (sword)_od_blk_major;
          iVar3 = _getnewbuf_count();
          if (2 < iVar3) {
            _update((int)(sword)((sword)((iVar4 + -0x40c3ec8) * -0x2593f69b >> 1) << 3 | sVar5 << 8)
                    ,0xfffffff8);
          }
        }
        puVar7 = (undefined *)((int)puVar7 + 0x20);
      } while (puVar7 < &_od_empty);
    }
    puVar9 = _all_psets;
    if ((undefined4 **)_all_psets != &_all_psets) {
      do {
        for (puVar6 = (undefined4 *)puVar9[0x4c]; puVar6 != puVar9 + 0x4c;
            puVar6 = (undefined4 *)puVar6[6]) {
          pcVar8 = (char *)(*(int *)(puVar6[3] + 0x30) + 8);
          iVar4 = _strcmp(pcVar8,*(int *)(_kernel_task + 0x30) + 8);
          if (((iVar4 != 0) && (iVar4 = _strcmp(pcVar8,&aBiod), iVar4 != 0)) &&
             (((uint)_od_lock_pid != (int)*(sword *)(*(int *)(puVar6[3] + 0x34) + 0x30) &&
              (*pcVar8 != '\0')))) {
            if (param_1 == 0x2000640f) {
              _thread_suspend(puVar6);
            }
            else {
              _thread_resume(puVar6);
            }
          }
        }
        puVar6 = puVar9 + 0x50;
        puVar9 = (undefined4 *)*puVar6;
      } while ((undefined4 **)*puVar6 != &_all_psets);
    }
    if (param_1 == 0x2000640f) {
      _mfs_cache_clear();
    }
    if (param_1 == 0x20006410) {
      _od_lock_pid = 0;
    }
    uVar2 = 0;
  }
  return uVar2;
}
