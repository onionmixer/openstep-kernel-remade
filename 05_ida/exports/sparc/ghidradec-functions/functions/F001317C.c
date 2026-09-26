
/* WARNING: Removing unreachable block (ram,0xf0013270) */
/* WARNING: Removing unreachable block (ram,0xf00131c0) */
/* WARNING: Removing unreachable block (ram,0xf0013238) */
/* WARNING: Removing unreachable block (ram,0xf0013280) */
/* WARNING: Removing unreachable block (ram,0xf00131a8) */

undefined8 _getitimer(undefined4 param_1,undefined4 param_2)

{
  uint uVar1;
  int iVar2;
  undefined *puVar3;
  uint uVar4;
  int iVar5;
  undefined4 unaff_l0;
  uint *puVar6;
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
  puVar6 = *(uint **)(dword_F0133DDC + 0x24);
  uVar1 = *puVar6;
  if (2 < uVar1) {
    *(undefined *)(dword_F0133DDC + 0x38) = 0x16;
    goto locret_F0013294;
  }
  _spltty();
  uVar4 = *puVar6;
  if (uVar4 == 0) {
    _getthetime((undefined *)((int)register0x00000038 + -0x20));
    iVar5 = *_active_u;
    *(undefined4 *)((int)register0x00000038 + -0x18) = *(undefined4 *)(iVar5 + 0x54);
    *(undefined4 *)((int)register0x00000038 + -0x14) = *(undefined4 *)(iVar5 + 0x58);
    iVar2 = *(int *)(iVar5 + 0x5c);
    *(int *)((int)register0x00000038 + -0x10) = iVar2;
    iVar5 = *(int *)(iVar5 + 0x60);
    *(int *)((int)register0x00000038 + -0xc) = iVar5;
    if ((iVar2 != 0) || (iVar5 != 0)) {
      if (iVar2 < *(int *)((int)register0x00000038 + -0x20)) {
        *(undefined4 *)((int)register0x00000038 + -0xc) = 0;
      }
      else {
        if ((iVar2 != *(int *)((int)register0x00000038 + -0x20)) ||
           (*(int *)((int)register0x00000038 + -0x1c) <= iVar5)) {
          _timevalsub((undefined *)((int)register0x00000038 + -0x10),
                      (undefined *)((int)register0x00000038 + -0x20));
          goto loc_F0013270;
        }
        *(undefined4 *)((int)register0x00000038 + -0xc) = 0;
      }
      *(undefined4 *)((int)register0x00000038 + -0x10) = 0;
    }
  }
  else {
    *(int *)((int)register0x00000038 + -0x18) = _active_u[uVar4 * 4 + 0x7f];
    *(int *)((int)register0x00000038 + -0x14) = _active_u[uVar4 * 4 + 0x80];
    *(int *)((int)register0x00000038 + -0x10) = _active_u[uVar4 * 4 + 0x81];
    *(int *)((int)register0x00000038 + -0xc) = _active_u[uVar4 * 4 + 0x82];
  }
loc_F0013270:
  _splx(uVar1);
  puVar3 = (undefined *)((int)register0x00000038 + -0x18);
  _copyout(puVar3,puVar6[1],0x10);
  *(char *)(dword_F0133DDC + 0x38) = (char)puVar3;
locret_F0013294:
  return CONCAT44(param_2,param_1);
}
