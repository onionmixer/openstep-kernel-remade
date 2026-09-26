
/* WARNING: Removing unreachable block (ram,0xf00d1384) */
/* WARNING: Removing unreachable block (ram,0xf00d1518) */
/* WARNING: Removing unreachable block (ram,0xf00d14bc) */
/* WARNING: Removing unreachable block (ram,0xf00d1418) */
/* WARNING: Removing unreachable block (ram,0xf00d13dc) */
/* WARNING: Removing unreachable block (ram,0xf00d1358) */
/* WARNING: Removing unreachable block (ram,0xf00d1278) */
/* WARNING: Removing unreachable block (ram,0xf00d11b4) */
/* WARNING: Removing unreachable block (ram,0xf00d112c) */
/* WARNING: Removing unreachable block (ram,0xf00d10a4) */
/* WARNING: Removing unreachable block (ram,0xf00d1070) */
/* WARNING: Removing unreachable block (ram,0xf00d1034) */
/* WARNING: Removing unreachable block (ram,0xf00d0f1c) */
/* WARNING: Removing unreachable block (ram,0xf00d0eb8) */
/* WARNING: Removing unreachable block (ram,0xf00d0ee4) */
/* WARNING: Removing unreachable block (ram,0xf00d0f48) */
/* WARNING: Removing unreachable block (ram,0xf00d1060) */
/* WARNING: Removing unreachable block (ram,0xf00d108c) */
/* WARNING: Removing unreachable block (ram,0xf00d10d0) */
/* WARNING: Removing unreachable block (ram,0xf00d1158) */
/* WARNING: Removing unreachable block (ram,0xf00d11e0) */
/* WARNING: Removing unreachable block (ram,0xf00d12a4) */
/* WARNING: Removing unreachable block (ram,0xf00d13b0) */
/* WARNING: Removing unreachable block (ram,0xf00d1400) */
/* WARNING: Removing unreachable block (ram,0xf00d1460) */
/* WARNING: Removing unreachable block (ram,0xf00d14f4) */
/* WARNING: Removing unreachable block (ram,0xf00d1550) */
/* WARNING: Removing unreachable block (ram,0xf00d1498) */
/* WARNING: Removing unreachable block (ram,0xf00d0e8c) */
/* WARNING: Heritage AFTER dead removal. Example location: o1 : 0xf00d1550 */
/* WARNING: Restarted to delay deadcode elimination for space: register */

int -[EventDriver getIntValues:forParameter:count:](int *param_1,undefined4 param_2,uint *param_3)

