/* GHIDRADEC_FUNCTION index=350 start=0x4010a62 */

undefined4 _ptcselect(byte param_1,int param_2)

{
  int *piVar1;
  uint *puVar2;
  int iVar3;
  uint uVar4;
  
  piVar1 = *(int **)((int)&dword_40B318A + (sword)(word)param_1 * 0xe);
  puVar2 = *(uint **)((int)&dword_40B318E + (sword)(word)param_1 * 0xe);
  if ((*(uint *)((int)piVar1 + 0x3e) & 0x10) == 0) {
    return 1;
  }
  if (param_2 == 1) {
    if ((((*(uint *)((int)piVar1 + 0x3e) & 4) != 0) && (piVar1[6] != 0)) &&
       ((*(uint *)((int)piVar1 + 0x3e) & 0x100) == 0)) {
      return 1;
    }
  }
  else {
    if (1 < param_2) {
      if (param_2 != 2) {
        return 0;
      }
      if ((*(uint *)((int)piVar1 + 0x3e) & 4) != 0) {
        if ((*puVar2 & 0x20) == 0) {
          if (piVar1[3] + *piVar1 < 0x3fe) {
            return 1;
          }
          if (piVar1[3] != 0) goto loc_4010B3A;
          uVar4 = *(uint *)((int)piVar1 + 0x3a) & 0x22;
        }
        else {
          uVar4 = piVar1[3];
        }
        if (uVar4 == 0) {
          return 1;
        }
      }
loc_4010B3A:
      iVar3 = _selthreadcache(puVar2 + 2);
      if (iVar3 == 0) {
        return 0;
      }
      uVar4 = 2;
      goto loc_4010B4A;
    }
    if (param_2 != 0) {
      return 0;
    }
  }
  if (((*(byte *)((int)piVar1 + 0x41) & 4) != 0) &&
     ((((*puVar2 & 8) != 0 && (*(char *)(puVar2 + 3) != '\0')) ||
      (((char)*puVar2 < '\0' && (*(char *)((int)puVar2 + 0xd) != '\0')))))) {
    return 1;
  }
  iVar3 = _selthreadcache(puVar2 + 1);
  if (iVar3 == 0) {
    return 0;
  }
  uVar4 = 1;
loc_4010B4A:
  *puVar2 = uVar4 | *puVar2;
  return 0;
}
/* GHIDRADEC_FUNCTION index=351 start=0x4010b5a */

int _ptcwrite(byte param_1,int *param_2)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  undefined *puVar7;
  int *piVar8;
  undefined auStack_68 [100];
  
  piVar2 = *(int **)((int)&dword_40B318A + (sword)(word)param_1 * 0xe);
  piVar8 = (int *)*param_2;
  puVar7 = (undefined *)0x0;
  iVar3 = 0;
  iVar6 = 0;
  iVar4 = *(int *)((int)&dword_40B318E + (sword)(word)param_1 * 0xe);
  do {
    if ((*(byte *)((int)piVar2 + 0x41) & 4) != 0) {
      if ((*(byte *)(iVar4 + 3) & 0x20) == 0) {
        iVar1 = param_2[1];
        do {
          if (iVar1 < 1) {
            return 0;
          }
          piVar8 = (int *)*param_2;
          if (iVar3 == 0) {
            iVar5 = piVar8[1];
            if (iVar5 != 0) {
              if (100 < iVar5) {
                iVar5 = 100;
              }
              puVar7 = auStack_68;
              iVar3 = _uiomove(puVar7,iVar5,1,param_2);
              if (iVar3 != 0) {
                return iVar3;
              }
              iVar3 = iVar5;
              if ((*(byte *)((int)piVar2 + 0x41) & 4) == 0) {
                return 5;
              }
              goto joined_r0x04010ca8;
            }
            param_2[1] = iVar1 + -1;
            *param_2 = *param_2 + 8;
          }
          else {
joined_r0x04010ca8:
            for (; 0 < iVar3; iVar3 = iVar3 + -1) {
              if ((0x3fd < piVar2[3] + *piVar2) &&
                 ((0 < piVar2[3] || ((*(uint *)((int)piVar2 + 0x3a) & 0x22) != 0)))) {
                _wakeup(piVar2);
                goto loc_4010D0E;
              }
              (**(code **)(DAT_40ae4c0 + *(char *)((int)piVar2 + 0x45) * 0x30))(*puVar7,piVar2);
              iVar6 = iVar6 + 1;
              puVar7 = puVar7 + 1;
            }
            iVar3 = 0;
          }
          iVar1 = param_2[1];
        } while( true );
      }
      if (piVar2[3] == 0) break;
    }
loc_4010D0E:
    if ((*(byte *)((int)piVar2 + 0x41) & 0x10) == 0) {
      return 5;
    }
    if ((*(byte *)(iVar4 + 3) & 4) != 0) {
      *piVar8 = *piVar8 - iVar3;
      piVar8[1] = iVar3 + piVar8[1];
      *(int *)((int)param_2 + 0x12) = iVar3 + *(int *)((int)param_2 + 0x12);
      param_2[2] = param_2[2] - iVar3;
      if (iVar6 != 0) {
        return 0;
      }
      if ((*(byte *)(*_active_u + 0x16) & 0x40) != 0) {
        return 0xb;
      }
      return 0x23;
    }
    _sleep(piVar2 + 1,0x1d);
  } while( true );
loc_4010C20:
  while( true ) {
    if ((param_2[1] < 1) || (0x3fe < piVar2[3])) {
      _putc(0,piVar2 + 3);
      _ttwakeup(piVar2);
      _wakeup(piVar2 + 3);
      return 0;
    }
    iVar4 = *(int *)(*param_2 + 4);
    if (iVar4 != 0) break;
    param_2[1] = param_2[1] + -1;
    *param_2 = *param_2 + 8;
  }
  if (iVar3 == 0) {
    if (100 < iVar4) {
      iVar4 = 100;
    }
    iVar6 = 0x3ff - piVar2[3];
    iVar3 = iVar4;
    if (iVar6 < iVar4) {
      iVar3 = iVar6;
    }
    puVar7 = auStack_68;
    iVar4 = _uiomove(puVar7,iVar3,1,param_2);
    if (iVar4 != 0) {
      return iVar4;
    }
    if ((*(byte *)((int)piVar2 + 0x41) & 4) == 0) {
      return 5;
    }
    if (iVar3 != 0) goto loc_4010C0C;
  }
  else {
loc_4010C0C:
    _b_to_q(puVar7,iVar3,piVar2 + 3);
  }
  iVar3 = 0;
  goto loc_4010C20;
}
/* GHIDRADEC_FUNCTION index=352 start=0x4010d6a */

int _ptyioctl(word param_1,uint param_2,uint *param_3,undefined4 param_4)

