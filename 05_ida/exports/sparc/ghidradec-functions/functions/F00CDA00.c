
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
