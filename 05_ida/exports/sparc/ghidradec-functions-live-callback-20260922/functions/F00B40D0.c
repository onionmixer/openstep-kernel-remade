
/* WARNING: Removing unreachable block (ram,0xf00b4200) */
/* WARNING: Removing unreachable block (ram,0xf00b410c) */
/* WARNING: Removing unreachable block (ram,0xf00b4198) */
/* WARNING: Removing unreachable block (ram,0xf00b4190) */
/* WARNING: Removing unreachable block (ram,0xf00b40f0) */
/* WARNING: Removing unreachable block (ram,0xf00b4128) */
/* WARNING: Removing unreachable block (ram,0xf00b4208) */
/* WARNING: Removing unreachable block (ram,0xf00b40dc) */

undefined8 _esp_reset(undefined4 *param_1,int param_2)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  uint uVar3;
  int iVar4;
  char cVar5;
  undefined4 unaff_l0;
  undefined *puVar6;
  undefined4 unaff_l1;
  undefined4 *puVar7;
  undefined4 uVar8;
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
  puVar7 = (undefined4 *)*param_1;
  uVar1 = *puVar7;
  uVar8 = 0;
  _splr(uVar1);
  if (param_2 == 0) {
    _esp_reset_bus(puVar7);
    puVar7[0x20] = puVar7[0x20] + 1;
    puVar2 = puVar7;
    _esp_dopoll(puVar7,180000000);
    uVar3 = 0;
    if (puVar2 != (undefined4 *)0x0) {
      _esplog(puVar7,3,aResetScsiBusFa);
      cVar5 = *(char *)((int)puVar7 + 0x41);
      goto loc_F00B41F4;
    }
loc_F00B41CC:
    uVar8 = 1;
  }
  else {
    uVar3 = (uint)*(byte *)((int)param_1 + 6) | (uint)*(word *)(param_1 + 1) << 3;
    if (*(char *)((int)puVar7 + 0x41) == '\0') {
      if (*(int *)((int)puVar7 + ((int)(uVar3 << 0x10) >> 0xe) + 0xb8) != 0) {
        cVar5 = *(char *)((int)puVar7 + 0x41);
        goto loc_F00B41F4;
      }
      if (puVar7[0x20] != 0) {
        cVar5 = *(char *)((int)puVar7 + 0x41);
        goto loc_F00B41F4;
      }
      puVar6 = (undefined *)((int)register0x00000038 + -0x78);
      _esp_makeproxy_cmd(puVar6,param_1,0xc);
      _esp_start();
      if (((puVar6 == (undefined *)0x1) && (*(char *)((int)register0x00000038 + -0x50) == '\0')) &&
         (*(char *)((int)register0x00000038 + -0xd) == '\x01')) goto loc_F00B41CC;
      iVar4 = (int)(uVar3 << 0x10) >> 0xe;
      if (*(undefined **)((int)puVar7 + iVar4 + 0xb8) ==
          (undefined *)((int)register0x00000038 + -0x78)) {
        *(undefined4 *)((int)puVar7 + iVar4 + 0xb8) = 0;
      }
    }
  }
  cVar5 = *(char *)((int)puVar7 + 0x41);
loc_F00B41F4:
  if (cVar5 == '\0') {
    _esp_ustart(puVar7,0);
  }
  _splx(uVar1);
  return CONCAT44(uVar3,uVar8);
}

