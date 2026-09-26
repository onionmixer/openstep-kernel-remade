
/* WARNING: Removing unreachable block (ram,0xf00324cc) */
/* WARNING: Removing unreachable block (ram,0xf003248c) */
/* WARNING: Removing unreachable block (ram,0xf00322bc) */
/* WARNING: Removing unreachable block (ram,0xf00321c4) */
/* WARNING: Removing unreachable block (ram,0xf003215c) */
/* WARNING: Removing unreachable block (ram,0xf003202c) */
/* WARNING: Removing unreachable block (ram,0xf0031f74) */
/* WARNING: Removing unreachable block (ram,0xf0031f48) */
/* WARNING: Removing unreachable block (ram,0xf0031ee0) */
/* WARNING: Removing unreachable block (ram,0xf0031ec4) */
/* WARNING: Removing unreachable block (ram,0xf0031f20) */
/* WARNING: Removing unreachable block (ram,0xf0031f68) */
/* WARNING: Removing unreachable block (ram,0xf0031fc8) */
/* WARNING: Removing unreachable block (ram,0xf0032070) */
/* WARNING: Removing unreachable block (ram,0xf003217c) */
/* WARNING: Removing unreachable block (ram,0xf0032384) */
/* WARNING: Removing unreachable block (ram,0xf0032368) */
/* WARNING: Removing unreachable block (ram,0xf00324b0) */
/* WARNING: Removing unreachable block (ram,0xf0032518) */
/* WARNING: Removing unreachable block (ram,0xf0031e58) */

undefined8 _ipintr(int *param_1,undefined4 param_2)

