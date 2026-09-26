/* GHIDRADEC_FUNCTION index=4450 start=0xf00cd998 */

undefined8 +[SCSIDisk requiredProtocols](undefined4 param_1,undefined4 param_2)

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
  return CONCAT44(param_2,&unk_F012ECF0);
}
/* GHIDRADEC_FUNCTION index=4451 start=0xf00cd9ac */

/* WARNING: Removing unreachable block (ram,0xf00cd9d0) */
/* WARNING: Removing unreachable block (ram,0xf00cd9f0) */
/* WARNING: Removing unreachable block (ram,0xf00cd9bc) */

undefined8 +[SCSIDisk initialize](undefined (*param_1) [9],undefined4 param_2)

{
  undefined (*pauVar1) [9];
  undefined *puVar2;
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
  pauVar1 = paScsidisk_0;
  _objc_msgSend(paScsidisk_0,paClass);
  if (param_1 == pauVar1) {
    _sd_init_idmap();
    *(undefined (**) [9])((int)register0x00000038 + -0x10) = param_1;
  }
  else {
    *(undefined (**) [9])((int)register0x00000038 + -0x10) = param_1;
  }
  puVar2 = (undefined *)((int)register0x00000038 + -0x10);
  *(undefined4 *)((int)register0x00000038 + -0xc) = uRamf0142aa0;
  _objc_msgSendSuper(puVar2,paInitialize);
  return CONCAT44(param_2,puVar2);
}
/* GHIDRADEC_FUNCTION index=4452 start=0xf00cda00 */

/* WARNING: Removing unreachable block (ram,0xf00cdbe0) */
/* WARNING: Removing unreachable block (ram,0xf00cdb5c) */
/* WARNING: Removing unreachable block (ram,0xf00cdae4) */
/* WARNING: Removing unreachable block (ram,0xf00cdaa0) */
/* WARNING: Removing unreachable block (ram,0xf00cda7c) */
/* WARNING: Removing unreachable block (ram,0xf00cda48) */
/* WARNING: Removing unreachable block (ram,0xf00cda28) */
/* WARNING: Removing unreachable block (ram,0xf00cdc30) */
/* WARNING: Removing unreachable block (ram,0xf00cda90) */
/* WARNING: Removing unreachable block (ram,0xf00cdac4) */
/* WARNING: Removing unreachable block (ram,0xf00cdb10) */
/* WARNING: Removing unreachable block (ram,0xf00cdbd0) */
/* WARNING: Removing unreachable block (ram,0xf00cdbec) */
/* WARNING: Removing unreachable block (ram,0xf00cda04) */

undefined8 +[SCSIDisk probe:](int param_1,undefined4 param_2,int param_3)

{
  undefined (*pauVar1) [15];
  undefined4 unaff_l0;
  int iVar2;
  undefined4 unaff_l1;
  int iVar3;
  uint uVar4;
  int iVar5;
  undefined4 unaff_l3;
  int iVar6;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  char cVar7;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 unaff_i1;
  undefined *puVar8;
  undefined4 unaff_i2;
  uint uVar9;
  undefined4 unaff_i3;
  undefined4 uVar10;
  undefined4 unaff_i4;
  undefined4 unaff_i5;
  undefined4 unaff_fp;
  undefined4 unaff_i7;
  bool in_DECOMPILE_MODE;
  int in_CWP;
  undefined auStackX_0 [92];
  int aiStack_30 [12];
  
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
  _sd_idmap();
  uVar10 = 0;
  cVar7 = '\0';
  _objc_msgSend(param_3,paDirectdevice);
  puVar8 = (undefined *)((int)register0x00000038 + -8);
  do {
    iVar5 = param_3;
    _objc_msgSend(param_3,paNumberoftarget);
    iVar6 = 0;
    if (iVar5 <= cVar7) {
      if (iVar3 != 0) {
        _objc_msgSend(iVar3,paFree);
      }
      return CONCAT44(puVar8,uVar10);
    }
    uVar4 = 0;
    do {
      if (iVar3 == 0) {
        iVar3 = paScsidisk_0;
        _objc_msgSend(paScsidisk_0,paAlloc);
        _objc_msgSend();
        _objc_msgSend(iVar3,paInitresources);
        _objc_msgSend(iVar3,paSetdevandidinf,param_1 + DAT_f012ecec * 0x24);
      }
      uVar9 = uVar4 & 0xff;
      iVar5 = param_3;
      _objc_msgSend(param_3,paReservetargetL,cVar7,uVar9,iVar3);
      if (iVar5 == 0) {
        iVar5 = iVar3;
        _objc_msgSend(iVar3,paScsidiskinitTa,DAT_f012ecec,cVar7,uVar9,param_3);
        if (iVar5 == 0) {
          *(int *)(puVar8 + iVar6 * 4 + -0x28) = iVar3;
          iVar6 = iVar6 + 1;
          iVar3 = 0;
          uVar10 = 1;
          DAT_f012ecec = DAT_f012ecec + 1;
        }
        else {
          _objc_msgSend(param_3,paReleasetargetL,cVar7,uVar9,iVar3);
          if (iVar5 == 2) break;
        }
      }
      uVar4 = uVar4 + 1;
    } while ((int)(uVar4 * 0x1000000) >> 0x18 < 8);
    iVar5 = 0;
    if (0 < iVar6) {
      do {
        pauVar1 = paSetdevicekind;
        iVar2 = *(int *)(puVar8 + ((iVar5 << 0x18) >> 0x16) + -0x28);
        *(uint *)(iVar2 + 0x188) = *(uint *)(iVar2 + 0x188) | 0x8000;
        _objc_msgSend(iVar2,pauVar1,aScsidisk);
        _objc_msgSend(iVar2,paSetisphysical,1);
        _objc_msgSend(iVar2,paRegisterdevice);
        iVar5 = iVar5 + 1;
        *(uint *)(iVar2 + 0x188) = *(uint *)(iVar2 + 0x188) | 0x4000;
      } while (iVar5 * 0x1000000 >> 0x18 < iVar6);
    }
    cVar7 = cVar7 + '\x01';
  } while( true );
}
/* GHIDRADEC_FUNCTION index=4453 start=0xf00cdc40 */

/* WARNING: Removing unreachable block (ram,0xf00cdc6c) */

undefined8
-[SCSIDisk readAt:length:buffer:actualLength:client:]
          (undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
          undefined4 param_5,undefined4 param_6)

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
  _objc_msgSend(param_1,paDevicerwcommon,0,param_3,param_4,param_5,
                *(undefined4 *)((int)register0x00000038 + 0x5c),0,param_6);
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=4454 start=0xf00cdc7c */

/* WARNING: Removing unreachable block (ram,0xf00cdca8) */

undefined8
-[SCSIDisk readAsyncAt:length:buffer:pending:client:]
          (undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
          undefined4 param_5,undefined4 param_6)

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
  _objc_msgSend(param_1,paDevicerwcommon,0,param_3,param_4,param_5,
                *(undefined4 *)((int)register0x00000038 + 0x5c),param_6,0);
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=4455 start=0xf00cdcb8 */

/* WARNING: Removing unreachable block (ram,0xf00cdce4) */

undefined8
-[SCSIDisk writeAt:length:buffer:actualLength:client:]
          (undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
          undefined4 param_5,undefined4 param_6)

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
  _objc_msgSend(param_1,paDevicerwcommon,1,param_3,param_4,param_5,
                *(undefined4 *)((int)register0x00000038 + 0x5c),0,param_6);
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=4456 start=0xf00cdcf4 */

/* WARNING: Removing unreachable block (ram,0xf00cdd20) */

undefined8
-[SCSIDisk writeAsyncAt:length:buffer:pending:client:]
          (undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
          undefined4 param_5,undefined4 param_6)

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
  _objc_msgSend(param_1,paDevicerwcommon,1,param_3,param_4,param_5,
                *(undefined4 *)((int)register0x00000038 + 0x5c),param_6,0);
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=4457 start=0xf00cdd30 */

/* WARNING: Removing unreachable block (ram,0xf00cddd8) */
/* WARNING: Removing unreachable block (ram,0xf00cdd78) */
/* WARNING: Removing unreachable block (ram,0xf00cddf8) */
/* WARNING: Removing unreachable block (ram,0xf00cdd3c) */

undefined8 -[SCSIDisk updateReadyState](undefined4 *param_1,undefined4 param_2)

{
  undefined (*pauVar1) [14];
  undefined4 *puVar2;
  int iVar3;
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
  _bzero((undefined *)((int)register0x00000038 + -0x70),0x60);
  *(undefined *)((int)register0x00000038 + -0x70) = *(undefined *)(param_1 + 0x62);
  *(undefined *)((int)register0x00000038 + -0x6f) = *(undefined *)((int)param_1 + 0x189);
  *(undefined4 *)((int)register0x00000038 + -0x58) = 0x14;
  *(uint *)((int)register0x00000038 + -0x54) =
       *(uint *)((int)register0x00000038 + -0x54) | 0x80000000;
  puVar2 = param_1;
  _objc_msgSend(param_1,paAllocsdbuf,0);
  *puVar2 = 3;
  puVar2[5] = (undefined *)((int)register0x00000038 + -0x70);
  pauVar1 = paEnqueuesdbuf;
  puVar2[8] = puVar2[8] & 0x7fffffff | 0x40000000;
  *(undefined *)((int)register0x00000038 + -0x6c) = 0;
  *(uint *)((int)register0x00000038 + -0x6c) =
       *(uint *)((int)register0x00000038 + -0x6c) & 0xff1fffff |
       (*(byte *)((int)param_1 + 0x189) & 7) << 0x15;
  _objc_msgSend(param_1,pauVar1,puVar2);
  iVar3 = *(int *)((int)register0x00000038 + -0x50);
  _objc_msgSend(param_1,paFreesdbuf,puVar2);
  return CONCAT44(param_2,(uint)(iVar3 != 0));
}
/* GHIDRADEC_FUNCTION index=4458 start=0xf00cde08 */

/* WARNING: Removing unreachable block (ram,0xf00cde1c) */

undefined8 -[SCSIDisk ejectPhysical](undefined4 param_1,undefined4 param_2)

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
  _objc_msgSend(param_1,paScsistartstopI,2,0);
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=4459 start=0xf00cde2c */

/* WARNING: Removing unreachable block (ram,0xf00cdf7c) */
/* WARNING: Removing unreachable block (ram,0xf00cdf48) */
/* WARNING: Removing unreachable block (ram,0xf00cdef0) */
/* WARNING: Removing unreachable block (ram,0xf00cdeb8) */
/* WARNING: Removing unreachable block (ram,0xf00cde8c) */
/* WARNING: Removing unreachable block (ram,0xf00cde60) */
/* WARNING: Removing unreachable block (ram,0xf00cdea4) */
/* WARNING: Removing unreachable block (ram,0xf00cded4) */
/* WARNING: Removing unreachable block (ram,0xf00cdf3c) */
/* WARNING: Removing unreachable block (ram,0xf00cdf68) */
/* WARNING: Removing unreachable block (ram,0xf00cdfa8) */
/* WARNING: Removing unreachable block (ram,0xf00cde3c) */

