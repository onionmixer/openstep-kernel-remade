
/* WARNING: Removing unreachable block (ram,0xf00b5850) */
/* WARNING: Removing unreachable block (ram,0xf00b5748) */
/* WARNING: Removing unreachable block (ram,0xf00b572c) */
/* WARNING: Removing unreachable block (ram,0xf00b575c) */
/* WARNING: Removing unreachable block (ram,0xf00b56bc) */
/* WARNING: Removing unreachable block (ram,0xf00b5720) */

undefined8 _esp_handle_data(int param_1,undefined4 param_2)

{
  word wVar1;
  undefined2 uVar2;
  undefined uVar3;
  uint uVar4;
  uint uVar5;
  uint *puVar6;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  uint *puVar7;
  undefined *puVar8;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  uint uVar9;
  undefined4 uVar10;
  undefined4 unaff_i1;
  undefined4 unaff_i2;
  undefined4 unaff_i3;
  undefined4 unaff_i4;
  undefined4 unaff_i5;
  undefined4 unaff_fp;
  undefined4 unaff_i7;
  bool bVar11;
  bool in_DECOMPILE_MODE;
  int in_CWP;
  
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
  puVar8 = *(undefined **)(param_1 + 0x9c);
  puVar7 = *(uint **)(param_1 + 0xa0);
  uVar9 = *(uint *)(*(sword *)(param_1 + 0xb2) * 4 + param_1 + 0xb8);
  if (*(char *)(param_1 + 0x31) == '\0') {
    puVar8[0xc] = 0;
  }
  wVar1 = *(word *)(uVar9 + 0x5c);
  if ((wVar1 & 1) == 0) {
    _esp_printstate(param_1,aUnexpectedData);
    uVar3 = 3;
loc_F00B585C:
    *(undefined *)(uVar9 + 0x28) = uVar3;
    uVar10 = 6;
  }
  else {
    if ((wVar1 & 0x1000) != 0) {
      puVar6 = *(uint **)(uVar9 + 0x54);
      uVar5 = *(uint *)(uVar9 + 0x34);
      uVar4 = *puVar6;
      if ((uVar5 < uVar4) || (uVar4 + puVar6[1] <= uVar5)) {
        _panic(aNeedNewSegInEs);
      }
      else {
        puVar6[1] = uVar5 - uVar4;
        *(word *)(uVar9 + 0x5c) = *(word *)(uVar9 + 0x5c) ^ 0x1000;
      }
    }
    uVar4 = uVar9;
    _scsi_chkdma(uVar9,0x10000);
    if (uVar4 == 0) {
      _esp_printstate(param_1,aDataTransferOv);
      *(undefined *)(uVar9 + 0x28) = 7;
      _esp_sync_backoff(param_1,uVar9);
      uVar10 = 6;
      goto locret_F00B589C;
    }
    *(uint *)(param_1 + 0xa8) = uVar4;
    if ((*(word *)(uVar9 + 0x5c) & 4) == 0) {
      uVar5 = *(uint *)(uVar9 + 0x34);
      if (uVar5 >> 0xc < 0x600) {
        uVar5 = uVar5 | 0xff000000;
      }
      *(uint *)(param_1 + 0xa4) = uVar5;
      puVar7[1] = uVar5;
    }
    else {
      uVar5 = *(uint *)(uVar9 + 0x34);
      if (uVar5 >> 0xc < _dvmasize) {
        uVar5 = uVar5 | *(uint *)(param_1 + 0xac);
        *(uint *)(param_1 + 0xa4) = uVar5;
      }
      else {
        *(uint *)(param_1 + 0xa4) = uVar5;
      }
      puVar7[1] = uVar5;
    }
    uVar3 = (undefined)(uVar4 >> 8);
    if ((*(byte *)(param_1 + 0x33) & 0x40) == 0) {
      *puVar8 = (char)uVar4;
      puVar8[4] = uVar3;
    }
    else {
      *puVar8 = (char)uVar4;
      puVar8[4] = uVar3;
      puVar8[0x38] = (char)(uVar4 >> 0x10);
    }
    if (*puVar7 >> 0x1c == 4) {
      puVar7[2] = uVar4;
    }
    bVar11 = (wVar1 >> 1 & 1) == 0;
    if ((*(byte *)(param_1 + 0x43) & 7) == 0) {
      if (bVar11) {
        uVar2 = *(undefined2 *)(uVar9 + 8);
        puVar8 = aUnwantedDataOu;
loc_F00B5850:
        _esplog(param_1,3,puVar8,uVar2);
        uVar3 = 2;
        goto loc_F00B585C;
      }
      uVar9 = *puVar7;
    }
    else {
      if (!bVar11) {
        uVar2 = *(undefined2 *)(uVar9 + 8);
        puVar8 = aUnwantedDataIn;
        goto loc_F00B5850;
      }
      *puVar7 = *puVar7 | 0x100;
      uVar9 = *puVar7;
    }
    *puVar7 = uVar9 | 0x210;
    puVar8[0xc] = 0x90;
    uVar10 = 0xffffffff;
    *(undefined *)(param_1 + 0x42) = *(undefined *)(param_1 + 0x41);
    *(undefined *)(param_1 + 0x41) = 10;
  }
locret_F00B589C:
  return CONCAT44(param_2,uVar10);
}