{
  int *piVar1;
  byte bVar2;
  sword sVar3;
  sword sVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  undefined *puVar8;
  int *piVar9;
  uint uVar10;
  word wVar11;
  undefined4 *puVar12;
  undefined4 unaff_l0;
  int *piVar13;
  int *piVar14;
  undefined4 unaff_l1;
  uint uVar15;
  undefined4 unaff_l3;
  int iVar16;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 unaff_i1;
  undefined4 unaff_i2;
  undefined4 unaff_i3;
  undefined4 unaff_i4;
  undefined4 unaff_i5;
  undefined4 unaff_fp;
  undefined4 unaff_i7;
  bool bVar17;
  bool in_DECOMPILE_MODE;
  int in_CWP;
  undefined auStackX_0 [92];
  
  if (!in_DECOMPILE_MODE) {
    *(undefined4 *)(in_CWP * 0x40 + 0x8000) = unaff_i0;
    *(undefined4 *)((in_CWP * 0x10 + 1) * 4 + 0x8000) = unaff_i1;
    *(undefined4 *)((in_CWP * 0x10 + 2) * 4 + 0x8000) = unaff_i2;
    *(undefined4 *)((in_CWP * 0x10 + 3) * 4 + 0x8000) = unaff_i3;
    *(undefined4 *)((in_CWP * 0x10 + 4) * 4 + 0x8000) = unaff_i4;
    *(undefined4 *)((in_CWP * 0x10 + 5) * 4 + 0x8000) = unaff_i5;
    *(undefined4 *)((in_CWP * 0x10 + 6) * 4 + 0x8000) = unaff_fp;
    *(undefined4 *)((in_CWP * 0x10 + 7) * 4 + 0x8000) = unaff_i7;
    *(undefined4 *)((in_CWP * 0x10 + 8) * 4 + 0x8000) = unaff_l0;
    *(undefined4 *)((in_CWP * 0x10 + 9) * 4 + 0x8000) = unaff_l1;
    *(undefined4 *)((in_CWP * 0x10 + 10) * 4 + 0x8000) = unaff_l3;
    *(undefined4 *)((in_CWP * 0x10 + 0xb) * 4 + 0x8000) = unaff_l3;
    *(undefined4 *)((in_CWP * 0x10 + 0xc) * 4 + 0x8000) = unaff_l4;
    *(undefined4 *)((in_CWP * 0x10 + 0xd) * 4 + 0x8000) = unaff_l5;
    *(undefined4 *)((in_CWP * 0x10 + 0xe) * 4 + 0x8000) = unaff_l6;
    *(undefined4 *)((in_CWP * 0x10 + 0xf) * 4 + 0x8000) = unaff_l7;
  }
  iVar16 = 0;
  piVar9 = param_1;
loc_F0031E58:
  while( true ) {
    _spltty();
    piVar14 = _ipintrq;
    piVar13 = piVar14;
    if (_ipintrq != (int *)0x0) {
      if ((int *)_ipintrq[0x1f] == (int *)0x0) {
        DAT_f0136484._0_4_ = 0;
      }
      piVar1 = _ipintrq + 0x1f;
      _ipintrq = (int *)_ipintrq[0x1f];
      *piVar1 = 0;
      DAT_f0136484._4_4_ = DAT_f0136484._4_4_ + -1;
      sVar3 = *(sword *)(piVar14 + 2);
      iVar16 = *(int *)((int)piVar14 + piVar14[1]);
      iVar5 = piVar14[1] + 4;
      piVar14[1] = iVar5;
      *(sword *)(piVar14 + 2) = sVar3 + -4;
      if ((sword)(sVar3 + -4) == 0) {
        _spltty();
        if (*(sword *)((int)piVar14 + 10) == 0) {
          _panic(&aMfree_7);
        }
        (&word_F0134B0C)[*(sword *)((int)piVar14 + 10)] =
             (&word_F0134B0C)[*(sword *)((int)piVar14 + 10)] + -1;
        word_F0134B0C = word_F0134B0C + 1;
        *(undefined2 *)((int)piVar14 + 10) = 0;
        if (0x7f < (uint)piVar14[1]) {
          _mclput(piVar14);
        }
        piVar14[1] = 0;
        piVar14[0x1f] = 0;
        piVar13 = (int *)*piVar14;
        *piVar14 = (int)_mfree;
        _mfree = piVar14;
        _splx(iVar5);
        if (_m_want != 0) {
          _m_want = 0;
          _wakeup(&_mfree);
        }
      }
    }
    _splx(piVar9);
    if (piVar13 == (int *)0x0) {
      return CONCAT44(param_2,param_1);
    }
    if (_in_ifaddr == 0) goto loc_F0032518;
    _ipstat = _ipstat + 1;
    uVar10 = piVar13[1];
    if ((uVar10 < 0x7d) && (0x13 < *(word *)(piVar13 + 2))) break;
    _m_pullup(piVar13,0x14);
    if (piVar13 != (int *)0x0) {
      uVar10 = piVar13[1];
      bVar2 = *(byte *)((int)piVar13 + uVar10);
      goto loc_F0031FF0;
    }
    piVar9 = (int *)(DAT_f01364d4._8_4_ + 1);
    DAT_f01364d4._8_4_ = piVar9;
  }
  bVar2 = *(byte *)((int)piVar13 + uVar10);
loc_F0031FF0:
  uVar15 = (bVar2 & 0xf) * 4;
  piVar14 = (int *)((int)piVar13 + uVar10);
  if (uVar15 < 0x14) {
    DAT_f01364d4._12_4_ = DAT_f01364d4._12_4_ + 1;
  }
  else {
    if (uVar15 - (int)*(sword *)(piVar13 + 2) != 0 && (int)*(sword *)(piVar13 + 2) <= (int)uVar15) {
      _m_pullup(piVar13,uVar15);
      if (piVar13 == (int *)0x0) {
        piVar9 = (int *)(DAT_f01364d4._12_4_ + 1);
        DAT_f01364d4._12_4_ = piVar9;
        goto loc_F0031E58;
      }
      piVar14 = (int *)((int)piVar13 + piVar13[1]);
    }
    if (_ipcksum._0_1_ != '\0') {
      piVar9 = piVar13;
      _in_cksum(piVar13,uVar15);
      *(sword *)((int)piVar14 + 10) = (sword)piVar9;
      if (((uint)piVar9 & 0xffff) != 0) {
        DAT_f01364d4._0_4_ = DAT_f01364d4._0_4_ + 1;
        goto loc_F0032518;
      }
    }
    *(sword *)((int)piVar14 + 2) = (sword)*piVar14;
    if ((int)uVar15 <= (int)(sword)*piVar14) {
      iVar5 = *piVar14;
      *(undefined2 *)(piVar14 + 1) = *(undefined2 *)(piVar14 + 1);
      *(undefined2 *)((int)piVar14 + 6) = *(undefined2 *)((int)piVar14 + 6);
      sVar3 = *(sword *)(piVar13 + 2);
      *(int **)((int)register0x00000038 + -0xc) = piVar13;
      iVar5 = (int)sVar3 - (uint)(word)iVar5;
      iVar6 = *piVar13;
      while (iVar6 != 0) {
        piVar13 = (int *)*piVar13;
        iVar5 = iVar5 + *(sword *)(piVar13 + 2);
        iVar6 = *piVar13;
      }
      if (iVar5 == 0) {
        iVar5 = *(int *)((int)register0x00000038 + -0xc);
      }
      else {
        if (iVar5 < 0) {
          piVar13 = *(int **)((int)register0x00000038 + -0xc);
          DAT_f01364d4._4_4_ = DAT_f01364d4._4_4_ + 1;
          goto loc_F0032518;
        }
        if (*(sword *)(piVar13 + 2) < iVar5) {
          _m_adj(*(undefined4 *)((int)register0x00000038 + -0xc),-iVar5);
        }
        else {
          *(sword *)(piVar13 + 2) = *(sword *)(piVar13 + 2) - (sword)iVar5;
        }
        iVar5 = *(int *)((int)register0x00000038 + -0xc);
      }
      _ip_nhops = 0;
      if ((uVar15 < 0x15) || (piVar9 = piVar14, _ip_dooptions(piVar14,iVar16), piVar9 == (int *)0x0)
         ) {
        if (((*(word *)(iVar16 + 0xc) & 0x4000) == 0) ||
           ((((0x7c < *(uint *)(iVar5 + 4) || (*(word *)(iVar5 + 8) < 0x1c)) &&
             (_m_pullup(iVar5,0x1c), iVar5 == 0)) ||
            ((iVar6 = iVar5 + *(int *)(iVar5 + 4), *(char *)(iVar6 + 9) != '\x11' ||
             (*(sword *)(iVar6 + 0x16) != 0x44)))))) {
          uVar10 = piVar14[4];
          if (_in_ifaddr == 0) {
loc_F0032288:
            if ((uVar10 & 0xf0000000) == 0xe0000000) {
              if (_ip_mrouter == 0) {
loc_F00322E4:
                bVar17 = _in_ifaddr == 0;
                iVar6 = _in_ifaddr;
                if (!bVar17) {
                  iVar7 = *(int *)(_in_ifaddr + 0x20);
                  while (bVar17 = iVar6 == 0, iVar7 != iVar16) {
                    iVar6 = *(int *)(iVar6 + 0x40);
                    if (iVar6 == 0) {
                      bVar17 = true;
                      break;
                    }
                    iVar7 = *(int *)(iVar6 + 0x20);
                  }
                }
                if (bVar17) {
loc_F003235C:
                  bVar17 = true;
                }
                else {
                  piVar9 = *(int **)(iVar6 + 0x44);
                  bVar17 = piVar9 == (int *)0x0;
                  if (!bVar17) {
                    iVar6 = *piVar9;
                    while (bVar17 = piVar9 == (int *)0x0, iVar6 != piVar14[4]) {
                      piVar9 = (int *)piVar9[5];
                      if (piVar9 == (int *)0x0) goto loc_F003235C;
                      iVar6 = *piVar9;
                    }
                  }
                }
                if (!bVar17) {
                  wVar11 = *(word *)((int)piVar14 + 6);
                  goto loc_F0032394;
                }
              }
              else {
                *(undefined2 *)(piVar14 + 1) = *(undefined2 *)(piVar14 + 1);
                piVar9 = piVar14;
                _ip_mforward(piVar14,iVar16);
                if (piVar9 == (int *)0x0) {
                  *(undefined2 *)(piVar14 + 1) = *(undefined2 *)(piVar14 + 1);
                  if (*(char *)((int)piVar14 + 9) == '\x02') goto loc_F0032390;
                  goto loc_F00322E4;
                }
              }
              piVar9 = (int *)((uint)piVar14 & 0xffffff80);
              _m_freem();
            }
            else {
              if ((uVar10 == 0xffffffff) || (uVar10 == 0)) goto loc_F0032390;
              _ip_forward(piVar14,iVar16);
              piVar9 = piVar14;
            }
            goto loc_F0031E58;
          }
          uVar15 = *(uint *)(_in_ifaddr + 4);
          iVar6 = _in_ifaddr;
          while (uVar15 != uVar10) {
            if ((*(word *)(*(int *)(iVar6 + 0x20) + 0xc) & 2) == 0) {
              iVar6 = *(int *)(iVar6 + 0x40);
            }
            else {
              if (*(uint *)(iVar6 + 0x14) == uVar10) {
                wVar11 = *(word *)((int)piVar14 + 6);
                goto loc_F0032394;
              }
              if (uVar10 == *(uint *)(iVar6 + 0x38)) {
                wVar11 = *(word *)((int)piVar14 + 6);
                goto loc_F0032394;
              }
              if (uVar10 == *(uint *)(iVar6 + 0x30)) {
                wVar11 = *(word *)((int)piVar14 + 6);
                goto loc_F0032394;
              }
              if (uVar10 == *(uint *)(iVar6 + 0x28)) {
                wVar11 = *(word *)((int)piVar14 + 6);
                goto loc_F0032394;
              }
              iVar6 = *(int *)(iVar6 + 0x40);
            }
            if (iVar6 == 0) {
              uVar10 = piVar14[4];
              goto loc_F0032288;
            }
            uVar15 = *(uint *)(iVar6 + 4);
          }
          wVar11 = *(word *)((int)piVar14 + 6);
        }
        else {
loc_F0032390:
          wVar11 = *(word *)((int)piVar14 + 6);
        }
loc_F0032394:
        sVar3 = (sword)(bVar2 & 0xf);
        if ((wVar11 & 0xbfff) == 0) {
          *(sword *)((int)piVar14 + 2) = (sword)*piVar14 + sVar3 * -4;
          *(int *)((int)register0x00000038 + -0xc) = iVar5;
        }
        else {
          if ((undefined4 **)_ipq != &_ipq) {
            sVar4 = *(sword *)((int)_ipq + 10);
            puVar12 = _ipq;
            while( true ) {
              if (*(sword *)(piVar14 + 1) == sVar4) {
                if (piVar14[3] == puVar12[5]) {
                  if (piVar14[4] == puVar12[6]) {
                    if (*(char *)((int)piVar14 + 9) == *(char *)((int)puVar12 + 9)) {
                      sVar4 = (sword)*piVar14;
                      goto loc_F0032428;
                    }
                    puVar12 = (undefined4 *)*puVar12;
                  }
                  else {
                    puVar12 = (undefined4 *)*puVar12;
                  }
                }
                else {
                  puVar12 = (undefined4 *)*puVar12;
                }
              }
              else {
                puVar12 = (undefined4 *)*puVar12;
              }
              if ((undefined4 **)puVar12 == &_ipq) break;
              sVar4 = *(sword *)((int)puVar12 + 10);
            }
          }
          puVar12 = (undefined4 *)0x0;
          sVar4 = (sword)*piVar14;
loc_F0032428:
          *(undefined *)((int)piVar14 + 1) = 0;
          *(sword *)((int)piVar14 + 2) = sVar4 + sVar3 * -4;
          if ((*(word *)((int)piVar14 + 6) & 0x2000) != 0) {
            *(undefined *)((int)piVar14 + 1) = 1;
          }
          wVar11 = *(word *)((int)piVar14 + 6);
          *(word *)((int)piVar14 + 6) = wVar11 << 3;
          if ((*(char *)((int)piVar14 + 1) == '\0') && ((wVar11 & 0x1fff) == 0)) {
            if (puVar12 == (undefined4 *)0x0) {
              *(int *)((int)register0x00000038 + -0xc) = iVar5;
            }
            else {
              _ip_freef(puVar12);
              *(int *)((int)register0x00000038 + -0xc) = iVar5;
            }
          }
          else {
            DAT_f01364d4._20_4_ = DAT_f01364d4._20_4_ + 1;
            _ip_reass(piVar14,puVar12);
            piVar9 = (int *)0x0;
            if (piVar14 == (int *)0x0) goto loc_F0031E58;
            *(uint *)((int)register0x00000038 + -0xc) = (uint)piVar14 & 0xffffff80;
          }
        }
        puVar8 = (undefined *)((int)register0x00000038 + -0xc);
        _receive_ip_datagram();
        piVar9 = (int *)DAT_f0136400;
        if (puVar8 == (undefined *)0x0) {
          piVar9 = *(int **)((int)register0x00000038 + -0xc);
          (**(code **)(DAT_f010c5ac + (uint)(byte)_ip_protox[*(byte *)((int)piVar14 + 9)] * 0x30))
                    (piVar9,iVar16);
        }
      }
      goto loc_F0031E58;
    }
    DAT_f01364d4._16_4_ = DAT_f01364d4._16_4_ + 1;
  }
loc_F0032518:
  _m_freem();
  piVar9 = piVar13;
  goto loc_F0031E58;
}

