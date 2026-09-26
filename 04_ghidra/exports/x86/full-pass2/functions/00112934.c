/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00112934 */

int _ptyioctl(ushort param_1,uint param_2,uint *param_3,undefined4 param_4)

{
  int iVar1;
  uint *puVar2;
  bool bVar3;
  int iVar4;
  undefined4 uVar5;
  undefined4 local_14;
  int local_c;
  byte local_8;
  
  local_8 = (byte)param_1;
  iVar1 = *(int *)(&DAT_001e56d0 + (uint)local_8 * 0x10);
  puVar2 = *(uint **)(&DAT_001e56d4 + (uint)local_8 * 0x10);
  if (param_2 == 0x80047461) {
    if (*param_3 != 0) {
      if ((*puVar2 & 8) != 0) {
        *(byte *)(puVar2 + 3) = (byte)puVar2[3] | 0x40;
        _ptcwakeup(iVar1);
      }
      *(uint *)(iVar1 + 0x40) = *(uint *)(iVar1 + 0x40) | 0x400000;
      return 0;
    }
    if (((*(byte *)(iVar1 + 0x42) & 0x40) != 0) && ((*puVar2 & 8) != 0)) {
      *(byte *)(puVar2 + 3) = (byte)puVar2[3] | 0x40;
      _ptcwakeup(iVar1);
    }
    *(uint *)(iVar1 + 0x40) = *(uint *)(iVar1 + 0x40) & 0xffbfffff;
    return 0;
  }
  if ((code *)(&_cdevsw)[(short)(param_1 >> 8) * 0xb] == _ptcopen) {
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
LAB_00112ae8:
        do {
          iVar4 = _getc((FILE *)(iVar1 + 0x18));
        } while (-1 < iVar4);
      }
      else if ((int)param_2 < -0x7ffb8bfe) {
        if (param_2 == 0x8004667e) {
          if (*param_3 != 0) {
            *(byte *)puVar2 = (byte)*puVar2 | 4;
            return 0;
          }
          *puVar2 = *puVar2 & 0xfffffffb;
          return 0;
        }
      }
      else {
        if (param_2 == 0x80047466) {
          if (*param_3 == 0) {
            *puVar2 = *puVar2 & 0xffffff7f;
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
            *(byte *)puVar2 = (byte)*puVar2 | 0x20;
          }
          _ttyflush(iVar1,3);
          return 0;
        }
      }
    }
    else if ((int)param_2 < -0x7fdb8be9) {
      if ((-0x7fdb8bed < (int)param_2) ||
         (((int)param_2 < -0x7ff98bf5 && (-0x7ff98bf8 < (int)param_2)))) goto LAB_00112ae8;
    }
    else if (param_2 == 0x2000745f) {
      if (0x1f < *param_3) {
        return 0x16;
      }
      if (-1 < *(int *)(iVar1 + 0x3c)) {
        _ttyflush(iVar1,3);
      }
      _gsignal((int)*(short *)(iVar1 + 0x44),*param_3);
      return 0;
    }
  }
  iVar4 = (*(code *)(&PTR__nullioctl_001daff8)[*(char *)(iVar1 + 0x47) * 0xc])
                    (iVar1,param_2,param_3,param_4);
  if (-1 < iVar4) {
    return iVar4;
  }
  local_c = _ttioctl(iVar1,param_2,param_3,param_4);
  if (*(int *)(&DAT_001db014 + *(char *)(iVar1 + 0x47) * 0x30) != 0) {
    (*(code *)(&PTR__ttylclose_001dafec)[*(char *)(iVar1 + 0x47) * 0xc])(iVar1);
    *(undefined1 *)(iVar1 + 0x47) = 0;
    (*_linesw)((int)(short)param_1,iVar1);
    local_c = 0x19;
  }
  if (local_c < 0) {
    if (((char)(byte)*puVar2 < '\0') && ((param_2 & 0xffffff00) == 0x20007500)) {
      if ((byte)param_2 != 0) {
        *(byte *)((int)puVar2 + 0xd) = (byte)param_2;
        puVar2 = *(uint **)(&DAT_001e56d4 + (uint)(byte)*(short *)(iVar1 + 0x38) * 0x10);
        if (*(short *)(iVar1 + 0x38) != 0) {
          uVar5 = _spltty();
          if (puVar2[1] != 0) {
            _selwakeup(puVar2[1],*puVar2 & 1);
            _selthreadclear(puVar2 + 1);
            *puVar2 = *puVar2 & 0xfffffffe;
          }
          _splx(uVar5);
          _wakeup(iVar1 + 0x1c);
        }
      }
      return 0;
    }
    local_c = 0x19;
  }
  if (((*(byte *)(iVar1 + 0x42) & 0x40) != 0) && ((*puVar2 & 8) != 0)) {
    if ((int)param_2 < -0x7ff98bf5) {
      if (((int)param_2 < -0x7ff98bf7) &&
         ((-0x7ffb8b81 < (int)param_2 || ((int)param_2 < -0x7ffb8b83)))) goto LAB_00112ca4;
    }
    else if (param_2 != 0x80067475) {
      if ((int)param_2 < -0x7ff98b8a) {
        if (param_2 != 0x80067411) goto LAB_00112ca4;
      }
      else if ((-0x7fdb8bea < (int)param_2) || ((int)param_2 < -0x7fdb8bec)) goto LAB_00112ca4;
    }
    *(byte *)(puVar2 + 3) = (byte)puVar2[3] | 0x40;
  }
LAB_00112ca4:
  bVar3 = false;
  if ((((*(byte *)(iVar1 + 0x3c) & 0x20) == 0) &&
      (iVar4 = _ttynty(iVar1), (*(byte *)(iVar4 + 0x13) & 4) != 0)) &&
     ((*(uint *)(iVar1 + 0x50) & 0xffff00) == 0x131100)) {
    bVar3 = true;
  }
  if ((*puVar2 & 0x40) == 0) {
    if (bVar3) {
      return local_c;
    }
    *(byte *)(puVar2 + 3) = (byte)puVar2[3] & 0xdf | 0x10;
    *(byte *)puVar2 = (byte)*puVar2 | 0x40;
    puVar2 = *(uint **)(&DAT_001e56d4 + (uint)(byte)*(short *)(iVar1 + 0x38) * 0x10);
    if (*(short *)(iVar1 + 0x38) == 0) {
      return local_c;
    }
    local_14 = _spltty();
    if (puVar2[1] != 0) {
      _selwakeup(puVar2[1],*puVar2 & 1);
      _selthreadclear(puVar2 + 1);
      *puVar2 = *puVar2 & 0xfffffffe;
    }
  }
  else {
    if (!bVar3) {
      return local_c;
    }
    *(byte *)(puVar2 + 3) = (byte)puVar2[3] & 0xef | 0x20;
    *puVar2 = *puVar2 & 0xffffffbf;
    puVar2 = *(uint **)(&DAT_001e56d4 + (uint)(byte)*(short *)(iVar1 + 0x38) * 0x10);
    if (*(short *)(iVar1 + 0x38) == 0) {
      return local_c;
    }
    local_14 = _spltty();
    if (puVar2[1] != 0) {
      _selwakeup(puVar2[1],*puVar2 & 1);
      _selthreadclear(puVar2 + 1);
      *puVar2 = *puVar2 & 0xfffffffe;
    }
  }
  _splx(local_14);
  _wakeup(iVar1 + 0x1c);
  return local_c;
}