{
  int iVar1;
  uint *puVar2;
  bool bVar3;
  int iVar4;
  int iVar5;
  
  iVar4 = (sword)(param_1 & 0xff) * 0xe;
  iVar1 = *(int *)((int)&dword_40B318A + iVar4);
  puVar2 = *(uint **)((int)&dword_40B318E + iVar4);
  if (param_2 == 0x80047461) {
    if (*param_3 != 0) {
      if ((*puVar2 & 8) != 0) {
        *(byte *)(puVar2 + 3) = *(byte *)(puVar2 + 3) | 0x40;
        _ptcwakeup(iVar1);
      }
      *(byte *)(iVar1 + 0x3f) = *(byte *)(iVar1 + 0x3f) | 0x40;
      return 0;
    }
    if (((*(byte *)(iVar1 + 0x3f) & 0x40) != 0) && ((*puVar2 & 8) != 0)) {
      *(byte *)(puVar2 + 3) = *(byte *)(puVar2 + 3) | 0x40;
      _ptcwakeup(iVar1);
    }
    *(byte *)(iVar1 + 0x3f) = *(byte *)(iVar1 + 0x3f) & 0xbf;
    return 0;
  }
  if (*(code **)(_cdevsw + (uint)(param_1 >> 8) * 0x2c) == _ptcopen) {
    if (param_2 == 0x80047470) {
      if (*param_3 == 0) {
        *puVar2 = *puVar2 & 0xfffffff7;
        return 0;
      }
      if (-1 < (char)*puVar2) {
        *puVar2 = *puVar2 | 8;
        return 0;
      }
      return 0x16;
    }
    if ((int)param_2 < -0x7ffb8b8f) {
      if (param_2 == 0x80047401) {
loc_4010EE0:
        do {
          iVar4 = _getc(iVar1 + 0x18);
        } while (-1 < iVar4);
      }
      else if ((int)param_2 < -0x7ffb8bfe) {
        if (param_2 == 0x8004667e) {
          if (*param_3 != 0) {
            *puVar2 = *puVar2 | 4;
            return 0;
          }
          *puVar2 = *puVar2 & 0xfffffffb;
          return 0;
        }
      }
      else {
        if (param_2 == 0x80047466) {
          if (*param_3 == 0) {
            *(word *)((int)puVar2 + 2) = *(word *)((int)puVar2 + 2) & 0xff7f;
            return 0;
          }
          if ((*puVar2 & 8) == 0) {
            *puVar2 = *puVar2 | 0x80;
            return 0;
          }
          return 0x16;
        }
        if (param_2 == 0x80047469) {
          if (*param_3 == 0) {
            *puVar2 = *puVar2 & 0xffffffdf;
          }
          else {
            *puVar2 = *puVar2 | 0x20;
          }
          _ttyflush(iVar1,3);
          return 0;
        }
      }
    }
    else if ((int)param_2 < -0x7fdb8be9) {
      if ((-0x7fdb8bed < (int)param_2) ||
         (((int)param_2 < -0x7ff98bf5 && (-0x7ff98bf8 < (int)param_2)))) goto loc_4010EE0;
    }
    else if (param_2 == 0x2000745f) {
      if (*param_3 < 0x20) {
        if (-1 < *(int *)(iVar1 + 0x3a)) {
          _ttyflush(iVar1,3);
        }
        _gsignal((int)*(sword *)(iVar1 + 0x42),*param_3);
        return 0;
      }
      return 0x16;
    }
  }
  iVar4 = (**(code **)(unk_40AE4B0 + *(char *)(iVar1 + 0x45) * 0x30 + 0xc))
                    (iVar1,param_2,param_3,param_4);
  if (-1 < iVar4) {
    return iVar4;
  }
  iVar5 = _ttioctl(iVar1,param_2,param_3,param_4);
  iVar4 = *(char *)(iVar1 + 0x45) * 0x30;
  if (*(int *)(unk_40AE4B0 + iVar4 + 0x28) != 0) {
    (**(code **)(unk_40AE4B0 + iVar4))(iVar1);
    *(undefined *)(iVar1 + 0x45) = 0;
    (*_linesw)((int)(sword)param_1,iVar1);
    iVar5 = 0x19;
  }
  if (iVar5 < 0) {
    if (((char)*puVar2 < '\0') && ((param_2 & 0xffffff00) == 0x20007500)) {
      if ((char)param_2 != '\0') {
        *(char *)((int)puVar2 + 0xd) = (char)param_2;
        _ptcwakeup(iVar1,1);
      }
      return 0;
    }
    iVar5 = 0x19;
  }
  if (((*(byte *)(iVar1 + 0x3f) & 0x40) != 0) && ((*puVar2 & 8) != 0)) {
    if ((int)param_2 < -0x7ff98bf5) {
      if (((int)param_2 < -0x7ff98bf7) &&
         ((-0x7ffb8b81 < (int)param_2 || ((int)param_2 < -0x7ffb8b83)))) goto loc_4011026;
    }
    else if (param_2 != 0x80067475) {
      if ((int)param_2 < -0x7ff98b8a) {
        if (param_2 != 0x80067411) goto loc_4011026;
      }
      else if ((-0x7fdb8bea < (int)param_2) || ((int)param_2 < -0x7fdb8bec)) goto loc_4011026;
    }
    *(byte *)(puVar2 + 3) = *(byte *)(puVar2 + 3) | 0x40;
  }
loc_4011026:
  bVar3 = false;
  if ((((*(byte *)(iVar1 + 0x3d) & 0x20) == 0) &&
      (iVar4 = _ttynty(iVar1), (*(byte *)(iVar4 + 0x10) & 4) != 0)) &&
     (*(sword *)(iVar1 + 0x50) == 0x1113)) {
    bVar3 = true;
  }
  if ((*puVar2 & 0x40) == 0) {
    if (bVar3) {
      return iVar5;
    }
    *(byte *)(puVar2 + 3) = *(byte *)(puVar2 + 3) & 0xdf | 0x10;
    *puVar2 = *puVar2 | 0x40;
  }
  else {
    if (!bVar3) {
      return iVar5;
    }
    *(byte *)(puVar2 + 3) = *(byte *)(puVar2 + 3) & 0xef | 0x20;
    *puVar2 = *puVar2 & 0xffffffbf;
  }
  _ptcwakeup(iVar1,1);
  return iVar5;
}
/* GHIDRADEC_FUNCTION index=353 start=0x4011122 */

uint _ptsputc(byte param_1,char param_2)

{
  int iVar1;
  undefined (*pauVar2) [256];
  int iVar3;
  uint uVar4;
  bool bVar5;
  bool bVar6;
  bool bVar7;
  bool bVar8;
  char cStack_6;
  undefined uStack_5;
  
  iVar1 = *(int *)((int)&dword_40B318A + (sword)(word)param_1 * 0xe);
  cStack_6 = param_2;
  uVar4 = 1;
  if (param_2 == '\n') {
    uStack_5 = 0xd;
    uVar4 = 2;
  }
  iVar3 = _curipl();
  if (iVar3 < 1) {
    uVar4 = _b_to_q(&cStack_6,uVar4,iVar1 + 0x18);
    if (uVar4 == 0) {
      uVar4 = _ptsstart(iVar1);
    }
  }
  else {
    if (off_40AE690[-0x40b34] == (undefined *)0xffffff44) {
      _callout_dispatch(0,sub_40110A0,iVar1);
    }
    else if (off_40AE690[-0x40b34] == (undefined *)0x44) {
      return (uint)(byte)(((int)(off_40AE690[-0x40b35] + 0xbc) < 0) << 3 | 4);
    }
    (*off_40AE690)[0] = cStack_6;
    pauVar2 = (undefined (*) [256])(*off_40AE690 + 1);
    bVar8 = 2 < uVar4;
    bVar7 = SBORROW4(2,uVar4);
    bVar5 = (int)(2 - uVar4) < 0;
    bVar6 = false;
    if (uVar4 == 2) {
      bVar8 = pauVar2 < unk_40B3444;
      bVar7 = SBORROW4((int)pauVar2,0x40b3444);
      bVar5 = (int)(off_40AE690[-0x40b35] + 0xbd) < 0;
      bVar6 = pauVar2 == (undefined (*) [256])unk_40B3444;
      if (!bVar6) {
        off_40AE690 = pauVar2;
        (*pauVar2)[0] = uStack_5;
        bVar8 = (undefined (*) [256])0xfffffffe < off_40AE690;
        bVar7 = SCARRY4((int)off_40AE690,1);
        pauVar2 = (undefined (*) [256])(*off_40AE690 + 1);
        bVar5 = (int)pauVar2 < 0;
        bVar6 = pauVar2 == (undefined (*) [256])0x0;
      }
    }
    off_40AE690 = pauVar2;
    uVar4 = (uint)(byte)(bVar8 << 4 | bVar5 << 3 | bVar6 << 2 | bVar7 << 1 | bVar8);
  }
  return uVar4;
}
/* GHIDRADEC_FUNCTION index=354 start=0x40111f8 */

/* WARNING: Removing unreachable block (ram,0x04011238) */

uint _getc(int *param_1)

{
  byte *pbVar1;
  int *piVar2;
  int iVar3;
  uint uVar4;
  
  if (*param_1 < 1) {
    uVar4 = 0xffffffff;
    *param_1 = 0;
    param_1[2] = 0;
    param_1[1] = 0;
  }
  else {
    pbVar1 = (byte *)param_1[1];
    uVar4 = (uint)*pbVar1;
    iVar3 = (int)((uint)pbVar1 & 0x3f) >> 3;
    if (((int)*(char *)(iVar3 + 4 + ((uint)pbVar1 & 0xffffffc0)) &
        1 << (((uint)pbVar1 & 0x3f) + iVar3 * -8 & 0x1f)) != 0) {
      uVar4 = *pbVar1 | 0x100;
    }
    param_1[1] = (int)(pbVar1 + 1);
    iVar3 = *param_1;
    *param_1 = iVar3 + -1;
    if (iVar3 == 1 || iVar3 + -1 < 0) {
      piVar2 = (int *)(param_1[1] - 1U & 0xffffffc0);
      param_1[1] = 0;
      param_1[2] = 0;
      *piVar2 = (int)_cfreelist;
      _cfreelist = piVar2;
    }
    else {
      if ((param_1[1] & 0x3fU) != 0) {
        return uVar4;
      }
      piVar2 = (int *)(param_1[1] - 0x40);
      param_1[1] = *piVar2 + 0xc;
      *piVar2 = (int)_cfreelist;
      _cfreelist = piVar2;
    }
    _cfreecount = _cfreecount + 0x34;
    if (_cwaiting != '\0') {
      _wakeup(&_cwaiting);
      _cwaiting = '\0';
    }
  }
  return uVar4;
}
/* GHIDRADEC_FUNCTION index=355 start=0x40112e8 */

