
/* WARNING: Removing unreachable block (ram,0xf00f1554) */
/* WARNING: Removing unreachable block (ram,0xf00f1428) */
/* WARNING: Removing unreachable block (ram,0xf00f13ac) */
/* WARNING: Removing unreachable block (ram,0xf00f12d4) */
/* WARNING: Removing unreachable block (ram,0xf00f11b8) */
/* WARNING: Removing unreachable block (ram,0xf00f1140) */
/* WARNING: Removing unreachable block (ram,0xf00f10b0) */
/* WARNING: Removing unreachable block (ram,0xf00f0f54) */
/* WARNING: Removing unreachable block (ram,0xf00f0fac) */
/* WARNING: Removing unreachable block (ram,0xf00f0eb4) */
/* WARNING: Removing unreachable block (ram,0xf00f0e5c) */
/* WARNING: Removing unreachable block (ram,0xf00f0e14) */
/* WARNING: Removing unreachable block (ram,0xf00f0dac) */
/* WARNING: Removing unreachable block (ram,0xf00f0e0c) */
/* WARNING: Removing unreachable block (ram,0xf00f0e30) */
/* WARNING: Removing unreachable block (ram,0xf00f0e9c) */
/* WARNING: Removing unreachable block (ram,0xf00f0f98) */
/* WARNING: Removing unreachable block (ram,0xf00f0ef4) */
/* WARNING: Removing unreachable block (ram,0xf00f0ffc) */
/* WARNING: Removing unreachable block (ram,0xf00f110c) */
/* WARNING: Removing unreachable block (ram,0xf00f11a8) */
/* WARNING: Removing unreachable block (ram,0xf00f127c) */
/* WARNING: Removing unreachable block (ram,0xf00f1314) */
/* WARNING: Removing unreachable block (ram,0xf00f140c) */
/* WARNING: Removing unreachable block (ram,0xf00f14b8) */
/* WARNING: Removing unreachable block (ram,0xf00f157c) */
/* WARNING: Removing unreachable block (ram,0xf00f0d58) */

undefined8 _objc_registerModule(int *param_1,code *param_2)

