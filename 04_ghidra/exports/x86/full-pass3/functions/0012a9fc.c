/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0012a9fc */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int _tcp_timers(int param_1,int param_2)

{
  ulonglong uVar1;
  short sVar2;
  int iVar3;
  ushort uVar4;
  
  if (param_2 == 1) {
    _DAT_001eed9c = _DAT_001eed9c + 1;
    _tcp_setpersist(param_1);
    *(undefined1 *)(param_1 + 0x1a) = 1;
    _tcp_output(param_1);
    *(undefined1 *)(param_1 + 0x1a) = 0;
    return param_1;
  }
  if (param_2 < 2) {
    if (param_2 != 0) {
      return param_1;
    }
    sVar2 = *(short *)(param_1 + 0x12);
    *(short *)(param_1 + 0x12) = sVar2 + 1;
    if ((short)(sVar2 + 1) < 0xd) {
      _DAT_001eed98 = _DAT_001eed98 + 1;
      *(short *)(param_1 + 0x14) =
           ((*(short *)(param_1 + 0x60) >> 3) + *(short *)(param_1 + 0x62)) *
           *(short *)(&_tcp_backoff + *(short *)(param_1 + 0x12) * 4);
      if ((int)*(short *)(param_1 + 0x14) < (int)(uint)*(ushort *)(param_1 + 100)) {
        *(ushort *)(param_1 + 0x14) = *(ushort *)(param_1 + 100);
      }
      else if (0x80 < *(short *)(param_1 + 0x14)) {
        *(undefined2 *)(param_1 + 0x14) = 0x80;
      }
      *(undefined2 *)(param_1 + 10) = *(undefined2 *)(param_1 + 0x14);
      if (3 < *(short *)(param_1 + 0x12)) {
        _in_losing(*(undefined4 *)(param_1 + 0x20));
        *(short *)(param_1 + 0x62) = *(short *)(param_1 + 0x62) + (*(short *)(param_1 + 0x60) >> 2);
        *(undefined2 *)(param_1 + 0x60) = 0;
      }
      *(undefined4 *)(param_1 + 0x28) = *(undefined4 *)(param_1 + 0x24);
      *(undefined2 *)(param_1 + 0x5a) = 0;
      uVar4 = *(ushort *)(param_1 + 0x3c);
      if (*(ushort *)(param_1 + 0x54) < *(ushort *)(param_1 + 0x3c)) {
        uVar4 = *(ushort *)(param_1 + 0x54);
      }
      uVar1 = (ulonglong)(uVar4 >> 1) / (ulonglong)(longlong)(int)(uint)*(ushort *)(param_1 + 0x18);
      sVar2 = (short)uVar1;
      if ((uint)uVar1 < 2) {
        sVar2 = 2;
      }
      *(ushort *)(param_1 + 0x54) = *(ushort *)(param_1 + 0x18);
      *(short *)(param_1 + 0x56) = *(short *)(param_1 + 0x18) * sVar2;
      *(undefined2 *)(param_1 + 0x16) = 0;
      _tcp_output(param_1);
      return param_1;
    }
    *(undefined2 *)(param_1 + 0x12) = 0xc;
    _DAT_001eed94 = _DAT_001eed94 + 1;
  }
  else {
    if (param_2 != 2) {
      if (param_2 != 3) {
        return param_1;
      }
      if ((*(short *)(param_1 + 8) != 10) && (*(short *)(param_1 + 0x58) <= __tcp_maxidle)) {
        *(undefined2 *)(param_1 + 0x10) = _tcp_keepintvl;
        return param_1;
      }
      iVar3 = _tcp_close(param_1);
      return iVar3;
    }
    _DAT_001eeda0 = _DAT_001eeda0 + 1;
    if (3 < *(short *)(param_1 + 8)) {
      if (((*(byte *)(*(int *)(*(int *)(param_1 + 0x20) + 0x1c) + 2) & 8) == 0) ||
         (5 < *(short *)(param_1 + 8))) {
        *(undefined2 *)(param_1 + 0xe) = _tcp_keepidle;
        return param_1;
      }
      if ((int)*(short *)(param_1 + 0x58) < __tcp_keepidle + __tcp_maxidle) {
        _DAT_001eeda4 = _DAT_001eeda4 + 1;
        _tcp_respond(param_1,*(undefined4 *)(param_1 + 0x1c),0,*(undefined4 *)(param_1 + 0x40),
                     *(int *)(param_1 + 0x24) + -1,0);
        *(undefined2 *)(param_1 + 0xe) = _tcp_keepintvl;
        return param_1;
      }
    }
    _DAT_001eeda8 = _DAT_001eeda8 + 1;
  }
  iVar3 = _tcp_drop(param_1,0x3c);
  return iVar3;
}