{
  undefined8 in_o0_1;
  undefined *puVar1;
  int iVar2;
  uint uVar3;
  undefined4 unaff_l0;
  undefined4 **ppuVar4;
  undefined4 **ppuVar5;
  int iVar6;
  undefined4 unaff_l1;
  uint uVar7;
  int iVar8;
  int iVar9;
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
  undefined4 auStack_20 [8];
  
  iVar2 = (int)((qword)in_o0_1 >> 0x20);
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
  iVar8 = -0x2c2;
  uVar7 = *param_3;
  *(undefined4 *)((int)register0x00000038 + -0x38) = 0;
  _strcmp();
  if (iVar2 == 0) {
    if (uVar7 < 2) goto loc_F00D1560;
    *(undefined4 *)((int)register0x00000038 + -0x38) = 2;
    _objc_msgSend();
    *param_1 = (int)sRam000001f8;
    param_1[1] = (int)sRam000001fa;
    goto loc_F00D1498;
  }
  _strcmp();
  if (iVar2 == 0) {
    if (uVar7 != 0) {
      *(undefined4 *)((int)register0x00000038 + -0x38) = 1;
      iVar8 = 0;
      *param_1 = iRam00000160;
    }
    goto loc_F00D1560;
  }
  _strcmp();
  if (iVar2 == 0) {
    if (uVar7 < 6) goto loc_F00D1560;
    *(undefined4 *)((int)register0x00000038 + -0x38) = 6;
    _objc_msgSend();
    if (cRam000001d2 == '\x01') {
      iVar2 = (uint)*(word *)(iRam00000168 + 0x4c) << 0x10;
      uVar7 = iVar2 >> 0x10;
      *(uint *)((int)register0x00000038 + -0x18) = uVar7 >> 8 | (iVar2 >> 0x1f) << 0x18;
      *(uint *)((int)register0x00000038 + -0x14) = uVar7 << 0x18;
    }
    else {
      *(undefined8 *)((int)register0x00000038 + -0x18) = 0;
    }
    puVar1 = (undefined *)((int)register0x00000038 + -0x18);
    iVar2 = 0;
    *(undefined8 *)((int)register0x00000038 + -0x20) =
         *(undefined8 *)((int)register0x00000038 + -0x18);
    do {
      *(undefined4 *)(iVar2 + (int)param_1) = *(undefined4 *)(puVar1 + -8);
      puVar1 = puVar1 + 4;
      iVar2 = iVar2 + 4;
    } while (puVar1 <= (undefined *)((int)register0x00000038 + -0x14));
    puVar1 = (undefined *)((int)register0x00000038 + -0x18);
    iVar2 = 0;
    *(undefined8 *)((int)register0x00000038 + -0x20) = uRam000001d8;
    do {
      *(undefined4 *)((int)param_1 + iVar2 + 8) = *(undefined4 *)(puVar1 + -8);
      in_o0_1 = uRam000001e8;
      puVar1 = puVar1 + 4;
      iVar2 = iVar2 + 4;
    } while (puVar1 <= (undefined *)((int)register0x00000038 + -0x14));
    puVar1 = (undefined *)((int)register0x00000038 + -0x18);
    iVar2 = 0;
    *(undefined8 *)((int)register0x00000038 + -0x20) = uRam000001e8;
    do {
      *(undefined4 *)((int)param_1 + iVar2 + 0x10) = *(undefined4 *)(puVar1 + -8);
      puVar1 = puVar1 + 4;
      iVar2 = iVar2 + 4;
    } while (puVar1 <= (undefined *)((int)register0x00000038 + -0x14));
  }
  else {
    _strcmp();
    if (iVar2 == 0) {
      if (uVar7 < 3) goto loc_F00D1560;
      *(undefined4 *)((int)register0x00000038 + -0x38) = 3;
      _objc_msgSend();
      _objc_msgSend(0);
      *param_1 = 0;
      param_1[1] = iRam000001c4;
      _objc_msgSend();
      param_1[2] = 0;
    }
    else {
      _strcmp();
      if (iVar2 == 0) {
        if (uVar7 < 2) goto loc_F00D1560;
        *(undefined4 *)((int)register0x00000038 + -0x38) = 2;
        _objc_msgSend();
        puVar1 = (undefined *)((int)register0x00000038 + -0x18);
        iVar2 = 0;
        *(qword *)((int)register0x00000038 + -0x18) =
             CONCAT44(uRam000001bc >> 8,uRam000001bc << 0x18);
        *(qword *)((int)register0x00000038 + -0x20) =
             CONCAT44(uRam000001bc >> 8,uRam000001bc << 0x18);
        do {
          *(undefined4 *)(iVar2 + (int)param_1) = *(undefined4 *)(puVar1 + -8);
          puVar1 = puVar1 + 4;
          iVar2 = iVar2 + 4;
        } while (puVar1 <= (undefined *)((int)register0x00000038 + -0x14));
      }
      else {
        _strcmp();
        if (iVar2 == 0) {
          if (uVar7 < 2) goto loc_F00D1560;
          *(undefined4 *)((int)register0x00000038 + -0x38) = 2;
          _objc_msgSend();
          puVar1 = (undefined *)((int)register0x00000038 + -0x18);
          iVar2 = 0;
          *(qword *)((int)register0x00000038 + -0x18) =
               CONCAT44(uRam000001a0 >> 8,uRam000001a0 << 0x18);
          *(qword *)((int)register0x00000038 + -0x20) =
               CONCAT44(uRam000001a0 >> 8,uRam000001a0 << 0x18);
          do {
            *(undefined4 *)(iVar2 + (int)param_1) = *(undefined4 *)(puVar1 + -8);
            puVar1 = puVar1 + 4;
            iVar2 = iVar2 + 4;
          } while (puVar1 <= (undefined *)((int)register0x00000038 + -0x14));
        }
        else {
          _strcmp();
          if (iVar2 == 0) {
            if (uVar7 < 2) goto loc_F00D1560;
            *(undefined4 *)((int)register0x00000038 + -0x38) = 2;
            _objc_msgSend();
            uVar7 = uRam000001a0;
            if (cRam000001d2 == '\x01') {
              if (cRam000001d3 == '\0') {
                uVar7 = iRam000001a4 - *(int *)(iRam00000168 + 0x10);
                goto loc_F00D1224;
              }
              *(undefined8 *)((int)register0x00000038 + -0x18) = 0;
            }
            else {
loc_F00D1224:
              *(qword *)((int)register0x00000038 + -0x18) = CONCAT44(uVar7 >> 8,uVar7 << 0x18);
            }
            puVar1 = (undefined *)((int)register0x00000038 + -0x18);
            iVar2 = 0;
            in_o0_1 = *(undefined8 *)((int)register0x00000038 + -0x18);
            *(undefined8 *)((int)register0x00000038 + -0x20) = in_o0_1;
            do {
              *(undefined4 *)(iVar2 + (int)param_1) = *(undefined4 *)(puVar1 + -8);
              puVar1 = puVar1 + 4;
              iVar2 = iVar2 + 4;
            } while (puVar1 <= (undefined *)((int)register0x00000038 + -0x14));
          }
          else {
            _strcmp();
            if (iVar2 == 0) {
              if (uVar7 < 2) goto loc_F00D1560;
              *(undefined4 *)((int)register0x00000038 + -0x38) = 2;
              _objc_msgSend();
              if (cRam000001d2 == '\x01') {
                if (cRam000001d3 == '\0') {
                  uVar7 = *(uint *)(iRam00000168 + 0x10);
                  uVar3 = uRam000001a0;
                }
                else {
                  uVar3 = *(uint *)(iRam00000168 + 0x10);
                  uVar7 = uRam000001a0;
                }
                uVar3 = uVar3 - (iRam000001a4 - uVar7);
                *(qword *)((int)register0x00000038 + -0x18) = CONCAT44(uVar3 >> 8,uVar3 * 0x1000000)
                ;
              }
              else {
                *(undefined8 *)((int)register0x00000038 + -0x18) = 0;
              }
              puVar1 = (undefined *)((int)register0x00000038 + -0x18);
              iVar2 = 0;
              in_o0_1 = *(undefined8 *)((int)register0x00000038 + -0x18);
              *(undefined8 *)((int)register0x00000038 + -0x20) = in_o0_1;
              do {
                *(undefined4 *)(iVar2 + (int)param_1) = *(undefined4 *)(puVar1 + -8);
                puVar1 = puVar1 + 4;
                iVar2 = iVar2 + 4;
              } while (puVar1 <= (undefined *)((int)register0x00000038 + -0x14));
            }
            else {
              _strcmp();
              if (iVar2 == 0) {
                if (uVar7 < 2) goto loc_F00D1560;
                *(undefined4 *)((int)register0x00000038 + -0x38) = 2;
                _objc_msgSend();
                *param_1 = (int)sRam000001b0;
                param_1[1] = (int)sRam000001b2;
              }
              else {
                _strcmp();
                if (iVar2 == 0) {
                  if (uVar7 == 0) goto loc_F00D1560;
                  *(undefined4 *)((int)register0x00000038 + -0x38) = 1;
                  _objc_msgSend();
                  *param_1 = (int)cRam000001d3;
                }
                else {
                  _strcmp();
                  if (iVar2 != 0) {
                    *(uint *)((int)register0x00000038 + -0x38) = *param_3;
                    _objc_msgSend();
                    iVar6 = *(int *)(iVar2 + 0x174);
                    do {
                      iVar9 = iVar8;
                      if (iVar2 + 0x174 == iVar6) break;
                      iVar6 = *(int *)(iVar6 + 4);
                      _objc_msgSend();
                      iVar9 = iVar2;
                    } while (iVar2 == -0x2c2);
                    _objc_msgSend();
                    iVar8 = iVar9;
                    if (iVar9 == -0x2c2) {
                      *(int *)((int)register0x00000038 + -0x10) = iVar2;
                      *(undefined4 *)((int)register0x00000038 + -0xc) = uRamf01421e0;
                      _objc_msgSendSuper((undefined *)((int)register0x00000038 + -0x10),(int)in_o0_1
                                         ,param_1,param_2,
                                         (undefined *)((int)register0x00000038 + -0x38));
                      iVar8 = iVar2;
                    }
                    goto loc_F00D1560;
                  }
                  _objc_msgSend();
                  ppuVar4 = puRam00000174;
                  if (puRam00000174 != &puRam00000174) {
                    do {
                      if (uVar7 < 4) break;
                      *(undefined4 *)((int)register0x00000038 + -0x34) = 0;
                      ppuVar5 = (undefined4 **)ppuVar4[1];
                      _objc_msgSend(*ppuVar4,(int)in_o0_1,
                                    param_1 + *(int *)((int)register0x00000038 + -0x38),param_2,
                                    (undefined *)((int)register0x00000038 + -0x34));
                      if ((int)((qword)in_o0_1 >> 0x20) == 0) {
                        in_o0_1 = *(undefined8 *)((int)register0x00000038 + -0x38);
                        uVar7 = uVar7 - (int)in_o0_1;
                        *(int *)((int)register0x00000038 + -0x38) =
                             (int)((qword)in_o0_1 >> 0x20) + (int)in_o0_1;
                      }
                      ppuVar4 = ppuVar5;
                    } while (ppuVar5 != &puRam00000174);
                  }
                }
              }
            }
          }
        }
      }
    }
  }
loc_F00D1498:
  _objc_msgSend((int)((qword)in_o0_1 >> 0x20));
  iVar8 = 0;
loc_F00D1560:
  *param_3 = (uint)((qword)in_o0_1 >> 0x20);
  return iVar8;
}

