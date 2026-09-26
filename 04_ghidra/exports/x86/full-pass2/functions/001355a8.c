/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001355a8 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint _clntkudp_callit_addr
               (int *param_1,undefined4 param_2,code *param_3,undefined4 param_4,undefined4 param_5,
               undefined4 param_6,int param_7,int param_8,undefined4 *param_9)

{
  uint *puVar1;
  byte bVar2;
  uint *puVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  int iVar7;
  undefined4 uVar8;
  uint uVar9;
  int *piVar10;
  boolean_t bVar11;
  int iVar12;
  uint *puVar13;
  undefined4 uVar14;
  code *pcVar15;
  uint *puVar16;
  int iVar17;
  int local_68;
  int local_64;
  int local_5c;
  uint local_50;
  int local_4c;
  undefined4 local_38;
  int local_34;
  undefined4 local_30;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  
  puVar3 = (uint *)param_1[2];
  uVar4 = puVar3[5];
  local_50 = puVar3[4];
  local_64 = 0;
  local_68 = 2;
  iVar17 = *_active_u;
  __rcstat = __rcstat + 1;
  bVar2 = (byte)*puVar3;
  while ((bVar2 & 2) != 0) {
    _DAT_001ef1d4 = _DAT_001ef1d4 + 1;
    *(byte *)puVar3 = (byte)*puVar3 | 4;
    _sleep((uint)param_1);
    bVar2 = (byte)*puVar3;
  }
  uVar9 = *puVar3;
  *puVar3 = uVar9 | 2;
  if ((uVar9 & 0x20) != 0) {
    local_50 = 1;
  }
  _lock_write(_active_u + 8);
  iVar5 = _active_u[7];
  _active_u[7] = puVar3[0x1d];
  iVar7 = _clntkudpxid;
  _clntkudpxid = _clntkudpxid + 1;
  local_5c = (_hz * param_8) / 1000000 + _hz * param_7;
  do {
    uVar8 = _splimp();
    uVar9 = *puVar3;
    if ((uVar9 & 8) != 0) {
      puVar1 = puVar3 + 0x1a;
      do {
        *puVar3 = uVar9 | 0x10;
        pcVar15 = _wakeup;
        puVar16 = puVar1;
        iVar12 = _hz;
        _timeout(0x10ab38);
        uVar14 = 0x16;
        puVar13 = puVar1;
        _sleep((uint)puVar1);
        _sbflush(uVar4 + 0x24,puVar13,uVar14,pcVar15,puVar16,iVar12);
        uVar9 = *puVar3;
      } while ((uVar9 & 8) != 0);
    }
    *(byte *)puVar3 = (byte)*puVar3 | 8;
    _splx(uVar8);
    uVar9 = _mclgetx(FUN_00135d94,puVar3,puVar3[0x1a],0x2260,1);
    if (uVar9 == 0) {
      puVar3[10] = 0xc;
      puVar3[0xb] = 0x37;
      uVar9 = *puVar3;
      *puVar3 = uVar9 & 0xfffffff7;
      if ((uVar9 & 0x10) != 0) {
        *puVar3 = uVar9 & 0xffffffe7;
        _wakeup(puVar3 + 0x1a);
      }
    }
    else {
      puVar1 = puVar3 + 0xd;
      *(int *)puVar3[0x1a] = iVar7;
      _xdrmbuf_init(puVar1,uVar9,0);
      if (local_64 == 0) {
        (**(code **)(puVar3[0xe] + 0x14))(puVar1,puVar3[0x19]);
        iVar12 = (**(code **)(puVar3[0xe] + 4))(puVar1,&param_2);
        if (((iVar12 != 0) &&
            (iVar12 = (**(code **)(*(int *)(*param_1 + 0x20) + 4))(*param_1,puVar1), iVar12 != 0))
           && (iVar12 = (*param_3)(puVar1,param_4), iVar12 != 0)) {
          local_64 = (**(code **)(puVar3[0xe] + 0x10))(puVar1);
          goto LAB_001357b3;
        }
        puVar3[10] = 1;
        puVar3[0xb] = 5;
LAB_00135abd:
        _m_freem(uVar9);
      }
      else {
        (**(code **)(puVar3[0xe] + 0x14))(puVar1,local_64);
LAB_001357b3:
        *(undefined2 *)(uVar9 + 8) = (undefined2)local_64;
        uVar9 = _ku_sendto_mbuf(uVar4,uVar9,puVar3 + 6);
        puVar3[0xb] = uVar9;
        if (uVar9 == 0) {
          local_4c = 2;
          do {
            uVar8 = _splnet();
            while (*(short *)(uVar4 + 0x24) == 0) {
              _timeout(0x135c08);
              *(byte *)(uVar4 + 0x38) = *(byte *)(uVar4 + 0x38) | 4;
              if ((iVar17 == 0) || ((*puVar3 & 0x800) == 0)) {
                _sleep(uVar4 + 0x24);
                uVar9 = 0;
              }
              else {
                uVar6 = *(uint *)(iVar17 + 0x1c);
                *(uint *)(iVar17 + 0x1c) = uVar6 | 0xfffbbffa;
                uVar9 = _sleep(uVar4 + 0x24);
                *(uint *)(iVar17 + 0x1c) = uVar6;
              }
              _untimeout(_ckuwakeup,puVar3);
              if (uVar9 != 0) {
                _splx(uVar8);
                puVar3[10] = 0x12;
                puVar3[0xb] = 4;
                goto LAB_00135ac6;
              }
              if ((*puVar3 & 1) != 0) {
                *puVar3 = *puVar3 & 0xfffffffe;
                _splx(uVar8);
                puVar3[10] = 5;
                puVar3[0xb] = 0x3c;
                _DAT_001ef1d0 = _DAT_001ef1d0 + 1;
                goto LAB_00135ac6;
              }
            }
            if (*(short *)(uVar4 + 0x56) == 0) {
              uVar9 = _ku_recvfrom(uVar4,&local_14);
              puVar3[0x1c] = uVar9;
              if (param_9 != (undefined4 *)0x0) {
                *param_9 = local_14;
                param_9[1] = local_10;
                param_9[2] = local_c;
                param_9[3] = local_8;
              }
              _splx(uVar8);
              uVar9 = puVar3[0x1c];
              if (uVar9 != 0) {
                piVar10 = (int *)(uVar9 + *(int *)(uVar9 + 4));
                puVar3[0x1b] = (uint)piVar10;
                uVar9 = puVar3[0x1c];
                if (3 < *(ushort *)(uVar9 + 8)) {
                  if (*piVar10 == *(int *)puVar3[0x1a]) {
                    uVar8 = _splnet();
                    _sbflush(uVar4 + 0x24);
                    _splx(uVar8);
                    break;
                  }
                  _DAT_001ef1cc = _DAT_001ef1cc + 1;
                  uVar9 = puVar3[0x1c];
                }
                _m_freem(uVar9);
              }
            }
            else {
              *(undefined2 *)(uVar4 + 0x56) = 0;
              _splx(uVar8);
            }
            local_4c = local_4c + -1;
          } while (local_4c != 0);
          if (local_4c != 0) {
            _xdrmbuf_init(puVar3 + 0x13,puVar3[0x1c],1);
            local_38 = __null_auth;
            local_34 = DAT_001ef1b4;
            local_30 = DAT_001ef1b8;
            local_28 = param_6;
            local_24 = param_5;
            bVar11 = _xdr_replymsg();
            if (bVar11 == 0) {
              puVar3[10] = 2;
              puVar3[0xb] = 5;
            }
            else {
              __seterr_reply();
              if (puVar3[10] == 0) {
                iVar12 = (**(code **)(*(int *)(*param_1 + 0x20) + 8))(*param_1,&local_38);
                if (iVar12 == 0) {
                  puVar3[10] = 7;
                  puVar3[0xb] = 6;
                  _DAT_001ef1dc = _DAT_001ef1dc + 1;
                }
                if (local_34 != 0) {
                  puVar3[0x13] = 2;
                  _xdr_opaque_auth(puVar3 + 0x13,&local_38);
                }
              }
              else if ((0 < local_68) &&
                      (iVar12 = (**(code **)(*(int *)(*param_1 + 0x20) + 0xc))(*param_1),
                      iVar12 != 0)) {
                local_68 = local_68 + -1;
                _DAT_001ef1d8 = _DAT_001ef1d8 + 1;
                local_64 = 0;
              }
            }
            uVar9 = puVar3[0x1c];
            goto LAB_00135abd;
          }
          puVar3[10] = 4;
          puVar3[0xb] = 5;
        }
        else {
          puVar3[10] = 3;
        }
      }
    }
LAB_00135ac6:
    uVar9 = puVar3[10];
    if ((((uVar9 == 0) || (uVar9 == 0x12)) || (uVar9 == 1)) ||
       (local_50 = local_50 - 1, (int)local_50 < 1)) {
      _active_u[7] = iVar5;
      _lock_done(_active_u + 8);
      uVar8 = _splimp();
      uVar9 = *puVar3;
      if ((uVar9 & 8) != 0) {
        puVar1 = puVar3 + 0x1a;
        do {
          *puVar3 = uVar9 | 0x10;
          pcVar15 = _wakeup;
          puVar16 = puVar1;
          iVar17 = _hz;
          _timeout(0x10ab38);
          uVar14 = 0x16;
          puVar13 = puVar1;
          _sleep((uint)puVar1);
          _sbflush(uVar4 + 0x24,puVar13,uVar14,pcVar15,puVar16,iVar17);
          uVar9 = *puVar3;
        } while ((uVar9 & 8) != 0);
      }
      _splx(uVar8);
      uVar4 = *puVar3;
      *puVar3 = uVar4 & 0xfffffffd;
      if ((uVar4 & 4) != 0) {
        *puVar3 = uVar4 & 0xfffffff9;
        _wakeup(param_1);
      }
      if (puVar3[10] != 0) {
        _DAT_001ef1c4 = _DAT_001ef1c4 + 1;
      }
      return puVar3[10];
    }
    _DAT_001ef1c8 = _DAT_001ef1c8 + 1;
    iVar12 = local_5c * 2;
    local_5c = _hz * 0x3c;
    if (iVar12 <= _hz * 0x3c) {
      local_5c = iVar12;
    }
    if ((puVar3[10] == 0xc) || (puVar3[10] == 3)) {
      _sleep(0x1e8df0);
    }
  } while( true );
}

