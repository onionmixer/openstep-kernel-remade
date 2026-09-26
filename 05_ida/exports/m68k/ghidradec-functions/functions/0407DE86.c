
int _sdioctl(undefined8 param_1,uint *param_2)

{
  int iVar1;
  int *piVar2;
  int *piVar3;
  char cVar4;
  word wVar5;
  uint uVar6;
  int iVar7;
  undefined2 uVar8;
  sword sVar9;
  uint uVar10;
  undefined *puVar11;
  undefined2 *puVar12;
  char *pcVar13;
  char *pcVar14;
  uint *puStack_10;
  uint uStack_c;
  undefined4 uStack_8;
  
  iVar7 = (int)param_1;
  piVar3 = *(int **)(unk_40B4FDE + (param_1._3_4_ >> 0x1b) * 4);
  uVar6 = *param_2;
  if (0x10 < param_1._3_4_ >> 0x1b) {
    return 6;
  }
  if (iVar7 == 0x40046411) {
    if (dword_40B2088 == 0) {
      return 0x13;
    }
    uVar6 = 0;
    puVar11 = unk_40B4FDE;
    while ((*(int *)puVar11 != 0 && (*(char *)(*(int *)puVar11 + 0xb) < '\0'))) {
      puVar11 = (undefined *)((int)puVar11 + 4);
      uVar6 = uVar6 + 1;
      if (0xf < (int)uVar6) {
        *param_2 = 0xffffffff;
        return 0;
      }
    }
    *param_2 = uVar6;
    return 0;
  }
  if (piVar3 == (int *)0x0) {
    return 6;
  }
  iVar1 = *piVar3;
  if (iVar7 == 0x20006415) {
    if ((*(byte *)((int)piVar3 + 0xb) & 2) == 0) {
      return 0;
    }
    iVar7 = _suser();
    if ((iVar7 == 0) &&
       (*(sword *)((int)piVar3 + 0x16) != *(sword *)(*(int *)(_active_u + 0x1a) + 6))) {
      return (int)*(char *)(dword_40B57D4 + 100);
    }
    if (*(char *)(*(int *)(*piVar3 + 0xb2) + 1) < '\0') {
      _update((int)(sword)((sword)piVar3[1] << 3 | (sword)dword_40B5026 << 8),0xfffffff8);
      iVar7 = sub_407CD5C(piVar3);
      return iVar7;
    }
    return 0;
  }
  if (0x20006415 < iVar7) {
    if (iVar7 == 0x40046419) {
      *param_2 = **(int **)((int)piVar3 + 0xca) + 1;
      return 0;
    }
    if (iVar7 < 0x4004641a) {
      if (iVar7 == 0x40046417) {
        *param_2 = (*(uint *)((int)piVar3 + 10) & 0x7ffffff) >> 0x1a;
        return 0;
      }
      if (iVar7 == 0x40046418) {
        *param_2 = *(uint *)(*(int *)((int)piVar3 + 0xca) + 4);
        return 0;
      }
    }
    else {
      if (iVar7 == 0x40087305) {
        iVar7 = sub_407E572(piVar3,*(undefined4 *)((int)piVar3 + 0xca),0);
        uVar6 = (*(uint **)((int)piVar3 + 0xca))[1];
        *param_2 = **(uint **)((int)piVar3 + 0xca);
        param_2[1] = uVar6;
        return iVar7;
      }
      if (iVar7 == 0x40306405) {
        _bzero(param_2,0x18);
        puStack_10 = param_2;
        iVar7 = *(int *)(iVar1 + 0xb2);
        pcVar13 = (char *)(iVar7 + 8);
        if (pcVar13 < (char *)(iVar7 + 0x20)) {
          do {
            if (param_2 + 6 <= puStack_10) break;
            *(char *)puStack_10 = *pcVar13;
            puStack_10 = (uint *)((int)puStack_10 + 1);
            pcVar14 = pcVar13 + 1;
            if (*pcVar13 == ' ') {
              cVar4 = *pcVar14;
              while (cVar4 == ' ') {
                pcVar14 = pcVar14 + 1;
                cVar4 = *pcVar14;
              }
            }
            pcVar13 = pcVar14;
          } while (pcVar14 < (char *)(*(int *)(iVar1 + 0xb2) + 0x20));
        }
        while (puStack_10 = (uint *)((int)puStack_10 + -1), *(char *)puStack_10 == ' ') {
          *(undefined *)puStack_10 = 0;
        }
        param_2[10] = *(uint *)(*(int *)((int)piVar3 + 0xca) + 4);
        uVar6 = *(uint *)(*(int *)((int)piVar3 + 0xca) + 4);
        uVar6 = (uVar6 + 0x1c47) / uVar6;
        iVar7 = 3;
        uVar10 = uVar6 * 3;
        do {
          do {
            param_2[iVar7 + 6] = uVar10;
            uVar10 = uVar10 - uVar6;
            wVar5 = (word)((uint)iVar7 >> 0x10);
            sVar9 = (sword)iVar7 + -1;
            iVar7 = CONCAT22(wVar5,sVar9);
          } while (sVar9 != -1);
          iVar7 = (uint)wVar5 * 0x10000 + -1;
        } while (wVar5 != 0);
        param_2[0xb] = *(int *)(*(int *)((int)piVar3 + 0xca) + 4) << 8;
        return 0;
      }
    }
    return 0x16;
  }
  if (iVar7 != -0x3fad8cff) {
    if (iVar7 < -0x3fad8cfe) {
      if (iVar7 != -0x7ffb9be9) {
        return 0x16;
      }
      if (uVar6 == 0) {
        *(word *)((int)piVar3 + 10) = *(word *)((int)piVar3 + 10) & 0xfbff;
      }
      else {
        *(word *)((int)piVar3 + 10) = *(word *)((int)piVar3 + 10) | 0x400;
      }
      piVar3[2] = piVar3[2] & 0xfffffffb;
      return 0;
    }
    if (iVar7 == 0x20006400) {
      if ((*(byte *)((int)piVar3 + 0xb) & 4) == 0) {
        return 6;
      }
      iVar7 = _copyoutmsg(*(undefined4 *)((int)piVar3 + 0xd2),uVar6,0x1c48);
      return iVar7;
    }
    if (iVar7 != 0x20006401) {
      return 0x16;
    }
    iVar7 = _suser();
    if (iVar7 != 0) {
      iVar7 = _copyinmsg(uVar6,*(undefined4 *)((int)piVar3 + 0xd2),0x1c48);
      if (iVar7 != 0) {
        return iVar7;
      }
      piVar2 = *(int **)((int)piVar3 + 0xd2);
      if ((*piVar2 == 0x4e655854) || (*piVar2 == 0x646c5632)) {
        wVar5 = 0x1c48;
        puVar12 = (undefined2 *)((int)piVar2 + 0x1c46);
      }
      else {
        wVar5 = 0x230;
        puVar12 = (undefined2 *)((int)piVar2 + 0x22e);
      }
      uStack_c = CONCAT31((uint3)*_eventc_m | (uint3)(((uint)*_eventc_h << 0x10) >> 8),*_eventc_l) &
                 0xfffff;
      if ((((uStack_c ^ *_event_middle) & 0x80000) != 0) &&
         (*_event_middle = *_event_middle + 0x80000, (*_event_middle & 0xfff80000) == 0)) {
        *_event_high = *_event_high + 1;
      }
      uStack_8 = *_event_high;
      uStack_c = uStack_c | *_event_middle;
      *(uint *)(*(int *)((int)piVar3 + 0xd2) + 0x28) = uStack_c;
      *(undefined4 *)(*(int *)((int)piVar3 + 0xd2) + 4) = 0;
      *puVar12 = 0;
      uVar8 = _checksum_16(*(undefined4 *)((int)piVar3 + 0xd2),wVar5 >> 1);
      *puVar12 = uVar8;
      iVar7 = _sdchecklabel(*(undefined4 *)((int)piVar3 + 0xd2),0);
      if (iVar7 == 0) {
        return 0x16;
      }
      iVar7 = sub_407E4A4(piVar3);
      if (iVar7 != 0) {
        return 5;
      }
      return 0;
    }
loc_407E1CC:
    return (int)*(char *)(dword_40B57D4 + 100);
  }
  iVar7 = _suser();
  if (iVar7 == 0) goto loc_407E1CC;
  if (param_2[5] == 0) {
    puStack_10 = (uint *)0x0;
  }
  else {
    iVar7 = _kmem_alloc_wired(_kernel_map,&puStack_10,param_2[5]);
    if (iVar7 != 0) {
      param_2[7] = 8;
      return 0xc;
    }
    if ((param_2[3] == 1) && (iVar7 = _copyinmsg(param_2[4],puStack_10,param_2[5]), iVar7 != 0)) {
      param_2[7] = 9;
      goto loc_407E278;
    }
  }
  uVar6 = param_2[4];
  param_2[4] = (uint)puStack_10;
  iVar7 = sub_407E678(piVar3,param_2,0);
  param_2[4] = uVar6;
  if ((param_2[3] == 0) && (param_2[0xf] != 0)) {
    iVar7 = _copyoutmsg(puStack_10,uVar6,param_2[0xf]);
  }
loc_407E278:
  if (param_2[5] != 0) {
    _kmem_free(_kernel_map,puStack_10,param_2[5]);
    return iVar7;
  }
  return iVar7;
}