undefined8 -[SCSIDisk updatePhysicalParameters](int param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 unaff_l0;
  int iVar3;
  undefined4 unaff_l1;
  int iVar4;
  undefined4 unaff_l3;
  undefined4 uVar5;
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
  uVar5 = 0;
  iVar1 = param_1;
  _objc_msgSend(param_1,paUpdatereadysta);
  if (iVar1 != 0) {
    uVar5 = 0xfffffd28;
    goto locret_F00CDFB4;
  }
  iVar1 = param_1;
  _objc_msgSend(param_1,paSdreadcapacity,(undefined *)((int)register0x00000038 + -0x18));
  if (iVar1 != 0) {
    uVar5 = 0xfffffd36;
    goto locret_F00CDFB4;
  }
  iVar4 = 10;
  _objc_msgSend(param_1,paSetdisksize,*(int *)((int)register0x00000038 + -0x18) + 1);
  iVar3 = 0;
  _objc_msgSend(param_1,paSetblocksize,*(undefined4 *)((int)register0x00000038 + -0x14));
  iVar1 = param_1;
  _objc_msgSend(param_1,paBlocksize);
  uVar2 = *(undefined4 *)(param_1 + 0x184);
  _objc_msgSend(uVar2,paAllocatebuffer,iVar1,(undefined *)((int)register0x00000038 + -0x5c),
                (undefined *)((int)register0x00000038 + -0x60));
  do {
    iVar1 = param_1;
    _objc_msgSend(param_1,paSdrawreadBlock,iVar4,1,uVar2);
    if (iVar1 == 0) break;
    iVar3 = iVar3 + 1;
    iVar4 = iVar4 + 10;
  } while (iVar3 < 5);
  _objc_msgSend(param_1,paSetformattedin,iVar1 == 0);
  _IOFree(*(undefined4 *)((int)register0x00000038 + -0x5c),
          *(undefined4 *)((int)register0x00000038 + -0x60));
  if (*(char *)(param_1 + 0x1bc) == '\x05') {
loc_F00CDF9C:
    uVar5 = 1;
  }
  else {
    _bzero((undefined *)((int)register0x00000038 + -0x58),0x3c);
    _objc_msgSend(param_1,paSdmodesense,(undefined *)((int)register0x00000038 + -0x58));
    if ((*(uint *)((int)register0x00000038 + -0x58) & 0x8000) != 0) goto loc_F00CDF9C;
  }
  _objc_msgSend(param_1,paSetwriteprotec,uVar5);
  uVar5 = 0;
locret_F00CDFB4:
  return CONCAT44(param_2,uVar5);
}
/* GHIDRADEC_FUNCTION index=4460 start=0xf00cdfbc */

/* WARNING: Removing unreachable block (ram,0xf00cdffc) */
/* WARNING: Removing unreachable block (ram,0xf00ce010) */
/* WARNING: Removing unreachable block (ram,0xf00cdfcc) */

undefined8 -[SCSIDisk abortRequest](undefined4 *param_1,undefined4 param_2)

{
  undefined4 uVar1;
  undefined4 *puVar2;
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
  puVar2 = param_1;
  _objc_msgSend(param_1,paAllocsdbuf,0);
  *puVar2 = 5;
  uVar1 = paEnqueuesdbuf;
  puVar2[8] = puVar2[8] & 0x7fffffff;
  _objc_msgSend(param_1,uVar1,puVar2);
  _objc_msgSend(param_1,paFreesdbuf,puVar2);
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=4461 start=0xf00ce020 */

/* WARNING: Removing unreachable block (ram,0xf00ce040) */
/* WARNING: Removing unreachable block (ram,0xf00ce02c) */

undefined8 -[SCSIDisk diskBecameReady](int param_1,undefined4 param_2)

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
  _objc_msgSend(*(undefined4 *)(param_1 + 0x1b8),paLock);
  _objc_msgSend(*(undefined4 *)(param_1 + 0x1b8),paUnlockwith,1);
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=4462 start=0xf00ce050 */

/* WARNING: Removing unreachable block (ram,0xf00ce0c0) */
/* WARNING: Removing unreachable block (ram,0xf00ce090) */
/* WARNING: Removing unreachable block (ram,0xf00ce0d8) */
/* WARNING: Removing unreachable block (ram,0xf00ce060) */

undefined8 -[SCSIDisk isDiskReady:](undefined4 *param_1,undefined4 param_2,uint param_3)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 *puVar3;
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
  puVar3 = param_1;
  _objc_msgSend(param_1,paLastreadystate_0);
  if (puVar3 == (undefined4 *)0x0) {
    puVar3 = (undefined4 *)0x0;
  }
  else if ((param_3 & 0xff) == 0) {
    puVar3 = (undefined4 *)0xfffffbb2;
  }
  else {
    puVar2 = param_1;
    _objc_msgSend(param_1,paAllocsdbuf,0);
    *puVar2 = 6;
    uVar1 = paEnqueuesdbuf;
    puVar2[8] = puVar2[8] | 0x80000000;
    puVar3 = param_1;
    _objc_msgSend(param_1,uVar1,puVar2);
    _objc_msgSend(param_1,paFreesdbuf,puVar2);
  }
  return CONCAT44(param_2,puVar3);
}
/* GHIDRADEC_FUNCTION index=4463 start=0xf00ce0f0 */

/* WARNING: Removing unreachable block (ram,0xf00ce128) */

undefined8 -[SCSIDisk setLastReadyState:](int param_1,undefined4 param_2,int param_3)

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
  if ((*(char *)(param_1 + 0x1c8) != '\0') && (param_3 != 3)) {
    *(undefined *)(param_1 + 0x1c8) = 0;
  }
  *(int *)((int)register0x00000038 + -0x10) = param_1;
  *(undefined4 *)((int)register0x00000038 + -0xc) = uRamf0142168;
  _objc_msgSendSuper((undefined *)((int)register0x00000038 + -0x10),paSetlastreadyst);
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=4464 start=0xf00ce138 */

/* WARNING: Removing unreachable block (ram,0xf00ce18c) */
/* WARNING: Removing unreachable block (ram,0xf00ce1a4) */
/* WARNING: Removing unreachable block (ram,0xf00ce14c) */

undefined8
-[SCSIDisk sdCdbRead:buffer:client:]
          (undefined4 *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
          undefined4 param_5)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
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
  puVar2 = param_1;
  _objc_msgSend(param_1,paAllocsdbuf,0);
  *puVar2 = 2;
  puVar2[5] = param_3;
  puVar2[3] = param_4;
  puVar2[4] = param_5;
  puVar2[6] = 0;
  uVar1 = paEnqueuesdbuf;
  puVar2[8] = puVar2[8] & 0x7fffffff;
  puVar3 = param_1;
  _objc_msgSend(param_1,uVar1,puVar2);
  _objc_msgSend(param_1,paFreesdbuf,puVar2);
  return CONCAT44(param_2,puVar3);
}
/* GHIDRADEC_FUNCTION index=4465 start=0xf00ce1b4 */

/* WARNING: Removing unreachable block (ram,0xf00ce208) */
/* WARNING: Removing unreachable block (ram,0xf00ce220) */
/* WARNING: Removing unreachable block (ram,0xf00ce1c8) */

undefined8
-[SCSIDisk sdCdbWrite:buffer:client:]
          (undefined4 *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
          undefined4 param_5)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
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
  puVar2 = param_1;
  _objc_msgSend(param_1,paAllocsdbuf,0);
  *puVar2 = 3;
  puVar2[5] = param_3;
  puVar2[3] = param_4;
  puVar2[4] = param_5;
  puVar2[6] = 0;
  uVar1 = paEnqueuesdbuf;
  puVar2[8] = puVar2[8] & 0x7fffffff;
  puVar3 = param_1;
  _objc_msgSend(param_1,uVar1,puVar2);
  _objc_msgSend(param_1,paFreesdbuf,puVar2);
  return CONCAT44(param_2,puVar3);
}
/* GHIDRADEC_FUNCTION index=4466 start=0xf00ce230 */

undefined8 -[SCSIDisk target](int param_1,undefined4 param_2)

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
  return CONCAT44(param_2,(uint)*(byte *)(param_1 + 0x188));
}
/* GHIDRADEC_FUNCTION index=4467 start=0xf00ce240 */

undefined8 -[SCSIDisk lun](int param_1,undefined4 param_2)

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
  return CONCAT44(param_2,(uint)*(byte *)(param_1 + 0x189));
}
/* GHIDRADEC_FUNCTION index=4468 start=0xf00ce250 */

undefined8 -[SCSIDisk inquiryDeviceType](int param_1,undefined4 param_2)

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
  return CONCAT44(param_2,(uint)*(byte *)(param_1 + 0x1bc));
}
/* GHIDRADEC_FUNCTION index=4469 start=0xf00ce260 */

undefined8 -[SCSIDisk controller](int param_1,undefined4 param_2)

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
  return CONCAT44(param_2,*(undefined4 *)(param_1 + 0x184));
}
/* GHIDRADEC_FUNCTION index=4470 start=0xf00ce270 */

undefined8 sub_F00CE270(char *param_1,char *param_2,int param_3,int param_4)

{
  bool bVar1;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 unaff_i1;
  char *pcVar2;
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
  bVar1 = false;
  pcVar2 = param_2;
  do {
    if ((param_3 == 0) || (param_4 == 0)) {
      return CONCAT44(pcVar2,(int)pcVar2 - (int)param_2);
    }
    if (*param_1 != '\0') {
      if (*param_1 == ' ') {
        if (bVar1) goto loc_F00CE2D8;
        bVar1 = true;
      }
      else {
        bVar1 = false;
      }
      param_4 = param_4 + -1;
      *pcVar2 = *param_1;
      pcVar2 = pcVar2 + 1;
    }
loc_F00CE2D8:
    param_3 = param_3 + -1;
    param_1 = param_1 + 1;
  } while( true );
}
/* GHIDRADEC_FUNCTION index=4471 start=0xf00ce2f0 */

/* WARNING: Removing unreachable block (ram,0xf00ce374) */
/* WARNING: Removing unreachable block (ram,0xf00ce358) */
/* WARNING: Removing unreachable block (ram,0xf00ce344) */
/* WARNING: Removing unreachable block (ram,0xf00ce364) */
/* WARNING: Removing unreachable block (ram,0xf00ce3a4) */
/* WARNING: Removing unreachable block (ram,0xf00ce32c) */

undefined8 -[SCSIDisk initResources](int param_1,undefined4 param_2)

