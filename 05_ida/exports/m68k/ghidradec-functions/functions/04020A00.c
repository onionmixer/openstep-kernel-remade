
undefined4 _ipintr(void)

{
  int *piVar1;
  int *piVar2;
  uint uVar3;
  uint uVar4;
  undefined2 uVar5;
  undefined2 extraout_D0u;
  int in_D0;
  int *piVar6;
  sword sVar8;
  int iVar7;
  int iVar9;
  int *piVar10;
  undefined4 *puVar11;
  byte *pbVar12;
  int iVar13;
  char cVar14;
  char cVar15;
  char cVar16;
  char cVar17;
  byte bVar18;
  int *piStack_8;
  
  iVar13 = 0;
loc_4020A0A:
  do {
    while( true ) {
      piVar10 = _ipintrq;
      uVar5 = (undefined2)((uint)in_D0 >> 0x10);
      cVar14 = '\0';
      cVar17 = '\0';
      bVar18 = 0;
      cVar15 = (int)_ipintrq < 0;
      cVar16 = _ipintrq == (int *)0x0;
      piVar6 = piVar10;
      if (!(bool)cVar16) {
        piVar2 = (int *)_ipintrq[0x1f];
        if (piVar2 == (int *)0x0) {
          dword_40B7BBC = 0;
        }
        piVar1 = _ipintrq + 0x1f;
        _ipintrq = piVar2;
        *piVar1 = 0;
        dword_40B7BC0 = dword_40B7BC0 + -1;
        iVar13 = *(int *)(piVar10[1] + (int)piVar10);
        piVar10[1] = piVar10[1] + 4;
        uVar5 = (undefined2)((uint)piVar2 >> 0x10);
        cVar14 = *(word *)(piVar10 + 2) < 4;
        sVar8 = *(word *)(piVar10 + 2) - 4;
        *(sword *)(piVar10 + 2) = sVar8;
        cVar15 = sVar8 < 0;
        cVar17 = '\0';
        bVar18 = 0;
        cVar16 = '\0';
        if (sVar8 == 0) {
          if (*(sword *)((int)piVar10 + 10) == 0) {
                    /* WARNING: Subroutine does not return */
            _panic(&aMfree);
          }
          (&word_40B61CC)[*(sword *)((int)piVar10 + 10)] =
               (&word_40B61CC)[*(sword *)((int)piVar10 + 10)] + -1;
          word_40B61CC = word_40B61CC + 1;
          *(undefined2 *)((int)piVar10 + 10) = 0;
          if (0x7f < (uint)piVar10[1]) {
            _mclput(piVar10);
          }
          piVar6 = (int *)*piVar10;
          *piVar10 = (int)_mfree;
          piVar10[1] = 0;
          piVar10[0x1f] = 0;
          _mfree = piVar10;
          uVar5 = 0;
          cVar17 = '\0';
          bVar18 = 0;
          cVar15 = _m_want < 0;
          cVar16 = _m_want == 0;
          if (!(bool)cVar16) {
            _m_want = 0;
            cVar15 = '\0';
            cVar16 = '\x01';
            cVar17 = '\0';
            bVar18 = 0;
            _wakeup(&_mfree);
            uVar5 = extraout_D0u;
          }
        }
      }
      if (piVar6 == (int *)0x0) {
        return CONCAT22(uVar5,(word)(byte)(cVar14 << 4 | cVar15 << 3 | cVar16 << 2 | cVar17 << 1 |
                                          bVar18));
      }
      if (_in_ifaddr != 0) break;
loc_4020E38:
      in_D0 = _m_freem(piVar6);
    }
    _ipstat = _ipstat + 1;
    if (((0x7c < (uint)piVar6[1]) || (*(word *)(piVar6 + 2) < 0x14)) &&
       (piVar6 = (int *)_m_pullup(piVar6,0x14), piVar6 == (int *)0x0)) {
      dword_40B68AC = dword_40B68AC + 1;
      in_D0 = 0;
      goto loc_4020A0A;
    }
    pbVar12 = (byte *)(piVar6[1] + (int)piVar6);
    uVar4 = (*pbVar12 & 0xf) * 4;
    if (uVar4 < 0x14) {
      dword_40B68B0 = dword_40B68B0 + 1;
      goto loc_4020E38;
    }
    if ((int)uVar4 <= (int)*(sword *)(piVar6 + 2)) {
loc_4020B62:
      if (_ipcksum != '\0') {
        sVar8 = _in_cksum(piVar6,uVar4);
        *(sword *)(pbVar12 + 10) = sVar8;
        if (sVar8 != 0) {
          dword_40B68A4 = dword_40B68A4 + 1;
          goto loc_4020E38;
        }
      }
      if ((int)*(sword *)(pbVar12 + 2) < (int)uVar4) {
        dword_40B68B4 = dword_40B68B4 + 1;
        goto loc_4020E38;
      }
      iVar9 = (int)*(sword *)(piVar6 + 2) - (uint)*(word *)(pbVar12 + 2);
      iVar7 = *piVar6;
      piVar10 = piVar6;
      while (iVar7 != 0) {
        piVar10 = (int *)*piVar10;
        iVar9 = *(sword *)(piVar10 + 2) + iVar9;
        iVar7 = *piVar10;
      }
      piStack_8 = piVar6;
      if (iVar9 != 0) {
        if (iVar9 < 0) {
          dword_40B68A8 = dword_40B68A8 + 1;
          goto loc_4020E38;
        }
        if (*(sword *)(piVar10 + 2) < iVar9) {
          _m_adj(piVar6,-iVar9);
        }
        else {
          *(sword *)(piVar10 + 2) = *(sword *)(piVar10 + 2) - (sword)iVar9;
        }
      }
      piVar6 = piStack_8;
      _ip_nhops = 0;
      if ((uVar4 < 0x15) || (in_D0 = _ip_dooptions(pbVar12,iVar13), in_D0 == 0)) {
        if ((((*(byte *)(iVar13 + 0xc) & 0x40) == 0) ||
            (((0x7c < (uint)piVar6[1] || (*(word *)(piVar6 + 2) < 0x1c)) &&
             (piVar6 = (int *)_m_pullup(piVar6,0x1c), piVar6 == (int *)0x0)))) ||
           ((*(char *)((int)piVar6 + piVar6[1] + 9) != '\x11' ||
            (*(sword *)((int)piVar6 + piVar6[1] + 0x16) != 0x44)))) {
          if (_in_ifaddr != 0) {
            iVar7 = *(int *)(pbVar12 + 0x10);
            iVar9 = _in_ifaddr;
            do {
              if ((iVar7 == *(int *)(iVar9 + 4)) ||
                 (((*(byte *)(*(int *)(iVar9 + 0x20) + 0xd) & 2) != 0 &&
                  ((((iVar7 == *(int *)(iVar9 + 0x14) || (iVar7 == *(int *)(iVar9 + 0x38))) ||
                    (iVar7 == *(int *)(iVar9 + 0x30))) || (iVar7 == *(int *)(iVar9 + 0x28)))))))
              goto loc_4020D3E;
              iVar9 = *(int *)(iVar9 + 0x40);
            } while (iVar9 != 0);
          }
          uVar3 = *(uint *)(pbVar12 + 0x10);
          if ((uVar3 & 0xf0000000) == 0xe0000000) {
            if (_ip_mrouter != 0) {
              iVar7 = _ip_mforward(pbVar12,iVar13);
              if (iVar7 != 0) {
                piVar6 = (int *)((uint)pbVar12 & 0xffffff80);
                goto loc_4020E38;
              }
              if (pbVar12[9] == 2) goto loc_4020D3E;
            }
            iVar7 = _in_ifaddr;
            if (_in_ifaddr != 0) {
              do {
                if (iVar13 == *(int *)(iVar7 + 0x20)) break;
                iVar7 = *(int *)(iVar7 + 0x40);
              } while (iVar7 != 0);
              if ((iVar7 != 0) && (piVar10 = *(int **)(iVar7 + 0x44), piVar10 != (int *)0x0)) {
                do {
                  if (*(int *)(pbVar12 + 0x10) == *piVar10) break;
                  piVar10 = (int *)piVar10[5];
                } while (piVar10 != (int *)0x0);
                if (piVar10 != (int *)0x0) goto loc_4020D3E;
              }
            }
            piVar6 = (int *)((uint)pbVar12 & 0xffffff80);
            goto loc_4020E38;
          }
          if ((uVar3 != 0xffffffff) && (uVar3 != 0)) {
            in_D0 = _ip_forward(pbVar12,iVar13);
            goto loc_4020A0A;
          }
        }
loc_4020D3E:
        if ((*(word *)(pbVar12 + 6) & 0xbfff) == 0) {
          *(sword *)(pbVar12 + 2) = *(sword *)(pbVar12 + 2) - (sword)uVar4;
        }
        else {
          if ((undefined4 **)_ipq != &_ipq) {
            puVar11 = _ipq;
            do {
              if ((((*(sword *)(pbVar12 + 4) == *(sword *)((int)puVar11 + 10)) &&
                   (*(int *)(pbVar12 + 0xc) == puVar11[5])) &&
                  (*(int *)(pbVar12 + 0x10) == puVar11[6])) &&
                 (pbVar12[9] == *(byte *)((int)puVar11 + 9))) goto loc_4020D88;
              puVar11 = (undefined4 *)*puVar11;
            } while ((undefined4 **)puVar11 != &_ipq);
          }
          puVar11 = (undefined4 *)0x0;
loc_4020D88:
          *(sword *)(pbVar12 + 2) = *(sword *)(pbVar12 + 2) - (sword)uVar4;
          pbVar12[1] = 0;
          if ((pbVar12[6] & 0x20) != 0) {
            pbVar12[1] = 1;
          }
          sVar8 = *(sword *)(pbVar12 + 6);
          *(sword *)(pbVar12 + 6) = sVar8 << 3;
          if ((pbVar12[1] == 0) && ((sword)(sVar8 << 3) == 0)) {
            if (puVar11 != (undefined4 *)0x0) {
              _ip_freef(puVar11);
            }
          }
          else {
            dword_40B68B8 = dword_40B68B8 + 1;
            pbVar12 = (byte *)_ip_reass(pbVar12,puVar11);
            in_D0 = 0;
            if (pbVar12 == (byte *)0x0) goto loc_4020A0A;
            piVar6 = (int *)((uint)pbVar12 & 0xffffff80);
          }
        }
        piStack_8 = piVar6;
        in_D0 = _receive_ip_datagram(&piStack_8);
        if (in_D0 == 0) {
          in_D0 = (**(code **)((int)&DAT_40ae968 + (uint)(byte)_ip_protox[pbVar12[9]] * 0x2e))
                            (piStack_8,iVar13);
        }
      }
      goto loc_4020A0A;
    }
    piVar6 = (int *)_m_pullup(piVar6,uVar4);
    if (piVar6 != (int *)0x0) {
      pbVar12 = (byte *)(piVar6[1] + (int)piVar6);
      goto loc_4020B62;
    }
    dword_40B68B0 = dword_40B68B0 + 1;
    in_D0 = 0;
  } while( true );
}
