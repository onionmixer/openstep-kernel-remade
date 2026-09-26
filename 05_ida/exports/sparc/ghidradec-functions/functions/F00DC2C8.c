
/* WARNING: Removing unreachable block (ram,0xf00dc400) */
/* WARNING: Removing unreachable block (ram,0xf00dc3ac) */

undefined8
-[InputStream completeRegion:descriptor:size:used:]
          (int param_1,undefined4 param_2,int param_3,int param_4,uint param_5,int *param_6)

{
  undefined2 uVar1;
  int iVar2;
  byte *pbVar3;
  uint uVar4;
  int iVar5;
  byte *pbVar6;
  undefined4 unaff_l0;
  uint uVar7;
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
  pbVar6 = *(byte **)(param_3 + 0xc);
  uVar7 = *(int *)(param_3 + 8) - (int)pbVar6;
  if (param_5 != 0) {
    if (uVar7 == 0) {
      iVar2 = *(int *)(param_3 + 0x24);
      goto loc_F00DC3DC;
    }
    iVar2 = *param_6;
    if (param_5 < iVar2 + uVar7) {
      uVar7 = param_5 - iVar2;
    }
    iVar5 = *(int *)(param_1 + 0x68);
    pbVar3 = (byte *)(*(int *)(param_4 + 4) + iVar2);
    if (iVar5 == 0) {
      uVar4 = 0;
      if (uVar7 >> 1 == 0) goto loc_F00DC3B4;
      do {
        uVar4 = uVar4 + 1;
        uVar1 = *(undefined2 *)pbVar3;
        pbVar3 = pbVar3 + 2;
        *(undefined2 *)pbVar6 = uVar1;
        pbVar6 = pbVar6 + 2;
      } while (uVar4 < uVar7 >> 1);
      iVar2 = *param_6;
    }
    else if (iVar5 == 3) {
      uVar4 = 0;
      if (uVar7 == 0) {
loc_F00DC3B4:
        iVar2 = *param_6;
      }
      else {
        do {
          uVar4 = uVar4 + 1;
          *pbVar6 = *pbVar3 ^ 0x80 | *pbVar3 & 0x7f;
          pbVar6 = pbVar6 + 1;
          pbVar3 = pbVar3 + 1;
        } while (uVar4 < uVar7);
        iVar2 = *param_6;
      }
    }
    else {
      if (iVar5 == 1) {
        _bcopy(pbVar3,pbVar6,uVar7);
        goto loc_F00DC3B4;
      }
      iVar2 = *param_6;
    }
    *param_6 = iVar2 + uVar7;
    *(uint *)(param_3 + 0xc) = *(int *)(param_3 + 0xc) + uVar7;
    *(uint *)(param_1 + 0x20) = *(int *)(param_1 + 0x20) + uVar7;
  }
  iVar2 = *(int *)(param_3 + 0x24);
loc_F00DC3DC:
  if ((iVar2 == param_4) || (*(int *)(param_3 + 0x30) != 0)) {
    _objc_msgSend(param_1,paSendrecordedda,param_3);
  }
  return CONCAT44(param_2,param_1);
}
