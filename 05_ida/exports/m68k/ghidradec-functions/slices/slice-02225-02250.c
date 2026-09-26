/* GHIDRADEC_FUNCTION index=2225 start=0x407c4c0 */

void _scsi_msg(int param_1,undefined param_2,undefined4 param_3)

{
  _printf(aSCDDDSOp0xXSdS,*(undefined *)(param_1 + 0x1e),
          (int)*(sword *)(*(int *)(param_1 + 0x10) + 4),*(undefined *)(param_1 + 0x1c),
          *(undefined *)(param_1 + 0x1d),param_3,param_2,*(undefined *)(param_1 + 0x4f),
          *(byte *)(param_1 + 0x4e) & 0x1e);
  return;
}
/* GHIDRADEC_FUNCTION index=2226 start=0x407c51e */

void _scsi_sensemsg(int param_1,int param_2)

{
  _printf(aSCDDDSenseKey0,*(undefined *)(param_1 + 0x1e),
          (int)*(sword *)(*(int *)(param_1 + 0x10) + 4),*(undefined *)(param_1 + 0x1c),
          *(undefined *)(param_1 + 0x1d),*(byte *)(param_2 + 2) & 0xf,*(undefined *)(param_2 + 0xc))
  ;
  return;
}
/* GHIDRADEC_FUNCTION index=2227 start=0x407ce8c */

undefined4 _sdopen(word param_1,byte param_2)

{
  uint uVar1;
  byte bVar2;
  undefined4 *puVar3;
  undefined *puVar4;
  
  uVar1 = (param_1 & 0xff) >> 3;
  bVar2 = (byte)(1 << (param_1 & 7));
  puVar3 = *(undefined4 **)(unk_40B4FDE + uVar1 * 4);
  if (uVar1 < 0x10) {
    _lock_write(&unk_40B504A);
    if ((puVar3 == (undefined4 *)0x0) || ((puVar3[2] & 0x81) != 0x80)) {
      if ((param_2 & 4) != 0) {
        _lock_done(&unk_40B504A);
        return 0x23;
      }
      if (dword_40B2088 == 0) {
        _lock_done(&unk_40B504A);
        return 6;
      }
      if (puVar3 == (undefined4 *)0x0) {
        puVar3 = (undefined4 *)sub_407E802(uVar1);
        *(undefined4 **)(unk_40B4FDE + uVar1 * 4) = puVar3;
        for (puVar4 = _sd_sdd; puVar4 < _sd_sdd + dword_40B2084 * 0xc2;
            puVar4 = (undefined *)((int)puVar4 + 0xc2)) {
          if (((*(char *)(*(int *)((int)puVar4 + 0xb2) + 1) < '\0') && (*(int *)puVar4 == 0)) &&
             (*(int *)((int)puVar4 + 4) == 0)) goto loc_407CF2C;
        }
        puVar4 = _sd_sdd;
        while( true ) {
          if (_sd_sdd + dword_40B2084 * 0xc2 <= puVar4) {
                    /* WARNING: Subroutine does not return */
            _panic(aSdopenNoRemova);
          }
          if (*(char *)(*(int *)((int)puVar4 + 0xb2) + 1) < '\0') break;
          puVar4 = (undefined *)((int)puVar4 + 0xc2);
        }
loc_407CF2C:
        *puVar3 = puVar4;
      }
      puVar3[2] = puVar3[2] | 0x40;
      _lock_done(&unk_40B504A);
      sub_407CCEE(puVar3,0);
      if ((*(byte *)((int)puVar3 + 0xb) & 1) != 0) {
        return 6;
      }
    }
    else {
      _lock_done(&unk_40B504A);
    }
    *(undefined2 *)((int)puVar3 + 0x16) = *(undefined2 *)(*(int *)(_active_u + 0x1a) + 6);
    if (param_1 >> 8 == dword_40B502A) {
      *(byte *)((int)puVar3 + 0xd) = bVar2 | *(byte *)((int)puVar3 + 0xd);
    }
    else {
      *(byte *)(puVar3 + 3) = bVar2 | *(byte *)(puVar3 + 3);
    }
  }
  else if (uVar1 != 0x10) {
    return 6;
  }
  return 0;
}
/* GHIDRADEC_FUNCTION index=2228 start=0x407d026 */

