
/* WARNING: Removing unreachable block (ram,0xf00b59e8) */
/* WARNING: Removing unreachable block (ram,0xf00b5918) */
/* WARNING: Removing unreachable block (ram,0xf00b59ac) */
/* WARNING: Removing unreachable block (ram,0xf00b5b68) */
/* WARNING: Removing unreachable block (ram,0xf00b5950) */

qword _esp_handle_data_done(int param_1)

{
  byte bVar1;
  word wVar2;
  int iVar3;
  uint uVar4;
  undefined8 *puVar5;
  undefined *puVar6;
  undefined4 unaff_l0;
  uint *puVar7;
  undefined4 unaff_l1;
  undefined *puVar8;
  undefined4 unaff_l3;
  int iVar9;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  byte bVar10;
  undefined4 unaff_l6;
  byte bVar11;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 uVar12;
  uint uVar13;
  int iVar14;
  undefined4 unaff_i1;
  undefined4 unaff_i2;
  undefined4 unaff_i3;
  undefined4 unaff_i4;
  undefined4 unaff_i5;
  undefined4 unaff_fp;
  undefined4 unaff_i7;
  bool bVar15;
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
  bVar10 = *(byte *)(param_1 + 0x43);
  puVar7 = *(uint **)(param_1 + 0xa0);
  puVar8 = *(undefined **)(param_1 + 0x9c);
  iVar9 = *(int *)(*(sword *)(param_1 + 0xb2) * 4 + param_1 + 0xb8);
  bVar11 = 0;
  bVar1 = *(byte *)(iVar9 + 9);
  wVar2 = *(word *)(iVar9 + 0x5c) >> 1;
  if ((*puVar7 & 2) != 0) {
    if ((wVar2 & 1) == 0) {
      puVar5 = &aReceive;
    }
    else {
      puVar5 = (undefined8 *)&aSend;
    }
    _esplog(param_1,3,aUnrecoverableD_0,puVar5);
    *(undefined *)(iVar9 + 0x28) = 3;
    uVar12 = 8;
    goto locret_F00B5C20;
  }
  if ((wVar2 & 1) == 0) {
    if ((bVar10 & 0x20) != 0) {
      _esplog(param_1,3,aScsiBusDataInP);
      *(undefined *)(param_1 + 0x4c) = 5;
      *(undefined *)(param_1 + 0x53) = 1;
      *(byte *)(iVar9 + 0x2a) = *(byte *)(iVar9 + 0x2a) | 4;
    }
    uVar4 = *puVar7;
    for (uVar13 = 0; ((uVar4 & 0xc) != 0 && (uVar13 < 100)); uVar13 = uVar13 + 1) {
      if (uVar4 >> 0x1c != 4) {
        *puVar7 = uVar4 | 0x40;
      }
      _us_spin(200);
      uVar4 = *puVar7;
    }
    if ((99 < uVar13) && ((*puVar7 & 0xc) != 0)) {
      _esplog(param_1,3,aDmaGateArrayWo);
      *(undefined *)(iVar9 + 0x28) = 3;
      uVar12 = 6;
      goto locret_F00B5C20;
    }
  }
  *puVar7 = *puVar7 & 0xffffdcff | 0x20;
  uVar12 = 2;
  if (*(char *)(param_1 + 0x44) != '\x10') {
    *(undefined *)(param_1 + 0x42) = *(undefined *)(param_1 + 0x41);
    *(undefined *)(param_1 + 0x41) = 0x1a;
    goto locret_F00B5C20;
  }
  if ((bVar10 & 0x10) == 0) {
    if ((*(byte *)(param_1 + 0x33) & 0x40) == 0) {
      uVar4 = (uint)CONCAT11(puVar8[4],*puVar8);
    }
    else {
      uVar4 = (uint)CONCAT12(puVar8[0x38],CONCAT11(puVar8[4],*puVar8));
    }
    iVar14 = *(int *)(param_1 + 0xa8) - uVar4;
  }
  else {
    iVar14 = *(int *)(param_1 + 0xa8);
  }
  if ((wVar2 & 1) != 0) {
    iVar14 = iVar14 - ((byte)puVar8[0x1c] & 0x1f);
  }
  if (*(char *)((uint)bVar1 + param_1 + 0x5e) == '\0') {
loc_F00B5BAC:
    bVar15 = false;
  }
  else {
    *(byte *)(iVar9 + 0x2a) = *(byte *)(iVar9 + 0x2a) | 2;
    *(int *)(param_1 + 0x98) = *(int *)(param_1 + 0x98) + 1;
    if (*(char *)(param_1 + 0x31) == '\0') {
      bVar10 = puVar8[0x10];
      *(byte *)(param_1 + 0x43) = bVar10;
      if ((bVar10 & 7) == 1) {
        if ((puVar8[0x1c] & 0x1f) == 0) {
          bVar11 = 1;
loc_F00B5B20:
          iVar3 = (uint)bVar11 << 0x18;
        }
        else {
          iVar3 = 0;
        }
      }
      else {
        iVar3 = 0;
        if ((bVar10 & 7) == 0) {
          if ((puVar8[0x1c] & 0x20) == 0) {
            bVar11 = 0xff;
          }
          goto loc_F00B5B20;
        }
      }
      if (iVar3 >> 0x18 != 0) {
        puVar8[0xc] = 0x12;
        if (iVar3 >> 0x18 < 0) {
          puVar6 = aDataOut;
        }
        else {
          puVar6 = (undefined *)&aDataIn;
        }
        _esplog(param_1,3,off_F011E724,puVar6,(uint)bVar1);
        *(byte *)(param_1 + 0x78) = *(byte *)(param_1 + 0x78) & ~(byte)(1 << (bVar1 & 0x1f));
      }
      bVar15 = true;
      if (bVar11 == 0) goto loc_F00B5BA0;
    }
    else {
loc_F00B5BA0:
      bVar15 = true;
      if ((wVar2 & 1) != 0) goto loc_F00B5BAC;
    }
  }
  if (!bVar15) {
    puVar8[0xc] = 1;
  }
  *(int *)(iVar9 + 0x34) = *(int *)(iVar9 + 0x34) + iVar14;
  *(int *)(*(int *)(iVar9 + 0x54) + 4) = *(int *)(*(int *)(iVar9 + 0x54) + 4) + iVar14;
  *(byte *)(iVar9 + 0x29) = *(byte *)(iVar9 + 0x29) | 8;
  *(undefined *)(param_1 + 0x42) = *(undefined *)(param_1 + 0x41);
  *(undefined *)(param_1 + 0x41) = 0x1a;
  if (bVar11 == 0) {
    if ((bVar10 & 7) < 2) {
      *(undefined *)(param_1 + 0x41) = 9;
    }
    uVar12 = 2;
  }
  else {
    uVar12 = 0xffffffff;
  }
locret_F00B5C20:
  return (qword)CONCAT14(bVar1,uVar12);
}
