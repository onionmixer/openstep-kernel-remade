
int _fc_send_cmd(undefined4 *param_1,int param_2)

{
  byte bVar1;
  bool bVar2;
  bool bVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  int iVar6;
  undefined *puVar7;
  uint uVar8;
  int iVar9;
  
  iVar6 = 0;
  bVar3 = false;
  bVar2 = false;
  iVar9 = *(int *)(param_2 + 0x22);
  uVar4 = 0;
  bVar1 = *(byte *)(param_2 + 10) & 0x1f;
  *(undefined4 *)(param_2 + 0x3e) = 0xffffffff;
  *(undefined4 *)(param_2 + 0x42) = 0;
  *(undefined4 *)(param_2 + 0x46) = 0;
  *(undefined4 *)(param_2 + 0x4a) = 0;
  if (0 < iVar9) {
    if (0x100000 < iVar9) {
      iVar6 = 4;
      _printf(aFdDmaByteCount);
      goto loc_406B29E;
    }
    uVar8 = *(uint *)(param_2 + 0x3a) & 2;
    uVar5 = 0;
    if ((uVar8 == 0) || (uVar5 = 0x40000, uVar8 == 0)) {
      uVar4 = 0x10;
      iVar9 = iVar9 + 0x10;
    }
    _dma_list((int)param_1 + 0x26,(int)param_1 + 0x11e,*(undefined4 *)(param_2 + 0x1e),iVar9,
              *(undefined4 *)(param_2 + 0x50),uVar5,10,0,uVar4);
    _dma_start((int)param_1 + 0x26,(int)param_1 + 0x11e,uVar5);
    bVar2 = true;
  }
  sub_406B346(param_1,param_2);
  _fc_start_timer(param_1,10000);
  puVar7 = (undefined *)(param_2 + 10);
  uVar8 = 0;
  if (*(int *)(param_2 + 0x1a) != 0) {
    do {
      iVar6 = _fc_send_byte(param_1,*puVar7);
      if (iVar6 != 0) {
        if (iVar6 == 10) {
          _fc_stop_timer(param_1);
          _fc_flags_bset(param_1,0x400);
        }
        goto loc_406B29E;
      }
      *(int *)(param_2 + 0x42) = *(int *)(param_2 + 0x42) + 1;
      uVar8 = uVar8 + 1;
      puVar7 = puVar7 + 1;
    } while (uVar8 < *(uint *)(param_2 + 0x1a));
  }
  _fc_stop_timer(param_1);
  if (iVar9 < 1) {
    _fc_flags_bclr(param_1,0x4000);
  }
  else {
    _fc_flags_bset(param_1,0x4000);
    if ((*(byte *)(param_2 + 0x3d) & 2) == 0) {
      **(byte **)((int)param_1 + 0x236) = **(byte **)((int)param_1 + 0x236) & 0xf7;
      _fc_flags_bclr(param_1,0x8000);
    }
    else {
      **(byte **)((int)param_1 + 0x236) = **(byte **)((int)param_1 + 0x236) | 8;
      _fc_flags_bset(param_1,0x8000);
    }
    **(byte **)((int)param_1 + 0x236) = **(byte **)((int)param_1 + 0x236) | 0x10;
  }
  switch(bVar1) {
  case :
  case :
  case :
  case :
  case :
  case :
  case :
    break;
  :
    iVar6 = sub_406B38A(param_1,*(int *)(param_2 + 2) * 1000,*(int *)(param_2 + 2) * 2000);
  }
  if ((param_1[6] & 0x10) != 0) {
    _fc_stop_timer(param_1);
  }
  if (((param_1[6] & 0x4000) != 0) && ((**(byte **)((int)param_1 + 0x236) & 0x10) != 0)) {
    iVar9 = 0;
    if (_dma_chip == 0x139) goto loc_406B016;
    while (iVar9 < 1) {
loc_406B016:
      while( true ) {
        **(byte **)((int)param_1 + 0x236) = **(byte **)((int)param_1 + 0x236) | 4;
        _delay(5);
        **(byte **)((int)param_1 + 0x236) = **(byte **)((int)param_1 + 0x236) & 0xfb;
        _delay(5);
        iVar9 = iVar9 + 1;
        if (_dma_chip != 0x139) break;
        if (7 < iVar9) goto loc_406B04C;
      }
    }
loc_406B04C:
    **(byte **)((int)param_1 + 0x236) = **(byte **)((int)param_1 + 0x236) & 0xef;
  }
  if (iVar6 != 0) {
    if (iVar6 != 1) goto loc_406B29E;
    bVar3 = true;
  }
  if (*(uint *)(param_2 + 0x4a) < *(uint *)(param_2 + 0x36)) {
    _fc_start_timer(param_1,10000);
  }
  uVar8 = *(uint *)(param_2 + 0x4a);
  iVar9 = param_2 + 0x26 + uVar8;
  if (uVar8 < *(uint *)(param_2 + 0x36)) {
    do {
      iVar6 = _fc_get_byte(param_1,iVar9);
      if (iVar6 != 0) {
        if ((iVar6 != 10) || (*(int *)(param_2 + 0x4a) == 0)) goto loc_406B29E;
        break;
      }
      *(int *)(param_2 + 0x4a) = *(int *)(param_2 + 0x4a) + 1;
      uVar8 = uVar8 + 1;
      iVar9 = iVar9 + 1;
    } while (uVar8 < *(uint *)(param_2 + 0x36));
  }
  if ((param_1[6] & 0x10) != 0) {
    _fc_stop_timer(param_1);
  }
  if ((param_1[6] & 0x4000) != 0) {
    _fc_flags_bclr(param_1,0x4000);
    *(undefined4 *)(param_2 + 0x46) = *(undefined4 *)(param_2 + 0x22);
    if (*(uint *)(param_2 + 0x22) < *(uint *)(param_2 + 0x46)) {
      *(uint *)(param_2 + 0x46) = *(uint *)(param_2 + 0x22);
    }
    if ((param_1[6] & 0x10000) != 0) {
      iVar6 = 3;
    }
    _dma_cleanup((int)param_1 + 0x26,0);
    bVar2 = false;
    sub_406B2D4(param_1);
  }
  if (iVar6 == 0) {
    switch(bVar1) {
    case :
    case :
    case :
    case :
    case :
    case :
    case :
    case :
      if (*(int *)(param_2 + 0x4a) == 0) {
        iVar6 = 0x12;
        goto loc_406B29E;
      }
      bVar1 = *(byte *)(param_2 + 0x26) & 0xc0;
      if (((bVar1 == 0) || (*(byte *)(param_2 + 0x27) == 0x80)) ||
         ((*(int *)(param_2 + 0x22) != 0 &&
          (((bVar1 == 0x40 && (*(int *)(param_2 + 0x22) == *(int *)(param_2 + 0x46))) &&
           ((*(byte *)(param_2 + 0x27) & 0x10) != 0)))))) goto loc_406B29E;
      if ((*(byte *)(param_2 + 0x26) & 0x10) != 0) {
        iVar6 = 0xb;
        goto loc_406B29E;
      }
      if (*(uint *)(param_2 + 0x4a) < 7) {
        iVar6 = 8;
        goto loc_406B29E;
      }
      bVar1 = *(byte *)(param_2 + 0x27);
      if ((bVar1 & 0x20) != 0) {
        iVar6 = 7;
        if ((*(byte *)(param_2 + 0x28) & 0x20) != 0) {
          iVar6 = 6;
        }
        goto loc_406B29E;
      }
      if ((bVar1 & 0x10) != 0) {
        iVar6 = 0x13;
        goto loc_406B29E;
      }
      if ((bVar1 & 4) != 0) {
        iVar6 = 0xc;
        goto loc_406B29E;
      }
      if ((bVar1 & 2) != 0) {
        iVar6 = 0xd;
        goto loc_406B29E;
      }
      if ((bVar1 & 1) != 0) {
        iVar6 = 0xe;
        goto loc_406B29E;
      }
      bVar1 = *(byte *)(param_2 + 0x28);
      if ((bVar1 & 0x40) != 0) {
        iVar6 = 0xf;
        goto loc_406B29E;
      }
      if ((bVar1 & 0x12) == 0) {
        if ((bVar1 & 1) != 0) {
          iVar6 = 0x10;
        }
        goto loc_406B29E;
      }
      break;
    :
      goto loc_406B29E;
    case :
      if (((*(byte *)(param_2 + 0x26) & 0x20) != 0) &&
         ((*(char *)(param_2 + 0x27) == '\0' && ((*(byte *)*param_1 & 0x10) == 0))))
      goto loc_406B29E;
      break;
    case :
      if (((*(byte *)(param_2 + 0x26) & 0x20) != 0) &&
         ((*(char *)(param_2 + 10) < '\0' || (*(char *)(param_2 + 0x27) == *(char *)(param_2 + 0xc))
          ))) goto loc_406B29E;
    }
    iVar6 = 9;
  }
loc_406B29E:
  if ((param_1[6] & 0x10) != 0) {
    _fc_stop_timer(param_1);
  }
  if (bVar2) {
    _dma_abort((int)param_1 + 0x26);
  }
  if (bVar3) {
    iVar6 = 1;
  }
  return iVar6;
}