undefined4 _sdclose(word param_1)

{
  int *piVar1;
  uint uVar2;
  byte bVar3;
  
  uVar2 = (param_1 & 0xff) >> 3;
  piVar1 = *(int **)(unk_40B4FDE + uVar2 * 4);
  if (uVar2 < 0x10) {
    if ((*(int *)(*piVar1 + 8) == 0) ||
       (*(sword *)(*(int *)(*(int *)(*piVar1 + 8) + 0x10) + 0x1a) == 0)) {
      return 6;
    }
    bVar3 = (byte)(1 << (param_1 & 7));
    if (param_1 >> 8 == dword_40B502A) {
      *(byte *)((int)piVar1 + 0xd) = ~bVar3 & *(byte *)((int)piVar1 + 0xd);
    }
    else {
      *(byte *)(piVar1 + 3) = ~bVar3 & *(byte *)(piVar1 + 3);
    }
    if (((*(char *)(piVar1 + 3) == '\0' && *(char *)((int)piVar1 + 0xd) == '\0') &&
        (*(char *)(*(int *)(*piVar1 + 0xb2) + 1) < '\0')) &&
       ((*(byte *)((int)piVar1 + 0xb) & 2) == 0)) {
      sub_407F330(piVar1);
    }
  }
  return 0;
}
/* GHIDRADEC_FUNCTION index=2229 start=0x407d0b8 */

undefined4 _sdsize(undefined8 param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = *(int *)(unk_40B4FDE + (param_1._3_4_ >> 0x1b) * 4);
  if ((param_1._3_4_ >> 0x1b < 0x10) && (iVar1 != 0)) {
    if ((*(byte *)(iVar1 + 0xb) & 4) == 0) {
      uVar2 = *(undefined4 *)(*(int *)(iVar1 + 0xca) + 4);
    }
    else {
      uVar2 = *(undefined4 *)(*(int *)(iVar1 + 0xd2) + 0x5c);
    }
  }
  else {
    uVar2 = 0xffffffff;
  }
  return uVar2;
}
/* GHIDRADEC_FUNCTION index=2230 start=0x407d0f8 */

undefined4 _sdread(word param_1,undefined4 param_2)

{
  int iVar1;
  uint uVar2;
  undefined4 uVar3;
  
  uVar2 = (param_1 & 0xff) >> 3;
  iVar1 = *(int *)(unk_40B4FDE + uVar2 * 4);
  if ((uVar2 < 0x10) && (iVar1 != 0)) {
    if (((param_1 & 7) == 7) || ((*(byte *)(iVar1 + 0xb) & 4) == 0)) {
      uVar3 = *(undefined4 *)(*(int *)(iVar1 + 0xca) + 4);
    }
    else {
      uVar3 = *(undefined4 *)(*(int *)(iVar1 + 0xd2) + 0x5c);
    }
    uVar3 = _physio(_sdstrategy,**(int **)(unk_40B4FDE + uVar2 * 4) + 0x1c,(int)(sword)param_1,1,
                    _scminphys,param_2,uVar3);
  }
  else {
    uVar3 = 6;
  }
  return uVar3;
}
/* GHIDRADEC_FUNCTION index=2231 start=0x407d182 */

undefined4 _sdwrite(word param_1,undefined4 param_2)

