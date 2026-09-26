
/* WARNING: Removing unreachable block (ram,0xf00e8ff4) */
/* WARNING: Removing unreachable block (ram,0xf00e90b8) */
/* WARNING: Removing unreachable block (ram,0xf00e8df8) */
/* WARNING: Removing unreachable block (ram,0xf00e94d0) */
/* WARNING: Removing unreachable block (ram,0xf00e93e8) */
/* WARNING: Removing unreachable block (ram,0xf00e91b0) */
/* WARNING: Removing unreachable block (ram,0xf00e87c0) */
/* WARNING: Removing unreachable block (ram,0xf00e8884) */
/* WARNING: Removing unreachable block (ram,0xf00e85c4) */
/* WARNING: Removing unreachable block (ram,0xf00e8c94) */
/* WARNING: Removing unreachable block (ram,0xf00e8bb0) */
/* WARNING: Removing unreachable block (ram,0xf00e897c) */
/* WARNING: Removing unreachable block (ram,0xf00e8324) */
/* WARNING: Removing unreachable block (ram,0xf00e8440) */
/* WARNING: Removing unreachable block (ram,0xf00e8290) */
/* WARNING: Removing unreachable block (ram,0xf00e83f0) */
/* WARNING: Removing unreachable block (ram,0xf00e82d4) */
/* WARNING: Removing unreachable block (ram,0xf00e8580) */
/* WARNING: Removing unreachable block (ram,0xf00e8a88) */
/* WARNING: Removing unreachable block (ram,0xf00e8bc8) */
/* WARNING: Removing unreachable block (ram,0xf00e8cac) */
/* WARNING: Removing unreachable block (ram,0xf00e86d4) */
/* WARNING: Removing unreachable block (ram,0xf00e88ac) */
/* WARNING: Removing unreachable block (ram,0xf00e8db4) */
/* WARNING: Removing unreachable block (ram,0xf00e92bc) */
/* WARNING: Removing unreachable block (ram,0xf00e9400) */
/* WARNING: Removing unreachable block (ram,0xf00e94e8) */
/* WARNING: Removing unreachable block (ram,0xf00e8f08) */
/* WARNING: Removing unreachable block (ram,0xf00e90e0) */
/* WARNING: Removing unreachable block (ram,0xf00e955c) */
/* WARNING: Removing unreachable block (ram,0xf00e8138) */

undefined8
-[IOFrameBufferDisplay showCursor:frame:token:]
          (int param_1,int param_2,undefined2 *param_3,undefined4 param_4)

