
/* WARNING: Removing unreachable block (ram,0xf0015b44) */
/* WARNING: Removing unreachable block (ram,0xf0015ae0) */
/* WARNING: Removing unreachable block (ram,0xf00159d4) */
/* WARNING: Removing unreachable block (ram,0xf0015aa0) */
/* WARNING: Removing unreachable block (ram,0xf0015acc) */
/* WARNING: Removing unreachable block (ram,0xf0015ab8) */
/* WARNING: Removing unreachable block (ram,0xf0015a10) */

undefined8 _ioctl(undefined4 param_1,undefined4 param_2)

{
  uint uVar1;
  undefined uVar2;
  uint uVar3;
  int iVar4;
  undefined4 unaff_l0;
  uint uVar5;
  undefined4 unaff_l1;
  int iVar6;
  undefined4 unaff_l3;
  undefined *puVar7;
  undefined4 unaff_l4;
  uint *puVar8;
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
  puVar8 = *(uint **)(dword_F0133DDC + 0x24);
  uVar3 = *puVar8;
  if (((uVar3 < *(uint *)(_active_u + 0x158)) &&
      (iVar6 = *(int *)(*(int *)(_active_u + 0x14c) + uVar3 * 4), iVar6 != 0)) &&
     (iVar6 != -0x10000)) {
    if ((*(uint *)(iVar6 + 8) & 3) == 0) {
      *(undefined *)(dword_F0133DDC + 0x38) = 9;
      goto locret_F0015B54;
    }
    uVar5 = puVar8[1];
    if (uVar5 == 0x20006601) {
      *(byte *)(*(int *)(_active_u + 0x150) + uVar3) =
           *(byte *)(*(int *)(_active_u + 0x150) + uVar3) | 1;
      goto locret_F0015B54;
    }
    if (uVar5 == 0x20006602) {
      *(byte *)(*(int *)(_active_u + 0x150) + uVar3) =
           *(byte *)(*(int *)(_active_u + 0x150) + uVar3) & 0xfe;
      goto locret_F0015B54;
    }
    uVar3 = (uVar5 & 0x1fffffff) >> 0x10;
    if (0x80 < uVar3) {
      *(undefined *)(dword_F0133DDC + 0x38) = 0xe;
      goto locret_F0015B54;
    }
    if ((int)uVar5 < 0) {
      if (uVar3 == 0) {
loc_F0015A30:
        *(uint *)((int)register0x00000038 + -0x88) = puVar8[2];
      }
      else {
        uVar1 = puVar8[2];
        _copyin(uVar1,(undefined *)((int)register0x00000038 + -0x88),uVar3);
        *(char *)(dword_F0133DDC + 0x38) = (char)uVar1;
        if (*(char *)(dword_F0133DDC + 0x38) != '\0') goto locret_F0015B54;
      }
    }
    else if (((uVar5 & 0x40000000) == 0) || (uVar3 == 0)) {
      if ((uVar5 & 0x20000000) != 0) goto loc_F0015A30;
    }
    else {
      _bzero((undefined *)((int)register0x00000038 + -0x88),uVar3);
    }
    if (uVar5 == 0x8004667d) {
      _fset(iVar6,0x40,*(undefined4 *)((int)register0x00000038 + -0x88));
      uVar2 = (undefined)iVar6;
    }
    else if ((int)uVar5 < -0x7ffb9982) {
      if (uVar5 == 0x8004667c) {
        _fsetown(iVar6,*(undefined4 *)((int)register0x00000038 + -0x88));
        uVar2 = (undefined)iVar6;
      }
      else {
        iVar4 = *(int *)(iVar6 + 0x14);
loc_F0015AF8:
        puVar7 = (undefined *)((int)register0x00000038 + -0x88);
        (**(code **)(iVar4 + 4))(iVar6,uVar5,puVar7);
        *(char *)(dword_F0133DDC + 0x38) = (char)iVar6;
        if (((*(char *)(dword_F0133DDC + 0x38) != '\0') || ((uVar5 & 0x40000000) == 0)) ||
           (uVar3 == 0)) goto locret_F0015B54;
        _copyout(puVar7,puVar8[2],uVar3);
        uVar2 = SUB41(puVar7,0);
      }
    }
    else if (uVar5 == 0x8004667e) {
      _fset(iVar6,4,*(undefined4 *)((int)register0x00000038 + -0x88));
      uVar2 = (undefined)iVar6;
    }
    else {
      if (uVar5 != 0x4004667b) {
        iVar4 = *(int *)(iVar6 + 0x14);
        goto loc_F0015AF8;
      }
      _fgetown(iVar6,(undefined *)((int)register0x00000038 + -0x88));
      uVar2 = (undefined)iVar6;
    }
  }
  else {
    uVar2 = 9;
  }
  *(undefined *)(dword_F0133DDC + 0x38) = uVar2;
locret_F0015B54:
  return CONCAT44(param_2,param_1);
}

