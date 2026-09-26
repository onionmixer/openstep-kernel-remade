
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