{
  int iVar1;
  uint uVar2;
  undefined4 uVar3;
  
  uVar2 = (param_1 & 0xff) >> 3;
  iVar1 = *(int *)(unk_40B4FDE + uVar2 * 4);
  if ((uVar2 < 0x10) && (iVar1 != 0)) {
    if (((param_1 & 7) == 7) || ((*(byte *)(iVar1 + 0xb) & 4) == 0)) {
      uVar3 = *(undefined4 *)(*(int *)(iVar1 + 0xca) + 4);
    }
    else {
      uVar3 = *(undefined4 *)(*(int *)(iVar1 + 0xd2) + 0x5c);
    }
    uVar3 = _physio(_sdstrategy,**(int **)(unk_40B4FDE + uVar2 * 4) + 0x1c,(int)(sword)param_1,0,
                    _scminphys,param_2,uVar3);
  }
  else {
    uVar3 = 6;
  }
  return uVar3;
}
/* GHIDRADEC_FUNCTION index=2232 start=0x407d20a */

undefined4 _sdstrategy(uint *param_1)

{
  int *piVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  undefined4 uVar6;
  
  uVar4 = (*(word *)((int)param_1 + 0x1e) & 0xff) >> 3;
  uVar3 = *(word *)((int)param_1 + 0x1e) & 7;
  iVar2 = *(int *)(unk_40B4FDE + uVar4 * 4);
  uVar6 = 0;
  if (((uVar4 == 0x10) || (iVar2 == 0)) || (0x11 < uVar4)) {
loc_407D2A8:
    *(undefined2 *)(param_1 + 7) = 6;
  }
  else {
    iVar5 = *(int *)(iVar2 + 0xd2);
    if ((uint *)(iVar2 + 0x18) == param_1) {
loc_407D306:
      if ((uint *)(iVar2 + 0x18) == param_1) {
        _disksort_enter_tail(iVar2 + 0x60,param_1);
      }
      else {
        _disksort_enter(iVar2 + 0x60,param_1);
      }
      if ((*(uint *)(iVar2 + 8) & 0x300) != 0) {
        return 0;
      }
      uVar6 = sub_407D376(iVar2);
      return uVar6;
    }
    uVar4 = param_1[9];
    param_1[0xe] = uVar4;
    if (((*param_1 & 1) != 0) || ((*(byte *)(iVar2 + 10) & 8) == 0)) {
      if ((*(word *)((int)param_1 + 0x1e) & 7) == 7) {
        uVar3 = **(int **)(iVar2 + 0xca) + 1;
        if ((int)uVar3 < (int)uVar4) {
loc_407D2D8:
          *(undefined2 *)(param_1 + 7) = 0x16;
          goto loc_407D35C;
        }
        if (uVar3 != uVar4) goto loc_407D306;
      }
      else {
        if (((*(byte *)(iVar2 + 0xb) & 4) == 0) || (7 < uVar3)) goto loc_407D2A8;
        piVar1 = (int *)(iVar5 + uVar3 * 0x2e + 0xbe);
        uVar3 = piVar1[1];
        if (((uVar3 == 0) || ((int)uVar4 < 0)) || ((int)uVar3 < (int)uVar4)) goto loc_407D2D8;
        if (uVar3 != uVar4) {
          uVar3 = *piVar1 + param_1[0xe];
          param_1[0xe] = uVar3;
          iVar5 = *(int *)(iVar5 + 0x60) * *(int *)(iVar5 + 100);
          if (0 < iVar5) {
            param_1[0xe] = (int)uVar3 / iVar5;
          }
          goto loc_407D306;
        }
      }
      param_1[10] = param_1[5];
      goto loc_407D362;
    }
    *(undefined2 *)(param_1 + 7) = 0x1e;
  }
loc_407D35C:
  *param_1 = *param_1 | 4;
  uVar6 = 0xffffffff;
loc_407D362:
  _biodone(param_1);
  return uVar6;
}
/* GHIDRADEC_FUNCTION index=2233 start=0x407de86 */

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
/* GHIDRADEC_FUNCTION index=2234 start=0x407e5de */

undefined4 _sdchecklabel(int *param_1,int param_2)

