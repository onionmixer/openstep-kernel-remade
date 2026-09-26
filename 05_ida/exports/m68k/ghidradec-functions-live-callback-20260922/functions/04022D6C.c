
void _tcp_input(byte *param_1)

{
  word wVar1;
  bool bVar2;
  byte bVar3;
  bool bVar4;
  sword sVar9;
  undefined4 *puVar5;
  undefined4 uVar6;
  int iVar7;
  uint uVar8;
  undefined2 uVar10;
  byte bVar11;
  int iVar12;
  sword sVar13;
  byte *unaff_D6;
  byte *pbVar14;
  byte *pbVar15;
  byte *pbVar16;
  byte *pbVar17;
  byte **ppbVar18;
  byte *pbStack_44;
  int iStack_16;
  int iStack_12;
  sword sStack_e;
  byte *pbStack_8;
  
  pbStack_8 = (byte *)0x0;
  pbVar16 = (byte *)0x0;
  bVar4 = false;
  iStack_12 = 0;
  iStack_16 = 0;
  dword_40BBD90 = dword_40BBD90 + 1;
  pbVar17 = param_1 + *(int *)(param_1 + 4);
  if (5 < (*pbVar17 & 0xf)) {
    pbStack_44 = (byte *)0x0;
    _ip_stripoptions(pbVar17);
  }
  if (*(word *)(param_1 + 8) < 0x28) {
    pbStack_44 = (byte *)0x28;
    param_1 = (byte *)_m_pullup(param_1);
    if (param_1 == (byte *)0x0) goto loc_4022E54;
    pbVar17 = param_1 + *(int *)(param_1 + 4);
  }
  sVar13 = *(sword *)(pbVar17 + 2);
  pbVar17[4] = 0;
  pbVar17[5] = 0;
  pbVar17[6] = 0;
  pbVar17[7] = 0;
  pbVar17[0] = 0;
  pbVar17[1] = 0;
  pbVar17[2] = 0;
  pbVar17[3] = 0;
  pbVar17[8] = 0;
  *(sword *)(pbVar17 + 10) = sVar13;
  *(sword *)(pbVar17 + 10) = sVar13;
  pbStack_44 = (byte *)(sVar13 + 0x14);
  sVar9 = _in_cksum(param_1);
  *(sword *)(pbVar17 + 0x24) = sVar9;
  if (sVar9 != 0) {
    dword_40BBD9C = dword_40BBD9C + 1;
    goto loc_4023D06;
  }
  uVar8 = (*(uint *)(pbVar17 + 0x20) >> 0x1c) * 4;
  if ((uVar8 < 0x14) || ((int)sVar13 < (int)uVar8)) {
    dword_40BBDA0 = dword_40BBDA0 + 1;
    goto loc_4023D06;
  }
  *(sword *)(pbVar17 + 10) = sVar13 - (sword)uVar8;
  if (uVar8 < 0x15) {
loc_4022EE0:
    bVar11 = pbVar17[0x21];
    do {
      if ((((*(sword *)(pbVar17 + 0x16) != *(sword *)((int)_tcp_last_inpcb + 0x16)) ||
           (*(sword *)(pbVar17 + 0x14) != *(sword *)(_tcp_last_inpcb + 4))) ||
          (_tcp_last_inpcb[3] != *(int *)(pbVar17 + 0xc))) ||
         (puVar5 = _tcp_last_inpcb,
         *(int *)((int)_tcp_last_inpcb + 0x12) != *(int *)(pbVar17 + 0x10))) {
        pbStack_44 = (byte *)0x1;
        puVar5 = (undefined4 *)
                 _in_pcblookup(&_tcb,*(undefined4 *)(pbVar17 + 0xc),*(undefined2 *)(pbVar17 + 0x14),
                               *(undefined4 *)(pbVar17 + 0x10),*(undefined2 *)(pbVar17 + 0x16));
        if (puVar5 != (undefined4 *)0x0) {
          _tcp_last_inpcb = puVar5;
        }
        _tcppcbcachemiss = _tcppcbcachemiss + 1;
      }
      if ((puVar5 == (undefined4 *)0x0) || (pbVar16 = (byte *)puVar5[7], pbVar16 == (byte *)0x0))
      goto loc_4023C9C;
      if (*(sword *)(pbVar16 + 8) == 0) goto loc_4023D06;
      unaff_D6 = (byte *)puVar5[6];
      if ((*(word *)(unaff_D6 + 2) & 3) != 0) {
        if ((*(word *)(unaff_D6 + 2) & 1) != 0) {
          _tcp_saveti = *(undefined4 *)pbVar17;
          dword_40BBDEC = *(undefined4 *)(pbVar17 + 4);
          dword_40BBDF0 = *(undefined4 *)(pbVar17 + 8);
          dword_40BBDF4 = *(undefined4 *)(pbVar17 + 0xc);
          dword_40BBDF8 = *(undefined4 *)(pbVar17 + 0x10);
          dword_40BBDFC = *(undefined4 *)(pbVar17 + 0x14);
          dword_40BBE00 = *(undefined4 *)(pbVar17 + 0x18);
          dword_40BBE04 = *(undefined4 *)(pbVar17 + 0x1c);
          dword_40BBE08 = *(undefined4 *)(pbVar17 + 0x20);
          dword_40BBE0C = *(undefined4 *)(pbVar17 + 0x24);
          sStack_e = *(sword *)(pbVar16 + 8);
        }
        if ((unaff_D6[3] & 2) != 0) {
          pbStack_44 = (byte *)0x0;
          unaff_D6 = (byte *)_sonewconn(unaff_D6);
          if (unaff_D6 == (byte *)0x0) goto loc_4023D06;
          iStack_12 = iStack_12 + 1;
          puVar5 = *(undefined4 **)(unaff_D6 + 8);
          *(undefined4 *)((int)puVar5 + 0x12) = *(undefined4 *)(pbVar17 + 0x10);
          *(undefined2 *)((int)puVar5 + 0x16) = *(undefined2 *)(pbVar17 + 0x16);
          pbStack_44 = (byte *)0x4022ffc;
          uVar6 = _ip_srcroute();
          puVar5[0xd] = uVar6;
          pbVar16 = (byte *)puVar5[7];
          pbVar16[8] = 0;
          pbVar16[9] = 1;
        }
      }
      pbVar16[0x58] = 0;
      pbVar16[0x59] = 0;
      *(undefined2 *)(pbVar16 + 0xe) = word_40AEB7E;
      if ((pbStack_8 != (byte *)0x0) && (*(sword *)(pbVar16 + 8) != 1)) {
        pbStack_44 = pbVar17;
        _tcp_dooptions(pbVar16,pbStack_8);
        pbStack_8 = (byte *)0x0;
      }
      if ((((*(sword *)(pbVar16 + 8) == 4) && ((bVar11 & 0x37) == 0x10)) &&
          (*(int *)(pbVar17 + 0x18) == *(int *)(pbVar16 + 0x40))) &&
         (((wVar1 = *(word *)(pbVar17 + 0x22), wVar1 != 0 && (wVar1 == *(word *)(pbVar16 + 0x3c)))
          && (iVar12 = *(int *)(pbVar16 + 0x28), iVar12 == *(int *)(pbVar16 + 0x50))))) {
        if (*(sword *)(pbVar17 + 10) == 0) {
          iVar7 = *(int *)(pbVar17 + 0x1c);
          if (((iVar7 != *(int *)(pbVar16 + 0x24) && -1 < iVar7 - *(int *)(pbVar16 + 0x24)) &&
              (iVar7 == iVar12 || iVar7 - iVar12 < 0)) && (wVar1 <= *(word *)(pbVar16 + 0x54))) {
            _tcppredack = _tcppredack + 1;
            if ((*(sword *)(pbVar16 + 0x5a) != 0) &&
               (*(int *)(pbVar17 + 0x1c) != *(int *)(pbVar16 + 0x5c) &&
                -1 < *(int *)(pbVar17 + 0x1c) - *(int *)(pbVar16 + 0x5c))) {
              pbStack_44 = pbVar16;
              _tcp_xmit_timer();
            }
            pbStack_44 = (byte *)(*(int *)(pbVar17 + 0x1c) - *(int *)(pbVar16 + 0x24));
            dword_40BBDD8 = dword_40BBDD8 + 1;
            dword_40BBDDC = pbStack_44 + (int)dword_40BBDDC;
            _sbdrop(unaff_D6 + 0x38);
            *(int *)(pbVar16 + 0x24) = *(int *)(pbVar17 + 0x1c);
            _m_freem(param_1);
            if (*(int *)(pbVar16 + 0x24) == *(int *)(pbVar16 + 0x50)) {
              pbVar16[10] = 0;
              pbVar16[0xb] = 0;
            }
            else if (*(sword *)(pbVar16 + 0xc) == 0) {
              *(undefined2 *)(pbVar16 + 10) = *(undefined2 *)(pbVar16 + 0x14);
            }
            if (((unaff_D6[0x4d] & 4) != 0) || (*(int *)(unaff_D6 + 0x48) != 0)) {
              pbStack_44 = unaff_D6 + 0x38;
              _sowakeup(unaff_D6);
            }
            ppbVar18 = (byte **)&stack0xffffffc0;
            if (*(sword *)(unaff_D6 + 0x38) == 0) {
              return;
            }
            goto loc_4023C90;
          }
        }
        else if ((*(int *)(pbVar17 + 0x1c) == *(int *)(pbVar16 + 0x24)) &&
                (pbVar16 == *(byte **)pbVar16)) {
          iVar12 = (uint)*(word *)(unaff_D6 + 0x24) - (uint)*(word *)(unaff_D6 + 0x22);
          if ((int)((uint)*(word *)(unaff_D6 + 0x28) - (uint)*(word *)(unaff_D6 + 0x26)) <
              (int)((uint)*(word *)(unaff_D6 + 0x24) - (uint)*(word *)(unaff_D6 + 0x22))) {
            iVar12 = (uint)*(word *)(unaff_D6 + 0x28) - (uint)*(word *)(unaff_D6 + 0x26);
          }
          if (*(sword *)(pbVar17 + 10) <= iVar12) {
            _tcppreddat = _tcppreddat + 1;
            *(int *)(pbVar16 + 0x40) = (int)*(sword *)(pbVar17 + 10) + *(int *)(pbVar16 + 0x40);
            dword_40BBD94 = dword_40BBD94 + 1;
            dword_40BBD98 = *(sword *)(pbVar17 + 10) + dword_40BBD98;
            *(int *)(param_1 + 4) = *(int *)(param_1 + 4) + 0x28;
            *(sword *)(param_1 + 8) = *(sword *)(param_1 + 8) + -0x28;
            pbStack_44 = param_1;
            _sbappend(unaff_D6 + 0x22);
            _sowakeup(unaff_D6,unaff_D6 + 0x22);
            pbVar16[0x1b] = pbVar16[0x1b] | 2;
            return;
          }
        }
      }
      *(int *)(param_1 + 4) = *(int *)(param_1 + 4) + 0x28;
      *(sword *)(param_1 + 8) = *(sword *)(param_1 + 8) + -0x28;
      iVar12 = (uint)*(word *)(unaff_D6 + 0x24) - (uint)*(word *)(unaff_D6 + 0x22);
      if ((int)((uint)*(word *)(unaff_D6 + 0x28) - (uint)*(word *)(unaff_D6 + 0x26)) <
          (int)((uint)*(word *)(unaff_D6 + 0x24) - (uint)*(word *)(unaff_D6 + 0x22))) {
        iVar12 = (uint)*(word *)(unaff_D6 + 0x28) - (uint)*(word *)(unaff_D6 + 0x26);
      }
      if (iVar12 < 0) {
        iVar12 = 0;
      }
      sVar13 = (sword)iVar12;
      if (iVar12 <= *(int *)(pbVar16 + 0x4c) - *(int *)(pbVar16 + 0x40)) {
        sVar13 = (sword)*(int *)(pbVar16 + 0x4c) - (sword)*(int *)(pbVar16 + 0x40);
      }
      *(sword *)(pbVar16 + 0x3e) = sVar13;
      sVar13 = *(sword *)(pbVar16 + 8);
      if (sVar13 == 1) {
        if ((bVar11 & 4) != 0) goto loc_4023D06;
        if ((bVar11 & 0x10) != 0) goto loc_4023C9C;
        if ((bVar11 & 2) == 0) goto loc_4023D06;
        pbStack_44 = *(byte **)(pbVar17 + 0x10);
        iVar12 = _in_broadcast();
        if (iVar12 != 0) goto loc_4023D06;
        pbStack_44 = (byte *)0x8;
        pbVar15 = (byte *)_m_get(0);
        if (pbVar15 == (byte *)0x0) goto loc_4023D06;
        pbVar15[8] = 0;
        pbVar15[9] = 0x10;
        pbVar14 = pbVar15 + *(int *)(pbVar15 + 4);
        pbVar14[0] = 0;
        pbVar14[1] = 2;
        *(undefined4 *)(pbVar14 + 4) = *(undefined4 *)(pbVar17 + 0xc);
        *(undefined2 *)(pbVar14 + 2) = *(undefined2 *)(pbVar17 + 0x14);
        iVar12 = *(int *)((int)puVar5 + 0x12);
        if (iVar12 == 0) {
          *(undefined4 *)((int)puVar5 + 0x12) = *(undefined4 *)(pbVar17 + 0x10);
        }
        pbStack_44 = pbVar15;
        iVar7 = _in_pcbconnect(puVar5);
        if (iVar7 != 0) {
          *(int *)((int)puVar5 + 0x12) = iVar12;
          pbStack_44 = pbVar15;
          _m_free();
          goto loc_4023D06;
        }
        pbStack_44 = pbVar15;
        _m_free();
        iVar12 = _tcp_template(pbVar16);
        *(int *)(pbVar16 + 0x1c) = iVar12;
        if (iVar12 == 0) {
          pbStack_44 = (byte *)0x37;
          pbVar16 = (byte *)_tcp_drop(pbVar16);
          iStack_12 = 0;
          goto loc_4023D06;
        }
        if (pbStack_8 != (byte *)0x0) {
          pbStack_44 = pbVar17;
          _tcp_dooptions(pbVar16,pbStack_8);
        }
        if (iStack_16 == 0) {
          *(int *)(pbVar16 + 0x38) = _tcp_iss;
        }
        else {
          *(int *)(pbVar16 + 0x38) = iStack_16;
        }
        _tcp_iss = _tcp_iss + 64000;
        *(int *)(pbVar16 + 0x48) = *(int *)(pbVar17 + 0x18);
        iVar12 = *(int *)(pbVar16 + 0x38);
        *(int *)(pbVar16 + 0x2c) = iVar12;
        *(int *)(pbVar16 + 0x50) = iVar12;
        *(int *)(pbVar16 + 0x28) = iVar12;
        *(int *)(pbVar16 + 0x24) = iVar12;
        *(int *)(pbVar16 + 0x40) = *(int *)(pbVar16 + 0x48) + 1;
        *(int *)(pbVar16 + 0x4c) = *(int *)(pbVar16 + 0x48) + 1;
        pbVar16[0x1b] = pbVar16[0x1b] | 1;
        pbVar16[8] = 0;
        pbVar16[9] = 3;
        pbVar16[0xe] = 0;
        pbVar16[0xf] = 0x96;
        dword_40BBD30 = dword_40BBD30 + 1;
loc_4023456:
        *(int *)(pbVar17 + 0x18) = *(int *)(pbVar17 + 0x18) + 1;
        if ((int)(uint)*(word *)(pbVar16 + 0x3e) < (int)*(sword *)(pbVar17 + 10)) {
          iVar12 = (int)*(sword *)(pbVar17 + 10) - (uint)*(word *)(pbVar16 + 0x3e);
          pbStack_44 = (byte *)-iVar12;
          _m_adj(param_1);
          *(undefined2 *)(pbVar17 + 10) = *(undefined2 *)(pbVar16 + 0x3e);
          bVar11 = bVar11 & 0xfe;
          dword_40BBDC0 = dword_40BBDC0 + 1;
          dword_40BBDC4 = iVar12 + dword_40BBDC4;
        }
        *(int *)(pbVar16 + 0x30) = *(int *)(pbVar17 + 0x18) + -1;
        *(int *)(pbVar16 + 0x44) = *(int *)(pbVar17 + 0x18);
        goto loc_40239E2;
      }
      if ((0 < sVar13) && (sVar13 < 4)) {
        bVar3 = bVar11 & 0x10;
        if ((bVar3 != 0) &&
           ((iVar12 = *(int *)(pbVar17 + 0x1c),
            iVar12 == *(int *)(pbVar16 + 0x38) || iVar12 - *(int *)(pbVar16 + 0x38) < 0 ||
            (iVar12 != *(int *)(pbVar16 + 0x50) && -1 < iVar12 - *(int *)(pbVar16 + 0x50)))))
        goto loc_4023C9C;
        if ((bVar11 & 4) != 0) {
          if (bVar3 != 0) {
            pbStack_44 = (byte *)0x3d;
            pbVar16 = (byte *)_tcp_drop(pbVar16);
          }
          goto loc_4023D06;
        }
        if (*(sword *)(pbVar16 + 8) != 3) {
          if ((bVar11 & 2) != 0) {
            if (bVar3 != 0) {
              *(int *)(pbVar16 + 0x24) = *(int *)(pbVar17 + 0x1c);
              if (*(int *)(pbVar16 + 0x28) - *(int *)(pbVar16 + 0x24) < 0) {
                *(int *)(pbVar16 + 0x28) = *(int *)(pbVar16 + 0x24);
              }
            }
            pbVar16[10] = 0;
            pbVar16[0xb] = 0;
            *(int *)(pbVar16 + 0x48) = *(int *)(pbVar17 + 0x18);
            *(int *)(pbVar16 + 0x40) = *(int *)(pbVar16 + 0x48) + 1;
            *(int *)(pbVar16 + 0x4c) = *(int *)(pbVar16 + 0x48) + 1;
            pbVar16[0x1b] = pbVar16[0x1b] | 1;
            if (((bVar11 & 0x10) == 0) ||
               (*(int *)(pbVar16 + 0x24) == *(int *)(pbVar16 + 0x38) ||
                *(int *)(pbVar16 + 0x24) - *(int *)(pbVar16 + 0x38) < 0)) {
              pbVar16[8] = 0;
              pbVar16[9] = 3;
            }
            else {
              dword_40BBD34 = dword_40BBD34 + 1;
              pbStack_44 = unaff_D6;
              _soisconnected();
              pbVar16[8] = 0;
              pbVar16[9] = 4;
              _tcp_reass(pbVar16,0,0);
              if (*(sword *)(pbVar16 + 0x5a) != 0) {
                pbStack_44 = pbVar16;
                _tcp_xmit_timer();
              }
            }
            goto loc_4023456;
          }
          goto loc_4023D06;
        }
      }
      pbVar15 = (byte *)(*(int *)(pbVar16 + 0x40) - *(int *)(pbVar17 + 0x18));
      if (0 < (int)pbVar15) {
        if ((bVar11 & 2) != 0) {
          *(int *)(pbVar17 + 0x18) = *(int *)(pbVar17 + 0x18) + 1;
          if (*(word *)(pbVar17 + 0x26) < 2) {
            bVar11 = bVar11 & 0xdd;
          }
          else {
            *(word *)(pbVar17 + 0x26) = *(word *)(pbVar17 + 0x26) - 1;
            bVar11 = bVar11 & 0xfd;
          }
          pbVar15 = pbVar15 + -1;
        }
        if (((int)*(sword *)(pbVar17 + 10) < (int)pbVar15) ||
           (((byte *)(int)*(sword *)(pbVar17 + 10) == pbVar15 && ((bVar11 & 1) == 0)))) {
          dword_40BBDA8 = dword_40BBDA8 + 1;
          dword_40BBDAC = *(sword *)(pbVar17 + 10) + dword_40BBDAC;
          if (((bVar11 & 1) == 0) ||
             (sVar13 = *(sword *)(pbVar17 + 10), (byte *)(int)sVar13 + 1 != pbVar15))
          goto loc_4023C7A;
          bVar11 = bVar11 & 0xfe;
          pbVar16[0x1b] = pbVar16[0x1b] | 1;
          pbVar15 = (byte *)(int)sVar13;
        }
        else {
          dword_40BBDB0 = dword_40BBDB0 + 1;
          dword_40BBDB4 = pbVar15 + (int)dword_40BBDB4;
        }
        pbStack_44 = pbVar15;
        _m_adj(param_1);
        *(byte **)(pbVar17 + 0x18) = pbVar15 + *(int *)(pbVar17 + 0x18);
        *(sword *)(pbVar17 + 10) = *(sword *)(pbVar17 + 10) - (sword)pbVar15;
        if ((int)pbVar15 < (int)(uint)*(word *)(pbVar17 + 0x26)) {
          *(word *)(pbVar17 + 0x26) = *(word *)(pbVar17 + 0x26) - (sword)pbVar15;
        }
        else {
          bVar11 = bVar11 & 0xdf;
          pbVar17[0x26] = 0;
          pbVar17[0x27] = 0;
        }
      }
      if ((((unaff_D6[7] & 1) != 0) && (5 < *(sword *)(pbVar16 + 8))) &&
         (*(sword *)(pbVar17 + 10) != 0)) {
        pbStack_44 = pbVar16;
        pbVar16 = (byte *)_tcp_close();
        dword_40BBDC8 = dword_40BBDC8 + 1;
        goto loc_4023C9C;
      }
      iVar12 = (*(int *)(pbVar17 + 0x18) + (int)*(sword *)(pbVar17 + 10)) -
               (*(int *)(pbVar16 + 0x40) + (uint)*(word *)(pbVar16 + 0x3e));
      if (iVar12 < 1) goto loc_4023636;
      dword_40BBDC0 = dword_40BBDC0 + 1;
      if (iVar12 < *(sword *)(pbVar17 + 10)) {
        dword_40BBDC4 = iVar12 + dword_40BBDC4;
        goto loc_402361E;
      }
      dword_40BBDC4 = *(sword *)(pbVar17 + 10) + dword_40BBDC4;
      if ((((bVar11 & 2) == 0) || (*(sword *)(pbVar16 + 8) != 10)) ||
         (iStack_16 = *(int *)(pbVar16 + 0x40),
         *(int *)(pbVar17 + 0x18) == iStack_16 || *(int *)(pbVar17 + 0x18) - iStack_16 < 0))
      goto loc_40235F6;
      iStack_16 = iStack_16 + 0x1f400;
      pbStack_44 = pbVar16;
      pbVar16 = (byte *)_tcp_close();
    } while( true );
  }
  pbStack_44 = (byte *)(uVar8 + 0x14);
  if ((byte *)(int)*(sword *)(param_1 + 8) < pbStack_44) {
    param_1 = (byte *)_m_pullup(param_1);
    if (param_1 == (byte *)0x0) {
loc_4022E54:
      dword_40BBDA4 = dword_40BBDA4 + 1;
      return;
    }
    pbVar17 = param_1 + *(int *)(param_1 + 4);
  }
  pbStack_44 = (byte *)0x1;
  pbStack_8 = (byte *)_m_get(0);
  if (pbStack_8 != (byte *)0x0) {
    sVar13 = (sword)uVar8 + -0x14;
    *(sword *)(pbStack_8 + 8) = sVar13;
    pbVar15 = param_1 + *(int *)(param_1 + 4) + 0x28;
    pbStack_44 = (byte *)(int)sVar13;
    _bcopy(pbVar15,pbStack_8 + *(int *)(pbStack_8 + 4));
    sVar13 = *(sword *)(param_1 + 8);
    sVar9 = *(sword *)(pbStack_8 + 8);
    *(sword *)(param_1 + 8) = sVar13 - sVar9;
    _bcopy(pbVar15 + *(sword *)(pbStack_8 + 8),pbVar15,(sword)(sVar13 - sVar9) + -0x28);
    goto loc_4022EE0;
  }
loc_4023D18:
  if ((pbVar16 != (byte *)0x0) &&
     ((*(byte *)(*(int *)(*(int *)(pbVar16 + 0x20) + 0x18) + 3) & 1) != 0)) {
    pbStack_44 = (byte *)0x0;
    _tcp_trace(4,(int)sStack_e,pbVar16,&_tcp_saveti);
  }
  pbStack_44 = param_1;
  _m_freem();
loc_4023D54:
  if (iStack_12 != 0) {
    pbStack_44 = unaff_D6;
    _soabort();
  }
  return;
loc_40235F6:
  if ((*(sword *)(pbVar16 + 0x3e) != 0) || (*(int *)(pbVar17 + 0x18) != *(int *)(pbVar16 + 0x40)))
  goto loc_4023C7A;
  pbVar16[0x1b] = pbVar16[0x1b] | 1;
  dword_40BBDCC = dword_40BBDCC + 1;
loc_402361E:
  pbStack_44 = (byte *)-iVar12;
  _m_adj(param_1);
  *(sword *)(pbVar17 + 10) = *(sword *)(pbVar17 + 10) - (sword)iVar12;
  bVar11 = bVar11 & 0xf6;
loc_4023636:
  if ((bVar11 & 4) == 0) {
loc_4023696:
    if ((bVar11 & 2) != 0) {
      pbStack_44 = (byte *)0x36;
      pbVar16 = (byte *)_tcp_drop(pbVar16);
loc_4023C9C:
      if (pbStack_8 != (byte *)0x0) {
        pbStack_44 = pbStack_8;
        _m_free();
        pbStack_8 = (byte *)0x0;
      }
      if ((bVar11 & 4) == 0) {
        pbStack_44 = *(byte **)(pbVar17 + 0x10);
        iVar12 = _in_broadcast();
        if (iVar12 == 0) {
          if ((bVar11 & 0x10) == 0) {
            if ((bVar11 & 2) != 0) {
              *(sword *)(pbVar17 + 10) = *(sword *)(pbVar17 + 10) + 1;
            }
            pbStack_44 = (byte *)0x14;
            uVar6 = 0;
            iVar12 = *(int *)(pbVar17 + 0x18) + (int)*(sword *)(pbVar17 + 10);
          }
          else {
            pbStack_44 = (byte *)0x4;
            uVar6 = *(undefined4 *)(pbVar17 + 0x1c);
            iVar12 = 0;
          }
          _tcp_respond(pbVar16,pbVar17,param_1,iVar12,uVar6);
          goto loc_4023D54;
        }
      }
      goto loc_4023D06;
    }
    if ((bVar11 & 0x10) == 0) goto loc_4023D06;
    sVar13 = *(sword *)(pbVar16 + 8);
    if (sVar13 == 3) {
      iVar12 = *(int *)(pbVar17 + 0x1c);
      if ((*(int *)(pbVar16 + 0x24) != iVar12 && -1 < *(int *)(pbVar16 + 0x24) - iVar12) ||
         (iVar12 != *(int *)(pbVar16 + 0x50) && -1 < iVar12 - *(int *)(pbVar16 + 0x50)))
      goto loc_4023C9C;
      dword_40BBD34 = dword_40BBD34 + 1;
      pbStack_44 = unaff_D6;
      _soisconnected();
      pbVar16[8] = 0;
      pbVar16[9] = 4;
      _tcp_reass(pbVar16,0,0);
      *(int *)(pbVar16 + 0x30) = *(int *)(pbVar17 + 0x18) + -1;
loc_402371A:
      if (*(int *)(pbVar17 + 0x1c) == *(int *)(pbVar16 + 0x24) ||
          *(int *)(pbVar17 + 0x1c) - *(int *)(pbVar16 + 0x24) < 0) {
        if ((((*(sword *)(pbVar17 + 10) == 0) &&
             (*(sword *)(pbVar16 + 0x3c) == *(sword *)(pbVar17 + 0x22))) &&
            (dword_40BBDD0 = dword_40BBDD0 + 1, *(sword *)(pbVar16 + 10) != 0)) &&
           (*(int *)(pbVar17 + 0x1c) == *(int *)(pbVar16 + 0x24))) {
          sVar13 = *(sword *)(pbVar16 + 0x16);
          *(sword *)(pbVar16 + 0x16) = sVar13 + 1;
          iVar12 = (int)(sword)(sVar13 + 1);
          if (_tcprexmtthresh == iVar12) {
            iVar12 = *(int *)(pbVar16 + 0x28);
            pbStack_44 = (byte *)(uint)*(word *)(pbVar16 + 0x54);
            uVar8 = _min(*(undefined2 *)(pbVar16 + 0x3c));
            uVar8 = (uVar8 >> 1) / (uint)*(word *)(pbVar16 + 0x18);
            if (uVar8 < 2) {
              uVar8 = 2;
            }
            *(word *)(pbVar16 + 0x56) = *(word *)(pbVar16 + 0x18) * (sword)uVar8;
            pbVar16[10] = 0;
            pbVar16[0xb] = 0;
            pbVar16[0x5a] = 0;
            pbVar16[0x5b] = 0;
            *(int *)(pbVar16 + 0x28) = *(int *)(pbVar17 + 0x1c);
            *(undefined2 *)(pbVar16 + 0x54) = *(undefined2 *)(pbVar16 + 0x18);
            pbStack_44 = pbVar16;
            _tcp_output();
            *(sword *)(pbVar16 + 0x54) =
                 *(sword *)(pbVar16 + 0x56) +
                 *(sword *)(pbVar16 + 0x18) * *(sword *)(pbVar16 + 0x16);
            if (iVar12 != *(int *)(pbVar16 + 0x28) && -1 < iVar12 - *(int *)(pbVar16 + 0x28)) {
              *(int *)(pbVar16 + 0x28) = iVar12;
            }
          }
          else {
            if (iVar12 <= _tcprexmtthresh) goto loc_40239E2;
            *(sword *)(pbVar16 + 0x54) = *(sword *)(pbVar16 + 0x18) + *(sword *)(pbVar16 + 0x54);
            pbStack_44 = pbVar16;
            _tcp_output();
          }
          goto loc_4023D06;
        }
        pbVar16[0x16] = 0;
        pbVar16[0x17] = 0;
      }
      else {
        if ((_tcprexmtthresh < *(sword *)(pbVar16 + 0x16)) &&
           (*(word *)(pbVar16 + 0x56) < *(word *)(pbVar16 + 0x54))) {
          *(word *)(pbVar16 + 0x54) = *(word *)(pbVar16 + 0x56);
        }
        pbVar16[0x16] = 0;
        pbVar16[0x17] = 0;
        iVar12 = *(int *)(pbVar17 + 0x1c);
        if (iVar12 != *(int *)(pbVar16 + 0x50) && -1 < iVar12 - *(int *)(pbVar16 + 0x50)) {
          dword_40BBDD4 = dword_40BBDD4 + 1;
loc_4023C7A:
          if ((bVar11 & 4) == 0) {
            pbStack_44 = param_1;
            _m_freem();
            pbVar16[0x1b] = pbVar16[0x1b] | 1;
            ppbVar18 = &pbStack_44;
            goto loc_4023C90;
          }
          goto loc_4023D06;
        }
        pbVar15 = (byte *)(iVar12 - *(int *)(pbVar16 + 0x24));
        dword_40BBDD8 = dword_40BBDD8 + 1;
        dword_40BBDDC = pbVar15 + (int)dword_40BBDDC;
        if ((*(sword *)(pbVar16 + 0x5a) != 0) &&
           (*(int *)(pbVar17 + 0x1c) != *(int *)(pbVar16 + 0x5c) &&
            -1 < *(int *)(pbVar17 + 0x1c) - *(int *)(pbVar16 + 0x5c))) {
          pbStack_44 = pbVar16;
          _tcp_xmit_timer();
        }
        if (*(int *)(pbVar17 + 0x1c) == *(int *)(pbVar16 + 0x50)) {
          pbVar16[10] = 0;
          pbVar16[0xb] = 0;
          bVar4 = true;
        }
        else if (*(sword *)(pbVar16 + 0xc) == 0) {
          *(undefined2 *)(pbVar16 + 10) = *(undefined2 *)(pbVar16 + 0x14);
        }
        uVar8 = (uint)*(word *)(pbVar16 + 0x18);
        if (*(word *)(pbVar16 + 0x56) < *(word *)(pbVar16 + 0x54)) {
          uVar8 = (uint)(*(word *)(pbVar16 + 0x18) >> 3) +
                  (uVar8 * uVar8) / (uint)*(word *)(pbVar16 + 0x54);
        }
        pbStack_44 = (byte *)0xffff;
        uVar10 = _min(*(word *)(pbVar16 + 0x54) + uVar8);
        *(undefined2 *)(pbVar16 + 0x54) = uVar10;
        bVar2 = (int)pbVar15 <= (int)(uint)*(word *)(unaff_D6 + 0x38);
        if (bVar2) {
          pbStack_44 = pbVar15;
          _sbdrop(unaff_D6 + 0x38);
          *(sword *)(pbVar16 + 0x3c) = *(sword *)(pbVar16 + 0x3c) - (sword)pbVar15;
        }
        else {
          *(word *)(pbVar16 + 0x3c) = *(sword *)(pbVar16 + 0x3c) - *(word *)(unaff_D6 + 0x38);
          pbStack_44 = (byte *)(uint)*(word *)(unaff_D6 + 0x38);
          _sbdrop(unaff_D6 + 0x38);
        }
        if (((unaff_D6[0x4d] & 4) != 0) || (*(int *)(unaff_D6 + 0x48) != 0)) {
          pbStack_44 = unaff_D6 + 0x38;
          _sowakeup(unaff_D6);
        }
        *(int *)(pbVar16 + 0x24) = *(int *)(pbVar17 + 0x1c);
        if (*(int *)(pbVar16 + 0x28) - *(int *)(pbVar16 + 0x24) < 0) {
          *(int *)(pbVar16 + 0x28) = *(int *)(pbVar16 + 0x24);
        }
        sVar13 = *(sword *)(pbVar16 + 8);
        if (sVar13 == 7) {
          if (!bVar2) {
            pbVar16[8] = 0;
            pbVar16[9] = 10;
            pbStack_44 = pbVar16;
            _tcp_canceltimers();
            pbVar16[0x10] = 0;
            pbVar16[0x11] = 0x78;
            _soisdisconnected(unaff_D6);
          }
        }
        else if (sVar13 < 8) {
          if ((sVar13 == 6) && (!bVar2)) {
            if ((unaff_D6[7] & 0x20) != 0) {
              pbStack_44 = unaff_D6;
              _soisdisconnected();
              *(undefined2 *)(pbVar16 + 0x10) = word_40BBDE6;
            }
            pbVar16[8] = 0;
            pbVar16[9] = 9;
          }
        }
        else if (sVar13 == 8) {
          if (!bVar2) goto loc_40239C8;
        }
        else if (sVar13 == 10) {
          pbVar16[0x10] = 0;
          pbVar16[0x11] = 0x78;
          goto loc_4023C7A;
        }
      }
    }
    else if ((2 < sVar13) && (sVar13 < 0xb)) goto loc_402371A;
loc_40239E2:
    if ((bVar11 & 0x10) != 0) {
      if (*(int *)(pbVar16 + 0x30) - *(int *)(pbVar17 + 0x18) < 0) {
loc_4023A16:
        if ((*(sword *)(pbVar17 + 10) == 0) &&
           ((*(int *)(pbVar16 + 0x34) == *(int *)(pbVar17 + 0x1c) &&
            (*(word *)(pbVar16 + 0x3c) < *(word *)(pbVar17 + 0x22))))) {
          dword_40BBDE0 = dword_40BBDE0 + 1;
        }
        *(undefined2 *)(pbVar16 + 0x3c) = *(undefined2 *)(pbVar17 + 0x22);
        *(int *)(pbVar16 + 0x30) = *(int *)(pbVar17 + 0x18);
        *(int *)(pbVar16 + 0x34) = *(int *)(pbVar17 + 0x1c);
        if (*(word *)(pbVar16 + 0x66) < *(word *)(pbVar16 + 0x3c)) {
          *(word *)(pbVar16 + 0x66) = *(word *)(pbVar16 + 0x3c);
        }
        bVar4 = true;
      }
      else if (*(int *)(pbVar17 + 0x18) == *(int *)(pbVar16 + 0x30)) {
        if ((*(int *)(pbVar16 + 0x34) - *(int *)(pbVar17 + 0x1c) < 0) ||
           ((*(int *)(pbVar17 + 0x1c) == *(int *)(pbVar16 + 0x34) &&
            (*(word *)(pbVar16 + 0x3c) < *(word *)(pbVar17 + 0x22))))) goto loc_4023A16;
      }
    }
    if ((((bVar11 & 0x20) == 0) || (wVar1 = *(word *)(pbVar17 + 0x26), wVar1 == 0)) ||
       (9 < *(sword *)(pbVar16 + 8))) {
      iVar12 = *(int *)(pbVar16 + 0x40);
      if (iVar12 != *(int *)(pbVar16 + 0x44) && -1 < iVar12 - *(int *)(pbVar16 + 0x44)) {
        *(int *)(pbVar16 + 0x44) = iVar12;
      }
    }
    else if ((uint)wVar1 + (uint)*(word *)(unaff_D6 + 0x22) < 0x10000) {
      iVar12 = *(int *)(pbVar17 + 0x18) + (uint)wVar1;
      if (iVar12 != *(int *)(pbVar16 + 0x44) && -1 < iVar12 - *(int *)(pbVar16 + 0x44)) {
        *(int *)(pbVar16 + 0x44) = iVar12;
        sVar13 = *(sword *)(unaff_D6 + 0x22) + ((sword)iVar12 - *(sword *)(pbVar16 + 0x42)) + -1;
        *(sword *)(unaff_D6 + 0x52) = sVar13;
        if (sVar13 == 0) {
          *(word *)(unaff_D6 + 6) = *(word *)(unaff_D6 + 6) | 0x40;
        }
        pbStack_44 = unaff_D6;
        _sohasoutofband();
        pbVar16[0x68] = pbVar16[0x68] & 0xfc;
      }
      if (((int)(uint)*(word *)(pbVar17 + 0x26) <= (int)*(sword *)(pbVar17 + 10)) &&
         ((unaff_D6[2] & 1) == 0)) {
        pbStack_44 = param_1;
        _tcp_pulloutofband(unaff_D6,pbVar17);
      }
    }
    else {
      pbVar17[0x26] = 0;
      pbVar17[0x27] = 0;
      bVar11 = bVar11 & 0xdf;
    }
    if (((*(sword *)(pbVar17 + 10) == 0) && ((bVar11 & 1) == 0)) || (9 < *(sword *)(pbVar16 + 8))) {
      pbStack_44 = param_1;
      _m_freem();
      bVar11 = 0;
    }
    else if (((*(int *)(pbVar17 + 0x18) == *(int *)(pbVar16 + 0x40)) &&
             (pbVar16 == *(byte **)pbVar16)) && (*(sword *)(pbVar16 + 8) == 4)) {
      pbVar16[0x1b] = pbVar16[0x1b] | 2;
      *(int *)(pbVar16 + 0x40) = (int)*(sword *)(pbVar17 + 10) + *(int *)(pbVar16 + 0x40);
      bVar11 = pbVar17[0x21] & 1;
      dword_40BBD94 = dword_40BBD94 + 1;
      dword_40BBD98 = *(sword *)(pbVar17 + 10) + dword_40BBD98;
      pbStack_44 = param_1;
      _sbappend(unaff_D6 + 0x22);
      _sowakeup(unaff_D6,unaff_D6 + 0x22);
    }
    else {
      pbStack_44 = param_1;
      bVar11 = _tcp_reass(pbVar16,pbVar17);
      pbVar16[0x1b] = pbVar16[0x1b] | 1;
    }
    if ((bVar11 & 1) != 0) {
      if (*(sword *)(pbVar16 + 8) < 10) {
        pbStack_44 = unaff_D6;
        _socantrcvmore();
        pbVar16[0x1b] = pbVar16[0x1b] | 1;
        *(int *)(pbVar16 + 0x40) = *(int *)(pbVar16 + 0x40) + 1;
      }
      switch(*(undefined2 *)(pbVar16 + 8)) {
      case :
      case :
        pbVar16[8] = 0;
        pbVar16[9] = 5;
        break;
      case :
        pbVar16[8] = 0;
        pbVar16[9] = 7;
        break;
      case :
        pbVar16[8] = 0;
        pbVar16[9] = 10;
        pbStack_44 = pbVar16;
        _tcp_canceltimers();
        pbVar16[0x10] = 0;
        pbVar16[0x11] = 0x78;
        _soisdisconnected(unaff_D6);
        break;
      case :
        pbVar16[0x10] = 0;
        pbVar16[0x11] = 0x78;
      }
    }
    if ((unaff_D6[3] & 1) != 0) {
      pbStack_44 = (byte *)0x0;
      _tcp_trace(0,(int)sStack_e,pbVar16,&_tcp_saveti);
    }
    ppbVar18 = (byte **)&stack0xffffffc0;
    if ((!bVar4) && (ppbVar18 = (byte **)&stack0xffffffc0, (pbVar16[0x1b] & 1) == 0)) {
      return;
    }
loc_4023C90:
    *(byte **)((int)ppbVar18 + -4) = pbVar16;
    *(undefined4 *)((int)ppbVar18 + -8) = 0x4023c98;
    _tcp_output();
    return;
  }
  switch(*(undefined2 *)(pbVar16 + 8)) {
  case :
    unaff_D6[0x50] = 0;
    unaff_D6[0x51] = 0x3d;
    break;
  case :
  case :
  case :
  case :
    unaff_D6[0x50] = 0;
    unaff_D6[0x51] = 0x36;
    break;
  case :
  case :
  case :
    goto loc_40239C8;
  :
    goto loc_4023696;
  }
  pbVar16[8] = 0;
  pbVar16[9] = 0;
  dword_40BBD38 = dword_40BBD38 + 1;
loc_40239C8:
  pbStack_44 = pbVar16;
  pbVar16 = (byte *)_tcp_close();
loc_4023D06:
  if (pbStack_8 != (byte *)0x0) {
    pbStack_44 = pbStack_8;
    _m_free();
  }
  goto loc_4023D18;
}

