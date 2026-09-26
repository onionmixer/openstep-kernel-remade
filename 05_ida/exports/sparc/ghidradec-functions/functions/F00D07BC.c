
/* WARNING: Removing unreachable block (ram,0xf00d08f0) */
/* WARNING: Removing unreachable block (ram,0xf00d08a8) */
/* WARNING: Removing unreachable block (ram,0xf00d08d0) */
/* WARNING: Removing unreachable block (ram,0xf00d0908) */
/* WARNING: Removing unreachable block (ram,0xf00d0834) */

undefined8
-[SCSIGeneric executeRequest:buffer:client:senseBuf:]
          (int param_1,undefined4 param_2,byte *param_3,undefined4 param_4,undefined4 param_5,
          undefined4 *param_6)

{
  int iVar1;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 uVar2;
  undefined8 in_l4_5;
  undefined4 uVar3;
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
    *(int *)((in_CWP * 0x10 + 0xc) * 4 + 0x8000) = (int)((qword)in_l4_5 >> 0x20);
    *(int *)((in_CWP * 0x10 + 0xd) * 4 + 0x8000) = (int)in_l4_5;
    *(undefined4 *)((in_CWP * 0x10 + 0xe) * 4 + 0x8000) = unaff_l6;
    *(undefined4 *)((in_CWP * 0x10 + 0xf) * 4 + 0x8000) = unaff_l7;
  }
  if (((*(uint *)(param_1 + 0x124) & 0x80000000) != 0) && (*(int *)(param_1 + 0x108) == 0)) {
    if ((uint)*param_3 != *(uint *)(param_1 + 0x10c)) {
      iVar4 = 7;
      goto locret_F00D0910;
    }
    if ((*(int *)(param_1 + 0x110) == 0) && ((uint)param_3[1] == *(uint *)(param_1 + 0x114))) {
      iVar4 = *(int *)(param_1 + 0x128);
      _objc_msgSend(iVar4,paExecuterequest_0,param_3,param_4,param_5);
      if (iVar4 == 2) {
        *param_6 = *(undefined4 *)(param_3 + 0x40);
        param_6[1] = *(undefined4 *)(param_3 + 0x44);
        param_6[2] = *(undefined4 *)(param_3 + 0x48);
        param_6[3] = *(undefined4 *)(param_3 + 0x4c);
        param_6[4] = *(undefined4 *)(param_3 + 0x50);
        param_6[5] = *(undefined4 *)(param_3 + 0x54);
        param_6[6] = *(undefined4 *)(param_3 + 0x58);
      }
      else if ((iVar4 == 3) && ((*(uint *)(param_1 + 0x11c) & 0x80000000) != 0)) {
        iVar1 = param_1;
        _objc_msgSend(param_1,paGetsense,param_6);
        if (param_1 == 0) {
          iVar4 = 2;
        }
        else {
          iVar4 = iVar1;
          _objc_msgSend(iVar1,paName);
          uVar3 = (undefined4)*(undefined8 *)(iVar4 + 0x108);
          uVar2 = (undefined4)*(undefined8 *)(iVar4 + 0x110);
          iVar4 = 3;
          _IOFindNameForValue(param_1,_IOScStatusStrings);
          _IOLog(aSRequestSenseO,iVar1,uVar3,uVar2,param_1);
        }
      }
      goto locret_F00D0910;
    }
  }
  iVar4 = 7;
locret_F00D0910:
  return CONCAT44(param_2,iVar4);
}