{
  int iVar1;
  sword sVar2;
  word wVar3;
  sword sVar4;
  sword *psVar5;
  
  iVar1 = *param_1;
  if ((iVar1 == 0x4e655854) || (iVar1 == 0x646c5632)) {
    wVar3 = 0x1c48;
    psVar5 = (sword *)((int)param_1 + 0x1c46);
  }
  else {
    if (iVar1 != 0x646c5633) {
      return 0;
    }
    wVar3 = 0x230;
    psVar5 = (sword *)((int)param_1 + 0x22e);
  }
  if (param_1[1] == param_2) {
    param_1[1] = 0;
    sVar2 = *psVar5;
    *psVar5 = 0;
    sVar4 = _checksum_16(param_1,wVar3 >> 1);
    if (sVar2 == sVar4) {
      *psVar5 = sVar4;
      return 1;
    }
    _printf(aLabelChecksumE,sVar4,sVar2);
  }
  else {
    _printf(aLabelInWrongLo);
  }
  return 0;
}
/* GHIDRADEC_FUNCTION index=2235 start=0x407f3c4 */

undefined4 _sfa_arbitrate(int param_1,undefined4 *param_2)

{
  undefined4 *puVar1;
  
  if ((param_2[4] & 1) == 0) {
    if ((*(int *)(param_1 + 0x1a) != 0) &&
       ((((*(byte *)((int)param_2 + 0x13) & 4) != 0 || ((*(byte *)(param_1 + 0x11) & 1) != 0)) ||
        (*(int *)(param_1 + 0x16) != 0)))) {
      puVar1 = *(undefined4 **)(param_1 + 10);
      if (puVar1 == (undefined4 *)(param_1 + 6)) {
        *puVar1 = param_2;
      }
      else {
        puVar1[2] = param_2;
      }
      param_2[3] = puVar1;
      param_2[2] = param_1 + 6;
      *(undefined4 **)(param_1 + 10) = param_2;
      *(char *)(param_1 + 4) = *(char *)(param_1 + 4) + '\x01';
      if ((*(byte *)((int)param_2 + 0x13) & 4) != 0) {
        *(int *)(param_1 + 0x16) = *(int *)(param_1 + 0x16) + 1;
      }
      return 1;
    }
    *(int *)(param_1 + 0x1a) = *(int *)(param_1 + 0x1a) + 1;
    if ((*(byte *)((int)param_2 + 0x13) & 4) != 0) {
      *(uint *)(param_1 + 0xe) = *(uint *)(param_1 + 0xe) | 1;
    }
    param_2[4] = param_2[4] | 1;
  }
  else if (((param_2[4] & 4) != 0) && ((*(byte *)(param_1 + 0x11) & 1) == 0)) {
                    /* WARNING: Subroutine does not return */
    _panic(aSfaArbitrateOn);
  }
  (*(code *)*param_2)(param_2[1]);
  return 0;
}
/* GHIDRADEC_FUNCTION index=2236 start=0x407f492 */

