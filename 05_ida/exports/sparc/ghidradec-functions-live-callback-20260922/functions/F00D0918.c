
/* WARNING: Removing unreachable block (ram,0xf00d0a50) */
/* WARNING: Removing unreachable block (ram,0xf00d0a08) */
/* WARNING: Removing unreachable block (ram,0xf00d0a30) */
/* WARNING: Removing unreachable block (ram,0xf00d0a68) */
/* WARNING: Removing unreachable block (ram,0xf00d0994) */

undefined8
-[SCSIGeneric executeSCSI3Request:buffer:client:senseBuf:]
          (int param_1,undefined4 param_2,int *param_3,undefined4 param_4,undefined4 param_5,
          int *param_6)

{
  int iVar1;
  int iVar2;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 uVar3;
  undefined8 in_l4_5;
  undefined4 uVar4;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 unaff_i1;
  undefined4 unaff_i2;
  undefined4 unaff_i3;
  int iVar5;
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
  if ((*(uint *)(param_1 + 0x124) & 0x80000000) != 0) {
    if (*param_3 != *(int *)(param_1 + 0x108)) {
      iVar5 = 7;
      goto locret_F00D0A70;
    }
    if (param_3[1] != *(int *)(param_1 + 0x10c)) {
      iVar5 = 7;
      goto locret_F00D0A70;
    }
    if (param_3[2] != *(int *)(param_1 + 0x110)) {
      iVar5 = 7;
      goto locret_F00D0A70;
    }
    if (param_3[3] == *(int *)(param_1 + 0x114)) {
      iVar5 = *(int *)(param_1 + 0x128);
      _objc_msgSend(iVar5,paExecutescsi3re_0,param_3,param_4,param_5);
      if (iVar5 == 2) {
        *param_6 = param_3[0x14];
        param_6[1] = param_3[0x15];
        param_6[2] = param_3[0x16];
        param_6[3] = param_3[0x17];
        param_6[4] = param_3[0x18];
        param_6[5] = param_3[0x19];
        param_6[6] = param_3[0x1a];
      }
      else if ((iVar5 == 3) && ((*(uint *)(param_1 + 0x11c) & 0x80000000) != 0)) {
        iVar1 = param_1;
        _objc_msgSend(param_1,paGetsense,param_6);
        if (iVar1 == 0) {
          iVar5 = 2;
        }
        else {
          iVar2 = param_1;
          _objc_msgSend(param_1,paName);
          uVar4 = (undefined4)*(undefined8 *)(param_1 + 0x108);
          uVar3 = (undefined4)*(undefined8 *)(param_1 + 0x110);
          iVar5 = 3;
          _IOFindNameForValue(iVar1,_IOScStatusStrings);
          _IOLog(aSRequestSenseO,iVar2,uVar4,uVar3,iVar1);
        }
      }
      goto locret_F00D0A70;
    }
  }
  iVar5 = 7;
locret_F00D0A70:
  return CONCAT44(param_2,iVar5);
}