{
  undefined4 uVar1;
  undefined (*pauVar2) [16];
  undefined (*pauVar3) [16];
  code *pcVar4;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  int iVar5;
  undefined4 unaff_l4;
  int iVar6;
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
  *(int *)(param_1 + 0x1ac) = param_1 + 0x1a8;
  *(int *)(param_1 + 0x1a8) = param_1 + 0x1a8;
  *(int *)(param_1 + 0x1b4) = param_1 + 0x1b0;
  *(int *)(param_1 + 0x1b0) = param_1 + 0x1b0;
  pauVar3 = paNxconditionloc;
  uVar1 = paAlloc;
  iVar6 = 0;
  pauVar2 = paNxconditionloc;
  _objc_msgSend(paNxconditionloc,paAlloc);
  *(undefined (**) [16])(param_1 + 0x1b8) = pauVar2;
  _objc_msgSend();
  _objc_msgSend(param_1,paSetlastreadyst,1);
  _objc_msgSend(pauVar3,uVar1);
  *(undefined (**) [16])(param_1 + 0x1c0) = pauVar3;
  _objc_msgSend();
  *(undefined4 *)(param_1 + 0x1c4) = 0;
  *(undefined *)(param_1 + 0x1c8) = 0;
  *(undefined4 *)(param_1 + 0x18c) = 0;
  *(uint *)(param_1 + 0x188) = *(uint *)(param_1 + 0x188) & 0xffff3fff;
  iVar5 = param_1;
  do {
    pcVar4 = _sdIoThread;
    _IOForkThread(_sdIoThread,param_1);
    *(code **)(iVar5 + 400) = pcVar4;
    iVar5 = iVar5 + 4;
    iVar6 = iVar6 + 1;
    *(int *)(param_1 + 0x18c) = *(int *)(param_1 + 0x18c) + 1;
  } while (iVar6 < 1);
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=4472 start=0xf00ce3d4 */

/* WARNING: Removing unreachable block (ram,0xf00ce71c) */
/* WARNING: Removing unreachable block (ram,0xf00ce6fc) */
/* WARNING: Removing unreachable block (ram,0xf00ce6d0) */
/* WARNING: Removing unreachable block (ram,0xf00ce684) */
/* WARNING: Removing unreachable block (ram,0xf00ce638) */
/* WARNING: Removing unreachable block (ram,0xf00ce61c) */
/* WARNING: Removing unreachable block (ram,0xf00ce5f0) */
/* WARNING: Removing unreachable block (ram,0xf00ce5cc) */
/* WARNING: Removing unreachable block (ram,0xf00ce59c) */
/* WARNING: Removing unreachable block (ram,0xf00ce558) */
/* WARNING: Removing unreachable block (ram,0xf00ce4e4) */
/* WARNING: Removing unreachable block (ram,0xf00ce440) */
/* WARNING: Removing unreachable block (ram,0xf00ce41c) */
/* WARNING: Removing unreachable block (ram,0xf00ce408) */
/* WARNING: Removing unreachable block (ram,0xf00ce42c) */
/* WARNING: Removing unreachable block (ram,0xf00ce4c4) */
/* WARNING: Removing unreachable block (ram,0xf00ce520) */
/* WARNING: Removing unreachable block (ram,0xf00ce574) */
/* WARNING: Removing unreachable block (ram,0xf00ce5b4) */
/* WARNING: Removing unreachable block (ram,0xf00ce5e0) */
/* WARNING: Removing unreachable block (ram,0xf00ce608) */
/* WARNING: Removing unreachable block (ram,0xf00ce62c) */
/* WARNING: Removing unreachable block (ram,0xf00ce64c) */
/* WARNING: Removing unreachable block (ram,0xf00ce6bc) */
/* WARNING: Removing unreachable block (ram,0xf00ce6e4) */
/* WARNING: Removing unreachable block (ram,0xf00ce70c) */
/* WARNING: Removing unreachable block (ram,0xf00ce730) */
/* WARNING: Removing unreachable block (ram,0xf00ce3f0) */

undefined8
-[SCSIDisk SCSIDiskInit:targetId:lun:controller:]
          (int param_1,undefined *param_2,undefined4 param_3,undefined param_4,undefined param_5,
          undefined4 param_6)

{
  undefined uVar1;
  undefined uVar2;
  uint uVar3;
  undefined5 *puVar4;
  undefined (*pauVar5) [13];
  undefined (*pauVar6) [14];
  int iVar7;
  uint uVar8;
  byte bVar10;
  undefined7 *puVar9;
  undefined4 unaff_l0;
  undefined *puVar11;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined *puVar12;
  undefined4 unaff_l5;
  undefined *puVar13;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined *puVar14;
  undefined4 unaff_i0;
  undefined4 uVar15;
  undefined4 unaff_i1;
  undefined4 unaff_i2;
  undefined *puVar16;
  undefined4 unaff_i3;
  undefined *puVar17;
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
  *(undefined4 *)(param_1 + 0x184) = param_6;
  *(undefined *)(param_1 + 0x188) = param_4;
  *(undefined *)(param_1 + 0x189) = param_5;
  _objc_msgSend(param_1,paSetunit,param_3);
  _sprintf((undefined *)((int)register0x00000038 + -200),&aSdD,param_3);
  _objc_msgSend(param_1,paSetname,(undefined *)((int)register0x00000038 + -200));
  _bzero((undefined *)((int)register0x00000038 + -0x58),0x41);
  iVar7 = param_1;
  _objc_msgSend(param_1,paSdinquiry,(undefined *)((int)register0x00000038 + -0x58));
  if (iVar7 == 0) {
    if ((*(byte *)((int)register0x00000038 + -0x58) & 0xe0) == 0) {
      uVar8 = *(byte *)((int)register0x00000038 + -0x58) & 0x1f;
      uVar3 = uVar8 - 7;
      if ((uVar8 < 6) && (uVar3 = uVar8, 3 < uVar8)) {
        bVar10 = *(byte *)((int)register0x00000038 + -0x58);
      }
      else {
        bVar10 = *(byte *)((int)register0x00000038 + -0x58);
        if (uVar3 != 0) {
          uVar15 = 1;
          goto locret_F00CE73C;
        }
      }
      *(byte *)(param_1 + 0x1bc) = bVar10 & 0x1f;
      if ((*(byte *)((int)register0x00000038 + -0x57) & 0x80) != 0) {
        _objc_msgSend(param_1,paSetremovable,1);
      }
      puVar14 = (undefined *)((int)register0x00000038 + -0x50);
      puVar16 = (undefined *)((int)register0x00000038 + -0xa8);
      puVar12 = puVar14;
      sub_F00CE270(puVar14,puVar16,8,0x50);
      puVar11 = puVar16 + (int)puVar12;
      if (puVar11[-1] != ' ') {
        puVar16[(int)puVar12] = 0x20;
        puVar11 = puVar11 + 1;
      }
      puVar13 = (undefined *)((int)register0x00000038 + -0x48);
      puVar12 = puVar13;
      sub_F00CE270(puVar13,puVar11,0x10,(int)puVar16 - (int)(puVar11 + -0x50));
      puVar11 = puVar11 + (int)puVar12;
      puVar12 = (undefined *)((int)register0x00000038 + -0x38);
      if (puVar11[-1] != ' ') {
        *puVar11 = 0x20;
        puVar11 = puVar11 + 1;
      }
      puVar17 = puVar12;
      sub_F00CE270(puVar12,puVar11,4,(int)puVar16 - (int)(puVar11 + -0x50));
      pauVar6 = paSetdrivename;
      puVar11[(int)puVar17] = 0;
      _objc_msgSend(param_1,paSetdrivename,puVar16);
      puVar4 = paName;
      puVar17 = (undefined *)((int)register0x00000038 + -0x118);
      uVar1 = *(undefined *)(param_1 + 0x188);
      param_2 = aTargetDLunDAtS;
      uVar2 = *(undefined *)(param_1 + 0x189);
      uVar15 = param_6;
      _objc_msgSend(param_6,paName);
      _sprintf(puVar17,aTargetDLunDAtS,uVar1,uVar2,uVar15);
      pauVar5 = paSetlocation;
      _objc_msgSend(param_1,paSetlocation,puVar17);
      _IOLog(&aSS,(undefined *)((int)register0x00000038 + -200),puVar16);
      _objc_msgSend(param_1,paUpdatereadysta);
      _objc_msgSend(param_1,paScsistartstopI,0,1);
      _objc_msgSend(param_1,paSetformattedin,0);
      _objc_msgSend(param_1,paUpdatephysical);
      _bzero(puVar16,0x50);
      sub_F00CE270(puVar14,puVar16,8,0x50);
      puVar11 = puVar16 + (int)puVar14;
      if (puVar11[-1] != ' ') {
        puVar16[(int)puVar14] = 0x20;
        puVar11 = puVar11 + 1;
      }
      sub_F00CE270(puVar13,puVar11,0x10,(int)puVar16 - (int)(puVar11 + -0x50));
      puVar11 = puVar11 + (int)puVar13;
      if (puVar11[-1] != ' ') {
        *puVar11 = 0x20;
        puVar11 = puVar11 + 1;
      }
      sub_F00CE270(puVar12,puVar11,0x20,(int)puVar16 - (int)(puVar11 + -0x50));
      puVar11[(int)puVar12] = 0;
      _objc_msgSend(param_1,pauVar6,puVar16);
      uVar1 = *(undefined *)(param_1 + 0x188);
      uVar2 = *(undefined *)(param_1 + 0x189);
      _objc_msgSend(param_6,puVar4);
      _sprintf(puVar17,aTargetDLunDAtS,uVar1,uVar2,param_6);
      _objc_msgSend(param_1,pauVar5,puVar17);
      *(int *)((int)register0x00000038 + -0x10) = param_1;
      puVar9 = &aIodisk;
      _objc_getOrigClass();
      *(undefined7 **)((int)register0x00000038 + -0xc) = puVar9;
      _objc_msgSendSuper((undefined *)((int)register0x00000038 + -0x10),paInit);
      uVar15 = 0;
    }
    else {
      uVar15 = 1;
    }
  }
  else {
    uVar15 = 3;
    if (iVar7 == 1) {
      uVar15 = 2;
    }
  }
locret_F00CE73C:
  return CONCAT44(param_2,uVar15);
}
/* GHIDRADEC_FUNCTION index=4473 start=0xf00ce744 */

/* WARNING: Removing unreachable block (ram,0xf00ce808) */
/* WARNING: Removing unreachable block (ram,0xf00ce7e4) */
/* WARNING: Removing unreachable block (ram,0xf00ce794) */
/* WARNING: Removing unreachable block (ram,0xf00ce7b8) */
/* WARNING: Removing unreachable block (ram,0xf00ce7f8) */
/* WARNING: Removing unreachable block (ram,0xf00ce818) */
/* WARNING: Removing unreachable block (ram,0xf00ce754) */

undefined8 -[SCSIDisk free](undefined4 *param_1,undefined4 param_2)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  undefined7 *puVar3;
  undefined *puVar4;
  undefined4 unaff_l0;
  int iVar5;
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
  puVar2 = param_1;
  _objc_msgSend(param_1,paAllocsdbuf,0);
  *puVar2 = 7;
  puVar2[8] = puVar2[8] & 0x7fffffff;
  iVar5 = 0;
  if (0 < (int)param_1[99]) {
    do {
      _objc_msgSend(param_1,paEnqueuesdbuf,puVar2);
      iVar5 = iVar5 + 1;
    } while (iVar5 < (int)param_1[99]);
  }
  _objc_msgSend(param_1,paFreesdbuf,puVar2);
  if ((param_1[0x62] & 0x8000) != 0) {
    _objc_msgSend(param_1[0x61],paReleasetargetL,*(undefined *)(param_1 + 0x62),
                  *(undefined *)((int)param_1 + 0x189),param_1);
  }
  uVar1 = paFree;
  _objc_msgSend(param_1[0x6e],paFree);
  *(undefined4 **)((int)register0x00000038 + -0x10) = param_1;
  puVar3 = &aIodisk;
  _objc_getOrigClass();
  *(undefined7 **)((int)register0x00000038 + -0xc) = puVar3;
  puVar4 = (undefined *)((int)register0x00000038 + -0x10);
  _objc_msgSendSuper(puVar4,uVar1);
  return CONCAT44(param_2,puVar4);
}
/* GHIDRADEC_FUNCTION index=4474 start=0xf00ce828 */

/* WARNING: Removing unreachable block (ram,0xf00ce9a4) */
/* WARNING: Removing unreachable block (ram,0xf00ce9d4) */
/* WARNING: Removing unreachable block (ram,0xf00ce95c) */
/* WARNING: Removing unreachable block (ram,0xf00ce8e0) */
/* WARNING: Removing unreachable block (ram,0xf00ce864) */
/* WARNING: Removing unreachable block (ram,0xf00ce858) */
/* WARNING: Removing unreachable block (ram,0xf00ce890) */
/* WARNING: Removing unreachable block (ram,0xf00ce8fc) */
/* WARNING: Removing unreachable block (ram,0xf00ce9c4) */
/* WARNING: Removing unreachable block (ram,0xf00ce994) */
/* WARNING: Removing unreachable block (ram,0xf00ce9e4) */
/* WARNING: Removing unreachable block (ram,0xf00ce84c) */

