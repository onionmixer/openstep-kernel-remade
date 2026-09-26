
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int _tcp_timers(int param_1,int param_2)

{
  sword sVar2;
  word wVar3;
  int iVar1;
  uint uVar4;
  
  if (param_2 == 1) {
    dword_40BBD58 = dword_40BBD58 + 1;
    _tcp_setpersist(param_1);
    *(undefined *)(param_1 + 0x1a) = 1;
    _tcp_output(param_1);
    *(undefined *)(param_1 + 0x1a) = 0;
    return param_1;
  }
  if (param_2 < 2) {
    if (param_2 != 0) {
      return param_1;
    }
    sVar2 = *(sword *)(param_1 + 0x12);
    *(sword *)(param_1 + 0x12) = sVar2 + 1;
    if ((sword)(sVar2 + 1) < 0xd) {
      dword_40BBD54 = dword_40BBD54 + 1;
      sVar2 = (sword)*(undefined4 *)(_tcp_backoff + *(sword *)(param_1 + 0x12) * 4) *
              (*(sword *)(param_1 + 0x62) + (*(sword *)(param_1 + 0x60) >> 3));
      *(sword *)(param_1 + 0x14) = sVar2;
      if ((int)sVar2 < (int)(uint)*(word *)(param_1 + 100)) {
        *(word *)(param_1 + 0x14) = *(word *)(param_1 + 100);
      }
      else if (0x80 < sVar2) {
        *(undefined2 *)(param_1 + 0x14) = 0x80;
      }
      *(undefined2 *)(param_1 + 10) = *(undefined2 *)(param_1 + 0x14);
      if (3 < *(sword *)(param_1 + 0x12)) {
        _in_losing(*(undefined4 *)(param_1 + 0x20));
        *(sword *)(param_1 + 0x62) = (*(sword *)(param_1 + 0x60) >> 2) + *(sword *)(param_1 + 0x62);
        *(undefined2 *)(param_1 + 0x60) = 0;
      }
      *(undefined4 *)(param_1 + 0x28) = *(undefined4 *)(param_1 + 0x24);
      *(undefined2 *)(param_1 + 0x5a) = 0;
      wVar3 = *(word *)(param_1 + 0x3c);
      if (*(word *)(param_1 + 0x54) < *(word *)(param_1 + 0x3c)) {
        wVar3 = *(word *)(param_1 + 0x54);
      }
      uVar4 = (uint)(wVar3 >> 1) / (uint)*(word *)(param_1 + 0x18);
      sVar2 = (sword)uVar4;
      if (uVar4 < 2) {
        sVar2 = 2;
      }
      *(word *)(param_1 + 0x54) = *(word *)(param_1 + 0x18);
      *(sword *)(param_1 + 0x56) = *(sword *)(param_1 + 0x18) * sVar2;
      *(undefined2 *)(param_1 + 0x16) = 0;
      _tcp_output(param_1);
      return param_1;
    }
    *(undefined2 *)(param_1 + 0x12) = 0xc;
    dword_40BBD50 = dword_40BBD50 + 1;
  }
  else {
    if (param_2 != 2) {
      if (param_2 != 3) {
        return param_1;
      }
      if ((*(sword *)(param_1 + 8) != 10) && (*(sword *)(param_1 + 0x58) <= __tcp_maxidle)) {
        *(undefined2 *)(param_1 + 0x10) = uRam040aeb82;
        return param_1;
      }
      iVar1 = _tcp_close(param_1);
      return iVar1;
    }
    dword_40BBD5C = dword_40BBD5C + 1;
    if (3 < *(sword *)(param_1 + 8)) {
      if (((*(byte *)(*(int *)(*(int *)(param_1 + 0x20) + 0x18) + 3) & 8) == 0) ||
         (5 < *(sword *)(param_1 + 8))) {
        *(undefined2 *)(param_1 + 0xe) = word_40AEB7E;
        return param_1;
      }
      if ((int)*(sword *)(param_1 + 0x58) < __tcp_maxidle + __tcp_keepidle) {
        dword_40BBD60 = dword_40BBD60 + 1;
        _tcp_respond(param_1,*(undefined4 *)(param_1 + 0x1c),0,*(undefined4 *)(param_1 + 0x40),
                     *(int *)(param_1 + 0x24) + -1,0);
        *(undefined2 *)(param_1 + 0xe) = uRam040aeb82;
        return param_1;
      }
    }
    dword_40BBD64 = dword_40BBD64 + 1;
  }
  iVar1 = _tcp_drop(param_1,0x3c);
  return iVar1;
}