int _q_to_b(int *param_1,int param_2,int param_3)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  
  if (param_3 < 1) {
    iVar3 = 0;
  }
  else {
    iVar3 = param_2;
    if (*param_1 < 1) {
      *param_1 = 0;
      param_1[2] = 0;
      param_1[1] = 0;
      iVar3 = 0;
    }
    else {
      do {
        iVar4 = 0x40 - (param_1[1] & 0x3fU);
        if (param_3 < iVar4) {
          iVar4 = param_3;
        }
        if (*param_1 < iVar4) {
          iVar4 = *param_1;
        }
        _bcopy(param_1[1],iVar3,iVar4);
        param_1[1] = iVar4 + param_1[1];
        iVar1 = *param_1;
        *param_1 = iVar1 - iVar4;
        param_3 = param_3 - iVar4;
        iVar3 = iVar4 + iVar3;
        if (iVar1 - iVar4 < 1) {
          piVar2 = (int *)(param_1[1] - 1U & 0xffffffc0);
          param_1[2] = 0;
          param_1[1] = 0;
          *piVar2 = (int)_cfreelist;
          _cfreecount = _cfreecount + 0x34;
          _cfreelist = piVar2;
          if (_cwaiting != '\0') {
            _wakeup(&_cwaiting);
            _cwaiting = '\0';
          }
          break;
        }
        if ((param_1[1] & 0x3fU) == 0) {
          piVar2 = (int *)(param_1[1] - 0x40);
          param_1[1] = *piVar2 + 0xc;
          *piVar2 = (int)_cfreelist;
          _cfreecount = _cfreecount + 0x34;
          _cfreelist = piVar2;
          if (_cwaiting != '\0') {
            _wakeup(&_cwaiting);
            _cwaiting = '\0';
          }
        }
      } while (param_3 != 0);
      iVar3 = iVar3 - param_2;
    }
  }
  return iVar3;
}
/* GHIDRADEC_FUNCTION index=356 start=0x401140a */

int _ndqb(int *param_1,uint param_2)

{
  char *pcVar1;
  int iVar2;
  int iVar3;
  char *pcVar4;
  
  iVar2 = *param_1;
  if (iVar2 < 1) {
    iVar3 = -iVar2;
  }
  else {
    pcVar4 = (char *)param_1[1];
    iVar3 = ((uint)(pcVar4 + 0x34) & 0xffffffc0) - (int)pcVar4;
    if (iVar2 < iVar3) {
      iVar3 = iVar2;
    }
    if (param_2 != 0) {
      pcVar1 = pcVar4 + iVar3;
      for (; pcVar4 < pcVar1; pcVar4 = pcVar4 + 1) {
        if ((param_2 & (int)*pcVar4) != 0) {
          return (int)pcVar4 - param_1[1];
        }
      }
    }
  }
  return iVar3;
}
/* GHIDRADEC_FUNCTION index=357 start=0x4011474 */

byte _ndflush(int *param_1,uint param_2)

{
  uint uVar1;
  int *piVar2;
  int iVar3;
  int *piVar4;
  char cVar5;
  bool bVar6;
  bool bVar7;
  
  cVar5 = '\0';
  bVar6 = *param_1 < 0;
  bVar7 = *param_1 == 0;
  if (0 < *param_1) {
    while (0 < (int)param_2) {
      if (*param_1 == 0) goto loc_4011544;
      piVar2 = (int *)(param_1[1] & 0xffffffc0);
      piVar4 = (int *)param_1[2];
      if ((int *)((int)piVar4 - 1U & 0xffffffc0) != piVar2) {
        piVar4 = piVar2 + 0x10;
      }
      iVar3 = (int)piVar4 - param_1[1];
      if ((int)param_2 < iVar3) {
        *param_1 = *param_1 - param_2;
        uVar1 = param_1[1];
        cVar5 = CARRY4(param_2,uVar1);
        param_1[1] = param_2 + uVar1;
        bVar6 = *param_1 < 0;
        bVar7 = *param_1 == 0;
        if (0 < *param_1) goto loc_401154E;
        *piVar2 = (int)_cfreelist;
        cVar5 = 0xffffffcb < _cfreecount;
        _cfreecount = _cfreecount + 0x34;
        _cfreelist = piVar2;
        if (_cwaiting != '\0') {
          _wakeup(&_cwaiting);
          _cwaiting = '\0';
        }
        break;
      }
      param_2 = param_2 - iVar3;
      *param_1 = *param_1 - iVar3;
      param_1[1] = *piVar2 + 0xc;
      *piVar2 = (int)_cfreelist;
      cVar5 = 0xffffffcb < _cfreecount;
      _cfreecount = _cfreecount + 0x34;
      _cfreelist = piVar2;
      if (_cwaiting != '\0') {
        _wakeup(&_cwaiting);
        _cwaiting = '\0';
      }
    }
    bVar6 = *param_1 < 0;
    bVar7 = *param_1 == 0;
    if (*param_1 < 1) {
loc_4011544:
      param_1[2] = 0;
      param_1[1] = 0;
      *param_1 = 0;
      bVar6 = false;
      bVar7 = true;
    }
  }
loc_401154E:
  return cVar5 << 4 | bVar6 << 3 | bVar7 << 2;
}
/* GHIDRADEC_FUNCTION index=358 start=0x401155c */

/* WARNING: Removing unreachable block (ram,0x04011608) */

undefined4 _putc(uint param_1,int *param_2)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  
  puVar2 = _cfreelist;
  puVar4 = (undefined4 *)param_2[2];
  if ((puVar4 == (undefined4 *)0x0) || (*param_2 < 0)) {
    if (_cfreelist == (undefined4 *)0x0) {
      return 0xffffffff;
    }
    _cfreecount = _cfreecount + -0x34;
    puVar3 = _cfreelist + 1;
    puVar4 = (undefined4 *)*_cfreelist;
    *_cfreelist = 0;
    _cfreelist = puVar4;
    _bzero(puVar3,8);
    puVar4 = puVar2 + 3;
    param_2[1] = (int)puVar4;
  }
  else if (((uint)puVar4 & 0x3f) == 0) {
    puVar4[-0x10] = _cfreelist;
    if (puVar2 == (undefined4 *)0x0) {
      return 0xffffffff;
    }
    _cfreelist = (undefined4 *)*puVar2;
    _cfreecount = _cfreecount + -0x34;
    *puVar2 = 0;
    puVar4 = puVar2 + 3;
  }
  if ((param_1 & 0x100) != 0) {
    iVar1 = (int)((uint)puVar4 & 0x3f) >> 3;
    *(byte *)(((uint)puVar4 & 0xffffffc0) + 4 + iVar1) =
         (byte)(1 << (((uint)puVar4 & 0x3f) + iVar1 * -8 & 0x3f)) |
         *(byte *)(((uint)puVar4 & 0xffffffc0) + 4 + iVar1);
  }
  *(char *)puVar4 = (char)param_1;
  *param_2 = *param_2 + 1;
  param_2[2] = (int)puVar4 + 1;
  return 0;
}
/* GHIDRADEC_FUNCTION index=359 start=0x401163a */

uint _b_to_q(int param_1,uint param_2,int *param_3)

{
  uint uVar1;
  undefined4 *puVar2;
  uint uVar3;
  uint uVar4;
  undefined4 *puVar5;
  
  puVar2 = _cfreelist;
  if ((int)param_2 < 1) {
    return 0;
  }
  puVar5 = (undefined4 *)param_3[2];
  uVar4 = param_2;
  if ((puVar5 == (undefined4 *)0x0) || (*param_3 < 0)) {
    if (_cfreelist == (undefined4 *)0x0) goto loc_401170E;
    puVar5 = _cfreelist + 1;
    _cfreelist = (undefined4 *)*_cfreelist;
    _cfreecount = _cfreecount + -0x34;
    _bzero(puVar5,8);
    *puVar2 = 0;
    puVar5 = puVar2 + 3;
    param_3[1] = (int)puVar5;
  }
  for (; puVar2 = _cfreelist, uVar4 != 0; uVar4 = uVar4 - uVar3) {
    if (((uint)puVar5 & 0x3f) == 0) {
      puVar5[-0x10] = _cfreelist;
      if (puVar2 == (undefined4 *)0x0) break;
      _cfreelist = (undefined4 *)*puVar2;
      _cfreecount = _cfreecount + -0x34;
      _bzero(puVar2 + 1,8);
      *puVar2 = 0;
      puVar5 = puVar2 + 3;
    }
    uVar1 = 0x40 - ((uint)puVar5 & 0x3f);
    uVar3 = uVar4;
    if (uVar1 <= uVar4) {
      uVar3 = uVar1;
    }
    _bcopy(param_1,puVar5,uVar3);
    param_1 = uVar3 + param_1;
    puVar5 = (undefined4 *)(uVar3 + (int)puVar5);
  }
loc_401170E:
  param_3[2] = (int)puVar5;
  *param_3 = (param_2 - uVar4) + *param_3;
  return uVar4;
}
/* GHIDRADEC_FUNCTION index=360 start=0x4011728 */