undefined8 -[SCSIDisk sdInquiry:](undefined4 *param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  undefined4 *puVar2;
  undefined *puVar3;
  undefined4 uVar4;
  uint uVar5;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  uint *puVar6;
  int iVar7;
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
  puVar6 = (uint *)((int)register0x00000038 + -0x6c);
  iVar1 = param_1[0x61];
  _objc_msgSend(iVar1,paAllocatebuffer,0x41,(undefined *)((int)register0x00000038 + -0x84),
                (undefined *)((int)register0x00000038 + -0x88));
  _bzero();
  _bzero((undefined *)((int)register0x00000038 + -0x70),0x60);
  *(undefined *)((int)register0x00000038 + -0x70) = *(undefined *)(param_1 + 0x62);
  *(undefined *)((int)register0x00000038 + -0x6f) = *(undefined *)((int)param_1 + 0x189);
  *(undefined *)((int)register0x00000038 + -0x60) = 1;
  _objc_msgSend(param_1[0x61],paGetdmaalignmen,(undefined *)((int)register0x00000038 + -0x80));
  uVar5 = *(uint *)((int)register0x00000038 + -0x78);
  if (uVar5 < 2) {
    uVar5 = 0x41;
  }
  else {
    uVar5 = uVar5 + 0x40 & -uVar5;
  }
  *(uint *)((int)register0x00000038 + -0x5c) = uVar5;
  *(undefined4 *)((int)register0x00000038 + -0x58) = 0x14;
  *(uint *)((int)register0x00000038 + -0x54) =
       *(uint *)((int)register0x00000038 + -0x54) | 0x80000000;
  puVar2 = param_1;
  _objc_msgSend(param_1,paAllocsdbuf,0);
  *puVar2 = 2;
  puVar3 = (undefined *)((int)register0x00000038 + -0x70);
  puVar2[5] = puVar3;
  puVar2[3] = iVar1;
  _IOVmTaskSelf();
  puVar2[4] = puVar3;
  uVar4 = paEnqueuesdbuf;
  *(undefined *)puVar6 = 0x12;
  *puVar6 = *puVar6 & 0xff1fffff | (*(byte *)((int)param_1 + 0x189) & 7) << 0x15;
  *(undefined *)((int)register0x00000038 + -0x68) = 0x41;
  puVar2[8] = puVar2[8] & 0x7fffffff | 0x40000000;
  _objc_msgSend(param_1,uVar4);
  iVar7 = *(int *)((int)register0x00000038 + -0x50);
  uVar4 = *(undefined4 *)((int)register0x00000038 + -0x84);
  if (iVar7 == 0) {
    uVar5 = *(uint *)((int)register0x00000038 + -0x48);
    if (uVar5 < 5) {
      iVar7 = 0x16;
      _objc_msgSend(param_1,paName);
      _IOLog(aSBadDmaTransfe,param_1,*(undefined4 *)((int)register0x00000038 + -0x48));
      uVar4 = *(undefined4 *)((int)register0x00000038 + -0x84);
    }
    else {
      if (0x41 - uVar5 != 0) {
        _bzero(iVar1 + uVar5,0x41 - uVar5);
      }
      _memcpy(param_3,iVar1,0x41);
      iVar7 = *(int *)((int)register0x00000038 + -0x50);
      uVar4 = *(undefined4 *)((int)register0x00000038 + -0x84);
    }
  }
  _IOFree(uVar4,*(undefined4 *)((int)register0x00000038 + -0x88));
  return CONCAT44(param_2,iVar7);
}
/* GHIDRADEC_FUNCTION index=4475 start=0xf00ce9f4 */

/* WARNING: Removing unreachable block (ram,0xf00ceb50) */
/* WARNING: Removing unreachable block (ram,0xf00ceb08) */
/* WARNING: Removing unreachable block (ram,0xf00ceaa4) */
/* WARNING: Removing unreachable block (ram,0xf00cea28) */
/* WARNING: Removing unreachable block (ram,0xf00cea54) */
/* WARNING: Removing unreachable block (ram,0xf00ceac0) */
/* WARNING: Removing unreachable block (ram,0xf00ceb40) */
/* WARNING: Removing unreachable block (ram,0xf00ceb78) */
/* WARNING: Removing unreachable block (ram,0xf00cea18) */

undefined8 -[SCSIDisk sdReadCapacity:](undefined4 *param_1,undefined4 param_2,undefined4 *param_3)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  undefined *puVar3;
  undefined4 uVar4;
  uint uVar5;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  int iVar6;
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
  puVar1 = (undefined4 *)param_1[0x61];
  _objc_msgSend(puVar1,paAllocatebuffer,8,(undefined *)((int)register0x00000038 + -0x84),
                (undefined *)((int)register0x00000038 + -0x88));
  _bzero((undefined *)((int)register0x00000038 + -0x70),0x60);
  *(undefined *)((int)register0x00000038 + -0x70) = *(undefined *)(param_1 + 0x62);
  *(undefined *)((int)register0x00000038 + -0x6f) = *(undefined *)((int)param_1 + 0x189);
  *(undefined *)((int)register0x00000038 + -0x60) = 1;
  _objc_msgSend(param_1[0x61],paGetdmaalignmen,(undefined *)((int)register0x00000038 + -0x80));
  uVar5 = *(uint *)((int)register0x00000038 + -0x78);
  if (uVar5 < 2) {
    uVar5 = 8;
  }
  else {
    uVar5 = uVar5 + 7 & -uVar5;
  }
  *(uint *)((int)register0x00000038 + -0x5c) = uVar5;
  *(undefined4 *)((int)register0x00000038 + -0x58) = 0x14;
  *(uint *)((int)register0x00000038 + -0x54) =
       *(uint *)((int)register0x00000038 + -0x54) | 0x80000000;
  puVar2 = param_1;
  _objc_msgSend(param_1,paAllocsdbuf,0);
  *puVar2 = 2;
  puVar3 = (undefined *)((int)register0x00000038 + -0x70);
  puVar2[5] = puVar3;
  puVar2[3] = puVar1;
  _IOVmTaskSelf();
  puVar2[4] = puVar3;
  uVar4 = paEnqueuesdbuf;
  *(undefined *)((int)register0x00000038 + -0x6c) = 0x25;
  *(byte *)((int)register0x00000038 + -0x6b) =
       *(byte *)((int)register0x00000038 + -0x6b) & 0x1f | *(char *)((int)param_1 + 0x189) << 5;
  puVar2[8] = puVar2[8] & 0x7fffffff;
  _objc_msgSend(param_1,uVar4);
  iVar6 = *(int *)((int)register0x00000038 + -0x50);
  uVar4 = *(undefined4 *)((int)register0x00000038 + -0x84);
  if (iVar6 == 0) {
    if (*(int *)((int)register0x00000038 + -0x48) == 8) {
      *param_3 = *puVar1;
      param_3[1] = puVar1[1];
      iVar6 = *(int *)((int)register0x00000038 + -0x50);
      uVar4 = *(undefined4 *)((int)register0x00000038 + -0x84);
    }
    else {
      iVar6 = 0x16;
      _objc_msgSend(param_1,paName);
      _IOLog(aSBadDmaTransfe_0,param_1,*(undefined4 *)((int)register0x00000038 + -0x48));
      uVar4 = *(undefined4 *)((int)register0x00000038 + -0x84);
    }
  }
  _IOFree(uVar4,*(undefined4 *)((int)register0x00000038 + -0x88));
  return CONCAT44(param_2,iVar6);
}
/* GHIDRADEC_FUNCTION index=4476 start=0xf00ceb88 */

/* WARNING: Removing unreachable block (ram,0xf00cecc4) */
/* WARNING: Removing unreachable block (ram,0xf00cec50) */
/* WARNING: Removing unreachable block (ram,0xf00cebe4) */
/* WARNING: Removing unreachable block (ram,0xf00cebb8) */
/* WARNING: Removing unreachable block (ram,0xf00cec34) */
/* WARNING: Removing unreachable block (ram,0xf00ceca4) */
/* WARNING: Removing unreachable block (ram,0xf00cecd4) */
/* WARNING: Removing unreachable block (ram,0xf00ceba8) */

undefined8 -[SCSIDisk sdModeSense:](undefined4 *param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  undefined *puVar3;
  undefined4 uVar4;
  uint uVar5;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  uint *puVar6;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  int iVar7;
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
  puVar6 = (uint *)((int)register0x00000038 + -0x6c);
  uVar1 = param_1[0x61];
  _objc_msgSend(uVar1,paAllocatebuffer,0x3c,(undefined *)((int)register0x00000038 + -0x84),
                (undefined *)((int)register0x00000038 + -0x88));
  _bzero((undefined *)((int)register0x00000038 + -0x70),0x60);
  *(undefined *)((int)register0x00000038 + -0x70) = *(undefined *)(param_1 + 0x62);
  *(undefined *)((int)register0x00000038 + -0x6f) = *(undefined *)((int)param_1 + 0x189);
  *(undefined *)((int)register0x00000038 + -0x60) = 1;
  _objc_msgSend(param_1[0x61],paGetdmaalignmen,(undefined *)((int)register0x00000038 + -0x80));
  uVar5 = *(uint *)((int)register0x00000038 + -0x78);
  if (uVar5 < 2) {
    uVar5 = 0x3c;
  }
  else {
    uVar5 = uVar5 + 0x3b & -uVar5;
  }
  *(uint *)((int)register0x00000038 + -0x5c) = uVar5;
  *(undefined4 *)((int)register0x00000038 + -0x58) = 0x14;
  *(uint *)((int)register0x00000038 + -0x54) =
       *(uint *)((int)register0x00000038 + -0x54) | 0x80000000;
  puVar2 = param_1;
  _objc_msgSend(param_1,paAllocsdbuf,0);
  *puVar2 = 2;
  puVar3 = (undefined *)((int)register0x00000038 + -0x70);
  puVar2[5] = puVar3;
  puVar2[3] = uVar1;
  _IOVmTaskSelf();
  puVar2[4] = puVar3;
  uVar4 = paEnqueuesdbuf;
  *(undefined *)puVar6 = 0x1a;
  *puVar6 = *puVar6 & 0xff1fffff | (*(byte *)((int)param_1 + 0x189) & 7) << 0x15;
  *(undefined *)((int)register0x00000038 + -0x68) = 0x3c;
  puVar2[8] = puVar2[8] | 0x80000000;
  _objc_msgSend(param_1,uVar4);
  iVar7 = *(int *)((int)register0x00000038 + -0x50);
  uVar4 = *(undefined4 *)((int)register0x00000038 + -0x84);
  if (iVar7 == 0) {
    _memcpy(param_3,uVar1,0x3c);
    iVar7 = *(int *)((int)register0x00000038 + -0x50);
    uVar4 = *(undefined4 *)((int)register0x00000038 + -0x84);
  }
  _IOFree(uVar4,*(undefined4 *)((int)register0x00000038 + -0x88));
  return CONCAT44(param_2,iVar7);
}
/* GHIDRADEC_FUNCTION index=4477 start=0xf00cece4 */

/* WARNING: Removing unreachable block (ram,0xf00ced40) */
/* WARNING: Removing unreachable block (ram,0xf00ced10) */
/* WARNING: Removing unreachable block (ram,0xf00ced58) */
/* WARNING: Removing unreachable block (ram,0xf00cecf8) */

