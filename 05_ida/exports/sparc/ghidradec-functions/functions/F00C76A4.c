
/* WARNING: Removing unreachable block (ram,0xf00c795c) */
/* WARNING: Removing unreachable block (ram,0xf00c77b0) */
/* WARNING: Removing unreachable block (ram,0xf00c7874) */
/* WARNING: Removing unreachable block (ram,0xf00c78d8) */
/* WARNING: Removing unreachable block (ram,0xf00c78ac) */
/* WARNING: Removing unreachable block (ram,0xf00c7850) */
/* WARNING: Removing unreachable block (ram,0xf00c7834) */
/* WARNING: Removing unreachable block (ram,0xf00c7808) */
/* WARNING: Removing unreachable block (ram,0xf00c77d8) */
/* WARNING: Removing unreachable block (ram,0xf00c7718) */
/* WARNING: Removing unreachable block (ram,0xf00c76f0) */
/* WARNING: Removing unreachable block (ram,0xf00c76d4) */
/* WARNING: Removing unreachable block (ram,0xf00c7708) */
/* WARNING: Removing unreachable block (ram,0xf00c7738) */
/* WARNING: Removing unreachable block (ram,0xf00c77fc) */
/* WARNING: Removing unreachable block (ram,0xf00c7824) */
/* WARNING: Removing unreachable block (ram,0xf00c7840) */
/* WARNING: Removing unreachable block (ram,0xf00c78b8) */
/* WARNING: Removing unreachable block (ram,0xf00c794c) */
/* WARNING: Removing unreachable block (ram,0xf00c7884) */
/* WARNING: Removing unreachable block (ram,0xf00c77bc) */
/* WARNING: Removing unreachable block (ram,0xf00c7970) */
/* WARNING: Removing unreachable block (ram,0xf00c76c0) */
/* WARNING: Heritage AFTER dead removal. Example location: o3 : 0xf00c78d8 */
/* WARNING: Restarted to delay deadcode elimination for space: register */

undefined8 -[IODiskPartition writeLabel:](uint param_1,uint param_2)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int *piVar6;
  undefined8 in_o2_3;
  undefined8 uVar7;
  undefined4 unaff_l0;
  int *piVar8;
  undefined4 unaff_l1;
  int iVar9;
  uint uVar10;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  int iVar11;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  uint uVar12;
  undefined4 unaff_i1;
  undefined4 unaff_i2;
  undefined4 unaff_i3;
  undefined4 unaff_i4;
  uint uVar13;
  undefined4 unaff_i5;
  undefined4 unaff_fp;
  undefined4 unaff_i7;
  bool in_DECOMPILE_MODE;
  int in_CWP;
  undefined auStackX_0 [92];
  
  piVar6 = (int *)((qword)in_o2_3 >> 0x20);
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
  iVar11 = 0;
  uVar10 = 0;
  uVar13 = 0;
  uVar1 = param_1;
  _objc_msgSend(param_1,paPhysicaldisk_0);
  uVar2 = param_1;
  _objc_msgSend(param_1,paPhysicalblocks_0);
  uVar12 = param_1;
  _objc_msgSend(param_1,paChecksafeconfi,aWritelabel);
  if (uVar12 != 0) goto locret_F00C7978;
  _objc_msgSend(uVar1,paLocklogicaldis);
  uVar12 = uVar1;
  _objc_msgSend(uVar1,paIsformatted);
  if ((uVar12 & 0xff) == 0) {
    uVar12 = 0xfffffd36;
  }
  else {
    _objc_msgSend(param_1,paFreepartitions);
    *(undefined *)(param_1 + 0x1a8) = 0;
    iVar5 = *piVar6;
    if ((iVar5 == 0x4e655854) || (iVar5 == 0x646c5632)) {
      param_2 = 0x1c48;
      piVar8 = piVar6 + 0x716;
      iVar5 = 0x1c46;
    }
    else {
      if (iVar5 != 0x646c5633) {
        uVar12 = 0xfffffd3e;
        _objc_msgSend(param_1,paName);
        _IOLog(aSWritelabelBad,param_1);
        goto loc_F00C7958;
      }
      param_2 = 0x230;
      piVar8 = piVar6 + 0x90;
      iVar5 = 0x22e;
    }
    _IOGetTimestamp((undefined *)((int)register0x00000038 + -0x18));
    piVar6[1] = 0;
    iVar3 = uVar2 + 0x1c47;
    uVar7 = *(undefined8 *)((int)register0x00000038 + -0x18);
    piVar6[10] = (int)uVar7;
    *(undefined2 *)piVar8 = 0;
    .udiv(iVar3,uVar2);
    iVar4 = iVar3;
    .umul();
    uVar13 = iVar4 + _page_mask & ~_page_mask;
    uVar10 = uVar13;
    _IOMalloc();
    _put_disk_label(piVar6,uVar10);
    uVar12 = uVar10;
    _checksum16(uVar10,param_2 >> 1);
    *(sword *)(uVar10 + iVar5) = (sword)uVar12;
    uVar2 = uVar10;
    _check_label(uVar10,0);
    if (uVar2 == 0) {
      iVar9 = 0;
      iVar5 = 0;
      .umul(0,iVar3);
      do {
        *(int *)(uVar10 + 4) = iVar5;
        _IOVmTaskSelf();
        uVar12 = uVar1;
        _objc_msgSend(uVar1,paWriteatLengthB,iVar5,(int)uVar7,uVar10,
                      (undefined *)((int)register0x00000038 + -0x1c));
        if ((uVar12 == 0) && (*(int *)((int)register0x00000038 + -0x1c) == iVar4)) {
          iVar11 = iVar11 + 1;
        }
        if (uVar12 == 0xfffffbb2) break;
        iVar9 = iVar9 + 1;
        iVar5 = iVar5 + iVar3;
      } while (iVar9 < 4);
      if (iVar11 == 0) {
        if (uVar12 == 0xfffffbb2) {
          uVar12 = 0xfffffbb2;
        }
        else {
          uVar12 = 0xfffffd36;
        }
      }
      else {
        *(undefined *)(param_1 + 0x1a8) = 1;
        uVar12 = 0;
        _objc_msgSend(param_1,paProbelabel,piVar6);
      }
    }
    else {
      uVar12 = 0xfffffd3e;
      _objc_msgSend(param_1,paName);
      _IOLog(aSWritelabelBad_0,param_1,uVar2);
    }
  }
loc_F00C7958:
  _objc_msgSend(uVar1,paUnlocklogicald);
  if (uVar10 != 0) {
    _IOFree(uVar10,uVar13);
  }
locret_F00C7978:
  return CONCAT44(param_2,uVar12);
}
