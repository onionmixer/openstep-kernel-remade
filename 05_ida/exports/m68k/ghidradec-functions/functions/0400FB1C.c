
void _ttsettermios(int *param_1,uint *param_2)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  
  iVar1 = *param_1;
  uVar2 = *param_2;
  uVar3 = param_2[3];
  uVar4 = param_2[1];
  uVar5 = param_2[2];
  uVar8 = 0;
  uVar7 = 0;
  if (((((uVar2 & 0x23e2) == 0) && ((uVar4 & 1) == 0)) && ((uVar3 & 0xe0) == 0)) &&
     ((uVar5 & 0x1300) == 0x300)) {
    uVar8 = 0x20;
  }
  else {
    if ((uVar2 & 2) != 0) {
      uVar7 = 0x40000;
    }
    if ((uVar2 & 0x20) != 0) {
      uVar7 = uVar7 | 0x400000;
    }
    if ((uVar2 & 0x40) != 0) {
      uVar7 = uVar7 | 0x800000;
    }
    if ((char)uVar2 < '\0') {
      uVar7 = uVar7 | 0x1000000;
    }
    if ((uVar2 & 0x200) != 0) {
      uVar7 = uVar7 | 0x4000000;
    }
    if ((uVar2 & 0x2000) != 0) {
      uVar7 = uVar7 | 0x8000000;
    }
    if ((uVar4 & 1) != 0) {
      uVar7 = uVar7 | 0x10000000;
    }
    if ((uVar4 & 2) == 0) {
loc_400FBC8:
      if ((uVar2 & 0x100) != 0) {
        uVar7 = uVar7 | 0x2000000;
      }
    }
    else {
      if ((uVar2 & 0x100) == 0) {
        uVar7 = uVar7 | 0x20000000;
        goto loc_400FBC8;
      }
      uVar8 = 0x10;
    }
    if ((uVar3 & 0x20) == 0) {
      uVar8 = uVar8 | 2;
    }
    if ((uVar3 & 0x40) != 0) {
      uVar7 = uVar7 | 8;
    }
    if ((char)uVar3 < '\0') {
      uVar7 = uVar7 | 0x10;
    }
    if ((uVar5 & 0x1000) != 0) {
      uVar7 = uVar7 | 0x1000;
    }
    uVar6 = uVar5 & 0x300;
    if (uVar6 == 0x100) {
      uVar7 = uVar7 | 0x100;
    }
    else if (0x100 < uVar6) {
      if (uVar6 == 0x200) {
        uVar7 = uVar7 | 0x200;
      }
      else if ((uVar6 == 0x300) && (uVar7 = uVar7 | 0x300, (uVar5 & 0x1000) == 0)) {
        if ((uVar4 & 1) == 0) {
          uVar6 = 0x200000;
        }
        else {
          uVar6 = 0x2000000;
        }
        uVar8 = uVar8 | uVar6;
        if ((uVar2 & 0x20) == 0) {
          uVar8 = uVar8 | 0x8000000;
        }
      }
    }
  }
  if ((uVar5 & 0x2000) != 0) {
    uVar8 = uVar8 | 0x40;
    goto loc_400FC78;
  }
  if ((char)uVar3 < '\0') {
    if ((uVar5 & 0x40000) != 0) {
      uVar8 = uVar8 | 0xc0;
      goto loc_400FC78;
    }
    if ((uVar5 & 0x20000) != 0) goto loc_400FC78;
  }
  uVar8 = uVar8 | 0x80;
