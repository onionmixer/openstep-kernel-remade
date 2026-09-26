
/* WARNING: Removing unreachable block (ram,0xf003f95c) */

undefined8 sub_F003F94C(undefined4 param_1,uint param_2,int param_3)

{
  sword sVar1;
  uint uVar2;
  sword *psVar3;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  int iVar4;
  undefined4 unaff_i1;
  uint uVar5;
  uint uVar6;
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
  _nfsgetattr(param_1,(undefined *)((int)register0x00000038 + -0x48),param_3,0);
  *(char *)(dword_F0133DDC + 0x38) = (char)param_1;
  iVar4 = (int)*(char *)(dword_F0133DDC + 0x38);
  uVar5 = param_2;
  if (iVar4 == 0) {
    if (*(sword *)(param_3 + 2) != 0) {
      uVar2 = (uint)*(word *)((int)register0x00000038 + -0x44);
      if (*(sword *)(param_3 + 2) != *(sword *)((int)register0x00000038 + -0x42)) {
        uVar5 = (int)param_2 >> 3;
        uVar6 = uVar5;
        if (*(sword *)(param_3 + 4) != *(sword *)((int)register0x00000038 + -0x40)) {
          psVar3 = (sword *)(param_3 + 10);
          uVar6 = (int)param_2 >> 6;
          if (psVar3 < (sword *)(param_3 + 0x2a)) {
            sVar1 = *psVar3;
            while (sVar1 != -1) {
              if (*(sword *)((int)register0x00000038 + -0x40) == sVar1) {
                uVar2 = (uint)*(word *)((int)register0x00000038 + -0x44);
                goto loc_F003F9F8;
              }
              psVar3 = psVar3 + 1;
              if ((sword *)(param_3 + 0x2a) <= psVar3) break;
              sVar1 = *psVar3;
            }
          }
        }
        uVar2 = (uint)*(word *)((int)register0x00000038 + -0x44);
        uVar5 = uVar6;
      }
loc_F003F9F8:
      if ((uVar2 & uVar5) != uVar5) {
        iVar4 = 0xd;
        *(undefined *)(dword_F0133DDC + 0x38) = 0xd;
        goto locret_F003FA20;
      }
    }
    iVar4 = 0;
  }
locret_F003FA20:
  return CONCAT44(uVar5,iVar4);
}
