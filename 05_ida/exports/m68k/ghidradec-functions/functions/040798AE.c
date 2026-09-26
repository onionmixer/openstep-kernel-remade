
int _odioctl(word param_1,int param_2,uint *param_3)

{
  uint uVar1;
  sword sVar2;
  uint *puVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  undefined *puVar9;
  int *piVar10;
  undefined4 uVar11;
  undefined4 uStack_2c;
  int iStack_28;
  uint uStack_24;
  uint uStack_20;
  undefined auStack_1c [8];
  int *piStack_14;
  uint uStack_10;
  uint uStack_c;
  uint uStack_8;
  
  uVar4 = (param_1 & 0xff) >> 3;
  iVar5 = uVar4 * 0xda;
  uVar1 = *param_3;
  if (param_2 == 0x2000640f) {
loc_40799D6:
    iVar5 = _od_lock(param_2);
    return iVar5;
  }
  if (param_2 < 0x20006410) {
    if (param_2 == -0x7ff39bf2) {
      uStack_c = param_3[1];
      uStack_8 = param_3[2];
      uStack_10 = uVar1;
      iVar5 = _vm_map_pageable(*(undefined4 *)(*(int *)(_active_threads + 0xc) + 8),uVar1,uStack_c,
                               uStack_8);
      if (uStack_8 == 0) {
        _od_make_free_pages();
        return iVar5;
      }
      return iVar5;
    }
    if (param_2 < -0x7ff39bf1) {
      if (param_2 == -0x7ffb9bf4) {
        iVar5 = _suser();
        if (iVar5 != 0) {
          _od_dbug = *param_3;
          if ((_od_dbug & 0x1000000) != 0) {
            byte_40C3DF7 = byte_40C3DF7 & 0xbf;
            return 0;
          }
          byte_40C3DF7 = byte_40C3DF7 | 0x40;
          return 0;
        }
        goto loc_4079EE4;
      }
    }
    else {
      if (param_2 == 0x20006407) {
        iVar5 = _suser();
        if (iVar5 != 0) {
          _bzero(&_od_stats,0x28);
          return 0;
        }
        goto loc_4079EE4;
      }
      if (param_2 == 0x20006408) {
        _copyoutmsg(&_od_stats,uVar1,0x28);
        return 0;
      }
    }
  }
  else {
    if (param_2 == 0x4004640b) {
      *param_3 = _od_dbug;
      return 0;
    }
    if (param_2 < 0x4004640c) {
      if (param_2 == 0x20006410) goto loc_40799D6;
    }
    else {
      if (param_2 == 0x40046411) {
        puVar9 = _od_vol;
        do {
          if (-1 < *(sword *)(puVar9 + 0xd8)) break;
          puVar9 = puVar9 + 0xda;
        } while (puVar9 < (undefined *)0x40c592e);
        if (puVar9 == (undefined *)0x40c592e) {
          *param_3 = 0xffffffff;
          return 0;
        }
        *param_3 = (int)(puVar9 + -0x40c3ec8) * -0x2593f69b >> 1;
        return 0;
      }
      if (param_2 == 0x40306405) {
        iVar5 = (char)(&byte_40C3E34)[(uint)*(word *)(_od_vol + iVar5 + 0xd2) * 0x20] * 0x30;
        *param_3 = *(uint *)(_od_drive_info + iVar5);
        param_3[1] = *(uint *)(_od_drive_info + iVar5 + 4);
        param_3[2] = *(uint *)(_od_drive_info + iVar5 + 8);
        param_3[3] = *(uint *)(DAT_40b1f66 + iVar5);
        param_3[4] = *(uint *)(DAT_40b1f66 + iVar5 + 4);
        param_3[5] = *(uint *)(DAT_40b1f66 + iVar5 + 8);
        param_3[6] = *(uint *)(DAT_40b1f66 + iVar5 + 0xc);
        param_3[7] = *(uint *)(DAT_40b1f66 + iVar5 + 0x10);
        param_3[8] = *(uint *)(DAT_40b1f66 + iVar5 + 0x14);
        param_3[9] = *(uint *)(DAT_40b1f66 + iVar5 + 0x18);
        param_3[10] = *(uint *)(DAT_40b1f66 + iVar5 + 0x1c);
        param_3[0xb] = *(uint *)(DAT_40b1f66 + iVar5 + 0x20);
        return 0;
      }
    }
  }
  if ((0x1e < uVar4) || (-1 < *(sword *)(unk_40C3FA0 + iVar5))) {
    return 6;
  }
  piStack_14 = *(int **)(_od_vol + iVar5 + 0xae);
  if (param_2 == 0x20006402) {
    if ((unk_40C3FA0[iVar5] & 0x40) == 0) {
      return 6;
    }
    uVar11 = *(undefined4 *)(_od_vol + iVar5 + 0xca);
    piVar10 = *(int **)(_od_vol + iVar5 + 0xc6);
loc_4079D46:
    iVar5 = _copyoutmsg(piVar10,uVar1,uVar11);
    return iVar5;
  }
  if (0x20006402 < param_2) {
    if (param_2 != 0x20006412) {
      if (param_2 < 0x20006413) {
        if (param_2 != 0x20006403) {
          return 0x19;
        }
        iVar8 = _suser();
        if (iVar8 != 0) {
          if (*(int *)(_od_vol + iVar5 + 0xc6) == 0) {
            return 0;
          }
          iVar8 = _copyinmsg(uVar1,*(int *)(_od_vol + iVar5 + 0xc6),
                             *(undefined4 *)(_od_vol + iVar5 + 0xca));
          *(word *)(unk_40C3FA0 + iVar5) = *(word *)(unk_40C3FA0 + iVar5) | 0x1000;
          if (_od_update_time == 0) {
            _od_update_time = 1;
            return iVar8;
          }
          return iVar8;
        }
      }
      else if (param_2 == 0x20006413) {
        iVar8 = _suser();
        if (iVar8 != 0) {
          if (*(int *)(_od_vol + iVar5 + 0xb2) == 0) {
            return 0;
          }
          iVar8 = _copyinmsg(uVar1,*(int *)(_od_vol + iVar5 + 0xb2),0x3000);
          *(word *)(unk_40C3FA0 + iVar5) = *(word *)(unk_40C3FA0 + iVar5) | 0x1000;
          _od_canon_remap(_od_ctrl);
          if (_od_update_time == 0) {
            _od_update_time = 1;
            return iVar8;
          }
          return iVar8;
        }
      }
      else {
        if (param_2 != 0x20006415) {
          return 0x19;
        }
        iVar8 = _suser();
        if ((iVar8 != 0) ||
           (*(sword *)(_od_vol + iVar5 + 0xce) == *(sword *)(*(int *)(_active_u + 0x1a) + 6))) {
          _od_sync((int)(sword)((sword)((int)(uVar4 * 2) >> 1) << 3 | (sword)_od_blk_major << 8));
          iVar5 = _od_cmd((int)(sword)param_1,0xf1,0,0,0,0,0,0,0,0);
          return iVar5;
        }
      }
      goto loc_4079EE4;
    }
    if ((unk_40C3FA0[iVar5] & 0x40) == 0) {
      return 6;
    }
    uVar11 = 0x3000;
    piVar10 = *(int **)(_od_vol + iVar5 + 0xb2);
    goto loc_4079D46;
  }
  if (param_2 == 0x20006400) {
    if ((unk_40C3FA0[iVar5] & 0x40) == 0) {
      return 6;
    }
    if (piStack_14[9] < 0) {
      return 6;
    }
    uVar11 = 0x1c48;
    piVar10 = piStack_14;
    goto loc_4079D46;
  }
  if (param_2 < 0x20006401) {
    if (param_2 != -0x3faf9bfc) {
      return 0x19;
    }
    puVar3 = param_3 + 4;
    if (*(char *)puVar3 != -0xf) {
      iVar8 = _suser();
      if (iVar8 == 0) goto loc_4079EE4;
      if (*(char *)puVar3 != -0xf) goto loc_4079E02;
    }
    if ((*(sword *)(_od_vol + iVar5 + 0xce) == *(sword *)(*(int *)(_active_u + 0x1a) + 6)) ||
       (iVar5 = _suser(), iVar5 != 0)) {
loc_4079E02:
      _microtime(auStack_1c);
      iVar5 = _od_cmd((int)(sword)param_1,*(undefined *)puVar3,*(undefined4 *)((int)param_3 + 0x12),
                      param_3[1],*param_3,param_3 + 0xc,puVar3,param_3 + 0xc,0,0);
      _microtime(&uStack_24);
      _timevalsub(&uStack_24,auStack_1c);
      param_3[2] = uStack_24;
      param_3[3] = uStack_20;
      if (*(sword *)((int)param_3 + 0x1a) != 0) {
        uStack_2c = 0;
        iStack_28 = (uint)*(word *)((int)param_3 + 0x1a) * 1000;
        _timevalfix(&uStack_2c);
        _us_timeout(_od_creq_timeout,puVar3,&uStack_2c,0);
        sVar2 = *(sword *)((int)param_3 + 0x1a);
        while (sVar2 != 0) {
          _sleep(_od_creq_timeout,0x14);
          sVar2 = *(sword *)((int)param_3 + 0x1a);
        }
        return iVar5;
      }
      return iVar5;
    }
loc_4079EE4:
    return (int)*(char *)(dword_40B57D4 + 100);
  }
  iVar8 = _suser();
  if (iVar8 == 0) goto loc_4079EE4;
  iVar8 = *(int *)(_od_vol + iVar5 + 0xca);
  if (piStack_14 == (int *)0x0) {
    iVar6 = _kmem_alloc_wired(_kernel_map,&piStack_14,0x1c48);
    if (iVar6 != 0) {
                    /* WARNING: Subroutine does not return */
      _panic(aOdSlabelAlloc);
    }
    iVar6 = 0;
  }
  else {
    iVar6 = piStack_14[10];
  }
  iVar7 = _copyinmsg(uVar1,piStack_14,0x1c48);
  if (iVar7 != 0) {
    return iVar7;
  }
  *(int **)(_od_vol + iVar5 + 0xae) = piStack_14;
  if (*(int *)(_od_vol + iVar5 + 0xb2) == 0) {
    iVar7 = _kmem_alloc_wired(_kernel_map,_od_vol + iVar5 + 0xb2,0x3000);
    if (iVar7 != 0) {
      return 0xc;
    }
    _bzero(*(undefined4 *)(_od_vol + iVar5 + 0xb2),0x3000);
  }
  *(int *)(_od_vol + iVar5 + 0xbe) = piStack_14[0x19] * **(int **)(_od_vol + iVar5 + 0xba);
  iVar7 = piStack_14[0x19] * piStack_14[0x18] * piStack_14[0x1a];
  *(int *)(_od_vol + iVar5 + 0xc2) = iVar7;
  if (*piStack_14 == 0x4e655854) {
    iVar7 = iVar7 / piStack_14[0x19] >> 1;
  }
  else {
    iVar7 = iVar7 >> 2;
  }
  if (*(int *)(_od_vol + iVar5 + 0xc6) != 0) {
    if (iVar7 == iVar8) goto loc_4079C5E;
    _kmem_free(_kernel_map,*(int *)(_od_vol + iVar5 + 0xc6),0x10000);
  }
  *(int *)(_od_vol + iVar5 + 0xca) = iVar7;
  iVar8 = _kmem_alloc_wired(_kernel_map,_od_vol + iVar5 + 0xc6,0x10000);
  if (iVar8 != 0) {
    return 0xc;
  }
  _bzero(*(undefined4 *)(_od_vol + iVar5 + 0xc6),*(undefined4 *)(_od_vol + iVar5 + 0xca));
loc_4079C5E:
  if (iVar6 == 0) {
    iVar6 = _rtc_get();
  }
  piStack_14[10] = iVar6;
  *(byte *)(piStack_14 + 9) = *(byte *)(piStack_14 + 9) & 0x7f;
  iVar8 = _od_write_label(_od_vol + iVar5,0);
  if (iVar8 == 0) {
    *(word *)(unk_40C3FA0 + iVar5) = *(word *)(unk_40C3FA0 + iVar5) | 0x4000;
    (&word_40C3E30)[(uint)*(word *)(_od_vol + iVar5 + 0xd2) * 0x10] =
         (&word_40C3E30)[(uint)*(word *)(_od_vol + iVar5 + 0xd2) * 0x10] | 0x8000;
    _od_canon_remap(_od_ctrl);
    return 0;
  }
  return 5;
}
