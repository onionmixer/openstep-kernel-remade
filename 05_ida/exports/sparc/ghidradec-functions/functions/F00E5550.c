
undefined8 _sparcfbLoadCmap(uint param_1)

{
  uint uVar1;
  undefined4 *puVar2;
  int iVar3;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 uVar4;
  undefined4 unaff_i1;
  int iVar5;
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
  iVar3 = param_1 * 0x44 + 8;
  iVar5 = _sparcfbs + iVar3;
  if ((param_1 < 0x10) && (*(int *)(_sparcfbs + iVar3) != 0)) {
    uVar1 = *(uint *)(_sparcfbs + iVar3);
    if (uVar1 == 2) {
      iVar3 = *(int *)(iVar5 + 0xc);
      *(undefined4 *)(iVar3 + 0x4000) = 0;
      *(undefined4 *)(iVar3 + 0x4264) = 0x999999;
      *(undefined4 *)(iVar3 + 0x4198) = 0x666666;
      *(undefined4 *)(iVar3 + 0x43fc) = 0xffffff;
      uVar4 = 0;
    }
    else {
      if (uVar1 < 3) {
        uVar4 = 0xffffffff;
        if (uVar1 != 1) goto locret_F00E565C;
      }
      else {
        uVar4 = 0xffffffff;
        if (uVar1 != 3) goto locret_F00E565C;
      }
      puVar2 = *(undefined4 **)(iVar5 + 0xc);
      *puVar2 = 0;
      puVar2[1] = 0;
      puVar2[1] = 0;
      puVar2[1] = 0;
      *puVar2 = 0xff000000;
      puVar2[1] = 0xff000000;
      puVar2[1] = 0xff000000;
      puVar2[1] = 0xff000000;
      *puVar2 = 0x99000000;
      puVar2[1] = 0x99000000;
      puVar2[1] = 0x99000000;
      puVar2[1] = 0x99000000;
      *puVar2 = 0x66000000;
      puVar2[1] = 0x66000000;
      puVar2[1] = 0x66000000;
      puVar2[1] = 0x66000000;
      *puVar2 = 0;
      uVar4 = 0;
    }
  }
  else {
    uVar4 = 0xfffffd40;
  }
locret_F00E565C:
  return CONCAT44(iVar5,uVar4);
}
