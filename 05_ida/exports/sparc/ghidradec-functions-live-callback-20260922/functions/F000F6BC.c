
/* WARNING: Removing unreachable block (ram,0xf000f794) */
/* WARNING: Removing unreachable block (ram,0xf000f6fc) */
/* WARNING: Removing unreachable block (ram,0xf000f718) */
/* WARNING: Removing unreachable block (ram,0xf000f73c) */
/* WARNING: Removing unreachable block (ram,0xf000f6c8) */

undefined8 _setgroups(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  uint uVar2;
  undefined4 uVar3;
  undefined4 *puVar4;
  undefined2 *puVar5;
  undefined4 unaff_l0;
  uint *puVar6;
  undefined4 unaff_l1;
  undefined4 *puVar7;
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
  undefined4 auStack_48 [18];
  
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
  iVar1 = dword_F0133DDC;
  _suser();
  if (iVar1 != 0) {
    if (*puVar6 < 0x11) {
      iVar1 = *(int *)(_active_u + 0x1c);
      _crdup();
      puVar7 = (undefined4 *)((int)register0x00000038 + -0x48);
      uVar2 = puVar6[1];
      _copyin(uVar2,puVar7,*puVar6 << 2);
      *(char *)(dword_F0133DDC + 0x38) = (char)uVar2;
      if (*(char *)(dword_F0133DDC + 0x38) == '\0') {
        puVar5 = (undefined2 *)(iVar1 + 10);
        puVar4 = puVar7;
        if (puVar7 < puVar7 + *puVar6) {
          do {
            *puVar5 = (sword)*puVar4;
            puVar4 = puVar4 + 1;
            puVar5 = puVar5 + 1;
          } while (puVar4 < puVar7 + *puVar6);
        }
        uVar3 = *(undefined4 *)(_active_u + 0x1c);
        *(int *)(_active_u + 0x1c) = iVar1;
        _crfree(uVar3);
        puVar5 = (undefined2 *)(*(int *)(_active_u + 0x1c) + *puVar6 * 2 + 10);
        if (puVar5 < (undefined2 *)(*(int *)(_active_u + 0x1c) + 0x2a)) {
          *puVar5 = 0xffff;
          while (puVar5 = puVar5 + 1, puVar5 < (undefined2 *)(*(int *)(_active_u + 0x1c) + 0x2a)) {
            *puVar5 = 0xffff;
          }
        }
      }
      else {
        _crfree(iVar1);
      }
    }
    else {
      *(undefined *)(dword_F0133DDC + 0x38) = 0x16;
    }
  }
  return CONCAT44(param_2,param_1);
}

