
/* WARNING: Removing unreachable block (ram,0xf00e7bac) */
/* WARNING: Removing unreachable block (ram,0xf00e7c70) */
/* WARNING: Removing unreachable block (ram,0xf00e79b0) */
/* WARNING: Removing unreachable block (ram,0xf00e8088) */
/* WARNING: Removing unreachable block (ram,0xf00e7fa0) */
/* WARNING: Removing unreachable block (ram,0xf00e7d68) */
/* WARNING: Removing unreachable block (ram,0xf00e6edc) */
/* WARNING: Removing unreachable block (ram,0xf00e6ff8) */
/* WARNING: Removing unreachable block (ram,0xf00e6e48) */
/* WARNING: Removing unreachable block (ram,0xf00e7464) */
/* WARNING: Removing unreachable block (ram,0xf00e728c) */
/* WARNING: Removing unreachable block (ram,0xf00e7864) */
/* WARNING: Removing unreachable block (ram,0xf00e7780) */
/* WARNING: Removing unreachable block (ram,0xf00e7640) */
/* WARNING: Removing unreachable block (ram,0xf00e7138) */
/* WARNING: Removing unreachable block (ram,0xf00e6ad0) */
/* WARNING: Removing unreachable block (ram,0xf00e6bec) */
/* WARNING: Removing unreachable block (ram,0xf00e6a8c) */
/* WARNING: Removing unreachable block (ram,0xf00e6c3c) */
/* WARNING: Removing unreachable block (ram,0xf00e6b20) */
/* WARNING: Removing unreachable block (ram,0xf00e7534) */
/* WARNING: Removing unreachable block (ram,0xf00e7768) */
/* WARNING: Removing unreachable block (ram,0xf00e784c) */
/* WARNING: Removing unreachable block (ram,0xf00e717c) */
/* WARNING: Removing unreachable block (ram,0xf00e743c) */
/* WARNING: Removing unreachable block (ram,0xf00e7378) */
/* WARNING: Removing unreachable block (ram,0xf00e6fa8) */
/* WARNING: Removing unreachable block (ram,0xf00e6e8c) */
/* WARNING: Removing unreachable block (ram,0xf00e796c) */
/* WARNING: Removing unreachable block (ram,0xf00e7e74) */
/* WARNING: Removing unreachable block (ram,0xf00e7fb8) */
/* WARNING: Removing unreachable block (ram,0xf00e80a0) */
/* WARNING: Removing unreachable block (ram,0xf00e7ac0) */
/* WARNING: Removing unreachable block (ram,0xf00e7c98) */
/* WARNING: Removing unreachable block (ram,0xf00e8114) */
/* WARNING: Removing unreachable block (ram,0xf00e6a44) */

undefined8
-[IOFrameBufferDisplay moveCursor:frame:token:]
          (int param_1,int param_2,undefined2 *param_3,undefined4 param_4)

