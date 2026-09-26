
/* WARNING: Removing unreachable block (ram,0xf004f3a4) */

undefined8 sub_F004F334(uint param_1,undefined4 param_2)

{
  int iVar1;
  uint uVar2;
  uint *puVar3;
  uint *puVar4;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  uint *puVar5;
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
  iVar1 = (param_1 & 0x3f) * 4;
  puVar5 = (uint *)(_lf_svnode_hash + iVar1);
  uVar2 = *(uint *)(_lf_svnode_hash + iVar1);
  puVar3 = puVar5;
  do {
    if (uVar2 == 0) {
      puVar3 = (uint *)0x10;
      _kalloc();
      *puVar3 = param_1;
      puVar3[1] = 0;
      puVar3[2] = 0;
      *(sword *)(param_1 + 6) = *(sword *)(param_1 + 6) + 1;
      puVar3[3] = *puVar5;
      *puVar5 = (uint)puVar3;
loc_F004F3D0:
      uVar2 = *puVar5;
locret_F004F3D4:
      return CONCAT44(param_2,uVar2);
    }
    puVar4 = (uint *)*puVar3;
    if (param_1 == *puVar4) {
      if (puVar3 == puVar5) {
        uVar2 = *puVar5;
        goto locret_F004F3D4;
      }
      *puVar3 = puVar4[3];
      puVar4[3] = *puVar5;
      *puVar5 = (uint)puVar4;
      goto loc_F004F3D0;
    }
    uVar2 = puVar4[3];
    puVar3 = puVar4 + 3;
  } while( true );
}