uint _sfa_relinquish(int param_1,int param_2,int param_3)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  byte bVar6;
  uint uVar7;
  char in_XF;
  bool bVar8;
  
  uVar7 = *(uint *)(param_2 + 0x10);
  if ((uVar7 & 1) != 0) {
    uVar7 = uVar7 & 0xfffffffe;
    *(uint *)(param_2 + 0x10) = uVar7;
    bVar6 = in_XF << 4 | ((int)uVar7 < 0) << 3 | (uVar7 == 0) << 2;
    if (param_3 != 0) {
      *(int *)(param_1 + 0x12) = param_3;
    }
    iVar2 = *(int *)(param_1 + 0x1a);
    *(int *)(param_1 + 0x1a) = iVar2 + -1;
    if ((*(byte *)(param_2 + 0x13) & 4) != 0) {
      *(uint *)(param_1 + 0xe) = *(uint *)(param_1 + 0xe) & 0xfffffffe;
    }
    if (*(char *)(param_1 + 4) == '\0') {
      uVar7 = (uint)(byte)((iVar2 == 0) << 4 | (*(char *)(param_1 + 4) < '\0') << 3 | 4);
    }
    else {
      puVar5 = (undefined4 *)(param_1 + 6);
      puVar1 = (undefined4 *)*puVar5;
      while (uVar7 = (uint)bVar6, puVar5 != puVar1) {
        puVar3 = *(undefined4 **)(param_1 + 6);
        if ((*(byte *)((int)puVar3 + 0x13) & 4) != 0) {
          bVar8 = *(int *)(param_1 + 0x1a) == 0;
          if (!bVar8) {
            return (uint)(byte)((puVar5 < puVar1) << 4 | (*(int *)(param_1 + 0x1a) < 0) << 3 |
                               bVar8 << 2);
          }
        }
        *(char *)(param_1 + 4) = *(char *)(param_1 + 4) + -1;
        *(int *)(param_1 + 0x1a) = *(int *)(param_1 + 0x1a) + 1;
        if ((*(byte *)((int)puVar3 + 0x13) & 4) != 0) {
          *(int *)(param_1 + 0x16) = *(int *)(param_1 + 0x16) + -1;
          *(uint *)(param_1 + 0xe) = *(uint *)(param_1 + 0xe) | 1;
        }
        puVar1 = (undefined4 *)puVar3[2];
        puVar4 = (undefined4 *)puVar3[3];
        if (puVar1 == puVar5) {
          *(undefined4 **)(param_1 + 10) = puVar4;
        }
        else {
          puVar1[3] = puVar4;
        }
        if (puVar4 == puVar5) {
          *puVar5 = puVar1;
        }
        else {
          puVar4[2] = puVar1;
        }
        puVar3[4] = puVar3[4] | 1;
        uVar7 = (*(code *)*puVar3)(puVar3[1]);
        if ((*(byte *)((int)puVar3 + 0x13) & 4) != 0) {
          return uVar7;
        }
        puVar1 = (undefined4 *)*puVar5;
        if (puVar5 == puVar1) {
          return uVar7;
        }
        bVar6 = (puVar5 < puVar1) << 4 | ((int)puVar5 - (int)puVar1 < 0) << 3 |
                SBORROW4((int)puVar5,(int)puVar1) << 1 | puVar5 < puVar1;
        puVar1 = (undefined4 *)*puVar5;
      }
    }
  }
  return uVar7;
}
/* GHIDRADEC_FUNCTION index=2237 start=0x407f584 */

word _sfa_abort(int param_1,int *param_2,undefined4 param_3)

{
  int *piVar1;
  int *piVar2;
  byte bVar3;
  int *piVar4;
  int iVar5;
  word wVar6;
  bool bVar7;
  bool bVar8;
  bool bVar9;
  bool bVar10;
  
  if ((*(byte *)((int)param_2 + 0x13) & 1) == 0) {
    piVar1 = *(int **)(param_1 + 6);
    piVar4 = (int *)(param_1 + 6);
    iVar5 = (int)piVar1 - (int)piVar4;
    while( true ) {
      bVar7 = iVar5 < 0;
      bVar9 = SBORROW4((int)piVar1,(int)piVar4);
      bVar10 = piVar1 < piVar4;
      bVar8 = true;
      if (piVar1 == piVar4) break;
      if (param_2 == piVar1) {
        piVar2 = (int *)piVar1[2];
        piVar1 = (int *)piVar1[3];
        if (piVar2 == piVar4) {
          *(int **)(param_1 + 10) = piVar1;
        }
        else {
          piVar2[3] = (int)piVar1;
        }
        if (piVar1 == piVar4) {
          *piVar4 = (int)piVar2;
        }
        else {
          piVar1[2] = (int)piVar2;
        }
        bVar3 = *(byte *)(param_1 + 4);
        bVar10 = bVar3 == 0;
        bVar9 = SBORROW1(bVar3,'\x01');
        *(byte *)(param_1 + 4) = bVar3 - 1;
        bVar7 = (int)((uint)(byte)(bVar3 - 1) << 0x18) < 0;
        bVar8 = (*(byte *)((int)param_2 + 0x13) & 4) == 0;
        if (!bVar8) {
          iVar5 = *(int *)(param_1 + 0x16);
          bVar10 = iVar5 == 0;
          bVar9 = SBORROW4(iVar5,1);
          iVar5 = iVar5 + -1;
          *(int *)(param_1 + 0x16) = iVar5;
          bVar7 = iVar5 < 0;
          bVar8 = iVar5 == 0;
        }
        break;
      }
      piVar1 = (int *)piVar1[2];
      iVar5 = (int)piVar1 - (int)piVar4;
    }
    wVar6 = (word)(byte)(bVar10 << 4 | bVar7 << 3 | bVar8 << 2 | bVar9 << 1 | bVar10);
  }
  else {
    wVar6 = _sfa_relinquish(param_1,param_2,param_3);
  }
  return wVar6;
}
/* GHIDRADEC_FUNCTION index=2238 start=0x407f70e */

