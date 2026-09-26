
/* WARNING: Removing unreachable block (ram,0xf00cfdd0) */
/* WARNING: Removing unreachable block (ram,0xf00cfe18) */
/* WARNING: Removing unreachable block (ram,0xf00cfe0c) */
/* WARNING: Removing unreachable block (ram,0xf00cfdec) */
/* WARNING: Removing unreachable block (ram,0xf00cfe64) */
/* WARNING: Removing unreachable block (ram,0xf00cfe48) */

undefined8
-[SCSIDisk logOpInfo:sense:](int param_1,undefined4 param_2,undefined4 *param_3,int *param_4)

{
  uint uVar1;
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
  *(undefined *)((int)register0x00000038 + -0x88) = 0;
  switch(*param_3) {
  case :
    *(undefined4 *)((int)register0x00000038 + -0x38) = 0x52656164;
    *(undefined *)((int)register0x00000038 + -0x34) = 0;
    goto loc_F00CFD9C;
  case :
    *(undefined4 *)((int)register0x00000038 + -0x38) = 0x57726974;
    *(undefined2 *)((int)register0x00000038 + -0x34) = 0x6500;
loc_F00CFD9C:
    if ((param_4 == (int *)0x0) || (-1 < *param_4)) {
      _sprintf((undefined *)((int)register0x00000038 + -0x88),aBlockDBlockcou,param_3[1],param_3[2])
      ;
    }
    else {
      _sprintf((undefined *)((int)register0x00000038 + -0x88),aBlockD,
               (uint)(byte)*param_4 << 0x18 | (uint)param_4[1] >> 8);
    }
    break;
  case :
  case :
    uVar1 = (uint)*(byte *)(param_3[5] + 4);
    _IOFindNameForValue(uVar1,_IOSCSIOpcodeStrings);
    _strcpy((undefined *)((int)register0x00000038 + -0x38),uVar1);
    break;
  case :
    *(undefined4 *)((int)register0x00000038 + -0x38) = 0x456a6563;
    *(undefined2 *)((int)register0x00000038 + -0x34) = 0x7400;
    break;
  :
    _panic(aBogusOpInLogop);
  }
  _IOLog(aTargetDLunDOpS,*(undefined *)(param_1 + 0x188),*(undefined *)(param_1 + 0x189),
         (undefined *)((int)register0x00000038 + -0x38),
         (undefined *)((int)register0x00000038 + -0x88));
  return CONCAT44(param_2,param_1);
}

