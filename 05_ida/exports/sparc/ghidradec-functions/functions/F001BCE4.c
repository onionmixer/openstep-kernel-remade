
/* WARNING: Removing unreachable block (ram,0xf001bddc) */
/* WARNING: Removing unreachable block (ram,0xf001bd78) */
/* WARNING: Removing unreachable block (ram,0xf001bd88) */
/* WARNING: Removing unreachable block (ram,0xf001be4c) */
/* WARNING: Removing unreachable block (ram,0xf001bd48) */

undefined8 _ptcselect(uint param_1,int param_2)

{
  uint uVar1;
  uint *puVar2;
  undefined4 unaff_l0;
  int *piVar3;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  int iVar4;
  uint *puVar5;
  undefined4 uVar6;
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
  iVar4 = (param_1 & 0xff) * 0x10;
  piVar3 = *(int **)(DAT_f012f20c + iVar4);
  uVar1 = piVar3[0x10];
  puVar5 = *(uint **)(DAT_f012f20c + iVar4 + 4);
  if ((uVar1 & 0x10) == 0) {
loc_F001BD80:
    uVar6 = 1;
  }
  else {
    if (param_2 == 1) {
      _spltty();
      if ((((piVar3[0x10] & 4U) != 0) && (piVar3[6] != 0)) && ((piVar3[0x10] & 0x100U) == 0)) {
        _splx(uVar1);
        goto loc_F001BD80;
      }
      _splx(uVar1);
      uVar1 = piVar3[0x10];
loc_F001BD98:
      if ((uVar1 & 4) != 0) {
        if (((*puVar5 & 8) != 0) && (*(char *)(puVar5 + 3) != '\0')) {
          uVar6 = 1;
          goto locret_F001BE70;
        }
        if (((*puVar5 & 0x80) != 0) && (*(char *)((int)puVar5 + 0xd) != '\0')) {
          uVar6 = 1;
          goto locret_F001BE70;
        }
      }
      puVar2 = puVar5 + 1;
      _selthreadcache();
      if (puVar2 == (uint *)0x0) {
        uVar6 = 0;
        goto locret_F001BE70;
      }
      uVar1 = *puVar5 | 1;
    }
    else {
      if (param_2 < 2) {
        if (param_2 != 0) {
          uVar6 = 0;
          goto locret_F001BE70;
        }
        goto loc_F001BD98;
      }
      if (param_2 != 2) {
        uVar6 = 0;
        goto locret_F001BE70;
      }
      if ((uVar1 & 4) != 0) {
        if ((*puVar5 & 0x20) == 0) {
          if (*piVar3 + piVar3[3] < 0x3fe) goto loc_F001BD80;
          if (piVar3[3] != 0) goto loc_F001BE4C;
          uVar1 = piVar3[0xf] & 0x22;
        }
        else {
          uVar1 = piVar3[3];
        }
        if (uVar1 == 0) {
          uVar6 = 1;
          goto locret_F001BE70;
        }
      }
loc_F001BE4C:
      puVar2 = puVar5 + 2;
      _selthreadcache();
      if (puVar2 == (uint *)0x0) {
        uVar6 = 0;
        goto locret_F001BE70;
      }
      uVar1 = *puVar5 | 2;
    }
    *puVar5 = uVar1;
    uVar6 = 0;
  }
locret_F001BE70:
  return CONCAT44(param_2,uVar6);
}
