/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00129d8c */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int _tcp_output(int param_1)

{
  byte bVar1;
  int iVar2;
  uint uVar3;
  int *piVar4;
  int *piVar5;
  ushort uVar6;
  undefined2 uVar7;
  undefined4 uVar8;
  uint uVar9;
  int iVar10;
  int iVar11;
  void *pvVar12;
  uint uVar13;
  uint uVar14;
  bool bVar15;
  short local_30;
  int local_20;
  size_t local_1c;
  int *local_18;
  uint local_c;
  
  iVar2 = *(int *)(*(int *)(param_1 + 0x20) + 0x1c);
  bVar15 = *(int *)(param_1 + 0x50) == *(int *)(param_1 + 0x24);
  if ((bVar15) && (*(short *)(param_1 + 0x14) <= *(short *)(param_1 + 0x58))) {
    *(undefined2 *)(param_1 + 0x54) = *(undefined2 *)(param_1 + 0x18);
  }
  while( true ) {
    iVar11 = *(int *)(param_1 + 0x28) - *(int *)(param_1 + 0x24);
    uVar6 = *(ushort *)(param_1 + 0x3c);
    if (*(ushort *)(param_1 + 0x54) < *(ushort *)(param_1 + 0x3c)) {
      uVar6 = *(ushort *)(param_1 + 0x54);
    }
    local_c = (uint)uVar6;
    if (*(char *)(param_1 + 0x1a) != '\0') {
      if (local_c == 0) {
        local_c = 1;
      }
      else {
        *(undefined2 *)(param_1 + 0xc) = 0;
        *(undefined2 *)(param_1 + 0x12) = 0;
      }
    }
    bVar1 = (&_tcp_outflags)[*(short *)(param_1 + 8)];
    uVar13 = (uint)*(ushort *)(iVar2 + 0x3c);
    if (local_c < *(ushort *)(iVar2 + 0x3c)) {
      uVar13 = local_c;
    }
    uVar13 = uVar13 - iVar11;
    if (((int)uVar13 < 0) && (uVar13 = 0, local_c == 0)) {
      *(undefined2 *)(param_1 + 10) = 0;
      *(undefined4 *)(param_1 + 0x28) = *(undefined4 *)(param_1 + 0x24);
    }
    uVar9 = (uint)*(ushort *)(param_1 + 0x18);
    uVar14 = uVar13;
    if ((int)uVar9 < (int)uVar13) {
      uVar14 = uVar9;
    }
    if ((int)((*(int *)(param_1 + 0x28) + uVar14) -
             ((uint)*(ushort *)(iVar2 + 0x3c) + *(int *)(param_1 + 0x24))) < 0) {
      bVar1 = bVar1 & 0xfe;
    }
    iVar10 = (uint)*(ushort *)(iVar2 + 0x2a) - (uint)*(ushort *)(iVar2 + 0x28);
    local_c = (uint)*(ushort *)(iVar2 + 0x26) - (uint)*(ushort *)(iVar2 + 0x24);
    if (iVar10 < (int)local_c) {
      local_c = iVar10;
    }
    if ((((uVar14 == 0) ||
         ((uVar9 != uVar14 &&
          (((((!bVar15 && ((*(byte *)(param_1 + 0x1b) & 4) == 0)) ||
             ((int)(iVar11 + uVar14) < (int)(uint)*(ushort *)(iVar2 + 0x3c))) &&
            ((*(char *)(param_1 + 0x1a) == '\0' &&
             ((int)uVar14 < (int)(uint)(*(ushort *)(param_1 + 0x66) >> 1))))) &&
           (-1 < *(int *)(param_1 + 0x28) - *(int *)(param_1 + 0x50))))))) &&
        (((int)local_c < 1 ||
         ((iVar10 = local_c - (*(int *)(param_1 + 0x4c) - *(int *)(param_1 + 0x40)),
          iVar10 < (int)((uint)*(ushort *)(param_1 + 0x18) * 2) &&
          (iVar10 * 2 < (int)(uint)*(ushort *)(iVar2 + 0x26))))))) &&
       ((((*(byte *)(param_1 + 0x1b) & 1) == 0 &&
         (((bVar1 & 6) == 0 &&
          (iVar10 = *(int *)(param_1 + 0x24),
          *(int *)(param_1 + 0x2c) == iVar10 || *(int *)(param_1 + 0x2c) - iVar10 < 0)))) &&
        (((bVar1 & 1) == 0 ||
         (((*(byte *)(param_1 + 0x1b) & 0x10) != 0 && (*(int *)(param_1 + 0x28) != iVar10)))))))) {
      if ((*(short *)(iVar2 + 0x3c) != 0) &&
         ((*(short *)(param_1 + 10) == 0 && (*(short *)(param_1 + 0xc) == 0)))) {
        *(undefined2 *)(param_1 + 0x12) = 0;
        _tcp_setpersist(param_1);
      }
      return 0;
    }
    local_1c = 0;
    local_20 = 0x28;
    if (((bVar1 & 2) != 0) && ((*(byte *)(param_1 + 0x1b) & 8) == 0)) {
      local_1c = 4;
      local_20 = 0x2c;
      uVar6 = _tcp_mss(param_1,0);
      _DAT_001dbe67 = uVar6 >> 8 | uVar6 << 8;
    }
    uVar8 = _splimp();
    piVar4 = _mfree;
    local_18 = _mfree;
    if (_mfree == (int *)0x0) {
      local_18 = (int *)_m_more(0,2);
    }
    else {
      if (*(short *)((int)_mfree + 10) != 0) {
                    /* WARNING: Subroutine does not return */
        _panic(&DAT_001dbe69);
      }
      *(undefined2 *)((int)_mfree + 10) = 2;
      _DAT_001e917c = _DAT_001e917c + -1;
      _DAT_001e9180 = _DAT_001e9180 + 1;
      piVar5 = (int *)*_mfree;
      *_mfree = 0;
      _mfree = piVar5;
      piVar4[1] = 0xc;
    }
    _splx(uVar8);
    if (local_18 == (int *)0x0) {
      return 0x37;
    }
    local_18[1] = 0x54 - local_1c;
    *(undefined2 *)(local_18 + 2) = (undefined2)local_20;
    if (uVar14 == 0) {
      if ((*(byte *)(param_1 + 0x1b) & 1) == 0) {
        if ((bVar1 & 7) == 0) {
          if (*(int *)(param_1 + 0x2c) == *(int *)(param_1 + 0x24) ||
              *(int *)(param_1 + 0x2c) - *(int *)(param_1 + 0x24) < 0) {
            _DAT_001eedcc = _DAT_001eedcc + 1;
          }
          else {
            _DAT_001eedc8 = _DAT_001eedc8 + 1;
          }
        }
        else {
          _DAT_001eedd0 = _DAT_001eedd0 + 1;
        }
      }
      else {
        _DAT_001eedc0 = _DAT_001eedc0 + 1;
      }
    }
    else {
      if ((*(char *)(param_1 + 0x1a) == '\0') || (uVar14 != 1)) {
        if (*(int *)(param_1 + 0x28) - *(int *)(param_1 + 0x50) < 0) {
          _DAT_001eedb8 = _DAT_001eedb8 + 1;
          _DAT_001eedbc = _DAT_001eedbc + uVar14;
        }
        else {
          _DAT_001eedb0 = _DAT_001eedb0 + 1;
          _DAT_001eedb4 = _DAT_001eedb4 + uVar14;
        }
      }
      else {
        _DAT_001eedc4 = _DAT_001eedc4 + 1;
      }
      iVar10 = _m_copy(*(undefined4 *)(iVar2 + 0x48),iVar11,uVar14);
      *local_18 = iVar10;
      if (iVar10 == 0) {
        uVar14 = 0;
      }
      else if (iVar11 + uVar14 == (uint)*(ushort *)(iVar2 + 0x3c)) {
        bVar1 = bVar1 | 8;
      }
    }
    pvVar12 = (void *)((int)local_18 + local_18[1]);
    if (*(int *)(param_1 + 0x1c) == 0) {
                    /* WARNING: Subroutine does not return */
      _panic(s_tcp_output_001dbe6e);
    }
    _bcopy(*(void **)(param_1 + 0x1c),pvVar12,0x28);
    if ((((bVar1 & 1) != 0) && ((*(byte *)(param_1 + 0x1b) & 0x10) != 0)) &&
       (*(int *)(param_1 + 0x50) == *(int *)(param_1 + 0x28))) {
      *(int *)(param_1 + 0x28) = *(int *)(param_1 + 0x28) + -1;
    }
    uVar3 = *(uint *)(param_1 + 0x28);
    *(uint *)((int)pvVar12 + 0x18) =
         uVar3 >> 0x18 | (uVar3 & 0xff0000) >> 8 | (uVar3 & 0xff00) << 8 | uVar3 << 0x18;
    uVar3 = *(uint *)(param_1 + 0x40);
    *(uint *)((int)pvVar12 + 0x1c) =
         uVar3 >> 0x18 | (uVar3 & 0xff0000) >> 8 | (uVar3 & 0xff00) << 8 | uVar3 << 0x18;
    if (local_1c != 0) {
      _bcopy(&_tcp_initopt,(void *)((int)pvVar12 + 0x28),local_1c);
      *(byte *)((int)pvVar12 + 0x20) =
           *(byte *)((int)pvVar12 + 0x20) & 0xf | (char)(local_1c + 0x14 >> 2) << 4;
    }
    *(byte *)((int)pvVar12 + 0x21) = bVar1;
    if (((int)local_c < (int)(uint)(*(ushort *)(iVar2 + 0x26) >> 2)) &&
       ((int)local_c < (int)(uint)*(ushort *)(param_1 + 0x18))) {
      local_c = 0;
    }
    if (0xffff < (int)local_c) {
      local_c = 0xffff;
    }
    iVar11 = *(int *)(param_1 + 0x4c) - *(int *)(param_1 + 0x40);
    if ((int)local_c < iVar11) {
      local_c = iVar11;
    }
    *(ushort *)((int)pvVar12 + 0x22) = (ushort)local_c >> 8 | (ushort)local_c << 8;
    iVar11 = *(int *)(param_1 + 0x2c);
    iVar10 = *(int *)(param_1 + 0x28);
    if (iVar11 == iVar10 || iVar11 - iVar10 < 0) {
      *(undefined4 *)(param_1 + 0x2c) = *(undefined4 *)(param_1 + 0x24);
    }
    else {
      local_30 = (short)iVar11;
      uVar6 = local_30 - (short)iVar10;
      *(ushort *)((int)pvVar12 + 0x26) = uVar6 >> 8 | uVar6 * 0x100;
      *(byte *)((int)pvVar12 + 0x21) = *(byte *)((int)pvVar12 + 0x21) | 0x20;
    }
    if (local_1c + uVar14 != 0) {
      uVar6 = (short)local_1c + 0x14 + (short)uVar14;
      *(ushort *)((int)pvVar12 + 10) = uVar6 >> 8 | uVar6 * 0x100;
    }
    uVar7 = _in_cksum(local_18,local_20 + uVar14);
    *(undefined2 *)((int)pvVar12 + 0x24) = uVar7;
    if ((*(char *)(param_1 + 0x1a) == '\0') || (*(short *)(param_1 + 0xc) == 0)) {
      iVar11 = *(int *)(param_1 + 0x28);
      if ((bVar1 & 3) != 0) {
        if ((bVar1 & 2) != 0) {
          *(int *)(param_1 + 0x28) = iVar11 + 1;
        }
        if ((bVar1 & 1) != 0) {
          *(int *)(param_1 + 0x28) = *(int *)(param_1 + 0x28) + 1;
          *(byte *)(param_1 + 0x1b) = *(byte *)(param_1 + 0x1b) | 0x10;
        }
      }
      iVar10 = *(int *)(param_1 + 0x28) + uVar14;
      *(int *)(param_1 + 0x28) = iVar10;
      if ((iVar10 != *(int *)(param_1 + 0x50) && -1 < iVar10 - *(int *)(param_1 + 0x50)) &&
         (*(int *)(param_1 + 0x50) = iVar10, *(short *)(param_1 + 0x5a) == 0)) {
        *(undefined2 *)(param_1 + 0x5a) = 1;
        *(int *)(param_1 + 0x5c) = iVar11;
        _DAT_001eed88 = _DAT_001eed88 + 1;
      }
      if (((*(short *)(param_1 + 10) == 0) && (*(int *)(param_1 + 0x28) != *(int *)(param_1 + 0x24))
          ) && (*(undefined2 *)(param_1 + 10) = *(undefined2 *)(param_1 + 0x14),
               *(short *)(param_1 + 0xc) != 0)) {
        *(undefined2 *)(param_1 + 0xc) = 0;
        *(undefined2 *)(param_1 + 0x12) = 0;
      }
    }
    else {
      iVar11 = *(int *)(param_1 + 0x28) + uVar14;
      if (iVar11 != *(int *)(param_1 + 0x50) && -1 < iVar11 - *(int *)(param_1 + 0x50)) {
        *(int *)(param_1 + 0x50) = iVar11;
      }
    }
    if ((*(byte *)(iVar2 + 2) & 1) != 0) {
      _tcp_trace(1,(int)*(short *)(param_1 + 8),param_1,pvVar12,0);
    }
    *(short *)((int)pvVar12 + 2) = (short)local_1c + 0x28 + (short)uVar14;
    *(undefined1 *)((int)pvVar12 + 8) = 0x3c;
    iVar11 = _ip_output(local_18,*(undefined4 *)(*(int *)(param_1 + 0x20) + 0x38),
                        *(int *)(param_1 + 0x20) + 0x24,*(byte *)(iVar2 + 2) & 0x10,0);
    if (iVar11 != 0) break;
    _DAT_001eedac = _DAT_001eedac + 1;
    if ((0 < (int)local_c) &&
       (iVar11 = local_c + *(int *)(param_1 + 0x40), 0 < iVar11 - *(int *)(param_1 + 0x4c))) {
      *(int *)(param_1 + 0x4c) = iVar11;
    }
    *(byte *)(param_1 + 0x1b) = *(byte *)(param_1 + 0x1b) & 0xfc;
    if ((int)uVar9 >= (int)uVar13) {
      return 0;
    }
  }
  if (iVar11 == 0x37) {
    _tcp_quench(*(undefined4 *)(param_1 + 0x20));
    return 0;
  }
  if ((iVar11 != 0x41) && (iVar11 != 0x32)) {
    return iVar11;
  }
  if (2 < *(short *)(param_1 + 8)) {
    *(short *)(param_1 + 0x6a) = (short)iVar11;
    return 0;
  }
  return iVar11;
}

