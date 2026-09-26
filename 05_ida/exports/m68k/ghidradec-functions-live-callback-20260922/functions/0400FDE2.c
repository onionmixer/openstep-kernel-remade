
void _ttgettermios(int *param_1,uint *param_2)

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
  uVar2 = *(uint *)(iVar1 + 0x3a);
  uVar3 = param_1[4];
  uVar5 = 0;
  uVar8 = 0;
  uVar6 = 0;
  uVar7 = 0;
  if ((uVar2 & 0x20) != 0) {
    uVar7 = 0x300;
    goto loc_400FEF6;
  }
  if ((uVar3 & 0x40000) != 0) {
    uVar5 = 2;
  }
  if ((uVar3 & 0x400000) != 0) {
    uVar5 = uVar5 | 0x20;
  }
  if ((uVar3 & 0x800000) != 0) {
    uVar5 = uVar5 | 0x40;
  }
  if ((uVar3 & 0x1000000) != 0) {
    uVar5 = uVar5 | 0x80;
  }
  if ((uVar3 & 0x4000000) != 0) {
    uVar5 = uVar5 | 0x200;
  }
  if ((uVar3 & 0x8000000) != 0) {
    uVar5 = uVar5 | 0x2000;
  }
  uVar8 = (uint)((uVar3 & 0x10000000) != 0);
  if ((uVar2 & 0x10) == 0) {
    if ((uVar3 & 0x2000000) != 0) {
      uVar5 = uVar5 | 0x100;
    }
    if ((uVar3 & 0x20000000) != 0) goto loc_400FE72;
  }
  else {
    uVar5 = uVar5 | 0x100;
loc_400FE72:
    uVar8 = uVar8 | 2;
  }
  if ((uVar2 & 2) == 0) {
    uVar6 = 0x20;
  }
  if ((uVar3 & 8) != 0) {
    uVar6 = uVar6 | 0x40;
  }
  if ((uVar3 & 0x10) != 0) {
    uVar6 = uVar6 | 0x80;
  }
  if ((uVar2 & 0xa200000) == 0) {
    if ((uVar3 & 0x1000) != 0) {
      uVar7 = 0x1000;
    }
    uVar4 = uVar3 & 0x300;
    if (uVar4 == 0x100) {
      uVar7 = uVar7 | 0x100;
    }
    else if (0x100 < uVar4) {
      if (uVar4 == 0x200) {
        uVar7 = uVar7 | 0x200;
      }
      else if (uVar4 == 0x300) {
        uVar7 = uVar7 | 0x300;
      }
    }
  }
  else {
    uVar7 = 0x300;
    if ((uVar2 & 0x8000000) != 0) {
      uVar5 = uVar5 & 0xffffffdf;
    }
    if ((uVar2 & 0x200000) != 0) {
      uVar8 = uVar8 & 0xfffffffe;
    }
  }