undefined4 _sgopen(byte param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = (uint)param_1 * 0x42;
  if ((param_1 < 4) && (*(int *)(_sg_sgd + iVar1) != 0)) {
    if (_sg_sgd[iVar1 + 0x16] == '\0') {
      sub_407F682(*(int *)(_sg_sgd + iVar1));
      _sg_sgd[iVar1 + 0x16] = 1;
      _sg_sgd[iVar1 + 0x17] = 0;
      _scsi_ndevices = _scsi_ndevices + 1;
      uVar2 = 0;
    }
    else {
      uVar2 = 0x10;
    }
  }
  else {
    uVar2 = 6;
  }
  return uVar2;
}
/* GHIDRADEC_FUNCTION index=2239 start=0x407f76a */

undefined4 _sgclose(byte param_1)

{
  int iVar1;
  int *piVar2;
  char *pcVar3;
  undefined4 uVar4;
  
  iVar1 = (uint)param_1 * 0x42;
  piVar2 = (int *)(_sg_sgd + iVar1);
  if ((param_1 < 4) && (_sg_sgd[iVar1 + 0x16] != '\0')) {
    _sg_sgd[iVar1 + 0x16] = 0;
    iVar1 = *piVar2;
    if (*(byte *)(iVar1 + 0x1c) != 0xff) {
      pcVar3 = (char *)(*(int *)(iVar1 + 0x18) + (uint)*(byte *)(iVar1 + 0x1c) * 8 + 0x18 +
                       (uint)*(byte *)(iVar1 + 0x1d));
      *pcVar3 = *pcVar3 + -1;
      *(undefined *)(*piVar2 + 0x1c) = 0xff;
      *(undefined *)(*piVar2 + 0x1d) = 0xff;
    }
    _scsi_ndevices = _scsi_ndevices + -1;
    uVar4 = 0;
  }
  else {
    uVar4 = 6;
  }
  return uVar4;
}
/* GHIDRADEC_FUNCTION index=2240 start=0x407fb84 */

int _sgioctl(byte param_1,int param_2,int *param_3)

{
  int iVar1;
  int iVar2;
  undefined4 *puVar3;
  
  iVar1 = (sword)(word)param_1 * 0x42;
  puVar3 = (undefined4 *)(_sg_sgd + iVar1);
  iVar2 = 0;
  if (_sg_sgd[iVar1 + 0x16] == '\0') {
    param_3[7] = 0xb;
    iVar2 = 0xd;
  }
  else if (param_2 == 0x20007302) {
    _sg_sgd[iVar1 + 0x17] = 1;
  }
  else {
    if (param_2 < 0x20007303) {
      if (param_2 == -0x7ffd8d00) {
        iVar1 = sub_407FC78(puVar3,param_3);
        return iVar1;
      }
      if (param_2 == -0x3fad8cff) {
        iVar1 = sub_407FD2C(puVar3,param_3);
        return iVar1;
      }
    }
    else {
      if (param_2 == 0x20007304) {
        iVar1 = _suser();
        if (iVar1 == 0) {
          return (int)*(char *)(dword_40B57D4 + 100);
        }
        iVar1 = _scsi_ioctl(*puVar3,0x20006409,0,0);
        return iVar1;
      }
      if (param_2 < 0x20007304) {
        _sg_sgd[iVar1 + 0x17] = 0;
        return 0;
      }
      if (param_2 == 0x40047307) {
        *param_3 = (int)(char)_sg_sgd[iVar1 + 0x17];
        return 0;
      }
    }
    iVar2 = 0x16;
  }
  return iVar2;
}
/* GHIDRADEC_FUNCTION index=2241 start=0x407ff14 */

