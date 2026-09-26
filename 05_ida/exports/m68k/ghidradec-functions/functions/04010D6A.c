
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
