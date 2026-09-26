/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00111474 */

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
  char local_18;
  short local_c;
  
  iVar1 = *param_1;
  uVar2 = *param_2;
  uVar3 = param_2[3];
  uVar4 = param_2[1];
  uVar5 = param_2[2];
  uVar8 = 0;
  uVar7 = 0;
  local_18 = (char)uVar3;
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
LAB_0011153a:
      if ((uVar2 & 0x100) != 0) {
        uVar7 = uVar7 | 0x2000000;
      }
    }
    else {
      if ((uVar2 & 0x100) == 0) {
        uVar7 = uVar7 | 0x20000000;
        goto LAB_0011153a;
      }
      uVar8 = 0x10;
    }
    if ((uVar3 & 0x20) == 0) {
      uVar8 = uVar8 | 2;
    }
    if ((uVar3 & 0x40) != 0) {
      uVar7 = uVar7 | 8;
    }
    if (local_18 < '\0') {
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
          uVar8 = uVar8 | 0x200000;
        }
        else {
          uVar8 = uVar8 | 0x2000000;
        }
        if ((uVar2 & 0x20) == 0) {
          uVar8 = uVar8 | 0x8000000;
        }
      }
    }
  }
  if ((uVar5 & 0x2000) != 0) {
    uVar8 = uVar8 | 0x40;
    goto LAB_00111609;
  }
  if (local_18 < '\0') {
    if ((uVar5 & 0x40000) != 0) {
      uVar8 = uVar8 | 0xc0;
      goto LAB_00111609;
    }
    if ((uVar5 & 0x20000) != 0) goto LAB_00111609;
  }
  uVar8 = uVar8 | 0x80;
LAB_00111609:
  if ((uVar5 & 0x400) != 0) {
    uVar7 = uVar7 | 0x400;
  }
  if ((uVar5 & 0x800) != 0) {
    uVar7 = uVar7 | 0x800;
  }
  if ((uVar5 & 0x4000) == 0) {
    uVar8 = uVar8 | 0x1000000;
  }
  local_c = (short)uVar5;
  if (local_c < 0) {
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
  uVar8 = uVar8 | uVar4 & 0xff00;
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
  *(uint *)(*param_1 + 0x3c) = uVar8 | uVar3 & 0x80500008;
  param_1[4] = uVar7;
  *(undefined1 *)(iVar1 + 0x49) = *(undefined1 *)((int)param_2 + 0x21);
  *(undefined1 *)(iVar1 + 0x4a) = *(undefined1 *)((int)param_2 + 0x22);
  *(undefined1 *)(iVar1 + 0x4d) = *(undefined1 *)((int)param_2 + 0x12);
  *(undefined1 *)(iVar1 + 0x4e) = *(undefined1 *)((int)param_2 + 0x13);
  *(char *)(iVar1 + 0x4f) = (char)param_2[5];
  *(undefined1 *)(iVar1 + 0x50) = *(undefined1 *)((int)param_2 + 0x15);
  *(undefined1 *)(iVar1 + 0x51) = *(undefined1 *)((int)param_2 + 0x17);
  *(char *)(iVar1 + 0x52) = (char)param_2[6];
  *(char *)(iVar1 + 0x53) = (char)param_2[4];
  *(undefined1 *)(iVar1 + 0x54) = *(undefined1 *)((int)param_2 + 0x11);
  *(undefined1 *)(iVar1 + 0x55) = *(undefined1 *)((int)param_2 + 0x16);
  *(undefined1 *)(iVar1 + 0x56) = *(undefined1 *)((int)param_2 + 0x1f);
  *(char *)(iVar1 + 0x57) = (char)param_2[7];
  *(undefined1 *)(iVar1 + 0x58) = *(undefined1 *)((int)param_2 + 0x1e);
  *(undefined1 *)(iVar1 + 0x59) = *(undefined1 *)((int)param_2 + 0x1b);
  *(undefined1 *)(iVar1 + 0x5a) = *(undefined1 *)((int)param_2 + 0x1d);
  *(undefined1 *)((int)param_1 + 0x15) = *(undefined1 *)((int)param_2 + 0x19);
  *(undefined1 *)((int)param_1 + 0x16) = *(undefined1 *)((int)param_2 + 0x1a);
  *(char *)(param_1 + 5) = (char)param_2[8];
  return;
}

