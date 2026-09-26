/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0012873c */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void _tcp_input(int param_1)

{
  ushort uVar1;
  bool bVar2;
  bool bVar3;
  byte bVar4;
  short sVar5;
  undefined2 uVar6;
  undefined4 uVar7;
  undefined2 *puVar8;
  uint uVar9;
  byte bVar10;
  int iVar11;
  int iVar12;
  void *pvVar13;
  undefined1 *puVar14;
  byte *pbVar15;
  short sVar16;
  undefined4 *puVar17;
  int *local_34;
  uint local_30;
  short local_2c;
  int local_28;
  int local_24;
  short local_20;
  int local_18;
  int local_10;
  undefined *local_c;
  byte *local_8;
  
  local_10 = 0;
  local_34 = (int *)0x0;
  bVar3 = false;
  local_24 = 0;
  local_28 = 0;
  _DAT_001eedd4 = _DAT_001eedd4 + 1;
  local_8 = (byte *)(param_1 + *(int *)(param_1 + 4));
  if (5 < (*local_8 & 0xf)) {
    _ip_stripoptions(local_8);
  }
  if (*(ushort *)(param_1 + 8) < 0x28) {
    param_1 = _m_pullup(param_1);
    if (param_1 == 0) goto LAB_0012886d;
    local_8 = (byte *)(param_1 + *(int *)(param_1 + 4));
  }
  sVar16 = *(short *)(local_8 + 2);
  local_8[4] = 0;
  local_8[5] = 0;
  local_8[6] = 0;
  local_8[7] = 0;
  local_8[0] = 0;
  local_8[1] = 0;
  local_8[2] = 0;
  local_8[3] = 0;
  local_8[8] = 0;
  *(short *)(local_8 + 10) = sVar16;
  *(ushort *)(local_8 + 10) = *(ushort *)(local_8 + 10) >> 8 | *(ushort *)(local_8 + 10) << 8;
  sVar5 = _in_cksum(param_1);
  *(short *)(local_8 + 0x24) = sVar5;
  if (sVar5 != 0) {
    _DAT_001eede0 = _DAT_001eede0 + 1;
    goto LAB_00129a20;
  }
  uVar9 = (uint)(local_8[0x20] >> 4) * 4;
  if ((uVar9 < 0x14) || (uVar9 - (int)sVar16 != 0 && (int)sVar16 <= (int)uVar9)) {
    _DAT_001eede4 = _DAT_001eede4 + 1;
    goto LAB_00129a20;
  }
  *(short *)(local_8 + 10) = sVar16 - (short)uVar9;
  if (uVar9 < 0x15) {
LAB_001288ee:
    bVar4 = local_8[0x21];
    uVar9 = *(uint *)(local_8 + 0x18);
    *(uint *)(local_8 + 0x18) =
         uVar9 >> 0x18 | (uVar9 & 0xff0000) >> 8 | (uVar9 & 0xff00) << 8 | uVar9 << 0x18;
    uVar9 = *(uint *)(local_8 + 0x1c);
    *(uint *)(local_8 + 0x1c) =
         uVar9 >> 0x18 | (uVar9 & 0xff0000) >> 8 | (uVar9 & 0xff00) << 8 | uVar9 << 0x18;
    *(ushort *)(local_8 + 0x22) =
         *(ushort *)(local_8 + 0x22) >> 8 | *(ushort *)(local_8 + 0x22) << 8;
    *(ushort *)(local_8 + 0x26) =
         *(ushort *)(local_8 + 0x26) >> 8 | *(ushort *)(local_8 + 0x26) << 8;
    do {
      local_c = _tcp_last_inpcb;
      if ((((*(short *)(_tcp_last_inpcb + 0x18) != *(short *)(local_8 + 0x16)) ||
           (*(short *)(_tcp_last_inpcb + 0x10) != *(short *)(local_8 + 0x14))) ||
          (*(int *)(_tcp_last_inpcb + 0xc) != *(int *)(local_8 + 0xc))) ||
         (*(int *)(_tcp_last_inpcb + 0x14) != *(int *)(local_8 + 0x10))) {
        local_c = (undefined *)
                  _in_pcblookup(&_tcb,*(undefined4 *)(local_8 + 0xc),*(undefined2 *)(local_8 + 0x14)
                                ,*(undefined4 *)(local_8 + 0x10),*(undefined2 *)(local_8 + 0x16));
        if (local_c != (undefined *)0x0) {
          _tcp_last_inpcb = local_c;
        }
        __tcppcbcachemiss = __tcppcbcachemiss + 1;
      }
      if ((local_c == (undefined *)0x0) ||
         (local_34 = *(int **)(local_c + 0x20), local_34 == (int *)0x0)) goto LAB_00129984;
      iVar12 = local_34[2];
      if ((short)iVar12 == 0) goto LAB_00129a20;
      local_18 = *(int *)(local_c + 0x1c);
      if ((*(ushort *)(local_18 + 2) & 3) != 0) {
        if ((*(ushort *)(local_18 + 2) & 1) != 0) {
          pbVar15 = local_8;
          puVar17 = &_tcp_saveti;
          for (iVar11 = 10; local_20 = (short)iVar12, iVar11 != 0; iVar11 = iVar11 + -1) {
            *puVar17 = *(undefined4 *)pbVar15;
            pbVar15 = pbVar15 + 4;
            puVar17 = puVar17 + 1;
          }
        }
        if ((*(byte *)(local_18 + 2) & 2) != 0) {
          local_18 = _sonewconn(local_18);
          if (local_18 == 0) goto LAB_00129a20;
          local_24 = local_24 + 1;
          local_c = *(undefined **)(local_18 + 8);
          *(undefined4 *)(local_c + 0x14) = *(undefined4 *)(local_8 + 0x10);
          *(undefined2 *)(local_c + 0x18) = *(undefined2 *)(local_8 + 0x16);
          uVar7 = _ip_srcroute();
          *(undefined4 *)(local_c + 0x38) = uVar7;
          local_34 = *(int **)(local_c + 0x20);
          *(undefined2 *)(local_34 + 2) = 1;
        }
      }
      *(undefined2 *)(local_34 + 0x16) = 0;
      *(undefined2 *)((int)local_34 + 0xe) = _tcp_keepidle;
      if ((local_10 != 0) && ((short)local_34[2] != 1)) {
        _tcp_dooptions(local_34,local_10);
        local_10 = 0;
      }
      if (((((short)local_34[2] == 4) && ((bVar4 & 0x37) == 0x10)) &&
          (*(int *)(local_8 + 0x18) == local_34[0x10])) &&
         (((uVar1 = *(ushort *)(local_8 + 0x22), uVar1 != 0 &&
           (*(ushort *)(local_34 + 0xf) == uVar1)) &&
          (iVar12 = local_34[10], local_34[0x14] == iVar12)))) {
        if (*(short *)(local_8 + 10) == 0) {
          iVar11 = *(int *)(local_8 + 0x1c);
          if (((iVar11 != local_34[9] && -1 < iVar11 - local_34[9]) &&
              (iVar11 == iVar12 || iVar11 - iVar12 < 0)) && (uVar1 <= *(ushort *)(local_34 + 0x15)))
          {
            __tcppredack = __tcppredack + 1;
            if ((*(short *)((int)local_34 + 0x5a) != 0) &&
               (*(int *)(local_8 + 0x1c) != local_34[0x17] &&
                -1 < *(int *)(local_8 + 0x1c) - local_34[0x17])) {
              _tcp_xmit_timer();
            }
            _DAT_001eee1c = _DAT_001eee1c + 1;
            _DAT_001eee20 = _DAT_001eee20 + (*(int *)(local_8 + 0x1c) - local_34[9]);
            _sbdrop(local_18 + 0x3c);
            local_34[9] = *(int *)(local_8 + 0x1c);
            _m_freem(param_1);
            if (local_34[9] == local_34[0x14]) {
              *(undefined2 *)((int)local_34 + 10) = 0;
            }
            else if ((short)local_34[3] == 0) {
              *(short *)((int)local_34 + 10) = (short)local_34[5];
            }
            if (((*(byte *)(local_18 + 0x50) & 4) != 0) || (*(int *)(local_18 + 0x4c) != 0)) {
              _sowakeup(local_18);
            }
            if (*(short *)(local_18 + 0x3c) == 0) {
              return;
            }
            _tcp_output();
            return;
          }
        }
        else if ((*(int *)(local_8 + 0x1c) == local_34[9]) && ((int *)*local_34 == local_34)) {
          iVar11 = (uint)*(ushort *)(local_18 + 0x2a) - (uint)*(ushort *)(local_18 + 0x28);
          iVar12 = (uint)*(ushort *)(local_18 + 0x26) - (uint)*(ushort *)(local_18 + 0x24);
          if (iVar11 < iVar12) {
            iVar12 = iVar11;
          }
          if (*(short *)(local_8 + 10) <= iVar12) {
            __tcppreddat = __tcppreddat + 1;
            local_34[0x10] = local_34[0x10] + (int)*(short *)(local_8 + 10);
            _DAT_001eedd8 = _DAT_001eedd8 + 1;
            _DAT_001eeddc = _DAT_001eeddc + *(short *)(local_8 + 10);
            *(int *)(param_1 + 4) = *(int *)(param_1 + 4) + 0x28;
            *(short *)(param_1 + 8) = *(short *)(param_1 + 8) + -0x28;
            _sbappend(local_18 + 0x24);
            _sowakeup(local_18,local_18 + 0x24);
            *(byte *)((int)local_34 + 0x1b) = *(byte *)((int)local_34 + 0x1b) | 2;
            return;
          }
        }
      }
      *(int *)(param_1 + 4) = *(int *)(param_1 + 4) + 0x28;
      *(short *)(param_1 + 8) = *(short *)(param_1 + 8) + -0x28;
      iVar12 = (uint)*(ushort *)(local_18 + 0x2a) - (uint)*(ushort *)(local_18 + 0x28);
      local_30 = (uint)*(ushort *)(local_18 + 0x26) - (uint)*(ushort *)(local_18 + 0x24);
      if (iVar12 < (int)local_30) {
        local_30 = iVar12;
      }
      if ((int)local_30 < 0) {
        local_30 = 0;
      }
      if ((int)local_30 <= local_34[0x13] - local_34[0x10]) {
        local_30._0_2_ = (short)local_34[0x13] - (short)local_34[0x10];
      }
      *(short *)((int)local_34 + 0x3e) = (short)local_30;
      sVar16 = (short)local_34[2];
      if (sVar16 == 1) {
        if ((bVar4 & 4) != 0) goto LAB_00129a20;
        if ((bVar4 & 0x10) != 0) goto LAB_00129984;
        if ((((bVar4 & 2) == 0) || (iVar12 = _in_broadcast(), iVar12 != 0)) ||
           (iVar12 = _m_get(0), iVar12 == 0)) goto LAB_00129a20;
        *(undefined2 *)(iVar12 + 8) = 0x10;
        puVar8 = (undefined2 *)(iVar12 + *(int *)(iVar12 + 4));
        *puVar8 = 2;
        *(undefined4 *)(puVar8 + 2) = *(undefined4 *)(local_8 + 0xc);
        puVar8[1] = *(undefined2 *)(local_8 + 0x14);
        iVar12 = *(int *)(local_c + 0x14);
        if (iVar12 == 0) {
          *(undefined4 *)(local_c + 0x14) = *(undefined4 *)(local_8 + 0x10);
        }
        iVar11 = _in_pcbconnect(local_c);
        if (iVar11 != 0) {
          *(int *)(local_c + 0x14) = iVar12;
          _m_free();
          goto LAB_00129a20;
        }
        _m_free();
        iVar12 = _tcp_template(local_34);
        local_34[7] = iVar12;
        if (iVar12 == 0) {
          local_34 = (int *)_tcp_drop(local_34);
          local_24 = 0;
          goto LAB_00129a20;
        }
        if (local_10 != 0) {
          _tcp_dooptions(local_34,local_10);
        }
        if (local_28 == 0) {
          local_34[0xe] = _tcp_iss;
        }
        else {
          local_34[0xe] = local_28;
        }
        _tcp_iss = _tcp_iss + 64000;
        local_34[0x12] = *(int *)(local_8 + 0x18);
        iVar12 = local_34[0xe];
        local_34[0xb] = iVar12;
        local_34[0x14] = iVar12;
        local_34[10] = iVar12;
        local_34[9] = iVar12;
        local_34[0x10] = local_34[0x12] + 1;
        local_34[0x13] = local_34[0x12] + 1;
        *(byte *)((int)local_34 + 0x1b) = *(byte *)((int)local_34 + 0x1b) | 1;
        *(undefined2 *)(local_34 + 2) = 3;
        *(undefined2 *)((int)local_34 + 0xe) = 0x96;
        _DAT_001eed74 = _DAT_001eed74 + 1;
LAB_00128f71:
        *(int *)(local_8 + 0x18) = *(int *)(local_8 + 0x18) + 1;
        sVar16 = *(short *)(local_8 + 10);
        uVar1 = *(ushort *)((int)local_34 + 0x3e);
        if ((int)(uint)uVar1 < (int)sVar16) {
          _m_adj(param_1);
          *(undefined2 *)(local_8 + 10) = *(undefined2 *)((int)local_34 + 0x3e);
          bVar4 = bVar4 & 0xfe;
          _DAT_001eee04 = _DAT_001eee04 + 1;
          _DAT_001eee08 = _DAT_001eee08 + ((int)sVar16 - (uint)uVar1);
        }
        local_34[0xc] = *(int *)(local_8 + 0x18) + -1;
        local_34[0x11] = *(int *)(local_8 + 0x18);
        goto LAB_00129640;
      }
      if ((0 < sVar16) && (sVar16 < 4)) {
        bVar10 = bVar4 & 0x10;
        if ((bVar10 != 0) &&
           ((iVar12 = *(int *)(local_8 + 0x1c),
            iVar12 == local_34[0xe] || iVar12 - local_34[0xe] < 0 || (0 < iVar12 - local_34[0x14])))
           ) goto LAB_00129984;
        if ((bVar4 & 4) != 0) {
          if (bVar10 != 0) {
            local_34 = (int *)_tcp_drop(local_34);
          }
          goto LAB_00129a20;
        }
        if ((short)local_34[2] != 3) {
          if ((bVar4 & 2) != 0) {
            if (bVar10 != 0) {
              local_34[9] = *(int *)(local_8 + 0x1c);
              if (local_34[10] - local_34[9] < 0) {
                local_34[10] = local_34[9];
              }
            }
            *(undefined2 *)((int)local_34 + 10) = 0;
            local_34[0x12] = *(int *)(local_8 + 0x18);
            local_34[0x10] = local_34[0x12] + 1;
            local_34[0x13] = local_34[0x12] + 1;
            *(byte *)((int)local_34 + 0x1b) = *(byte *)((int)local_34 + 0x1b) | 1;
            if (((bVar4 & 0x10) == 0) ||
               (local_34[9] == local_34[0xe] || local_34[9] - local_34[0xe] < 0)) {
              *(undefined2 *)(local_34 + 2) = 3;
            }
            else {
              _DAT_001eed78 = _DAT_001eed78 + 1;
              _soisconnected();
              *(undefined2 *)(local_34 + 2) = 4;
              _tcp_reass(local_34,0,0);
              if (*(short *)((int)local_34 + 0x5a) != 0) {
                _tcp_xmit_timer();
              }
            }
            goto LAB_00128f71;
          }
          goto LAB_00129a20;
        }
      }
      iVar12 = local_34[0x10] - *(int *)(local_8 + 0x18);
      if (0 < iVar12) {
        if ((bVar4 & 2) != 0) {
          *(int *)(local_8 + 0x18) = *(int *)(local_8 + 0x18) + 1;
          if (*(ushort *)(local_8 + 0x26) < 2) {
            bVar4 = bVar4 & 0xdd;
          }
          else {
            *(ushort *)(local_8 + 0x26) = *(ushort *)(local_8 + 0x26) - 1;
            bVar4 = bVar4 & 0xfd;
          }
          iVar12 = iVar12 + -1;
        }
        if ((*(short *)(local_8 + 10) < iVar12) ||
           ((iVar12 == *(short *)(local_8 + 10) && ((bVar4 & 1) == 0)))) {
          _DAT_001eedec = _DAT_001eedec + 1;
          _DAT_001eedf0 = _DAT_001eedf0 + *(short *)(local_8 + 10);
          if (((bVar4 & 1) == 0) || (sVar16 = *(short *)(local_8 + 10), iVar12 != sVar16 + 1))
          goto LAB_0012995c;
          bVar4 = bVar4 & 0xfe;
          *(byte *)((int)local_34 + 0x1b) = *(byte *)((int)local_34 + 0x1b) | 1;
          iVar12 = (int)sVar16;
        }
        else {
          _DAT_001eedf4 = _DAT_001eedf4 + 1;
          _DAT_001eedf8 = _DAT_001eedf8 + iVar12;
        }
        _m_adj(param_1);
        *(int *)(local_8 + 0x18) = *(int *)(local_8 + 0x18) + iVar12;
        *(short *)(local_8 + 10) = *(short *)(local_8 + 10) - (short)iVar12;
        if (iVar12 < (int)(uint)*(ushort *)(local_8 + 0x26)) {
          *(ushort *)(local_8 + 0x26) = *(ushort *)(local_8 + 0x26) - (short)iVar12;
        }
        else {
          bVar4 = bVar4 & 0xdf;
          local_8[0x26] = 0;
          local_8[0x27] = 0;
        }
      }
      if ((((*(byte *)(local_18 + 6) & 1) != 0) && (5 < (short)local_34[2])) &&
         (*(short *)(local_8 + 10) != 0)) {
        local_34 = (int *)_tcp_close();
        _DAT_001eee0c = _DAT_001eee0c + 1;
        goto LAB_00129984;
      }
      iVar12 = ((int)*(short *)(local_8 + 10) + *(int *)(local_8 + 0x18)) -
               ((uint)*(ushort *)((int)local_34 + 0x3e) + local_34[0x10]);
      if (iVar12 < 1) goto LAB_001291aa;
      _DAT_001eee04 = _DAT_001eee04 + 1;
      if (iVar12 < *(short *)(local_8 + 10)) {
        _DAT_001eee08 = _DAT_001eee08 + iVar12;
        goto LAB_0012918e;
      }
      _DAT_001eee08 = _DAT_001eee08 + *(short *)(local_8 + 10);
      if ((((bVar4 & 2) == 0) || ((short)local_34[2] != 10)) ||
         (local_28 = local_34[0x10],
         *(int *)(local_8 + 0x18) == local_28 || *(int *)(local_8 + 0x18) - local_28 < 0))
      goto LAB_0012915c;
      local_28 = local_28 + 0x1f400;
      local_34 = (int *)_tcp_close();
    } while( true );
  }
  if ((uint)(int)*(short *)(param_1 + 8) < uVar9 + 0x14) {
    param_1 = _m_pullup(param_1);
    if (param_1 == 0) {
LAB_0012886d:
      _DAT_001eede8 = _DAT_001eede8 + 1;
      return;
    }
    local_8 = (byte *)(param_1 + *(int *)(param_1 + 4));
  }
  local_10 = _m_get(0);
  if (local_10 != 0) {
    sVar16 = (short)uVar9 + -0x14;
    *(short *)(local_10 + 8) = sVar16;
    pvVar13 = (void *)(param_1 + *(int *)(param_1 + 4) + 0x28);
    _bcopy(pvVar13,(void *)(local_10 + *(int *)(local_10 + 4)),(int)sVar16);
    sVar16 = *(short *)(param_1 + 8) - *(short *)(local_10 + 8);
    *(short *)(param_1 + 8) = sVar16;
    _bcopy((void *)((int)pvVar13 + (int)*(short *)(local_10 + 8)),pvVar13,(int)sVar16 - 0x28);
    goto LAB_001288ee;
  }
LAB_00129a32:
  if ((local_34 != (int *)0x0) && ((*(byte *)(*(int *)(local_34[8] + 0x1c) + 2) & 1) != 0)) {
    _tcp_trace(4,(int)local_20,local_34,&_tcp_saveti);
  }
  _m_freem();
joined_r0x00129a15:
  if (local_24 != 0) {
    _soabort();
  }
  return;
LAB_0012915c:
  if ((*(short *)((int)local_34 + 0x3e) != 0) || (*(int *)(local_8 + 0x18) != local_34[0x10]))
  goto LAB_0012995c;
  *(byte *)((int)local_34 + 0x1b) = *(byte *)((int)local_34 + 0x1b) | 1;
  _DAT_001eee10 = _DAT_001eee10 + 1;
LAB_0012918e:
  _m_adj(param_1);
  *(short *)(local_8 + 10) = *(short *)(local_8 + 10) - (short)iVar12;
  bVar4 = bVar4 & 0xf6;
LAB_001291aa:
  if ((bVar4 & 4) == 0) {
switchD_001291c4_default:
    if ((bVar4 & 2) != 0) {
      local_34 = (int *)_tcp_drop(local_34);
LAB_00129984:
      if (local_10 != 0) {
        _m_free();
        local_10 = 0;
      }
      if (((bVar4 & 4) == 0) && (iVar12 = _in_broadcast(), iVar12 == 0)) {
        if ((bVar4 & 0x10) == 0) {
          if ((bVar4 & 2) != 0) {
            *(short *)(local_8 + 10) = *(short *)(local_8 + 10) + 1;
          }
          uVar7 = 0;
          iVar12 = (int)*(short *)(local_8 + 10) + *(int *)(local_8 + 0x18);
        }
        else {
          uVar7 = *(undefined4 *)(local_8 + 0x1c);
          iVar12 = 0;
        }
        _tcp_respond(local_34,local_8,param_1,iVar12,uVar7);
        goto joined_r0x00129a15;
      }
      goto LAB_00129a20;
    }
    if ((bVar4 & 0x10) == 0) goto LAB_00129a20;
    sVar16 = (short)local_34[2];
    if (sVar16 == 3) {
      iVar12 = *(int *)(local_8 + 0x1c);
      if ((local_34[9] != iVar12 && -1 < local_34[9] - iVar12) || (0 < iVar12 - local_34[0x14]))
      goto LAB_00129984;
      _DAT_001eed78 = _DAT_001eed78 + 1;
      _soisconnected();
      *(undefined2 *)(local_34 + 2) = 4;
      _tcp_reass(local_34,0,0);
      local_34[0xc] = *(int *)(local_8 + 0x18) + -1;
LAB_001292ca:
      if (*(int *)(local_8 + 0x1c) == local_34[9] || *(int *)(local_8 + 0x1c) - local_34[9] < 0) {
        if ((((*(short *)(local_8 + 10) == 0) &&
             (*(short *)(local_8 + 0x22) == (short)local_34[0xf])) &&
            (_DAT_001eee14 = _DAT_001eee14 + 1, *(short *)((int)local_34 + 10) != 0)) &&
           (*(int *)(local_8 + 0x1c) == local_34[9])) {
          sVar16 = *(short *)((int)local_34 + 0x16);
          *(short *)((int)local_34 + 0x16) = sVar16 + 1;
          iVar12 = (int)(short)(sVar16 + 1);
          if (iVar12 == _tcprexmtthresh) {
            iVar12 = local_34[10];
            uVar9 = _min((short)local_34[0xf]);
            uVar9 = (uVar9 >> 1) / (uint)*(ushort *)(local_34 + 6);
            if (uVar9 < 2) {
              uVar9 = 2;
            }
            *(ushort *)((int)local_34 + 0x56) = *(ushort *)(local_34 + 6) * (short)uVar9;
            *(undefined2 *)((int)local_34 + 10) = 0;
            *(undefined2 *)((int)local_34 + 0x5a) = 0;
            local_34[10] = *(int *)(local_8 + 0x1c);
            *(short *)(local_34 + 0x15) = (short)local_34[6];
            _tcp_output();
            local_2c = (short)local_34[6] * *(short *)((int)local_34 + 0x16);
            *(short *)(local_34 + 0x15) = local_2c + *(short *)((int)local_34 + 0x56);
            if (iVar12 != local_34[10] && -1 < iVar12 - local_34[10]) {
              local_34[10] = iVar12;
            }
          }
          else {
            if (iVar12 <= _tcprexmtthresh) goto LAB_00129640;
            *(short *)(local_34 + 0x15) = (short)local_34[0x15] + (short)local_34[6];
            _tcp_output();
          }
          goto LAB_00129a20;
        }
        *(undefined2 *)((int)local_34 + 0x16) = 0;
      }
      else {
        if ((_tcprexmtthresh < *(short *)((int)local_34 + 0x16)) &&
           (*(ushort *)((int)local_34 + 0x56) < *(ushort *)(local_34 + 0x15))) {
          *(ushort *)(local_34 + 0x15) = *(ushort *)((int)local_34 + 0x56);
        }
        *(undefined2 *)((int)local_34 + 0x16) = 0;
        iVar12 = *(int *)(local_8 + 0x1c);
        if (iVar12 != local_34[0x14] && -1 < iVar12 - local_34[0x14]) {
          _DAT_001eee18 = _DAT_001eee18 + 1;
LAB_0012995c:
          if ((bVar4 & 4) == 0) {
            _m_freem();
            *(byte *)((int)local_34 + 0x1b) = *(byte *)((int)local_34 + 0x1b) | 1;
            puVar14 = &stack0xffffff48;
            goto LAB_00129978;
          }
          goto LAB_00129a20;
        }
        iVar12 = iVar12 - local_34[9];
        _DAT_001eee1c = _DAT_001eee1c + 1;
        _DAT_001eee20 = _DAT_001eee20 + iVar12;
        if ((*(short *)((int)local_34 + 0x5a) != 0) &&
           (*(int *)(local_8 + 0x1c) != local_34[0x17] &&
            -1 < *(int *)(local_8 + 0x1c) - local_34[0x17])) {
          _tcp_xmit_timer();
        }
        if (*(int *)(local_8 + 0x1c) == local_34[0x14]) {
          *(undefined2 *)((int)local_34 + 10) = 0;
          bVar3 = true;
        }
        else if ((short)local_34[3] == 0) {
          *(short *)((int)local_34 + 10) = (short)local_34[5];
        }
        uVar9 = (uint)*(ushort *)(local_34 + 0x15);
        local_30 = (uint)*(ushort *)(local_34 + 6);
        if (*(ushort *)((int)local_34 + 0x56) < uVar9) {
          local_30 = (local_30 * local_30) / uVar9 + (uint)(*(ushort *)(local_34 + 6) >> 3);
        }
        uVar6 = _min(uVar9 + local_30);
        *(undefined2 *)(local_34 + 0x15) = uVar6;
        uVar1 = *(ushort *)(local_18 + 0x3c);
        if ((int)(uint)uVar1 < iVar12) {
          *(ushort *)(local_34 + 0xf) = (short)local_34[0xf] - uVar1;
          _sbdrop(local_18 + 0x3c);
        }
        else {
          _sbdrop(local_18 + 0x3c);
          *(short *)(local_34 + 0xf) = (short)local_34[0xf] - (short)iVar12;
        }
        bVar2 = (int)(uint)uVar1 < iVar12;
        if (((*(byte *)(local_18 + 0x50) & 4) != 0) || (*(int *)(local_18 + 0x4c) != 0)) {
          _sowakeup(local_18);
        }
        local_34[9] = *(int *)(local_8 + 0x1c);
        if (local_34[10] - local_34[9] < 0) {
          local_34[10] = local_34[9];
        }
        sVar16 = (short)local_34[2];
        if (sVar16 == 7) {
          if (bVar2) {
            *(undefined2 *)(local_34 + 2) = 10;
            _tcp_canceltimers();
            *(undefined2 *)(local_34 + 4) = 0x78;
            _soisdisconnected(local_18);
          }
        }
        else if (sVar16 < 8) {
          if ((sVar16 == 6) && (bVar2)) {
            if ((*(byte *)(local_18 + 6) & 0x20) != 0) {
              _soisdisconnected();
              *(undefined2 *)(local_34 + 4) = _tcp_maxidle;
            }
            *(undefined2 *)(local_34 + 2) = 9;
          }
        }
        else if (sVar16 == 8) {
          if (bVar2) goto LAB_00129620;
        }
        else if (sVar16 == 10) {
          *(undefined2 *)(local_34 + 4) = 0x78;
          goto LAB_0012995c;
        }
      }
    }
    else if ((2 < sVar16) && (sVar16 < 0xb)) goto LAB_001292ca;
LAB_00129640:
    if ((bVar4 & 0x10) != 0) {
      if (local_34[0xc] - *(int *)(local_8 + 0x18) < 0) {
LAB_00129685:
        if ((*(short *)(local_8 + 10) == 0) &&
           ((local_34[0xd] == *(int *)(local_8 + 0x1c) &&
            (*(ushort *)(local_34 + 0xf) < *(ushort *)(local_8 + 0x22))))) {
          _DAT_001eee24 = _DAT_001eee24 + 1;
        }
        *(undefined2 *)(local_34 + 0xf) = *(undefined2 *)(local_8 + 0x22);
        local_34[0xc] = *(int *)(local_8 + 0x18);
        local_34[0xd] = *(int *)(local_8 + 0x1c);
        if (*(ushort *)((int)local_34 + 0x66) < *(ushort *)(local_34 + 0xf)) {
          *(ushort *)((int)local_34 + 0x66) = *(ushort *)(local_34 + 0xf);
        }
        bVar3 = true;
      }
      else if (local_34[0xc] == *(int *)(local_8 + 0x18)) {
        if ((local_34[0xd] - *(int *)(local_8 + 0x1c) < 0) ||
           ((local_34[0xd] == *(int *)(local_8 + 0x1c) &&
            (*(ushort *)(local_34 + 0xf) < *(ushort *)(local_8 + 0x22))))) goto LAB_00129685;
      }
    }
    if ((((bVar4 & 0x20) == 0) || (uVar1 = *(ushort *)(local_8 + 0x26), uVar1 == 0)) ||
       (9 < (short)local_34[2])) {
      iVar12 = local_34[0x10];
      if (iVar12 != local_34[0x11] && -1 < iVar12 - local_34[0x11]) {
        local_34[0x11] = iVar12;
      }
    }
    else if ((uint)*(ushort *)(local_18 + 0x24) + (uint)uVar1 < 0x10000) {
      iVar12 = (uint)uVar1 + *(int *)(local_8 + 0x18);
      if (iVar12 != local_34[0x11] && -1 < iVar12 - local_34[0x11]) {
        local_34[0x11] = iVar12;
        sVar16 = ((short)iVar12 - (short)local_34[0x10]) + *(short *)(local_18 + 0x24) + -1;
        *(short *)(local_18 + 0x58) = sVar16;
        if (sVar16 == 0) {
          *(byte *)(local_18 + 6) = *(byte *)(local_18 + 6) | 0x40;
        }
        _sohasoutofband();
        *(byte *)(local_34 + 0x1a) = *(byte *)(local_34 + 0x1a) & 0xfc;
      }
      if (((int)(uint)*(ushort *)(local_8 + 0x26) <= (int)*(short *)(local_8 + 10)) &&
         ((*(byte *)(local_18 + 3) & 1) == 0)) {
        _tcp_pulloutofband(local_18,local_8);
      }
    }
    else {
      local_8[0x26] = 0;
      local_8[0x27] = 0;
      bVar4 = bVar4 & 0xdf;
    }
    if (((*(short *)(local_8 + 10) == 0) && ((bVar4 & 1) == 0)) || (9 < (short)local_34[2])) {
      _m_freem();
      bVar4 = 0;
    }
    else if (((*(int *)(local_8 + 0x18) == local_34[0x10]) && ((int *)*local_34 == local_34)) &&
            ((short)local_34[2] == 4)) {
      *(byte *)((int)local_34 + 0x1b) = *(byte *)((int)local_34 + 0x1b) | 2;
      local_34[0x10] = local_34[0x10] + (int)*(short *)(local_8 + 10);
      bVar4 = local_8[0x21] & 1;
      _DAT_001eedd8 = _DAT_001eedd8 + 1;
      _DAT_001eeddc = _DAT_001eeddc + *(short *)(local_8 + 10);
      _sbappend(local_18 + 0x24);
      _sowakeup(local_18,local_18 + 0x24);
    }
    else {
      bVar4 = _tcp_reass(local_34,local_8);
      *(byte *)((int)local_34 + 0x1b) = *(byte *)((int)local_34 + 0x1b) | 1;
    }
    if ((bVar4 & 1) != 0) {
      if ((short)local_34[2] < 10) {
        _socantrcvmore();
        *(byte *)((int)local_34 + 0x1b) = *(byte *)((int)local_34 + 0x1b) | 1;
        local_34[0x10] = local_34[0x10] + 1;
      }
      switch((short)local_34[2]) {
      case 3:
      case 4:
        *(undefined2 *)(local_34 + 2) = 5;
        break;
      case 6:
        *(undefined2 *)(local_34 + 2) = 7;
        break;
      case 9:
        *(undefined2 *)(local_34 + 2) = 10;
        _tcp_canceltimers();
        *(undefined2 *)(local_34 + 4) = 0x78;
        _soisdisconnected(local_18);
        break;
      case 10:
        *(undefined2 *)(local_34 + 4) = 0x78;
      }
    }
    if ((*(byte *)(local_18 + 2) & 1) != 0) {
      _tcp_trace(0,(int)local_20,local_34,&_tcp_saveti);
    }
    puVar14 = &stack0xffffff4c;
    if ((!bVar3) && (puVar14 = &stack0xffffff4c, (*(byte *)((int)local_34 + 0x1b) & 1) == 0)) {
      return;
    }
LAB_00129978:
    *(int **)(puVar14 + -4) = local_34;
    *(undefined4 *)(puVar14 + -8) = 0x12997e;
    _tcp_output();
    return;
  }
  switch((short)local_34[2]) {
  case 3:
    *(undefined2 *)(local_18 + 0x56) = 0x3d;
    break;
  case 4:
  case 5:
  case 6:
  case 9:
    *(undefined2 *)(local_18 + 0x56) = 0x36;
    break;
  case 7:
  case 8:
  case 10:
    goto LAB_00129620;
  default:
    goto switchD_001291c4_default;
  }
  *(undefined2 *)(local_34 + 2) = 0;
  _DAT_001eed7c = _DAT_001eed7c + 1;
LAB_00129620:
  local_34 = (int *)_tcp_close();
LAB_00129a20:
  if (local_10 != 0) {
    _m_free();
  }
  goto LAB_00129a32;
}

