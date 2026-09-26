
/* WARNING: Removing unreachable block (ram,0xf00d16e8) */
/* WARNING: Removing unreachable block (ram,0xf00d17cc) */
/* WARNING: Removing unreachable block (ram,0xf00d1810) */
/* WARNING: Removing unreachable block (ram,0xf00d1854) */
/* WARNING: Removing unreachable block (ram,0xf00d1a04) */
/* WARNING: Removing unreachable block (ram,0xf00d1b50) */
/* WARNING: Removing unreachable block (ram,0xf00d1b00) */
/* WARNING: Removing unreachable block (ram,0xf00d1ad0) */
/* WARNING: Removing unreachable block (ram,0xf00d1bd4) */
/* WARNING: Removing unreachable block (ram,0xf00d1b74) */
/* WARNING: Removing unreachable block (ram,0xf00d1a68) */
/* WARNING: Removing unreachable block (ram,0xf00d1a18) */
/* WARNING: Removing unreachable block (ram,0xf00d19c4) */
/* WARNING: Removing unreachable block (ram,0xf00d193c) */
/* WARNING: Removing unreachable block (ram,0xf00d1908) */
/* WARNING: Removing unreachable block (ram,0xf00d18dc) */
/* WARNING: Removing unreachable block (ram,0xf00d1868) */
/* WARNING: Removing unreachable block (ram,0xf00d17e0) */
/* WARNING: Removing unreachable block (ram,0xf00d1734) */
/* WARNING: Removing unreachable block (ram,0xf00d1690) */
/* WARNING: Removing unreachable block (ram,0xf00d1634) */
/* WARNING: Removing unreachable block (ram,0xf00d15e8) */
/* WARNING: Removing unreachable block (ram,0xf00d15b8) */
/* WARNING: Removing unreachable block (ram,0xf00d15a4) */
/* WARNING: Removing unreachable block (ram,0xf00d15d8) */
/* WARNING: Removing unreachable block (ram,0xf00d1620) */
/* WARNING: Removing unreachable block (ram,0xf00d1648) */
/* WARNING: Removing unreachable block (ram,0xf00d16cc) */
/* WARNING: Removing unreachable block (ram,0xf00d179c) */
/* WARNING: Removing unreachable block (ram,0xf00d1824) */
/* WARNING: Removing unreachable block (ram,0xf00d18b4) */
/* WARNING: Removing unreachable block (ram,0xf00d18ec) */
/* WARNING: Removing unreachable block (ram,0xf00d192c) */
/* WARNING: Removing unreachable block (ram,0xf00d1988) */
/* WARNING: Removing unreachable block (ram,0xf00d19d4) */
/* WARNING: Removing unreachable block (ram,0xf00d1a40) */
/* WARNING: Removing unreachable block (ram,0xf00d1a80) */
/* WARNING: Removing unreachable block (ram,0xf00d1bac) */
/* WARNING: Removing unreachable block (ram,0xf00d1c08) */
/* WARNING: Removing unreachable block (ram,0xf00d1ae0) */
/* WARNING: Removing unreachable block (ram,0xf00d1b18) */
/* WARNING: Removing unreachable block (ram,0xf00d19f0) */
/* WARNING: Removing unreachable block (ram,0xf00d1840) */
/* WARNING: Removing unreachable block (ram,0xf00d17fc) */
/* WARNING: Removing unreachable block (ram,0xf00d17b8) */
/* WARNING: Removing unreachable block (ram,0xf00d1750) */
/* WARNING: Removing unreachable block (ram,0xf00d1b64) */
/* WARNING: Removing unreachable block (ram,0xf00d157c) */

undefined8 -[EventDriver setIntValues:forParameter:count:](undefined *param_1,undefined4 param_2)