void _snd_device_init(int param_1)

{
  bool bVar1;
  undefined2 uStack_24;
  undefined uStack_22;
  byte bStack_21;
  
  if ((param_1 == 0) && (_vol_r == 0xffffffff)) {
    _nvram_check(&uStack_24);
    _vol_r = (CONCAT31(CONCAT21(uStack_24,uStack_22),bStack_21) & 0x3ffffff) >> 0x14;
    _vol_l = (CONCAT11(uStack_22,bStack_21) & 0x3ff) >> 4;
    dword_40B5088 = 0xffffffff;
    dword_40B508C = 0xffffffff;
    _gpflags = 0;
    bVar1 = (bStack_21 & 8) == 0;
    if (!bVar1) {
      _gpflags = 0x10;
    }
    dword_40B5080 = (uint)bVar1;
    bVar1 = (bStack_21 & 4) == 0;
    if (!bVar1) {
      _gpflags = _gpflags | 8;
    }
    dword_40B5084 = (uint)bVar1;
    sub_40800CC();
  }
  return;
}
/* GHIDRADEC_FUNCTION index=2242 start=0x407ffc0 */

void _snd_device_set_parms(uint param_1)

{
  if ((param_1 & 2) == 0) {
    _gpflags = _gpflags | 0x10;
  }
  else {
    _gpflags = _gpflags & 0xffffffef;
  }
  if ((param_1 & 1) == 0) {
    _gpflags = _gpflags & 0xfffffff7;
  }
  else {
    _gpflags = _gpflags | 8;
  }
  if (_gpflags != byte_40C6CED) {
    sub_40800CC();
    sub_4080388();
  }
  return;
}
/* GHIDRADEC_FUNCTION index=2243 start=0x4080038 */

uint _snd_device_get_parms(void)

{
  uint uVar1;
  
  uVar1 = (_gpflags & 0xf) >> 3;
  if ((_gpflags & 0x10) == 0) {
    uVar1 = uVar1 | 2;
  }
  return uVar1;
}
/* GHIDRADEC_FUNCTION index=2244 start=0x4080062 */

void _snd_device_set_volume(uint param_1)

{
  _vol_l = 0x2b - ((param_1 & 0xffff) >> 8);
  _vol_r = 0x2b - (param_1 & 0xff);
  sub_40800CC();
  sub_4080388();
  return;
}
/* GHIDRADEC_FUNCTION index=2245 start=0x40800a2 */

uint _snd_device_get_volume(void)

{
  return 0x2bU - _vol_r | (0x2b - _vol_l) * 0x100;
}
/* GHIDRADEC_FUNCTION index=2246 start=0x408036e */

void _snd_device_vol_set(void)

{
  _callout_dispatch(4,sub_40800CC,0);
  return;
}
/* GHIDRADEC_FUNCTION index=2247 start=0x40803ea */

void _snd_device_vol_save(void)

{
  _callout_dispatch(4,sub_4080388,0);
  return;
}
/* GHIDRADEC_FUNCTION index=2248 start=0x4080404 */

void _snd_dev_intr(void)

{
  _printf(aSounddspSndDev);
  _mon_csr_and(0xffffff7f);
  _mon_csr_or(0x20);
  _mon_csr_and(0xfffffff7);
  _mon_csr_or(2);
  _mon_send(3,0);
  _mon_send(7,0);
  _mon_send(0xc4,0xff);
  return;
}
/* GHIDRADEC_FUNCTION index=2249 start=0x408046e */

int _snd_device_probe(int param_1,int param_2)

{
  if (param_2 == 0) {
    param_1 = _slot_id + param_1;
  }
  else {
    param_1 = 0;
  }
  return param_1;
}

