
uint _clntkudp_callit_addr
               (int *param_1,undefined4 param_2,code *param_3,undefined4 param_4,undefined4 param_5,
               undefined4 param_6,int param_7,int param_8,undefined4 *param_9)

{
  uint *puVar1;
  uint uVar2;
  uint uVar3;
  short sVar4;
  byte bVar5;
  uint *puVar6;
  int *piVar7;
  int iVar8;
  int iVar9;
  uint uVar10;
  boolean_t bVar11;
  int iVar12;
  int iVar13;
  uint *puVar14;
  undefined4 uVar15;
  undefined4 uVar16;
  code *pcVar17;
  uint *puVar18;
  int iVar19;
  int local_58;
  int local_54;
  uint local_48;
  undefined4 local_38;
  int local_34;
  undefined4 local_30;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  
  iVar9 = param_8;
  iVar13 = param_7;
  puVar1 = (uint *)param_1[2];
  uVar2 = puVar1[5];
  local_48 = puVar1[4];
  iVar12 = 0;
  local_54 = 2;
  iVar19 = *_active_u;
  _rcstat = _rcstat + 1;
  bVar5 = (byte)*puVar1;
  while ((bVar5 & 2) != 0) {
    DAT_040bc148 = DAT_040bc148 + 1;
    *puVar1 = *puVar1 | 4;
    _sleep((uint)param_1);
    bVar5 = (byte)*puVar1;
  }
  uVar10 = *puVar1;
  *puVar1 = uVar10 | 2;
  if ((uVar10 & 0x20) != 0) {
    local_48 = 1;
  }
  _lock_write((int)_active_u + 0x1e);
  uVar16 = *(undefined4 *)((int)_active_u + 0x1a);
  *(uint *)((int)_active_u + 0x1a) = puVar1[0x1d];
  iVar8 = _clntkudpxid;
  _clntkudpxid = _clntkudpxid + 1;
  local_58 = (iVar9 * _hz) / 1000000 + iVar13 * _hz;
  do {
    uVar10 = *puVar1;
    if ((uVar10 & 8) != 0) {
      puVar6 = puVar1 + 0x1a;
      do {
        *puVar1 = uVar10 | 0x10;
        pcVar17 = _wakeup;
        puVar18 = puVar6;
        iVar13 = _hz;
        _timeout(0x400a202);
        uVar15 = 0x16;
        puVar14 = puVar6;
        _sleep((uint)puVar6);
        _sbflush(uVar2 + 0x22,puVar14,uVar15,pcVar17,puVar18,iVar13);
        uVar10 = *puVar1;
      } while ((uVar10 & 8) != 0);
    }
    *puVar1 = *puVar1 | 8;
    uVar10 = _mclgetx(FUN_0402dc60,puVar1,puVar1[0x1a],0x2260,1);
    if (uVar10 == 0) {
      puVar1[10] = 0xc;
      puVar1[0xb] = 0x37;
      FUN_0402dc60(puVar1);
    }
    else {
      puVar6 = puVar1 + 0xd;
      *(int *)puVar1[0x1a] = iVar8;
      _xdrmbuf_init(puVar6,uVar10,0);
      if (iVar12 == 0) {
        (**(code **)(puVar1[0xe] + 0x14))(puVar6,puVar1[0x19]);
        iVar13 = (**(code **)(puVar1[0xe] + 4))(puVar6,&param_2);
        if (((iVar13 != 0) &&
            (iVar13 = (**(code **)(*(int *)(*param_1 + 0x20) + 4))(*param_1,puVar6), iVar13 != 0))
           && (iVar13 = (*param_3)(puVar6,param_4), iVar13 != 0)) {
          iVar12 = (**(code **)(puVar1[0xe] + 0x10))(puVar6);
          goto LAB_0402e0a8;
        }
        puVar1[10] = 1;
        puVar1[0xb] = 5;
LAB_0402e350:
        _m_freem(uVar10);
      }
      else {
        (**(code **)(puVar1[0xe] + 0x14))(puVar6,iVar12);
LAB_0402e0a8:
        *(short *)(uVar10 + 8) = (short)iVar12;
        uVar10 = _ku_sendto_mbuf(uVar2,uVar10,puVar1 + 6);
        puVar1[0xb] = uVar10;
        if (uVar10 == 0) {
          iVar13 = 2;
          do {
            sVar4 = *(short *)(uVar2 + 0x22);
            while (sVar4 == 0) {
              _timeout(0x402e49c);
              *(ushort *)(uVar2 + 0x36) = *(ushort *)(uVar2 + 0x36) | 4;
              if ((iVar19 == 0) || ((*puVar1 & 0x800) == 0)) {
                uVar10 = 0;
                _sleep(uVar2 + 0x22);
              }
              else {
                uVar3 = *(uint *)(iVar19 + 0x1c);
                *(uint *)(iVar19 + 0x1c) = uVar3 | 0xfffbbffa;
                uVar10 = _sleep(uVar2 + 0x22);
                *(uint *)(iVar19 + 0x1c) = uVar3;
              }
              _untimeout(_ckuwakeup,puVar1);
              if (uVar10 != 0) {
                puVar1[10] = 0x12;
                puVar1[0xb] = 4;
                goto LAB_0402e358;
              }
              if ((*puVar1 & 1) != 0) {
                *puVar1 = *puVar1 & 0xfffffffe;
                puVar1[10] = 5;
                puVar1[0xb] = 0x3c;
                DAT_040bc144 = DAT_040bc144 + 1;
                goto LAB_0402e358;
              }
              sVar4 = *(short *)(uVar2 + 0x22);
            }
            if (*(short *)(uVar2 + 0x50) == 0) {
              uVar10 = _ku_recvfrom(uVar2,&local_14);
              puVar1[0x1c] = uVar10;
              if (param_9 != (undefined4 *)0x0) {
                *param_9 = local_14;
                param_9[1] = local_10;
                param_9[2] = local_c;
                param_9[3] = local_8;
              }
              uVar10 = puVar1[0x1c];
              if (uVar10 != 0) {
                piVar7 = (int *)(*(int *)(uVar10 + 4) + uVar10);
                puVar1[0x1b] = (uint)piVar7;
                uVar10 = puVar1[0x1c];
                if (3 < *(ushort *)(uVar10 + 8)) {
                  if (*piVar7 == *(int *)puVar1[0x1a]) {
                    _sbflush(uVar2 + 0x22);
                    break;
                  }
                  DAT_040bc140 = DAT_040bc140 + 1;
                  uVar10 = puVar1[0x1c];
                }
                _m_freem(uVar10);
              }
            }
            else {
              *(undefined2 *)(uVar2 + 0x50) = 0;
            }
            iVar13 = iVar13 + -1;
          } while (iVar13 != 0);
          if (iVar13 != 0) {
            puVar6 = puVar1 + 0x13;
            _xdrmbuf_init(puVar6,puVar1[0x1c],1);
            local_38 = __null_auth;
            local_34 = DAT_040bc128;
            local_30 = DAT_040bc12c;
            local_28 = param_6;
            local_24 = param_5;
            bVar11 = _xdr_replymsg();
            if (bVar11 == 0) {
              puVar1[10] = 2;
              puVar1[0xb] = 5;
            }
            else {
              __seterr_reply();
              if (puVar1[10] == 0) {
                iVar13 = (**(code **)(*(int *)(*param_1 + 0x20) + 8))(*param_1,&local_38);
                if (iVar13 == 0) {
                  puVar1[10] = 7;
                  puVar1[0xb] = 6;
                  DAT_040bc150 = DAT_040bc150 + 1;
                }
                if (local_34 != 0) {
                  *puVar6 = 2;
                  _xdr_opaque_auth(puVar6,&local_38);
                }
              }
              else if ((0 < local_54) &&
                      (iVar13 = (**(code **)(*(int *)(*param_1 + 0x20) + 0xc))(*param_1),
                      iVar13 != 0)) {
                local_54 = local_54 + -1;
                DAT_040bc14c = DAT_040bc14c + 1;
                iVar12 = 0;
              }
            }
            uVar10 = puVar1[0x1c];
            goto LAB_0402e350;
          }
          puVar1[10] = 4;
          puVar1[0xb] = 5;
        }
        else {
          puVar1[10] = 3;
        }
      }
    }
LAB_0402e358:
    uVar10 = puVar1[10];
    if ((((uVar10 == 0) || (uVar10 == 0x12)) || (uVar10 == 1)) ||
       (local_48 = local_48 - 1, (int)local_48 < 1)) {
      *(undefined4 *)((int)_active_u + 0x1a) = uVar16;
      _lock_done((int)_active_u + 0x1e);
      uVar10 = *puVar1;
      if ((uVar10 & 8) != 0) {
        puVar6 = puVar1 + 0x1a;
        do {
          *puVar1 = uVar10 | 0x10;
          pcVar17 = _wakeup;
          puVar18 = puVar6;
          iVar19 = _hz;
          _timeout(0x400a202);
          uVar16 = 0x16;
          puVar14 = puVar6;
          _sleep((uint)puVar6);
          _sbflush(uVar2 + 0x22,puVar14,uVar16,pcVar17,puVar18,iVar19);
          uVar10 = *puVar1;
        } while ((uVar10 & 8) != 0);
      }
      uVar2 = *puVar1;
      *puVar1 = uVar2 & 0xfffffffd;
      if ((uVar2 & 4) != 0) {
        *puVar1 = uVar2 & 0xfffffff9;
        _wakeup(param_1);
      }
      if (puVar1[10] != 0) {
        DAT_040bc138 = DAT_040bc138 + 1;
      }
      return puVar1[10];
    }
    DAT_040bc13c = DAT_040bc13c + 1;
    iVar13 = local_58 * 2;
    local_58 = _hz * 0x3c;
    if (iVar13 <= _hz * 0x3c) {
      local_58 = iVar13;
    }
    if ((puVar1[10] == 0xc) || (puVar1[10] == 3)) {
      _sleep(0x40b5dc4);
    }
  } while( true );
}

