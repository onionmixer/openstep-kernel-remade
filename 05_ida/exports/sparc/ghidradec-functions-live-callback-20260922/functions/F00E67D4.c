
/* WARNING: Removing unreachable block (ram,0xf00e6914) */
/* WARNING: Removing unreachable block (ram,0xf00e6890) */

undefined8 _sparcfbRestoreMode(uint param_1,undefined4 param_2)

{
  uint uVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 unaff_l0;
  int iVar4;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 uVar5;
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
  iVar2 = param_1 * 0x44 + 8;
  iVar4 = _sparcfbs + iVar2;
  if ((0xf < param_1) || (*(int *)(_sparcfbs + iVar2) == 0)) {
    uVar5 = 0xfffffd40;
    goto locret_F00E6A20;
  }
  uVar1 = *(uint *)(_sparcfbs + iVar2);
  if (uVar1 == 2) {
    if (*(int *)(iVar4 + 0x40) != 0) {
      (**(code **)(iVar4 + 0x40))(param_1);
    }
    if (*(int *)(iVar4 + 0x30) != 8) {
      *(undefined4 *)(iVar4 + 0x30) = 8;
      *(undefined4 *)(iVar4 + 0x34) = 1;
      uVar5 = *(undefined4 *)(iVar4 + 0x20);
      umul(uVar5,*(undefined4 *)(iVar4 + 0x34));
      *(undefined4 *)(iVar4 + 0x38) = uVar5;
      uVar5 = 0;
      goto locret_F00E6A20;
    }
  }
  else {
    if (uVar1 < 3) {
      if (uVar1 == 1) {
        if (*(int *)(iVar4 + 0x40) == 0) {
          uVar5 = 0;
        }
        else {
          (**(code **)(iVar4 + 0x40))(param_1);
          uVar5 = 0;
        }
      }
      else {
        uVar5 = 0xffffffff;
      }
      goto locret_F00E6A20;
    }
    if (uVar1 != 3) {
      uVar5 = 0xffffffff;
      goto locret_F00E6A20;
    }
    if (*(int *)(iVar4 + 4) != 0) {
      puVar3 = *(undefined4 **)(iVar4 + 8);
      iVar2 = 0;
      do {
        *puVar3 = 0x66;
        iVar2 = iVar2 + 1;
        puVar3 = puVar3 + 1;
      } while (iVar2 < 0x100000);
    }
    *(undefined4 *)(iVar4 + 0x30) = 8;
    *(undefined4 *)(iVar4 + 0x34) = 1;
    uVar5 = *(undefined4 *)(iVar4 + 0x20);
    umul(uVar5,*(undefined4 *)(iVar4 + 0x34));
    *(undefined4 *)(iVar4 + 0x38) = uVar5;
    iVar2 = param_1 * 0x44 + 8;
    if (param_1 < 0x10) {
      if (*(int *)(_sparcfbs + iVar2) == 0) {
        uVar5 = 0;
        goto locret_F00E6A20;
      }
      uVar1 = *(uint *)(_sparcfbs + iVar2);
      if (uVar1 != 2) {
        if (uVar1 < 3) {
          uVar5 = 0;
          if (uVar1 != 1) goto locret_F00E6A20;
        }
        else {
          uVar5 = 0;
          if (uVar1 != 3) goto locret_F00E6A20;
        }
        puVar3 = *(undefined4 **)(_sparcfbs + iVar2 + 0xc);
        *puVar3 = 0;
        puVar3[1] = 0;
        puVar3[1] = 0;
        puVar3[1] = 0;
        *puVar3 = 0xff000000;
        puVar3[1] = 0xff000000;
        puVar3[1] = 0xff000000;
        puVar3[1] = 0xff000000;
        *puVar3 = 0x99000000;
        puVar3[1] = 0x99000000;
        puVar3[1] = 0x99000000;
        puVar3[1] = 0x99000000;
        *puVar3 = 0x66000000;
        puVar3[1] = 0x66000000;
        puVar3[1] = 0x66000000;
        puVar3[1] = 0x66000000;
        *puVar3 = 0;
        uVar5 = 0;
        goto locret_F00E6A20;
      }
      iVar2 = *(int *)(_sparcfbs + iVar2 + 0xc);
      *(undefined4 *)(iVar2 + 0x4000) = 0;
      *(undefined4 *)(iVar2 + 0x4264) = 0x999999;
      *(undefined4 *)(iVar2 + 0x4198) = 0x666666;
      *(undefined4 *)(iVar2 + 0x43fc) = 0xffffff;
    }
  }
  uVar5 = 0;
locret_F00E6A20:
  return CONCAT44(param_2,uVar5);
}