uint _nextc(int *param_1,int param_2)

{
  uint uVar1;
  
  if ((*param_1 == 0) || (uVar1 = param_2 + 1, uVar1 == param_1[2])) {
    uVar1 = 0;
  }
  else if ((uVar1 & 0x3f) == 0) {
    uVar1 = *(int *)(param_2 + -0x3f) + 0xc;
  }
  return uVar1;
}
/* GHIDRADEC_FUNCTION index=361 start=0x4011758 */

/* WARNING: Removing unreachable block (ram,0x0401179c) */

char * _nextc3(int *param_1,int param_2,uint *param_3)

{
  char cVar1;
  int iVar2;
  char *pcVar3;
  
  if ((*param_1 == 0) || (pcVar3 = (char *)(param_2 + 1), pcVar3 == (char *)param_1[2])) {
    pcVar3 = (char *)0x0;
  }
  else {
    if (((uint)pcVar3 & 0x3f) == 0) {
      pcVar3 = (char *)(*(int *)(param_2 + -0x3f) + 0xc);
    }
    cVar1 = *pcVar3;
    *param_3 = (int)cVar1;
    iVar2 = (int)((uint)pcVar3 & 0x3f) >> 3;
    if (((int)*(char *)(iVar2 + 4 + ((uint)pcVar3 & 0xffffffc0)) &
        1 << (((uint)pcVar3 & 0x3f) + iVar2 * -8 & 0x1f)) != 0) {
      *param_3 = CONCAT22(cVar1 >> 7,(sword)cVar1) | 0x100;
    }
  }
  return pcVar3;
}
/* GHIDRADEC_FUNCTION index=362 start=0x40117c8 */

/* WARNING: Removing unreachable block (ram,0x0401180a) */

uint _unputc(int *param_1)

{
  uint uVar1;
  int *piVar2;
  int iVar3;
  uint uVar4;
  char cVar5;
  uint *puVar6;
  char *pcVar7;
  uint uVar8;
  
  if (*param_1 < 1) {
    uVar8 = 0xffffffff;
  }
  else {
    iVar3 = param_1[2];
    param_1[2] = iVar3 + -1;
    pcVar7 = (char *)(iVar3 + -1);
    cVar5 = *pcVar7;
    uVar8 = (uint)cVar5;
    iVar3 = (int)((uint)pcVar7 & 0x3f) >> 3;
    if (((int)*(char *)(iVar3 + 4 + ((uint)pcVar7 & 0xffffffc0)) &
        1 << (((uint)pcVar7 & 0x3f) + iVar3 * -8 & 0x1f)) != 0) {
      uVar8 = CONCAT22(cVar5 >> 7,(sword)cVar5) | 0x100;
    }
    iVar3 = *param_1;
    *param_1 = iVar3 + -1;
    if (iVar3 == 1 || iVar3 + -1 < 0) {
      uVar4 = param_1[2];
      param_1[1] = 0;
      param_1[2] = 0;
      *(int *)(uVar4 & 0xffffffc0) = (int)_cfreelist;
      _cfreecount = _cfreecount + 0x34;
      _cfreelist = (int *)(uVar4 & 0xffffffc0);
    }
    else {
      uVar4 = param_1[2] & 0xffffffc0;
      if (uVar4 + 0xc == param_1[2]) {
        param_1[2] = uVar4;
        puVar6 = (uint *)(param_1[1] & 0xffffffc0);
        uVar1 = *puVar6;
        while (uVar4 != uVar1) {
          puVar6 = (uint *)*puVar6;
          uVar1 = *puVar6;
        }
        param_1[2] = (int)(puVar6 + 0x10);
        piVar2 = (int *)*puVar6;
        *piVar2 = (int)_cfreelist;
        _cfreecount = _cfreecount + 0x34;
        _cfreelist = piVar2;
        *puVar6 = 0;
      }
    }
  }
  return uVar8;
}
/* GHIDRADEC_FUNCTION index=363 start=0x40118b2 */

int _catq(int *param_1,int *param_2)

{
  int iVar1;
  
  if (*param_2 == 0) {
    *param_2 = *param_1;
    param_2[1] = param_1[1];
    param_2[2] = param_1[2];
    *param_1 = 0;
    param_1[1] = 0;
    param_1[2] = 0;
    iVar1 = 4;
  }
  else {
    while (iVar1 = _getc(param_1), -1 < iVar1) {
      _putc(iVar1,param_2);
    }
  }
  return iVar1;
}
/* GHIDRADEC_FUNCTION index=364 start=0x4011916 */

undefined4 _syopen(undefined4 param_1,undefined4 param_2)

{
  undefined4 uVar1;
  
  if (*(int *)(_active_u + 0x15e) == 0) {
    uVar1 = 6;
  }
  else {
    uVar1 = (**(code **)(_cdevsw + (uint)(*(word *)(_active_u + 0x162) >> 8) * 0x2c))
                      ((int)(sword)*(word *)(_active_u + 0x162),param_2);
  }
  return uVar1;
}
/* GHIDRADEC_FUNCTION index=365 start=0x401195c */

undefined4 _syread(undefined4 param_1,undefined4 param_2)

{
  undefined4 uVar1;
  
  if (*(int *)(_active_u + 0x15e) == 0) {
    uVar1 = 6;
  }
  else {
    uVar1 = (**(code **)(DAT_40b0ac8 + (uint)(*(word *)(_active_u + 0x162) >> 8) * 0x2c))
                      ((int)(sword)*(word *)(_active_u + 0x162),param_2);
  }
  return uVar1;
}
/* GHIDRADEC_FUNCTION index=366 start=0x40119a2 */

undefined4 _sywrite(undefined4 param_1,undefined4 param_2)

{
  undefined4 uVar1;
  
  if (*(int *)(_active_u + 0x15e) == 0) {
    uVar1 = 6;
  }
  else {
    uVar1 = (**(code **)(DAT_40b0acc + (uint)(*(word *)(_active_u + 0x162) >> 8) * 0x2c))
                      ((int)(sword)*(word *)(_active_u + 0x162),param_2);
  }
  return uVar1;
}
/* GHIDRADEC_FUNCTION index=367 start=0x40119e8 */

undefined4 _syioctl(undefined4 param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  
  if (param_2 == 0x20007471) {
    iVar1 = *_active_u;
    iVar3 = _get_posix_proc((int)*(sword *)(iVar1 + 0x30));
    iVar2 = *(int *)(*(int *)(iVar3 + 0xe) + 8);
    if (iVar1 == *(int *)(iVar2 + 4)) {
      *(undefined4 *)(iVar2 + 8) = 0;
      *(undefined2 *)(*(int *)(*(int *)(iVar3 + 0xe) + 8) + 0xc) = 0;
    }
    *(byte *)(iVar1 + 0x28) = *(byte *)(iVar1 + 0x28) & 0xbf;
    *(undefined4 *)((int)_active_u + 0x15e) = 0;
    *(undefined2 *)((int)_active_u + 0x162) = 0;
    uVar4 = 0;
  }
  else if (*(int *)((int)_active_u + 0x15e) == 0) {
    uVar4 = 6;
  }
  else {
    uVar4 = (**(code **)(DAT_40b0ad0 + (uint)(*(word *)((int)_active_u + 0x162) >> 8) * 0x2c))
                      ((int)(sword)*(word *)((int)_active_u + 0x162),param_2,param_3,param_4);
  }
  return uVar4;
}
/* GHIDRADEC_FUNCTION index=368 start=0x4011a96 */

undefined4 _syselect(undefined4 param_1,undefined4 param_2)

{
  undefined4 uVar1;
  
  if (*(int *)(_active_u + 0x15e) == 0) {
    *(undefined *)(dword_40B57D4 + 100) = 6;
    uVar1 = 0;
  }
  else {
    uVar1 = (*(code *)(&DAT_40b0adc)[(uint)(*(word *)(_active_u + 0x162) >> 8) * 0xb])
                      ((int)(sword)*(word *)(_active_u + 0x162),param_2);
  }
  return uVar1;
}
/* GHIDRADEC_FUNCTION index=369 start=0x4011ae8 */

void _domaininit(void)

