
/* WARNING: Type propagation algorithm not settling */

uint * sub_405589E(uint *param_1,int param_2)

{
  uint uVar1;
  char cVar2;
  byte bVar3;
  int iVar4;
  char in_XF;
  bool bVar5;
  uint *puStack_8;
  
  if (param_1 == (uint *)0x0) {
                    /* WARNING: Subroutine does not return */
    _panic(aZallocNullZone);
  }
  bVar5 = *(char *)(param_1 + 10) < '\0';
  if (bVar5) {
    _lock_write((int)param_1 + 0x2a);
  }
  else {
    bVar3 = in_XF << 4;
    in_XF = '\0';
    *param_1 = (int)(sword)(word)(byte)(bVar3 | bVar5 << 3 | (*(char *)(param_1 + 10) == '\0') << 2)
    ;
  }
  puStack_8 = (uint *)param_1[3];
  do {
    if (puStack_8 == (uint *)0x0) goto loc_40558EA;
    param_1[1] = param_1[1] + 1;
    param_1[3] = *puStack_8;
    in_XF = puStack_8 < (uint *)param_1[2];
    if (puStack_8 == (uint *)param_1[2]) {
      param_1[2] = 0;
    }
    while( true ) {
      if (puStack_8 != (uint *)0x0) goto loc_4055B30;
loc_40558EA:
      if (param_1[8] == 0) break;
      if (param_2 == 0) {
        if (-1 < *(char *)(param_1 + 10)) {
          return (uint *)0x0;
        }
        _lock_done((int)param_1 + 0x2a);
        return (uint *)0x0;
      }
      _assert_wait(param_1 + 8,1);
      if (*(char *)(param_1 + 10) < '\0') {
        _lock_done((int)param_1 + 0x2a);
      }
      else {
        in_XF = (*param_1 & 0x10) != 0;
      }
      _thread_block_with_continuation(0);
      if (*(char *)(param_1 + 10) < '\0') {
        _lock_write((int)param_1 + 0x2a);
      }
      else {
        bVar3 = in_XF << 4;
        in_XF = '\0';
        *param_1 = (int)(sword)(word)(byte)(bVar3 | (*(char *)(param_1 + 10) == '\0') << 2);
      }
    }
    if (*(char *)(param_1 + 10) < '\0') {
      uVar1 = param_1[7];
    }
    else {
      uVar1 = param_1[6];
    }
    in_XF = param_1[5] < uVar1 + param_1[4];
    if ((bool)in_XF) {
      bVar3 = *(byte *)(param_1 + 10);
      if ((bVar3 & 0x20) != 0) {
loc_4055B30:
        cVar2 = *(char *)(param_1 + 10);
        goto joined_r0x04055b34;
      }
      if ((bVar3 & 0x10) == 0) {
        if (_zone_ignore_overflow == 0) {
          if ((char)bVar3 < '\0') {
            _lock_done((int)param_1 + 0x2a);
          }
          if (param_2 == 0) {
            return (uint *)0x0;
          }
          _printf(aZoneSEmpty,param_1[9]);
                    /* WARNING: Subroutine does not return */
          _panic(&aZalloc);
        }
      }
      else {
        uVar1 = param_1[5];
        in_XF = CARRY4(uVar1 >> 1,uVar1);
        param_1[5] = (uVar1 >> 1) + uVar1;
      }
    }
    if ((*(char *)(param_1 + 10) < '\0') && (param_1[8] = 1, *(char *)(param_1 + 10) < '\0')) {
      _lock_done((int)param_1 + 0x2a);
    }
    else {
      in_XF = (*param_1 & 0x10) != 0;
    }
    if (-1 < *(char *)(param_1 + 10)) {
      puStack_8 = (uint *)_zget_space(*(undefined4 *)((int)param_1 + 0x32),param_1[6],param_2);
      if (puStack_8 == (uint *)0x0) {
        if (param_2 == 0) {
          return (uint *)0x0;
        }
                    /* WARNING: Subroutine does not return */
        _panic(&aZalloc);
      }
      if (*(char *)(param_1 + 10) < '\0') {
        _lock_write((int)param_1 + 0x2a);
      }
      else {
        *param_1 = (int)(sword)(word)(byte)(in_XF << 4 | (*(char *)(param_1 + 10) == '\0') << 2);
      }
      param_1[1] = param_1[1] + 1;
      param_1[4] = param_1[6] + param_1[4];
      cVar2 = *(char *)(param_1 + 10);
joined_r0x04055b34:
      if (-1 < cVar2) {
        return puStack_8;
      }
      _lock_done((int)param_1 + 0x2a);
      return puStack_8;
    }
    iVar4 = _kmem_alloc_pageable(_zone_map,&puStack_8,param_1[7]);
    if (iVar4 != 0) {
                    /* WARNING: Subroutine does not return */
      _panic(&aZalloc);
    }
    _zcram(param_1,puStack_8,param_1[7]);
    if (*(char *)(param_1 + 10) < '\0') {
      _lock_write((int)param_1 + 0x2a);
    }
    else {
      bVar3 = in_XF << 4;
      in_XF = '\0';
      *param_1 = (int)(sword)(word)(byte)(bVar3 | (*(char *)(param_1 + 10) == '\0') << 2);
    }
    param_1[8] = 0;
    _thread_wakeup_prim(param_1 + 8,0,0);
    puStack_8 = (uint *)param_1[3];
  } while( true );
}

