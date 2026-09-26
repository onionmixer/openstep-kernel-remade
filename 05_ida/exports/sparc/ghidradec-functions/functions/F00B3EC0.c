
/* WARNING: Removing unreachable block (ram,0xf00b40b8) */
/* WARNING: Removing unreachable block (ram,0xf00b4004) */
/* WARNING: Removing unreachable block (ram,0xf00b3f0c) */
/* WARNING: Removing unreachable block (ram,0xf00b3fa8) */
/* WARNING: Removing unreachable block (ram,0xf00b400c) */
/* WARNING: Removing unreachable block (ram,0xf00b40c0) */
/* WARNING: Removing unreachable block (ram,0xf00b3ed8) */

undefined8 _esp_abort(undefined4 *param_1,undefined *param_2)

{
  char cVar1;
  undefined4 uVar2;
  int iVar3;
  undefined *puVar4;
  undefined *puVar5;
  undefined4 unaff_l0;
  undefined4 *puVar6;
  undefined4 unaff_l1;
  word wVar7;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 uVar8;
  undefined4 unaff_i1;
  undefined4 unaff_i2;
  undefined4 unaff_i3;
  undefined4 unaff_i4;
  undefined4 unaff_i5;
  undefined4 unaff_fp;
  undefined4 unaff_i7;
  bool bVar9;
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
  puVar6 = (undefined4 *)*param_1;
  uVar2 = *puVar6;
  wVar7 = (word)*(byte *)((int)param_1 + 6) | *(sword *)(param_1 + 1) << 3;
  _splr(uVar2);
  if ((*(char *)((int)puVar6 + 0x41) != '\0') && (*(word *)((int)puVar6 + 0xb2) == wVar7)) {
    _splx(uVar2);
    uVar8 = 0;
    puVar4 = param_2;
    goto locret_F00B40C8;
  }
  if (param_2 == (undefined *)0x0) {
    param_2 = *(undefined **)((int)puVar6 + ((int)((uint)wVar7 << 0x10) >> 0xe) + 0xb8);
  }
  iVar3 = (int)((uint)wVar7 << 0x10) >> 0xe;
  puVar4 = *(undefined **)((int)puVar6 + iVar3 + 0xb8);
  if (puVar4 == (undefined *)0x0) {
    param_2 = (undefined *)0x0;
  }
  if (param_2 == (undefined *)0x0) {
loc_F00B3F9C:
    bVar9 = param_2 == (undefined *)0x0;
  }
  else {
    bVar9 = param_2 == (undefined *)0x0;
    if ((param_2 == puVar4) && (bVar9 = param_2 == (undefined *)0x0, param_2[0x29] == '\0')) {
      *(undefined4 *)((int)puVar6 + iVar3 + 0xb8) = 0;
      param_2[0x28] = 5;
      puVar6[0x21] = puVar6[0x21] + -1;
      (**(code **)(param_2 + 0x10))(param_2);
      param_2 = (undefined *)0x0;
      goto loc_F00B3F9C;
    }
  }
  if (bVar9) {
    _splx(uVar2);
    uVar8 = 1;
    puVar4 = param_2;
    goto locret_F00B40C8;
  }
  *(undefined4 *)((int)puVar6 + ((int)((uint)wVar7 << 0x10) >> 0xe) + 0xb8) = 0;
  bVar9 = (*(word *)(param_2 + 0x5c) & 0x10) != 0;
  if (bVar9) {
    puVar6[0x22] = puVar6[0x22] + -1;
  }
  puVar4 = (undefined *)((int)register0x00000038 + -0x78);
  puVar6[0x21] = puVar6[0x21] + -1;
  _esp_makeproxy_cmd(puVar4,param_1,6);
  puVar5 = puVar4;
  _esp_start();
  if (puVar5 == (undefined *)0x1) {
    if (*(char *)((int)register0x00000038 + -0x50) != '\0') {
      iVar3 = puVar6[0x21];
      goto loc_F00B4060;
    }
    if (*(char *)((int)register0x00000038 + -0xd) != '\x01') {
      iVar3 = puVar6[0x21];
      goto loc_F00B4060;
    }
    uVar8 = 1;
    param_2[0x28] = 5;
    (**(code **)(param_2 + 0x10))(param_2);
    cVar1 = *(char *)((int)puVar6 + 0x41);
  }
  else {
    iVar3 = puVar6[0x21];
loc_F00B4060:
    puVar6[0x21] = iVar3 + 1;
    if (bVar9) {
      puVar6[0x22] = puVar6[0x22] + 1;
      *(word *)(param_2 + 0x5c) = *(word *)(param_2 + 0x5c) | 0x10;
    }
    *(undefined **)((int)puVar6 + ((int)((uint)wVar7 << 0x10) >> 0xe) + 0xb8) = param_2;
    uVar8 = 0;
    cVar1 = *(char *)((int)puVar6 + 0x41);
  }
  if (cVar1 == '\0') {
    _esp_ustart(puVar6,(int)(sword)wVar7 + 1U & 0x3f);
  }
  _splx(uVar2);
locret_F00B40C8:
  return CONCAT44(puVar4,uVar8);
}