undefined8
-[SCSIDisk sdRawRead:blockCnt:buffer:]
          (undefined4 *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
          undefined4 param_5)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
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
  puVar2 = param_1;
  _objc_msgSend(param_1,paAllocsdbuf,0);
  *puVar2 = 0;
  puVar2[1] = param_3;
  puVar2[2] = param_4;
  puVar2[3] = param_5;
  puVar3 = puVar2;
  _IOVmTaskSelf();
  puVar2[4] = puVar3;
  uVar1 = paEnqueuesdbuf;
  puVar2[8] = puVar2[8] | 0xc0000000;
  puVar3 = param_1;
  _objc_msgSend(param_1,uVar1,puVar2);
  _objc_msgSend(param_1,paFreesdbuf,puVar2);
  return CONCAT44(param_2,puVar3);
}
/* GHIDRADEC_FUNCTION index=4478 start=0xf00ced68 */

/* WARNING: Removing unreachable block (ram,0xf00cee64) */
/* WARNING: Removing unreachable block (ram,0xf00cedb4) */
/* WARNING: Removing unreachable block (ram,0xf00cee7c) */
/* WARNING: Removing unreachable block (ram,0xf00ced78) */

undefined8
-[SCSIDisk scsiStartStop:inhibitRetry:]
          (undefined4 *param_1,undefined4 param_2,uint param_3,uint param_4)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
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
  _bzero((undefined *)((int)register0x00000038 + -0x70),0x60);
  *(undefined *)((int)register0x00000038 + -0x70) = *(undefined *)(param_1 + 0x62);
  *(undefined *)((int)register0x00000038 + -0x6f) = *(undefined *)((int)param_1 + 0x189);
  *(undefined4 *)((int)register0x00000038 + -0x58) = 0x14;
  *(uint *)((int)register0x00000038 + -0x54) =
       *(uint *)((int)register0x00000038 + -0x54) | 0x80000000;
  puVar1 = param_1;
  _objc_msgSend(param_1,paAllocsdbuf,0);
  puVar1[5] = (undefined *)((int)register0x00000038 + -0x70);
  puVar1[8] = puVar1[8] & 0xbfffffff | (uint)((param_4 & 0xff) != 0) << 0x1e | 0x80000000;
  *(undefined *)((int)register0x00000038 + -0x6c) = 0x1b;
  *(uint *)((int)register0x00000038 + -0x6c) =
       *(uint *)((int)register0x00000038 + -0x6c) & 0xff1fffff |
       (*(byte *)((int)param_1 + 0x189) & 7) << 0x15;
  if (param_3 == 1) {
    *(undefined *)((int)register0x00000038 + -0x68) = 0;
loc_F00CEE50:
    uVar2 = 3;
  }
  else {
    if (param_3 < 2) {
      *(undefined *)((int)register0x00000038 + -0x68) = 1;
      goto loc_F00CEE50;
    }
    if (param_3 != 2) goto loc_F00CEE5C;
    *(undefined *)((int)register0x00000038 + -0x68) = 2;
    uVar2 = 4;
  }
  *puVar1 = uVar2;
loc_F00CEE5C:
  puVar3 = param_1;
  _objc_msgSend(param_1,paEnqueuesdbuf,puVar1);
  _objc_msgSend(param_1,paFreesdbuf,puVar1);
  return CONCAT44(param_2,puVar3);
}
/* GHIDRADEC_FUNCTION index=4479 start=0xf00cee8c */

/* WARNING: Removing unreachable block (ram,0xf00cef00) */
/* WARNING: Removing unreachable block (ram,0xf00cf01c) */
/* WARNING: Removing unreachable block (ram,0xf00cefb8) */
/* WARNING: Removing unreachable block (ram,0xf00cef68) */
/* WARNING: Removing unreachable block (ram,0xf00cef44) */
/* WARNING: Removing unreachable block (ram,0xf00cef20) */
/* WARNING: Removing unreachable block (ram,0xf00cef58) */
/* WARNING: Removing unreachable block (ram,0xf00cef80) */
/* WARNING: Removing unreachable block (ram,0xf00ceff4) */
/* WARNING: Removing unreachable block (ram,0xf00ceee8) */
/* WARNING: Removing unreachable block (ram,0xf00cef10) */
/* WARNING: Removing unreachable block (ram,0xf00ceeac) */

undefined8
-[SCSIDisk deviceRwCommon:block:length:buffer:client:pending:actualLength:]
          (undefined4 *param_1,undefined4 param_2,undefined4 param_3,undefined4 *param_4,int param_5
          ,undefined4 param_6)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  int iVar3;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  int iVar4;
  undefined4 unaff_l4;
  undefined4 uVar5;
  undefined4 unaff_l5;
  undefined4 *puVar6;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 *puVar7;
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
  uVar5 = *(undefined4 *)((int)register0x00000038 + 0x5c);
  iVar4 = *(int *)((int)register0x00000038 + 0x60);
  puVar6 = *(undefined4 **)((int)register0x00000038 + 100);
  puVar7 = param_1;
  _objc_msgSend(param_1,paIsdiskready,1);
  if (puVar7 == (undefined4 *)0xfffffbb2) {
    puVar7 = (undefined4 *)0xfffffbb2;
  }
  else if (puVar7 == (undefined4 *)0x0) {
    puVar7 = param_1;
    _objc_msgSend(param_1,paIsformatted);
    if (((uint)puVar7 & 0xff) == 0) {
      puVar7 = (undefined4 *)0xfffffbb3;
    }
    else {
      puVar1 = param_1;
      _objc_msgSend(param_1,paBlocksize);
      puVar2 = param_1;
      _objc_msgSend(param_1,paDisksize);
      iVar3 = param_5;
      .urem(param_5,puVar1);
      puVar7 = (undefined4 *)0xffffffff;
      if (iVar3 == 0) {
        .udiv(param_5,puVar1);
        if ((puVar2 < (undefined4 *)((int)param_4 + param_5)) &&
           (param_5 = (int)puVar2 - (int)param_4, puVar2 <= param_4)) {
          puVar7 = (undefined4 *)0xfffffd3e;
        }
        else {
          puVar1 = param_1;
          _objc_msgSend(param_1,paAllocsdbuf,iVar4);
          *puVar1 = param_3;
          puVar1[1] = param_4;
          puVar1[2] = param_5;
          puVar1[3] = param_6;
          puVar1[4] = uVar5;
          uVar5 = paEnqueuesdbuf;
          puVar1[8] = puVar1[8] | 0x80000000;
          puVar7 = param_1;
          _objc_msgSend(param_1,uVar5,puVar1);
          uVar5 = paFreesdbuf;
          if (iVar4 == 0) {
            *puVar6 = puVar1[9];
            _objc_msgSend(param_1,uVar5);
          }
        }
      }
    }
  }
  else {
    puVar6 = param_1;
    _objc_msgSend(param_1,paName);
    _objc_msgSend(param_1,paStringfromretu,puVar7);
    _IOLog(aSDevicerwcommo,puVar6,param_1);
  }
  return CONCAT44(param_2,puVar7);
}
/* GHIDRADEC_FUNCTION index=4480 start=0xf00cf02c */

/* WARNING: Removing unreachable block (ram,0xf00cf0c8) */
/* WARNING: Removing unreachable block (ram,0xf00cf0a4) */
/* WARNING: Removing unreachable block (ram,0xf00cf0d8) */
/* WARNING: Removing unreachable block (ram,0xf00cf040) */

undefined8 -[SCSIDisk enqueueSdBuf:](int param_1,undefined4 param_2,int param_3)

{
  undefined4 uVar1;
  int iVar2;
  int *piVar3;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 uVar4;
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
  *(undefined4 *)(param_3 + 0x28) = 0xffffffff;
  _objc_msgSend(*(undefined4 *)(param_1 + 0x1b8),paLock);
  piVar3 = (int *)(param_1 + 0x1b0);
  if (*(int *)(param_3 + 0x20) < 0) {
    piVar3 = (int *)(param_1 + 0x1a8);
  }
  if (piVar3 == (int *)*piVar3) {
    *piVar3 = param_3;
    piVar3[1] = param_3;
    *(int **)(param_3 + 0x2c) = piVar3;
    *(int **)(param_3 + 0x30) = piVar3;
  }
  else {
    iVar2 = piVar3[1];
    *(int *)(param_3 + 0x30) = iVar2;
    *(int **)(param_3 + 0x2c) = piVar3;
    piVar3[1] = param_3;
    *(int *)(iVar2 + 0x2c) = param_3;
  }
  uVar1 = paUnlockwith;
  _objc_msgSend(*(undefined4 *)(param_1 + 0x1b8),paUnlockwith,1);
  uVar4 = 0;
  if (*(int *)(param_3 + 0x18) == 0) {
    _objc_msgSend(*(undefined4 *)(param_3 + 0x1c),paLockwhen,1);
    _objc_msgSend(*(undefined4 *)(param_3 + 0x1c),uVar1,0);
    uVar4 = *(undefined4 *)(param_3 + 0x28);
  }
  return CONCAT44(param_2,uVar4);
}
/* GHIDRADEC_FUNCTION index=4481 start=0xf00cf0ec */

/* WARNING: Removing unreachable block (ram,0xf00cf11c) */
/* WARNING: Removing unreachable block (ram,0xf00cf0fc) */
/* WARNING: Removing unreachable block (ram,0xf00cf130) */
/* WARNING: Removing unreachable block (ram,0xf00cf0f0) */

undefined8 -[SCSIDisk allocSdBuf:](undefined4 param_1,undefined4 param_2,int param_3)

{
  int iVar1;
  undefined4 uVar2;
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
  iVar1 = 0x44;
  _IOMalloc();
  _bzero();
  if (param_3 == 0) {
    uVar2 = paNxconditionloc;
    _objc_msgSend(paNxconditionloc,paAlloc);
    *(undefined4 *)(iVar1 + 0x1c) = uVar2;
    _objc_msgSend();
  }
  else {
    *(int *)(iVar1 + 0x18) = param_3;
  }
  return CONCAT44(param_2,iVar1);
}
/* GHIDRADEC_FUNCTION index=4482 start=0xf00cf140 */

/* WARNING: Removing unreachable block (ram,0xf00cf168) */
/* WARNING: Removing unreachable block (ram,0xf00cf15c) */

undefined8 -[SCSIDisk freeSdBuf:](undefined4 param_1,undefined4 param_2,int param_3)

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
  if (*(int *)(param_3 + 0x18) == 0) {
    _objc_msgSend(*(undefined4 *)(param_3 + 0x1c),paFree);
  }
  _IOFree(param_3,0x44);
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=4483 start=0xf00cf178 */

