
/* WARNING: Removing unreachable block (ram,0xf0033bc4) */
/* WARNING: Removing unreachable block (ram,0xf0033b6c) */
/* WARNING: Removing unreachable block (ram,0xf0033b44) */
/* WARNING: Removing unreachable block (ram,0xf0033a90) */
/* WARNING: Removing unreachable block (ram,0xf00339dc) */
/* WARNING: Removing unreachable block (ram,0xf0033978) */
/* WARNING: Removing unreachable block (ram,0xf0033908) */
/* WARNING: Removing unreachable block (ram,0xf003387c) */
/* WARNING: Removing unreachable block (ram,0xf00337bc) */
/* WARNING: Removing unreachable block (ram,0xf0033604) */
/* WARNING: Removing unreachable block (ram,0xf00335e4) */
/* WARNING: Removing unreachable block (ram,0xf0033550) */
/* WARNING: Removing unreachable block (ram,0xf003359c) */
/* WARNING: Removing unreachable block (ram,0xf00335fc) */
/* WARNING: Removing unreachable block (ram,0xf003362c) */
/* WARNING: Removing unreachable block (ram,0xf00337f0) */
/* WARNING: Removing unreachable block (ram,0xf00338f4) */
/* WARNING: Removing unreachable block (ram,0xf003395c) */
/* WARNING: Removing unreachable block (ram,0xf00339d0) */
/* WARNING: Removing unreachable block (ram,0xf0033a4c) */
/* WARNING: Removing unreachable block (ram,0xf0033b0c) */
/* WARNING: Removing unreachable block (ram,0xf0033b60) */
/* WARNING: Removing unreachable block (ram,0xf0033660) */
/* WARNING: Removing unreachable block (ram,0xf0033c04) */
/* WARNING: Removing unreachable block (ram,0xf00334ac) */

undefined8 _ip_output(undefined4 param_1,int param_2,int *param_3,undefined4 param_4,int param_5)