{
  uint uVar1;
  undefined *puVar2;
  
  unk_40AE73A = _domains;
  unk_40AEABC = _unixdomain;
  _domains = _inetdomain;
  puVar2 = _inetdomain;
  do {
    if (*(code **)(puVar2 + 8) != (code *)0x0) {
      (**(code **)(puVar2 + 8))();
    }
    uVar1 = *(uint *)(puVar2 + 0x14);
    if (uVar1 < *(uint *)(puVar2 + 0x18)) {
      do {
        if (*(code **)(uVar1 + 0x1e) != (code *)0x0) {
          (**(code **)(uVar1 + 0x1e))();
        }
        uVar1 = uVar1 + 0x2e;
      } while (uVar1 < *(uint *)(puVar2 + 0x18));
    }
    puVar2 = *(undefined **)(puVar2 + 0x1c);
  } while (puVar2 != (undefined *)0x0);
  _null_init();
  _pffasttimo();
  _pfslowtimo();
  return;
}
/* GHIDRADEC_FUNCTION index=370 start=0x4011b74 */

sword * _pffindtype(int param_1,int param_2)

{
  int *piVar1;
  sword *psVar2;
  
  piVar1 = _domains;
  while( true ) {
    if (piVar1 == (int *)0x0) {
      return (sword *)0x0;
    }
    if (param_1 == *piVar1) break;
    piVar1 = (int *)piVar1[7];
  }
  psVar2 = (sword *)piVar1[5];
  while( true ) {
    if ((sword *)piVar1[6] <= psVar2) {
      return (sword *)0x0;
    }
    if ((*psVar2 != 0) && (param_2 == *psVar2)) break;
    psVar2 = psVar2 + 0x17;
  }
  return psVar2;
}
/* GHIDRADEC_FUNCTION index=371 start=0x4011bc8 */

sword * _pffindproto(int param_1,int param_2,int param_3)

{
  int *piVar1;
  sword *psVar2;
  sword *psVar3;
  sword *psVar4;
  
  psVar2 = (sword *)0x0;
  piVar1 = _domains;
  if (param_1 == 0) {
    return (sword *)0x0;
  }
  while( true ) {
    if (piVar1 == (int *)0x0) {
      return (sword *)0x0;
    }
    if (param_1 == *piVar1) break;
    piVar1 = (int *)piVar1[7];
  }
  psVar3 = (sword *)piVar1[5];
  if (psVar3 < (sword *)piVar1[6]) {
    psVar4 = psVar3 + 3;
    do {
      if ((param_2 == *psVar4) && (param_3 == *psVar3)) {
        return psVar3;
      }
      if ((((param_3 == 3) && (*psVar3 == 3)) && (*psVar4 == 0)) && (psVar2 == (sword *)0x0)) {
        psVar2 = psVar3;
      }
      psVar4 = psVar4 + 0x17;
      psVar3 = psVar3 + 0x17;
    } while (psVar3 < (sword *)piVar1[6]);
    return psVar2;
  }
  return (sword *)0x0;
}
/* GHIDRADEC_FUNCTION index=372 start=0x4011c4c */

void _pfctlinput(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  uint uVar2;
  
  for (iVar1 = _domains; iVar1 != 0; iVar1 = *(int *)(iVar1 + 0x1c)) {
    uVar2 = *(uint *)(iVar1 + 0x14);
    if (uVar2 < *(uint *)(iVar1 + 0x18)) {
      do {
        if (*(code **)(uVar2 + 0x12) != (code *)0x0) {
          (**(code **)(uVar2 + 0x12))(param_1,param_2,0);
        }
        uVar2 = uVar2 + 0x2e;
      } while (uVar2 < *(uint *)(iVar1 + 0x18));
    }
  }
  return;
}
/* GHIDRADEC_FUNCTION index=373 start=0x4011ca0 */

void _pfslowtimo(void)

{
  int iVar1;
  uint uVar2;
  
  for (iVar1 = _domains; iVar1 != 0; iVar1 = *(int *)(iVar1 + 0x1c)) {
    uVar2 = *(uint *)(iVar1 + 0x14);
    if (uVar2 < *(uint *)(iVar1 + 0x18)) {
      do {
        if (*(code **)(uVar2 + 0x26) != (code *)0x0) {
          (**(code **)(uVar2 + 0x26))();
        }
        uVar2 = uVar2 + 0x2e;
      } while (uVar2 < *(uint *)(iVar1 + 0x18));
    }
  }
  iVar1 = _hz;
  if (_hz < 0) {
    iVar1 = _hz + 1;
  }
  _timeout(_pfslowtimo,0,iVar1 >> 1);
  return;
}
/* GHIDRADEC_FUNCTION index=374 start=0x4011d00 */

void _pffasttimo(void)

{
  int iVar1;
  uint uVar2;
  
  for (iVar1 = _domains; iVar1 != 0; iVar1 = *(int *)(iVar1 + 0x1c)) {
    uVar2 = *(uint *)(iVar1 + 0x14);
    if (uVar2 < *(uint *)(iVar1 + 0x18)) {
      do {
        if (*(code **)(uVar2 + 0x22) != (code *)0x0) {
          (**(code **)(uVar2 + 0x22))();
        }
        uVar2 = uVar2 + 0x2e;
      } while (uVar2 < *(uint *)(iVar1 + 0x18));
    }
  }
  _timeout(_pffasttimo,0,_hz / 5);
  return;
}
/* GHIDRADEC_FUNCTION index=375 start=0x4011d6a */

byte _mbinit(void)

{
  int iVar1;
  int iVar2;
  char cVar3;
  
  if (_m68k_page_size < 0x1000) {
    iVar2 = 0x1000 / _m68k_page_size;
  }
  else {
    iVar2 = 1;
  }
  cVar3 = CARRY4(iVar2 * 5,iVar2 * 5);
  iVar1 = _m_clalloc(iVar2 * 10,0,0);
  if (iVar1 != 0) {
    iVar2 = _m_clalloc(iVar2 * 10,1,0);
    if (iVar2 != 0) {
      return cVar3 << 4 | (iVar2 < 0) << 3;
    }
  }
                    /* WARNING: Subroutine does not return */
  _panic(&aMbinit);
}
/* GHIDRADEC_FUNCTION index=376 start=0x4011de8 */

undefined4 * _m_clalloc(int param_1,int param_2)

{
  undefined4 *puVar1;
  int iVar2;
  uint uVar3;
  undefined4 *puVar4;
  
  puVar1 = (undefined4 *)
           _kmem_mb_alloc(_mb_map,~_page_mask & _page_mask + _m68k_page_size * param_1);
  if (puVar1 == (undefined4 *)0x0) {
    puVar1 = (undefined4 *)0x0;
  }
  else if (param_2 == 1) {
    param_1 = _m68k_page_size * param_1;
    if (param_1 < 0) {
      param_1 = param_1 + 0x3ff;
    }
    param_1 = param_1 >> 10;
    iVar2 = 0;
    if (0 < param_1) {
      do {
        puVar4 = puVar1;
        puVar4[1] = 0;
        *puVar4 = _mclfree;
        puVar1 = puVar4 + 0x100;
        dword_40B61BC = dword_40B61BC + 1;
        iVar2 = iVar2 + 1;
        _mclfree = puVar4;
      } while (iVar2 < param_1);
    }
    dword_40B61B4 = param_1 + dword_40B61B4;
  }
  else if (param_2 < 2) {
    if ((param_2 == 0) && (uVar3 = (uint)(_m68k_page_size * param_1) >> 7, uVar3 != 0)) {
      do {
        puVar1[1] = 0;
        *(undefined2 *)((int)puVar1 + 10) = 1;
        word_40B61CE = word_40B61CE + 1;
        _mbstat = _mbstat + 1;
        _m_free(puVar1);
        puVar1 = puVar1 + 0x20;
        uVar3 = uVar3 - 1;
      } while (0 < (int)uVar3);
    }
  }
  else if (param_2 == 2) {
    dword_40B61B8 = param_1 + dword_40B61B8;
  }
  return puVar1;
}
/* GHIDRADEC_FUNCTION index=377 start=0x4011ee0 */

void _m_pgfree(void)

{
  return;
}
/* GHIDRADEC_FUNCTION index=378 start=0x4011ee8 */

undefined4 _m_expand(int param_1)

{
  bool bVar1;
  int iVar2;
  uint uVar3;
  
  bVar1 = false;
  while( true ) {
    iVar2 = _m_clalloc(1,0,param_1);
    if (iVar2 != 0) {
      return 1;
    }
    if ((param_1 == 0) || (iVar2 = _domains, bVar1)) break;
    for (; iVar2 != 0; iVar2 = *(int *)(iVar2 + 0x1c)) {
      uVar3 = *(uint *)(iVar2 + 0x14);
      if (uVar3 < *(uint *)(iVar2 + 0x18)) {
        do {
          if (*(code **)(uVar3 + 0x2a) != (code *)0x0) {
            (**(code **)(uVar3 + 0x2a))();
          }
          uVar3 = uVar3 + 0x2e;
        } while (uVar3 < *(uint *)(iVar2 + 0x18));
      }
    }
    unk_40B61C8 = unk_40B61C8 + 1;
    bVar1 = true;
  }
  return 0;
}
/* GHIDRADEC_FUNCTION index=379 start=0x4011f64 */