/* WARNING: Removing unreachable block (ram,0xf00cf8b4) */
/* WARNING: Removing unreachable block (ram,0xf00cf6d4) */
/* WARNING: Removing unreachable block (ram,0xf00cf29c) */
/* WARNING: Removing unreachable block (ram,0xf00cf814) */
/* WARNING: Removing unreachable block (ram,0xf00cf32c) */
/* WARNING: Removing unreachable block (ram,0xf00cf244) */
/* WARNING: Removing unreachable block (ram,0xf00cf3c8) */
/* WARNING: Removing unreachable block (ram,0xf00cf754) */
/* WARNING: Removing unreachable block (ram,0xf00cf668) */
/* WARNING: Removing unreachable block (ram,0xf00cf5f4) */
/* WARNING: Removing unreachable block (ram,0xf00cf798) */
/* WARNING: Removing unreachable block (ram,0xf00cf558) */
/* WARNING: Removing unreachable block (ram,0xf00cf7c8) */
/* WARNING: Removing unreachable block (ram,0xf00cf508) */
/* WARNING: Removing unreachable block (ram,0xf00cf58c) */
/* WARNING: Removing unreachable block (ram,0xf00cf5a4) */
/* WARNING: Removing unreachable block (ram,0xf00cf42c) */
/* WARNING: Removing unreachable block (ram,0xf00cf610) */
/* WARNING: Removing unreachable block (ram,0xf00cf21c) */
/* WARNING: Removing unreachable block (ram,0xf00cf1e8) */
/* WARNING: Removing unreachable block (ram,0xf00cf40c) */
/* WARNING: Removing unreachable block (ram,0xf00cf628) */
/* WARNING: Removing unreachable block (ram,0xf00cf444) */
/* WARNING: Removing unreachable block (ram,0xf00cf5bc) */
/* WARNING: Removing unreachable block (ram,0xf00cf4f4) */
/* WARNING: Removing unreachable block (ram,0xf00cf510) */
/* WARNING: Removing unreachable block (ram,0xf00cf544) */
/* WARNING: Removing unreachable block (ram,0xf00cf788) */
/* WARNING: Removing unreachable block (ram,0xf00cf5e0) */
/* WARNING: Removing unreachable block (ram,0xf00cf654) */
/* WARNING: Removing unreachable block (ram,0xf00cf744) */
/* WARNING: Removing unreachable block (ram,0xf00cf3b4) */
/* WARNING: Removing unreachable block (ram,0xf00cf7e0) */
/* WARNING: Removing unreachable block (ram,0xf00cf254) */
/* WARNING: Removing unreachable block (ram,0xf00cf7f8) */
/* WARNING: Removing unreachable block (ram,0xf00cf284) */
/* WARNING: Removing unreachable block (ram,0xf00cf680) */
/* WARNING: Removing unreachable block (ram,0xf00cf834) */
/* WARNING: Removing unreachable block (ram,0xf00cf900) */
/* WARNING: Removing unreachable block (ram,0xf00cf188) */
/* WARNING: Heritage AFTER dead removal. Example location: o1 : 0xf00cf1e8 */
/* WARNING: Removing unreachable block (ram,0xf00cf35c) */
/* WARNING: Removing unreachable block (ram,0xf00cf64c) */
/* WARNING: Removing unreachable block (ram,0xf00cf37c) */
/* WARNING: Removing unreachable block (ram,0xf00cf388) */
/* WARNING: Removing unreachable block (ram,0xf00cf390) */
/* WARNING: Removing unreachable block (ram,0xf00cf398) */
/* WARNING: Removing unreachable block (ram,0xf00cf228) */
/* WARNING: Removing unreachable block (ram,0xf00cf34c) */
/* WARNING: Removing unreachable block (ram,0xf00cf354) */
/* WARNING: Removing unreachable block (ram,0xf00cf364) */
/* WARNING: Removing unreachable block (ram,0xf00cf638) */
/* WARNING: Removing unreachable block (ram,0xf00cf440) */
/* WARNING: Removing unreachable block (ram,0xf00cf36c) */
/* WARNING: Removing unreachable block (ram,0xf00cf374) */
/* WARNING: Removing unreachable block (ram,0xf00cf3dc) */
/* WARNING: Removing unreachable block (ram,0xf00cf3e8) */
/* WARNING: Removing unreachable block (ram,0xf00cf3f0) */
/* WARNING: Removing unreachable block (ram,0xf00cf7c0) */
/* WARNING: Removing unreachable block (ram,0xf00cf404) */
/* WARNING: Removing unreachable block (ram,0xf00cf60c) */
/* WARNING: Removing unreachable block (ram,0xf00cf418) */
/* WARNING: Removing unreachable block (ram,0xf00cf454) */
/* WARNING: Removing unreachable block (ram,0xf00cf424) */
/* WARNING: Removing unreachable block (ram,0xf00cf488) */
/* WARNING: Removing unreachable block (ram,0xf00cf4a0) */
/* WARNING: Removing unreachable block (ram,0xf00cf59c) */
/* WARNING: Removing unreachable block (ram,0xf00cf570) */
/* WARNING: Removing unreachable block (ram,0xf00cf584) */
/* WARNING: Removing unreachable block (ram,0xf00cf674) */
/* WARNING: Removing unreachable block (ram,0xf00cf764) */
/* WARNING: Removing unreachable block (ram,0xf00cf5cc) */
/* WARNING: Removing unreachable block (ram,0xf00cf4d8) */
/* WARNING: Removing unreachable block (ram,0xf00cf4ec) */
/* WARNING: Removing unreachable block (ram,0xf00cf7b4) */
/* WARNING: Removing unreachable block (ram,0xf00cf520) */
/* WARNING: Removing unreachable block (ram,0xf00cf534) */
/* WARNING: Removing unreachable block (ram,0xf00cf67c) */
/* WARNING: Removing unreachable block (ram,0xf00cf770) */
/* WARNING: Removing unreachable block (ram,0xf00cf498) */
/* WARNING: Removing unreachable block (ram,0xf00cf5d0) */
/* WARNING: Removing unreachable block (ram,0xf00cf3a0) */
/* WARNING: Removing unreachable block (ram,0xf00cf3a4) */
/* WARNING: Removing unreachable block (ram,0xf00cf63c) */
/* WARNING: Removing unreachable block (ram,0xf00cf734) */
/* WARNING: Removing unreachable block (ram,0xf00cf7d4) */
/* WARNING: Removing unreachable block (ram,0xf00cf3ac) */
/* WARNING: Removing unreachable block (ram,0xf00cf3b0) */
/* WARNING: Removing unreachable block (ram,0xf00cf7dc) */
/* WARNING: Recovered jumptable eliminated as dead code */
/* WARNING: Removing unreachable block (ram,0xf00cf6ec) */
/* WARNING: Removing unreachable block (ram,0xf00cf6f4) */
/* WARNING: Restarted to delay deadcode elimination for space: register */

int -[SCSIDisk doSdBuf:](uint *param_1)

{
  undefined8 uVar1;
  int iVar2;
  uint uVar3;
  qword in_o0_1;
  int iVar4;
  undefined4 uVar5;
  undefined4 unaff_l0;
  uint uVar6;
  undefined4 unaff_l1;
  int iVar7;
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
  bool bVar8;
  bool in_DECOMPILE_MODE;
  int in_CWP;
  undefined auStackX_0 [92];
  
  iVar2 = (int)(in_o0_1 >> 0x20);
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
  iVar7 = 100;
  _objc_msgSend(iVar2);
  param_1[0xd] = 10;
  param_1[0xe] = 5;
  param_1[0xf] = 10;
  if (param_1[0xd] == 0) {
loc_F00CF6FC:
    iVar7 = 100;
  }
  else if (param_1[0xe] != 0) {
    if (iVar2 == 0) goto loc_F00CF6FC;
    uVar5 = (undefined4)in_o0_1;
    _objc_msgSend(iVar2,uVar5,param_1,(undefined *)((int)register0x00000038 + -0x70));
    if (iVar2 != 0) {
      return iVar2;
    }
    *(uint *)((int)register0x00000038 + -0x90) =
         *(uint *)((int)register0x00000038 + -0x90) & 0x7fffffff;
    _objc_msgSend(uRam00000184,uVar5,(undefined *)((int)register0x00000038 + -0x70),param_1[3],
                  param_1[4]);
    iVar7 = 0;
    if (*param_1 < 2) {
      _objc_msgSend(0);
      .umul(param_1[2]);
      if (*(int *)((int)register0x00000038 + -0x48) != 0) {
        uVar6 = param_1[0xe];
        param_1[0xe] = uVar6 - 1;
        if ((int)(uVar6 - 1) < 1) {
          _IOLog(aSTransferCount);
          iVar7 = 0xf;
          _objc_msgSend(0,uVar5,param_1,(undefined *)((int)register0x00000038 + -0x90));
        }
        else {
          .umul(param_1[2]);
          _IOLog(aSTransferCount_0,uVar5,0,param_1[9]);
          _objc_msgSend(0,uVar5,param_1,0);
          if ((in_o0_1 & 0x4000) != 0) {
            _objc_msgSend(0);
          }
        }
        goto loc_F00CF700;
      }
      in_o0_1 = (qword)uRam00000188;
    }
    else {
      in_o0_1 = CONCAT44(&paLock,uRam00000188);
    }
    if ((in_o0_1 & 0x4000) != 0) {
      if (*param_1 == 0) {
        uVar5 = *(undefined4 *)((int)register0x00000038 + -0x48);
        uVar1 = *(undefined8 *)((int)register0x00000038 + -0x40);
      }
      else {
        uVar5 = *(undefined4 *)((int)register0x00000038 + -0x48);
        if (*param_1 != 1) goto loc_F00CF700;
        uVar1 = *(undefined8 *)((int)register0x00000038 + -0x40);
      }
      _objc_msgSend(0,(int)in_o0_1,uVar5,(int)((qword)uVar1 >> 0x20),(int)uVar1);
    }
  }
loc_F00CF700:
  uVar3 = (uint)(in_o0_1 >> 0x20);
  uVar6 = 0xfffffd36;
  iVar4 = (int)in_o0_1;
  if (uVar3 != 0) {
    bVar8 = false;
    if (param_1[0xe] == 0) goto loc_F00CF84C;
    if (param_1[0xf] == 0) {
      bVar8 = false;
      goto loc_F00CF84C;
    }
    if (iVar7 == 0) {
      uVar6 = 0;
    }
    else {
      _objc_msgSend(*(undefined4 *)(iVar2 + 0x184),iVar4,iVar7);
      uVar6 = uVar3;
    }
  }
  bVar8 = uVar6 == 0;
loc_F00CF84C:
  if (((!bVar8) && ((*(uint *)(iVar2 + 0x188) & 0x4000) != 0)) &&
     ((*param_1 == 0 || ((*param_1 == 1 || ((param_1[8] & 0x40000000) == 0)))))) {
    _objc_msgSend(iVar2);
  }
  if (iVar4 != 0) {
    *(undefined4 *)(iVar4 + 0x20) = *(undefined4 *)((int)register0x00000038 + -0x50);
    *(undefined *)(param_1[5] + 0x24) = *(undefined *)((int)register0x00000038 + -0x4c);
    *(undefined4 *)(param_1[5] + 0x28) = *(undefined4 *)((int)register0x00000038 + -0x48);
  }
  param_1[9] = *(uint *)((int)register0x00000038 + -0x48);
  param_1[10] = uVar6;
  _objc_msgSend();
  return iVar2;
}
/* GHIDRADEC_FUNCTION index=4484 start=0xf00cfa74 */

/* WARNING: Removing unreachable block (ram,0xf00cfcfc) */
/* WARNING: Removing unreachable block (ram,0xf00cfc98) */
/* WARNING: Removing unreachable block (ram,0xf00cfc64) */
/* WARNING: Removing unreachable block (ram,0xf00cfc34) */
/* WARNING: Removing unreachable block (ram,0xf00cfc00) */
/* WARNING: Removing unreachable block (ram,0xf00cfce0) */
/* WARNING: Removing unreachable block (ram,0xf00cfcc0) */
/* WARNING: Removing unreachable block (ram,0xf00cfb20) */
/* WARNING: Removing unreachable block (ram,0xf00cfb34) */
/* WARNING: Removing unreachable block (ram,0xf00cfcd8) */
/* WARNING: Removing unreachable block (ram,0xf00cfbdc) */
/* WARNING: Removing unreachable block (ram,0xf00cfc0c) */
/* WARNING: Removing unreachable block (ram,0xf00cfc50) */
/* WARNING: Removing unreachable block (ram,0xf00cfc84) */
/* WARNING: Removing unreachable block (ram,0xf00cfca8) */
/* WARNING: Removing unreachable block (ram,0xf00cfd18) */
/* WARNING: Removing unreachable block (ram,0xf00cfaf0) */
/* WARNING: Removing unreachable block (ram,0xf00cfaa0) */

undefined8 sub_F00CFA74(int param_1,uint param_2)