{
  byte bVar1;
  word wVar2;
  word wVar3;
  sword sVar4;
  sword sVar5;
  sword sVar6;
  sword sVar7;
  undefined4 uVar8;
  int iVar9;
  undefined4 *puVar10;
  int iVar11;
  undefined2 uVar14;
  uint uVar12;
  uint uVar13;
  int iVar15;
  int iVar16;
  int *piVar17;
  undefined *puVar18;
  undefined4 *puVar19;
  char cVar21;
  undefined *puVar20;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  uint uVar22;
  uint *puVar23;
  undefined4 unaff_l3;
  byte bVar24;
  undefined4 unaff_l4;
  uint *puVar25;
  byte *pbVar26;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  uint *puVar27;
  undefined4 unaff_l7;
  byte *pbVar28;
  undefined4 unaff_i0;
  undefined4 unaff_i1;
  undefined4 unaff_i2;
  byte *pbVar29;
  undefined4 unaff_i3;
  byte *pbVar30;
  uint uVar31;
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
  *(int *)((int)register0x00000038 + -0x3c) = param_1;
  iVar9 = *(int *)(param_1 + 0x1fc);
  *(int *)((int)register0x00000038 + -0x44) = iVar9;
  iVar9 = iVar9 + 4;
  _ev_try_lock();
  puVar10 = *(undefined4 **)((int)register0x00000038 + -0x44);
  if (iVar9 == 0) goto loc_F00E9564;
  *puVar10 = param_4;
  *(undefined2 *)(puVar10 + 7) = *param_3;
  *(undefined2 *)((int)puVar10 + 0x1e) = param_3[1];
  if (*(char *)((int)puVar10 + 10) == '\0') goto loc_F00E8D1C;
  piVar17 = *(int **)(*(int *)((int)register0x00000038 + -0x3c) + 0x1fc);
  iVar9 = *piVar17;
  wVar2 = *(word *)(piVar17 + iVar9 + 0xe);
  *(word *)((int)register0x00000038 + -0x18) = wVar2;
  wVar3 = *(word *)((int)piVar17 + iVar9 * 4 + 0x3a);
  *(word *)((int)register0x00000038 + -0x16) = wVar3;
  cVar21 = '\0';
  iVar9 = (uint)*(word *)(piVar17 + 7) - (uint)wVar2;
  *(sword *)((int)register0x00000038 + -0x20) = (sword)iVar9;
  *(sword *)((int)register0x00000038 + -0x1e) = (sword)(iVar9 + 0x10);
  iVar15 = (uint)*(word *)((int)piVar17 + 0x1e) - (uint)wVar3;
  *(sword *)((int)register0x00000038 + -0x1c) = (sword)iVar15;
  *(sword *)((int)register0x00000038 + -0x1a) = (sword)(iVar15 + 0x10);
  if (((iVar9 * 0x10000 >> 0x10 < (int)*(sword *)((int)piVar17 + 0x16)) &&
      ((int)*(sword *)(piVar17 + 5) < (iVar9 + 0x10) * 0x10000 >> 0x10)) &&
     (iVar15 * 0x10000 >> 0x10 < (int)*(sword *)((int)piVar17 + 0x1a))) {
    if ((int)*(sword *)(piVar17 + 6) < (iVar15 + 0x10) * 0x10000 >> 0x10) {
      cVar21 = '\x01';
    }
    else {
      cVar21 = '\0';
    }
  }
  if (cVar21 == *(char *)((int)piVar17 + 0xb)) {
    iVar9 = *(int *)((int)register0x00000038 + -0x3c);
loc_F00E8D20:
    iVar15 = *(int *)(iVar9 + 0x1fc);
  }
  else {
    *(char *)((int)piVar17 + 0xb) = cVar21;
    if (*(char *)((int)piVar17 + 0xb) != '\0') {
      cVar21 = *(char *)(*(int *)(*(int *)((int)register0x00000038 + -0x3c) + 0x1fc) + 8);
      *(char *)(*(int *)(*(int *)((int)register0x00000038 + -0x3c) + 0x1fc) + 8) = cVar21 + '\x01';
      iVar9 = *(int *)((int)register0x00000038 + -0x3c);
      if (cVar21 == '\0') {
        iVar9 = *(int *)((int)register0x00000038 + -0x3c);
        _objc_msgSend(iVar9,paDisplayinfo);
        uVar12 = *(uint *)(iVar9 + 0x18);
        if (uVar12 < 4) {
          if (uVar12 < 2) {
            if (uVar12 == 1) {
              iVar15 = *(int *)((int)register0x00000038 + -0x3c);
              _objc_msgSend(iVar15,paDisplayinfo);
              iVar16 = *(int *)(*(int *)((int)register0x00000038 + -0x3c) + 0x1fc);
              *(undefined2 *)((int)register0x00000038 + -0x28) = *(undefined2 *)(iVar16 + 0xc);
              *(undefined2 *)((int)register0x00000038 + -0x26) = *(undefined2 *)(iVar16 + 0xe);
              sVar4 = *(sword *)(iVar16 + 0x10);
              *(sword *)((int)register0x00000038 + -0x24) = sVar4;
              *(undefined2 *)((int)register0x00000038 + -0x22) = *(undefined2 *)(iVar16 + 0x12);
              iVar11 = *(int *)(iVar15 + 8);
              iVar9 = iVar11;
              .umul(iVar11,(int)sVar4 - (int)*(sword *)(iVar16 + 0x34));
              puVar20 = (undefined *)(iVar16 + 0x848);
              puVar18 = (undefined *)
                        (*(int *)(iVar15 + 0x14) + iVar9 +
                        ((int)*(sword *)((int)register0x00000038 + -0x28) -
                        (int)*(sword *)(iVar16 + 0x30)));
              iVar16 = (uint)*(word *)((int)register0x00000038 + -0x26) -
                       (int)*(sword *)((int)register0x00000038 + -0x28);
              iVar15 = ((uint)*(word *)((int)register0x00000038 + -0x22) -
                       (uint)*(word *)((int)register0x00000038 + -0x24)) + -1;
              iVar9 = iVar16;
              if (iVar15 * 0x10000 >> 0x10 == -1) goto loc_F00E8D1C;
              do {
                while ((iVar9 + -1) * 0x10000 >> 0x10 != -1) {
                  *puVar18 = *puVar20;
                  puVar20 = puVar20 + 1;
                  puVar18 = puVar18 + 1;
                  iVar9 = iVar9 + -1;
                }
                iVar15 = iVar15 + -1;
                puVar18 = puVar18 + (iVar11 - (iVar16 * 0x10000 >> 0x10));
                iVar9 = iVar16;
              } while (iVar15 * 0x10000 >> 0x10 != -1);
              iVar9 = *(int *)((int)register0x00000038 + -0x3c);
            }
            else {
              iVar9 = *(int *)((int)register0x00000038 + -0x3c);
            }
          }
          else {
loc_F00E8D1C:
            iVar9 = *(int *)((int)register0x00000038 + -0x3c);
          }
        }
        else if (uVar12 == 4) {
          iVar15 = *(int *)((int)register0x00000038 + -0x3c);
          _objc_msgSend(iVar15,paDisplayinfo);
          iVar16 = *(int *)(*(int *)((int)register0x00000038 + -0x3c) + 0x1fc);
          *(undefined2 *)((int)register0x00000038 + -0x28) = *(undefined2 *)(iVar16 + 0xc);
          *(undefined2 *)((int)register0x00000038 + -0x26) = *(undefined2 *)(iVar16 + 0xe);
          sVar4 = *(sword *)(iVar16 + 0x10);
          *(sword *)((int)register0x00000038 + -0x24) = sVar4;
          *(undefined2 *)((int)register0x00000038 + -0x22) = *(undefined2 *)(iVar16 + 0x12);
          iVar11 = *(int *)(iVar15 + 8);
          iVar9 = iVar11;
          .umul(iVar11,(int)sVar4 - (int)*(sword *)(iVar16 + 0x34));
          puVar19 = (undefined4 *)(iVar16 + 0x1048);
          puVar10 = (undefined4 *)
                    (*(int *)(iVar15 + 0x14) + iVar9 * 4 +
                    ((int)*(sword *)((int)register0x00000038 + -0x28) -
                    (int)*(sword *)(iVar16 + 0x30)) * 4);
          iVar16 = (int)*(sword *)((int)register0x00000038 + -0x26) -
                   (int)*(sword *)((int)register0x00000038 + -0x28);
          iVar15 = ((int)*(sword *)((int)register0x00000038 + -0x22) -
                   (int)*(sword *)((int)register0x00000038 + -0x24)) + -1;
          iVar9 = iVar16;
          if (iVar15 == -1) goto loc_F00E8D1C;
          do {
            while (iVar9 + -1 != -1) {
              *puVar10 = *puVar19;
              puVar19 = puVar19 + 1;
              puVar10 = puVar10 + 1;
              iVar9 = iVar9 + -1;
            }
            iVar15 = iVar15 + -1;
            puVar10 = puVar10 + (iVar11 - iVar16);
            iVar9 = iVar16;
          } while (iVar15 != -1);
          iVar9 = *(int *)((int)register0x00000038 + -0x3c);
        }
        else {
          iVar9 = *(int *)((int)register0x00000038 + -0x3c);
        }
      }
      goto loc_F00E8D20;
    }
    iVar9 = *(int *)((int)register0x00000038 + -0x3c);
    iVar15 = *(int *)(iVar9 + 0x1fc);
    if (*(char *)(iVar15 + 8) != '\0') {
      *(char *)(iVar15 + 8) = *(char *)(iVar15 + 8) + -1;
      if (*(char *)(iVar15 + 8) != '\0') {
        iVar9 = *(int *)((int)register0x00000038 + -0x3c);
        goto loc_F00E8D20;
      }
      piVar17 = *(int **)(iVar9 + 0x1fc);
      iVar9 = *piVar17;
      sVar4 = *(sword *)(piVar17 + iVar9 + 0xe);
      *(sword *)((int)register0x00000038 + -0x30) = sVar4;
      *(undefined2 *)((int)register0x00000038 + -0x2e) =
           *(undefined2 *)((int)piVar17 + iVar9 * 4 + 0x3a);
      *(sword *)(piVar17 + 8) = *(sword *)(piVar17 + 7) - sVar4;
      *(sword *)((int)piVar17 + 0x22) = *(sword *)(piVar17 + 8) + 0x10;
      iVar9 = *(int *)((int)register0x00000038 + -0x3c);
      *(sword *)(piVar17 + 9) =
           *(sword *)((int)piVar17 + 0x1e) - *(sword *)((int)register0x00000038 + -0x2e);
      uVar8 = paDisplayinfo;
      sVar4 = *(sword *)(piVar17 + 9);
      *(int **)((int)register0x00000038 + -0x4c) = piVar17;
      *(sword *)((int)piVar17 + 0x26) = sVar4 + 0x10;
      _objc_msgSend(iVar9,uVar8);
      uVar12 = *(uint *)(iVar9 + 0x18);
      if (uVar12 < 4) {
        if (1 < uVar12) goto loc_F00E8CF8;
        if (uVar12 == 1) {
          iVar9 = *(int *)((int)register0x00000038 + -0x3c);
          _objc_msgSend(iVar9,paDisplayinfo);
          piVar17 = *(int **)(*(int *)((int)register0x00000038 + -0x3c) + 0x1fc);
          sVar4 = *(sword *)(piVar17 + 8);
          *(sword *)((int)register0x00000038 + -0x38) = sVar4;
          sVar5 = *(sword *)((int)piVar17 + 0x22);
          *(sword *)((int)register0x00000038 + -0x36) = sVar5;
          sVar6 = *(sword *)(piVar17 + 9);
          *(sword *)((int)register0x00000038 + -0x34) = sVar6;
          sVar7 = *(sword *)((int)piVar17 + 0x26);
          *(sword *)((int)register0x00000038 + -0x32) = sVar7;
          if (sVar6 < *(sword *)(piVar17 + 0xd)) {
            *(undefined2 *)((int)register0x00000038 + -0x34) = *(undefined2 *)(piVar17 + 0xd);
          }
          if (*(sword *)((int)piVar17 + 0x36) < sVar7) {
            *(undefined2 *)((int)register0x00000038 + -0x32) = *(undefined2 *)((int)piVar17 + 0x36);
          }
          if (sVar4 < *(sword *)(piVar17 + 0xc)) {
            *(undefined2 *)((int)register0x00000038 + -0x38) = *(undefined2 *)(piVar17 + 0xc);
          }
          uVar14 = *(undefined2 *)((int)register0x00000038 + -0x38);
          if (*(sword *)((int)piVar17 + 0x32) < sVar5) {
            *(undefined2 *)((int)register0x00000038 + -0x36) = *(undefined2 *)((int)piVar17 + 0x32);
            uVar14 = *(undefined2 *)((int)register0x00000038 + -0x38);
          }
          *(undefined2 *)(piVar17 + 3) = uVar14;
          *(undefined2 *)((int)piVar17 + 0xe) = *(undefined2 *)((int)register0x00000038 + -0x36);
          *(undefined2 *)(piVar17 + 4) = *(undefined2 *)((int)register0x00000038 + -0x34);
          *(undefined2 *)((int)piVar17 + 0x12) = *(undefined2 *)((int)register0x00000038 + -0x32);
          sVar4 = *(sword *)(piVar17 + 0xd);
          *(undefined4 *)((int)register0x00000038 + -0x54) = *(undefined4 *)(iVar9 + 8);
          iVar15 = *(int *)((int)register0x00000038 + -0x54);
          .umul(iVar15,(int)*(sword *)((int)register0x00000038 + -0x34) - (int)sVar4);
          iVar16 = (int)*(sword *)((int)register0x00000038 + -0x38);
          pbVar28 = (byte *)(piVar17 + 0x212);
          pbVar29 = (byte *)(*(int *)(iVar9 + 0x14) + iVar15 + (iVar16 - *(sword *)(piVar17 + 0xc)))
          ;
          iVar15 = *(int *)(iVar9 + 0x1c);
          *(int *)((int)register0x00000038 + -0x5c) =
               *(sword *)((int)register0x00000038 + -0x36) - iVar16;
          *(int *)((int)register0x00000038 + -0x54) =
               *(int *)((int)register0x00000038 + -0x54) -
               (*(sword *)((int)register0x00000038 + -0x36) - iVar16);
          iVar9 = ((int)*(sword *)((int)register0x00000038 + -0x34) - (int)*(sword *)(piVar17 + 9))
                  * 0x10 + (iVar16 - *(sword *)(piVar17 + 8));
          pbVar26 = (byte *)((int)piVar17 + iVar9 + *piVar17 * 0x100 + 0x48);
          pbVar30 = (byte *)((int)piVar17 + iVar9 + *piVar17 * 0x100 + 0x448);
          iVar9 = (int)*(sword *)((int)register0x00000038 + -0x32) -
                  (int)*(sword *)((int)register0x00000038 + -0x34);
          param_2 = 0x10 - *(int *)((int)register0x00000038 + -0x5c);
          if (iVar15 == 1) {
            iVar9 = iVar9 + -1;
            if (iVar9 < 0) goto loc_F00E8CF8;
            do {
              iVar15 = *(int *)((int)register0x00000038 + -0x5c);
              while (iVar15 = iVar15 + -1, -1 < iVar15) {
                uVar12 = (uint)*pbVar29;
                *pbVar28 = *pbVar29;
                pbVar28 = pbVar28 + 1;
                bVar1 = *pbVar26;
                pbVar26 = pbVar26 + 1;
                .umul(uVar12,0xff - (uint)*pbVar30);
                pbVar30 = pbVar30 + 1;
                *pbVar29 = bVar1 + (char)(uVar12 + ((int)uVar12 >> 8) + 1 >> 8);
                pbVar29 = pbVar29 + 1;
              }
              pbVar26 = pbVar26 + param_2;
              pbVar30 = pbVar30 + param_2;
              iVar9 = iVar9 + -1;
              pbVar29 = pbVar29 + *(int *)((int)register0x00000038 + -0x54);
            } while (-1 < iVar9);
            iVar9 = *(int *)((int)register0x00000038 + -0x4c);
          }
          else {
            iVar16 = *(int *)(*(int *)((int)register0x00000038 + -0x3c) + 0x208);
            iVar9 = iVar9 + -1;
            iVar15 = *(int *)(*(int *)((int)register0x00000038 + -0x3c) + 0x20c);
            if (iVar9 < 0) goto loc_F00E8CF8;
            do {
              iVar11 = *(int *)((int)register0x00000038 + -0x5c);
              while (iVar11 = iVar11 + -1, -1 < iVar11) {
                *pbVar28 = *pbVar29;
                if (*pbVar30 != 0) {
                  bVar24 = *pbVar26;
                  bVar1 = ~*pbVar30;
                  if (bVar1 != 0) {
                    uVar22 = *(uint *)(iVar16 + (uint)*pbVar29 * 4);
                    uVar12 = (uVar22 & 0xff00ff00) >> 8;
                    .umul(uVar12,bVar1);
                    uVar22 = uVar22 & 0xff00ff;
                    .umul(uVar22,bVar1);
                    uVar12 = (*(uint *)(iVar16 + (uint)bVar24 * 4) & 0xffffff00) +
                             (uVar12 + 0x10001 + ((uVar12 & 0xff00ff00) >> 8) & 0xff00ff00 |
                             uVar22 + 0x10001 + ((uVar22 & 0xff00ff00) >> 8) >> 8 & 0xff00ff);
                    if (((uVar12 ^ uVar12 >> 8) & 0xffff00) == 0) {
                      bVar24 = *(byte *)((uVar12 >> 0x18) + iVar15 + 0x300);
                    }
                    else {
                      bVar24 = *(char *)((uVar12 >> 8 & 0xff) + iVar15 + 0x200) +
                               *(char *)(iVar15 + (uVar12 >> 0x18)) +
                               *(char *)((uVar12 >> 0x10 & 0xff) + iVar15 + 0x100);
                    }
                  }
                  *pbVar29 = bVar24;
                }
                pbVar28 = pbVar28 + 1;
                pbVar30 = pbVar30 + 1;
                pbVar26 = pbVar26 + 1;
                pbVar29 = pbVar29 + 1;
              }
              pbVar26 = pbVar26 + param_2;
              pbVar30 = pbVar30 + param_2;
              iVar9 = iVar9 + -1;
              pbVar29 = pbVar29 + *(int *)((int)register0x00000038 + -0x54);
            } while (-1 < iVar9);
            iVar9 = *(int *)((int)register0x00000038 + -0x4c);
          }
        }
        else {
          iVar9 = *(int *)((int)register0x00000038 + -0x4c);
        }
      }
      else if (uVar12 == 4) {
        iVar9 = *(int *)((int)register0x00000038 + -0x3c);
        _objc_msgSend(iVar9,paDisplayinfo);
        piVar17 = *(int **)(*(int *)((int)register0x00000038 + -0x3c) + 0x1fc);
        sVar4 = *(sword *)(piVar17 + 8);
        *(sword *)((int)register0x00000038 + -0x38) = sVar4;
        sVar5 = *(sword *)((int)piVar17 + 0x22);
        *(sword *)((int)register0x00000038 + -0x36) = sVar5;
        sVar6 = *(sword *)(piVar17 + 9);
        *(sword *)((int)register0x00000038 + -0x34) = sVar6;
        sVar7 = *(sword *)((int)piVar17 + 0x26);
        *(sword *)((int)register0x00000038 + -0x32) = sVar7;
        if (sVar6 < *(sword *)(piVar17 + 0xd)) {
          *(undefined2 *)((int)register0x00000038 + -0x34) = *(undefined2 *)(piVar17 + 0xd);
        }
        if (*(sword *)((int)piVar17 + 0x36) < sVar7) {
          *(undefined2 *)((int)register0x00000038 + -0x32) = *(undefined2 *)((int)piVar17 + 0x36);
        }
        if (sVar4 < *(sword *)(piVar17 + 0xc)) {
          *(undefined2 *)((int)register0x00000038 + -0x38) = *(undefined2 *)(piVar17 + 0xc);
        }
        uVar14 = *(undefined2 *)((int)register0x00000038 + -0x38);
        if (*(sword *)((int)piVar17 + 0x32) < sVar5) {
          *(undefined2 *)((int)register0x00000038 + -0x36) = *(undefined2 *)((int)piVar17 + 0x32);
          uVar14 = *(undefined2 *)((int)register0x00000038 + -0x38);
        }
        *(undefined2 *)(piVar17 + 3) = uVar14;
        *(undefined2 *)((int)piVar17 + 0xe) = *(undefined2 *)((int)register0x00000038 + -0x36);
        *(undefined2 *)(piVar17 + 4) = *(undefined2 *)((int)register0x00000038 + -0x34);
        *(undefined2 *)((int)piVar17 + 0x12) = *(undefined2 *)((int)register0x00000038 + -0x32);
        param_2 = *(int *)(iVar9 + 8);
        iVar15 = param_2;
        .umul(param_2,(int)*(sword *)((int)register0x00000038 + -0x34) -
                      (int)*(sword *)(piVar17 + 0xd));
        puVar27 = (uint *)(piVar17 + 0x412);
        iVar16 = (int)*(sword *)((int)register0x00000038 + -0x38);
        puVar23 = (uint *)(*(int *)(iVar9 + 0x14) + iVar15 * 4 +
                          (iVar16 - *(sword *)(piVar17 + 0xc)) * 4);
        iVar15 = (int)*(sword *)((int)register0x00000038 + -0x34);
        iVar11 = *(sword *)((int)register0x00000038 + -0x36) - iVar16;
        param_2 = param_2 - iVar11;
        puVar25 = (uint *)(piVar17 +
                          *piVar17 * 0x100 +
                          (iVar15 - *(sword *)(piVar17 + 9)) * 0x10 +
                          (iVar16 - *(sword *)(piVar17 + 8)) + 0x12);
        if ((*(char *)(iVar9 + 0x20) == 'A') || (*(char *)(iVar9 + 0x20) == '-')) {
          iVar15 = (*(sword *)((int)register0x00000038 + -0x32) - iVar15) + -1;
          iVar9 = iVar11;
          if (iVar15 != -1) {
            do {
              while (iVar9 + -1 != -1) {
                uVar12 = *puVar23;
                *puVar27 = uVar12;
                uVar31 = *puVar25;
                puVar27 = puVar27 + 1;
                uVar22 = uVar31 >> 0x18;
                puVar25 = puVar25 + 1;
                if (uVar22 != 0) {
                  if (uVar22 == 0xff) {
                    *puVar23 = uVar31;
                  }
                  else {
                    uVar12 = uVar12 << 8;
                    uVar13 = (uVar12 & 0xff00ff00) >> 8;
                    .umul(uVar13,uVar22 ^ 0xff);
                    uVar12 = uVar12 & 0xff00ff;
                    .umul(uVar12,uVar22 ^ 0xff);
                    *puVar23 = uVar31 * 0x100 +
                               (uVar13 + 0xff00ff & 0xff00ff00 | uVar12 + 0xff00ff >> 8 & 0xff00ff)
                               >> 8 | 0xff000000;
                  }
                }
                puVar23 = puVar23 + 1;
                iVar9 = iVar9 + -1;
              }
              puVar25 = puVar25 + (0x10 - iVar11);
              iVar15 = iVar15 + -1;
              puVar23 = puVar23 + param_2;
              iVar9 = iVar11;
            } while (iVar15 != -1);
            iVar9 = *(int *)((int)register0x00000038 + -0x4c);
            goto loc_F00E8CFC;
          }
        }
        else {
          iVar15 = *(sword *)((int)register0x00000038 + -0x32) - iVar15;
          while (iVar15 = iVar15 + -1, iVar9 = iVar11, iVar15 != -1) {
            while (iVar9 + -1 != -1) {
              uVar22 = *puVar23;
              *puVar27 = uVar22;
              uVar31 = *puVar25;
              puVar27 = puVar27 + 1;
              uVar12 = uVar31 & 0xff;
              puVar25 = puVar25 + 1;
              if (uVar12 != 0) {
                if (uVar12 == 0xff) {
                  *puVar23 = uVar31;
                }
                else {
                  uVar13 = (uVar22 & 0xff00ff00) >> 8;
                  .umul(uVar13,uVar12 ^ 0xff);
                  uVar22 = uVar22 & 0xff00ff;
                  .umul(uVar22,uVar12 ^ 0xff);
                  *puVar23 = uVar31 + (uVar13 + 0xff00ff & 0xff00ff00 |
                                      uVar22 + 0xff00ff >> 8 & 0xff00ff);
                }
              }
              puVar23 = puVar23 + 1;
              iVar9 = iVar9 + -1;
            }
            puVar25 = puVar25 + (0x10 - iVar11);
            puVar23 = puVar23 + param_2;
          }
        }
loc_F00E8CF8:
        iVar9 = *(int *)((int)register0x00000038 + -0x4c);
      }
      else {
        iVar9 = *(int *)((int)register0x00000038 + -0x4c);
      }
loc_F00E8CFC:
      *(undefined2 *)(iVar9 + 0x28) = *(undefined2 *)(iVar9 + 0x20);
      *(undefined2 *)(iVar9 + 0x2a) = *(undefined2 *)(iVar9 + 0x22);
      *(undefined2 *)(iVar9 + 0x2c) = *(undefined2 *)(iVar9 + 0x24);
      *(undefined2 *)(iVar9 + 0x2e) = *(undefined2 *)(iVar9 + 0x26);
      goto loc_F00E8D1C;
    }
  }
  if (*(char *)(iVar15 + 8) == '\0') {
    iVar9 = *(int *)((int)register0x00000038 + -0x44);
  }
  else {
    *(char *)(iVar15 + 8) = *(char *)(iVar15 + 8) + -1;
    if (*(char *)(iVar15 + 8) == '\0') {
      piVar17 = *(int **)(iVar9 + 0x1fc);
      iVar9 = *piVar17;
      sVar4 = *(sword *)(piVar17 + iVar9 + 0xe);
      *(sword *)((int)register0x00000038 + -0x30) = sVar4;
      *(undefined2 *)((int)register0x00000038 + -0x2e) =
           *(undefined2 *)((int)piVar17 + iVar9 * 4 + 0x3a);
      *(sword *)(piVar17 + 8) = *(sword *)(piVar17 + 7) - sVar4;
      *(sword *)((int)piVar17 + 0x22) = *(sword *)(piVar17 + 8) + 0x10;
      iVar9 = *(int *)((int)register0x00000038 + -0x3c);
      *(sword *)(piVar17 + 9) =
           *(sword *)((int)piVar17 + 0x1e) - *(sword *)((int)register0x00000038 + -0x2e);
      uVar8 = paDisplayinfo;
      sVar4 = *(sword *)(piVar17 + 9);
      *(int **)((int)register0x00000038 + -100) = piVar17;
      *(sword *)((int)piVar17 + 0x26) = sVar4 + 0x10;
      _objc_msgSend(iVar9,uVar8);
      uVar12 = *(uint *)(iVar9 + 0x18);
      if (uVar12 < 4) {
        if (1 < uVar12) goto loc_F00E9534;
        if (uVar12 == 1) {
          iVar9 = *(int *)((int)register0x00000038 + -0x3c);
          _objc_msgSend(iVar9,paDisplayinfo);
          piVar17 = *(int **)(*(int *)((int)register0x00000038 + -0x3c) + 0x1fc);
          sVar4 = *(sword *)(piVar17 + 8);
          *(sword *)((int)register0x00000038 + -0x38) = sVar4;
          sVar5 = *(sword *)((int)piVar17 + 0x22);
          *(sword *)((int)register0x00000038 + -0x36) = sVar5;
          sVar6 = *(sword *)(piVar17 + 9);
          *(sword *)((int)register0x00000038 + -0x34) = sVar6;
          sVar7 = *(sword *)((int)piVar17 + 0x26);
          *(sword *)((int)register0x00000038 + -0x32) = sVar7;
          if (sVar6 < *(sword *)(piVar17 + 0xd)) {
            *(undefined2 *)((int)register0x00000038 + -0x34) = *(undefined2 *)(piVar17 + 0xd);
          }
          if (*(sword *)((int)piVar17 + 0x36) < sVar7) {
            *(undefined2 *)((int)register0x00000038 + -0x32) = *(undefined2 *)((int)piVar17 + 0x36);
          }
          if (sVar4 < *(sword *)(piVar17 + 0xc)) {
            *(undefined2 *)((int)register0x00000038 + -0x38) = *(undefined2 *)(piVar17 + 0xc);
          }
          uVar14 = *(undefined2 *)((int)register0x00000038 + -0x38);
          if (*(sword *)((int)piVar17 + 0x32) < sVar5) {
            *(undefined2 *)((int)register0x00000038 + -0x36) = *(undefined2 *)((int)piVar17 + 0x32);
            uVar14 = *(undefined2 *)((int)register0x00000038 + -0x38);
          }
          *(undefined2 *)(piVar17 + 3) = uVar14;
          *(undefined2 *)((int)piVar17 + 0xe) = *(undefined2 *)((int)register0x00000038 + -0x36);
          *(undefined2 *)(piVar17 + 4) = *(undefined2 *)((int)register0x00000038 + -0x34);
          *(undefined2 *)((int)piVar17 + 0x12) = *(undefined2 *)((int)register0x00000038 + -0x32);
          sVar4 = *(sword *)(piVar17 + 0xd);
          *(undefined4 *)((int)register0x00000038 + -0x6c) = *(undefined4 *)(iVar9 + 8);
          iVar15 = *(int *)((int)register0x00000038 + -0x6c);
          .umul(iVar15,(int)*(sword *)((int)register0x00000038 + -0x34) - (int)sVar4);
          iVar16 = (int)*(sword *)((int)register0x00000038 + -0x38);
          pbVar28 = (byte *)(piVar17 + 0x212);
          pbVar29 = (byte *)(*(int *)(iVar9 + 0x14) + iVar15 + (iVar16 - *(sword *)(piVar17 + 0xc)))
          ;
          iVar15 = *(int *)(iVar9 + 0x1c);
          *(int *)((int)register0x00000038 + -0x74) =
               *(sword *)((int)register0x00000038 + -0x36) - iVar16;
          *(int *)((int)register0x00000038 + -0x6c) =
               *(int *)((int)register0x00000038 + -0x6c) -
               (*(sword *)((int)register0x00000038 + -0x36) - iVar16);
          iVar9 = ((int)*(sword *)((int)register0x00000038 + -0x34) - (int)*(sword *)(piVar17 + 9))
                  * 0x10 + (iVar16 - *(sword *)(piVar17 + 8));
          pbVar26 = (byte *)((int)piVar17 + iVar9 + *piVar17 * 0x100 + 0x48);
          pbVar30 = (byte *)((int)piVar17 + iVar9 + *piVar17 * 0x100 + 0x448);
          iVar9 = (int)*(sword *)((int)register0x00000038 + -0x32) -
                  (int)*(sword *)((int)register0x00000038 + -0x34);
          param_2 = 0x10 - *(int *)((int)register0x00000038 + -0x74);
          if (iVar15 == 1) {
            iVar9 = iVar9 + -1;
            if (iVar9 < 0) {
loc_F00E9534:
              iVar15 = *(int *)((int)register0x00000038 + -100);
            }
            else {
              do {
                iVar15 = *(int *)((int)register0x00000038 + -0x74);
                while (iVar15 = iVar15 + -1, -1 < iVar15) {
                  uVar12 = (uint)*pbVar29;
                  *pbVar28 = *pbVar29;
                  pbVar28 = pbVar28 + 1;
                  bVar1 = *pbVar26;
                  pbVar26 = pbVar26 + 1;
                  .umul(uVar12,0xff - (uint)*pbVar30);
                  pbVar30 = pbVar30 + 1;
                  *pbVar29 = bVar1 + (char)(uVar12 + ((int)uVar12 >> 8) + 1 >> 8);
                  pbVar29 = pbVar29 + 1;
                }
                pbVar26 = pbVar26 + param_2;
                pbVar30 = pbVar30 + param_2;
                iVar9 = iVar9 + -1;
                pbVar29 = pbVar29 + *(int *)((int)register0x00000038 + -0x6c);
              } while (-1 < iVar9);
              iVar15 = *(int *)((int)register0x00000038 + -100);
            }
          }
          else {
            iVar16 = *(int *)(*(int *)((int)register0x00000038 + -0x3c) + 0x208);
            iVar9 = iVar9 + -1;
            iVar15 = *(int *)(*(int *)((int)register0x00000038 + -0x3c) + 0x20c);
            if (iVar9 < 0) goto loc_F00E9534;
            do {
              iVar11 = *(int *)((int)register0x00000038 + -0x74);
              while (iVar11 = iVar11 + -1, -1 < iVar11) {
                *pbVar28 = *pbVar29;
                if (*pbVar30 != 0) {
                  bVar24 = *pbVar26;
                  bVar1 = ~*pbVar30;
                  if (bVar1 != 0) {
                    uVar22 = *(uint *)(iVar16 + (uint)*pbVar29 * 4);
                    uVar12 = (uVar22 & 0xff00ff00) >> 8;
                    .umul(uVar12,bVar1);
                    uVar22 = uVar22 & 0xff00ff;
                    .umul(uVar22,bVar1);
                    uVar12 = (*(uint *)(iVar16 + (uint)bVar24 * 4) & 0xffffff00) +
                             (uVar12 + 0x10001 + ((uVar12 & 0xff00ff00) >> 8) & 0xff00ff00 |
                             uVar22 + 0x10001 + ((uVar22 & 0xff00ff00) >> 8) >> 8 & 0xff00ff);
                    if (((uVar12 ^ uVar12 >> 8) & 0xffff00) == 0) {
                      bVar24 = *(byte *)((uVar12 >> 0x18) + iVar15 + 0x300);
                    }
                    else {
                      bVar24 = *(char *)((uVar12 >> 8 & 0xff) + iVar15 + 0x200) +
                               *(char *)(iVar15 + (uVar12 >> 0x18)) +
                               *(char *)((uVar12 >> 0x10 & 0xff) + iVar15 + 0x100);
                    }
                  }
                  *pbVar29 = bVar24;
                }
                pbVar28 = pbVar28 + 1;
                pbVar30 = pbVar30 + 1;
                pbVar26 = pbVar26 + 1;
                pbVar29 = pbVar29 + 1;
              }
              pbVar26 = pbVar26 + param_2;
              pbVar30 = pbVar30 + param_2;
              iVar9 = iVar9 + -1;
              pbVar29 = pbVar29 + *(int *)((int)register0x00000038 + -0x6c);
            } while (-1 < iVar9);
            iVar15 = *(int *)((int)register0x00000038 + -100);
          }
        }
        else {
          iVar15 = *(int *)((int)register0x00000038 + -100);
        }
      }
      else if (uVar12 == 4) {
        iVar9 = *(int *)((int)register0x00000038 + -0x3c);
        _objc_msgSend(iVar9,paDisplayinfo);
        piVar17 = *(int **)(*(int *)((int)register0x00000038 + -0x3c) + 0x1fc);
        sVar4 = *(sword *)(piVar17 + 8);
        *(sword *)((int)register0x00000038 + -0x38) = sVar4;
        sVar5 = *(sword *)((int)piVar17 + 0x22);
        *(sword *)((int)register0x00000038 + -0x36) = sVar5;
        sVar6 = *(sword *)(piVar17 + 9);
        *(sword *)((int)register0x00000038 + -0x34) = sVar6;
        sVar7 = *(sword *)((int)piVar17 + 0x26);
        *(sword *)((int)register0x00000038 + -0x32) = sVar7;
        if (sVar6 < *(sword *)(piVar17 + 0xd)) {
          *(undefined2 *)((int)register0x00000038 + -0x34) = *(undefined2 *)(piVar17 + 0xd);
        }
        if (*(sword *)((int)piVar17 + 0x36) < sVar7) {
          *(undefined2 *)((int)register0x00000038 + -0x32) = *(undefined2 *)((int)piVar17 + 0x36);
        }
        if (sVar4 < *(sword *)(piVar17 + 0xc)) {
          *(undefined2 *)((int)register0x00000038 + -0x38) = *(undefined2 *)(piVar17 + 0xc);
        }
        uVar14 = *(undefined2 *)((int)register0x00000038 + -0x38);
        if (*(sword *)((int)piVar17 + 0x32) < sVar5) {
          *(undefined2 *)((int)register0x00000038 + -0x36) = *(undefined2 *)((int)piVar17 + 0x32);
          uVar14 = *(undefined2 *)((int)register0x00000038 + -0x38);
        }
        *(undefined2 *)(piVar17 + 3) = uVar14;
        *(undefined2 *)((int)piVar17 + 0xe) = *(undefined2 *)((int)register0x00000038 + -0x36);
        *(undefined2 *)(piVar17 + 4) = *(undefined2 *)((int)register0x00000038 + -0x34);
        *(undefined2 *)((int)piVar17 + 0x12) = *(undefined2 *)((int)register0x00000038 + -0x32);
        param_2 = *(int *)(iVar9 + 8);
        iVar15 = param_2;
        .umul(param_2,(int)*(sword *)((int)register0x00000038 + -0x34) -
                      (int)*(sword *)(piVar17 + 0xd));
        puVar27 = (uint *)(piVar17 + 0x412);
        iVar16 = (int)*(sword *)((int)register0x00000038 + -0x38);
        puVar23 = (uint *)(*(int *)(iVar9 + 0x14) + iVar15 * 4 +
                          (iVar16 - *(sword *)(piVar17 + 0xc)) * 4);
        iVar15 = (int)*(sword *)((int)register0x00000038 + -0x34);
        iVar11 = *(sword *)((int)register0x00000038 + -0x36) - iVar16;
        param_2 = param_2 - iVar11;
        puVar25 = (uint *)(piVar17 +
                          *piVar17 * 0x100 +
                          (iVar15 - *(sword *)(piVar17 + 9)) * 0x10 +
                          (iVar16 - *(sword *)(piVar17 + 8)) + 0x12);
        if ((*(char *)(iVar9 + 0x20) == 'A') || (*(char *)(iVar9 + 0x20) == '-')) {
          iVar16 = (*(sword *)((int)register0x00000038 + -0x32) - iVar15) + -1;
          iVar15 = *(int *)((int)register0x00000038 + -100);
          iVar9 = iVar11;
          if (iVar16 != -1) {
            do {
              while (iVar9 + -1 != -1) {
                uVar12 = *puVar23;
                *puVar27 = uVar12;
                uVar31 = *puVar25;
                puVar27 = puVar27 + 1;
                uVar22 = uVar31 >> 0x18;
                puVar25 = puVar25 + 1;
                if (uVar22 != 0) {
                  if (uVar22 == 0xff) {
                    *puVar23 = uVar31;
                  }
                  else {
                    uVar12 = uVar12 << 8;
                    uVar13 = (uVar12 & 0xff00ff00) >> 8;
                    .umul(uVar13,uVar22 ^ 0xff);
                    uVar12 = uVar12 & 0xff00ff;
                    .umul(uVar12,uVar22 ^ 0xff);
                    *puVar23 = uVar31 * 0x100 +
                               (uVar13 + 0xff00ff & 0xff00ff00 | uVar12 + 0xff00ff >> 8 & 0xff00ff)
                               >> 8 | 0xff000000;
                  }
                }
                puVar23 = puVar23 + 1;
                iVar9 = iVar9 + -1;
              }
              puVar25 = puVar25 + (0x10 - iVar11);
              iVar16 = iVar16 + -1;
              puVar23 = puVar23 + param_2;
              iVar9 = iVar11;
            } while (iVar16 != -1);
            iVar15 = *(int *)((int)register0x00000038 + -100);
          }
        }
        else {
          iVar16 = (*(sword *)((int)register0x00000038 + -0x32) - iVar15) + -1;
          iVar15 = *(int *)((int)register0x00000038 + -100);
          iVar9 = iVar11;
          if (iVar16 != -1) {
            do {
              while (iVar9 + -1 != -1) {
                uVar22 = *puVar23;
                *puVar27 = uVar22;
                uVar31 = *puVar25;
                puVar27 = puVar27 + 1;
                uVar12 = uVar31 & 0xff;
                puVar25 = puVar25 + 1;
                if (uVar12 != 0) {
                  if (uVar12 == 0xff) {
                    *puVar23 = uVar31;
                  }
                  else {
                    uVar13 = (uVar22 & 0xff00ff00) >> 8;
                    .umul(uVar13,uVar12 ^ 0xff);
                    uVar22 = uVar22 & 0xff00ff;
                    .umul(uVar22,uVar12 ^ 0xff);
                    *puVar23 = uVar31 + (uVar13 + 0xff00ff & 0xff00ff00 |
                                        uVar22 + 0xff00ff >> 8 & 0xff00ff);
                  }
                }
                puVar23 = puVar23 + 1;
                iVar9 = iVar9 + -1;
              }
              puVar25 = puVar25 + (0x10 - iVar11);
              iVar16 = iVar16 + -1;
              puVar23 = puVar23 + param_2;
              iVar9 = iVar11;
            } while (iVar16 != -1);
            goto loc_F00E9534;
          }
        }
      }
      else {
        iVar15 = *(int *)((int)register0x00000038 + -100);
      }
      *(undefined2 *)(iVar15 + 0x28) = *(undefined2 *)(iVar15 + 0x20);
      *(undefined2 *)(iVar15 + 0x2a) = *(undefined2 *)(iVar15 + 0x22);
      *(undefined2 *)(iVar15 + 0x2c) = *(undefined2 *)(iVar15 + 0x24);
      *(undefined2 *)(iVar15 + 0x2e) = *(undefined2 *)(iVar15 + 0x26);
      iVar9 = *(int *)((int)register0x00000038 + -0x44);
    }
    else {
      iVar9 = *(int *)((int)register0x00000038 + -0x44);
    }
  }
  _ev_unlock(iVar9 + 4);
loc_F00E9564:
  return CONCAT44(param_2,*(undefined4 *)((int)register0x00000038 + -0x3c));
}