undefined4 * _m_get(undefined4 param_1,int param_2)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  
  puVar2 = _mfree;
  if (_mfree == (undefined4 *)0x0) {
    puVar2 = (undefined4 *)_m_more(param_1,param_2);
  }
  else {
    if (*(sword *)((int)_mfree + 10) != 0) {
                    /* WARNING: Subroutine does not return */
      _panic(&aMget);
    }
    *(sword *)((int)_mfree + 10) = (sword)param_2;
    word_40B61CC = word_40B61CC + -1;
    (&word_40B61CC)[param_2] = (&word_40B61CC)[param_2] + 1;
    puVar1 = (undefined4 *)*_mfree;
    *_mfree = 0;
    _mfree = puVar1;
    puVar2[1] = 0xc;
  }
  return puVar2;
}
/* GHIDRADEC_FUNCTION index=380 start=0x4011fd4 */

undefined4 * _m_getclr(undefined4 param_1,int param_2)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  
  puVar2 = _mfree;
  if (_mfree == (undefined4 *)0x0) {
    puVar2 = (undefined4 *)_m_more(param_1,param_2);
  }
  else {
    if (*(sword *)((int)_mfree + 10) != 0) {
                    /* WARNING: Subroutine does not return */
      _panic(&aMget);
    }
    *(sword *)((int)_mfree + 10) = (sword)param_2;
    word_40B61CC = word_40B61CC + -1;
    (&word_40B61CC)[param_2] = (&word_40B61CC)[param_2] + 1;
    puVar1 = (undefined4 *)*_mfree;
    *_mfree = 0;
    _mfree = puVar1;
    puVar2[1] = 0xc;
  }
  if (puVar2 == (undefined4 *)0x0) {
    puVar2 = (undefined4 *)0x0;
  }
  else {
    _bzero(puVar2[1] + (int)puVar2,0x70);
  }
  return puVar2;
}
/* GHIDRADEC_FUNCTION index=381 start=0x4012062 */

undefined4 _m_free(undefined4 *param_1)

{
  undefined4 uVar1;
  
  if (*(sword *)((int)param_1 + 10) == 0) {
                    /* WARNING: Subroutine does not return */
    _panic(&aMfree);
  }
  (&word_40B61CC)[*(sword *)((int)param_1 + 10)] =
       (&word_40B61CC)[*(sword *)((int)param_1 + 10)] + -1;
  word_40B61CC = word_40B61CC + 1;
  *(undefined2 *)((int)param_1 + 10) = 0;
  if (0x7f < (uint)param_1[1]) {
    _mclput(param_1);
  }
  uVar1 = *param_1;
  *param_1 = _mfree;
  param_1[1] = 0;
  param_1[0x1f] = 0;
  _mfree = param_1;
  if (_m_want != 0) {
    _m_want = 0;
    _wakeup(&_mfree);
  }
  return uVar1;
}
/* GHIDRADEC_FUNCTION index=382 start=0x40120f2 */

undefined4 * _m_more(int param_1,int param_2)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  int iVar3;
  
  while (iVar3 = _m_expand(param_1), puVar1 = _mfree, iVar3 == 0) {
    if (param_1 != 1) {
      unk_40B61C0 = unk_40B61C0 + 1;
      return (undefined4 *)0x0;
    }
    unk_40B61C4 = unk_40B61C4 + 1;
    _m_want = _m_want + 1;
    _sleep(&_mfree,0x18);
  }
  if (_mfree == (undefined4 *)0x0) {
                    /* WARNING: Subroutine does not return */
    _panic(&aMMore);
  }
  if (*(sword *)((int)_mfree + 10) == 0) {
    *(sword *)((int)_mfree + 10) = (sword)param_2;
    word_40B61CC = word_40B61CC + -1;
    (&word_40B61CC)[param_2] = (&word_40B61CC)[param_2] + 1;
    uVar2 = *_mfree;
    *_mfree = 0;
    _mfree = (undefined4 *)uVar2;
    puVar1[1] = 0xc;
    return puVar1;
  }
                    /* WARNING: Subroutine does not return */
  _panic(&aMget);
}
/* GHIDRADEC_FUNCTION index=383 start=0x40121a6 */

void _m_freem(undefined4 *param_1)

{
  undefined4 *puVar1;
  bool bVar2;
  
  while( true ) {
    puVar1 = param_1;
    if (puVar1 == (undefined4 *)0x0) {
      return;
    }
    if (*(sword *)((int)puVar1 + 10) == 0) break;
    (&word_40B61CC)[*(sword *)((int)puVar1 + 10)] =
         (&word_40B61CC)[*(sword *)((int)puVar1 + 10)] + -1;
    word_40B61CC = word_40B61CC + 1;
    *(undefined2 *)((int)puVar1 + 10) = 0;
    if (0x7f < (uint)puVar1[1]) {
      _mclput(puVar1);
    }
    param_1 = (undefined4 *)*puVar1;
    *puVar1 = _mfree;
    puVar1[1] = 0;
    puVar1[0x1f] = 0;
    bVar2 = _m_want != 0;
    _m_want = 0;
    _mfree = puVar1;
    if (bVar2) {
      _m_want = 0;
      _wakeup(&_mfree);
    }
  }
                    /* WARNING: Subroutine does not return */
  _panic(&aMfree);
}
/* GHIDRADEC_FUNCTION index=384 start=0x4012250 */

undefined4 _m_copy(undefined4 *param_1,int param_2,int param_3)

{
  sword *psVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  sword sVar4;
  undefined4 uStack_8;
  
  if (param_3 == 0) {
loc_40123B8:
    uStack_8 = 0;
  }
  else {
    if ((param_2 < 0) || (param_3 < 0)) {
                    /* WARNING: Subroutine does not return */
      _panic(&aMCopy);
    }
    for (; 0 < param_2; param_2 = param_2 - *psVar1) {
      if (param_1 == (undefined4 *)0x0) {
                    /* WARNING: Subroutine does not return */
        _panic(&aMCopy);
      }
      psVar1 = (sword *)(param_1 + 2);
      if (param_2 < *psVar1) break;
      param_1 = (undefined4 *)*param_1;
    }
    uStack_8 = 0;
    puVar2 = &uStack_8;
    puVar3 = _mfree;
    while (_mfree = puVar3, 0 < param_3) {
      if (param_1 == (undefined4 *)0x0) {
        if (param_3 == 1000000000) {
          return uStack_8;
        }
                    /* WARNING: Subroutine does not return */
        _panic(&aMCopy);
      }
      if (puVar3 == (undefined4 *)0x0) {
        puVar3 = (undefined4 *)_m_more(0,(int)*(sword *)((int)param_1 + 10));
      }
      else {
        if (*(sword *)((int)puVar3 + 10) != 0) {
                    /* WARNING: Subroutine does not return */
          _panic(&aMget);
        }
        *(undefined2 *)((int)puVar3 + 10) = *(undefined2 *)((int)param_1 + 10);
        word_40B61CC = word_40B61CC + -1;
        (&word_40B61CC)[*(sword *)((int)param_1 + 10)] =
             (&word_40B61CC)[*(sword *)((int)param_1 + 10)] + 1;
        _mfree = (undefined4 *)*puVar3;
        *puVar3 = 0;
        puVar3[1] = 0xc;
      }
      *puVar2 = puVar3;
      if (puVar3 == (undefined4 *)0x0) {
        _m_freem(uStack_8);
        goto loc_40123B8;
      }
      sVar4 = (sword)param_3;
      if (*(sword *)(param_1 + 2) - param_2 < param_3) {
        sVar4 = (sword)(*(sword *)(param_1 + 2) - param_2);
      }
      *(sword *)(puVar3 + 2) = sVar4;
      if (((uint)param_1[1] < 0x7d) || (sVar4 < 0x71)) {
        _bcopy((int)param_1 + param_2 + param_1[1],puVar3[1] + (int)puVar3,
               (int)*(sword *)(puVar3 + 2));
      }
      else {
        _mcldup(param_1,puVar3,param_2);
        puVar3[1] = param_2 + puVar3[1];
      }
      if (param_3 != 1000000000) {
        param_3 = param_3 - *(sword *)(puVar3 + 2);
      }
      param_2 = 0;
      param_1 = (undefined4 *)*param_1;
      puVar2 = puVar3;
      puVar3 = _mfree;
    }
  }
  return uStack_8;
}
/* GHIDRADEC_FUNCTION index=385 start=0x40123c4 */