{
  sword sVar1;
  int *piVar2;
  undefined *puVar3;
  int iVar4;
  char cVar5;
  int iVar6;
  code *pcVar7;
  word wVar8;
  int iVar9;
  int iVar10;
  uint uVar11;
  undefined4 unaff_l0;
  int *piVar12;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 *puVar13;
  undefined4 unaff_l4;
  int iVar14;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  uint uVar15;
  undefined4 unaff_l7;
  int *piVar16;
  undefined4 unaff_i0;
  int iVar17;
  undefined4 unaff_i1;
  undefined4 *puVar18;
  undefined4 unaff_i2;
  undefined4 unaff_i3;
  undefined4 unaff_i4;
  undefined4 unaff_i5;
  undefined4 unaff_fp;
  undefined4 unaff_i7;
  bool bVar19;
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
  *(undefined4 *)((int)register0x00000038 + -0x44) = param_1;
  *(undefined4 *)((int)register0x00000038 + -0x4c) = param_4;
  uVar15 = 0x14;
  piVar12 = (int *)0x0;
  iVar14 = *(int *)((int)register0x00000038 + -0x44);
  iVar17 = 0;
  if (param_2 != 0) {
    iVar14 = *(int *)((int)register0x00000038 + -0x44);
    _ip_insertoptions(iVar14,param_2,(undefined *)((int)register0x00000038 + -0x3c));
    uVar15 = *(uint *)((int)register0x00000038 + -0x3c);
  }
  iVar9 = *(int *)(iVar14 + 4);
  puVar18 = (undefined4 *)(iVar14 + iVar9);
  if ((*(uint *)((int)register0x00000038 + -0x4c) & 1) == 0) {
    *(uint *)(iVar14 + iVar9) = *(uint *)(iVar14 + iVar9) & 0xfffffff | 0x40000000;
    sVar1 = _ip_id + 1;
    *(sword *)(puVar18 + 1) = _ip_id;
    _ip_id = sVar1;
    *(word *)((int)puVar18 + 6) = *(word *)((int)puVar18 + 6) & 0x4000;
    *(uint *)(iVar14 + iVar9) =
         *(uint *)(iVar14 + iVar9) & 0xf0ffffff | ((int)uVar15 >> 2 & 0xfU) << 0x18;
  }
  else {
    uVar15 = (*(byte *)(iVar14 + iVar9) & 0xf) << 2;
  }
  if (param_3 == (int *)0x0) {
    param_3 = (int *)((int)register0x00000038 + -0x20);
    _bzero(param_3,0x14);
    iVar9 = *param_3;
  }
  else {
    iVar9 = *param_3;
  }
  piVar16 = param_3 + 1;
  if (iVar9 == 0) {
loc_F00335B4:
    iVar9 = *param_3;
  }
  else {
    if ((*(word *)(iVar9 + 0x24) & 1) == 0) {
      sVar1 = *(sword *)(iVar9 + 0x26);
loc_F0033590:
      if (sVar1 == 1) {
        _rtfree(iVar9);
        *param_3 = 0;
      }
      else {
        *(sword *)(iVar9 + 0x26) = sVar1 + -1;
        *param_3 = 0;
      }
      goto loc_F00335B4;
    }
    if (param_3[2] != puVar18[4]) {
      sVar1 = *(sword *)(iVar9 + 0x26);
      goto loc_F0033590;
    }
    iVar9 = *param_3;
  }
  uVar11 = *(uint *)((int)register0x00000038 + -0x4c);
  if (iVar9 == 0) {
    *(undefined2 *)piVar16 = 2;
    param_3[2] = puVar18[4];
    uVar11 = *(uint *)((int)register0x00000038 + -0x4c);
  }
  if ((uVar11 & 0x10) != 0) {
    piVar12 = piVar16;
    _ifa_ifwithdstaddr();
    piVar2 = (int *)((int)register0x00000038 + -0x40);
    bVar19 = false;
    if (piVar12 == (int *)0x0) {
      *(undefined4 *)((int)register0x00000038 + -0x40) = puVar18[4];
      _in_netof();
      _in_iaonnetof();
      bVar19 = piVar2 == (int *)0x0;
      piVar12 = piVar2;
    }
    if (!bVar19) {
      iVar9 = piVar12[8];
      goto loc_F0033698;
    }
    iVar17 = 0x33;
    goto loc_F0033BC0;
  }
  if (*param_3 == 0) {
    _rtalloc(param_3);
    iVar6 = *param_3;
  }
  else {
    iVar6 = *param_3;
  }
  if ((iVar6 == 0) || (iVar9 = *(int *)(iVar6 + 0x2c), iVar9 == 0)) {
    puVar3 = (undefined *)((int)register0x00000038 + -0x40);
    *(undefined4 *)((int)register0x00000038 + -0x40) = puVar18[4];
    _in_localaddr();
    if (puVar3 != (undefined *)0x0) {
      iVar17 = 0x41;
      goto loc_F0033BC0;
    }
    iVar14 = *(int *)((int)register0x00000038 + -0x44);
    iVar17 = 0x33;
  }
  else {
    *(int *)(iVar6 + 0x28) = *(int *)(iVar6 + 0x28) + 1;
    if ((*(word *)(*param_3 + 0x24) & 2) != 0) {
      piVar16 = (int *)(*param_3 + 0x14);
    }
loc_F0033698:
    if ((puVar18[4] & 0xf0000000) == 0xe0000000) {
      piVar16 = param_3 + 1;
      if (((*(uint *)((int)register0x00000038 + -0x4c) & 2) == 0) || (param_5 == 0)) {
        iVar10 = 0;
        *(undefined *)(puVar18 + 2) = 1;
        iVar6 = iVar9;
loc_F003370C:
        iVar4 = puVar18[3];
        iVar9 = iVar6;
      }
      else {
        iVar6 = *(int *)(param_5 + 4);
        iVar10 = param_5 + iVar6;
        *(undefined *)(puVar18 + 2) = *(undefined *)(iVar10 + 4);
        iVar6 = *(int *)(param_5 + iVar6);
        if (iVar6 != 0) goto loc_F003370C;
        iVar4 = puVar18[3];
      }
      bVar19 = piVar12 == (int *)0x0;
      if ((iVar4 == 0) && (bVar19 = _in_ifaddr == (int *)0x0, piVar12 = _in_ifaddr, !bVar19)) {
        iVar6 = _in_ifaddr[8];
        while (iVar6 != iVar9) {
          piVar12 = (int *)piVar12[0x10];
          if (piVar12 == (int *)0x0) goto loc_F0033750;
          iVar6 = piVar12[8];
        }
        puVar18[3] = piVar12[1];
loc_F0033750:
        bVar19 = piVar12 == (int *)0x0;
      }
      if (bVar19) {
        piVar12 = (int *)0x0;
loc_F0033798:
        if ((piVar12 == (int *)0x0) || ((iVar10 != 0 && (*(char *)(iVar10 + 5) == '\0'))))
        goto loc_F00337CC;
        _ip_mloopback(iVar9,iVar14,piVar16);
        cVar5 = *(char *)(puVar18 + 2);
      }
      else {
        piVar12 = (int *)piVar12[0x11];
        if (piVar12 != (int *)0x0) {
          iVar6 = *piVar12;
          while ((iVar6 != puVar18[4] && (piVar12 = (int *)piVar12[5], piVar12 != (int *)0x0))) {
            iVar6 = *piVar12;
          }
          goto loc_F0033798;
        }
loc_F00337CC:
        if (_ip_mrouter != 0) {
          if ((*(uint *)((int)register0x00000038 + -0x4c) & 1) != 0) {
            cVar5 = *(char *)(puVar18 + 2);
            goto loc_F0033808;
          }
          puVar13 = puVar18;
          _ip_mforward(puVar18,iVar9);
          if (puVar13 != (undefined4 *)0x0) goto loc_F0033BC4;
        }
        cVar5 = *(char *)(puVar18 + 2);
      }
loc_F0033808:
      if ((cVar5 != '\0') && (iVar9 != _loifp)) {
        iVar17 = (int)*(sword *)((int)puVar18 + 2);
        goto loc_F00338D0;
      }
    }
    else {
      if (puVar18[3] == 0) {
        if (_in_ifaddr == (int *)0x0) {
          iVar17 = piVar16[1];
        }
        else {
          iVar17 = _in_ifaddr[8];
          piVar12 = _in_ifaddr;
          while (iVar17 != iVar9) {
            piVar12 = (int *)piVar12[0x10];
            if (piVar12 == (int *)0x0) goto loc_F0033874;
            iVar17 = piVar12[8];
          }
          puVar18[3] = piVar12[1];
loc_F0033874:
          iVar17 = piVar16[1];
        }
      }
      else {
        iVar17 = piVar16[1];
      }
      puVar3 = (undefined *)((int)register0x00000038 + -0x40);
      *(int *)((int)register0x00000038 + -0x40) = iVar17;
      _in_broadcast();
      if (puVar3 == (undefined *)0x0) {
        iVar17 = (int)*(sword *)((int)puVar18 + 2);
loc_F00338D0:
        if (iVar17 <= *(sword *)(iVar9 + 10)) {
          *(sword *)((int)puVar18 + 2) = (sword)iVar17;
          *(undefined2 *)((int)puVar18 + 10) = 0;
          *(undefined2 *)((int)puVar18 + 6) = *(undefined2 *)((int)puVar18 + 6);
          iVar17 = iVar14;
          _in_cksum(iVar14,uVar15);
          *(sword *)((int)puVar18 + 10) = (sword)iVar17;
          _if_output_mbuf(iVar9,iVar14,piVar16);
          goto loc_F0033BCC;
        }
        iVar17 = 0x28;
        if ((*(word *)((int)puVar18 + 6) & 0x4000) == 0) {
          uVar11 = (int)*(sword *)(iVar9 + 10) - uVar15 & 0xfffffff8;
          *(uint *)((int)register0x00000038 + -0x3c) = uVar11;
          if ((int)uVar11 < 8) {
            iVar14 = *(int *)((int)register0x00000038 + -0x44);
            goto loc_F0033BC4;
          }
          iVar6 = iVar9;
          (**(code **)(iVar9 + 0x40))();
          iVar17 = 0x37;
          if (iVar6 != 0) {
            iVar17 = iVar6;
            _nb_map();
            _mbuf_read(iVar14,iVar17,0,uVar15 + *(int *)((int)register0x00000038 + -0x3c));
            *(undefined4 *)((int)register0x00000038 + -0x38) = *puVar18;
            *(undefined4 *)((int)register0x00000038 + -0x34) = puVar18[1];
            *(undefined4 *)((int)register0x00000038 + -0x30) = puVar18[2];
            *(undefined4 *)((int)register0x00000038 + -0x2c) = puVar18[3];
            *(undefined4 *)((int)register0x00000038 + -0x28) = puVar18[4];
            *(sword *)((int)register0x00000038 + -0x36) =
                 (sword)uVar15 + (sword)*(undefined4 *)((int)register0x00000038 + -0x3c);
            *(word *)((int)register0x00000038 + -0x32) = *(word *)((int)puVar18 + 6) | 0x2000;
            *(undefined2 *)((int)register0x00000038 + -0x2e) = 0;
            _bcopy((undefined *)((int)register0x00000038 + -0x38),iVar17,0x14);
            iVar10 = iVar6;
            _in_cksum(iVar6,uVar15);
            *(sword *)((int)register0x00000038 + -0x2e) = (sword)iVar10;
            *(undefined *)(iVar17 + 10) = *(undefined *)((int)register0x00000038 + -0x2e);
            *(undefined *)(iVar17 + 0xb) = *(undefined *)((int)register0x00000038 + -0x2d);
            iVar17 = iVar9;
            (**(code **)(iVar9 + 0x34))(iVar9,iVar6,piVar16);
            if (iVar17 == 0) {
              iVar6 = uVar15 + *(int *)((int)register0x00000038 + -0x3c);
              puVar13 = (undefined4 *)0x14;
              if (iVar6 < *(sword *)((int)puVar18 + 2)) {
                pcVar7 = *(code **)(iVar9 + 0x40);
                while (iVar10 = iVar9, (*pcVar7)(), iVar10 != 0) {
                  iVar17 = iVar10;
                  _nb_map();
                  *(undefined4 *)((int)register0x00000038 + -0x38) = *puVar18;
                  *(undefined4 *)((int)register0x00000038 + -0x34) = puVar18[1];
                  *(undefined4 *)((int)register0x00000038 + -0x30) = puVar18[2];
                  *(undefined4 *)((int)register0x00000038 + -0x2c) = puVar18[3];
                  *(undefined4 *)((int)register0x00000038 + -0x28) = puVar18[4];
                  if (0x14 < uVar15) {
                    puVar13 = puVar18;
                    _ip_optcopy(puVar18,iVar17);
                    puVar13 = puVar13 + 5;
                    *(uint *)((int)register0x00000038 + -0x38) =
                         *(uint *)((int)register0x00000038 + -0x38) & 0xf0ffffff |
                         ((int)puVar13 >> 2 & 0xfU) << 0x18;
                  }
                  wVar8 = (sword)((int)(iVar6 - uVar15) >> 3) +
                          (*(word *)((int)puVar18 + 6) & 0xdfff);
                  *(word *)((int)register0x00000038 + -0x32) = wVar8;
                  if ((*(word *)((int)puVar18 + 6) & 0x2000) != 0) {
                    *(word *)((int)register0x00000038 + -0x32) = wVar8 | 0x2000;
                  }
                  if (iVar6 + *(int *)((int)register0x00000038 + -0x3c) <
                      (int)*(sword *)((int)puVar18 + 2)) {
                    *(word *)((int)register0x00000038 + -0x32) =
                         *(word *)((int)register0x00000038 + -0x32) | 0x2000;
                  }
                  else {
                    _nb_shrink_bot(iVar10,(iVar6 + *(int *)((int)register0x00000038 + -0x3c)) -
                                          (int)*(sword *)((int)puVar18 + 2));
                    *(int *)((int)register0x00000038 + -0x3c) = *(sword *)((int)puVar18 + 2) - iVar6
                    ;
                  }
                  *(sword *)((int)register0x00000038 + -0x36) =
                       (sword)*(undefined4 *)((int)register0x00000038 + -0x3c) + (sword)puVar13;
                  _mbuf_read(iVar14,iVar17 + (int)puVar13,iVar6);
                  *(undefined2 *)((int)register0x00000038 + -0x2e) = 0;
                  *(undefined2 *)((int)register0x00000038 + -0x32) =
                       *(undefined2 *)((int)register0x00000038 + -0x32);
                  _bcopy((undefined *)((int)register0x00000038 + -0x38),iVar17,0x14);
                  iVar4 = iVar10;
                  _in_cksum(iVar10,puVar13);
                  *(sword *)((int)register0x00000038 + -0x2e) = (sword)iVar4;
                  *(undefined *)(iVar17 + 10) = *(undefined *)((int)register0x00000038 + -0x2e);
                  *(undefined *)(iVar17 + 0xb) = *(undefined *)((int)register0x00000038 + -0x2d);
                  iVar17 = iVar9;
                  (**(code **)(iVar9 + 0x34))(iVar9,iVar10,piVar16);
                  if ((iVar17 != 0) ||
                     (iVar6 = iVar6 + *(int *)((int)register0x00000038 + -0x3c),
                     *(sword *)((int)puVar18 + 2) <= iVar6)) goto loc_F0033BC0;
                  pcVar7 = *(code **)(iVar9 + 0x40);
                }
                iVar17 = 0x37;
              }
            }
          }
        }
      }
      else if ((*(word *)(iVar9 + 0xc) & 2) == 0) {
        iVar17 = 0x31;
      }
      else if ((*(uint *)((int)register0x00000038 + -0x4c) & 0x20) == 0) {
        iVar17 = 0xd;
      }
      else {
        iVar17 = 0x28;
        if (*(sword *)((int)puVar18 + 2) <= *(sword *)(iVar9 + 10)) {
          iVar17 = (int)*(sword *)((int)puVar18 + 2);
          goto loc_F00338D0;
        }
      }
loc_F0033BC0:
      iVar14 = *(int *)((int)register0x00000038 + -0x44);
    }
  }
loc_F0033BC4:
  iVar9 = iVar17;
  _m_freem(iVar14);
loc_F0033BCC:
  if (((param_3 == (int *)((int)register0x00000038 + -0x20)) &&
      (iVar17 = *(int *)((int)register0x00000038 + -0x20),
      (*(uint *)((int)register0x00000038 + -0x4c) & 0x10) == 0)) && (iVar17 != 0)) {
    if (*(sword *)(iVar17 + 0x26) == 1) {
      _rtfree(iVar17);
    }
    else {
      *(sword *)(iVar17 + 0x26) = *(sword *)(iVar17 + 0x26) + -1;
    }
  }
  return CONCAT44(puVar18,iVar9);
}
