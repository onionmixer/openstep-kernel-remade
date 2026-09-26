
/* WARNING: Removing unreachable block (ram,0xf001c9f8) */
/* WARNING: Removing unreachable block (ram,0xf001c978) */

undefined8 _ndqb(int *param_1,uint param_2)

{
  char cVar1;
  int *piVar2;
  int iVar3;
  char *pcVar4;
  char *pcVar5;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  int iVar6;
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
  piVar2 = param_1;
  _spltty();
  iVar3 = *param_1;
  if (iVar3 < 1) {
    iVar6 = -iVar3;
  }
  else {
    pcVar4 = (char *)param_1[1];
    iVar6 = ((uint)(pcVar4 + 0x34) & 0xffffffc0) - (int)pcVar4;
    if (iVar3 < iVar6) {
      iVar6 = iVar3;
    }
    if ((param_2 != 0) && (pcVar5 = pcVar4 + iVar6, pcVar4 < pcVar5)) {
      cVar1 = *pcVar4;
      while (((int)cVar1 & param_2) == 0) {
        pcVar4 = pcVar4 + 1;
        if (pcVar5 <= pcVar4) goto loc_F001C9F8;
        cVar1 = *pcVar4;
      }
      iVar6 = (int)pcVar4 - param_1[1];
    }
  }
loc_F001C9F8:
  _splx(piVar2);
  return CONCAT44(param_2,iVar6);
}

