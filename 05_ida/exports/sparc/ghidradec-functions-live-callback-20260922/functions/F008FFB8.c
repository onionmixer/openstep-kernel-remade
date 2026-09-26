
/* WARNING: Removing unreachable block (ram,0xf009012c) */
/* WARNING: Removing unreachable block (ram,0xf00900c4) */
/* WARNING: Removing unreachable block (ram,0xf009014c) */
/* WARNING: Removing unreachable block (ram,0xf008ffd4) */

undefined8
-[KernStringList initWithWhitespaceDelimitedString:](int param_1,undefined4 param_2,char *param_3)

{
  char cVar3;
  int iVar1;
  int iVar2;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  char *pcVar4;
  undefined4 unaff_l4;
  int iVar5;
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
  *(int *)((int)register0x00000038 + -0x10) = param_1;
  *(undefined4 *)((int)register0x00000038 + -0xc) = uRamf0141d08;
  _objc_msgSendSuper((undefined *)((int)register0x00000038 + -0x10),paInit);
  cVar3 = *param_3;
  while (cVar3 != '\0') {
    if ((*param_3 != ' ') && (1 < (byte)(*param_3 - 9U))) {
      cVar3 = *param_3;
      goto loc_F0090018;
    }
    param_3 = param_3 + 1;
    cVar3 = *param_3;
  }
  cVar3 = *param_3;
loc_F0090018:
  if (cVar3 != '\0') {
    cVar3 = *param_3;
    pcVar4 = param_3;
loc_F0090050:
    while (cVar3 != '\0') {
      if ((*pcVar4 != ' ') && (1 < (byte)(*pcVar4 - 9U))) {
        cVar3 = *pcVar4;
        goto loc_F0090060;
      }
      pcVar4 = pcVar4 + 1;
      cVar3 = *pcVar4;
    }
    cVar3 = *pcVar4;
loc_F0090060:
    if (cVar3 != '\0') {
      *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 1;
      goto loc_F0090090;
    }
    cVar3 = *pcVar4;
    while ((cVar3 != '\0' && (cVar3 != ' '))) {
      if ((byte)(*pcVar4 - 9U) < 2) {
        cVar3 = *pcVar4;
        goto loc_F00900B0;
      }
      pcVar4 = pcVar4 + 1;
loc_F0090090:
      cVar3 = *pcVar4;
    }
    cVar3 = *pcVar4;
loc_F00900B0:
    if (cVar3 != '\0') {
      cVar3 = *pcVar4;
      goto loc_F0090050;
    }
  }
  iVar5 = 0;
  iVar1 = *(int *)(param_1 + 8) << 2;
  sub_F008FF6C();
  *(int *)(param_1 + 4) = iVar1;
  do {
    if ((param_3 == (char *)0x0) || (*param_3 == '\0')) {
      return CONCAT44(param_2,param_1);
    }
    pcVar4 = param_3;
    if (*param_3 == ' ') {
loc_F0090124:
      iVar1 = (int)pcVar4 - (int)param_3;
    }
    else {
      cVar3 = *param_3;
      while (iVar1 = (int)pcVar4 - (int)param_3, 1 < (byte)(cVar3 - 9U)) {
        pcVar4 = pcVar4 + 1;
        if ((*pcVar4 == '\0') || (*pcVar4 == ' ')) goto loc_F0090124;
        cVar3 = *pcVar4;
      }
    }
    iVar2 = iVar1 + 1;
    sub_F008FF6C();
    *(int *)(*(int *)(param_1 + 4) + iVar5 * 4) = iVar2;
    _strncpy();
    *(undefined *)(iVar1 + 1 + iVar2 + -1) = 0;
    cVar3 = *pcVar4;
    while ((cVar3 != '\0' && ((*pcVar4 == ' ' || ((byte)(*pcVar4 - 9U) < 2))))) {
      pcVar4 = pcVar4 + 1;
      cVar3 = *pcVar4;
    }
    iVar5 = iVar5 + 1;
    param_3 = pcVar4;
  } while( true );
}

