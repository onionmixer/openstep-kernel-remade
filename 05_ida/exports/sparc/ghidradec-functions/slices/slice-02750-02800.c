/* GHIDRADEC_FUNCTION index=2750 start=0xf00b7e30 */

/* WARNING: Removing unreachable block (ram,0xf00b7ef0) */
/* WARNING: Removing unreachable block (ram,0xf00b7ebc) */
/* WARNING: Removing unreachable block (ram,0xf00b7e78) */
/* WARNING: Removing unreachable block (ram,0xf00b7e50) */
/* WARNING: Removing unreachable block (ram,0xf00b7eac) */
/* WARNING: Removing unreachable block (ram,0xf00b7edc) */
/* WARNING: Removing unreachable block (ram,0xf00b7ef8) */
/* WARNING: Removing unreachable block (ram,0xf00b7e44) */

undefined8 _esp_dump_cmd(int param_1,undefined4 param_2)

{
  byte bVar1;
  undefined uVar2;
  undefined4 unaff_l0;
  int iVar3;
  undefined4 unaff_l1;
  undefined *puVar4;
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
  puVar4 = *(undefined **)(param_1 + 0x20);
  _printf(aCmdDumpForTarg,*(undefined2 *)(param_1 + 8),*(undefined *)(param_1 + 10));
  _printf(&aCdb);
  iVar3 = 0;
  if (*(char *)(param_1 + 99) == '\0') {
    bVar1 = *(byte *)(param_1 + 0x29);
  }
  else {
    do {
      iVar3 = iVar3 + 1;
      _printf(&a0xX_0,*puVar4);
      puVar4 = puVar4 + 1;
    } while (iVar3 < (int)(uint)*(byte *)(param_1 + 99));
    bVar1 = *(byte *)(param_1 + 0x29);
  }
  if ((bVar1 & 0x10) == 0) {
    _printf(&DAT_f011edd0);
    uVar2 = *(undefined *)(param_1 + 0x29);
  }
  else {
    _printf(aStatus0xX,(int)**(char **)(param_1 + 0x1c));
    uVar2 = *(undefined *)(param_1 + 0x29);
  }
  _printf(aPktState0xBPkt,uVar2,_state_bits,*(undefined4 *)(param_1 + 0x14),
          *(undefined *)(param_1 + 0x2a));
  _printf(aCmdFlags0xXCmd,*(undefined2 *)(param_1 + 0x5c),*(undefined4 *)(param_1 + 0x58));
  _esp_dump_datasegs(param_1);
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=2751 start=0xf00b7f08 */

/* WARNING: Removing unreachable block (ram,0xf00b7f4c) */
/* WARNING: Removing unreachable block (ram,0xf00b7f30) */
/* WARNING: Removing unreachable block (ram,0xf00b7f68) */
/* WARNING: Removing unreachable block (ram,0xf00b7f10) */

undefined8 _esp_dump_datasegs(int param_1,undefined4 param_2)

{
  undefined4 uVar1;
  undefined4 unaff_l0;
  undefined4 *puVar2;
  undefined4 unaff_l1;
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
  _printf(aMappedDmaSpace);
  puVar2 = (undefined4 *)(param_1 + 0x3c);
  if (puVar2 != (undefined4 *)0x0) {
    uVar1 = *puVar2;
    while( true ) {
      _printf(aBase0xXCount0x,uVar1,puVar2[1]);
      puVar2 = (undefined4 *)puVar2[2];
      if (puVar2 == (undefined4 *)0x0) break;
      uVar1 = *puVar2;
    }
  }
  _printf(aTransferHistor);
  puVar2 = (undefined4 *)(param_1 + 0x48);
  if (puVar2 != (undefined4 *)0x0) {
    uVar1 = *puVar2;
    while( true ) {
      _printf(aBase0xXCount0x_0,uVar1,puVar2[1]);
      puVar2 = (undefined4 *)puVar2[2];
      if (puVar2 == (undefined4 *)0x0) break;
      uVar1 = *puVar2;
    }
  }
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=2752 start=0xf00b7f88 */

undefined8 _esp_state_name(uint param_1)

{
  int *piVar1;
  uint uVar2;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined *puVar3;
  int iVar4;
  undefined4 unaff_i1;
  undefined4 unaff_i2;
  undefined4 unaff_i3;
  undefined4 unaff_i4;
  undefined4 unaff_i5;
  undefined4 unaff_fp;
  undefined4 unaff_i7;
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
  uVar2 = param_1 & 0xff;
  if (uVar2 == 0) {
    puVar3 = (undefined *)&aFree;
  }
  else if (((param_1 & 0xe0) == 0) || ((param_1 & 0xf) != 0)) {
    iVar4 = 0;
    if (DAT_f011eedc._0_4_ != 0) {
      param_1 = param_1 & 0xff;
      puVar3 = DAT_f011eedc;
      do {
        piVar1 = (int *)((int)puVar3 + 4);
        puVar3 = (undefined *)((int)puVar3 + 8);
        if ((int)*(char *)piVar1 == param_1) {
          puVar3 = *(undefined **)(DAT_f011eedc + iVar4);
          goto locret_F00B8054;
        }
        iVar4 = iVar4 + 8;
      } while (*(int *)puVar3 != 0);
    }
    puVar3 = (undefined *)&aBad;
  }
  else if (uVar2 == 0x20) {
    puVar3 = (undefined *)&aSelect;
  }
  else if (uVar2 == 0x40) {
    puVar3 = aSelStop;
  }
  else if (uVar2 == 0x60) {
    puVar3 = aSelectSndmsg;
  }
  else {
    puVar3 = aSelNoAtn;
  }
locret_F00B8054:
  return CONCAT44(param_1,puVar3);
}
/* GHIDRADEC_FUNCTION index=2753 start=0xf00b805c */

/* WARNING: Removing unreachable block (ram,0xf00b80dc) */
/* WARNING: Removing unreachable block (ram,0xf00b80e8) */
/* WARNING: Removing unreachable block (ram,0xf00b80a4) */

undefined8 _scsi_add_device(int *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  int iVar4;
  undefined4 unaff_i1;
  undefined4 unaff_i2;
  undefined4 unaff_i3;
  undefined4 unaff_i4;
  undefined4 unaff_i5;
  undefined4 unaff_fp;
  undefined4 unaff_i7;
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
  iVar4 = 0;
  iVar2 = 0;
  do {
    if (*param_1 == *(int *)(_scsibuscookies + iVar2)) break;
    iVar4 = iVar4 + 1;
    iVar2 = iVar2 + 4;
  } while (iVar4 < 0x10);
  if (iVar4 == 0x10) {
    uVar3 = 0;
  }
  else {
    uVar1 = _scsi_spl;
    _splr(_scsi_spl);
    uVar3 = *(undefined4 *)(_scsibuscookies + iVar4 * 4);
    sub_F00B8244(uVar3,*(undefined4 *)(_scsibusctlrs + iVar4 * 4),param_2,param_3,param_4,
                 *(undefined2 *)(param_1 + 1),*(undefined *)((int)param_1 + 6));
    _splx(uVar1);
  }
  return CONCAT44(param_2,uVar3);
}
/* GHIDRADEC_FUNCTION index=2754 start=0xf00b8100 */

undefined8 _scsa_config(undefined4 param_1,undefined4 param_2)

{
  undefined4 unaff_l0;
  undefined4 unaff_l1;
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
  _scsa_Transport = param_1;
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=2755 start=0xf00b8114 */

/* WARNING: Removing unreachable block (ram,0xf00b81d8) */
/* WARNING: Removing unreachable block (ram,0xf00b817c) */
/* WARNING: Removing unreachable block (ram,0xf00b820c) */
/* WARNING: Removing unreachable block (ram,0xf00b8130) */

undefined8 _scsi_config(int *param_1,int param_2)

{
  int iVar1;
  int *piVar2;
  uint uVar3;
  undefined4 unaff_l0;
  undefined *puVar4;
  undefined4 unaff_l1;
  int *piVar5;
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
  if (_scsi_spl < *param_1) {
    _scsi_spl = *param_1;
  }
  _scsi_rinit();
  piVar5 = &_scsi_conf;
  if (_scsi_conf != 0) {
    puVar4 = DAT_f011d30a;
    do {
      if (*piVar5 == *(int *)(param_2 + 0x20)) {
        iVar1 = *(int *)(param_2 + 0xc);
        _strcmp(iVar1,*(undefined4 *)(puVar4 + -6));
        if ((iVar1 == 0) && (*(int *)(param_2 + 0x2c) == (int)(char)puVar4[-2])) {
          uVar3 = (uint)(byte)puVar4[2];
          if ((0xf < uVar3) ||
             ((*(int **)(_scsibuscookies + uVar3 * 4) != (int *)0x0 &&
              (*(int **)(_scsibuscookies + uVar3 * 4) != param_1)))) {
            _printf(aSDIllegalScsiB,*(undefined4 *)(param_2 + 0xc));
            break;
          }
          *(int **)(_scsibuscookies + uVar3 * 4) = param_1;
          *(int *)(_scsibusctlrs + uVar3 * 4) = param_2;
          piVar2 = param_1;
          sub_F00B8244(param_1,param_2,*(undefined4 *)(puVar4 + -0xe),*(undefined4 *)(puVar4 + -10),
                       (int)(char)puVar4[1],(int)(char)puVar4[-1],(int)(char)*puVar4);
          if (piVar2 != (int *)0x0) {
            _nscsi_devices = _nscsi_devices + 1;
          }
        }
      }
      piVar5 = piVar5 + 6;
      puVar4 = puVar4 + 0x18;
    } while (*piVar5 != 0);
  }
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=2756 start=0xf00b8454 */

/* WARNING: Removing unreachable block (ram,0xf00b8674) */
/* WARNING: Removing unreachable block (ram,0xf00b8628) */
/* WARNING: Removing unreachable block (ram,0xf00b85f4) */
/* WARNING: Removing unreachable block (ram,0xf00b85c0) */
/* WARNING: Removing unreachable block (ram,0xf00b8580) */
/* WARNING: Removing unreachable block (ram,0xf00b8544) */
/* WARNING: Removing unreachable block (ram,0xf00b8500) */
/* WARNING: Removing unreachable block (ram,0xf00b84c8) */
/* WARNING: Removing unreachable block (ram,0xf00b84a8) */
/* WARNING: Removing unreachable block (ram,0xf00b84d0) */
/* WARNING: Removing unreachable block (ram,0xf00b8518) */
/* WARNING: Removing unreachable block (ram,0xf00b8564) */
/* WARNING: Removing unreachable block (ram,0xf00b8598) */
/* WARNING: Removing unreachable block (ram,0xf00b85d8) */
/* WARNING: Removing unreachable block (ram,0xf00b85fc) */
/* WARNING: Removing unreachable block (ram,0xf00b8660) */
/* WARNING: Removing unreachable block (ram,0xf00b8690) */
/* WARNING: Removing unreachable block (ram,0xf00b8484) */

qword _scsi_slave(int param_1,int param_2)

{
  byte bVar1;
  int iVar2;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  int iVar3;
  undefined4 uVar4;
  undefined4 unaff_l3;
  int iVar5;
  undefined4 unaff_l4;
  int iVar6;
  undefined4 unaff_l5;
  int iVar7;
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
  bool bVar8;
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
  iVar3 = 0;
  iVar5 = 0;
  iVar6 = 0;
  bVar9 = param_2 != 0;
  uVar4 = 3;
  if (*(int *)(param_1 + 0x10) == 0) {
    iVar7 = _iopbmap;
    _rmalloc(_iopbmap,0x24);
    *(int *)(param_1 + 0x10) = iVar7;
    if (iVar7 != 0) goto loc_F00B8498;
  }
  else {
loc_F00B8498:
    iVar7 = param_1 + 4;
    iVar3 = iVar7;
    _scsi_pktalloc(iVar7,6,1,bVar9);
    if (iVar3 != 0) {
      _makecom_g0();
      iVar2 = iVar3;
      _scsi_poll();
      if (iVar2 < 0) {
        uVar4 = 4;
        if (*(char *)(iVar3 + 0x28) == '\x01') {
          uVar4 = 2;
        }
      }
      else {
        iVar6 = _iopbmap;
        _rmalloc(_iopbmap,0x14);
        if (iVar6 != 0) {
          _bzero((undefined *)((int)register0x00000038 + -0x50),0x44);
          *(int *)((int)register0x00000038 + -0x30) = iVar6;
          *(undefined4 *)((int)register0x00000038 + -0x3c) = 0x14;
          *(undefined4 *)((int)register0x00000038 + -0x50) = 1;
          _scsi_resalloc(iVar7,6,1,(undefined *)((int)register0x00000038 + -0x50),bVar9);
          bVar8 = true;
          if (iVar7 == 0) goto loc_F00B8658;
          _makecom_g0();
          iVar5 = iVar7;
          if (((**(byte **)(iVar3 + 0x1c) & 2) == 0) || (iVar2 = iVar7, _scsi_poll(), -1 < iVar2)) {
            _bzero((undefined *)((int)register0x00000038 + -0x50),0x44);
            *(undefined4 *)((int)register0x00000038 + -0x30) = *(undefined4 *)(param_1 + 0x10);
            *(undefined4 *)((int)register0x00000038 + -0x3c) = 0x24;
            *(undefined4 *)((int)register0x00000038 + -0x50) = 1;
            iVar2 = iVar3;
            _scsi_dmaget(iVar3,(undefined *)((int)register0x00000038 + -0x50),bVar9);
            bVar8 = iVar7 == 0;
            if (iVar2 == 0) goto loc_F00B8658;
            _bzero(*(undefined4 *)(param_1 + 0x10),0x24);
            _makecom_g0(iVar3,param_1,9,0x12,0,0x24);
            iVar2 = iVar3;
            _scsi_poll();
            if (-1 < iVar2) {
              if ((**(byte **)(iVar3 + 0x1c) & 2) == 0) {
                bVar1 = *(byte *)(iVar3 + 0x29);
              }
              else {
                _scsi_poll(iVar7);
                bVar1 = *(byte *)(iVar3 + 0x29);
              }
              uVar4 = 1;
              if (((bVar1 & 8) != 0) && (3 < 0x24U - *(int *)(iVar3 + 0x24))) {
                uVar4 = 0;
              }
              goto loc_F00B8654;
            }
          }
          uVar4 = 4;
        }
      }
    }
  }
loc_F00B8654:
  iVar7 = iVar5;
  bVar8 = iVar7 == 0;
loc_F00B8658:
  if (!bVar8) {
    _scsi_resfree(iVar7);
  }
  if (iVar3 != 0) {
    _scsi_resfree(iVar3);
  }
  if (iVar6 != 0) {
    _rmfree(_iopbmap,0x14,iVar6);
  }
  return (qword)CONCAT14(bVar9,uVar4);
}
/* GHIDRADEC_FUNCTION index=2757 start=0xf00b86a0 */

undefined8 _scsi_ifgetcap(int *param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 unaff_l0;
  undefined4 unaff_l1;
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
  (**(code **)(*param_1 + 0x10))(param_1,param_2,param_3);
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=2758 start=0xf00b86c4 */

undefined8 _scsi_ifsetcap(int *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 unaff_l0;
  undefined4 unaff_l1;
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
  (**(code **)(*param_1 + 0x14))(param_1,param_2,param_3,param_4);
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=2759 start=0xf00b86ec */

undefined8 _scsi_abort(int *param_1,undefined4 param_2)

{
  undefined4 unaff_l0;
  undefined4 unaff_l1;
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
  (**(code **)(*param_1 + 0xc))(param_1,param_2);
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=2760 start=0xf00b870c */

undefined8 _scsi_reset(int *param_1,undefined4 param_2)

{
  undefined4 unaff_l0;
  undefined4 unaff_l1;
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
  (**(code **)(*param_1 + 8))(param_1,param_2);
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=2761 start=0xf00b872c */

/* WARNING: Removing unreachable block (ram,0xf00b8764) */
/* WARNING: Removing unreachable block (ram,0xf00b87a0) */

undefined8
_scsi_resalloc(int *param_1,undefined4 param_2,undefined4 param_3,int param_4,int param_5)

{
  int *piVar1;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  int *piVar2;
  undefined4 unaff_i1;
  int iVar3;
  undefined4 unaff_i2;
  undefined4 unaff_i3;
  undefined4 unaff_i4;
  undefined4 unaff_i5;
  undefined4 unaff_fp;
  undefined4 unaff_i7;
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
  iVar3 = *param_1;
  (**(code **)(iVar3 + 0x18))(param_1,param_2,param_3,param_5);
  piVar2 = param_1;
  if (param_1 == (int *)0x0) {
    if (param_5 == 1) {
      _panic(aScsiResallocNo);
    }
  }
  else if (param_4 != 0) {
    piVar1 = param_1;
    (**(code **)(iVar3 + 0x1c))(param_1,param_4,param_5);
    if (piVar1 == (int *)0x0) {
      if (param_5 == 1) {
        _panic(aScsiResallocNo_0);
      }
      piVar2 = (int *)0x0;
      (**(code **)(iVar3 + 0x20))(param_1);
    }
  }
  return CONCAT44(iVar3,piVar2);
}
/* GHIDRADEC_FUNCTION index=2762 start=0xf00b87c0 */

undefined8 _scsi_pktalloc(int *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 unaff_l0;
  undefined4 unaff_l1;
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
  (**(code **)(*param_1 + 0x18))(param_1,param_2,param_3,param_4);
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=2763 start=0xf00b87e8 */

undefined8 _scsi_dmaget(int param_1,int param_2,undefined4 param_3)

{
  undefined4 unaff_l0;
  undefined4 unaff_l1;
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
  if (param_2 == 0) {
    param_1 = 0;
  }
  else {
    (**(code **)(*(int *)(param_1 + 4) + 0x1c))(param_1,param_2,param_3);
  }
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=2764 start=0xf00b881c */

undefined8 _scsi_dmafree(int param_1,undefined4 param_2)

{
  undefined4 unaff_l0;
  undefined4 unaff_l1;
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
  (**(code **)(*(int *)(param_1 + 4) + 0x24))();
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=2765 start=0xf00b883c */

undefined8 _scsi_resfree(int param_1,undefined4 param_2)

{
  undefined4 unaff_l0;
  int iVar1;
  undefined4 unaff_l1;
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
  iVar1 = *(int *)(param_1 + 4);
  (**(code **)(iVar1 + 0x24))(param_1);
  (**(code **)(iVar1 + 0x20))(param_1);
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=2766 start=0xf00b8864 */

/* WARNING: Removing unreachable block (ram,0xf00b889c) */
/* WARNING: Removing unreachable block (ram,0xf00b8880) */

undefined8 _scsi_rinit(undefined4 param_1,undefined4 param_2)

{
  undefined4 unaff_l0;
  undefined4 unaff_l1;
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
  if (dword_F013179C == 0) {
    _scsi_addcmds(_scsi_ncmds_per_dev << 1);
    if (dword_F013179C == 0) {
      _panic(aNoSpaceForScsi);
    }
    DAT_f01317dc._0_4_ = 7;
    DAT_f01317a8._0_4_ = 7;
    dword_F01317E4 = 0;
    DAT_f01317a8._8_4_ = 0;
  }
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=2767 start=0xf00b88d0 */

/* WARNING: Removing unreachable block (ram,0xf00b8910) */
/* WARNING: Removing unreachable block (ram,0xf00b88f4) */
/* WARNING: Removing unreachable block (ram,0xf00b8970) */
/* WARNING: Removing unreachable block (ram,0xf00b88e0) */

undefined8 _scsi_addcmds(int param_1,undefined4 param_2)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  int iVar5;
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
  iVar5 = param_1 * 0x70;
  _kalloc();
  if (iVar5 != 0) {
    _bzero();
    _scsi_ncmds = _scsi_ncmds + param_1;
    uVar1 = _scsi_spl;
    _splr(_scsi_spl);
    iVar3 = 0;
    if (0 < param_1 + -1) {
      iVar4 = 0x70;
      iVar2 = 0;
      do {
        *(int *)(iVar2 + iVar5) = iVar5 + iVar4;
        iVar4 = iVar4 + 0x70;
        iVar3 = iVar3 + 1;
        iVar2 = iVar2 + 0x70;
      } while (iVar3 < param_1 + -1);
    }
    *(int *)(param_1 * 0x70 + iVar5 + -0x70) = dword_F013179C;
    dword_F013179C = iVar5;
    _splx(uVar1);
  }
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=2768 start=0xf00b8980 */

/* WARNING: Removing unreachable block (ram,0xf00b8a7c) */
/* WARNING: Removing unreachable block (ram,0xf00b8a50) */
/* WARNING: Removing unreachable block (ram,0xf00b8a28) */
/* WARNING: Removing unreachable block (ram,0xf00b89e0) */
/* WARNING: Removing unreachable block (ram,0xf00b8a14) */
/* WARNING: Removing unreachable block (ram,0xf00b89cc) */
/* WARNING: Removing unreachable block (ram,0xf00b89f8) */
/* WARNING: Removing unreachable block (ram,0xf00b8a3c) */
/* WARNING: Removing unreachable block (ram,0xf00b8a6c) */
/* WARNING: Removing unreachable block (ram,0xf00b8a90) */
/* WARNING: Removing unreachable block (ram,0xf00b899c) */

undefined8 _scsi_std_pktalloc(undefined4 *param_1,int param_2,int param_3,int param_4)

{
  undefined4 uVar1;
  undefined *puVar2;
  undefined4 unaff_l0;
  int iVar3;
  undefined4 unaff_l1;
  int iVar4;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 *puVar5;
  undefined4 unaff_i1;
  undefined4 unaff_i2;
  undefined4 unaff_i3;
  undefined4 unaff_i4;
  undefined4 unaff_i5;
  undefined4 unaff_fp;
  undefined4 unaff_i7;
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
  iVar4 = 0;
  iVar3 = 0;
  uVar1 = _scsi_spl;
  _splr(_scsi_spl);
  puVar2 = DAT_f0131400;
  puVar5 = dword_F013179C;
  do {
    while (puVar5 == (undefined4 *)0x0) {
      if (param_4 != 1) {
        if (param_4 != 0) {
          sub_F00B8E1C(&dword_F01317A0,param_4);
        }
        goto loc_F00B8A7C;
      }
      _servicing_interrupt();
      if ((undefined4 *)puVar2 != (undefined4 *)0x0) {
        _panic(aScsiStdPktallo);
      }
      puVar2 = (undefined *)&dword_F013179C;
      dword_F011F4A4 = dword_F011F4A4 + 1;
      _sleep(&dword_F013179C,0x14);
      puVar5 = dword_F013179C;
    }
    if (param_2 < 0xd) {
loc_F00B8A48:
      if (param_3 < 4) {
        dword_F013179C = (undefined4 *)*puVar5;
        goto loc_F00B8A7C;
      }
      iVar4 = param_3;
      _kalloc();
      if (iVar4 != 0) {
        _bzero(iVar4,param_3);
        dword_F013179C = (undefined4 *)*puVar5;
loc_F00B8A7C:
        _splx(uVar1);
        if (puVar5 != (undefined4 *)0x0) {
          _bzero(puVar5,0x70);
          if (iVar3 == 0) {
            puVar5[8] = puVar5 + 0x19;
          }
          else {
            puVar5[8] = iVar3;
            *(word *)(puVar5 + 0x17) = *(word *)(puVar5 + 0x17) | 0x40;
          }
          if (iVar4 == 0) {
            puVar5[7] = puVar5 + 0x18;
          }
          else {
            puVar5[7] = iVar4;
            *(word *)(puVar5 + 0x17) = *(word *)(puVar5 + 0x17) | 0x80;
          }
          *(char *)((int)puVar5 + 99) = (char)param_2;
          *(char *)((int)puVar5 + 0x5f) = (char)param_3;
          puVar5[1] = *param_1;
          puVar5[2] = param_1[1];
        }
        return CONCAT44(param_2,puVar5);
      }
    }
    else {
      iVar3 = param_2;
      _kalloc();
      if (iVar3 != 0) {
        _bzero(iVar3,param_2);
        goto loc_F00B8A48;
      }
    }
    puVar2 = (undefined *)0x0;
    puVar5 = (undefined4 *)0x0;
  } while( true );
}
/* GHIDRADEC_FUNCTION index=2769 start=0xf00b8b00 */

/* WARNING: Removing unreachable block (ram,0xf00b8b58) */
/* WARNING: Removing unreachable block (ram,0xf00b8b38) */
/* WARNING: Removing unreachable block (ram,0xf00b8b80) */
/* WARNING: Removing unreachable block (ram,0xf00b8b08) */

undefined8 _scsi_std_pktfree(undefined *param_1,undefined4 param_2)

{
  undefined4 uVar1;
  code *pcVar2;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
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
  uVar1 = _scsi_spl;
  _splr(_scsi_spl);
  *(undefined4 **)param_1 = dword_F013179C;
  dword_F013179C = (undefined4 *)param_1;
  if (dword_F011F4A4 != 0) {
    dword_F011F4A4 = 0;
    _wakeup(&dword_F013179C);
  }
  if (dword_F01317A0 != 0) {
    param_1 = DAT_f0131400;
    do {
      pcVar2 = (code *)&dword_F01317A0;
      sub_F00B8E84();
      (*pcVar2)();
      if (pcVar2 == (code *)0x0) break;
    } while (dword_F01317A0 != 0);
  }
  _splx(uVar1);
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=2770 start=0xf00b8b90 */

/* WARNING: Removing unreachable block (ram,0xf00b8cd4) */
/* WARNING: Removing unreachable block (ram,0xf00b8ce4) */
/* WARNING: Removing unreachable block (ram,0xf00b8c98) */
/* WARNING: Removing unreachable block (ram,0xf00b8ccc) */
/* WARNING: Removing unreachable block (ram,0xf00b8c2c) */
/* WARNING: Removing unreachable block (ram,0xf00b8c3c) */

undefined8 _scsi_std_dmaget(int param_1,uint *param_2,int param_3)

{
  undefined4 uVar1;
  int iVar2;
  word wVar3;
  uint uVar4;
  uint uVar5;
  code *pcVar6;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
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
  *(word *)(param_1 + 0x5c) = *(word *)(param_1 + 0x5c) & 0xfff8;
  uVar4 = param_2[8];
  if ((((uVar4 < 0xfff00000) || (uVar5 = _dvmasize * 0x1000 - 0x100000, uVar5 <= uVar4)) ||
      (uVar4 + param_2[5] < 0xfff00000)) || (uVar5 <= (uVar4 + param_2[5]) - 1)) {
    if (param_3 != 1) {
      uVar1 = _scsi_spl;
      _splr(_scsi_spl);
      if ((dword_F01317E4 != 0) || (dword_F01317D4 == 0)) {
        if (param_3 == 0) {
          pcVar6 = (code *)0x0;
        }
        else {
          pcVar6 = sub_F00B8D20;
        }
        iVar2 = _dvmamap;
        _mb_mapalloc(_dvmamap,param_2,0x41,pcVar6,0);
        *(int *)(param_1 + 0x3c) = iVar2;
        if (iVar2 != 0) {
          _splx(uVar1);
          goto loc_F00B8CEC;
        }
      }
      if (param_3 != 0) {
        sub_F00B8E1C(&dword_F01317D4,param_3);
      }
      _splx(uVar1);
      param_1 = 0;
      goto locret_F00B8D18;
    }
    iVar2 = _dvmamap;
    _mb_mapalloc(_dvmamap,param_2,0x40,0,0);
    *(int *)(param_1 + 0x3c) = iVar2;
  }
  else {
    *(uint *)(param_1 + 0x3c) = uVar4 + 0x100000;
    *(word *)(param_1 + 0x5c) = *(word *)(param_1 + 0x5c) | 4;
  }
loc_F00B8CEC:
  *(uint *)(param_1 + 0x40) = param_2[5];
  wVar3 = *(word *)(param_1 + 0x5c);
  if ((*param_2 & 1) == 0) {
    *(word *)(param_1 + 0x5c) = wVar3 | 2;
    wVar3 = *(word *)(param_1 + 0x5c);
  }
  *(word *)(param_1 + 0x5c) = wVar3 | 1;
locret_F00B8D18:
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=2771 start=0xf00b8dc8 */

/* WARNING: Removing unreachable block (ram,0xf00b8df0) */

undefined8 _scsi_std_dmafree(int param_1,undefined4 param_2)

{
  undefined4 unaff_l0;
  undefined4 unaff_l1;
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
  if ((*(word *)(param_1 + 0x5c) & 1) != 0) {
    if ((*(word *)(param_1 + 0x5c) & 4) == 0) {
      _mb_mapfree(_dvmamap,param_1 + 0x3c);
      *(undefined4 *)(param_1 + 0x40) = 0;
    }
    else {
      *(undefined4 *)(param_1 + 0x40) = 0;
    }
    *(undefined4 *)(param_1 + 0x3c) = 0;
    *(word *)(param_1 + 0x5c) = *(word *)(param_1 + 0x5c) & 0xfffe;
  }
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=2772 start=0xf00b8ebc */

undefined8 _scsi_chkdma(int param_1,int param_2)

{
  uint uVar1;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  uint uVar2;
  int iVar3;
  undefined4 unaff_i1;
  undefined4 unaff_i2;
  undefined4 unaff_i3;
  undefined4 unaff_i4;
  undefined4 unaff_i5;
  undefined4 unaff_fp;
  undefined4 unaff_i7;
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
  uVar1 = *(uint *)(param_1 + 0x34);
  if (uVar1 < *(uint *)(param_1 + 0x3c)) {
    iVar3 = 0;
  }
  else {
    uVar2 = *(uint *)(param_1 + 0x3c) + *(int *)(param_1 + 0x40);
    if (uVar1 < uVar2) {
      iVar3 = uVar2 - uVar1;
      if (uVar1 + param_2 < uVar2) {
        iVar3 = param_2;
      }
    }
    else {
      iVar3 = 0;
    }
  }
  return CONCAT44(param_2,iVar3);
}
/* GHIDRADEC_FUNCTION index=2773 start=0xf00b8f08 */

/* WARNING: Removing unreachable block (ram,0xf00b8fb0) */
/* WARNING: Removing unreachable block (ram,0xf00b8f54) */

undefined8 _scsi_poll(int param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 unaff_l0;
  int iVar3;
  undefined4 unaff_l1;
  int iVar4;
  uint uVar5;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 uVar6;
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
  
  iVar1 = dword_F011F4E8;
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
  iVar4 = -1;
  uVar5 = *(uint *)(param_1 + 0x14);
  iVar3 = 0;
  uVar6 = *(undefined4 *)(param_1 + 0x10);
  *(uint *)(param_1 + 0x14) = uVar5 | 1;
  *(code **)(param_1 + 0x10) = _scsi_pollintr;
  if (0 < iVar1) {
    param_2 = 0xffff0000;
    do {
      iVar1 = param_1;
      _pkt_transport();
      if (iVar1 != 1) {
        *(uint *)(param_1 + 0x14) = uVar5;
        goto loc_F00B8FCC;
      }
      if ((*(uint *)(param_1 + 0x28) & 0xffff0000) == 0x1000000) {
        uVar2 = 10000;
      }
      else {
        if (*(char *)(param_1 + 0x28) != '\0') {
          *(uint *)(param_1 + 0x14) = uVar5;
          goto loc_F00B8FCC;
        }
        uVar2 = 1000000;
        if ((**(byte **)(param_1 + 0x1c) & 0x3e) != 8) {
          iVar4 = 0;
          break;
        }
      }
      iVar3 = iVar3 + 1;
      _us_spin(uVar2);
    } while (iVar3 < dword_F011F4E8);
  }
  *(uint *)(param_1 + 0x14) = uVar5;
loc_F00B8FCC:
  *(undefined4 *)(param_1 + 0x10) = uVar6;
  if ((dword_F011F4E8 <= iVar3) && (iVar4 == 0)) {
    iVar4 = iVar3;
  }
  return CONCAT44(param_2,iVar4);
}
/* GHIDRADEC_FUNCTION index=2774 start=0xf00b8ff8 */

undefined8 _scsi_pollintr(undefined4 param_1,undefined4 param_2)

{
  undefined4 unaff_l0;
  undefined4 unaff_l1;
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
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=2775 start=0xf00b9004 */

undefined8
_makecom_g0(int param_1,int param_2,undefined4 param_3,undefined param_4,uint param_5,
           undefined param_6)

{
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 unaff_i1;
  uint *puVar1;
  undefined4 unaff_i2;
  undefined4 unaff_i3;
  undefined4 unaff_i4;
  undefined4 unaff_i5;
  undefined4 unaff_fp;
  undefined4 unaff_i7;
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
  *(undefined4 *)(param_1 + 4) = *(undefined4 *)(param_2 + 4);
  *(undefined4 *)(param_1 + 8) = *(undefined4 *)(param_2 + 8);
  *(undefined4 *)(param_1 + 0x14) = param_3;
  **(undefined **)(param_1 + 0x20) = param_4;
  **(uint **)(param_1 + 0x20) =
       **(uint **)(param_1 + 0x20) & 0xff1fffff | (*(byte *)(param_1 + 10) & 7) << 0x15;
  puVar1 = *(uint **)(param_1 + 0x20);
  *puVar1 = *puVar1 & 0xffe0ffff | param_5 & 0x1f0000;
  *(char *)(*(int *)(param_1 + 0x20) + 2) = (char)(param_5 >> 8);
  *(char *)(*(int *)(param_1 + 0x20) + 3) = (char)param_5;
  *(undefined *)(*(int *)(param_1 + 0x20) + 4) = param_6;
  return CONCAT44(puVar1,param_1);
}
/* GHIDRADEC_FUNCTION index=2776 start=0xf00b908c */

undefined8
_makecom_g0_s(int param_1,int param_2,undefined4 param_3,undefined param_4,undefined4 param_5,
             uint param_6)

{
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  uint *puVar1;
  undefined4 unaff_i1;
  uint uVar2;
  undefined4 unaff_i2;
  undefined4 unaff_i3;
  undefined4 unaff_i4;
  undefined4 unaff_i5;
  undefined4 unaff_fp;
  undefined4 unaff_i7;
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
  *(undefined4 *)(param_1 + 4) = *(undefined4 *)(param_2 + 4);
  *(undefined4 *)(param_1 + 8) = *(undefined4 *)(param_2 + 8);
  *(undefined4 *)(param_1 + 0x14) = param_3;
  **(undefined **)(param_1 + 0x20) = param_4;
  uVar2 = **(uint **)(param_1 + 0x20);
  **(uint **)(param_1 + 0x20) = uVar2 & 0xff1fffff | (*(byte *)(param_1 + 10) & 7) << 0x15;
  *(char *)(*(int *)(param_1 + 0x20) + 2) = (char)((uint)param_5 >> 0x10);
  *(char *)(*(int *)(param_1 + 0x20) + 3) = (char)((uint)param_5 >> 8);
  *(char *)(*(int *)(param_1 + 0x20) + 4) = (char)param_5;
  puVar1 = *(uint **)(param_1 + 0x20);
  *puVar1 = *puVar1 & 0xffe0ffff | (param_6 & 0x1f) << 0x10;
  return CONCAT44(uVar2,puVar1);
}
/* GHIDRADEC_FUNCTION index=2777 start=0xf00b9118 */

undefined8
_makecom_g1(int param_1,int param_2,undefined4 param_3,undefined param_4,undefined4 param_5,
           undefined2 param_6)

{
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 unaff_i1;
  uint uVar1;
  undefined4 unaff_i2;
  undefined4 unaff_i3;
  undefined4 unaff_i4;
  undefined4 unaff_i5;
  undefined4 unaff_fp;
  undefined4 unaff_i7;
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
  *(undefined4 *)(param_1 + 4) = *(undefined4 *)(param_2 + 4);
  *(undefined4 *)(param_1 + 8) = *(undefined4 *)(param_2 + 8);
  *(undefined4 *)(param_1 + 0x14) = param_3;
  **(undefined **)(param_1 + 0x20) = param_4;
  uVar1 = **(uint **)(param_1 + 0x20);
  **(uint **)(param_1 + 0x20) = uVar1 & 0xff1fffff | (*(byte *)(param_1 + 10) & 7) << 0x15;
  *(char *)(*(int *)(param_1 + 0x20) + 2) = (char)((uint)param_5 >> 0x18);
  *(char *)(*(int *)(param_1 + 0x20) + 3) = (char)((uint)param_5 >> 0x10);
  *(char *)(*(int *)(param_1 + 0x20) + 4) = (char)((uint)param_5 >> 8);
  *(char *)(*(int *)(param_1 + 0x20) + 5) = (char)param_5;
  *(char *)(*(int *)(param_1 + 0x20) + 7) = (char)((word)param_6 >> 8);
  *(char *)(*(int *)(param_1 + 0x20) + 8) = (char)param_6;
  return CONCAT44(uVar1,param_1);
}
/* GHIDRADEC_FUNCTION index=2778 start=0xf00b91a4 */

undefined8
_makecom_g5(int param_1,int param_2,undefined4 param_3,undefined param_4,undefined4 param_5,
           undefined2 param_6)

{
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 unaff_i1;
  uint uVar1;
  undefined4 unaff_i2;
  undefined4 unaff_i3;
  undefined4 unaff_i4;
  undefined4 unaff_i5;
  undefined4 unaff_fp;
  undefined4 unaff_i7;
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
  *(undefined4 *)(param_1 + 4) = *(undefined4 *)(param_2 + 4);
  *(undefined4 *)(param_1 + 8) = *(undefined4 *)(param_2 + 8);
  *(undefined4 *)(param_1 + 0x14) = param_3;
  **(undefined **)(param_1 + 0x20) = param_4;
  uVar1 = **(uint **)(param_1 + 0x20);
  **(uint **)(param_1 + 0x20) = uVar1 & 0xff1fffff | (*(byte *)(param_1 + 10) & 7) << 0x15;
  *(char *)(*(int *)(param_1 + 0x20) + 2) = (char)((uint)param_5 >> 0x18);
  *(char *)(*(int *)(param_1 + 0x20) + 3) = (char)((uint)param_5 >> 0x10);
  *(char *)(*(int *)(param_1 + 0x20) + 4) = (char)((uint)param_5 >> 8);
  *(char *)(*(int *)(param_1 + 0x20) + 5) = (char)param_5;
  *(char *)(*(int *)(param_1 + 0x20) + 9) = (char)((word)param_6 >> 8);
  *(char *)(*(int *)(param_1 + 0x20) + 10) = (char)param_6;
  return CONCAT44(uVar1,param_1);
}
/* GHIDRADEC_FUNCTION index=2779 start=0xf00b9230 */

/* WARNING: Removing unreachable block (ram,0xf00b92c0) */
/* WARNING: Removing unreachable block (ram,0xf00b9280) */
/* WARNING: Removing unreachable block (ram,0xf00b92dc) */
/* WARNING: Removing unreachable block (ram,0xf00b9268) */

undefined8
_get_pktiopb(int param_1,undefined4 *param_2,undefined4 param_3,undefined4 param_4,int param_5,
            int param_6)

{
  int iVar1;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  uint uVar2;
  int iVar3;
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
  iVar3 = *(int *)((int)register0x00000038 + 0x5c);
  iVar1 = 0;
  if (((iVar3 == 1) || (iVar3 == 0)) && (param_2 != (undefined4 *)0x0)) {
    *param_2 = 0;
    _bzero((undefined *)((int)register0x00000038 + -0x50),0x44);
    uVar2 = param_5 + 3U & 0xfffffffc;
    iVar1 = _iopbmap;
    _rmalloc(_iopbmap,uVar2);
    *(int *)((int)register0x00000038 + -0x30) = iVar1;
    if (iVar1 == 0) {
      iVar1 = 0;
    }
    else {
      if (param_6 != 0) {
        *(undefined4 *)((int)register0x00000038 + -0x50) = 1;
      }
      *(int *)((int)register0x00000038 + -0x3c) = param_5;
      _scsi_resalloc(param_1,param_3,param_4,(undefined *)((int)register0x00000038 + -0x50),iVar3);
      iVar1 = param_1;
      if (param_1 == 0) {
        _rmfree(_iopbmap,uVar2,*(undefined4 *)((int)register0x00000038 + -0x30));
      }
      else {
        *param_2 = *(undefined4 *)((int)register0x00000038 + -0x30);
      }
    }
  }
  return CONCAT44(param_2,iVar1);
}
/* GHIDRADEC_FUNCTION index=2780 start=0xf00b92f4 */

/* WARNING: Removing unreachable block (ram,0xf00b931c) */
/* WARNING: Removing unreachable block (ram,0xf00b9314) */

undefined8 _free_pktiopb(undefined4 param_1,int param_2,int param_3)

{
  undefined4 unaff_l0;
  undefined4 unaff_l1;
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
  if ((param_2 != 0) && (param_3 != 0)) {
    _rmfree(_iopbmap,param_3 + 3U & 0xfffffffc,param_2);
  }
  _scsi_resfree(param_1);
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=2781 start=0xf00b932c */

undefined8 _scsi_cookie(undefined4 param_1,undefined4 param_2)

{
  undefined4 unaff_l0;
  undefined4 unaff_l1;
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
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=2782 start=0xf00b9338 */

/* WARNING: Removing unreachable block (ram,0xf00b9378) */

undefined8 _scsi_dname(uint param_1,undefined4 param_2)

{
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined *puVar1;
  undefined4 unaff_i1;
  undefined4 unaff_i2;
  undefined4 unaff_i3;
  undefined4 unaff_i4;
  undefined4 unaff_i5;
  undefined4 unaff_fp;
  undefined4 unaff_i7;
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
  if ((param_1 & 0x1f) < 10) {
    puVar1 = *(undefined **)(unk_F011F4EC + (param_1 & 0x1f) * 4);
  }
  else if (param_1 == 0x3f) {
    puVar1 = aNotPresent;
  }
  else {
    puVar1 = unk_F0131808;
    _sprintf(unk_F0131808,aUnknownDeviceT);
  }
  return CONCAT44(param_2,puVar1);
}
/* GHIDRADEC_FUNCTION index=2783 start=0xf00b9394 */

/* WARNING: Removing unreachable block (ram,0xf00b93c8) */

undefined8 _scsi_rname(uint param_1,undefined4 param_2)

{
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined *puVar1;
  undefined4 unaff_i1;
  undefined4 unaff_i2;
  undefined4 unaff_i3;
  undefined4 unaff_i4;
  undefined4 unaff_i5;
  undefined4 unaff_fp;
  undefined4 unaff_i7;
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
  if ((param_1 & 0xff) < 0x15) {
    puVar1 = *(undefined **)(unk_F011F5DC + (param_1 & 0xff) * 4);
  }
  else {
    puVar1 = unk_F0131808;
    _sprintf(unk_F0131808,aUnkownReason0x);
  }
  return CONCAT44(param_2,puVar1);
}
/* GHIDRADEC_FUNCTION index=2784 start=0xf00b93d8 */

/* WARNING: Removing unreachable block (ram,0xf00b9424) */

undefined8 _scsi_mname(uint param_1,undefined4 param_2)

{
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined *puVar1;
  undefined4 unaff_i1;
  undefined4 unaff_i2;
  undefined4 unaff_i3;
  undefined4 unaff_i4;
  undefined4 unaff_i5;
  undefined4 unaff_fp;
  undefined4 unaff_i7;
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
  if ((param_1 & 0xff) < 0x12) {
    puVar1 = *(undefined **)(unk_F011F760 + (param_1 & 0xff) * 4);
  }
  else if ((param_1 & 0x98) == 0x80) {
    puVar1 = aIdentify_0;
  }
  else {
    puVar1 = unk_F0131808;
    _sprintf(unk_F0131808,aUnknownMsg0xX);
  }
  return CONCAT44(param_2,puVar1);
}
/* GHIDRADEC_FUNCTION index=2785 start=0xf00b9434 */

/* WARNING: Removing unreachable block (ram,0xf00b948c) */

undefined8 _scsi_cmd_decode(uint param_1,int *param_2)

{
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  byte *pbVar1;
  undefined *puVar2;
  undefined4 unaff_i1;
  undefined4 unaff_i2;
  undefined4 unaff_i3;
  undefined4 unaff_i4;
  undefined4 unaff_i5;
  undefined4 unaff_fp;
  undefined4 unaff_i7;
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
  if (*param_2 == 0) {
loc_F00B9478:
    puVar2 = unk_F0131808;
    _sprintf(unk_F0131808,aUndecodedCmd0x,param_1 & 0xff);
  }
  else {
    pbVar1 = (byte *)*param_2;
    while (param_2 = param_2 + 1, (param_1 & 0xff) != (uint)*pbVar1) {
      if (*param_2 == 0) goto loc_F00B9478;
      pbVar1 = (byte *)*param_2;
    }
    puVar2 = pbVar1 + 1;
  }
  return CONCAT44(param_2,puVar2);
}
/* GHIDRADEC_FUNCTION index=2786 start=0xf00b949c */

undefined8 _pkt_transport(int param_1,undefined4 param_2)

{
  undefined4 unaff_l0;
  undefined4 unaff_l1;
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
  (**(code **)(*(int *)(param_1 + 4) + 4))();
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=2787 start=0xf00b94bc */

/* WARNING: Removing unreachable block (ram,0xf00b94c8) */

undefined8 _espdmaidentify(int param_1,undefined4 param_2)

{
  undefined4 unaff_l0;
  undefined4 unaff_l1;
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
  _strcmp(param_1,&aEspdma);
  if (param_1 == 0) {
    _ndma_map = _ndma_map + 1;
  }
  return CONCAT44(param_2,(uint)(param_1 == 0));
}
/* GHIDRADEC_FUNCTION index=2788 start=0xf00b94f8 */

/* WARNING: Removing unreachable block (ram,0xf00b9634) */
/* WARNING: Removing unreachable block (ram,0xf00b9624) */
/* WARNING: Removing unreachable block (ram,0xf00b953c) */
/* WARNING: Removing unreachable block (ram,0xf00b95b0) */
/* WARNING: Removing unreachable block (ram,0xf00b962c) */
/* WARNING: Removing unreachable block (ram,0xf00b95d0) */
/* WARNING: Removing unreachable block (ram,0xf00b9518) */

undefined8 _espdmaattach(int param_1,undefined4 param_2)

{
  bool bVar1;
  int iVar2;
  undefined *puVar3;
  int iVar4;
  int iVar5;
  undefined4 *puVar6;
  undefined4 unaff_l0;
  int iVar7;
  undefined4 unaff_l1;
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
  if (_dma_map == 0) {
    iVar2 = _ndma_map << 4;
    _kalloc();
    _dma_map = iVar2;
    if (iVar2 != 0) {
      _bzero();
      goto loc_F00B9548;
    }
    iVar5 = *(int *)(param_1 + 0x2c);
    puVar3 = aEspdmaDNoSpace;
  }
  else {
loc_F00B9548:
    iVar5 = (int)DAT_f011fa2f;
    bVar1 = iVar5 < _ndma_map;
    DAT_f011fa2f = DAT_f011fa2f + '\x01';
    *(int *)(param_1 + 0x2c) = iVar5;
    iVar2 = _dma_map;
    if (bVar1) {
      iVar7 = _dma_map + iVar5 * 0x10;
      if (*(int *)(param_1 + 0x10) < 3) {
        puVar6 = *(undefined4 **)(param_1 + 0x14);
        iVar4 = puVar6[1];
        _map_regs(iVar4,puVar6[2],*puVar6);
        *(int *)(iVar2 + iVar5 * 0x10) = iVar4;
        if (iVar4 != 0) {
          *(undefined4 *)(iVar7 + 4) = **(undefined4 **)(param_1 + 0x14);
          *(undefined4 *)(iVar7 + 8) = *(undefined4 *)(*(int *)(param_1 + 0x14) + 4);
          *(undefined *)(iVar7 + 0xc) = 1;
          if (*(int *)(param_1 + 0x18) != 0) {
            _addintr(**(undefined4 **)(param_1 + 0x1c),_espdmaintr,*(undefined4 *)(param_1 + 0xc),
                     *(undefined4 *)(param_1 + 0x2c),0,0);
          }
          _report_dev(param_1);
          _attach_devs(param_1);
          uVar8 = 0;
          goto locret_F00B9640;
        }
        iVar5 = *(int *)(param_1 + 0x2c);
        puVar3 = aEspdmaDUnableT;
      }
      else {
        puVar3 = aEspdmaDBadRegi;
      }
    }
    else {
      puVar3 = aEspdmaDBadUnit;
    }
  }
  uVar8 = 0xffffffff;
  _printf(puVar3,iVar5);
locret_F00B9640:
  return CONCAT44(param_2,uVar8);
}
/* GHIDRADEC_FUNCTION index=2789 start=0xf00b9648 */

sqword _espdmaintr(undefined4 param_1,uint param_2)

{
  undefined4 unaff_l0;
  undefined4 unaff_l1;
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
  return (qword)param_2 << 0x20;
}
/* GHIDRADEC_FUNCTION index=2790 start=0xf00b9654 */

undefined8 _zsa_attach(int param_1)

{
  int iVar1;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 unaff_i1;
  int iVar2;
  undefined4 unaff_i2;
  undefined4 unaff_i3;
  undefined4 unaff_i4;
  undefined4 unaff_i5;
  undefined4 unaff_fp;
  undefined4 unaff_i7;
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
  iVar2 = *(sword *)(param_1 + 0x14) * 0x11c;
  iVar1 = *(sword *)(param_1 + 0x14) * 0x88;
  *(undefined **)(_zsaline + iVar2) = _zs_tty + iVar1;
  *(int *)(_zs_tty + iVar1 + 0x34) = param_1;
  *(undefined2 *)(_zs_tty + iVar1 + 0x38) = *(undefined2 *)(param_1 + 0x14);
  return CONCAT44(iVar2,param_1);
}
/* GHIDRADEC_FUNCTION index=2791 start=0xf00b96a8 */

/* WARNING: Removing unreachable block (ram,0xf00b96f0) */
/* WARNING: Removing unreachable block (ram,0xf00b96e0) */

undefined8 _zsgetspeed(uint param_1,undefined4 param_2)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  int iVar4;
  undefined4 unaff_i1;
  undefined4 unaff_i2;
  undefined4 unaff_i3;
  undefined4 unaff_i4;
  undefined4 unaff_i5;
  undefined4 unaff_fp;
  undefined4 unaff_i7;
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
  iVar4 = *(int *)(DAT_f013ee94 + (param_1 & 0x1f) * 0x88);
  if (iVar4 == 0) {
    iVar4 = 6;
  }
  else {
    uVar1 = *(uint *)(iVar4 + 0x10);
    _zszread(uVar1,0xc);
    iVar2 = *(int *)(iVar4 + 0x10);
    _zszread(iVar2,0xd);
    iVar4 = 0;
    iVar3 = 0;
    do {
      if ((uint)*(word *)(_zs_speeds + iVar3) == (uVar1 | iVar2 << 8)) goto locret_F00B9734;
      iVar4 = iVar4 + 1;
      iVar3 = iVar3 + 2;
    } while (iVar4 < 0x10);
    iVar4 = 0xd;
  }
locret_F00B9734:
  return CONCAT44(param_2,iVar4);
}
/* GHIDRADEC_FUNCTION index=2792 start=0xf00b973c */

/* WARNING: Removing unreachable block (ram,0xf00b9a00) */
/* WARNING: Removing unreachable block (ram,0xf00b9950) */
/* WARNING: Removing unreachable block (ram,0xf00b98b8) */
/* WARNING: Removing unreachable block (ram,0xf00b9938) */
/* WARNING: Removing unreachable block (ram,0xf00b9854) */
/* WARNING: Removing unreachable block (ram,0xf00b97d0) */
/* WARNING: Removing unreachable block (ram,0xf00b97c8) */
/* WARNING: Removing unreachable block (ram,0xf00b97fc) */
/* WARNING: Removing unreachable block (ram,0xf00b990c) */
/* WARNING: Removing unreachable block (ram,0xf00b9880) */
/* WARNING: Removing unreachable block (ram,0xf00b98d8) */
/* WARNING: Removing unreachable block (ram,0xf00b9994) */
/* WARNING: Removing unreachable block (ram,0xf00b99f0) */
/* WARNING: Removing unreachable block (ram,0xf00b97b0) */

undefined8 _zsopen(uint param_1,uint param_2)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  uint uVar4;
  undefined uVar6;
  undefined *puVar5;
  sword sVar7;
  undefined4 unaff_l0;
  int iVar8;
  undefined4 unaff_l1;
  undefined *puVar9;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  int iVar10;
  undefined4 unaff_i1;
  undefined4 unaff_i2;
  undefined4 unaff_i3;
  undefined4 unaff_i4;
  undefined4 unaff_i5;
  undefined4 unaff_fp;
  undefined4 unaff_i7;
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
  iVar1 = (param_1 & 0x1f) * 0x88;
  puVar9 = _zs_tty + iVar1;
  if (*(int *)(_zs_tty + iVar1 + 0x34) == 0) {
    iVar10 = 6;
  }
  else {
    _zs_tty[iVar1 + 0x47] = 2;
    *(code **)(_zs_tty + iVar1 + 0x24) = _zsstart;
    iVar8 = *(int *)(_zs_tty + iVar1 + 0x34);
    iVar2 = (*(word *)(_zs_tty + iVar1 + 0x38) & 0x1f) * 0x11c;
    iVar10 = iVar2;
    _splzs();
    *(undefined **)(iVar8 + 0x18) = _zsaline + iVar2;
    _zsopinit(iVar8,_zsops_async);
    _splx(iVar10);
    if (dword_F011FB08 != 0) {
      dword_F011FB08 = 0;
      _timeout(_zspoll,0,_zsticks);
    }
    sVar7 = (sword)param_1;
    if ((sVar7 != _kbddev) || (iVar10 = 0, _kbddevopen == 0)) {
      uVar3 = 0x14;
      if (sVar7 == _kbddev) {
        *(undefined2 *)(_zsaline + iVar2 + 4) = 0x14;
      }
      _spltty();
      uVar4 = *(uint *)(_zs_tty + iVar1 + 0x40);
      do {
        *(uint *)(_zs_tty + iVar1 + 0x40) = uVar4 | 2;
        if ((uVar4 & 4) == 0) {
          *(undefined2 *)(_zsaline + iVar2 + 0x110) = 0;
          *(undefined2 *)(_zsaline + iVar2 + 0x112) = 0;
          *(undefined2 *)(_zsaline + iVar2 + 8) = 0;
          _ttychars(puVar9);
          iVar10 = (int)sVar7;
          if ((iVar10 == _rconsdev) || (iVar10 == _kbddev)) {
            _zsgetspeed();
            uVar6 = (undefined)iVar10;
            _zs_tty[iVar1 + 0x49] = uVar6;
          }
          else {
            uVar6 = 0xd;
            _zs_tty[iVar1 + 0x49] = 0xd;
          }
          _zs_tty[iVar1 + 0x4a] = uVar6;
          *(undefined4 *)(_zs_tty + iVar1 + 0x3c) = 0xd8;
          _zsparam(puVar9);
        }
        else {
          if (((uVar4 & 0x80) != 0) && (*(sword *)(*(int *)(_active_u + 0x1c) + 2) != 0)) {
            _splx(uVar3);
            iVar10 = 0x10;
            break;
          }
          if (((param_1 & 0x80) != 0) && ((*(uint *)(_zs_tty + iVar1 + 0x40) & 0x40000000) == 0)) {
            _splx(uVar3);
            iVar10 = 6;
            break;
          }
        }
        _zsmctl(puVar9,0x82,0);
        if ((param_1 & 0x80) != 0) {
          *(uint *)(_zs_tty + iVar1 + 0x40) = *(uint *)(_zs_tty + iVar1 + 0x40) | 0x40000010;
        }
        if (*(char *)((int)&_zssoftCAR + (param_1 & 0x1f)) == '\0') {
          puVar5 = puVar9;
          _zsmctl(puVar9,0,3);
          if (((uint)puVar5 & 8) != 0) {
            uVar4 = *(uint *)(_zs_tty + iVar1 + 0x40);
            goto loc_F00B99AC;
          }
        }
        else {
          uVar4 = *(uint *)(_zs_tty + iVar1 + 0x40);
loc_F00B99AC:
          *(uint *)(_zs_tty + iVar1 + 0x40) = uVar4 | 0x10;
        }
        if (((param_2 & 4) != 0) ||
           ((uVar4 = *(uint *)(_zs_tty + iVar1 + 0x40), (uVar4 & 0x10) != 0 &&
            (((uVar4 & 0x40000000) == 0 || ((param_1 & 0x80) != 0)))))) goto loc_F00B9A00;
        *(uint *)(_zs_tty + iVar1 + 0x40) = uVar4 | 2;
        _sleep(iVar1 + -0xfec1160,0x1c);
        uVar4 = *(uint *)(_zs_tty + iVar1 + 0x40);
      } while( true );
    }
  }
locret_F00B9A38:
  return CONCAT44(param_2,iVar10);
loc_F00B9A00:
  _splx(uVar3);
  iVar10 = (int)sVar7;
  (**(code **)(_linesw + (char)_zs_tty[iVar1 + 0x47] * 0x30))(iVar10,puVar9);
  goto locret_F00B9A38;
}
/* GHIDRADEC_FUNCTION index=2793 start=0xf00b9a40 */

/* WARNING: Removing unreachable block (ram,0xf00b9b84) */
/* WARNING: Removing unreachable block (ram,0xf00b9b74) */
/* WARNING: Removing unreachable block (ram,0xf00b9b44) */
/* WARNING: Removing unreachable block (ram,0xf00b9b2c) */
/* WARNING: Removing unreachable block (ram,0xf00b9ae8) */
/* WARNING: Removing unreachable block (ram,0xf00b9ad0) */
/* WARNING: Removing unreachable block (ram,0xf00b9af0) */
/* WARNING: Removing unreachable block (ram,0xf00b9b3c) */
/* WARNING: Removing unreachable block (ram,0xf00b9b5c) */
/* WARNING: Removing unreachable block (ram,0xf00b9b7c) */
/* WARNING: Removing unreachable block (ram,0xf00b9b8c) */
/* WARNING: Removing unreachable block (ram,0xf00b9a60) */

undefined8 _zsclose(uint param_1,undefined4 param_2)

{
  sword sVar2;
  uint uVar1;
  int iVar3;
  undefined4 unaff_l0;
  undefined *puVar4;
  undefined4 unaff_l1;
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
  sVar2 = (sword)param_1;
  if (sVar2 != _kbddev) {
    _spltty();
    iVar3 = (param_1 & 0x1f) * 0x88;
    puVar4 = _zs_tty + iVar3;
    (**(code **)(DAT_f010b8d0 + (char)_zs_tty[iVar3 + 0x47] * 0x30))(puVar4);
    param_1 = *(uint *)(_zs_tty + iVar3 + 0x34);
    *(uint *)(_zs_tty + iVar3 + 0x40) = *(uint *)(_zs_tty + iVar3 + 0x40) & 0xbfffffff;
    if ((*(byte *)(param_1 + 0x25) & 0x10) == 0) {
      uVar1 = *(uint *)(_zs_tty + iVar3 + 0x40);
    }
    else {
      _splzs();
      *(byte *)(param_1 + 0x25) = *(byte *)(param_1 + 0x25) & 0xef;
      _zszwrite(*(undefined4 *)(param_1 + 0x10),5);
      _spltty();
      uVar1 = *(uint *)(_zs_tty + iVar3 + 0x40);
    }
    if ((((uVar1 & 0x206) != 4) && (sVar2 != _rconsdev)) && (sVar2 != _kbddev)) {
      _zsmctl(puVar4,0,0);
      _sleep(_lbolt,0x1d);
    }
    _ttyclose(puVar4);
    if ((*(uint *)(_zs_tty + iVar3 + 0x40) & 6) == 0) {
      _splzs();
      *(byte *)(param_1 + 0x21) = *(byte *)(param_1 + 0x21) & 0xef;
      _zszwrite(*(undefined4 *)(param_1 + 0x10),1);
      _spltty();
    }
    _wakeup(iVar3 + -0xfec1160);
    _spl0();
  }
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=2794 start=0xf00b9b9c */

qword _zsread(uint param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
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
  iVar1 = (param_1 & 0x1f) * 0x88;
  (**(code **)(DAT_f010b8d4 + (char)_zs_tty[iVar1 + 0x47] * 0x30))(_zs_tty + iVar1,param_2);
  return CONCAT44(param_2,param_1) & 0xffffffff0000001f;
}
/* GHIDRADEC_FUNCTION index=2795 start=0xf00b9bec */

qword _zswrite(uint param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
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
  iVar1 = (param_1 & 0x1f) * 0x88;
  (**(code **)(DAT_f010b8d8 + (char)_zs_tty[iVar1 + 0x47] * 0x30))(_zs_tty + iVar1,param_2);
  return CONCAT44(param_2,param_1) & 0xffffffff0000001f;
}
/* GHIDRADEC_FUNCTION index=2796 start=0xf00b9c3c */

/* WARNING: Removing unreachable block (ram,0xf00b9c5c) */

undefined8 _zsselect(uint param_1,undefined4 param_2)

{
  undefined *puVar1;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
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
  puVar1 = _zs_tty + (param_1 & 0x1f) * 0x88;
  _ttselect(puVar1,param_2);
  return CONCAT44(param_2,puVar1);
}
/* GHIDRADEC_FUNCTION index=2797 start=0xf00b9c6c */

/* WARNING: Removing unreachable block (ram,0xf00b9ecc) */
/* WARNING: Removing unreachable block (ram,0xf00b9ebc) */
/* WARNING: Removing unreachable block (ram,0xf00b9edc) */
/* WARNING: Removing unreachable block (ram,0xf00b9e80) */
/* WARNING: Removing unreachable block (ram,0xf00b9e44) */
/* WARNING: Removing unreachable block (ram,0xf00b9f08) */
/* WARNING: Removing unreachable block (ram,0xf00b9f00) */
/* WARNING: Removing unreachable block (ram,0xf00b9e60) */
/* WARNING: Removing unreachable block (ram,0xf00b9e78) */
/* WARNING: Removing unreachable block (ram,0xf00b9e9c) */
/* WARNING: Removing unreachable block (ram,0xf00b9eec) */
/* WARNING: Removing unreachable block (ram,0xf00b9eac) */
/* WARNING: Removing unreachable block (ram,0xf00b9d48) */
/* WARNING: Removing unreachable block (ram,0xf00b9cd8) */

undefined8 _zsioctl(uint param_1,int param_2,undefined4 *param_3,undefined4 param_4)

{
  int iVar1;
  undefined4 uVar2;
  byte bVar3;
  undefined4 unaff_l0;
  undefined *puVar4;
  undefined4 unaff_l1;
  int iVar5;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined *puVar6;
  undefined4 unaff_i1;
  undefined4 unaff_i2;
  undefined4 unaff_i3;
  undefined4 unaff_i4;
  undefined4 unaff_i5;
  undefined4 unaff_fp;
  undefined4 unaff_i7;
  bool bVar7;
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
  iVar1 = (param_1 & 0x1f) * 0x88;
  puVar4 = _zs_tty + iVar1;
  iVar5 = *(int *)(_zs_tty + iVar1 + 0x34);
  puVar6 = puVar4;
  (**(code **)(DAT_f010b8dc + (char)_zs_tty[iVar1 + 0x47] * 0x30))(puVar4,param_2,param_3,param_4);
  bVar7 = false;
  if ((int)puVar6 < 0) {
    puVar6 = puVar4;
    _ttioctl(puVar4,param_2,param_3,param_4);
    bVar7 = (int)puVar6 < 0;
  }
  if (bVar7) {
    if (param_2 == 0x20007479) {
      uVar2 = 0x82;
loc_F00B9ECC:
      _zsmctl(puVar4,uVar2,1);
      puVar6 = (undefined *)0x0;
    }
    else {
      if (0x20007479 < param_2) {
        if (param_2 == 0x4004746a) {
          _zsmctl(puVar4,0,3);
          puVar6 = (undefined *)0x0;
          _zstodm();
          *param_3 = puVar4;
          goto locret_F00B9F1C;
        }
        if (param_2 < 0x4004746b) {
          if (param_2 == 0x2000747a) {
            _splzs();
            uVar2 = *(undefined4 *)(iVar5 + 0x10);
            bVar3 = *(byte *)(iVar5 + 0x25) & 0xef;
          }
          else {
            puVar6 = (undefined *)0x19;
            if (param_2 != 0x2000747b) goto locret_F00B9F1C;
            _splzs();
            uVar2 = *(undefined4 *)(iVar5 + 0x10);
            bVar3 = *(byte *)(iVar5 + 0x25) | 0x10;
          }
          *(byte *)(iVar5 + 0x25) = bVar3;
          _zszwrite(uVar2,5);
          puVar6 = (undefined *)0x0;
          _spl0();
          goto locret_F00B9F1C;
        }
        if (param_2 != 0x40047a00) {
          puVar6 = (undefined *)0x19;
          if (param_2 == 0x40047a02) {
            puVar6 = (undefined *)0x0;
          }
          goto locret_F00B9F1C;
        }
loc_F00B9F18:
        puVar6 = (undefined *)0x0;
        goto locret_F00B9F1C;
      }
      if (param_2 == -0x7ffb8b93) {
        uVar2 = *param_3;
        _dmtozs(uVar2);
      }
      else {
        if (param_2 < -0x7ffb8b92) {
          if (param_2 == -0x7ffb8b95) {
            uVar2 = *param_3;
            _dmtozs(uVar2);
            _zsmctl(puVar4,uVar2,2);
            puVar6 = (undefined *)0x0;
            goto locret_F00B9F1C;
          }
          puVar6 = (undefined *)0x19;
          if (param_2 != -0x7ffb8b94) goto locret_F00B9F1C;
          uVar2 = *param_3;
          _dmtozs(uVar2);
          goto loc_F00B9ECC;
        }
        if (param_2 == -0x7ffb85ff) goto loc_F00B9F18;
        if (param_2 != 0x20007478) {
          puVar6 = (undefined *)0x19;
          goto locret_F00B9F1C;
        }
        uVar2 = 0;
      }
      _zsmctl(puVar4,uVar2,0);
      puVar6 = (undefined *)0x0;
    }
    goto locret_F00B9F1C;
  }
  if (param_2 < -0x7ff98bf5) {
    if (param_2 < -0x7ff98bf7) {
      if (-0x7ffb8b81 < param_2) goto locret_F00B9F1C;
      iVar1 = -0x7ffb8b83;
      goto loc_F00B9D3C;
    }
  }
  else {
    if (-0x7fdb8bea < param_2) goto locret_F00B9F1C;
    iVar1 = -0x7fdb8bec;
loc_F00B9D3C:
    if (param_2 < iVar1) goto locret_F00B9F1C;
  }
  _zsparam(puVar4);
locret_F00B9F1C:
  return CONCAT44(param_2,puVar6);
}
/* GHIDRADEC_FUNCTION index=2798 start=0xf00b9f24 */

undefined8 _dmtozs(uint param_1,undefined4 param_2)

{
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  uint uVar1;
  undefined4 unaff_i1;
  undefined4 unaff_i2;
  undefined4 unaff_i3;
  undefined4 unaff_i4;
  undefined4 unaff_i5;
  undefined4 unaff_fp;
  undefined4 unaff_i7;
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
  uVar1 = param_1 >> 3 & 8;
  if ((param_1 & 0x20) != 0) {
    uVar1 = uVar1 | 0x20;
  }
  if ((param_1 & 4) != 0) {
    uVar1 = uVar1 | 2;
  }
  if ((param_1 & 2) != 0) {
    uVar1 = uVar1 | 0x80;
  }
  return CONCAT44(param_2,uVar1);
}
/* GHIDRADEC_FUNCTION index=2799 start=0xf00b9f60 */

undefined8 _zstodm(uint param_1,undefined4 param_2)

{
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  uint uVar1;
  undefined4 unaff_i1;
  undefined4 unaff_i2;
  undefined4 unaff_i3;
  undefined4 unaff_i4;
  undefined4 unaff_i5;
  undefined4 unaff_fp;
  undefined4 unaff_i7;
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
  uVar1 = (param_1 & 8) << 3;
  if ((param_1 & 0x20) != 0) {
    uVar1 = uVar1 | 0x20;
  }
  if ((param_1 & 2) != 0) {
    uVar1 = uVar1 | 4;
  }
  if ((param_1 & 0x80) != 0) {
    uVar1 = uVar1 | 2;
  }
  return CONCAT44(param_2,uVar1);
}

