
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
  undefined (*pauVar2) [9];
  undefined4 unaff_l0;
  int iVar3;
  undefined4 unaff_l1;
  undefined (*pauVar4) [9];
  uint uVar5;
  int iVar6;
  undefined4 unaff_l3;
  int iVar7;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  char cVar8;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 unaff_i1;
  undefined *puVar9;
  undefined4 unaff_i2;
  uint uVar10;
  undefined4 unaff_i3;
  undefined4 uVar11;
  undefined4 unaff_i4;
  undefined4 unaff_i5;
  undefined4 unaff_fp;
  undefined4 unaff_i7;
  bool in_DECOMPILE_MODE;
  int in_CWP;
  undefined auStackX_0 [92];
  undefined4 auStack_30 [12];
  
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
  pauVar4 = (undefined (*) [9])0x0;
  _sd_idmap();
  uVar11 = 0;
  cVar8 = '\0';
  _objc_msgSend(param_3,paDirectdevice);
  puVar9 = (undefined *)((int)register0x00000038 + -8);
  do {
    iVar6 = param_3;
    _objc_msgSend(param_3,paNumberoftarget);
    iVar7 = 0;
    if (iVar6 <= cVar8) {
      if (pauVar4 != (undefined (*) [9])0x0) {
        _objc_msgSend(pauVar4,paFree);
      }
      return CONCAT44(puVar9,uVar11);
    }
    uVar5 = 0;
    do {
      if (pauVar4 == (undefined (*) [9])0x0) {
        pauVar4 = paScsidisk_0;
        _objc_msgSend(paScsidisk_0,paAlloc);
        _objc_msgSend();
        _objc_msgSend(pauVar4,paInitresources);
        _objc_msgSend(pauVar4,paSetdevandidinf,param_1 + DAT_f012ecec * 0x24);
      }
      uVar10 = uVar5 & 0xff;
      iVar6 = param_3;
      _objc_msgSend(param_3,paReservetargetL,cVar8,uVar10,pauVar4);
      if (iVar6 == 0) {
        pauVar2 = pauVar4;
        _objc_msgSend(pauVar4,paScsidiskinitTa,DAT_f012ecec,cVar8,uVar10,param_3);
        if (pauVar2 == (undefined (*) [9])0x0) {
          *(undefined (**) [9])(puVar9 + iVar7 * 4 + -0x28) = pauVar4;
          iVar7 = iVar7 + 1;
          pauVar4 = (undefined (*) [9])0x0;
          uVar11 = 1;
          DAT_f012ecec = DAT_f012ecec + 1;
        }
        else {
          _objc_msgSend(param_3,paReleasetargetL,cVar8,uVar10,pauVar4);
          if (pauVar2 == (undefined (*) [9])0x2) break;
        }
      }
      uVar5 = uVar5 + 1;
    } while ((int)(uVar5 * 0x1000000) >> 0x18 < 8);
    iVar6 = 0;
    if (0 < iVar7) {
      do {
        pauVar1 = paSetdevicekind;
        iVar3 = *(int *)(puVar9 + ((iVar6 << 0x18) >> 0x16) + -0x28);
        *(uint *)(iVar3 + 0x188) = *(uint *)(iVar3 + 0x188) | 0x8000;
        _objc_msgSend(iVar3,pauVar1,aScsidisk);
        _objc_msgSend(iVar3,paSetisphysical,1);
        _objc_msgSend(iVar3,paRegisterdevice);
        iVar6 = iVar6 + 1;
        *(uint *)(iVar3 + 0x188) = *(uint *)(iVar3 + 0x188) | 0x4000;
      } while (iVar6 * 0x1000000 >> 0x18 < iVar7);
    }
    cVar8 = cVar8 + '\x01';
  } while( true );
}

