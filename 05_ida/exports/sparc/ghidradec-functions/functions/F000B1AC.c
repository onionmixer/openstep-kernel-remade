
/* WARNING: Removing unreachable block (ram,0xf000b254) */
/* WARNING: Removing unreachable block (ram,0xf000b240) */
/* WARNING: Removing unreachable block (ram,0xf000b278) */
/* WARNING: Removing unreachable block (ram,0xf000b230) */

undefined8 _fstat(undefined4 param_1,undefined4 param_2)

{
  undefined4 uVar1;
  undefined uVar3;
  undefined *puVar2;
  int iVar4;
  uint uVar5;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  uint *puVar6;
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
  puVar6 = *(uint **)(dword_F0133DDC + 0x24);
  uVar5 = *puVar6;
  if (((uVar5 < *(uint *)(_active_u + 0x158)) &&
      (iVar4 = *(int *)(*(int *)(_active_u + 0x14c) + uVar5 * 4), iVar4 != 0)) &&
     (iVar4 != -0x10000)) {
    if (*(sword *)(iVar4 + 0xc) == 1) {
      uVar1 = *(undefined4 *)(iVar4 + 0x18);
      _vno_stat(uVar1,(undefined *)((int)register0x00000038 + -0x48));
      uVar3 = (undefined)uVar1;
loc_F000B24C:
      *(undefined *)(dword_F0133DDC + 0x38) = uVar3;
    }
    else {
      if (*(sword *)(iVar4 + 0xc) == 2) {
        uVar1 = *(undefined4 *)(iVar4 + 0x18);
        _soo_stat(uVar1,(undefined *)((int)register0x00000038 + -0x48));
        uVar3 = (undefined)uVar1;
        goto loc_F000B24C;
      }
      _panic(&aFstat);
    }
    puVar2 = (undefined *)((int)register0x00000038 + -0x48);
    if (*(char *)(dword_F0133DDC + 0x38) != '\0') goto locret_F000B288;
    _copyout(puVar2,puVar6[1],0x40);
    uVar3 = SUB41(puVar2,0);
  }
  else {
    uVar3 = 9;
  }
  *(undefined *)(dword_F0133DDC + 0x38) = uVar3;
locret_F000B288:
  return CONCAT44(param_2,param_1);
}