{
  undefined7 *puVar1;
  undefined4 uVar2;
  int *piVar3;
  int *piVar4;
  int *piVar5;
  int *piVar6;
  int *piVar7;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  int iVar8;
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
  piVar7 = (int *)(param_1 + 0x1a8);
  if ((param_2 & 0xff) == 0) {
    piVar7 = (int *)(param_1 + 0x1b0);
  }
  piVar5 = (int *)*piVar7;
  if (piVar7 == piVar5) {
    _IOLog(aSdthreaddequeu);
    goto locret_F00CFD20;
  }
  piVar6 = (int *)piVar5[0xb];
  piVar4 = (int *)piVar5[0xc];
  piVar3 = piVar7;
  if (piVar7 != piVar6) {
    piVar3 = piVar6 + 0xb;
  }
  piVar3[1] = (int)piVar4;
  if (piVar7 != piVar4) {
    piVar7 = piVar4 + 0xb;
  }
  *piVar7 = (int)piVar6;
  if ((param_2 & 0xff) != 0) {
    _objc_msgSend(*(undefined4 *)(param_1 + 0x1c0),paLock);
    *(int *)(param_1 + 0x1c4) = *(int *)(param_1 + 0x1c4) + 1;
    if (*piVar5 == 4) {
      *(undefined *)(param_1 + 0x1c8) = 1;
      _volCheckEjecting(param_1,2);
      uVar2 = *(undefined4 *)(param_1 + 0x1c0);
    }
    else {
      uVar2 = *(undefined4 *)(param_1 + 0x1c0);
    }
    _objc_msgSend(uVar2,paUnlockwith,*(undefined4 *)(param_1 + 0x1c4));
  }
  puVar1 = paUnlock;
  switch(*piVar5) {
  case :
  case :
  case :
  case :
    uVar2 = *(undefined4 *)(param_1 + 0x1b8);
    goto loc_F00CFC84;
  case :
    _objc_msgSend(*(undefined4 *)(param_1 + 0x1b8),paUnlock);
    _objc_msgSend(*(undefined4 *)(param_1 + 0x1c0),paLockwhen,1);
    uVar2 = *(undefined4 *)(param_1 + 0x1c0);
loc_F00CFC84:
    _objc_msgSend(uVar2,puVar1);
    _objc_msgSend(param_1,paDosdbuf,piVar5);
    _objc_msgSend(*(undefined4 *)(param_1 + 0x1b8),paLock);
    break;
  case :
    piVar7 = (int *)(param_1 + 0x1a8);
    if (piVar7 != *(int **)(param_1 + 0x1a8)) {
      iVar8 = *piVar7;
      while( true ) {
        piVar6 = *(int **)(iVar8 + 0x2c);
        piVar4 = *(int **)(iVar8 + 0x30);
        piVar3 = piVar7;
        if (piVar7 != piVar6) {
          piVar3 = piVar6 + 0xb;
        }
        piVar3[1] = (int)piVar4;
        piVar3 = piVar7;
        if (piVar7 != piVar4) {
          piVar3 = piVar4 + 0xb;
        }
        *piVar3 = (int)piVar6;
        _objc_msgSend(*(undefined4 *)(param_1 + 0x1b8),paUnlock);
        *(undefined4 *)(iVar8 + 0x28) = 0xfffffbb2;
        if (*(int *)(iVar8 + 0x14) != 0) {
          *(undefined4 *)(*(int *)(iVar8 + 0x14) + 0x20) = 0x10;
        }
        _objc_msgSend(param_1,paSdiocomplete,iVar8);
        _objc_msgSend(*(undefined4 *)(param_1 + 0x1b8),paLock);
        if (piVar7 == (int *)*piVar7) break;
        iVar8 = *piVar7;
      }
    }
  case :
    piVar5[10] = 0;
    _objc_msgSend(param_1,paSdiocomplete,piVar5);
    break;
  case :
    _objc_msgSend(*(undefined4 *)(param_1 + 0x1b8),paUnlock);
    piVar5[10] = 0;
    _objc_msgSend(param_1,paSdiocomplete,piVar5);
    _IOExitThread();
  }
  if ((param_2 & 0xff) != 0) {
    _objc_msgSend(*(undefined4 *)(param_1 + 0x1c0),paLock);
    uVar2 = paUnlockwith;
    *(int *)(param_1 + 0x1c4) = *(int *)(param_1 + 0x1c4) + -1;
    _objc_msgSend(*(undefined4 *)(param_1 + 0x1c0),uVar2);
  }
locret_F00CFD20:
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=4485 start=0xf00cfd28 */

/* WARNING: Removing unreachable block (ram,0xf00cfdd0) */
/* WARNING: Removing unreachable block (ram,0xf00cfe18) */
/* WARNING: Removing unreachable block (ram,0xf00cfe0c) */
/* WARNING: Removing unreachable block (ram,0xf00cfdec) */
/* WARNING: Removing unreachable block (ram,0xf00cfe64) */
/* WARNING: Removing unreachable block (ram,0xf00cfe48) */

undefined8
-[SCSIDisk logOpInfo:sense:](int param_1,undefined4 param_2,undefined4 *param_3,int *param_4)

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
  *(undefined *)((int)register0x00000038 + -0x88) = 0;
  switch(*param_3) {
  case :
    *(undefined4 *)((int)register0x00000038 + -0x38) = 0x52656164;
    *(undefined *)((int)register0x00000038 + -0x34) = 0;
    goto loc_F00CFD9C;
  case :
    *(undefined4 *)((int)register0x00000038 + -0x38) = 0x57726974;
    *(undefined2 *)((int)register0x00000038 + -0x34) = 0x6500;
loc_F00CFD9C:
    if ((param_4 == (int *)0x0) || (-1 < *param_4)) {
      _sprintf((undefined *)((int)register0x00000038 + -0x88),aBlockDBlockcou,param_3[1],param_3[2])
      ;
    }
    else {
      _sprintf((undefined *)((int)register0x00000038 + -0x88),aBlockD,
               (uint)(byte)*param_4 << 0x18 | (uint)param_4[1] >> 8);
    }
    break;
  case :
  case :
    uVar1 = (uint)*(byte *)(param_3[5] + 4);
    _IOFindNameForValue(uVar1,_IOSCSIOpcodeStrings);
    _strcpy((undefined *)((int)register0x00000038 + -0x38),uVar1);
    break;
  case :
    *(undefined4 *)((int)register0x00000038 + -0x38) = 0x456a6563;
    *(undefined2 *)((int)register0x00000038 + -0x34) = 0x7400;
    break;
  :
    _panic(aBogusOpInLogop);
  }
  _IOLog(aTargetDLunDOpS,*(undefined *)(param_1 + 0x188),*(undefined *)(param_1 + 0x189),
         (undefined *)((int)register0x00000038 + -0x38),
         (undefined *)((int)register0x00000038 + -0x88));
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=4486 start=0xf00cfe74 */

/* WARNING: Removing unreachable block (ram,0xf00cfec4) */

undefined8
-[SCSIDisk genRwCdb:readFlag:block:blockCnt:]
          (int param_1,undefined4 param_2,undefined *param_3,uint param_4,undefined4 param_5,
          undefined2 param_6)

{
  char cVar1;
  undefined uVar2;
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
  if ((param_4 & 0xff) == 0) {
    uVar2 = 0x2a;
  }
  else {
    uVar2 = 0x28;
  }
  cVar1 = *(char *)(param_1 + 0x189);
  *(undefined4 *)((int)register0x00000038 + -0x20) = param_5;
  *param_3 = uVar2;
  param_3[1] = param_3[1] & 0x1f | cVar1 << 5;
  _bcopy((undefined *)((int)register0x00000038 + -0x20),param_3 + 2,4);
  param_3[7] = (char)((word)param_6 >> 8);
  param_3[8] = (char)param_6;
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=4487 start=0xf00cfee4 */

/* WARNING: Removing unreachable block (ram,0xf00cff78) */
/* WARNING: Removing unreachable block (ram,0xf00cff00) */
/* WARNING: Removing unreachable block (ram,0xf00cffe8) */
/* WARNING: Removing unreachable block (ram,0xf00cff88) */
/* WARNING: Removing unreachable block (ram,0xf00cfef0) */
/* WARNING: Heritage AFTER dead removal. Example location: o1 : 0xf00cffe8 */
/* WARNING: Restarted to delay deadcode elimination for space: register */

undefined4 -[SCSIDisk setupScsiReq:scsiReq:](uint *param_1,undefined8 *param_2)

{
  int iVar1;
  uint uVar2;
  undefined8 in_o0_1;
  qword qVar3;
  int iVar4;
  undefined8 *puVar5;
  undefined4 uVar6;
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
  
  iVar1 = (int)((qword)in_o0_1 >> 0x20);
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
  _objc_msgSend(iVar1);
  _bzero(param_2);
  *(undefined *)param_2 = *(undefined *)(iVar1 + 0x188);
  *(undefined *)((int)param_2 + 1) = *(undefined *)(iVar1 + 0x189);
  uVar2 = *param_1;
  if (uVar2 == 1) {
    *(undefined *)(param_2 + 2) = 0;
    uVar2 = param_1[1];
    uVar6 = 0;
  }
  else {
    if (3 < uVar2) {
      if (4 < uVar2) {
        return 0;
      }
      puVar5 = (undefined8 *)param_1[5];
      qVar3 = CONCAT44(*(undefined4 *)puVar5,*(undefined4 *)(iVar1 + 0x188)) & 0xffff0000ffff0000;
      iVar4 = (int)qVar3;
      if ((int)(qVar3 >> 0x20) == iVar4) {
        *param_2 = *puVar5;
        param_2[1] = puVar5[1];
        param_2[2] = puVar5[2];
        param_2[3] = puVar5[3];
        param_2[4] = puVar5[4];
        param_2[5] = puVar5[5];
        param_2[6] = puVar5[6];
        param_2[7] = puVar5[7];
        param_2[8] = puVar5[8];
        param_2[9] = puVar5[9];
        param_2[10] = puVar5[10];
        param_2[0xb] = puVar5[0xb];
        return 0;
      }
      *(undefined4 *)(puVar5 + 4) = 7;
      param_1[10] = 0xfffffd3e;
      _objc_msgSend(iVar1,iVar4,param_1);
      return 7;
    }
    *(undefined *)(param_2 + 2) = 1;
    uVar2 = param_1[1];
    uVar6 = 1;
  }
  _objc_msgSend(iVar1,(int)in_o0_1,(undefined *)((int)param_2 + 4),uVar6,uVar2,param_1[2]);
  param_1[5] = 0;
  .umul(param_1[2]);
  *(int *)((int)param_2 + 0x14) = iVar1;
  *(undefined4 *)(param_2 + 3) = 0x1e;
  *(uint *)((int)param_2 + 0x1c) = *(uint *)((int)param_2 + 0x1c) | 0x80000000;
  return 0;
}
/* GHIDRADEC_FUNCTION index=4488 start=0xf00d0064 */

/* WARNING: Removing unreachable block (ram,0xf00d0154) */
/* WARNING: Removing unreachable block (ram,0xf00d00ec) */
/* WARNING: Removing unreachable block (ram,0xf00d0090) */
/* WARNING: Removing unreachable block (ram,0xf00d013c) */
/* WARNING: Removing unreachable block (ram,0xf00d019c) */
/* WARNING: Removing unreachable block (ram,0xf00d0080) */

undefined8 -[SCSIDisk reqSense:](int param_1,undefined4 param_2,undefined4 *param_3)

{
  undefined4 *puVar1;
  undefined (**ppauVar2) [23];
  undefined4 uVar3;
  uint uVar4;
  undefined4 uVar5;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 uVar6;
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
  puVar1 = *(undefined4 **)(param_1 + 0x184);
  _objc_msgSend(puVar1,paAllocatebuffer,0x1c,(undefined *)((int)register0x00000038 + -0x84),
                (undefined *)((int)register0x00000038 + -0x88));
  _bzero((undefined *)((int)register0x00000038 + -0x70),0x60);
  *(undefined *)((int)register0x00000038 + -0x6c) = 3;
  *(uint *)((int)register0x00000038 + -0x6c) =
       *(uint *)((int)register0x00000038 + -0x6c) & 0xff1fffff |
       (*(byte *)(param_1 + 0x189) & 7) << 0x15;
  *(undefined *)((int)register0x00000038 + -0x68) = 0x1c;
  *(undefined *)((int)register0x00000038 + -0x70) = *(undefined *)(param_1 + 0x188);
  *(undefined *)((int)register0x00000038 + -0x6f) = *(undefined *)(param_1 + 0x189);
  *(undefined *)((int)register0x00000038 + -0x60) = 1;
  _objc_msgSend(*(undefined4 *)(param_1 + 0x184),paGetdmaalignmen,
                (undefined *)((int)register0x00000038 + -0x80));
  uVar3 = paExecuterequest_0;
  uVar4 = *(uint *)((int)register0x00000038 + -0x78);
  if (uVar4 < 2) {
    uVar4 = 0x1c;
  }
  else {
    uVar4 = uVar4 + 0x1b & -uVar4;
  }
  *(uint *)((int)register0x00000038 + -0x5c) = uVar4;
  *(undefined4 *)((int)register0x00000038 + -0x58) = 0x14;
  *(uint *)((int)register0x00000038 + -0x54) =
       *(uint *)((int)register0x00000038 + -0x54) | 0x80000000;
  uVar6 = *(undefined4 *)(param_1 + 0x184);
  ppauVar2 = &paBytesprocessed_0;
  _IOVmTaskSelf();
  _objc_msgSend(uVar6,uVar3,(undefined *)((int)register0x00000038 + -0x70),puVar1,ppauVar2);
  *param_3 = *puVar1;
  param_3[1] = puVar1[1];
  param_3[2] = puVar1[2];
  param_3[3] = puVar1[3];
  param_3[4] = puVar1[4];
  uVar3 = *(undefined4 *)((int)register0x00000038 + -0x84);
  param_3[5] = puVar1[5];
  uVar5 = *(undefined4 *)((int)register0x00000038 + -0x88);
  param_3[6] = puVar1[6];
  _IOFree(uVar3,uVar5);
  return CONCAT44(param_2,uVar6);
}
/* GHIDRADEC_FUNCTION index=4489 start=0xf00d01ac */

/* WARNING: Removing unreachable block (ram,0xf00d01cc) */
/* WARNING: Removing unreachable block (ram,0xf00d01e0) */
/* WARNING: Removing unreachable block (ram,0xf00d01f8) */

undefined8 -[SCSIDisk sdIoComplete:](undefined4 param_1,undefined4 param_2,int param_3)

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
  if (*(int *)(param_3 + 0x18) == 0) {
    _objc_msgSend(*(undefined4 *)(param_3 + 0x1c),paUnlockwith,1);
  }
  else {
    _objc_msgSend(param_1,paCompletetransf,*(int *)(param_3 + 0x18),*(undefined4 *)(param_3 + 0x28),
                  *(undefined4 *)(param_3 + 0x24));
    _objc_msgSend(param_1,paFreesdbuf,param_3);
  }
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=4490 start=0xf00d0208 */

/* WARNING: Removing unreachable block (ram,0xf00d0278) */
/* WARNING: Removing unreachable block (ram,0xf00d028c) */
/* WARNING: Removing unreachable block (ram,0xf00d0214) */

undefined8 -[SCSIDisk unlockIoQLock](int param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 unaff_l0;
  int iVar3;
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
  iVar1 = param_1;
  _objc_msgSend(param_1,paLastreadystate_0);
  if (param_1 + 0x1b0 == *(int *)(param_1 + 0x1b0)) {
    if (param_1 + 0x1a8 == *(int *)(param_1 + 0x1a8)) {
      iVar3 = 0;
    }
    else {
      iVar3 = 0;
      if (1 < iVar1 - 2U) {
        if (*(char *)(param_1 + 0x1c8) != '\0') {
          uVar2 = *(undefined4 *)(param_1 + 0x1b8);
          goto loc_F00D0270;
        }
        goto loc_F00D0260;
      }
    }
  }
  else {
loc_F00D0260:
    iVar3 = 1;
  }
  uVar2 = *(undefined4 *)(param_1 + 0x1b8);
loc_F00D0270:
  _objc_msgSend(uVar2,paUnlockwith,iVar3);
  if (iVar3 == 1) {
    _thread_block();
  }
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=4491 start=0xf00d029c */

undefined8 +[SCSIGeneric deviceStyle](undefined4 param_1,undefined4 param_2)

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
  return CONCAT44(param_2,1);
}
/* GHIDRADEC_FUNCTION index=4492 start=0xf00d02a8 */

undefined8 +[SCSIGeneric requiredProtocols](undefined4 param_1,undefined4 param_2)

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
  return CONCAT44(param_2,&unk_F012ECF8);
}
/* GHIDRADEC_FUNCTION index=4493 start=0xf00d02bc */

/* WARNING: Removing unreachable block (ram,0xf00d030c) */
/* WARNING: Removing unreachable block (ram,0xf00d02d8) */
/* WARNING: Removing unreachable block (ram,0xf00d0328) */
/* WARNING: Removing unreachable block (ram,0xf00d02c8) */

undefined8 +[SCSIGeneric probe:](undefined4 param_1,undefined4 param_2,int param_3)

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
  undefined4 uVar2;
  undefined4 unaff_i1;
  undefined4 unaff_i2;
  int iVar3;
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
  _objc_msgSend(param_3,paDirectdevice);
  _objc_msgSend();
  iVar3 = 0;
  if (param_3 == 0) {
    iVar1 = 0;
    do {
      uVar2 = param_1;
      _objc_msgSend(param_1,paAlloc);
      *(undefined4 *)(_sgIdMap + iVar1) = uVar2;
      iVar1 = iVar1 + 4;
      iVar3 = iVar3 + 1;
      _objc_msgSend();
    } while (iVar3 < 4);
    uVar2 = 1;
  }
  else {
    uVar2 = 0;
  }
  return CONCAT44(param_2,uVar2);
}
/* GHIDRADEC_FUNCTION index=4494 start=0xf00d0348 */

