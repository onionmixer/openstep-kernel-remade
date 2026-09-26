
/* WARNING: Removing unreachable block (ram,0xf001f158) */
/* WARNING: Removing unreachable block (ram,0xf001f0f4) */
/* WARNING: Removing unreachable block (ram,0xf001f2a4) */
/* WARNING: Removing unreachable block (ram,0xf001f914) */
/* WARNING: Removing unreachable block (ram,0xf001f868) */
/* WARNING: Removing unreachable block (ram,0xf001f764) */
/* WARNING: Removing unreachable block (ram,0xf001f700) */
/* WARNING: Removing unreachable block (ram,0xf001f684) */
/* WARNING: Removing unreachable block (ram,0xf001f660) */
/* WARNING: Removing unreachable block (ram,0xf001f5b4) */
/* WARNING: Removing unreachable block (ram,0xf001f568) */
/* WARNING: Removing unreachable block (ram,0xf001f50c) */
/* WARNING: Removing unreachable block (ram,0xf001f440) */
/* WARNING: Removing unreachable block (ram,0xf001f3f4) */
/* WARNING: Removing unreachable block (ram,0xf001f398) */
/* WARNING: Removing unreachable block (ram,0xf001f310) */
/* WARNING: Removing unreachable block (ram,0xf001f2e4) */
/* WARNING: Removing unreachable block (ram,0xf001f330) */
/* WARNING: Removing unreachable block (ram,0xf001f3b4) */
/* WARNING: Removing unreachable block (ram,0xf001f420) */
/* WARNING: Removing unreachable block (ram,0xf001f488) */
/* WARNING: Removing unreachable block (ram,0xf001f528) */
/* WARNING: Removing unreachable block (ram,0xf001f594) */
/* WARNING: Removing unreachable block (ram,0xf001f4a8) */
/* WARNING: Removing unreachable block (ram,0xf001f618) */
/* WARNING: Removing unreachable block (ram,0xf001f67c) */
/* WARNING: Removing unreachable block (ram,0xf001f6e4) */
/* WARNING: Removing unreachable block (ram,0xf001f740) */
/* WARNING: Removing unreachable block (ram,0xf001f784) */
/* WARNING: Removing unreachable block (ram,0xf001f90c) */
/* WARNING: Removing unreachable block (ram,0xf001f29c) */
/* WARNING: Removing unreachable block (ram,0xf001f2ac) */
/* WARNING: Removing unreachable block (ram,0xf001f14c) */
/* WARNING: Removing unreachable block (ram,0xf001f190) */
/* WARNING: Removing unreachable block (ram,0xf001f1a4) */
/* WARNING: Removing unreachable block (ram,0xf001f1c4) */

undefined8 _soreceive(uint param_1,undefined4 *param_2,int param_3,uint param_4,uint *param_5)