void _m_cat(int *param_1,int param_2)

{
  int iVar1;
  uint uVar2;
  
  iVar1 = *param_1;
  while (iVar1 != 0) {
    param_1 = (int *)*param_1;
    iVar1 = *param_1;
  }
  while( true ) {
    if (param_2 == 0) {
      return;
    }
    uVar2 = param_1[1];
    if (0x7b < uVar2) break;
    if (0x7c < (int)*(sword *)(param_2 + 8) + (int)*(sword *)(param_1 + 2) + uVar2) break;
    _bcopy(*(int *)(param_2 + 4) + param_2,(int)param_1 + (int)*(sword *)(param_1 + 2) + uVar2,
           (int)*(sword *)(param_2 + 8));
    *(sword *)(param_1 + 2) = *(sword *)(param_2 + 8) + *(sword *)(param_1 + 2);
    param_2 = _m_free(param_2);
  }
  *param_1 = param_2;
  return;
}
/* GHIDRADEC_FUNCTION index=386 start=0x401243e */

void _m_adj(int *param_1,int param_2)

{
  int iVar1;
  int *piVar2;
  sword sVar3;
  int iVar4;
  
  if (param_1 != (int *)0x0) {
    if (param_2 < 0) {
      iVar4 = (int)*(sword *)(param_1 + 2);
      iVar1 = *param_1;
      piVar2 = param_1;
      while (iVar1 != 0) {
        piVar2 = (int *)*piVar2;
        iVar4 = *(sword *)(piVar2 + 2) + iVar4;
        iVar1 = *piVar2;
      }
      sVar3 = *(sword *)(piVar2 + 2);
      if (-(int)sVar3 == param_2 || -param_2 < (int)sVar3) {
        *(sword *)(piVar2 + 2) = sVar3 - (sword)-param_2;
      }
      else {
        iVar4 = iVar4 + param_2;
        for (; param_1 != (int *)0x0; param_1 = (int *)*param_1) {
          if (iVar4 <= *(sword *)(param_1 + 2)) {
            *(sword *)(param_1 + 2) = (sword)iVar4;
            break;
          }
          iVar4 = iVar4 - *(sword *)(param_1 + 2);
        }
        while (param_1 = (int *)*param_1, param_1 != (int *)0x0) {
          *(undefined2 *)(param_1 + 2) = 0;
        }
      }
    }
    else {
      do {
        if (param_2 < 1) {
          return;
        }
        sVar3 = *(sword *)(param_1 + 2);
        if (param_2 < sVar3) {
          *(sword *)(param_1 + 2) = sVar3 - (sword)param_2;
          param_1[1] = param_2 + param_1[1];
          return;
        }
        param_2 = param_2 - sVar3;
        *(undefined2 *)(param_1 + 2) = 0;
        param_1 = (int *)*param_1;
      } while (param_1 != (int *)0x0);
    }
  }
  return;
}
/* GHIDRADEC_FUNCTION index=387 start=0x40124de */

undefined4 * _m_pullup(undefined4 *param_1,int param_2)

{
  int iVar1;
  sword sVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  int iVar5;
  
  puVar4 = _mfree;
  if (((uint)(param_2 + param_1[1]) < 0x7d) && ((undefined4 *)*param_1 != (undefined4 *)0x0)) {
    param_2 = param_2 - *(sword *)(param_1 + 2);
    puVar4 = param_1;
    param_1 = (undefined4 *)*param_1;
  }
  else {
    if (0x70 < param_2) goto loc_40125FE;
    if (_mfree == (undefined4 *)0x0) {
      puVar4 = (undefined4 *)_m_more(0,(int)*(sword *)((int)param_1 + 10));
    }
    else {
      if (*(sword *)((int)_mfree + 10) != 0) {
                    /* WARNING: Subroutine does not return */
        _panic(&aMget);
      }
      *(undefined2 *)((int)_mfree + 10) = *(undefined2 *)((int)param_1 + 10);
      word_40B61CC = word_40B61CC + -1;
      (&word_40B61CC)[*(sword *)((int)param_1 + 10)] =
           (&word_40B61CC)[*(sword *)((int)param_1 + 10)] + 1;
      puVar3 = (undefined4 *)*_mfree;
      *_mfree = 0;
      _mfree = puVar3;
      puVar4[1] = 0xc;
    }
    if (puVar4 == (undefined4 *)0x0) goto loc_40125FE;
    *(undefined2 *)(puVar4 + 2) = 0;
  }
  iVar1 = puVar4[1];
  do {
    iVar5 = (0x7c - iVar1) - (int)*(sword *)(puVar4 + 2);
    if (param_2 + 0x20 < iVar5) {
      iVar5 = param_2 + 0x20;
    }
    if (*(sword *)(param_1 + 2) < iVar5) {
      iVar5 = (int)*(sword *)(param_1 + 2);
    }
    _bcopy(param_1[1] + (int)param_1,(int)puVar4 + (int)*(sword *)(puVar4 + 2) + puVar4[1],iVar5);
    param_2 = param_2 - iVar5;
    *(sword *)(puVar4 + 2) = (sword)iVar5 + *(sword *)(puVar4 + 2);
    sVar2 = *(sword *)(param_1 + 2) - (sword)iVar5;
    *(sword *)(param_1 + 2) = sVar2;
    if (sVar2 == 0) {
      param_1 = (undefined4 *)_m_free(param_1);
    }
    else {
      param_1[1] = iVar5 + param_1[1];
    }
    if (param_2 < 1) {
      *puVar4 = param_1;
      return puVar4;
    }
  } while (param_1 != (undefined4 *)0x0);
  _m_free(puVar4);
  param_1 = (undefined4 *)0x0;
loc_40125FE:
  _m_freem(param_1);
  return (undefined4 *)0x0;
}
/* GHIDRADEC_FUNCTION index=388 start=0x4012612 */

int _mclget(int param_1)

{
  undefined4 *puVar1;
  
  if (_mclfree == (undefined4 *)0x0) {
    _m_clalloc(1,1,0);
  }
  puVar1 = _mclfree;
  if (_mclfree != (undefined4 *)0x0) {
    _mclrefcnt[(int)_mclfree - _mbutl >> 10] = _mclrefcnt[(int)_mclfree - _mbutl >> 10] + '\x01';
    dword_40B61BC = dword_40B61BC + -1;
    _mclfree = (undefined4 *)*_mclfree;
    *(undefined2 *)(param_1 + 8) = 0x400;
    *(int *)(param_1 + 4) = (int)puVar1 - param_1;
    *(undefined2 *)(param_1 + 0xc) = 1;
  }
  return -(int)-(puVar1 != (undefined4 *)0x0);
}
/* GHIDRADEC_FUNCTION index=389 start=0x4012698 */

undefined4 *
_mclgetx(undefined4 param_1,undefined4 param_2,int param_3,undefined2 param_4,undefined4 param_5)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  
  puVar2 = _mfree;
  if (_mfree == (undefined4 *)0x0) {
    puVar2 = (undefined4 *)_m_more(param_5,1);
  }
  else {
    if (*(sword *)((int)_mfree + 10) != 0) {
                    /* WARNING: Subroutine does not return */
      _panic(&aMget);
    }
    *(undefined2 *)((int)_mfree + 10) = 1;
    word_40B61CC = word_40B61CC + -1;
    word_40B61CE = word_40B61CE + 1;
    puVar1 = (undefined4 *)*_mfree;
    *_mfree = 0;
    _mfree = puVar1;
    puVar2[1] = 0xc;
  }
  if (puVar2 == (undefined4 *)0x0) {
    puVar2 = (undefined4 *)0x0;
  }
  else {
    puVar2[1] = param_3 - (int)puVar2;
    *(undefined2 *)(puVar2 + 2) = param_4;
    *(undefined2 *)(puVar2 + 3) = 2;
    *(undefined4 *)((int)puVar2 + 0xe) = param_1;
    *(undefined4 *)((int)puVar2 + 0x12) = param_2;
    *(undefined4 *)((int)puVar2 + 0x16) = 0;
  }
  return puVar2;
}
/* GHIDRADEC_FUNCTION index=390 start=0x4012738 */

void _mclput(int param_1)

