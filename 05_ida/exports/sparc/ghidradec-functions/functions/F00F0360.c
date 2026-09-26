
/* WARNING: Removing unreachable block (ram,0xf00f0434) */

undefined8 sub_F00F0360(char *param_1,undefined4 param_2)

{
  char cVar1;
  int iVar2;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  char *pcVar3;
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
  iVar2 = 0;
  cVar1 = *param_1;
  if (cVar1 != '\0') {
    pcVar3 = param_1;
    do {
      if (cVar1 == '\0') {
loc_F00F03AC:
        iVar2 = (int)pcVar3 - (int)param_1;
        goto locret_F00F0440;
      }
      if (iVar2 == 0) {
        if (cVar1 == (char)param_2) goto loc_F00F03AC;
        cVar1 = *pcVar3;
      }
      else {
        cVar1 = *pcVar3;
      }
      if (cVar1 == '[') {
        iVar2 = iVar2 + 1;
      }
      else if (cVar1 < '\\') {
        if (cVar1 == '(') goto loc_F00F0418;
        if (cVar1 == ')') {
          iVar2 = iVar2 + -1;
        }
      }
      else if (cVar1 == '{') {
loc_F00F0418:
        iVar2 = iVar2 + 1;
      }
      else if (cVar1 < '|') {
        if (cVar1 == ']') {
          iVar2 = iVar2 + -1;
        }
      }
      else if (cVar1 == '}') {
        iVar2 = iVar2 + -1;
      }
      pcVar3 = pcVar3 + 1;
      cVar1 = *pcVar3;
    } while (*pcVar3 != '\0');
  }
  __NXLogError(aObjectSubtypeu);
  iVar2 = 0;
locret_F00F0440:
  return CONCAT44(param_2,iVar2);
}
