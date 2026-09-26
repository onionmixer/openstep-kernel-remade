/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00196084 */

uint _kmtrygetc(void)

{
  bool bVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  
  iVar2 = _steal_keyboard_event();
  if (iVar2 == 0) {
    return 0xffffffff;
  }
  bVar1 = false;
  uVar4 = *(uint *)(iVar2 + 8);
  if (uVar4 == 0x36) {
    DAT_001e7758 = (int)*(char *)(iVar2 + 0xc);
    *(undefined4 *)(iVar2 + 8) = 0;
  }
  else if (uVar4 < 0x37) {
    if (uVar4 == 0x1d) {
      DAT_001e774c = (int)*(char *)(iVar2 + 0xc);
      *(undefined4 *)(iVar2 + 8) = 0;
    }
    else {
      if (uVar4 != 0x2a) goto LAB_00196150;
      DAT_001e7754 = (int)*(char *)(iVar2 + 0xc);
      *(undefined4 *)(iVar2 + 8) = 0;
    }
  }
  else if (uVar4 == 0x60) {
    DAT_001e7750 = (int)*(char *)(iVar2 + 0xc);
    *(undefined4 *)(iVar2 + 8) = 0;
  }
  else if (uVar4 < 0x61) {
    if (uVar4 == 0x38) {
      DAT_001e775c = (int)*(char *)(iVar2 + 0xc);
      *(undefined4 *)(iVar2 + 8) = 0;
    }
    else {
LAB_00196150:
      bVar1 = true;
    }
  }
  else {
    if (uVar4 != 0x61) goto LAB_00196150;
    DAT_001e7760 = (int)*(char *)(iVar2 + 0xc);
    *(undefined4 *)(iVar2 + 8) = 0;
  }
  if (bVar1) {
    uVar4 = 0;
    if ((DAT_001e7758 != 0) || (DAT_001e7754 != 0)) {
      uVar4 = 1;
    }
    if ((DAT_001e774c == 0) && (DAT_001e7750 == 0)) {
      iVar3 = 0;
    }
    else {
      iVar3 = 0xdc;
    }
    uVar4 = (uint)*(ushort *)(&_ascii + ((*(int *)(iVar2 + 8) * 2 | uVar4) + iVar3) * 2);
    if ((DAT_001e7760 == 0) && (DAT_001e775c == 0)) {
      uVar5 = 0;
    }
    else {
      uVar5 = 0x80;
    }
    switch(uVar4) {
    case 0x101:
    case 0x102:
    case 0x104:
    case 0x106:
    case 0x107:
    case 0x108:
      break;
    default:
      uVar4 = uVar4 | uVar5;
    }
    if (*(char *)(iVar2 + 0xc) != '\0') goto LAB_00196203;
  }
  uVar4 = 0x100;
LAB_00196203:
  uVar5 = 0xffffffff;
  if (uVar4 != 0x100) {
    uVar5 = uVar4;
  }
  return uVar5;
}