{
  byte bVar1;
  word wVar2;
  word wVar3;
  sword sVar4;
  sword sVar5;
  sword sVar6;
  sword sVar7;
  undefined (*pauVar8) [12];
  int iVar9;
  undefined4 *puVar10;
  int iVar11;
  int iVar12;
  uint uVar13;
  undefined2 uVar15;
  uint uVar14;
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
  *(int *)((int)register0x00000038 + -0x44) = param_1;
  iVar9 = *(int *)(param_1 + 0x1fc);
  *(int *)((int)register0x00000038 + -0x4c) = iVar9;
  iVar9 = iVar9 + 4;
  _ev_try_lock();
  puVar10 = *(undefined4 **)((int)register0x00000038 + -0x4c);
  if (iVar9 == 0) goto loc_F00E811C;
  *puVar10 = param_4;
  *(undefined2 *)(puVar10 + 7) = *param_3;
  *(undefined2 *)((int)puVar10 + 0x1e) = param_3[1];
  cVar21 = *(char *)(puVar10 + 2);
  *(char *)(puVar10 + 2) = cVar21 + '\x01';
  iVar9 = *(int *)((int)register0x00000038 + -0x4c);
  if (cVar21 == '\0') {
    iVar9 = *(int *)((int)register0x00000038 + -0x44);
    _objc_msgSend(iVar9,paDisplayinfo);
    uVar13 = *(uint *)(iVar9 + 0x18);
    if (uVar13 < 4) {
      if (uVar13 < 2) {
        if (uVar13 == 1) {
          iVar11 = *(int *)((int)register0x00000038 + -0x44);
          _objc_msgSend(iVar11,paDisplayinfo);
          iVar16 = *(int *)(*(int *)((int)register0x00000038 + -0x44) + 0x1fc);
          *(undefined2 *)((int)register0x00000038 + -0x18) = *(undefined2 *)(iVar16 + 0xc);
          *(undefined2 *)((int)register0x00000038 + -0x16) = *(undefined2 *)(iVar16 + 0xe);
          sVar4 = *(sword *)(iVar16 + 0x10);
          *(sword *)((int)register0x00000038 + -0x14) = sVar4;
          *(undefined2 *)((int)register0x00000038 + -0x12) = *(undefined2 *)(iVar16 + 0x12);
          iVar12 = *(int *)(iVar11 + 8);
          iVar9 = iVar12;
          umul(iVar12,(int)sVar4 - (int)*(sword *)(iVar16 + 0x34));
          puVar20 = (undefined *)(iVar16 + 0x848);
          puVar18 = (undefined *)
                    (*(int *)(iVar11 + 0x14) + iVar9 +
                    ((int)*(sword *)((int)register0x00000038 + -0x18) -
                    (int)*(sword *)(iVar16 + 0x30)));
          iVar16 = (uint)*(word *)((int)register0x00000038 + -0x16) -
                   (int)*(sword *)((int)register0x00000038 + -0x18);
          iVar11 = ((uint)*(word *)((int)register0x00000038 + -0x12) -
                   (uint)*(word *)((int)register0x00000038 + -0x14)) + -1;
          iVar9 = iVar16;
          if (iVar11 * 0x10000 >> 0x10 == -1) goto loc_F00E6CDC;
          do {
            while ((iVar9 + -1) * 0x10000 >> 0x10 != -1) {
              *puVar18 = *puVar20;
              puVar20 = puVar20 + 1;
              puVar18 = puVar18 + 1;
              iVar9 = iVar9 + -1;
            }
            iVar11 = iVar11 + -1;
            puVar18 = puVar18 + (iVar12 - (iVar16 * 0x10000 >> 0x10));
            iVar9 = iVar16;
          } while (iVar11 * 0x10000 >> 0x10 != -1);
          iVar9 = *(int *)((int)register0x00000038 + -0x4c);
        }
        else {
          iVar9 = *(int *)((int)register0x00000038 + -0x4c);
        }
      }
      else {
loc_F00E6CDC:
        iVar9 = *(int *)((int)register0x00000038 + -0x4c);
      }
    }
    else {
      if (uVar13 == 4) {
        iVar11 = *(int *)((int)register0x00000038 + -0x44);
        _objc_msgSend(iVar11,paDisplayinfo);
        iVar16 = *(int *)(*(int *)((int)register0x00000038 + -0x44) + 0x1fc);
        *(undefined2 *)((int)register0x00000038 + -0x18) = *(undefined2 *)(iVar16 + 0xc);
        *(undefined2 *)((int)register0x00000038 + -0x16) = *(undefined2 *)(iVar16 + 0xe);
        sVar4 = *(sword *)(iVar16 + 0x10);
        *(sword *)((int)register0x00000038 + -0x14) = sVar4;
        *(undefined2 *)((int)register0x00000038 + -0x12) = *(undefined2 *)(iVar16 + 0x12);
        iVar12 = *(int *)(iVar11 + 8);
        iVar9 = iVar12;
        umul(iVar12,(int)sVar4 - (int)*(sword *)(iVar16 + 0x34));
        puVar19 = (undefined4 *)(iVar16 + 0x1048);
        puVar10 = (undefined4 *)
                  (*(int *)(iVar11 + 0x14) + iVar9 * 4 +
                  ((int)*(sword *)((int)register0x00000038 + -0x18) - (int)*(sword *)(iVar16 + 0x30)
                  ) * 4);
        iVar11 = (int)*(sword *)((int)register0x00000038 + -0x16) -
                 (int)*(sword *)((int)register0x00000038 + -0x18);
        iVar9 = (int)*(sword *)((int)register0x00000038 + -0x12) -
                (int)*(sword *)((int)register0x00000038 + -0x14);
        while (iVar9 = iVar9 + -1, iVar16 = iVar11, iVar9 != -1) {
          while (iVar16 + -1 != -1) {
            *puVar10 = *puVar19;
            puVar19 = puVar19 + 1;
            puVar10 = puVar10 + 1;
            iVar16 = iVar16 + -1;
          }
          puVar10 = puVar10 + (iVar12 - iVar11);
        }
        goto loc_F00E6CDC;
      }
      iVar9 = *(int *)((int)register0x00000038 + -0x4c);
    }
  }
  iVar11 = *(int *)((int)register0x00000038 + -0x4c);
  if (*(char *)(iVar9 + 9) != '\0') {
    *(undefined *)(iVar9 + 9) = 0;
    iVar11 = *(int *)((int)register0x00000038 + -0x4c);
    if (*(char *)(iVar9 + 8) != '\0') {
      *(char *)(iVar9 + 8) = *(char *)(iVar9 + 8) + -1;
      iVar11 = *(int *)((int)register0x00000038 + -0x4c);
    }
  }
  if (*(char *)(iVar11 + 10) == '\0') goto loc_F00E78D4;
  piVar17 = *(int **)(*(int *)((int)register0x00000038 + -0x44) + 0x1fc);
  iVar9 = *piVar17;
  wVar2 = *(word *)(piVar17 + iVar9 + 0xe);
  *(word *)((int)register0x00000038 + -0x20) = wVar2;
  wVar3 = *(word *)((int)piVar17 + iVar9 * 4 + 0x3a);
  *(word *)((int)register0x00000038 + -0x1e) = wVar3;
  cVar21 = '\0';
  iVar9 = (uint)*(word *)(piVar17 + 7) - (uint)wVar2;
  *(sword *)((int)register0x00000038 + -0x28) = (sword)iVar9;
  *(sword *)((int)register0x00000038 + -0x26) = (sword)(iVar9 + 0x10);
  iVar11 = (uint)*(word *)((int)piVar17 + 0x1e) - (uint)wVar3;
  *(sword *)((int)register0x00000038 + -0x24) = (sword)iVar11;
  *(sword *)((int)register0x00000038 + -0x22) = (sword)(iVar11 + 0x10);
  if (((iVar9 * 0x10000 >> 0x10 < (int)*(sword *)((int)piVar17 + 0x16)) &&
      ((int)*(sword *)(piVar17 + 5) < (iVar9 + 0x10) * 0x10000 >> 0x10)) &&
     (iVar11 * 0x10000 >> 0x10 < (int)*(sword *)((int)piVar17 + 0x1a))) {
    if ((int)*(sword *)(piVar17 + 6) < (iVar11 + 0x10) * 0x10000 >> 0x10) {
      cVar21 = '\x01';
    }
    else {
      cVar21 = '\0';
    }
  }
  if (cVar21 == *(char *)((int)piVar17 + 0xb)) {
    iVar9 = *(int *)((int)register0x00000038 + -0x4c);
  }
  else {
    *(char *)((int)piVar17 + 0xb) = cVar21;
    if (*(char *)((int)piVar17 + 0xb) == '\0') {
      iVar9 = *(int *)((int)register0x00000038 + -0x44);
      iVar11 = *(int *)(iVar9 + 0x1fc);
      if (*(char *)(iVar11 + 8) == '\0') {
        iVar9 = *(int *)((int)register0x00000038 + -0x4c);
      }
      else {
        *(char *)(iVar11 + 8) = *(char *)(iVar11 + 8) + -1;
        if (*(char *)(iVar11 + 8) == '\0') {
          piVar17 = *(int **)(iVar9 + 0x1fc);
          iVar9 = *piVar17;
          sVar4 = *(sword *)(piVar17 + iVar9 + 0xe);
          *(sword *)((int)register0x00000038 + -0x38) = sVar4;
          *(undefined2 *)((int)register0x00000038 + -0x36) =
               *(undefined2 *)((int)piVar17 + iVar9 * 4 + 0x3a);
          *(sword *)(piVar17 + 8) = *(sword *)(piVar17 + 7) - sVar4;
          *(sword *)((int)piVar17 + 0x22) = *(sword *)(piVar17 + 8) + 0x10;
          iVar9 = *(int *)((int)register0x00000038 + -0x44);
          *(sword *)(piVar17 + 9) =
               *(sword *)((int)piVar17 + 0x1e) - *(sword *)((int)register0x00000038 + -0x36);
          pauVar8 = paDisplayinfo;
          sVar4 = *(sword *)(piVar17 + 9);
          *(int **)((int)register0x00000038 + -0x54) = piVar17;
          *(sword *)((int)piVar17 + 0x26) = sVar4 + 0x10;
          _objc_msgSend(iVar9,pauVar8);
          uVar13 = *(uint *)(iVar9 + 0x18);
          if (uVar13 < 4) {
            if (1 < uVar13) goto loc_F00E78B0;
            if (uVar13 == 1) {
              iVar9 = *(int *)((int)register0x00000038 + -0x44);
              _objc_msgSend(iVar9,paDisplayinfo);
              piVar17 = *(int **)(*(int *)((int)register0x00000038 + -0x44) + 0x1fc);
              sVar4 = *(sword *)(piVar17 + 8);
              *(sword *)((int)register0x00000038 + -0x40) = sVar4;
              sVar5 = *(sword *)((int)piVar17 + 0x22);
              *(sword *)((int)register0x00000038 + -0x3e) = sVar5;
              sVar6 = *(sword *)(piVar17 + 9);
              *(sword *)((int)register0x00000038 + -0x3c) = sVar6;
              sVar7 = *(sword *)((int)piVar17 + 0x26);
              *(sword *)((int)register0x00000038 + -0x3a) = sVar7;
              if (sVar6 < *(sword *)(piVar17 + 0xd)) {
                *(undefined2 *)((int)register0x00000038 + -0x3c) = *(undefined2 *)(piVar17 + 0xd);
              }
              if (*(sword *)((int)piVar17 + 0x36) < sVar7) {
                *(undefined2 *)((int)register0x00000038 + -0x3a) =
                     *(undefined2 *)((int)piVar17 + 0x36);
              }
              if (sVar4 < *(sword *)(piVar17 + 0xc)) {
                *(undefined2 *)((int)register0x00000038 + -0x40) = *(undefined2 *)(piVar17 + 0xc);
              }
              uVar15 = *(undefined2 *)((int)register0x00000038 + -0x40);
              if (*(sword *)((int)piVar17 + 0x32) < sVar5) {
                *(undefined2 *)((int)register0x00000038 + -0x3e) =
                     *(undefined2 *)((int)piVar17 + 0x32);
                uVar15 = *(undefined2 *)((int)register0x00000038 + -0x40);
              }
              *(undefined2 *)(piVar17 + 3) = uVar15;
              *(undefined2 *)((int)piVar17 + 0xe) = *(undefined2 *)((int)register0x00000038 + -0x3e)
              ;
              *(undefined2 *)(piVar17 + 4) = *(undefined2 *)((int)register0x00000038 + -0x3c);
              *(undefined2 *)((int)piVar17 + 0x12) =
                   *(undefined2 *)((int)register0x00000038 + -0x3a);
              sVar4 = *(sword *)(piVar17 + 0xd);
              *(undefined4 *)((int)register0x00000038 + -0x5c) = *(undefined4 *)(iVar9 + 8);
              iVar11 = *(int *)((int)register0x00000038 + -0x5c);
              umul(iVar11,(int)*(sword *)((int)register0x00000038 + -0x3c) - (int)sVar4);
              iVar16 = (int)*(sword *)((int)register0x00000038 + -0x40);
              pbVar28 = (byte *)(piVar17 + 0x212);
              pbVar29 = (byte *)(*(int *)(iVar9 + 0x14) + iVar11 +
                                (iVar16 - *(sword *)(piVar17 + 0xc)));
              iVar11 = *(int *)(iVar9 + 0x1c);
              *(int *)((int)register0x00000038 + -100) =
                   *(sword *)((int)register0x00000038 + -0x3e) - iVar16;
              *(int *)((int)register0x00000038 + -0x5c) =
                   *(int *)((int)register0x00000038 + -0x5c) -
                   (*(sword *)((int)register0x00000038 + -0x3e) - iVar16);
              iVar9 = ((int)*(sword *)((int)register0x00000038 + -0x3c) -
                      (int)*(sword *)(piVar17 + 9)) * 0x10 + (iVar16 - *(sword *)(piVar17 + 8));
              pbVar26 = (byte *)((int)piVar17 + iVar9 + *piVar17 * 0x100 + 0x48);
              pbVar30 = (byte *)((int)piVar17 + iVar9 + *piVar17 * 0x100 + 0x448);
              iVar9 = (int)*(sword *)((int)register0x00000038 + -0x3a) -
                      (int)*(sword *)((int)register0x00000038 + -0x3c);
              param_2 = 0x10 - *(int *)((int)register0x00000038 + -100);
              if (iVar11 == 1) {
                iVar9 = iVar9 + -1;
                if (iVar9 < 0) goto loc_F00E78B0;
                do {
                  iVar11 = *(int *)((int)register0x00000038 + -100);
                  while (iVar11 = iVar11 + -1, -1 < iVar11) {
                    uVar13 = (uint)*pbVar29;
                    *pbVar28 = *pbVar29;
                    pbVar28 = pbVar28 + 1;
                    bVar1 = *pbVar26;
                    pbVar26 = pbVar26 + 1;
                    umul(uVar13,0xff - (uint)*pbVar30);
                    pbVar30 = pbVar30 + 1;
                    *pbVar29 = bVar1 + (char)(uVar13 + ((int)uVar13 >> 8) + 1 >> 8);
                    pbVar29 = pbVar29 + 1;
                  }
                  pbVar26 = pbVar26 + param_2;
                  pbVar30 = pbVar30 + param_2;
                  iVar9 = iVar9 + -1;
                  pbVar29 = pbVar29 + *(int *)((int)register0x00000038 + -0x5c);
                } while (-1 < iVar9);
                iVar9 = *(int *)((int)register0x00000038 + -0x54);
              }
              else {
                iVar16 = *(int *)(*(int *)((int)register0x00000038 + -0x44) + 0x208);
                iVar9 = iVar9 + -1;
                iVar11 = *(int *)(*(int *)((int)register0x00000038 + -0x44) + 0x20c);
                if (iVar9 < 0) goto loc_F00E78B0;
                do {
                  iVar12 = *(int *)((int)register0x00000038 + -100);
                  while (iVar12 = iVar12 + -1, -1 < iVar12) {
                    *pbVar28 = *pbVar29;
                    if (*pbVar30 != 0) {
                      bVar24 = *pbVar26;
                      bVar1 = ~*pbVar30;
                      if (bVar1 != 0) {
                        uVar22 = *(uint *)(iVar16 + (uint)*pbVar29 * 4);
                        uVar13 = (uVar22 & 0xff00ff00) >> 8;
                        umul(uVar13,bVar1);
                        uVar22 = uVar22 & 0xff00ff;
                        umul(uVar22,bVar1);
                        uVar13 = (*(uint *)(iVar16 + (uint)bVar24 * 4) & 0xffffff00) +
                                 (uVar13 + 0x10001 + ((uVar13 & 0xff00ff00) >> 8) & 0xff00ff00 |
                                 uVar22 + 0x10001 + ((uVar22 & 0xff00ff00) >> 8) >> 8 & 0xff00ff);
                        if (((uVar13 ^ uVar13 >> 8) & 0xffff00) == 0) {
                          bVar24 = *(byte *)((uVar13 >> 0x18) + iVar11 + 0x300);
                        }
                        else {
                          bVar24 = *(char *)((uVar13 >> 8 & 0xff) + iVar11 + 0x200) +
                                   *(char *)(iVar11 + (uVar13 >> 0x18)) +
                                   *(char *)((uVar13 >> 0x10 & 0xff) + iVar11 + 0x100);
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
                  pbVar29 = pbVar29 + *(int *)((int)register0x00000038 + -0x5c);
                } while (-1 < iVar9);
                iVar9 = *(int *)((int)register0x00000038 + -0x54);
              }
            }
            else {
              iVar9 = *(int *)((int)register0x00000038 + -0x54);
            }
          }
          else if (uVar13 == 4) {
            iVar9 = *(int *)((int)register0x00000038 + -0x44);
            _objc_msgSend(iVar9,paDisplayinfo);
            piVar17 = *(int **)(*(int *)((int)register0x00000038 + -0x44) + 0x1fc);
            sVar4 = *(sword *)(piVar17 + 8);
            *(sword *)((int)register0x00000038 + -0x40) = sVar4;
            sVar5 = *(sword *)((int)piVar17 + 0x22);
            *(sword *)((int)register0x00000038 + -0x3e) = sVar5;
            sVar6 = *(sword *)(piVar17 + 9);
            *(sword *)((int)register0x00000038 + -0x3c) = sVar6;
            sVar7 = *(sword *)((int)piVar17 + 0x26);
            *(sword *)((int)register0x00000038 + -0x3a) = sVar7;
            if (sVar6 < *(sword *)(piVar17 + 0xd)) {
              *(undefined2 *)((int)register0x00000038 + -0x3c) = *(undefined2 *)(piVar17 + 0xd);
            }
            if (*(sword *)((int)piVar17 + 0x36) < sVar7) {
              *(undefined2 *)((int)register0x00000038 + -0x3a) =
                   *(undefined2 *)((int)piVar17 + 0x36);
            }
            if (sVar4 < *(sword *)(piVar17 + 0xc)) {
              *(undefined2 *)((int)register0x00000038 + -0x40) = *(undefined2 *)(piVar17 + 0xc);
            }
            uVar15 = *(undefined2 *)((int)register0x00000038 + -0x40);
            if (*(sword *)((int)piVar17 + 0x32) < sVar5) {
              *(undefined2 *)((int)register0x00000038 + -0x3e) =
                   *(undefined2 *)((int)piVar17 + 0x32);
              uVar15 = *(undefined2 *)((int)register0x00000038 + -0x40);
            }
            *(undefined2 *)(piVar17 + 3) = uVar15;
            *(undefined2 *)((int)piVar17 + 0xe) = *(undefined2 *)((int)register0x00000038 + -0x3e);
            *(undefined2 *)(piVar17 + 4) = *(undefined2 *)((int)register0x00000038 + -0x3c);
            *(undefined2 *)((int)piVar17 + 0x12) = *(undefined2 *)((int)register0x00000038 + -0x3a);
            param_2 = *(int *)(iVar9 + 8);
            iVar11 = param_2;
            umul(param_2,(int)*(sword *)((int)register0x00000038 + -0x3c) -
                         (int)*(sword *)(piVar17 + 0xd));
            puVar27 = (uint *)(piVar17 + 0x412);
            iVar16 = (int)*(sword *)((int)register0x00000038 + -0x40);
            puVar23 = (uint *)(*(int *)(iVar9 + 0x14) + iVar11 * 4 +
                              (iVar16 - *(sword *)(piVar17 + 0xc)) * 4);
            iVar11 = (int)*(sword *)((int)register0x00000038 + -0x3c);
            iVar12 = *(sword *)((int)register0x00000038 + -0x3e) - iVar16;
            param_2 = param_2 - iVar12;
            puVar25 = (uint *)(piVar17 +
                              *piVar17 * 0x100 +
                              (iVar11 - *(sword *)(piVar17 + 9)) * 0x10 +
                              (iVar16 - *(sword *)(piVar17 + 8)) + 0x12);
            if ((*(char *)(iVar9 + 0x20) == 'A') || (*(char *)(iVar9 + 0x20) == '-')) {
              iVar11 = (*(sword *)((int)register0x00000038 + -0x3a) - iVar11) + -1;
              iVar9 = iVar12;
              if (iVar11 != -1) {
                do {
                  while (iVar9 + -1 != -1) {
                    uVar13 = *puVar23;
                    *puVar27 = uVar13;
                    uVar31 = *puVar25;
                    puVar27 = puVar27 + 1;
                    uVar22 = uVar31 >> 0x18;
                    puVar25 = puVar25 + 1;
                    if (uVar22 != 0) {
                      if (uVar22 == 0xff) {
                        *puVar23 = uVar31;
                      }
                      else {
                        uVar13 = uVar13 << 8;
                        uVar14 = (uVar13 & 0xff00ff00) >> 8;
                        umul(uVar14,uVar22 ^ 0xff);
                        uVar13 = uVar13 & 0xff00ff;
                        umul(uVar13,uVar22 ^ 0xff);
                        *puVar23 = uVar31 * 0x100 +
                                   (uVar14 + 0xff00ff & 0xff00ff00 |
                                   uVar13 + 0xff00ff >> 8 & 0xff00ff) >> 8 | 0xff000000;
                      }
                    }
                    puVar23 = puVar23 + 1;
                    iVar9 = iVar9 + -1;
                  }
                  puVar25 = puVar25 + (0x10 - iVar12);
                  iVar11 = iVar11 + -1;
                  puVar23 = puVar23 + param_2;
                  iVar9 = iVar12;
                } while (iVar11 != -1);
                iVar9 = *(int *)((int)register0x00000038 + -0x54);
                goto loc_F00E78B4;
              }
            }
            else {
              iVar11 = *(sword *)((int)register0x00000038 + -0x3a) - iVar11;
              while (iVar11 = iVar11 + -1, iVar9 = iVar12, iVar11 != -1) {
                while (iVar9 + -1 != -1) {
                  uVar22 = *puVar23;
                  *puVar27 = uVar22;
                  uVar31 = *puVar25;
                  puVar27 = puVar27 + 1;
                  uVar13 = uVar31 & 0xff;
                  puVar25 = puVar25 + 1;
                  if (uVar13 != 0) {
                    if (uVar13 == 0xff) {
                      *puVar23 = uVar31;
                    }
                    else {
                      uVar14 = (uVar22 & 0xff00ff00) >> 8;
                      umul(uVar14,uVar13 ^ 0xff);
                      uVar22 = uVar22 & 0xff00ff;
                      umul(uVar22,uVar13 ^ 0xff);
                      *puVar23 = uVar31 + (uVar14 + 0xff00ff & 0xff00ff00 |
                                          uVar22 + 0xff00ff >> 8 & 0xff00ff);
                    }
                  }
                  puVar23 = puVar23 + 1;
                  iVar9 = iVar9 + -1;
                }
                puVar25 = puVar25 + (0x10 - iVar12);
                puVar23 = puVar23 + param_2;
              }
            }
loc_F00E78B0:
            iVar9 = *(int *)((int)register0x00000038 + -0x54);
          }
          else {
            iVar9 = *(int *)((int)register0x00000038 + -0x54);
          }
loc_F00E78B4:
          *(undefined2 *)(iVar9 + 0x28) = *(undefined2 *)(iVar9 + 0x20);
          *(undefined2 *)(iVar9 + 0x2a) = *(undefined2 *)(iVar9 + 0x22);
          *(undefined2 *)(iVar9 + 0x2c) = *(undefined2 *)(iVar9 + 0x24);
          *(undefined2 *)(iVar9 + 0x2e) = *(undefined2 *)(iVar9 + 0x26);
          goto loc_F00E78D4;
        }
        iVar9 = *(int *)((int)register0x00000038 + -0x4c);
      }
    }
    else {
      cVar21 = *(char *)(*(int *)(*(int *)((int)register0x00000038 + -0x44) + 0x1fc) + 8);
      *(char *)(*(int *)(*(int *)((int)register0x00000038 + -0x44) + 0x1fc) + 8) = cVar21 + '\x01';
      iVar9 = *(int *)((int)register0x00000038 + -0x4c);
      if (cVar21 == '\0') {
        iVar9 = *(int *)((int)register0x00000038 + -0x44);
        _objc_msgSend(iVar9,paDisplayinfo);
        uVar13 = *(uint *)(iVar9 + 0x18);
        if (uVar13 < 4) {
          if (uVar13 < 2) {
            if (uVar13 == 1) {
              iVar11 = *(int *)((int)register0x00000038 + -0x44);
              _objc_msgSend(iVar11,paDisplayinfo);
              iVar16 = *(int *)(*(int *)((int)register0x00000038 + -0x44) + 0x1fc);
              *(undefined2 *)((int)register0x00000038 + -0x30) = *(undefined2 *)(iVar16 + 0xc);
              *(undefined2 *)((int)register0x00000038 + -0x2e) = *(undefined2 *)(iVar16 + 0xe);
              sVar4 = *(sword *)(iVar16 + 0x10);
              *(sword *)((int)register0x00000038 + -0x2c) = sVar4;
              *(undefined2 *)((int)register0x00000038 + -0x2a) = *(undefined2 *)(iVar16 + 0x12);
              iVar12 = *(int *)(iVar11 + 8);
              iVar9 = iVar12;
              umul(iVar12,(int)sVar4 - (int)*(sword *)(iVar16 + 0x34));
              puVar20 = (undefined *)(iVar16 + 0x848);
              puVar18 = (undefined *)
                        (*(int *)(iVar11 + 0x14) + iVar9 +
                        ((int)*(sword *)((int)register0x00000038 + -0x30) -
                        (int)*(sword *)(iVar16 + 0x30)));
              iVar16 = (uint)*(word *)((int)register0x00000038 + -0x2e) -
                       (int)*(sword *)((int)register0x00000038 + -0x30);
              iVar11 = ((uint)*(word *)((int)register0x00000038 + -0x2a) -
                       (uint)*(word *)((int)register0x00000038 + -0x2c)) + -1;
              iVar9 = iVar16;
              if (iVar11 * 0x10000 >> 0x10 == -1) goto loc_F00E78D4;
              do {
                while ((iVar9 + -1) * 0x10000 >> 0x10 != -1) {
                  *puVar18 = *puVar20;
                  puVar20 = puVar20 + 1;
                  puVar18 = puVar18 + 1;
                  iVar9 = iVar9 + -1;
                }
                iVar11 = iVar11 + -1;
                puVar18 = puVar18 + (iVar12 - (iVar16 * 0x10000 >> 0x10));
                iVar9 = iVar16;
              } while (iVar11 * 0x10000 >> 0x10 != -1);
              iVar9 = *(int *)((int)register0x00000038 + -0x4c);
            }
            else {
              iVar9 = *(int *)((int)register0x00000038 + -0x4c);
            }
          }
          else {
loc_F00E78D4:
            iVar9 = *(int *)((int)register0x00000038 + -0x4c);
          }
        }
        else if (uVar13 == 4) {
          iVar11 = *(int *)((int)register0x00000038 + -0x44);
          _objc_msgSend(iVar11,paDisplayinfo);
          iVar16 = *(int *)(*(int *)((int)register0x00000038 + -0x44) + 0x1fc);
          *(undefined2 *)((int)register0x00000038 + -0x30) = *(undefined2 *)(iVar16 + 0xc);
          *(undefined2 *)((int)register0x00000038 + -0x2e) = *(undefined2 *)(iVar16 + 0xe);
          sVar4 = *(sword *)(iVar16 + 0x10);
          *(sword *)((int)register0x00000038 + -0x2c) = sVar4;
          *(undefined2 *)((int)register0x00000038 + -0x2a) = *(undefined2 *)(iVar16 + 0x12);
          iVar12 = *(int *)(iVar11 + 8);
          iVar9 = iVar12;
          umul(iVar12,(int)sVar4 - (int)*(sword *)(iVar16 + 0x34));
          puVar19 = (undefined4 *)(iVar16 + 0x1048);
          puVar10 = (undefined4 *)
                    (*(int *)(iVar11 + 0x14) + iVar9 * 4 +
                    ((int)*(sword *)((int)register0x00000038 + -0x30) -
                    (int)*(sword *)(iVar16 + 0x30)) * 4);
          iVar16 = (int)*(sword *)((int)register0x00000038 + -0x2e) -
                   (int)*(sword *)((int)register0x00000038 + -0x30);
          iVar11 = ((int)*(sword *)((int)register0x00000038 + -0x2a) -
                   (int)*(sword *)((int)register0x00000038 + -0x2c)) + -1;
          iVar9 = iVar16;
          if (iVar11 == -1) goto loc_F00E78D4;
          do {
            while (iVar9 + -1 != -1) {
              *puVar10 = *puVar19;
              puVar19 = puVar19 + 1;
              puVar10 = puVar10 + 1;
              iVar9 = iVar9 + -1;
            }
            iVar11 = iVar11 + -1;
            puVar10 = puVar10 + (iVar12 - iVar16);
            iVar9 = iVar16;
          } while (iVar11 != -1);
          iVar9 = *(int *)((int)register0x00000038 + -0x4c);
        }
        else {
          iVar9 = *(int *)((int)register0x00000038 + -0x4c);
        }
      }
    }
  }
  if (*(char *)(iVar9 + 8) == '\0') {
    iVar11 = *(int *)((int)register0x00000038 + -0x4c);
  }
  else {
    *(char *)(iVar9 + 8) = *(char *)(iVar9 + 8) + -1;
    iVar11 = *(int *)((int)register0x00000038 + -0x4c);
    if (*(char *)(iVar9 + 8) == '\0') {
      piVar17 = *(int **)(*(int *)((int)register0x00000038 + -0x44) + 0x1fc);
      iVar9 = *piVar17;
      sVar4 = *(sword *)(piVar17 + iVar9 + 0xe);
      *(sword *)((int)register0x00000038 + -0x38) = sVar4;
      *(undefined2 *)((int)register0x00000038 + -0x36) =
           *(undefined2 *)((int)piVar17 + iVar9 * 4 + 0x3a);
      *(sword *)(piVar17 + 8) = *(sword *)(piVar17 + 7) - sVar4;
      *(sword *)((int)piVar17 + 0x22) = *(sword *)(piVar17 + 8) + 0x10;
      iVar9 = *(int *)((int)register0x00000038 + -0x44);
      *(sword *)(piVar17 + 9) =
           *(sword *)((int)piVar17 + 0x1e) - *(sword *)((int)register0x00000038 + -0x36);
      pauVar8 = paDisplayinfo;
      sVar4 = *(sword *)(piVar17 + 9);
      *(int **)((int)register0x00000038 + -0x6c) = piVar17;
      *(sword *)((int)piVar17 + 0x26) = sVar4 + 0x10;
      _objc_msgSend(iVar9,pauVar8);
      uVar13 = *(uint *)(iVar9 + 0x18);
      if (uVar13 < 4) {
        if (1 < uVar13) goto loc_F00E80EC;
        if (uVar13 == 1) {
          iVar9 = *(int *)((int)register0x00000038 + -0x44);
          _objc_msgSend(iVar9,paDisplayinfo);
          piVar17 = *(int **)(*(int *)((int)register0x00000038 + -0x44) + 0x1fc);
          sVar4 = *(sword *)(piVar17 + 8);
          *(sword *)((int)register0x00000038 + -0x40) = sVar4;
          sVar5 = *(sword *)((int)piVar17 + 0x22);
          *(sword *)((int)register0x00000038 + -0x3e) = sVar5;
          sVar6 = *(sword *)(piVar17 + 9);
          *(sword *)((int)register0x00000038 + -0x3c) = sVar6;
          sVar7 = *(sword *)((int)piVar17 + 0x26);
          *(sword *)((int)register0x00000038 + -0x3a) = sVar7;
          if (sVar6 < *(sword *)(piVar17 + 0xd)) {
            *(undefined2 *)((int)register0x00000038 + -0x3c) = *(undefined2 *)(piVar17 + 0xd);
          }
          if (*(sword *)((int)piVar17 + 0x36) < sVar7) {
            *(undefined2 *)((int)register0x00000038 + -0x3a) = *(undefined2 *)((int)piVar17 + 0x36);
          }
          if (sVar4 < *(sword *)(piVar17 + 0xc)) {
            *(undefined2 *)((int)register0x00000038 + -0x40) = *(undefined2 *)(piVar17 + 0xc);
          }
          uVar15 = *(undefined2 *)((int)register0x00000038 + -0x40);
          if (*(sword *)((int)piVar17 + 0x32) < sVar5) {
            *(undefined2 *)((int)register0x00000038 + -0x3e) = *(undefined2 *)((int)piVar17 + 0x32);
            uVar15 = *(undefined2 *)((int)register0x00000038 + -0x40);
          }
          *(undefined2 *)(piVar17 + 3) = uVar15;
          *(undefined2 *)((int)piVar17 + 0xe) = *(undefined2 *)((int)register0x00000038 + -0x3e);
          *(undefined2 *)(piVar17 + 4) = *(undefined2 *)((int)register0x00000038 + -0x3c);
          *(undefined2 *)((int)piVar17 + 0x12) = *(undefined2 *)((int)register0x00000038 + -0x3a);
          sVar4 = *(sword *)(piVar17 + 0xd);
          *(undefined4 *)((int)register0x00000038 + -0x74) = *(undefined4 *)(iVar9 + 8);
          iVar11 = *(int *)((int)register0x00000038 + -0x74);
          umul(iVar11,(int)*(sword *)((int)register0x00000038 + -0x3c) - (int)sVar4);
          iVar16 = (int)*(sword *)((int)register0x00000038 + -0x40);
          pbVar28 = (byte *)(piVar17 + 0x212);
          pbVar29 = (byte *)(*(int *)(iVar9 + 0x14) + iVar11 + (iVar16 - *(sword *)(piVar17 + 0xc)))
          ;
          iVar11 = *(int *)(iVar9 + 0x1c);
          *(int *)((int)register0x00000038 + -0x7c) =
               *(sword *)((int)register0x00000038 + -0x3e) - iVar16;
          *(int *)((int)register0x00000038 + -0x74) =
               *(int *)((int)register0x00000038 + -0x74) -
               (*(sword *)((int)register0x00000038 + -0x3e) - iVar16);
          iVar9 = ((int)*(sword *)((int)register0x00000038 + -0x3c) - (int)*(sword *)(piVar17 + 9))
                  * 0x10 + (iVar16 - *(sword *)(piVar17 + 8));
          pbVar26 = (byte *)((int)piVar17 + iVar9 + *piVar17 * 0x100 + 0x48);
          pbVar30 = (byte *)((int)piVar17 + iVar9 + *piVar17 * 0x100 + 0x448);
          iVar9 = (int)*(sword *)((int)register0x00000038 + -0x3a) -
                  (int)*(sword *)((int)register0x00000038 + -0x3c);
          param_2 = 0x10 - *(int *)((int)register0x00000038 + -0x7c);
          if (iVar11 == 1) {
            iVar9 = iVar9 + -1;
            if (iVar9 < 0) {
loc_F00E80EC:
              iVar11 = *(int *)((int)register0x00000038 + -0x6c);
            }
            else {
              do {
                iVar11 = *(int *)((int)register0x00000038 + -0x7c);
                while (iVar11 = iVar11 + -1, -1 < iVar11) {
                  uVar13 = (uint)*pbVar29;
                  *pbVar28 = *pbVar29;
                  pbVar28 = pbVar28 + 1;
                  bVar1 = *pbVar26;
                  pbVar26 = pbVar26 + 1;
                  umul(uVar13,0xff - (uint)*pbVar30);
                  pbVar30 = pbVar30 + 1;
                  *pbVar29 = bVar1 + (char)(uVar13 + ((int)uVar13 >> 8) + 1 >> 8);
                  pbVar29 = pbVar29 + 1;
                }
                pbVar26 = pbVar26 + param_2;
                pbVar30 = pbVar30 + param_2;
                iVar9 = iVar9 + -1;
                pbVar29 = pbVar29 + *(int *)((int)register0x00000038 + -0x74);
              } while (-1 < iVar9);
              iVar11 = *(int *)((int)register0x00000038 + -0x6c);
            }
          }
          else {
            iVar16 = *(int *)(*(int *)((int)register0x00000038 + -0x44) + 0x208);
            iVar9 = iVar9 + -1;
            iVar11 = *(int *)(*(int *)((int)register0x00000038 + -0x44) + 0x20c);
            if (iVar9 < 0) goto loc_F00E80EC;
            do {
              iVar12 = *(int *)((int)register0x00000038 + -0x7c);
              while (iVar12 = iVar12 + -1, -1 < iVar12) {
                *pbVar28 = *pbVar29;
                if (*pbVar30 != 0) {
                  bVar24 = *pbVar26;
                  bVar1 = ~*pbVar30;
                  if (bVar1 != 0) {
                    uVar22 = *(uint *)(iVar16 + (uint)*pbVar29 * 4);
                    uVar13 = (uVar22 & 0xff00ff00) >> 8;
                    umul(uVar13,bVar1);
                    uVar22 = uVar22 & 0xff00ff;
                    umul(uVar22,bVar1);
                    uVar13 = (*(uint *)(iVar16 + (uint)bVar24 * 4) & 0xffffff00) +
                             (uVar13 + 0x10001 + ((uVar13 & 0xff00ff00) >> 8) & 0xff00ff00 |
                             uVar22 + 0x10001 + ((uVar22 & 0xff00ff00) >> 8) >> 8 & 0xff00ff);
                    if (((uVar13 ^ uVar13 >> 8) & 0xffff00) == 0) {
                      bVar24 = *(byte *)((uVar13 >> 0x18) + iVar11 + 0x300);
                    }
                    else {
                      bVar24 = *(char *)((uVar13 >> 8 & 0xff) + iVar11 + 0x200) +
                               *(char *)(iVar11 + (uVar13 >> 0x18)) +
                               *(char *)((uVar13 >> 0x10 & 0xff) + iVar11 + 0x100);
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
              pbVar29 = pbVar29 + *(int *)((int)register0x00000038 + -0x74);
            } while (-1 < iVar9);
            iVar11 = *(int *)((int)register0x00000038 + -0x6c);
          }
        }
        else {
          iVar11 = *(int *)((int)register0x00000038 + -0x6c);
        }
      }
      else if (uVar13 == 4) {
        iVar9 = *(int *)((int)register0x00000038 + -0x44);
        _objc_msgSend(iVar9,paDisplayinfo);
        piVar17 = *(int **)(*(int *)((int)register0x00000038 + -0x44) + 0x1fc);
        sVar4 = *(sword *)(piVar17 + 8);
        *(sword *)((int)register0x00000038 + -0x40) = sVar4;
        sVar5 = *(sword *)((int)piVar17 + 0x22);
        *(sword *)((int)register0x00000038 + -0x3e) = sVar5;
        sVar6 = *(sword *)(piVar17 + 9);
        *(sword *)((int)register0x00000038 + -0x3c) = sVar6;
        sVar7 = *(sword *)((int)piVar17 + 0x26);
        *(sword *)((int)register0x00000038 + -0x3a) = sVar7;
        if (sVar6 < *(sword *)(piVar17 + 0xd)) {
          *(undefined2 *)((int)register0x00000038 + -0x3c) = *(undefined2 *)(piVar17 + 0xd);
        }
        if (*(sword *)((int)piVar17 + 0x36) < sVar7) {
          *(undefined2 *)((int)register0x00000038 + -0x3a) = *(undefined2 *)((int)piVar17 + 0x36);
        }
        if (sVar4 < *(sword *)(piVar17 + 0xc)) {
          *(undefined2 *)((int)register0x00000038 + -0x40) = *(undefined2 *)(piVar17 + 0xc);
        }
        uVar15 = *(undefined2 *)((int)register0x00000038 + -0x40);
        if (*(sword *)((int)piVar17 + 0x32) < sVar5) {
          *(undefined2 *)((int)register0x00000038 + -0x3e) = *(undefined2 *)((int)piVar17 + 0x32);
          uVar15 = *(undefined2 *)((int)register0x00000038 + -0x40);
        }
        *(undefined2 *)(piVar17 + 3) = uVar15;
        *(undefined2 *)((int)piVar17 + 0xe) = *(undefined2 *)((int)register0x00000038 + -0x3e);
        *(undefined2 *)(piVar17 + 4) = *(undefined2 *)((int)register0x00000038 + -0x3c);
        *(undefined2 *)((int)piVar17 + 0x12) = *(undefined2 *)((int)register0x00000038 + -0x3a);
        param_2 = *(int *)(iVar9 + 8);
        iVar11 = param_2;
        umul(param_2,(int)*(sword *)((int)register0x00000038 + -0x3c) -
                     (int)*(sword *)(piVar17 + 0xd));
        puVar27 = (uint *)(piVar17 + 0x412);
        iVar16 = (int)*(sword *)((int)register0x00000038 + -0x40);
        puVar23 = (uint *)(*(int *)(iVar9 + 0x14) + iVar11 * 4 +
                          (iVar16 - *(sword *)(piVar17 + 0xc)) * 4);
        iVar11 = (int)*(sword *)((int)register0x00000038 + -0x3c);
        iVar12 = *(sword *)((int)register0x00000038 + -0x3e) - iVar16;
        param_2 = param_2 - iVar12;
        puVar25 = (uint *)(piVar17 +
                          *piVar17 * 0x100 +
                          (iVar11 - *(sword *)(piVar17 + 9)) * 0x10 +
                          (iVar16 - *(sword *)(piVar17 + 8)) + 0x12);
        if ((*(char *)(iVar9 + 0x20) == 'A') || (*(char *)(iVar9 + 0x20) == '-')) {
          iVar16 = (*(sword *)((int)register0x00000038 + -0x3a) - iVar11) + -1;
          iVar11 = *(int *)((int)register0x00000038 + -0x6c);
          iVar9 = iVar12;
          if (iVar16 != -1) {
            do {
              while (iVar9 + -1 != -1) {
                uVar13 = *puVar23;
                *puVar27 = uVar13;
                uVar31 = *puVar25;
                puVar27 = puVar27 + 1;
                uVar22 = uVar31 >> 0x18;
                puVar25 = puVar25 + 1;
                if (uVar22 != 0) {
                  if (uVar22 == 0xff) {
                    *puVar23 = uVar31;
                  }
                  else {
                    uVar13 = uVar13 << 8;
                    uVar14 = (uVar13 & 0xff00ff00) >> 8;
                    umul(uVar14,uVar22 ^ 0xff);
                    uVar13 = uVar13 & 0xff00ff;
                    umul(uVar13,uVar22 ^ 0xff);
                    *puVar23 = uVar31 * 0x100 +
                               (uVar14 + 0xff00ff & 0xff00ff00 | uVar13 + 0xff00ff >> 8 & 0xff00ff)
                               >> 8 | 0xff000000;
                  }
                }
                puVar23 = puVar23 + 1;
                iVar9 = iVar9 + -1;
              }
              puVar25 = puVar25 + (0x10 - iVar12);
              iVar16 = iVar16 + -1;
              puVar23 = puVar23 + param_2;
              iVar9 = iVar12;
            } while (iVar16 != -1);
            iVar11 = *(int *)((int)register0x00000038 + -0x6c);
          }
        }
        else {
          iVar16 = (*(sword *)((int)register0x00000038 + -0x3a) - iVar11) + -1;
          iVar11 = *(int *)((int)register0x00000038 + -0x6c);
          iVar9 = iVar12;
          if (iVar16 != -1) {
            do {
              while (iVar9 + -1 != -1) {
                uVar22 = *puVar23;
                *puVar27 = uVar22;
                uVar31 = *puVar25;
                puVar27 = puVar27 + 1;
                uVar13 = uVar31 & 0xff;
                puVar25 = puVar25 + 1;
                if (uVar13 != 0) {
                  if (uVar13 == 0xff) {
                    *puVar23 = uVar31;
                  }
                  else {
                    uVar14 = (uVar22 & 0xff00ff00) >> 8;
                    umul(uVar14,uVar13 ^ 0xff);
                    uVar22 = uVar22 & 0xff00ff;
                    umul(uVar22,uVar13 ^ 0xff);
                    *puVar23 = uVar31 + (uVar14 + 0xff00ff & 0xff00ff00 |
                                        uVar22 + 0xff00ff >> 8 & 0xff00ff);
                  }
                }
                puVar23 = puVar23 + 1;
                iVar9 = iVar9 + -1;
              }
              puVar25 = puVar25 + (0x10 - iVar12);
              iVar16 = iVar16 + -1;
              puVar23 = puVar23 + param_2;
              iVar9 = iVar12;
            } while (iVar16 != -1);
            goto loc_F00E80EC;
          }
        }
      }
      else {
        iVar11 = *(int *)((int)register0x00000038 + -0x6c);
      }
      *(undefined2 *)(iVar11 + 0x28) = *(undefined2 *)(iVar11 + 0x20);
      *(undefined2 *)(iVar11 + 0x2a) = *(undefined2 *)(iVar11 + 0x22);
      *(undefined2 *)(iVar11 + 0x2c) = *(undefined2 *)(iVar11 + 0x24);
      *(undefined2 *)(iVar11 + 0x2e) = *(undefined2 *)(iVar11 + 0x26);
      iVar11 = *(int *)((int)register0x00000038 + -0x4c);
    }
  }
  _ev_unlock(iVar11 + 4);
loc_F00E811C:
  return CONCAT44(param_2,*(undefined4 *)((int)register0x00000038 + -0x44));
}

