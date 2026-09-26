/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00126058 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void _ipintr(void)

{
  int *piVar1;
  uint uVar2;
  short sVar3;
  ushort uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  int *piVar7;
  uint uVar8;
  int iVar9;
  int iVar10;
  uint uVar11;
  int *piVar12;
  undefined4 *puVar13;
  byte *pbVar14;
  short local_14;
  int local_c;
  int *local_8;
  
  local_c = 0;
LAB_00126068:
  do {
    while( true ) {
      uVar5 = _splimp();
      piVar12 = _ipintrq;
      piVar7 = piVar12;
      if (_ipintrq != (int *)0x0) {
        if ((int *)_ipintrq[0x1f] == (int *)0x0) {
          DAT_001eaa74 = 0;
        }
        piVar1 = _ipintrq + 0x1f;
        _ipintrq = (int *)_ipintrq[0x1f];
        *piVar1 = 0;
        DAT_001eaa78 = DAT_001eaa78 + -1;
        local_c = *(int *)(piVar12[1] + (int)piVar12);
        piVar12[1] = piVar12[1] + 4;
        sVar3 = (short)piVar12[2] + -4;
        *(short *)(piVar12 + 2) = sVar3;
        if (sVar3 == 0) {
          uVar6 = _splimp();
          if (*(short *)((int)piVar12 + 10) == 0) {
                    /* WARNING: Subroutine does not return */
            _panic(s_mfree_001dbda0);
          }
          *(short *)(&DAT_001e917c + *(short *)((int)piVar12 + 10) * 2) =
               *(short *)(&DAT_001e917c + *(short *)((int)piVar12 + 10) * 2) + -1;
          _DAT_001e917c = _DAT_001e917c + 1;
          *(undefined2 *)((int)piVar12 + 10) = 0;
          if (0x7f < (uint)piVar12[1]) {
            _mclput(piVar12);
          }
          piVar7 = (int *)*piVar12;
          *piVar12 = (int)_mfree;
          piVar12[1] = 0;
          piVar12[0x1f] = 0;
          _mfree = piVar12;
          _splx(uVar6);
          if (_m_want != 0) {
            _m_want = 0;
            _wakeup(&_mfree);
          }
        }
      }
      _splx(uVar5);
      if (piVar7 == (int *)0x0) {
        return;
      }
      if (_in_ifaddr != 0) break;
LAB_00126519:
      _m_freem(piVar7);
    }
    __ipstat = __ipstat + 1;
    if (((0x7c < (uint)piVar7[1]) || (*(ushort *)(piVar7 + 2) < 0x14)) &&
       (piVar7 = (int *)_m_pullup(piVar7,0x14), piVar7 == (int *)0x0)) {
      _DAT_001eaabc = _DAT_001eaabc + 1;
      goto LAB_00126068;
    }
    pbVar14 = (byte *)((int)piVar7 + piVar7[1]);
    uVar8 = (*pbVar14 & 0xf) * 4;
    if (uVar8 < 0x14) {
      _DAT_001eaac0 = _DAT_001eaac0 + 1;
      goto LAB_00126519;
    }
    if ((int)uVar8 <= (int)(short)piVar7[2]) {
LAB_001261f1:
      if (_ipcksum != '\0') {
        sVar3 = _in_cksum(piVar7,uVar8);
        *(short *)(pbVar14 + 10) = sVar3;
        if (sVar3 != 0) {
          _DAT_001eaab4 = _DAT_001eaab4 + 1;
          goto LAB_00126519;
        }
      }
      uVar4 = *(ushort *)(pbVar14 + 2) >> 8 | *(ushort *)(pbVar14 + 2) << 8;
      *(ushort *)(pbVar14 + 2) = uVar4;
      if ((int)(short)uVar4 < (int)uVar8) {
        _DAT_001eaac4 = _DAT_001eaac4 + 1;
        goto LAB_00126519;
      }
      *(ushort *)(pbVar14 + 4) = *(ushort *)(pbVar14 + 4) >> 8 | *(ushort *)(pbVar14 + 4) << 8;
      *(ushort *)(pbVar14 + 6) = *(ushort *)(pbVar14 + 6) >> 8 | *(ushort *)(pbVar14 + 6) << 8;
      iVar9 = (int)(short)piVar7[2] - (uint)*(ushort *)(pbVar14 + 2);
      iVar10 = *piVar7;
      piVar12 = piVar7;
      while (iVar10 != 0) {
        piVar12 = (int *)*piVar12;
        iVar9 = iVar9 + (short)piVar12[2];
        iVar10 = *piVar12;
      }
      local_8 = piVar7;
      if (iVar9 != 0) {
        if (iVar9 < 0) {
          _DAT_001eaab8 = _DAT_001eaab8 + 1;
          goto LAB_00126519;
        }
        if ((short)piVar12[2] < iVar9) {
          _m_adj(piVar7,-iVar9);
        }
        else {
          *(short *)(piVar12 + 2) = (short)piVar12[2] - (short)iVar9;
        }
      }
      piVar7 = local_8;
      _ip_nhops = 0;
      if ((uVar8 < 0x15) || (iVar10 = _ip_dooptions(pbVar14,local_c), iVar10 == 0)) {
        if ((((*(byte *)(local_c + 0xd) & 0x40) == 0) ||
            (((0x7c < (uint)piVar7[1] || (*(ushort *)(piVar7 + 2) < 0x1c)) &&
             (piVar7 = (int *)_m_pullup(piVar7,0x1c), piVar7 == (int *)0x0)))) ||
           ((*(char *)((int)piVar7 + piVar7[1] + 9) != '\x11' ||
            (*(short *)((int)piVar7 + piVar7[1] + 0x16) != 0x4400)))) {
          if (_in_ifaddr != 0) {
            uVar2 = *(uint *)(pbVar14 + 0x10);
            iVar10 = _in_ifaddr;
            do {
              if ((*(uint *)(iVar10 + 4) == uVar2) ||
                 (((*(byte *)(*(int *)(iVar10 + 0x20) + 0xc) & 2) != 0 &&
                  ((((*(uint *)(iVar10 + 0x14) == uVar2 || (*(uint *)(iVar10 + 0x38) == uVar2)) ||
                    (uVar11 = uVar2 >> 0x18 | (uVar2 & 0xff0000) >> 8 | (uVar2 & 0xff00) << 8 |
                              uVar2 << 0x18, *(uint *)(iVar10 + 0x30) == uVar11)) ||
                   (*(uint *)(iVar10 + 0x28) == uVar11)))))) goto LAB_00126428;
              iVar10 = *(int *)(iVar10 + 0x40);
            } while (iVar10 != 0);
          }
          uVar2 = *(uint *)(pbVar14 + 0x10);
          if ((uVar2 & 0xf0) == 0xe0) {
            if (_ip_mrouter != 0) {
              *(ushort *)(pbVar14 + 4) =
                   *(ushort *)(pbVar14 + 4) >> 8 | *(ushort *)(pbVar14 + 4) << 8;
              iVar10 = _ip_mforward(pbVar14,local_c);
              if (iVar10 != 0) {
                piVar7 = (int *)((uint)pbVar14 & 0xffffff80);
                goto LAB_00126519;
              }
              *(ushort *)(pbVar14 + 4) =
                   *(ushort *)(pbVar14 + 4) >> 8 | *(ushort *)(pbVar14 + 4) << 8;
              if (pbVar14[9] == 2) goto LAB_00126428;
            }
            iVar10 = _in_ifaddr;
            if (_in_ifaddr != 0) {
              do {
                if (*(int *)(iVar10 + 0x20) == local_c) break;
                iVar10 = *(int *)(iVar10 + 0x40);
              } while (iVar10 != 0);
              if ((iVar10 != 0) && (piVar12 = *(int **)(iVar10 + 0x44), piVar12 != (int *)0x0)) {
                do {
                  if (*piVar12 == *(int *)(pbVar14 + 0x10)) break;
                  piVar12 = (int *)piVar12[5];
                } while (piVar12 != (int *)0x0);
                if (piVar12 != (int *)0x0) goto LAB_00126428;
              }
            }
            piVar7 = (int *)((uint)pbVar14 & 0xffffff80);
            goto LAB_00126519;
          }
          if ((uVar2 != 0xffffffff) && (uVar2 != 0)) {
            _ip_forward(pbVar14,local_c);
            goto LAB_00126068;
          }
        }
LAB_00126428:
        local_14 = (short)uVar8;
        if ((*(ushort *)(pbVar14 + 6) & 0xbfff) == 0) {
          *(short *)(pbVar14 + 2) = *(short *)(pbVar14 + 2) - local_14;
        }
        else {
          if ((undefined4 **)_ipq != &_ipq) {
            puVar13 = _ipq;
            do {
              if ((((*(short *)((int)puVar13 + 10) == *(short *)(pbVar14 + 4)) &&
                   (*(int *)(pbVar14 + 0xc) == puVar13[5])) &&
                  (*(int *)(pbVar14 + 0x10) == puVar13[6])) &&
                 (pbVar14[9] == *(byte *)((int)puVar13 + 9))) goto LAB_00126472;
              puVar13 = (undefined4 *)*puVar13;
            } while ((undefined4 **)puVar13 != &_ipq);
          }
          puVar13 = (undefined4 *)0x0;
LAB_00126472:
          *(short *)(pbVar14 + 2) = *(short *)(pbVar14 + 2) - local_14;
          pbVar14[1] = 0;
          if ((pbVar14[7] & 0x20) != 0) {
            pbVar14[1] = 1;
          }
          uVar4 = *(ushort *)(pbVar14 + 6);
          *(ushort *)(pbVar14 + 6) = uVar4 << 3;
          if ((pbVar14[1] == 0) && ((uVar4 & 0x1fff) == 0)) {
            if (puVar13 != (undefined4 *)0x0) {
              _ip_freef(puVar13);
            }
          }
          else {
            _DAT_001eaac8 = _DAT_001eaac8 + 1;
            pbVar14 = (byte *)_ip_reass(pbVar14,puVar13);
            if (pbVar14 == (byte *)0x0) goto LAB_00126068;
            piVar7 = (int *)((uint)pbVar14 & 0xffffff80);
          }
        }
        local_8 = piVar7;
        iVar10 = _receive_ip_datagram(&local_8);
        if (iVar10 == 0) {
          (**(code **)(&DAT_001dbb70 + (uint)(byte)(&_ip_protox)[pbVar14[9]] * 0x30))
                    (local_8,local_c);
        }
      }
      goto LAB_00126068;
    }
    piVar7 = (int *)_m_pullup(piVar7,uVar8);
    if (piVar7 != (int *)0x0) {
      pbVar14 = (byte *)((int)piVar7 + piVar7[1]);
      goto LAB_001261f1;
    }
    _DAT_001eaac0 = _DAT_001eaac0 + 1;
  } while( true );
}

