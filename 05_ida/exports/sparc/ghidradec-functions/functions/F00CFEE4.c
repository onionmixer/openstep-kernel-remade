
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
