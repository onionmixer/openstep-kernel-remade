
/* WARNING: Removing unreachable block (ram,0xf00c3bb4) */
/* WARNING: Removing unreachable block (ram,0xf00c3bd4) */
/* WARNING: Type propagation algorithm not settling */

undefined8 _findBootConfigString(int param_1,undefined4 param_2)

{
  char *pcVar1;
  undefined4 unaff_l0;
  int iVar2;
  undefined4 unaff_l1;
  char *pcVar3;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined *puVar4;
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
  puVar4 = DAT_f0122578;
  pcVar3 = (char *)0x0;
  if (DAT_f0122578[0] == '\0') {
    _IOLog(aWarningNoConfi);
loc_F00C3BBC:
    puVar4 = (char *)0x0;
  }
  else {
    iVar2 = 0;
    if (0 < param_1) {
      do {
        pcVar1 = puVar4;
        _strlen();
        pcVar3 = pcVar3 + 1 + (int)pcVar1;
        puVar4 = puVar4 + (int)(pcVar1 + 1);
        if (pcVar1 == (char *)0x0) goto loc_F00C3BBC;
        if (0xc000 < (int)pcVar3) {
          puVar4 = (char *)0x0;
          break;
        }
        iVar2 = iVar2 + 1;
        if (*puVar4 == '\0') goto loc_F00C3BBC;
      } while (iVar2 < param_1);
    }
  }
  return CONCAT44(param_2,puVar4);
}