/* WARNING: Removing unreachable block (ram,0xf00d040c) */
/* WARNING: Removing unreachable block (ram,0xf00d03e8) */
/* WARNING: Removing unreachable block (ram,0xf00d03b8) */
/* WARNING: Removing unreachable block (ram,0xf00d03a4) */
/* WARNING: Removing unreachable block (ram,0xf00d03d0) */
/* WARNING: Removing unreachable block (ram,0xf00d03f8) */
/* WARNING: Removing unreachable block (ram,0xf00d041c) */
/* WARNING: Removing unreachable block (ram,0xf00d0384) */

sqword -[SCSIGeneric sgInit:controller:]
                 (int param_1,uint param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  undefined7 *puVar3;
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
  *(undefined4 *)(param_1 + 0x128) = param_4;
  *(undefined4 *)(param_1 + 0x118) = 0;
  *(undefined4 *)(param_1 + 0x120) = 0;
  puVar3 = paNxlock;
  puVar1 = paNew;
  *(uint *)(param_1 + 0x11c) = *(uint *)(param_1 + 0x11c) & 0x7fffffff;
  *(uint *)(param_1 + 0x124) = *(uint *)(param_1 + 0x124) & 0x7fffffff;
  _objc_msgSend(puVar3,puVar1);
  *(undefined7 **)(param_1 + 300) = puVar3;
  *(undefined4 *)(param_1 + 0x130) = 0;
  _sprintf((undefined *)((int)register0x00000038 + -0x28),&aSgD,param_3);
  _objc_msgSend(param_1,paSetname,(undefined *)((int)register0x00000038 + -0x28));
  _objc_msgSend(param_1,paSetdevicekind,aScsigeneric);
  uVar2 = paSetlocation;
  _objc_msgSend(param_4,paName);
  _objc_msgSend(param_1,uVar2,param_4);
  _objc_msgSend(param_1,paSetunit,param_3);
  _objc_msgSend(param_1,paRegisterdevice);
  return (qword)param_2 << 0x20;
}
/* GHIDRADEC_FUNCTION index=4495 start=0xf00d042c */

undefined8 -[SCSIGeneric target](int param_1,undefined4 param_2)

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
  return CONCAT44(param_2,(uint)*(byte *)(param_1 + 0x10f));
}
/* GHIDRADEC_FUNCTION index=4496 start=0xf00d043c */

undefined8 -[SCSIGeneric lun](int param_1,undefined4 param_2)

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
  return CONCAT44(param_2,(uint)*(byte *)(param_1 + 0x117));
}
/* GHIDRADEC_FUNCTION index=4497 start=0xf00d044c */

undefined8 -[SCSIGeneric SCSI3_target](int param_1)

{
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined8 in_i0_1;
  undefined4 unaff_i2;
  undefined4 unaff_i3;
  undefined4 unaff_i4;
  undefined4 unaff_i5;
  undefined4 unaff_fp;
  undefined4 unaff_i7;
  bool in_DECOMPILE_MODE;
  int in_CWP;
  
  if (!in_DECOMPILE_MODE) {
    *(int *)(in_CWP * 0x40 + 0x8000) = (int)((qword)in_i0_1 >> 0x20);
    *(int *)((in_CWP * 0x10 + 1) * 4 + 0x8000) = (int)in_i0_1;
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
  return CONCAT44((int)*(undefined8 *)(param_1 + 0x108),
                  (int)((qword)*(undefined8 *)(param_1 + 0x108) >> 0x20));
}
/* GHIDRADEC_FUNCTION index=4498 start=0xf00d045c */

undefined8 -[SCSIGeneric SCSI3_lun](int param_1)

{
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined8 in_i0_1;
  undefined4 unaff_i2;
  undefined4 unaff_i3;
  undefined4 unaff_i4;
  undefined4 unaff_i5;
  undefined4 unaff_fp;
  undefined4 unaff_i7;
  bool in_DECOMPILE_MODE;
  int in_CWP;
  
  if (!in_DECOMPILE_MODE) {
    *(int *)(in_CWP * 0x40 + 0x8000) = (int)((qword)in_i0_1 >> 0x20);
    *(int *)((in_CWP * 0x10 + 1) * 4 + 0x8000) = (int)in_i0_1;
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
  return CONCAT44((int)*(undefined8 *)(param_1 + 0x110),
                  (int)((qword)*(undefined8 *)(param_1 + 0x110) >> 0x20));
}
/* GHIDRADEC_FUNCTION index=4499 start=0xf00d046c */

/* WARNING: Removing unreachable block (ram,0xf00d04b4) */
/* WARNING: Removing unreachable block (ram,0xf00d0478) */

undefined8 -[SCSIGeneric acquire:](int param_1,undefined4 param_2,undefined4 param_3)

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
  bool bVar1;
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
  _objc_msgSend(*(undefined4 *)(param_1 + 300),paLock);
  bVar1 = *(int *)(param_1 + 0x130) != 0;
  if (!bVar1) {
    *(undefined4 *)(param_1 + 0x130) = param_3;
    *(uint *)(param_1 + 0x11c) = *(uint *)(param_1 + 0x11c) & 0x7fffffff;
  }
  _objc_msgSend(*(undefined4 *)(param_1 + 300),paUnlock);
  return CONCAT44(param_2,(uint)bVar1);
}