loc_400FC78:
  if ((uVar5 & 0x400) != 0) {
    uVar7 = uVar7 | 0x400;
  }
  if ((uVar5 & 0x800) != 0) {
    uVar7 = uVar7 | 0x800;
  }
  if ((uVar5 & 0x4000) == 0) {
    uVar8 = uVar8 | 0x1000000;
  }
  if ((sword)uVar5 < 0) {
    uVar7 = uVar7 | 0x8000;
  }
  if ((uVar5 & 0x10000) != 0) {
    uVar7 = uVar7 | 0x10000;
  }
  if ((uVar2 & 1) != 0) {
    uVar7 = uVar7 | 0x20000;
  }
  if ((uVar2 & 4) != 0) {
    uVar7 = uVar7 | 0x80000;
  }
  if ((uVar2 & 8) != 0) {
    uVar7 = uVar7 | 0x100000;
  }
  if ((uVar2 & 0x10) != 0) {
    uVar7 = uVar7 | 0x200000;
  }
  if ((uVar2 & 0x400) != 0) {
    uVar8 = uVar8 | 1;
  }
  if ((uVar2 & 0x800) == 0) {
    uVar8 = uVar8 | 0x40000000;
  }
  uVar8 = uVar4 & 0xff00 | uVar8;
  if ((uVar3 & 2) != 0) {
    uVar8 = uVar8 | 0x10000;
  }
  if ((uVar3 & 4) != 0) {
    uVar7 = uVar7 | 4;
  }
  if ((uVar3 & 1) != 0) {
    uVar8 = uVar8 | 0x4000000;
  }
  if ((uVar3 & 0x100) != 0) {
    uVar8 = uVar8 | 0x40000;
  }
  if ((uVar3 & 0x200) != 0) {
    uVar8 = uVar8 | 0x20000;
  }
  if ((uVar3 & 0x400) != 0) {
    uVar8 = uVar8 | 0x10000000;
  }
  if ((uVar3 & 0x10) != 0) {
    uVar7 = uVar7 | 2;
  }
  if ((uVar3 & 0x800) != 0) {
    uVar7 = uVar7 | 0x20;
  }
  if ((uVar3 & 0x4000000) != 0) {
    uVar8 = uVar8 | 4;
  }
  if ((uVar3 & 0x8000000) != 0) {
    uVar8 = uVar8 | 0x80000;
  }
  *(uint *)(*param_1 + 0x3a) = uVar3 & 0x80500008 | uVar8;
  param_1[4] = uVar7;
  *(undefined *)(iVar1 + 0x47) = *(undefined *)((int)param_2 + 0x21);
  *(undefined *)(iVar1 + 0x48) = *(undefined *)((int)param_2 + 0x22);
  *(undefined *)(iVar1 + 0x4c) = *(undefined *)((int)param_2 + 0x12);
  *(undefined *)(iVar1 + 0x4d) = *(undefined *)((int)param_2 + 0x13);
  *(undefined *)(iVar1 + 0x4e) = *(undefined *)(param_2 + 5);
  *(undefined *)(iVar1 + 0x4f) = *(undefined *)((int)param_2 + 0x15);
  *(undefined *)(iVar1 + 0x50) = *(undefined *)((int)param_2 + 0x17);
  *(undefined *)(iVar1 + 0x51) = *(undefined *)(param_2 + 6);
  *(undefined *)(iVar1 + 0x52) = *(undefined *)(param_2 + 4);
  *(undefined *)(iVar1 + 0x53) = *(undefined *)((int)param_2 + 0x11);
  *(undefined *)(iVar1 + 0x54) = *(undefined *)((int)param_2 + 0x16);
  *(undefined *)(iVar1 + 0x55) = *(undefined *)((int)param_2 + 0x1f);
  *(undefined *)(iVar1 + 0x56) = *(undefined *)(param_2 + 7);
  *(undefined *)(iVar1 + 0x57) = *(undefined *)((int)param_2 + 0x1e);
  *(undefined *)(iVar1 + 0x58) = *(undefined *)((int)param_2 + 0x1b);
  *(undefined *)(iVar1 + 0x59) = *(undefined *)((int)param_2 + 0x1d);
  *(undefined *)((int)param_1 + 0x15) = *(undefined *)((int)param_2 + 0x19);
  *(undefined *)((int)param_1 + 0x16) = *(undefined *)((int)param_2 + 0x1a);
  *(undefined *)(param_1 + 5) = *(undefined *)(param_2 + 8);
  return;
}