{
  sword sVar1;
  int iVar2;
  uint uVar3;
  undefined4 *puVar4;
  int iVar5;
  word wVar6;
  code *pcVar7;
  undefined4 unaff_l0;
  undefined4 *puVar8;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  uint uVar9;
  undefined4 unaff_l4;
  int iVar10;
  undefined4 unaff_l5;
  undefined4 uVar11;
  undefined4 unaff_l6;
  int iVar12;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 unaff_i1;
  undefined4 unaff_i2;
  undefined4 unaff_i3;
  undefined4 unaff_i4;
  undefined4 unaff_i5;
  undefined4 unaff_fp;
  undefined4 unaff_i7;
  bool bVar13;
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
  uVar9 = 0;
  iVar12 = *(int *)(param_1 + 0xc);
  if (param_5 != (uint *)0x0) {
    *param_5 = 0;
  }
  if (param_2 != (undefined4 *)0x0) {
    *param_2 = 0;
  }
  iVar2 = 1;
  if ((param_4 & 1) == 0) {
    do {
      wVar6 = *(word *)(param_1 + 0x38);
      while ((wVar6 & 1) == 0) {
        uVar3 = *(word *)(param_1 + 0x38) | 1;
        *(sword *)(param_1 + 0x38) = (sword)uVar3;
        _splnet();
        sVar1 = *(sword *)(param_1 + 0x24);
        *(uint *)((int)register0x00000038 + -0xc) = uVar3;
        if (sVar1 != 0) {
          _active_u[0x69] = _active_u[0x69] + 1;
          puVar8 = *(undefined4 **)(param_1 + 0x30);
          if (puVar8 == (undefined4 *)0x0) {
            _panic(aReceive1);
            wVar6 = *(word *)(iVar12 + 10);
          }
          else {
            wVar6 = *(word *)(iVar12 + 10);
          }
          uVar11 = puVar8[0x1f];
          if ((wVar6 & 2) == 0) {
loc_F001F458:
            bVar13 = puVar8 == (undefined4 *)0x0;
          }
          else {
            if (*(sword *)((int)puVar8 + 10) != 8) {
              _panic(aReceive1a);
            }
            if ((param_4 & 2) != 0) {
              if (param_2 != (undefined4 *)0x0) {
                puVar4 = puVar8;
                _m_copy(puVar8,0,(int)*(sword *)(puVar8 + 2));
                *param_2 = puVar4;
              }
              puVar8 = (undefined4 *)*puVar8;
              goto loc_F001F458;
            }
            wVar6 = *(word *)(param_1 + 0x28);
            *(sword *)(param_1 + 0x24) = *(sword *)(param_1 + 0x24) - *(sword *)(puVar8 + 2);
            *(word *)(param_1 + 0x28) = wVar6 - 0x80;
            iVar2 = wVar6 - 0x480;
            if (0x7c < (uint)puVar8[1]) {
              *(sword *)(param_1 + 0x28) = (sword)iVar2;
            }
            if (param_2 == (undefined4 *)0x0) {
              _spltty();
              if (*(sword *)((int)puVar8 + 10) == 0) {
                _panic(&aMfree_0);
              }
              (&word_F0134B0C)[*(sword *)((int)puVar8 + 10)] =
                   (&word_F0134B0C)[*(sword *)((int)puVar8 + 10)] + -1;
              word_F0134B0C = word_F0134B0C + 1;
              *(undefined2 *)((int)puVar8 + 10) = 0;
              if (0x7f < (uint)puVar8[1]) {
                _mclput(puVar8);
              }
              *(undefined4 *)(param_1 + 0x30) = *puVar8;
              *puVar8 = _mfree;
              puVar8[1] = 0;
              puVar8[0x1f] = 0;
              _mfree = puVar8;
              _splx(iVar2);
              if (_m_want == 0) {
                puVar8 = *(undefined4 **)(param_1 + 0x30);
              }
              else {
                _m_want = 0;
                _wakeup(&_mfree);
                puVar8 = *(undefined4 **)(param_1 + 0x30);
              }
            }
            else {
              *param_2 = puVar8;
              puVar8 = (undefined4 *)*puVar8;
              *(undefined4 *)*param_2 = 0;
              *(undefined4 **)(param_1 + 0x30) = puVar8;
            }
            if (puVar8 == (undefined4 *)0x0) goto loc_F001F458;
            puVar8[0x1f] = uVar11;
            bVar13 = false;
          }
          if ((!bVar13) &&
             (bVar13 = puVar8 == (undefined4 *)0x0, *(sword *)((int)puVar8 + 10) == 0xc)) {
            if ((*(word *)(iVar12 + 10) & 0x10) == 0) {
              _panic(aReceive2);
            }
            if ((param_4 & 2) == 0) {
              wVar6 = *(word *)(param_1 + 0x28);
              *(sword *)(param_1 + 0x24) = *(sword *)(param_1 + 0x24) - *(sword *)(puVar8 + 2);
              *(word *)(param_1 + 0x28) = wVar6 - 0x80;
              iVar2 = wVar6 - 0x480;
              if (0x7c < (uint)puVar8[1]) {
                *(sword *)(param_1 + 0x28) = (sword)iVar2;
              }
              if (param_5 == (uint *)0x0) {
                _spltty();
                if (*(sword *)((int)puVar8 + 10) == 0) {
                  _panic(&aMfree_1);
                }
                (&word_F0134B0C)[*(sword *)((int)puVar8 + 10)] =
                     (&word_F0134B0C)[*(sword *)((int)puVar8 + 10)] + -1;
                word_F0134B0C = word_F0134B0C + 1;
                *(undefined2 *)((int)puVar8 + 10) = 0;
                if (0x7f < (uint)puVar8[1]) {
                  _mclput(puVar8);
                }
                *(undefined4 *)(param_1 + 0x30) = *puVar8;
                *puVar8 = _mfree;
                puVar8[1] = 0;
                puVar8[0x1f] = 0;
                _mfree = puVar8;
                _splx(iVar2);
                if (_m_want != 0) {
                  _m_want = 0;
                  _wakeup(&_mfree);
                  goto loc_F001F5BC;
                }
                puVar8 = *(undefined4 **)(param_1 + 0x30);
              }
              else {
                *param_5 = (uint)puVar8;
                *(undefined4 *)(param_1 + 0x30) = *puVar8;
                *puVar8 = 0;
loc_F001F5BC:
                puVar8 = *(undefined4 **)(param_1 + 0x30);
              }
              if (puVar8 != (undefined4 *)0x0) {
                puVar8[0x1f] = uVar11;
              }
            }
            else {
              if (param_5 != (uint *)0x0) {
                puVar4 = puVar8;
                _m_copy(puVar8,0,(int)*(sword *)(puVar8 + 2));
                *param_5 = (uint)puVar4;
              }
              puVar8 = (undefined4 *)*puVar8;
            }
            bVar13 = puVar8 == (undefined4 *)0x0;
          }
          iVar2 = 0;
          iVar10 = 0;
          if ((bVar13) || (*(int *)(param_3 + 0x14) < 1)) goto loc_F001F840;
          sVar1 = *(sword *)((int)puVar8 + 10);
          goto loc_F001F600;
        }
        uVar3 = (uint)*(word *)(param_1 + 0x56);
        if (uVar3 != 0) {
          *(undefined2 *)(param_1 + 0x56) = 0;
          goto loc_F001F8F0;
        }
        if ((*(word *)(param_1 + 6) & 0x20) != 0) {
          wVar6 = *(word *)(param_1 + 0x38);
          goto loc_F001F8F4;
        }
        if ((*(word *)(param_1 + 6) & 2) == 0) {
          if ((*(word *)(*(int *)(param_1 + 0xc) + 10) & 4) != 0) {
            uVar3 = 0x39;
            goto loc_F001F8F0;
          }
          iVar2 = *(int *)(param_3 + 0x14);
        }
        else {
          iVar2 = *(int *)(param_3 + 0x14);
        }
        if (iVar2 == 0) {
          wVar6 = *(word *)(param_1 + 0x38);
          goto loc_F001F8F4;
        }
        if ((*(word *)(param_1 + 6) & 0x100) != 0) {
          uVar3 = 0x23;
          if ((*(uint *)(*_active_u + 0x14) & 0x4000) == 0) goto loc_F001F8F0;
          if ((*(word *)(param_3 + 0x10) & 0x2000) != 0) {
            uVar3 = 0xb;
            goto loc_F001F8F0;
          }
          wVar6 = *(word *)(param_1 + 0x38);
          uVar9 = uVar3;
          goto loc_F001F8F4;
        }
        wVar6 = *(word *)(param_1 + 0x38);
        *(word *)(param_1 + 0x38) = wVar6 & 0xfffe;
        if ((wVar6 & 2) != 0) {
          *(word *)(param_1 + 0x38) = wVar6 & 0xfffc;
          _wakeup(param_1 + 0x38);
        }
        _sbwait(param_1 + 0x24);
        _splx(*(undefined4 *)((int)register0x00000038 + -0xc));
        wVar6 = *(word *)(param_1 + 0x38);
      }
      *(word *)(param_1 + 0x38) = wVar6 | 2;
      _sleep(param_1 + 0x38,0x1a);
    } while( true );
  }
  _m_get(1,1);
  (**(code **)(iVar12 + 0x1c))(param_1,0xd,iVar2,param_4 & 2,0);
  if (param_1 == 0) {
    param_2 = *(undefined4 **)(param_3 + 0x14);
    while( true ) {
      if ((int)*(sword *)(iVar2 + 8) < (int)param_2) {
        param_2 = (undefined4 *)(int)*(sword *)(iVar2 + 8);
      }
      param_1 = iVar2 + *(int *)(iVar2 + 4);
      _uiomove(param_1,param_2,0,param_3);
      _m_free();
      if (((*(int *)(param_3 + 0x14) == 0) || (param_1 != 0)) || (iVar2 == 0)) break;
      param_2 = *(undefined4 **)(param_3 + 0x14);
    }
  }
  uVar9 = param_1;
  if (iVar2 != 0) {
    _m_freem(iVar2);
  }
  goto locret_F001F91C;
loc_F001F600:
  if (1 < (word)(sVar1 - 1U)) {
    _panic(aReceive3);
  }
  param_2 = *(undefined4 **)(param_3 + 0x14);
  *(word *)(param_1 + 6) = *(word *)(param_1 + 6) & 0xffbf;
  if ((*(word *)(param_1 + 0x58) != 0) &&
     (puVar4 = (undefined4 *)((uint)*(word *)(param_1 + 0x58) - iVar10), (int)puVar4 < (int)param_2)
     ) {
    param_2 = puVar4;
  }
  if (*(sword *)(puVar8 + 2) - iVar2 < (int)param_2) {
    param_2 = (undefined4 *)(*(sword *)(puVar8 + 2) - iVar2);
  }
  _splx(*(undefined4 *)((int)register0x00000038 + -0xc));
  uVar9 = (int)puVar8 + iVar2 + puVar8[1];
  _uiomove(uVar9,param_2,0,param_3);
  uVar3 = uVar9;
  _splnet();
  sVar1 = *(sword *)(puVar8 + 2);
  *(uint *)((int)register0x00000038 + -0xc) = uVar3;
  bVar13 = (param_4 & 2) != 0;
  if (param_2 == (undefined4 *)(sVar1 - iVar2)) {
    if (bVar13) {
      puVar8 = (undefined4 *)*puVar8;
      iVar2 = 0;
      goto loc_F001F7D4;
    }
    uVar11 = puVar8[0x1f];
    wVar6 = *(word *)(param_1 + 0x28);
    *(sword *)(param_1 + 0x24) = *(sword *)(param_1 + 0x24) - sVar1;
    *(word *)(param_1 + 0x28) = wVar6 - 0x80;
    iVar5 = wVar6 - 0x480;
    if (0x7c < (uint)puVar8[1]) {
      *(sword *)(param_1 + 0x28) = (sword)iVar5;
    }
    _spltty();
    if (*(sword *)((int)puVar8 + 10) == 0) {
      _panic(&aMfree_2);
    }
    (&word_F0134B0C)[*(sword *)((int)puVar8 + 10)] =
         (&word_F0134B0C)[*(sword *)((int)puVar8 + 10)] + -1;
    word_F0134B0C = word_F0134B0C + 1;
    *(undefined2 *)((int)puVar8 + 10) = 0;
    if (0x7f < (uint)puVar8[1]) {
      _mclput(puVar8);
    }
    *(undefined4 *)(param_1 + 0x30) = *puVar8;
    *puVar8 = _mfree;
    puVar8[1] = 0;
    puVar8[0x1f] = 0;
    _mfree = puVar8;
    _splx(iVar5);
    if (_m_want == 0) {
      puVar8 = *(undefined4 **)(param_1 + 0x30);
    }
    else {
      _m_want = 0;
      _wakeup(&_mfree);
      puVar8 = *(undefined4 **)(param_1 + 0x30);
    }
    if (puVar8 != (undefined4 *)0x0) {
      puVar8[0x1f] = uVar11;
      goto loc_F001F7D4;
    }
    wVar6 = *(word *)(param_1 + 0x58);
  }
  else {
    if (bVar13) {
      iVar2 = iVar2 + (int)param_2;
    }
    else {
      puVar8[1] = puVar8[1] + (int)param_2;
      *(sword *)(puVar8 + 2) = *(sword *)(puVar8 + 2) - (sword)param_2;
      *(sword *)(param_1 + 0x24) = *(sword *)(param_1 + 0x24) - (sword)param_2;
    }
loc_F001F7D4:
    wVar6 = *(word *)(param_1 + 0x58);
  }
  if (wVar6 == 0) {
loc_F001F81C:
    if (((puVar8 == (undefined4 *)0x0) || (*(int *)(param_3 + 0x14) < 1)) || (uVar9 != 0))
    goto loc_F001F840;
    sVar1 = *(sword *)((int)puVar8 + 10);
    goto loc_F001F600;
  }
  if ((param_4 & 2) != 0) {
    iVar10 = iVar10 + (int)param_2;
    goto loc_F001F81C;
  }
  uVar3 = (uint)wVar6 - (int)param_2;
  *(sword *)(param_1 + 0x58) = (sword)uVar3;
  if ((uVar3 & 0xffff) != 0) goto loc_F001F81C;
  *(word *)(param_1 + 6) = *(word *)(param_1 + 6) | 0x40;
loc_F001F840:
  if ((param_4 & 2) == 0) {
    if (puVar8 == (undefined4 *)0x0) {
      *(undefined4 *)(param_1 + 0x30) = uVar11;
loc_F001F870:
      wVar6 = *(word *)(iVar12 + 10);
    }
    else {
      if ((*(word *)(iVar12 + 10) & 1) != 0) {
        _sbdroprecord(param_1 + 0x24);
        goto loc_F001F870;
      }
      wVar6 = *(word *)(iVar12 + 10);
    }
    if (((wVar6 & 8) != 0) && (*(int *)(param_1 + 8) != 0)) {
      (**(code **)(iVar12 + 0x1c))(param_1,8,0,0,0);
    }
    if (uVar9 == 0) {
      if (param_5 == (uint *)0x0) {
        wVar6 = *(word *)(param_1 + 0x38);
      }
      else {
        uVar3 = *param_5;
        if (uVar3 == 0) {
          wVar6 = *(word *)(param_1 + 0x38);
        }
        else {
          pcVar7 = *(code **)(*(int *)(iVar12 + 4) + 0xc);
          if (pcVar7 == (code *)0x0) {
            wVar6 = *(word *)(param_1 + 0x38);
          }
          else {
            (*pcVar7)(uVar3);
loc_F001F8F0:
            wVar6 = *(word *)(param_1 + 0x38);
            uVar9 = uVar3;
          }
        }
      }
    }
    else {
      wVar6 = *(word *)(param_1 + 0x38);
    }
  }
  else {
    wVar6 = *(word *)(param_1 + 0x38);
  }
loc_F001F8F4:
  *(word *)(param_1 + 0x38) = wVar6 & 0xfffe;
  if ((wVar6 & 2) != 0) {
    *(word *)(param_1 + 0x38) = wVar6 & 0xfffc;
    _wakeup(param_1 + 0x38);
  }
  _splx(*(undefined4 *)((int)register0x00000038 + -0xc));
locret_F001F91C:
  return CONCAT44(param_2,uVar9);
}