{
  undefined7 *puVar1;
  undefined (*pauVar2) [30];
  int iVar3;
  undefined4 uVar4;
  int iVar5;
  undefined *puVar6;
  undefined (*pauVar7) [25];
  undefined4 *puVar8;
  int iVar9;
  undefined8 in_o2_3;
  uint uVar10;
  undefined8 in_o4_5;
  undefined4 unaff_l0;
  int *piVar11;
  undefined4 unaff_l1;
  undefined *puVar12;
  undefined4 unaff_l3;
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
  bool in_DECOMPILE_MODE;
  int in_CWP;
  undefined auStackX_0 [92];
  undefined4 auStack_38 [14];
  
  iVar9 = (int)((qword)in_o4_5 >> 0x20);
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
  puVar8 = (undefined4 *)((qword)in_o2_3 >> 0x20);
  iVar5 = (int)in_o2_3;
  puVar12 = (undefined *)0xfffffd3e;
  iVar3 = iVar5;
  _strcmp(iVar5,aEvSetscreen);
  if (iVar3 == 0) {
    if (iVar9 == 7) {
      _objc_msgSend(param_1,paEvsetscreen,puVar8);
      puVar12 = param_1;
    }
    goto locret_F00D1C14;
  }
  iVar3 = iVar5;
  _strcmp(iVar5,aEvStartcursor);
  if (iVar3 == 0) {
    _objc_msgSend(param_1,paStartcursor);
    puVar12 = (undefined *)0x0;
    goto locret_F00D1C14;
  }
  iVar3 = iVar5;
  _strcmp(iVar5,aEvMousepositio);
  if (iVar3 == 0) {
    if (iVar9 != 2) goto locret_F00D1C14;
    *(sword *)((int)register0x00000038 + -0x18) = (sword)*puVar8;
    *(sword *)((int)register0x00000038 + -0x16) = (sword)puVar8[1];
    _objc_msgSend(*(undefined4 *)(param_1 + 0x110),paLock);
    _objc_msgSend(param_1,paSetcursorposit,(undefined *)((int)register0x00000038 + -0x18));
    param_1 = *(undefined **)(param_1 + 0x110);
    pauVar7 = (undefined (*) [25])paUnlock;
  }
  else {
    iVar3 = iVar5;
    _strcmp(iVar5,aEvsSetwaitthre);
    if (iVar3 == 0) {
      puVar12 = (undefined *)((int)register0x00000038 + -0x30);
      iVar9 = 0;
      do {
        *(undefined4 *)(puVar12 + -8) = *(undefined4 *)(iVar9 + (int)puVar8);
        puVar12 = puVar12 + 4;
        iVar9 = iVar9 + 4;
      } while (puVar12 <= (undefined *)((int)register0x00000038 + -0x2c));
      uVar4 = *(undefined4 *)(param_1 + 0x110);
      *(undefined8 *)((int)register0x00000038 + -0x30) =
           *(undefined8 *)((int)register0x00000038 + -0x38);
      _objc_msgSend(uVar4,paLock);
      if (param_1[0x1d2] == '\0') {
loc_F00D1B58:
        param_1 = *(undefined **)(param_1 + 0x110);
        pauVar7 = (undefined (*) [25])paUnlock;
      }
      else {
        *(word *)(*(int *)(param_1 + 0x168) + 0x4c) =
             (word)((int)((qword)*(undefined8 *)((int)register0x00000038 + -0x30) >> 0x20) << 8) |
             (word)(byte)((qword)*(undefined8 *)((int)register0x00000038 + -0x30) >> 0x18);
        param_1 = *(undefined **)(param_1 + 0x110);
        pauVar7 = (undefined (*) [25])paUnlock;
      }
    }
    else {
      iVar3 = iVar5;
      _strcmp(iVar5,aEvsSetwaitsust);
      if (iVar3 == 0) {
        _objc_msgSend(*(undefined4 *)(param_1 + 0x110),paLock);
        pauVar7 = (undefined (*) [25])paUnlock;
        puVar12 = (undefined *)((int)register0x00000038 + -0x30);
        iVar9 = 0;
        do {
          *(undefined4 *)(puVar12 + -8) = *(undefined4 *)(iVar9 + (int)puVar8);
          puVar12 = puVar12 + 4;
          iVar9 = iVar9 + 4;
        } while (puVar12 <= (undefined *)((int)register0x00000038 + -0x2c));
        *(undefined8 *)(param_1 + 0x1d8) = *(undefined8 *)((int)register0x00000038 + -0x38);
        param_1 = *(undefined **)(param_1 + 0x110);
      }
      else {
        iVar3 = iVar5;
        _strcmp(iVar5,aEvsSetwaitfram);
        if (iVar3 == 0) {
          _objc_msgSend(*(undefined4 *)(param_1 + 0x110),paLock);
          pauVar7 = (undefined (*) [25])paUnlock;
          puVar12 = (undefined *)((int)register0x00000038 + -0x30);
          iVar9 = 0;
          do {
            *(undefined4 *)(puVar12 + -8) = *(undefined4 *)(iVar9 + (int)puVar8);
            puVar12 = puVar12 + 4;
            iVar9 = iVar9 + 4;
          } while (puVar12 <= (undefined *)((int)register0x00000038 + -0x2c));
          *(undefined8 *)(param_1 + 0x1e8) = *(undefined8 *)((int)register0x00000038 + -0x38);
          param_1 = *(undefined **)(param_1 + 0x110);
        }
        else {
          iVar3 = iVar5;
          _strcmp(iVar5,aEvsSetbrightne);
          if (iVar3 == 0) {
            _objc_msgSend(*(undefined4 *)(param_1 + 0x110),paLock);
            _objc_msgSend(param_1,paSetbrightness,*puVar8);
            param_1 = *(undefined **)(param_1 + 0x110);
            pauVar7 = (undefined (*) [25])paUnlock;
          }
          else {
            iVar3 = iVar5;
            _strcmp(iVar5,aEvsSetattenuat);
            if (iVar3 == 0) {
              _objc_msgSend(*(undefined4 *)(param_1 + 0x110),paLock);
              _objc_msgSend(param_1,paSetuseraudiovo,*puVar8);
              param_1 = *(undefined **)(param_1 + 0x110);
              pauVar7 = (undefined (*) [25])paUnlock;
            }
            else {
              iVar3 = iVar5;
              _strcmp(iVar5,aEvsSetautodimb);
              if (iVar3 == 0) {
                _objc_msgSend(*(undefined4 *)(param_1 + 0x110),paLock);
                _objc_msgSend(param_1,paSetautodimbrig,*puVar8);
                param_1 = *(undefined **)(param_1 + 0x110);
                pauVar7 = (undefined (*) [25])paUnlock;
              }
              else {
                iVar3 = iVar5;
                _strcmp(iVar5,aEvsSetclicktim);
                if (iVar3 == 0) {
                  puVar12 = (undefined *)((int)register0x00000038 + -0x30);
                  iVar9 = 0;
                  do {
                    *(undefined4 *)(puVar12 + -8) = *(undefined4 *)(iVar9 + (int)puVar8);
                    puVar12 = puVar12 + 4;
                    iVar9 = iVar9 + 4;
                  } while (puVar12 <= (undefined *)((int)register0x00000038 + -0x2c));
                  uVar4 = *(undefined4 *)(param_1 + 0x110);
                  *(undefined8 *)((int)register0x00000038 + -0x30) =
                       *(undefined8 *)((int)register0x00000038 + -0x38);
                  _objc_msgSend(uVar4,paLock);
                  puVar1 = paUnlock;
                  *(uint *)(param_1 + 0x1bc) =
                       (int)((qword)*(undefined8 *)((int)register0x00000038 + -0x30) >> 0x20) << 8 |
                       (uint)*(undefined8 *)((int)register0x00000038 + -0x30) >> 0x18;
                  _objc_msgSend(*(undefined4 *)(param_1 + 0x110),puVar1);
                  puVar12 = (undefined *)0x0;
                  goto locret_F00D1C14;
                }
                iVar3 = iVar5;
                _strcmp(iVar5,aEvsSetclickspa);
                if (iVar3 == 0) {
                  _objc_msgSend(*(undefined4 *)(param_1 + 0x110),paLock);
                  *(sword *)(param_1 + 0x1b0) = (sword)*puVar8;
                  puVar1 = paUnlock;
                  *(sword *)(param_1 + 0x1b2) = (sword)puVar8[1];
                  _objc_msgSend(*(undefined4 *)(param_1 + 0x110),puVar1);
                  puVar12 = (undefined *)0x0;
                  goto locret_F00D1C14;
                }
                iVar3 = iVar5;
                _strcmp(iVar5,aEvsSetautodimt);
                if (iVar3 == 0) {
                  puVar12 = (undefined *)((int)register0x00000038 + -0x30);
                  iVar9 = 0;
                  do {
                    *(undefined4 *)(puVar12 + -8) = *(undefined4 *)(iVar9 + (int)puVar8);
                    puVar12 = puVar12 + 4;
                    iVar9 = iVar9 + 4;
                  } while (puVar12 <= (undefined *)((int)register0x00000038 + -0x2c));
                  uVar4 = *(undefined4 *)(param_1 + 0x110);
                  *(undefined8 *)((int)register0x00000038 + -0x30) =
                       *(undefined8 *)((int)register0x00000038 + -0x38);
                  _objc_msgSend(uVar4,paLock);
                  puVar1 = paUnlock;
                  uVar10 = (int)((qword)*(undefined8 *)((int)register0x00000038 + -0x30) >> 0x20) <<
                           8 | (uint)*(undefined8 *)((int)register0x00000038 + -0x30) >> 0x18;
                  *(uint *)(param_1 + 0x1a4) =
                       (*(int *)(param_1 + 0x1a4) - *(int *)(param_1 + 0x1a0)) + uVar10;
                  *(uint *)(param_1 + 0x1a0) = uVar10;
                  _objc_msgSend(*(undefined4 *)(param_1 + 0x110),puVar1);
                  puVar12 = (undefined *)0x0;
                  goto locret_F00D1C14;
                }
                iVar3 = iVar5;
                _strcmp(iVar5,aEvsSetautodims);
                if (iVar3 == 0) {
                  _objc_msgSend(*(undefined4 *)(param_1 + 0x110),paLock);
                  _objc_msgSend(param_1,paForceautodimst,(int)*(char *)((int)puVar8 + 3));
                  param_1 = *(undefined **)(param_1 + 0x110);
                  pauVar7 = (undefined (*) [25])paUnlock;
                }
                else {
                  iVar3 = iVar5;
                  _strcmp(iVar5,aEvsResetmouse);
                  pauVar7 = (undefined (*) [25])paResetmousepara;
                  if ((iVar3 != 0) &&
                     (iVar3 = iVar5, _strcmp(iVar5,aEvsResetkeyboa), pauVar7 = paResetkeyboardp,
                     iVar3 != 0)) {
                    iVar3 = iVar5;
                    _strcmp(iVar5,aEvLlpostevent);
                    if ((iVar3 != 0) && (iVar3 = iVar5, _strcmp(iVar5,aEvPointerllpos), iVar3 != 0))
                    {
                      _objc_msgSend(*(undefined4 *)(param_1 + 0x170),paLock);
                      piVar11 = *(int **)(param_1 + 0x174);
                      if ((int *)(param_1 + 0x174) == piVar11) {
                        uVar4 = *(undefined4 *)(param_1 + 0x170);
                      }
                      else {
                        do {
                          puVar6 = (undefined *)*piVar11;
                          piVar11 = (int *)piVar11[1];
                          _objc_msgSend(puVar6,paSetintvaluesFo_0,puVar8);
                          if (puVar6 != (undefined *)0xfffffd3e) {
                            puVar12 = puVar6;
                          }
                        } while ((int *)(param_1 + 0x174) != piVar11);
                        uVar4 = *(undefined4 *)(param_1 + 0x170);
                      }
                      _objc_msgSend(uVar4,paUnlock);
                      puVar6 = (undefined *)((int)register0x00000038 + -0x10);
                      if (puVar12 == (undefined *)0xfffffd3e) {
                        *(undefined **)((int)register0x00000038 + -0x10) = param_1;
                        *(undefined4 *)((int)register0x00000038 + -0xc) = uRamf01421e0;
                        _objc_msgSendSuper(puVar6,paSetintvaluesFo_0,puVar8);
                        puVar12 = puVar6;
                      }
                      goto locret_F00D1C14;
                    }
                    if (iVar9 != 6) goto locret_F00D1C14;
                    *(sword *)((int)register0x00000038 + -0x18) = (sword)puVar8[1];
                    *(sword *)((int)register0x00000038 + -0x16) = (sword)puVar8[2];
                    *(undefined4 *)((int)register0x00000038 + -0x28) = puVar8[3];
                    *(undefined4 *)((int)register0x00000038 + -0x24) = puVar8[4];
                    *(undefined4 *)((int)register0x00000038 + -0x20) = puVar8[5];
                    _objc_msgSend(*(undefined4 *)(param_1 + 0x110),paLock);
                    _strcmp(iVar5,aEvPointerllpos);
                    if (iVar5 == 0) {
                      _objc_msgSend(param_1,paSetcursorposit,
                                    (undefined *)((int)register0x00000038 + -0x18));
                    }
                    pauVar2 = paPosteventAtAtt;
                    uVar4 = *puVar8;
                    _IOGetTimestamp((undefined *)((int)register0x00000038 + -0x38));
                    _objc_msgSend(param_1,pauVar2,uVar4);
                    goto loc_F00D1B58;
                  }
                }
              }
            }
          }
        }
      }
    }
  }
  _objc_msgSend(param_1,pauVar7);
  puVar12 = (undefined *)0x0;
locret_F00D1C14:
  return CONCAT44(param_2,puVar12);
}

