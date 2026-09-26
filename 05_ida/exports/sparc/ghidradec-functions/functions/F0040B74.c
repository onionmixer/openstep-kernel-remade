
/* WARNING: Removing unreachable block (ram,0xf0040c24) */
/* WARNING: Removing unreachable block (ram,0xf0040bcc) */
/* WARNING: Removing unreachable block (ram,0xf0040cb0) */
/* WARNING: Removing unreachable block (ram,0xf0040c8c) */
/* WARNING: Removing unreachable block (ram,0xf0040c98) */
/* WARNING: Removing unreachable block (ram,0xf0040ba8) */
/* WARNING: Removing unreachable block (ram,0xf0040c04) */
/* WARNING: Removing unreachable block (ram,0xf0040d24) */
/* WARNING: Removing unreachable block (ram,0xf0040c58) */

undefined8 sub_F0040B74(uint *param_1,undefined4 param_2)

{
  int *piVar1;
  int *piVar2;
  uint uVar3;
  int *piVar4;
  uint uVar5;
  sword sVar6;
  undefined4 unaff_l0;
  int iVar7;
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
  piVar1 = (int *)param_1[0x10];
  iVar8 = piVar1[0xc];
  piVar2 = piVar1;
  (**(code **)(piVar1[7] + 0x80))(piVar1);
  if ((*param_1 & 1) == 0) {
    iVar7 = (int)*(sword *)(iVar8 + 0x62);
    if (iVar7 == 0) {
      uVar5 = param_1[9];
      .umul(uVar5,piVar2);
      uVar5 = *(int *)(iVar8 + 0x98) - uVar5;
      uVar3 = param_1[5];
      if (uVar5 <= param_1[5]) {
        uVar3 = uVar5;
      }
      if ((int)uVar3 < 0) {
        _panic(aDoBioWriteCoun);
        uVar5 = param_1[9];
      }
      else {
        uVar5 = param_1[9];
      }
      .umul(uVar5,piVar2);
      piVar2 = piVar1;
      _nfswrite(piVar1,param_1[8],uVar5,uVar3,*(undefined4 *)(iVar8 + 0x70));
      sVar6 = (sword)piVar2;
      *(sword *)(param_1 + 7) = sVar6;
      iVar7 = (int)sVar6;
      if ((*param_1 & 0x100) != 0) {
        *(sword *)(iVar8 + 0x62) = sVar6;
      }
    }
    else {
      *(sword *)(param_1 + 7) = *(sword *)(iVar8 + 0x62);
    }
  }
  else {
    uVar3 = param_1[9];
    .umul(uVar3,piVar2);
    piVar4 = piVar1;
    sub_F003F5B4(piVar1,param_1[8],uVar3,param_1[5],param_1 + 10,*(undefined4 *)(iVar8 + 0x70),
                 (undefined *)((int)register0x00000038 + -0x48));
    *(sword *)(param_1 + 7) = (sword)piVar4;
    iVar7 = (int)(sword)piVar4;
    bVar9 = iVar7 == 0;
    if (!bVar9) goto loc_F0040CE8;
    uVar5 = param_1[5];
    uVar3 = 0;
    if (param_1[10] != 0) {
      _bzero(param_1[8] + (uVar5 - param_1[10]));
      uVar3 = param_1[10];
      uVar5 = param_1[5];
    }
    bVar9 = true;
    if (uVar3 != uVar5) goto loc_F0040CE8;
    uVar3 = param_1[9];
    .umul(uVar3,piVar2);
    if (uVar3 < *(uint *)(iVar8 + 0x98)) {
      bVar9 = true;
      goto loc_F0040CE8;
    }
    iVar7 = -0x62;
  }
  bVar9 = iVar7 == 0;
loc_F0040CE8:
  if ((!bVar9) && (iVar7 != -0x62)) {
    *param_1 = *param_1 | 4;
    iVar8 = *piVar1;
    if ((iVar8 != 0) && (*(int *)(iVar8 + 0x34) == 0)) {
      *(int *)(iVar8 + 0x34) = iVar7;
    }
  }
  _biodone(param_1);
  return CONCAT44(param_2,iVar7);
}