loc_400FEF6:
  uVar4 = uVar2 & 0xc0;
  if (uVar4 == 0x40) {
    uVar7 = uVar7 | 0x2000;
  }
  else if (uVar4 < 0x41) {
    if (uVar4 == 0) {
      uVar7 = uVar7 | 0x20000;
    }
  }
  else if ((uVar4 != 0x80) && (uVar4 == 0xc0)) {
    uVar7 = uVar7 | 0x40000;
  }
  if ((uVar3 & 0x400) != 0) {
    uVar7 = uVar7 | 0x400;
  }
  if ((uVar3 & 0x800) != 0) {
    uVar7 = uVar7 | 0x800;
  }
  if ((uVar2 & 0x1000000) == 0) {
    uVar7 = uVar7 | 0x4000;
  }
  if ((sword)uVar3 < 0) {
    uVar7 = uVar7 | 0x8000;
  }
  if ((uVar3 & 0x10000) != 0) {
    uVar7 = uVar7 | 0x10000;
  }
  if ((uVar3 & 0x20000) != 0) {
    uVar5 = uVar5 | 1;
  }
  if ((uVar3 & 0x80000) != 0) {
    uVar5 = uVar5 | 4;
  }
  if ((uVar3 & 0x100000) != 0) {
    uVar5 = uVar5 | 8;
  }
  if ((uVar3 & 0x200000) != 0) {
    uVar5 = uVar5 | 0x10;
  }
  if ((uVar2 & 1) != 0) {
    uVar5 = uVar5 | 0x400;
  }
  if ((uVar2 & 0x40000000) == 0) {
    uVar5 = uVar5 | 0x800;
  }
  if ((uVar2 & 0x10000) != 0) {
    uVar6 = uVar6 | 2;
  }
  if ((uVar3 & 4) != 0) {
    uVar6 = uVar6 | 4;
  }
  if ((uVar2 & 0x4000000) != 0) {
    uVar6 = uVar6 | 1;
  }
  if ((uVar2 & 0x40000) != 0) {
    uVar6 = uVar6 | 0x100;
  }
  if ((uVar2 & 0x20000) != 0) {
    uVar6 = uVar6 | 0x200;
  }
  if ((uVar2 & 0x10000000) != 0) {
    uVar6 = uVar6 | 0x400;
  }
  if ((uVar3 & 2) != 0) {
    uVar6 = uVar6 | 0x10;
  }
  if ((uVar3 & 0x20) != 0) {
    uVar6 = uVar6 | 0x800;
  }
  if ((uVar2 & 4) != 0) {
    uVar6 = uVar6 | 0x4000000;
  }
  if ((uVar2 & 0x80000) != 0) {
    uVar6 = uVar6 | 0x8000000;
  }
  *param_2 = uVar5;
  param_2[1] = uVar2 & 0xff00 | uVar8;
  param_2[3] = uVar2 & 0x80500008 | uVar6;
  param_2[2] = uVar7;
  *(undefined *)((int)param_2 + 0x21) = *(undefined *)(iVar1 + 0x47);
  *(undefined *)((int)param_2 + 0x22) = *(undefined *)(iVar1 + 0x48);
  *(undefined *)((int)param_2 + 0x12) = *(undefined *)(iVar1 + 0x4c);
  *(undefined *)((int)param_2 + 0x13) = *(undefined *)(iVar1 + 0x4d);
  *(undefined *)(param_2 + 5) = *(undefined *)(iVar1 + 0x4e);
  *(undefined *)((int)param_2 + 0x15) = *(undefined *)(iVar1 + 0x4f);
  *(undefined *)((int)param_2 + 0x17) = *(undefined *)(iVar1 + 0x50);
  *(undefined *)(param_2 + 6) = *(undefined *)(iVar1 + 0x51);
  *(undefined *)(param_2 + 4) = *(undefined *)(iVar1 + 0x52);
  *(undefined *)((int)param_2 + 0x11) = *(undefined *)(iVar1 + 0x53);
  *(undefined *)((int)param_2 + 0x16) = *(undefined *)(iVar1 + 0x54);
  *(undefined *)((int)param_2 + 0x1f) = *(undefined *)(iVar1 + 0x55);
  *(undefined *)(param_2 + 7) = *(undefined *)(iVar1 + 0x56);
  *(undefined *)((int)param_2 + 0x1e) = *(undefined *)(iVar1 + 0x57);
  *(undefined *)((int)param_2 + 0x1b) = *(undefined *)(iVar1 + 0x58);
  *(undefined *)((int)param_2 + 0x1d) = *(undefined *)(iVar1 + 0x59);
  *(undefined *)((int)param_2 + 0x19) = *(undefined *)((int)param_1 + 0x15);
  *(undefined *)((int)param_2 + 0x1a) = *(undefined *)((int)param_1 + 0x16);
  *(undefined *)(param_2 + 8) = *(undefined *)(param_1 + 5);
  return;
}

