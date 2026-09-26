
/* WARNING: Removing unreachable block (ram,0xf000f0ac) */
/* WARNING: Removing unreachable block (ram,0xf000f108) */

undefined8 _getgroups(undefined4 param_1,undefined4 param_2)

{
  sword sVar1;
  int iVar2;
  undefined uVar4;
  undefined *puVar3;
  uint uVar5;
  uint uVar6;
  sword *psVar7;
  int *piVar8;
  int *piVar9;
  undefined4 unaff_l0;
  uint *puVar10;
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
  int aiStack_48 [18];
  
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
  iVar2 = _active_u[7];
  puVar10 = *(uint **)(dword_F0133DDC + 0x24);
  uVar5 = iVar2 + 0x2a;
  if (iVar2 + 10U < uVar5) {
    sVar1 = *(sword *)(iVar2 + 0x28);
    uVar6 = uVar5;
    while ((uVar5 = uVar6, sVar1 == -1 && (uVar5 = uVar6 - 2, _active_u[7] + 10U < uVar5))) {
      sVar1 = *(sword *)(uVar6 - 4);
      uVar6 = uVar5;
    }
  }
  uVar5 = (int)((uVar5 - 10) - _active_u[7]) >> 1;
  if (*puVar10 < uVar5) {
    *(undefined *)(dword_F0133DDC + 0x38) = 0x16;
  }
  else {
    *puVar10 = uVar5;
    piVar8 = (int *)((int)register0x00000038 + -0x48);
    if ((*(uint *)(*_active_u + 0x14) & 0x4000) == 0) {
      psVar7 = (sword *)(_active_u[7] + 10);
      piVar9 = piVar8;
      if (piVar8 < piVar8 + uVar5) {
        do {
          *piVar9 = (int)*psVar7;
          piVar9 = piVar9 + 1;
          psVar7 = psVar7 + 1;
        } while (piVar9 < piVar8 + *puVar10);
      }
      puVar3 = (undefined *)((int)register0x00000038 + -0x48);
      _copyout(puVar3,puVar10[1],*puVar10 << 2);
      uVar4 = SUB41(puVar3,0);
    }
    else {
      iVar2 = _active_u[7] + 10;
      _copyout(iVar2,puVar10[1],uVar5 << 1);
      uVar4 = (undefined)iVar2;
    }
    *(undefined *)(dword_F0133DDC + 0x38) = uVar4;
    if (*(char *)(dword_F0133DDC + 0x38) == '\0') {
      *(uint *)(dword_F0133DDC + 0x30) = *puVar10;
    }
  }
  return CONCAT44(param_2,param_1);
}
