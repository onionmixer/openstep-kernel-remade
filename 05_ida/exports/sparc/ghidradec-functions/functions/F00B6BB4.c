
/* WARNING: Removing unreachable block (ram,0xf00b6eec) */
/* WARNING: Removing unreachable block (ram,0xf00b6e20) */
/* WARNING: Removing unreachable block (ram,0xf00b6de4) */
/* WARNING: Removing unreachable block (ram,0xf00b6dc4) */
/* WARNING: Removing unreachable block (ram,0xf00b6dec) */
/* WARNING: Removing unreachable block (ram,0xf00b6e80) */
/* WARNING: Removing unreachable block (ram,0xf00b706c) */
/* WARNING: Removing unreachable block (ram,0xf00b6d78) */

undefined8 _esp_reconnect(int param_1,undefined4 param_2)

{
  char cVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  int iVar7;
  byte bVar8;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined *puVar9;
  undefined4 unaff_l3;
  int iVar10;
  undefined4 unaff_l4;
  int iVar11;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 uVar12;
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
  iVar10 = *(int *)(param_1 + 0x9c);
  *(undefined *)(param_1 + 0x42) = *(undefined *)(param_1 + 0x41);
  *(undefined *)(param_1 + 0x41) = 0x1b;
  uVar2 = 1 << (*(byte *)(param_1 + 0x32) & 7);
  if (((*(byte *)(iVar10 + 0x1c) & 0x1f) == 2) &&
     (uVar6 = *(byte *)(iVar10 + 8) ^ uVar2, (*(byte *)(iVar10 + 8) & uVar2) != 0)) {
    uVar3 = uVar6 & 0xff;
    iVar11 = 0;
    uVar2 = uVar3;
    if (uVar3 != 0) {
      do {
        if ((uVar2 & 1) != 0) {
          uVar6 = uVar6 ^ 1 << ((byte)iVar11 & 0x1f);
          break;
        }
        iVar11 = iVar11 + 1;
        uVar2 = (int)uVar3 >> ((byte)iVar11 & 0x1f);
      } while (iVar11 < 8);
      if (((uVar6 & 0xff) == 0) && ((*(byte *)(param_1 + 0x43) & 7) == 7)) {
        uVar2 = (uint)*(byte *)(iVar10 + 8);
        *(byte *)(param_1 + 0x54) = *(byte *)(iVar10 + 8);
        if ((*(byte *)(param_1 + 0x43) & 0x20) != 0) {
          uVar2 = 0x80;
        }
        if ((uVar2 & 0xd8) == 0x80) {
          uVar2 = uVar2 & 7;
          if ((*(byte *)(iVar10 + 0x1c) & 0x1f) != 0) {
            do {
            } while ((*(byte *)(iVar10 + 0x1c) & 0x1f) != 0);
          }
          *(undefined *)(iVar10 + 0xc) = 0;
          iVar7 = param_1 + iVar11;
          *(byte *)(iVar10 + 0x18) = *(byte *)(iVar7 + 0x66) & 0x1f;
          *(byte *)(iVar10 + 0x1c) = *(byte *)(iVar7 + 0x5e) | *(byte *)(param_1 + 0x77);
          if ((byte)(*(char *)(param_1 + 0x31) - 3U) < 2) {
            *(undefined *)(iVar10 + 0x30) = *(undefined *)(iVar7 + 0x34);
          }
          uVar3 = iVar11 << 3 | uVar2;
          iVar7 = (int)(sword)uVar3;
          uVar6 = *(uint *)(iVar7 * 4 + param_1 + 0xb8);
          if ((*(byte *)(param_1 + 0x43) & 0x20) != 0) {
            bVar8 = 0;
            uVar2 = 0;
            iVar5 = iVar7;
            do {
              uVar4 = *(uint *)(iVar5 * 4 + param_1 + 0xb8);
              if ((uVar4 != 0) && (bVar8 = bVar8 + 1, uVar6 == 0)) {
                uVar6 = uVar4;
              }
              uVar2 = uVar2 + 1;
              iVar5 = iVar7 + uVar2;
            } while ((int)uVar2 < 8);
            if (bVar8 == 1) {
              uVar2 = (uint)*(byte *)(uVar6 + 10);
              uVar3 = uVar3 + uVar2;
            }
            else if (1 < bVar8) {
              _esplog(param_1,3,off_F011EA4C);
              goto loc_F00B7068;
            }
          }
          if ((uVar6 == 0) || ((*(word *)(uVar6 + 0x5c) & 0x110) == 0)) {
            uVar6 = uVar6 & -(uint)(uVar6 != 0);
            puVar9 = (undefined *)((int)register0x00000038 + -0x80);
            iVar7 = param_1;
            _scsi_cookie();
            *(int *)((int)register0x00000038 + -0x10) = iVar7;
            *(sword *)((int)register0x00000038 + -0xc) = (sword)iVar11;
            *(char *)((int)register0x00000038 + -10) = (char)uVar2;
            *(undefined *)((int)register0x00000038 + -9) = 0;
            _esp_makeproxy_cmd(puVar9,(undefined *)((int)register0x00000038 + -0x10),6);
            _esp_init_cmd(puVar9);
            *(int *)(param_1 + 0x80) = *(int *)(param_1 + 0x80) + 1;
            *(int *)(param_1 + 0x84) = *(int *)(param_1 + 0x84) + 1;
            _esplog(param_1,4,aNoCommandForRe,iVar11,uVar2);
            *(undefined *)(param_1 + 0x4c) = 6;
            *(undefined *)(param_1 + 0x53) = 1;
            *(undefined *)(iVar10 + 0xc) = 0x12;
            *(sword *)(param_1 + 0xb2) = (sword)uVar3;
            iVar7 = ((int)(uVar3 << 0x10) >> 0xe) + param_1;
            *(undefined **)(iVar7 + 0xb8) = puVar9;
            iVar10 = *(int *)(param_1 + 0x80);
            *(undefined *)(param_1 + 0x42) = *(undefined *)(param_1 + 0x41);
            *(undefined *)(param_1 + 0x41) = 0x1a;
            while (iVar10 != 0) {
              iVar10 = param_1;
              _esp_dopoll(param_1,180000000);
              if (iVar10 != 0) {
                if (*(undefined **)(iVar7 + 0xb8) != puVar9) {
                  uVar12 = 8;
                  goto locret_F00B7078;
                }
                *(undefined4 *)(iVar7 + 0xb8) = 0;
                goto loc_F00B7074;
              }
              iVar10 = *(int *)(param_1 + 0x80);
            }
            if (*(char *)((int)register0x00000038 + -0x58) == '\0') {
              puVar9 = aSucceeded;
            }
            else {
              puVar9 = (undefined *)&aFailed;
            }
            _esplog(param_1,6,aProxyAbortSFor,puVar9,iVar11,uVar2);
            iVar10 = (int)(uVar3 << 0x10) >> 0xe;
            if (uVar6 == 0) {
              iVar10 = iVar10 + param_1;
              if (*(undefined **)(iVar10 + 0xb8) == (undefined *)((int)register0x00000038 + -0x80))
              {
                *(undefined4 *)(iVar10 + 0xb8) = 0;
              }
            }
            else {
              *(uint *)(iVar10 + param_1 + 0xb8) = uVar6;
            }
            uVar12 = 8;
            if ((*(char *)((int)register0x00000038 + -0x58) == '\0') &&
               (*(char *)((int)register0x00000038 + -0x15) == '\x01')) {
              uVar12 = 5;
            }
          }
          else {
            bVar8 = 0;
            if ((*(word *)(uVar6 + 0x5c) & 0x100) == 0) {
              if ((_scsi_options & 0x40) != 0) {
                if ((*(uint *)(uVar6 + 0x14) & 8) == 0) {
                  if ((*(byte *)(param_1 + 0x43) & 0x20) != 0) {
                    *(undefined *)(param_1 + 0x4c) = 9;
                    *(undefined *)(param_1 + 0x53) = 1;
                  }
                }
                else {
                  *(byte *)(iVar10 + 0x20) = *(byte *)(param_1 + 0x32) & 0xef;
                }
              }
            }
            else {
              *(int *)(param_1 + 0x88) = *(int *)(param_1 + 0x88) + 1;
              *(undefined *)(iVar10 + 0xc) = 0x1a;
              cVar1 = *(char *)(uVar6 + 0x6c);
              *(char *)(param_1 + 0x53) = cVar1;
              if (cVar1 != '\0') {
                uVar2 = 0;
                do {
                  bVar8 = bVar8 + 1;
                  *(undefined *)(param_1 + uVar2 + 0x4c) = *(undefined *)(uVar6 + uVar2 + 0x6d);
                  uVar2 = (uint)bVar8;
                } while (bVar8 < *(byte *)(param_1 + 0x53));
              }
              *(undefined *)(uVar6 + 0x6b) = 0;
            }
            *(undefined *)(iVar10 + 0xc) = 0x12;
            *(sword *)(param_1 + 0xb2) = (sword)uVar3;
            if (*(int *)(param_1 + 0x88) != 0) {
              *(int *)(param_1 + 0x88) = *(int *)(param_1 + 0x88) + -1;
            }
            uVar12 = 0xffffffff;
            *(undefined *)(param_1 + 0x42) = *(undefined *)(param_1 + 0x41);
            *(undefined *)(param_1 + 0x41) = 0x1a;
            *(word *)(uVar6 + 0x5c) = *(word *)(uVar6 + 0x5c) & 0xffef;
            *(undefined4 *)(uVar6 + 0x2c) = *(undefined4 *)(uVar6 + 0x20);
            *(undefined4 *)(uVar6 + 0x30) = *(undefined4 *)(uVar6 + 0x1c);
            *(undefined4 *)(uVar6 + 0x34) = *(undefined4 *)(uVar6 + 0x38);
            *(undefined *)(param_1 + 0x46) = 0;
          }
          goto locret_F00B7078;
        }
      }
    }
  }
loc_F00B7068:
  _esp_printstate(param_1,aFailedReselect);
loc_F00B7074:
  uVar12 = 8;
locret_F00B7078:
  return CONCAT44(param_2,uVar12);
}
