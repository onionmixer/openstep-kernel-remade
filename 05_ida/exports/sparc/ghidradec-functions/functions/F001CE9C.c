
/* WARNING: Removing unreachable block (ram,0xf001cfc8) */
/* WARNING: Removing unreachable block (ram,0xf001cee4) */
/* WARNING: Removing unreachable block (ram,0xf001cea0) */

undefined8 _unputc(int *param_1,undefined4 param_2)

{
  int *piVar1;
  uint uVar2;
  int iVar3;
  uint *puVar4;
  undefined4 *puVar5;
  undefined4 unaff_l0;
  uint uVar6;
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
  piVar1 = param_1;
  _spltty();
  if (*param_1 < 1) {
    uVar6 = 0xffffffff;
  }
  else {
    iVar3 = param_1[2];
    uVar2 = iVar3 - 1;
    param_1[2] = uVar2;
    uVar6 = (uint)*(char *)(iVar3 + -1);
    iVar3 = (int)(uVar2 & 0x3f) >> 3;
    if (((int)*(char *)(iVar3 + (uVar2 & 0xffffffc0) + 4) >>
         ((char)(uVar2 & 0x3f) + (char)iVar3 * -8 & 0x1fU) & 1U) != 0) {
      uVar6 = uVar6 | 0x100;
    }
    iVar3 = *param_1;
    *param_1 = iVar3 + -1;
    if (iVar3 + -1 < 1) {
      param_1[1] = 0;
      uVar2 = param_1[2];
      param_1[2] = 0;
      *(undefined4 *)(uVar2 & 0xffffffc0) = _cfreelist;
      _cfreelist = (undefined4 *)(uVar2 & 0xffffffc0);
    }
    else {
      uVar2 = param_1[2] & 0xffffffc0;
      if (param_1[2] != uVar2 + 0xc) goto loc_F001CFC8;
      param_1[2] = uVar2;
      puVar4 = (uint *)(param_1[1] & 0xffffffc0);
      if (*puVar4 != uVar2) {
        for (puVar4 = (uint *)*puVar4; *puVar4 != uVar2; puVar4 = (uint *)*puVar4) {
        }
      }
      param_1[2] = (int)(puVar4 + 0x10);
      puVar5 = (undefined4 *)*puVar4;
      *puVar5 = _cfreelist;
      _cfreelist = puVar5;
      *puVar4 = 0;
    }
    _cfreecount = _cfreecount + 0x34;
  }
loc_F001CFC8:
  _splx(piVar1);
  return CONCAT44(param_2,uVar6);
}