{
  char cVar1;
  int iVar2;
  undefined4 *puVar3;
  
  if (*(sword *)(param_1 + 0xc) == 1) {
    puVar3 = (undefined4 *)(*(int *)(param_1 + 4) + param_1 & 0xfffffc00);
    iVar2 = (int)puVar3 - _mbutl >> 10;
    cVar1 = _mclrefcnt[iVar2];
    _mclrefcnt[iVar2] = cVar1 + -1;
    if (cVar1 == '\x01') {
      *puVar3 = _mclfree;
      dword_40B61BC = dword_40B61BC + 1;
      _mclfree = puVar3;
    }
  }
  else {
    if (*(sword *)(param_1 + 0xc) != 2) {
                    /* WARNING: Subroutine does not return */
      _panic(&aMclput);
    }
    (**(code **)(param_1 + 0xe))(*(undefined4 *)(param_1 + 0x12));
  }
  return;
}
/* GHIDRADEC_FUNCTION index=391 start=0x40127cc */

void _mcldup(int param_1,int param_2,int param_3)

{
  int *piVar1;
  
  if (*(sword *)(param_1 + 0xc) == 1) {
    param_1 = *(int *)(param_1 + 4) + param_1;
    *(int *)(param_2 + 4) = param_1 - param_2;
    *(undefined2 *)(param_2 + 0xc) = 1;
    _mclrefcnt[param_1 - _mbutl >> 10] = _mclrefcnt[param_1 - _mbutl >> 10] + '\x01';
  }
  else {
    if (*(sword *)(param_1 + 0xc) != 2) {
                    /* WARNING: Subroutine does not return */
      _panic(&aMcldup);
    }
    piVar1 = (int *)_kalloc(*(sword *)(param_2 + 8) + 4);
    *piVar1 = *(sword *)(param_2 + 8) + 4;
    _bcopy(param_3 + *(int *)(param_1 + 4) + param_1,piVar1 + 1,(int)*(sword *)(param_2 + 8));
    *(int *)(param_2 + 4) = (int)piVar1 + (-param_3 - (param_2 + -4));
    *(undefined2 *)(param_2 + 0xc) = 2;
    *(undefined4 *)(param_2 + 0xe) = 0x40127b6;
    *(int **)(param_2 + 0x12) = piVar1;
    *(undefined4 *)(param_2 + 0x16) = 0;
  }
  return;
}
/* GHIDRADEC_FUNCTION index=392 start=0x401288c */

undefined4 _piconnect(int param_1,int param_2)

{
  *(undefined4 *)(*(int *)(param_1 + 8) + 0xc) = *(undefined4 *)(param_2 + 8);
  *(undefined4 *)(*(int *)(param_2 + 8) + 0xc) = *(undefined4 *)(param_1 + 8);
  *(undefined2 *)(param_1 + 0x3a) = 0x1000;
  *(undefined2 *)(param_1 + 0x3e) = 0x2000;
  *(word *)(param_1 + 6) = *(word *)(param_1 + 6) | 0x22;
  *(undefined2 *)(param_2 + 0x24) = 0;
  *(undefined2 *)(param_2 + 0x28) = 0;
  *(word *)(param_2 + 6) = *(word *)(param_2 + 6) | 0x12;
  return 1;
}
/* GHIDRADEC_FUNCTION index=393 start=0x40128d8 */

int _socreate(undefined4 param_1,undefined4 *param_2,int param_3,int param_4)

{
  sword *psVar1;
  int iVar2;
  undefined2 *puVar3;
  
  if (param_4 == 0) {
    psVar1 = (sword *)_pffindtype(param_1,param_3);
  }
  else {
    psVar1 = (sword *)_pffindproto(param_1,param_4,param_3);
  }
  if (psVar1 == (sword *)0x0) {
    iVar2 = 0x2b;
  }
  else if (param_3 == *psVar1) {
    iVar2 = _m_getclr(1,3);
    puVar3 = (undefined2 *)(*(int *)(iVar2 + 4) + iVar2);
    puVar3[1] = 0x20;
    puVar3[3] = 0;
    *puVar3 = (sword)param_3;
    if (*(sword *)(*(int *)(_active_u + 0x1a) + 2) == 0) {
      puVar3[3] = 0x80;
    }
    *(sword **)(puVar3 + 6) = psVar1;
    iVar2 = (**(code **)(psVar1 + 0xd))(puVar3,0,0,param_4,0);
    if (iVar2 == 0) {
      *param_2 = puVar3;
      iVar2 = 0;
    }
    else {
      puVar3[3] = puVar3[3] | 1;
      _sofree(puVar3);
    }
  }
  else {
    iVar2 = 0x29;
  }
  return iVar2;
}
/* GHIDRADEC_FUNCTION index=394 start=0x401299e */

void _sobind(int param_1,undefined4 param_2)

{
  (**(code **)(*(int *)(param_1 + 0xc) + 0x1a))(param_1,2,0,param_2,0);
  return;
}
/* GHIDRADEC_FUNCTION index=395 start=0x40129d6 */

int _solisten(int param_1,int param_2)

{
  int iVar1;
  
  iVar1 = (**(code **)(*(int *)(param_1 + 0xc) + 0x1a))(param_1,3,0,0,0);
  if (iVar1 == 0) {
    if (*(int *)(param_1 + 0x1a) == 0) {
      *(int *)(param_1 + 0x1a) = param_1;
      *(int *)(param_1 + 0x14) = param_1;
      *(word *)(param_1 + 2) = *(word *)(param_1 + 2) | 2;
    }
    if (param_2 < 0) {
      param_2 = 0;
    }
    if (0x80 < param_2) {
      param_2 = 0x80;
    }
    *(sword *)(param_1 + 0x20) = (sword)param_2;
    iVar1 = 0;
  }
  return iVar1;
}
/* GHIDRADEC_FUNCTION index=396 start=0x4012a4e */

void _sofree(uint param_1)

{
  int iVar1;
  
  if ((*(int *)(param_1 + 8) == 0) && ((*(byte *)(param_1 + 7) & 1) != 0)) {
    if (*(int *)(param_1 + 0x10) != 0) {
      iVar1 = _soqremque(param_1,0);
      if (iVar1 == 0) {
        iVar1 = _soqremque(param_1,1);
        if (iVar1 == 0) {
                    /* WARNING: Subroutine does not return */
          _panic(aSofreeDq);
        }
      }
      *(undefined4 *)(param_1 + 0x10) = 0;
    }
    _sbrelease(param_1 + 0x38);
    _sorflush(param_1);
    _m_free(param_1 & 0xffffff80);
  }
  return;
}
/* GHIDRADEC_FUNCTION index=397 start=0x4012aca */

int _soclose(int param_1)

{
  int iVar1;
  int iVar2;
  
  iVar2 = 0;
  if ((*(byte *)(param_1 + 3) & 2) != 0) {
    iVar1 = *(int *)(param_1 + 0x14);
    while (param_1 != iVar1) {
      _soabort(*(undefined4 *)(param_1 + 0x14));
      iVar1 = *(int *)(param_1 + 0x14);
    }
    while (param_1 != *(int *)(param_1 + 0x1a)) {
      _soabort(*(undefined4 *)(param_1 + 0x1a));
    }
  }
  if (*(int *)(param_1 + 8) != 0) {
    if (((*(word *)(param_1 + 6) & 2) != 0) &&
       (((((*(word *)(param_1 + 6) & 8) != 0 || (iVar2 = _sodisconnect(param_1), iVar2 == 0)) &&
         (*(char *)(param_1 + 3) < '\0')) &&
        (((*(word *)(param_1 + 6) & 0x108) != 0x108 && ((*(word *)(param_1 + 6) & 2) != 0)))))) {
      do {
        _sleep(param_1 + 0x4e,0x1a);
      } while ((*(byte *)(param_1 + 7) & 2) != 0);
    }
    if ((*(int *)(param_1 + 8) != 0) &&
       (iVar1 = (**(code **)(*(int *)(param_1 + 0xc) + 0x1a))(param_1,1,0,0,0), iVar2 == 0)) {
      iVar2 = iVar1;
    }
  }
  if ((*(byte *)(param_1 + 7) & 1) != 0) {
                    /* WARNING: Subroutine does not return */
    _panic(aSocloseNofdref);
  }
  *(word *)(param_1 + 6) = *(word *)(param_1 + 6) | 1;
  _sofree(param_1);
  return iVar2;
}
/* GHIDRADEC_FUNCTION index=398 start=0x4012bc8 */

void _soabort(int param_1)

{
  (**(code **)(*(int *)(param_1 + 0xc) + 0x1a))(param_1,10,0,0,0);
  return;
}
/* GHIDRADEC_FUNCTION index=399 start=0x4012bea */

void _soaccept(int param_1,undefined4 param_2)

{
  if ((*(byte *)(param_1 + 7) & 1) == 0) {
                    /* WARNING: Subroutine does not return */
    _panic(aSoacceptNofdre);
  }
  *(word *)(param_1 + 6) = *(word *)(param_1 + 6) & 0xfffe;
  (**(code **)(*(int *)(param_1 + 0xc) + 0x1a))(param_1,5,0,param_2,0);
  return;
}