{
  bool bVar1;
  int *piVar2;
  int iVar3;
  int *piVar4;
  uint uVar5;
  uint *puVar6;
  uint uVar7;
  undefined4 unaff_l0;
  int iVar8;
  undefined4 unaff_l1;
  uint uVar9;
  undefined4 unaff_l3;
  int *piVar10;
  undefined4 unaff_l4;
  int iVar11;
  int iVar12;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 uVar13;
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
  bVar1 = false;
  piVar2 = param_1;
  _getsectdatafromheader(param_1,&aObjc,aModuleInfo,(undefined *)((int)register0x00000038 + -0xc));
  *(undefined4 *)((int)register0x00000038 + -0x10) = *(undefined4 *)((int)register0x00000038 + -0xc)
  ;
  if (piVar2 != (int *)0x0) {
    iVar3 = *(int *)((int)register0x00000038 + -0x10);
    piVar4 = piVar2;
    do {
      if (iVar3 == 0) break;
      iVar11 = 0;
      iVar3 = piVar4[3];
      if (*(sword *)(iVar3 + 8) == 0) {
        iVar3 = piVar4[1];
      }
      else {
        iVar12 = 0;
        do {
          iVar3 = *(int *)(iVar12 + iVar3 + 0xc);
          _objc_lookUpClass();
          if (iVar3 != 0) {
            bVar1 = true;
          }
          iVar11 = iVar11 + 1;
          iVar3 = piVar4[3];
          iVar12 = iVar11 * 4;
        } while (iVar11 < (int)(uint)*(word *)(iVar3 + 8));
        iVar3 = piVar4[1];
      }
      *(int *)((int)register0x00000038 + -0x10) = *(int *)((int)register0x00000038 + -0x10) - iVar3;
      piVar4 = (int *)((int)piVar4 + piVar4[1]);
      iVar3 = *(int *)((int)register0x00000038 + -0x10);
    } while (piVar4 != (int *)0x0);
  }
  if (bVar1) {
    uVar13 = 1;
  }
  else {
    __objc_addHeader(param_1,0);
    sub_F00F0CC0(param_1);
    piVar4 = param_1;
    _getsectdatafromheader
              (param_1,&aObjc,aMessageRefs,(undefined *)((int)register0x00000038 + -0x10));
    uVar5 = *(uint *)((int)register0x00000038 + -0x10);
    if (piVar4 != (int *)0x0) {
      uVar9 = 0;
      if (uVar5 >> 2 != 0) {
        iVar3 = 0;
        while( true ) {
          iVar11 = *(int *)((int)piVar4 + iVar3);
          _sel_registerName();
          if (*(int *)((int)piVar4 + iVar3) != iVar11) {
            *(int *)((int)piVar4 + iVar3) = iVar11;
          }
          uVar9 = uVar9 + 1;
          if (uVar5 >> 2 <= uVar9) break;
          iVar3 = uVar9 * 4;
        }
      }
    }
    piVar4 = param_1;
    _getsectdatafromheader(param_1,&aObjc,aProtocol,(undefined *)((int)register0x00000038 + -0x10));
    uVar5 = 0;
    if (piVar4 != (int *)0x0) {
      while( true ) {
        uVar9 = *(uint *)((int)register0x00000038 + -0x10);
        udiv(uVar9,0x14);
        if (uVar9 <= uVar5) break;
        puVar6 = (uint *)piVar4[uVar5 * 5 + 3];
        if (puVar6 != (uint *)0x0) {
          for (uVar9 = 0; uVar9 < *puVar6; uVar9 = uVar9 + 1) {
            uVar7 = puVar6[uVar9 * 2 + 1];
            _sel_registerName();
            if (puVar6[uVar9 * 2 + 1] != uVar7) {
              puVar6[uVar9 * 2 + 1] = uVar7;
            }
          }
        }
        puVar6 = (uint *)piVar4[uVar5 * 5 + 4];
        if (puVar6 == (uint *)0x0) {
          uVar5 = uVar5 + 1;
        }
        else {
          for (uVar9 = 0; uVar9 < *puVar6; uVar9 = uVar9 + 1) {
            uVar7 = puVar6[uVar9 * 2 + 1];
            _sel_registerName();
            if (puVar6[uVar9 * 2 + 1] != uVar7) {
              puVar6[uVar9 * 2 + 1] = uVar7;
            }
          }
          uVar5 = uVar5 + 1;
        }
      }
      uVar13 = *(undefined4 *)((int)register0x00000038 + -0x10);
      udiv(uVar13,0x14);
      _objc_msgSend(paProtocol_0,paFixupNumelemen,piVar4,uVar13);
    }
    *(undefined4 *)((int)register0x00000038 + -0x10) =
         *(undefined4 *)((int)register0x00000038 + -0xc);
    if (piVar2 != (int *)0x0) {
      iVar3 = *(int *)((int)register0x00000038 + -0x10);
      piVar4 = piVar2;
      do {
        if (iVar3 == 0) break;
        iVar11 = 0;
        iVar3 = piVar4[3];
        if (*(sword *)(iVar3 + 8) == 0) {
          iVar3 = *(int *)((int)register0x00000038 + -0x10);
        }
        else {
          iVar12 = 0;
          do {
            _objc_addClass(*(undefined4 *)(iVar12 + iVar3 + 0xc));
            iVar11 = iVar11 + 1;
            iVar3 = piVar4[3];
            iVar12 = iVar11 * 4;
          } while (iVar11 < (int)(uint)*(word *)(iVar3 + 8));
          iVar3 = *(int *)((int)register0x00000038 + -0x10);
        }
        *(int *)((int)register0x00000038 + -0x10) = iVar3 - piVar4[1];
        piVar4 = (int *)((int)piVar4 + piVar4[1]);
        iVar3 = *(int *)((int)register0x00000038 + -0x10);
      } while (piVar4 != (int *)0x0);
    }
    *(undefined4 *)((int)register0x00000038 + -0x10) =
         *(undefined4 *)((int)register0x00000038 + -0xc);
    if (piVar2 != (int *)0x0) {
      iVar3 = *(int *)((int)register0x00000038 + -0x10);
      piVar4 = piVar2;
      do {
        if (iVar3 == 0) break;
        iVar12 = 0;
        iVar3 = piVar4[3];
        iVar11 = *(int *)((int)register0x00000038 + -0x10);
        if (*(sword *)(iVar3 + 8) != 0) {
          iVar11 = 0;
          do {
            piVar10 = *(int **)(iVar11 + iVar3 + 0xc);
            iVar3 = piVar10[7];
            if (iVar3 == 0) {
              iVar3 = *piVar10;
            }
            else {
              for (uVar5 = 0; uVar5 < *(uint *)(iVar3 + 4); uVar5 = uVar5 + 1) {
                iVar8 = uVar5 * 0xc + 8;
                iVar11 = *(int *)(iVar3 + iVar8);
                _sel_registerName();
                if (*(int *)(iVar3 + iVar8) != iVar11) {
                  *(int *)(iVar3 + iVar8) = iVar11;
                }
              }
              iVar3 = *piVar10;
            }
            iVar3 = *(int *)(iVar3 + 0x1c);
            if (iVar3 != 0) {
              for (uVar5 = 0; uVar5 < *(uint *)(iVar3 + 4); uVar5 = uVar5 + 1) {
                iVar8 = uVar5 * 0xc + 8;
                iVar11 = *(int *)(iVar3 + iVar8);
                _sel_registerName();
                if (*(int *)(iVar3 + iVar8) != iVar11) {
                  *(int *)(iVar3 + iVar8) = iVar11;
                }
              }
            }
            __class_install_relationships(piVar10,*piVar4);
            if (*(int *)(*piVar10 + 0xc) == 3 || *(int *)(*piVar10 + 0xc) == 4) {
              if (piVar10[9] != 0) {
                piVar10[9] = piVar10[9] + -4;
                *(int *)(*piVar10 + 0x24) = *(int *)(*piVar10 + 0x24) + -4;
              }
              iVar3 = *piVar10;
            }
            else {
              iVar3 = *piVar10;
            }
            if ((*(int *)(iVar3 + 0xc) == 3) && (piVar10[9] != 0)) {
              __objc_inform(aUnableToInstal);
              __objc_inform(aClassSMustBeRe,piVar10[2]);
              piVar10[9] = 0;
              *(undefined4 *)(*piVar10 + 0x24) = 0;
            }
            iVar12 = iVar12 + 1;
            iVar3 = piVar4[3];
            iVar11 = iVar12 * 4;
          } while (iVar12 < (int)(uint)*(word *)(iVar3 + 8));
          iVar11 = *(int *)((int)register0x00000038 + -0x10);
        }
        *(int *)((int)register0x00000038 + -0x10) = iVar11 - piVar4[1];
        piVar4 = (int *)((int)piVar4 + piVar4[1]);
        iVar3 = *(int *)((int)register0x00000038 + -0x10);
      } while (piVar4 != (int *)0x0);
    }
    *(undefined4 *)((int)register0x00000038 + -0x10) =
         *(undefined4 *)((int)register0x00000038 + -0xc);
    if (piVar2 != (int *)0x0) {
      iVar3 = *(int *)((int)register0x00000038 + -0x10);
      piVar4 = piVar2;
      do {
        if (iVar3 == 0) break;
        iVar3 = piVar4[3];
        uVar5 = (uint)*(word *)(iVar3 + 8);
        iVar11 = *(int *)((int)register0x00000038 + -0x10);
        if (uVar5 < uVar5 + *(word *)(iVar3 + 10)) {
          do {
            iVar11 = *(int *)(uVar5 * 4 + iVar3 + 0xc);
            iVar3 = *(int *)(iVar11 + 8);
            if (iVar3 == 0) {
              iVar3 = *(int *)(iVar11 + 0xc);
            }
            else {
              for (uVar9 = 0; uVar9 < *(uint *)(iVar3 + 4); uVar9 = uVar9 + 1) {
                iVar8 = uVar9 * 0xc + 8;
                iVar12 = *(int *)(iVar3 + iVar8);
                _sel_registerName();
                if (*(int *)(iVar3 + iVar8) != iVar12) {
                  *(int *)(iVar3 + iVar8) = iVar12;
                }
              }
              iVar3 = *(int *)(iVar11 + 0xc);
            }
            if (iVar3 == 0) {
              iVar3 = piVar4[3];
            }
            else {
              for (uVar9 = 0; uVar9 < *(uint *)(iVar3 + 4); uVar9 = uVar9 + 1) {
                iVar12 = uVar9 * 0xc + 8;
                iVar11 = *(int *)(iVar3 + iVar12);
                _sel_registerName();
                if (*(int *)(iVar3 + iVar12) != iVar11) {
                  *(int *)(iVar3 + iVar12) = iVar11;
                }
              }
              iVar3 = piVar4[3];
            }
            __objc_add_category(*(undefined4 *)(uVar5 * 4 + iVar3 + 0xc),*piVar4);
            uVar5 = uVar5 + 1;
            iVar3 = piVar4[3];
          } while ((int)uVar5 < (int)((uint)*(word *)(iVar3 + 8) + (uint)*(word *)(iVar3 + 10)));
          iVar11 = *(int *)((int)register0x00000038 + -0x10);
        }
        *(int *)((int)register0x00000038 + -0x10) = iVar11 - piVar4[1];
        piVar4 = (int *)((int)piVar4 + piVar4[1]);
        iVar3 = *(int *)((int)register0x00000038 + -0x10);
      } while (piVar4 != (int *)0x0);
    }
    *(undefined4 *)((int)register0x00000038 + -0x10) =
         *(undefined4 *)((int)register0x00000038 + -0xc);
    if (piVar2 != (int *)0x0) {
      iVar3 = *(int *)((int)register0x00000038 + -0x10);
      piVar4 = piVar2;
      do {
        if (iVar3 == 0) break;
        iVar3 = *(int *)((int)register0x00000038 + -0x10);
        if (*piVar4 == 1) {
          uVar7 = *(uint *)piVar4[3];
          uVar5 = 0;
          uVar9 = ((uint *)piVar4[3])[1];
          if (uVar7 != 0) {
            iVar3 = 0;
            while( true ) {
              iVar11 = *(int *)(uVar9 + iVar3);
              _sel_registerName();
              if (*(int *)(uVar9 + iVar3) != iVar11) {
                *(int *)(uVar9 + iVar3) = iVar11;
              }
              uVar5 = uVar5 + 1;
              if (uVar7 <= uVar5) break;
              iVar3 = uVar5 * 4;
            }
          }
          iVar3 = *(int *)((int)register0x00000038 + -0x10);
        }
        *(int *)((int)register0x00000038 + -0x10) = iVar3 - piVar4[1];
        piVar4 = (int *)((int)piVar4 + piVar4[1]);
        iVar3 = *(int *)((int)register0x00000038 + -0x10);
      } while (piVar4 != (int *)0x0);
    }
    piVar4 = param_1;
    _getsectdatafromheader(param_1,&aObjc,aClsRefs,(undefined *)((int)register0x00000038 + -0x10));
    if (piVar4 != (int *)0x0) {
      for (uVar5 = 0; uVar5 < *(uint *)((int)register0x00000038 + -0x10) >> 2; uVar5 = uVar5 + 1) {
        iVar3 = piVar4[uVar5];
        _objc_getClass();
        piVar4[uVar5] = iVar3;
      }
    }
    *(undefined4 *)((int)register0x00000038 + -0x10) =
         *(undefined4 *)((int)register0x00000038 + -0xc);
    if (piVar2 != (int *)0x0) {
      iVar3 = *(int *)((int)register0x00000038 + -0x10);
      piVar4 = piVar2;
      do {
        if (iVar3 == 0) break;
        iVar12 = 0;
        iVar3 = piVar4[3];
        iVar11 = *(int *)((int)register0x00000038 + -0x10);
        if (*(sword *)(iVar3 + 8) != 0) {
          do {
            if (param_2 != (code *)0x0) {
              (*param_2)(*(undefined4 *)(iVar12 * 4 + iVar3 + 0xc),0);
            }
            sub_F00F0BBC(*(undefined4 *)(iVar12 * 4 + piVar4[3] + 0xc),param_1);
            iVar12 = iVar12 + 1;
            iVar3 = piVar4[3];
          } while (iVar12 < (int)(uint)*(word *)(iVar3 + 8));
          iVar11 = *(int *)((int)register0x00000038 + -0x10);
        }
        *(int *)((int)register0x00000038 + -0x10) = iVar11 - piVar4[1];
        piVar4 = (int *)((int)piVar4 + piVar4[1]);
        iVar3 = *(int *)((int)register0x00000038 + -0x10);
      } while (piVar4 != (int *)0x0);
    }
    *(undefined4 *)((int)register0x00000038 + -0x10) =
         *(undefined4 *)((int)register0x00000038 + -0xc);
    if (piVar2 != (int *)0x0) {
      iVar3 = *(int *)((int)register0x00000038 + -0x10);
      do {
        if (iVar3 == 0) {
          uVar13 = 0;
          goto locret_F00F15C8;
        }
        iVar3 = piVar2[3];
        uVar5 = (uint)*(word *)(iVar3 + 8);
        iVar11 = *(int *)((int)register0x00000038 + -0x10);
        if (uVar5 < uVar5 + *(word *)(iVar3 + 10)) {
          do {
            if (param_2 == (code *)0x0) {
              iVar3 = piVar2[3];
            }
            else {
              _objc_getClass(*(undefined4 *)(*(int *)(uVar5 * 4 + iVar3 + 0xc) + 4));
              (*param_2)();
              iVar3 = piVar2[3];
            }
            sub_F00F0BFC(*(undefined4 *)(uVar5 * 4 + iVar3 + 0xc),param_1);
            uVar5 = uVar5 + 1;
            iVar3 = piVar2[3];
          } while ((int)uVar5 < (int)((uint)*(word *)(iVar3 + 8) + (uint)*(word *)(iVar3 + 10)));
          iVar11 = *(int *)((int)register0x00000038 + -0x10);
        }
        *(int *)((int)register0x00000038 + -0x10) = iVar11 - piVar2[1];
        piVar2 = (int *)((int)piVar2 + piVar2[1]);
        iVar3 = *(int *)((int)register0x00000038 + -0x10);
      } while (piVar2 != (int *)0x0);
    }
    uVar13 = 0;
  }
locret_F00F15C8:
  return CONCAT44(param_2,uVar13);
}

