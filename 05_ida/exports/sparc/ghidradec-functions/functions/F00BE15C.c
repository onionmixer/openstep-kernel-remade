
/* WARNING: Removing unreachable block (ram,0xf00be670) */
/* WARNING: Removing unreachable block (ram,0xf00be47c) */
/* WARNING: Removing unreachable block (ram,0xf00be5a8) */
/* WARNING: Removing unreachable block (ram,0xf00be578) */
/* WARNING: Removing unreachable block (ram,0xf00be590) */
/* WARNING: Removing unreachable block (ram,0xf00be5e8) */
/* WARNING: Removing unreachable block (ram,0xf00be658) */
/* WARNING: Removing unreachable block (ram,0xf00be678) */
/* WARNING: Removing unreachable block (ram,0xf00be254) */
/* WARNING: Removing unreachable block (ram,0xf00be5c0) */
/* WARNING: Removing unreachable block (ram,0xf00be4c4) */

undefined8 sub_F00BE15C(int param_1,uint param_2)

{
  char cVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  undefined4 unaff_l0;
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
  uVar2 = *(uint *)(param_1 + 0x44);
  cVar1 = (char)param_2;
  if (uVar2 != 1) {
    if (uVar2 < 2) {
      if (cVar1 == '\x1b') {
        *(undefined4 *)(param_1 + 0x44) = 1;
        goto locret_F00BE680;
      }
    }
    else if (uVar2 == 2) goto loc_F00BE1C8;
    sub_F00BDF1C(param_1);
    switch((int)((param_2 - 4) * 0x1000000) >> 0x18) {
    case :
      *(int *)(param_1 + 0x28) = *(int *)(param_1 + 0x28) + 1;
      break;
    :
      sub_F00BE0C4(param_1,(int)cVar1);
      break;
    case :
      if (*(int *)(param_1 + 0x28) != 0) {
        *(int *)(param_1 + 0x28) = *(int *)(param_1 + 0x28) + -1;
      }
      break;
    case :
      iVar4 = 8 - *(int *)(param_1 + 0x28) % 8;
      sub_F00BDF1C(param_1);
      param_2 = 0;
      if (0 < iVar4) {
        do {
          sub_F00BE15C(param_1,0x20);
          param_2 = param_2 + 1;
        } while ((int)param_2 < iVar4);
      }
      sub_F00BDF1C(param_1);
      iVar4 = *(int *)(param_1 + 0x28);
      goto loc_F00BE5F4;
    case :
      *(undefined4 *)(param_1 + 0x28) = 0;
      *(int *)(param_1 + 0x24) = *(int *)(param_1 + 0x24) + 1;
      break;
    case :
      *(undefined4 *)(param_1 + 0x28) = 0;
      *(undefined4 *)(param_1 + 0x24) = 0;
      sub_F00BDFFC(param_1);
      iVar4 = *(int *)(param_1 + 0x28);
      goto loc_F00BE5F4;
    case :
      *(undefined4 *)(param_1 + 0x28) = 0;
    }
    goto loc_F00BE5F0;
  }
  if (cVar1 == '[') {
    *(undefined4 *)(param_1 + 0x44) = 2;
    goto locret_F00BE680;
  }
  *(undefined4 *)(param_1 + 0x44) = 0;
loc_F00BE1C8:
  if ((param_2 - 0x30 & 0xff) < 10) {
    **(char **)(param_1 + 0x4c) = **(char **)(param_1 + 0x4c) * '\n' + (char)(param_2 - 0x30);
    goto locret_F00BE680;
  }
  iVar3 = 0;
  iVar4 = param_1;
  if (cVar1 == ';') {
    if (*(uint *)(param_1 + 0x4c) < param_1 + 0x4bU) {
      *(uint *)(param_1 + 0x4c) = *(uint *)(param_1 + 0x4c) + 1;
    }
    goto locret_F00BE680;
  }
  do {
    if (*(char *)(iVar4 + 0x48) == '\0') {
      *(undefined *)(iVar4 + 0x48) = 1;
    }
    iVar3 = iVar3 + 1;
    iVar4 = param_1 + iVar3;
  } while (iVar3 < 3);
  uVar2 = (uint)**(byte **)(param_1 + 0x4c);
  sub_F00BDF1C(param_1);
  switch((int)((param_2 - 0x41) * 0x1000000) >> 0x18) {
  case :
    uVar2 = uVar2 - 1;
    if (uVar2 != 0xffffffff) {
      iVar4 = *(int *)(param_1 + 0x24);
      while( true ) {
        uVar2 = uVar2 - 1;
        if (iVar4 != 0) {
          *(int *)(param_1 + 0x24) = iVar4 + -1;
        }
        if (uVar2 == 0xffffffff) break;
        iVar4 = *(int *)(param_1 + 0x24);
      }
      uVar2 = 0xffffffff;
    }
    break;
  case :
    uVar2 = uVar2 - 1;
    if (uVar2 != 0xffffffff) {
      do {
        uVar2 = uVar2 - 1;
        *(int *)(param_1 + 0x24) = *(int *)(param_1 + 0x24) + 1;
      } while (uVar2 != 0xffffffff);
      uVar2 = 0xffffffff;
    }
    break;
  case :
    uVar2 = uVar2 - 1;
    if (uVar2 != 0xffffffff) {
      do {
        uVar2 = uVar2 - 1;
        *(int *)(param_1 + 0x28) = *(int *)(param_1 + 0x28) + 1;
      } while (uVar2 != 0xffffffff);
      uVar2 = 0xffffffff;
    }
    break;
  case :
    uVar2 = uVar2 - 1;
    if (uVar2 != 0xffffffff) {
      iVar4 = *(int *)(param_1 + 0x28);
      while( true ) {
        uVar2 = uVar2 - 1;
        if (iVar4 != 0) {
          *(int *)(param_1 + 0x28) = iVar4 + -1;
        }
        if (uVar2 == 0xffffffff) break;
        iVar4 = *(int *)(param_1 + 0x28);
      }
      uVar2 = 0xffffffff;
    }
    break;
  case :
    uVar2 = uVar2 - 1;
    *(undefined4 *)(param_1 + 0x28) = 0;
    if (uVar2 == 0xffffffff) goto def_F00BE280;
    do {
      uVar2 = uVar2 - 1;
      *(int *)(param_1 + 0x24) = *(int *)(param_1 + 0x24) + 1;
    } while (uVar2 != 0xffffffff);
    uVar2 = 0xffffffff;
    break;
  :
    goto def_F00BE280;
  case :
  case :
    iVar4 = *(int *)(param_1 + 0x4c);
    *(uint *)(param_1 + 0x28) = **(byte **)(param_1 + 0x4c) - 1;
    *(int *)(param_1 + 0x4c) = iVar4 + -1;
    *(uint *)(param_1 + 0x24) = *(byte *)(iVar4 + -1) - 1;
    *(int *)(param_1 + 0x4c) = *(int *)(param_1 + 0x4c) + -1;
    goto def_F00BE280;
  case :
    sub_F00BE038(param_1);
    break;
  case :
    *(int *)(param_1 + 0x4c) = *(int *)(param_1 + 0x4c) + -2;
def_F00BE280:
  }
  *(int *)(param_1 + 0x4c) = param_1 + 0x49;
  *(undefined *)(param_1 + 0x4a) = 0;
  iVar4 = param_1 + 2;
  while (param_1 <= iVar4 + -1) {
    *(undefined *)(iVar4 + 0x47) = 0;
    iVar4 = iVar4 + -1;
  }
  *(undefined4 *)(param_1 + 0x44) = 0;
  param_2 = uVar2;
loc_F00BE5F0:
  iVar4 = *(int *)(param_1 + 0x28);
loc_F00BE5F4:
  if (iVar4 < *(int *)(param_1 + 0x14)) {
    iVar4 = *(int *)(param_1 + 0x24);
  }
  else {
    *(undefined4 *)(param_1 + 0x28) = 0;
    *(int *)(param_1 + 0x24) = *(int *)(param_1 + 0x24) + 1;
    iVar4 = *(int *)(param_1 + 0x24);
  }
  if (*(int *)(param_1 + 0x1c) <= iVar4) {
    *(sword *)((int)register0x00000038 + -0x10) = (sword)*(undefined4 *)(param_1 + 0xc);
    *(sword *)((int)register0x00000038 + -0xe) = (sword)*(undefined4 *)(param_1 + 0x10) + 0xc;
    *(sword *)((int)register0x00000038 + -0xc) = (sword)*(undefined4 *)(param_1 + 0x18);
    *(sword *)((int)register0x00000038 + -10) = (sword)*(undefined4 *)(param_1 + 0x20) + -0xc;
    _sparcfbMoveRect(0,(undefined *)((int)register0x00000038 + -0x10),*(undefined4 *)(param_1 + 0xc)
                     ,*(undefined4 *)(param_1 + 0x10));
    *(undefined4 *)(param_1 + 0x28) = 0;
    *(int *)(param_1 + 0x24) = *(int *)(param_1 + 0x24) + -1;
    sub_F00BE038(param_1);
  }
  sub_F00BDF1C(param_1);
locret_F00BE680:
  return CONCAT44(param_2,param_1);
}

