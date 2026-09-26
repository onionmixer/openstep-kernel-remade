
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
  undefined (*pauVar1) [30];
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  undefined *puVar5;
  undefined (*pauVar6) [25];
  undefined4 *puVar7;
  int iVar8;
  undefined8 in_o2_3;
  uint uVar9;
  undefined8 in_o4_5;
  undefined4 unaff_l0;
  int *piVar10;
  undefined4 unaff_l1;
  undefined *puVar11;
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
  
  iVar8 = (int)((qword)in_o4_5 >> 0x20);
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
  puVar7 = (undefined4 *)((qword)in_o2_3 >> 0x20);
  iVar4 = (int)in_o2_3;
  puVar11 = (undefined *)0xfffffd3e;
  iVar2 = iVar4;
  _strcmp(iVar4,aEvSetscreen);
  if (iVar2 == 0) {
    if (iVar8 == 7) {
      _objc_msgSend(param_1,paEvsetscreen,puVar7);
      puVar11 = param_1;
    }
    goto locret_F00D1C14;
  }
  iVar2 = iVar4;
  _strcmp(iVar4,aEvStartcursor);
  if (iVar2 == 0) {
    _objc_msgSend(param_1,paStartcursor);
    puVar11 = (undefined *)0x0;
    goto locret_F00D1C14;
  }
  iVar2 = iVar4;
  _strcmp(iVar4,aEvMousepositio);
  if (iVar2 == 0) {
    if (iVar8 != 2) goto locret_F00D1C14;
    *(sword *)((int)register0x00000038 + -0x18) = (sword)*puVar7;
    *(sword *)((int)register0x00000038 + -0x16) = (sword)puVar7[1];
    _objc_msgSend(*(undefined4 *)(param_1 + 0x110),paLock);
    _objc_msgSend(param_1,paSetcursorposit,(undefined *)((int)register0x00000038 + -0x18));
    param_1 = *(undefined **)(param_1 + 0x110);
    pauVar6 = paUnlock;
  }
  else {
    iVar2 = iVar4;
    _strcmp(iVar4,aEvsSetwaitthre);
    if (iVar2 == 0) {
      puVar11 = (undefined *)((int)register0x00000038 + -0x30);
      iVar8 = 0;
      do {
        *(undefined4 *)(puVar11 + -8) = *(undefined4 *)(iVar8 + (int)puVar7);
        puVar11 = puVar11 + 4;
        iVar8 = iVar8 + 4;
      } while (puVar11 <= (undefined *)((int)register0x00000038 + -0x2c));
      uVar3 = *(undefined4 *)(param_1 + 0x110);
      *(undefined8 *)((int)register0x00000038 + -0x30) =
           *(undefined8 *)((int)register0x00000038 + -0x38);
      _objc_msgSend(uVar3,paLock);
      if (param_1[0x1d2] == '\0') {
loc_F00D1B58:
        param_1 = *(undefined **)(param_1 + 0x110);
        pauVar6 = paUnlock;
      }
      else {
        *(word *)(*(int *)(param_1 + 0x168) + 0x4c) =
             (word)((int)((qword)*(undefined8 *)((int)register0x00000038 + -0x30) >> 0x20) << 8) |
             (word)(byte)((qword)*(undefined8 *)((int)register0x00000038 + -0x30) >> 0x18);
        param_1 = *(undefined **)(param_1 + 0x110);
        pauVar6 = paUnlock;
      }
    }
    else {
      iVar2 = iVar4;
      _strcmp(iVar4,aEvsSetwaitsust);
      if (iVar2 == 0) {
        _objc_msgSend(*(undefined4 *)(param_1 + 0x110),paLock);
        pauVar6 = paUnlock;
        puVar11 = (undefined *)((int)register0x00000038 + -0x30);
        iVar8 = 0;
        do {
          *(undefined4 *)(puVar11 + -8) = *(undefined4 *)(iVar8 + (int)puVar7);
          puVar11 = puVar11 + 4;
          iVar8 = iVar8 + 4;
        } while (puVar11 <= (undefined *)((int)register0x00000038 + -0x2c));
        *(undefined8 *)(param_1 + 0x1d8) = *(undefined8 *)((int)register0x00000038 + -0x38);
        param_1 = *(undefined **)(param_1 + 0x110);
      }
      else {
        iVar2 = iVar4;
        _strcmp(iVar4,aEvsSetwaitfram);
        if (iVar2 == 0) {
          _objc_msgSend(*(undefined4 *)(param_1 + 0x110),paLock);
          pauVar6 = paUnlock;
          puVar11 = (undefined *)((int)register0x00000038 + -0x30);
          iVar8 = 0;
          do {
            *(undefined4 *)(puVar11 + -8) = *(undefined4 *)(iVar8 + (int)puVar7);
            puVar11 = puVar11 + 4;
            iVar8 = iVar8 + 4;
          } while (puVar11 <= (undefined *)((int)register0x00000038 + -0x2c));
          *(undefined8 *)(param_1 + 0x1e8) = *(undefined8 *)((int)register0x00000038 + -0x38);
          param_1 = *(undefined **)(param_1 + 0x110);
        }
        else {
          iVar2 = iVar4;
          _strcmp(iVar4,aEvsSetbrightne);
          if (iVar2 == 0) {
            _objc_msgSend(*(undefined4 *)(param_1 + 0x110),paLock);
            _objc_msgSend(param_1,paSetbrightness,*puVar7);
            param_1 = *(undefined **)(param_1 + 0x110);
            pauVar6 = paUnlock;
          }
          else {
            iVar2 = iVar4;
            _strcmp(iVar4,aEvsSetattenuat);
            if (iVar2 == 0) {
              _objc_msgSend(*(undefined4 *)(param_1 + 0x110),paLock);
              _objc_msgSend(param_1,paSetuseraudiovo,*puVar7);
              param_1 = *(undefined **)(param_1 + 0x110);
              pauVar6 = paUnlock;
            }
            else {
              iVar2 = iVar4;
              _strcmp(iVar4,aEvsSetautodimb);
              if (iVar2 == 0) {
                _objc_msgSend(*(undefined4 *)(param_1 + 0x110),paLock);
                _objc_msgSend(param_1,paSetautodimbrig,*puVar7);
                param_1 = *(undefined **)(param_1 + 0x110);
                pauVar6 = paUnlock;
              }
              else {
                iVar2 = iVar4;
                _strcmp(iVar4,aEvsSetclicktim);
                if (iVar2 == 0) {
                  puVar11 = (undefined *)((int)register0x00000038 + -0x30);
                  iVar8 = 0;
                  do {
                    *(undefined4 *)(puVar11 + -8) = *(undefined4 *)(iVar8 + (int)puVar7);
                    puVar11 = puVar11 + 4;
                    iVar8 = iVar8 + 4;
                  } while (puVar11 <= (undefined *)((int)register0x00000038 + -0x2c));
                  uVar3 = *(undefined4 *)(param_1 + 0x110);
                  *(undefined8 *)((int)register0x00000038 + -0x30) =
                       *(undefined8 *)((int)register0x00000038 + -0x38);
                  _objc_msgSend(uVar3,paLock);
                  pauVar6 = paUnlock;
                  *(uint *)(param_1 + 0x1bc) =
                       (int)((qword)*(undefined8 *)((int)register0x00000038 + -0x30) >> 0x20) << 8 |
                       (uint)*(undefined8 *)((int)register0x00000038 + -0x30) >> 0x18;
                  _objc_msgSend(*(undefined4 *)(param_1 + 0x110),pauVar6);
                  puVar11 = (undefined *)0x0;
                  goto locret_F00D1C14;
                }
                iVar2 = iVar4;
                _strcmp(iVar4,aEvsSetclickspa);
                if (iVar2 == 0) {
                  _objc_msgSend(*(undefined4 *)(param_1 + 0x110),paLock);
                  *(sword *)(param_1 + 0x1b0) = (sword)*puVar7;
                  pauVar6 = paUnlock;
                  *(sword *)(param_1 + 0x1b2) = (sword)puVar7[1];
                  _objc_msgSend(*(undefined4 *)(param_1 + 0x110),pauVar6);
                  puVar11 = (undefined *)0x0;
                  goto locret_F00D1C14;
                }
                iVar2 = iVar4;
                _strcmp(iVar4,aEvsSetautodimt);
                if (iVar2 == 0) {
                  puVar11 = (undefined *)((int)register0x00000038 + -0x30);
                  iVar8 = 0;
                  do {
                    *(undefined4 *)(puVar11 + -8) = *(undefined4 *)(iVar8 + (int)puVar7);
                    puVar11 = puVar11 + 4;
                    iVar8 = iVar8 + 4;
                  } while (puVar11 <= (undefined *)((int)register0x00000038 + -0x2c));
                  uVar3 = *(undefined4 *)(param_1 + 0x110);
                  *(undefined8 *)((int)register0x00000038 + -0x30) =
                       *(undefined8 *)((int)register0x00000038 + -0x38);
                  _objc_msgSend(uVar3,paLock);
                  pauVar6 = paUnlock;
                  uVar9 = (int)((qword)*(undefined8 *)((int)register0x00000038 + -0x30) >> 0x20) <<
                          8 | (uint)*(undefined8 *)((int)register0x00000038 + -0x30) >> 0x18;
                  *(uint *)(param_1 + 0x1a4) =
                       (*(int *)(param_1 + 0x1a4) - *(int *)(param_1 + 0x1a0)) + uVar9;
                  *(uint *)(param_1 + 0x1a0) = uVar9;
                  _objc_msgSend(*(undefined4 *)(param_1 + 0x110),pauVar6);
                  puVar11 = (undefined *)0x0;
                  goto locret_F00D1C14;
                }
                iVar2 = iVar4;
                _strcmp(iVar4,aEvsSetautodims);
                if (iVar2 == 0) {
                  _objc_msgSend(*(undefined4 *)(param_1 + 0x110),paLock);
                  _objc_msgSend(param_1,paForceautodimst,(int)*(char *)((int)puVar7 + 3));
                  param_1 = *(undefined **)(param_1 + 0x110);
                  pauVar6 = paUnlock;
                }
                else {
                  iVar2 = iVar4;
                  _strcmp(iVar4,aEvsResetmouse);
                  pauVar6 = (undefined (*) [25])paResetmousepara;
                  if ((iVar2 != 0) &&
                     (iVar2 = iVar4, _strcmp(iVar4,aEvsResetkeyboa), pauVar6 = paResetkeyboardp,
                     iVar2 != 0)) {
                    iVar2 = iVar4;
                    _strcmp(iVar4,aEvLlpostevent);
                    if ((iVar2 != 0) && (iVar2 = iVar4, _strcmp(iVar4,aEvPointerllpos), iVar2 != 0))
                    {
                      _objc_msgSend(*(undefined4 *)(param_1 + 0x170),paLock);
                      piVar10 = *(int **)(param_1 + 0x174);
                      if ((int *)(param_1 + 0x174) == piVar10) {
                        uVar3 = *(undefined4 *)(param_1 + 0x170);
                      }
                      else {
                        do {
                          puVar5 = (undefined *)*piVar10;
                          piVar10 = (int *)piVar10[1];
                          _objc_msgSend(puVar5,paSetintvaluesFo_0,puVar7);
                          if (puVar5 != (undefined *)0xfffffd3e) {
                            puVar11 = puVar5;
                          }
                        } while ((int *)(param_1 + 0x174) != piVar10);
                        uVar3 = *(undefined4 *)(param_1 + 0x170);
                      }
                      _objc_msgSend(uVar3,paUnlock);
                      puVar5 = (undefined *)((int)register0x00000038 + -0x10);
                      if (puVar11 == (undefined *)0xfffffd3e) {
                        *(undefined **)((int)register0x00000038 + -0x10) = param_1;
                        *(undefined4 *)((int)register0x00000038 + -0xc) = uRamf01421e0;
                        _objc_msgSendSuper(puVar5,paSetintvaluesFo_0,puVar7);
                        puVar11 = puVar5;
                      }
                      goto locret_F00D1C14;
                    }
                    if (iVar8 != 6) goto locret_F00D1C14;
                    *(sword *)((int)register0x00000038 + -0x18) = (sword)puVar7[1];
                    *(sword *)((int)register0x00000038 + -0x16) = (sword)puVar7[2];
                    *(undefined4 *)((int)register0x00000038 + -0x28) = puVar7[3];
                    *(undefined4 *)((int)register0x00000038 + -0x24) = puVar7[4];
                    *(undefined4 *)((int)register0x00000038 + -0x20) = puVar7[5];
                    _objc_msgSend(*(undefined4 *)(param_1 + 0x110),paLock);
                    _strcmp(iVar4,aEvPointerllpos);
                    if (iVar4 == 0) {
                      _objc_msgSend(param_1,paSetcursorposit,
                                    (undefined *)((int)register0x00000038 + -0x18));
                    }
                    pauVar1 = paPosteventAtAtt;
                    uVar3 = *puVar7;
                    _IOGetTimestamp((undefined *)((int)register0x00000038 + -0x38));
                    _objc_msgSend(param_1,pauVar1,uVar3);
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
  _objc_msgSend(param_1,pauVar6);
  puVar11 = (undefined *)0x0;
locret_F00D1C14:
  return CONCAT44(param_2,puVar11);
}
