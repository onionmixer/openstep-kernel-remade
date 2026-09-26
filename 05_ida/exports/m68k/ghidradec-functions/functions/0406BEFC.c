
int _fdioctl(undefined8 param_1,uint *param_2)

{
  int *piVar1;
  undefined4 uVar2;
  undefined2 uVar6;
  int iVar3;
  int iVar4;
  uint uVar5;
  int unaff_D2;
  word wVar7;
  int iVar8;
  uint unaff_D5;
  undefined *puVar9;
  undefined2 *puVar10;
  int iStack_1a;
  undefined auStack_16 [10];
  uint uStack_c;
  int iStack_8;
  
  iVar4 = (int)param_1;
  puVar9 = _fd_volume_p;
  iVar3 = *(int *)(_fd_volume_p + (param_1._3_4_ >> 0x1b) * 4);
  uVar5 = *param_2;
  if (iVar3 == 0) {
    return 6;
  }
  if (iVar4 == 0x40046411) {
    if ((byte_40C371F & 1) == 0) {
      return 0x13;
    }
    uVar5 = 0;
    do {
      if (*(int *)puVar9 == 0) {
        *param_2 = uVar5;
        return 0;
      }
      puVar9 = (undefined *)((int)puVar9 + 4);
      uVar5 = uVar5 + 1;
    } while ((int)uVar5 < 8);
    *param_2 = 0xffffffff;
    return 0;
  }
  if (iVar4 < 0x40046412) {
    if (iVar4 == -0x7ffb99fa) {
      _fd_inner_retry = uVar5;
      return 0;
    }
    if (iVar4 == -0x7ffb99f8) {
      _fd_outer_retry = uVar5;
      return 0;
    }
  }
  else {
    if (iVar4 == 0x40046607) {
      *param_2 = _fd_inner_retry;
      return 0;
    }
    if (iVar4 == 0x40046609) {
      *param_2 = _fd_outer_retry;
      return 0;
    }
  }
  if (7 < param_1._3_4_ >> 0x1b) {
    return 6;
  }
  if (iVar4 == 0x20006401) {
    iVar4 = _suser();
    if (iVar4 == 0) {
      return (int)*(char *)(dword_40B57D4 + 100);
    }
    iVar4 = _copyinmsg(uVar5,*(undefined4 *)(iVar3 + 0x14),0x1c48);
    if (iVar4 == 0) {
      piVar1 = *(int **)(iVar3 + 0x14);
      if ((*piVar1 == 0x4e655854) || (*piVar1 == 0x646c5632)) {
        wVar7 = 0x1c48;
        puVar10 = (undefined2 *)((int)piVar1 + 0x1c46);
      }
      else {
        wVar7 = 0x230;
        puVar10 = (undefined2 *)((int)piVar1 + 0x22e);
      }
      uStack_c = CONCAT31((uint3)*_eventc_m | (uint3)(((uint)*_eventc_h << 0x10) >> 8),*_eventc_l) &
                 0xfffff;
      if ((((uStack_c ^ *_event_middle) & 0x80000) != 0) &&
         (*_event_middle = *_event_middle + 0x80000, (*_event_middle & 0xfff80000) == 0)) {
        *_event_high = *_event_high + 1;
      }
      iStack_8 = *_event_high;
      uStack_c = uStack_c | *_event_middle;
      *(uint *)(*(int *)(iVar3 + 0x14) + 0x28) = uStack_c;
      *(undefined4 *)(*(int *)(iVar3 + 0x14) + 4) = 0;
      *puVar10 = 0;
      uVar6 = _checksum_16(*(undefined4 *)(iVar3 + 0x14),wVar7 >> 1);
      *puVar10 = uVar6;
      iVar4 = _sdchecklabel(*(undefined4 *)(iVar3 + 0x14),0);
      if (iVar4 == 0) {
        return 0x16;
      }
      iVar3 = _fd_write_label(iVar3);
      if (iVar3 != 0) {
        return 5;
      }
      return 0;
    }
    return iVar4;
  }
  if (0x20006401 < iVar4) {
    if (iVar4 == 0x40046418) {
      *param_2 = *(uint *)(iVar3 + 0x186);
      return 0;
    }
    if (iVar4 < 0x40046419) {
      if (iVar4 == 0x20006415) {
        iVar4 = _suser();
        if ((iVar4 == 0) &&
           (*(sword *)(iVar3 + 0x136) != *(sword *)(*(int *)(_active_u + 0x1a) + 6))) {
          return (int)*(char *)(dword_40B57D4 + 100);
        }
        _update(*(int *)(iVar3 + 0x10) << 3 | _fd_blk_major << 8,0xfffffff8);
        iVar3 = _fd_basic_cmd(iVar3,2);
        return iVar3;
      }
      if (iVar4 == 0x40046417) {
        *param_2 = *(uint *)(iVar3 + 0x176) & 1;
        return 0;
      }
    }
    else {
      if (iVar4 == 0x402e6601) {
        *param_2 = *(uint *)(iVar3 + 0x168);
        param_2[1] = *(uint *)(iVar3 + 0x16c);
        param_2[2] = *(uint *)(iVar3 + 0x170);
        param_2[3] = *(uint *)(iVar3 + 0x174);
        param_2[4] = *(uint *)(iVar3 + 0x178);
        param_2[5] = *(uint *)(iVar3 + 0x17c);
        param_2[6] = *(uint *)(iVar3 + 0x180);
        param_2[7] = *(uint *)(iVar3 + 0x184);
        param_2[8] = *(uint *)(iVar3 + 0x188);
        param_2[9] = *(uint *)(iVar3 + 0x18c);
        param_2[10] = *(uint *)(iVar3 + 400);
        *(undefined2 *)(param_2 + 0xb) = *(undefined2 *)(iVar3 + 0x194);
        return 0;
      }
      if (iVar4 < 0x402e6602) {
        if (iVar4 == 0x40046419) {
          *param_2 = *(uint *)(iVar3 + 0x192);
          return 0;
        }
      }
      else if (iVar4 == 0x40306405) {
        iVar4 = *(int *)(iVar3 + 4);
        if (iVar4 == 1) {
          iVar4 = 0;
        }
        iVar4 = (&dword_40C3720)[iVar4 * 10] * 0x44;
        *param_2 = *(uint *)(_fd_drive_info + iVar4);
        param_2[1] = *(uint *)(_fd_drive_info + iVar4 + 4);
        param_2[2] = *(uint *)(_fd_drive_info + iVar4 + 8);
        param_2[3] = *(uint *)(_fd_drive_info + iVar4 + 0xc);
        param_2[4] = *(uint *)(DAT_40b12de + iVar4);
        param_2[5] = *(uint *)(DAT_40b12de + iVar4 + 4);
        param_2[6] = *(uint *)(DAT_40b12de + iVar4 + 8);
        param_2[7] = *(uint *)(DAT_40b12de + iVar4 + 0xc);
        param_2[8] = *(uint *)(DAT_40b12de + iVar4 + 0x10);
        param_2[9] = *(uint *)(DAT_40b12de + iVar4 + 0x14);
        param_2[10] = *(uint *)(DAT_40b12de + iVar4 + 0x18);
        param_2[0xb] = *(uint *)(DAT_40b12de + iVar4 + 0x1c);
        param_2[10] = *(uint *)(iVar3 + 0x186);
        _sprintf(auStack_16,&aD_1,*(undefined4 *)(iVar3 + 0x192));
        _strcat(param_2,auStack_16);
        return 0;
      }
    }
loc_406C46E:
    *(undefined *)(dword_40B57D4 + 100) = 0x16;
    return 0x16;
  }
  if (iVar4 == -0x7ffb99fc) {
    *(char *)(iVar3 + 400) = (char)*param_2;
    return 0;
  }
  if (iVar4 < -0x7ffb99fb) {
    if (iVar4 == -0x7ffb99fe) {
      if (3 < *param_2) {
        return 0x16;
      }
      _fd_set_density_info(iVar3,*param_2);
      return 0;
    }
    if (iVar4 == -0x7ffb99fd) {
      iVar3 = _fd_set_sector_size(iVar3,*param_2);
      if (iVar3 != 0) {
        return 0x16;
      }
      return 0;
    }
    goto loc_406C46E;
  }
  if (iVar4 != -0x3fa59a00) {
    if (-0x3fa59a00 < iVar4) {
      if (iVar4 == 0x20006400) {
        if ((*(byte *)(iVar3 + 0x179) & 2) == 0) {
          return 6;
        }
        iVar3 = _copyoutmsg(*(undefined4 *)(iVar3 + 0x14),uVar5,0x1c48);
        return iVar3;
      }
      goto loc_406C46E;
    }
    if (iVar4 != -0x3fe799fb) goto loc_406C46E;
    iVar8 = *(int *)(iVar3 + 0x186) * param_2[1];
    if (*(int *)(iVar3 + 0x176) == 0) {
      return 0x16;
    }
    unaff_D2 = _kalloc(iVar8);
    if (unaff_D2 == 0) {
      param_2[4] = 2;
      return 0xc;
    }
    if ((param_2[3] == 0) && (iVar4 = _copyinmsg(param_2[2],unaff_D2,iVar8), iVar4 != 0)) {
      param_2[4] = 3;
    }
    else {
      uVar5 = _fd_live_rw(iVar3,*param_2,param_2[1],unaff_D2,param_2[3],&iStack_1a);
      param_2[4] = uVar5;
      iVar4 = 0;
      param_2[5] = param_2[1] - iStack_1a;
      if ((param_2[3] != 0) && (param_2[1] - iStack_1a != 0)) {
        iVar4 = _copyoutmsg(unaff_D2,param_2[2],iVar8);
      }
    }
    goto loc_406C464;
  }
  uVar5 = *(uint *)((int)param_2 + 0x22);
  if (uVar5 == 0) {
loc_406C370:
    uVar2 = *(undefined4 *)((int)param_2 + 0x1e);
    *(uint *)((int)param_2 + 0x1e) = unaff_D5;
    iVar4 = _fd_command(iVar3,param_2);
    if (*(int *)((int)param_2 + 0x3e) != 0) {
      iVar4 = 0;
    }
    *(undefined4 *)((int)param_2 + 0x1e) = uVar2;
    if (((*(byte *)((int)param_2 + 0x3d) & 2) != 0) && (*(int *)((int)param_2 + 0x46) != 0)) {
      iVar4 = _copyoutmsg(unaff_D5,uVar2,*(int *)((int)param_2 + 0x46));
    }
  }
  else {
    if ((uVar5 & 0xf) != 0) {
      return 0x16;
    }
    unaff_D2 = _kalloc(uVar5 + 0x10);
    unaff_D5 = unaff_D2 + 0xfU & 0xfffffff0;
    if (unaff_D2 == 0) {
      *(undefined4 *)((int)param_2 + 0x3e) = 2;
      return 0xc;
    }
    if (((*(byte *)((int)param_2 + 0x3d) & 2) != 0) ||
       (iVar4 = _copyinmsg(*(undefined4 *)((int)param_2 + 0x1e),unaff_D5,
                           *(undefined4 *)((int)param_2 + 0x22)), iVar4 == 0)) goto loc_406C370;
    *(undefined4 *)((int)param_2 + 0x3e) = 3;
  }
  if (*(int *)((int)param_2 + 0x22) == 0) {
    return iVar4;
  }
  iVar8 = *(int *)((int)param_2 + 0x22) + 0x10;
loc_406C464:
  _kfree(unaff_D2,iVar8);
  return iVar4;
}
