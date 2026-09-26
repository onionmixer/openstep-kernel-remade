
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
