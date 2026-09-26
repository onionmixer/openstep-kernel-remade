/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001260db */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Synthetic analysis entry; not a reconstructed ABI function. Role=noreturn_fallthrough_fragment.
   Context recorded in gap-actions.json. */

void __analysis_fragment_001260db(void)

{
  int *piVar1;
  uint uVar2;
  short sVar3;
  ushort uVar4;
  undefined4 uVar5;
  int *piVar6;
  uint uVar7;
  int iVar8;
  int iVar9;
  uint uVar10;
  undefined4 *puVar11;
  int *unaff_EBX;
  int unaff_EBP;
  byte *pbVar12;
  
  do {
    *(short *)(&DAT_001e917c + *(short *)((int)unaff_EBX + 10) * 2) =
         *(short *)(&DAT_001e917c + *(short *)((int)unaff_EBX + 10) * 2) + -1;
    _DAT_001e917c = _DAT_001e917c + 1;
    *(undefined2 *)((int)unaff_EBX + 10) = 0;
    if (0x7f < (uint)unaff_EBX[1]) {
      _mclput();
    }
    piVar6 = (int *)*unaff_EBX;
    *unaff_EBX = (int)_mfree;
    unaff_EBX[1] = 0;
    unaff_EBX[0x1f] = 0;
    _mfree = unaff_EBX;
    _splx();
    if (_m_want != 0) {
      _m_want = 0;
      _wakeup();
    }
    do {
      do {
        _splx();
        if (piVar6 == (int *)0x0) {
          return;
        }
        if (_in_ifaddr == 0) {
LAB_00126519:
          _m_freem();
        }
        else {
          __ipstat = __ipstat + 1;
          if ((((uint)piVar6[1] < 0x7d) && (0x13 < *(ushort *)(piVar6 + 2))) ||
             (piVar6 = (int *)_m_pullup(piVar6), piVar6 != (int *)0x0)) {
            pbVar12 = (byte *)((int)piVar6 + piVar6[1]);
            uVar7 = (*pbVar12 & 0xf) * 4;
            *(uint *)(unaff_EBP + -0x10) = uVar7;
            if (uVar7 < 0x14) {
              _DAT_001eaac0 = _DAT_001eaac0 + 1;
            }
            else {
              if ((int)(short)piVar6[2] < *(int *)(unaff_EBP + -0x10)) {
                piVar6 = (int *)_m_pullup(piVar6);
                if (piVar6 == (int *)0x0) {
                  _DAT_001eaac0 = _DAT_001eaac0 + 1;
                  goto LAB_00126068;
                }
                pbVar12 = (byte *)((int)piVar6 + piVar6[1]);
              }
              if (_ipcksum != '\0') {
                sVar3 = _in_cksum(piVar6);
                *(short *)(pbVar12 + 10) = sVar3;
                if (sVar3 != 0) {
                  _DAT_001eaab4 = _DAT_001eaab4 + 1;
                  goto LAB_00126519;
                }
              }
              uVar4 = *(ushort *)(pbVar12 + 2) >> 8 | *(ushort *)(pbVar12 + 2) << 8;
              *(ushort *)(pbVar12 + 2) = uVar4;
              if (*(int *)(unaff_EBP + -0x10) <= (int)(short)uVar4) {
                *(ushort *)(pbVar12 + 4) =
                     *(ushort *)(pbVar12 + 4) >> 8 | *(ushort *)(pbVar12 + 4) << 8;
                *(ushort *)(pbVar12 + 6) =
                     *(ushort *)(pbVar12 + 6) >> 8 | *(ushort *)(pbVar12 + 6) << 8;
                uVar4 = *(ushort *)(pbVar12 + 2);
                *(int **)(unaff_EBP + -4) = piVar6;
                iVar8 = (int)(short)piVar6[2] - (uint)uVar4;
                iVar9 = *piVar6;
                while (iVar9 != 0) {
                  piVar6 = (int *)*piVar6;
                  iVar8 = iVar8 + (short)piVar6[2];
                  iVar9 = *piVar6;
                }
                if (iVar8 != 0) {
                  if (iVar8 < 0) {
                    _DAT_001eaab8 = _DAT_001eaab8 + 1;
                    goto LAB_00126519;
                  }
                  if ((short)piVar6[2] < iVar8) {
                    _m_adj(*(undefined4 *)(unaff_EBP + -4));
                  }
                  else {
                    *(short *)(piVar6 + 2) = (short)piVar6[2] - (short)iVar8;
                  }
                }
                uVar7 = *(uint *)(unaff_EBP + -4);
                _ip_nhops = 0;
                if ((*(uint *)(unaff_EBP + -0x10) < 0x15) ||
                   (iVar9 = _ip_dooptions(pbVar12), iVar9 == 0)) {
                  if ((((*(byte *)(*(int *)(unaff_EBP + -8) + 0xd) & 0x40) == 0) ||
                      (((0x7c < *(uint *)(uVar7 + 4) || (*(ushort *)(uVar7 + 8) < 0x1c)) &&
                       (uVar7 = _m_pullup(uVar7), uVar7 == 0)))) ||
                     ((iVar9 = uVar7 + *(int *)(uVar7 + 4), *(char *)(iVar9 + 9) != '\x11' ||
                      (*(short *)(iVar9 + 0x16) != 0x4400)))) {
                    if (_in_ifaddr != 0) {
                      uVar2 = *(uint *)(pbVar12 + 0x10);
                      iVar9 = _in_ifaddr;
                      do {
                        if ((*(uint *)(iVar9 + 4) == uVar2) ||
                           (((*(byte *)(*(int *)(iVar9 + 0x20) + 0xc) & 2) != 0 &&
                            ((((*(uint *)(iVar9 + 0x14) == uVar2 ||
                               (*(uint *)(iVar9 + 0x38) == uVar2)) ||
                              (uVar10 = uVar2 >> 0x18 | (uVar2 & 0xff0000) >> 8 |
                                        (uVar2 & 0xff00) << 8 | uVar2 << 0x18,
                              *(uint *)(iVar9 + 0x30) == uVar10)) ||
                             (*(uint *)(iVar9 + 0x28) == uVar10)))))) goto LAB_00126428;
                        iVar9 = *(int *)(iVar9 + 0x40);
                      } while (iVar9 != 0);
                    }
                    uVar2 = *(uint *)(pbVar12 + 0x10);
                    if ((uVar2 & 0xf0) == 0xe0) {
                      if (_ip_mrouter != 0) {
                        *(ushort *)(pbVar12 + 4) =
                             *(ushort *)(pbVar12 + 4) >> 8 | *(ushort *)(pbVar12 + 4) << 8;
                        iVar9 = _ip_mforward(pbVar12);
                        if (iVar9 != 0) goto LAB_00126519;
                        *(ushort *)(pbVar12 + 4) =
                             *(ushort *)(pbVar12 + 4) >> 8 | *(ushort *)(pbVar12 + 4) << 8;
                        if (pbVar12[9] == 2) goto LAB_00126428;
                      }
                      iVar9 = _in_ifaddr;
                      if (_in_ifaddr != 0) {
                        do {
                          if (*(int *)(iVar9 + 0x20) == *(int *)(unaff_EBP + -8)) break;
                          iVar9 = *(int *)(iVar9 + 0x40);
                        } while (iVar9 != 0);
                        if ((iVar9 != 0) && (piVar6 = *(int **)(iVar9 + 0x44), piVar6 != (int *)0x0)
                           ) {
                          do {
                            if (*piVar6 == *(int *)(pbVar12 + 0x10)) break;
                            piVar6 = (int *)piVar6[5];
                          } while (piVar6 != (int *)0x0);
                          if (piVar6 != (int *)0x0) goto LAB_00126428;
                        }
                      }
                      goto LAB_00126519;
                    }
                    if ((uVar2 != 0xffffffff) && (uVar2 != 0)) {
                      _ip_forward(pbVar12);
                      goto LAB_00126068;
                    }
                  }
LAB_00126428:
                  if ((*(ushort *)(pbVar12 + 6) & 0xbfff) == 0) {
                    *(short *)(pbVar12 + 2) =
                         *(short *)(pbVar12 + 2) - *(short *)(unaff_EBP + -0x10);
                  }
                  else {
                    if ((undefined4 **)_ipq != &_ipq) {
                      puVar11 = _ipq;
                      do {
                        if ((((*(short *)((int)puVar11 + 10) == *(short *)(pbVar12 + 4)) &&
                             (*(int *)(pbVar12 + 0xc) == puVar11[5])) &&
                            (*(int *)(pbVar12 + 0x10) == puVar11[6])) &&
                           (pbVar12[9] == *(byte *)((int)puVar11 + 9))) goto LAB_00126472;
                        puVar11 = (undefined4 *)*puVar11;
                      } while ((undefined4 **)puVar11 != &_ipq);
                    }
                    puVar11 = (undefined4 *)0x0;
LAB_00126472:
                    *(short *)(pbVar12 + 2) =
                         *(short *)(pbVar12 + 2) - *(short *)(unaff_EBP + -0x10);
                    pbVar12[1] = 0;
                    if ((pbVar12[7] & 0x20) != 0) {
                      pbVar12[1] = 1;
                    }
                    uVar4 = *(ushort *)(pbVar12 + 6);
                    *(ushort *)(pbVar12 + 6) = uVar4 << 3;
                    if ((pbVar12[1] == 0) && ((uVar4 & 0x1fff) == 0)) {
                      if (puVar11 != (undefined4 *)0x0) {
                        _ip_freef();
                      }
                    }
                    else {
                      _DAT_001eaac8 = _DAT_001eaac8 + 1;
                      pbVar12 = (byte *)_ip_reass(pbVar12);
                      if (pbVar12 == (byte *)0x0) goto LAB_00126068;
                      uVar7 = (uint)pbVar12 & 0xffffff80;
                    }
                  }
                  *(uint *)(unaff_EBP + -4) = uVar7;
                  iVar9 = _receive_ip_datagram();
                  if (iVar9 == 0) {
                    (**(code **)(&DAT_001dbb70 + (uint)(byte)(&_ip_protox)[pbVar12[9]] * 0x30))
                              (*(undefined4 *)(unaff_EBP + -4));
                  }
                }
                goto LAB_00126068;
              }
              _DAT_001eaac4 = _DAT_001eaac4 + 1;
            }
            goto LAB_00126519;
          }
          _DAT_001eaabc = _DAT_001eaabc + 1;
        }
LAB_00126068:
        uVar5 = _splimp();
        *(undefined4 *)(unaff_EBP + -0xc) = uVar5;
        piVar6 = _ipintrq;
      } while (_ipintrq == (int *)0x0);
      if ((int *)_ipintrq[0x1f] == (int *)0x0) {
        DAT_001eaa74 = 0;
      }
      piVar1 = _ipintrq + 0x1f;
      _ipintrq = (int *)_ipintrq[0x1f];
      *piVar1 = 0;
      DAT_001eaa78 = DAT_001eaa78 + -1;
      iVar9 = piVar6[1];
      *(undefined4 *)(unaff_EBP + -8) = *(undefined4 *)(iVar9 + (int)piVar6);
      piVar6[1] = iVar9 + 4;
      sVar3 = (short)piVar6[2] + -4;
      *(short *)(piVar6 + 2) = sVar3;
    } while (sVar3 != 0);
    uVar5 = _splimp();
    *(undefined4 *)(unaff_EBP + -0x10) = uVar5;
    unaff_EBX = piVar6;
    if (*(short *)((int)piVar6 + 10) == 0) {
                    /* WARNING: Subroutine does not return */
      _panic(s_mfree_001dbda0);
    }
  } while( true );
}

