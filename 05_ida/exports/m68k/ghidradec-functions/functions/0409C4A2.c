
uint uni_getop(void)

{
  byte bVar1;
  uint uVar2;
  word wVar3;
  int unaff_A6;
  
  if (*(uint *)(unaff_A6 + -0xe4) >> 0x1a == 0x17) {
    return 0x17;
  }
  if ((*(byte *)(unaff_A6 + -0xdc) & 4) == 0) {
    bVar1 = *(byte *)(unaff_A6 + -0xe0) | *(byte *)(unaff_A6 + -0xe8);
    uVar2 = (uint)bVar1;
    if (-1 < (sword)((word)bVar1 << 8)) {
      return uVar2;
    }
    if (((*(byte *)(unaff_A6 + -0xe0) & 0x80) == 0) ||
       (uVar2 = sub_409C614(), *(char *)(unaff_A6 + -0x48) == '\0')) goto loc_409C50C;
  }
  else {
    *(undefined4 *)(unaff_A6 + -0xcc) = *(undefined4 *)(unaff_A6 + -0xd0);
    sub_409C614();
    uVar2 = sub_409C714();
    if (*(char *)(unaff_A6 + -0x48) == '\0') {
      return uVar2;
    }
    uVar2 = 1 << (7 - ((*(uint *)(unaff_A6 + -0xe4) & 0x3ffffff) >> 0x17) & 0x1f);
    fmovem(*(undefined4 *)(unaff_A6 + -0xd8),uVar2);
    if ((*(byte *)(unaff_A6 + -0xe0) & 0x80) == 0) {
      if ((*(byte *)(unaff_A6 + -0xe0) & 0xf0) != 0) {
        return CONCAT31((int3)(uVar2 >> 8),*(byte *)(unaff_A6 + -0xe0)) & 0xfffffff0;
      }
      uVar2 = CONCAT22((sword)(uVar2 >> 0x10),*(word *)(unaff_A6 + -0xd8)) & 0xffff7fff;
      if (0x3ffe < (*(word *)(unaff_A6 + -0xd8) & 0x7fff)) {
        return uVar2;
      }
      *(byte *)(unaff_A6 + -0xe0) = *(byte *)(unaff_A6 + -0xe0) | 0x10;
      return uVar2;
    }
  }
  uVar2 = CONCAT22((sword)(uVar2 >> 0x10),*(word *)(unaff_A6 + -0xd8)) & 0xffff7fff;
  if ((*(word *)(unaff_A6 + -0xd8) & 0x7fff) != 0) {
    uVar2 = sub_409C646();
    *(undefined *)(unaff_A6 + -0xe0) = *(undefined *)(unaff_A6 + -0x54);
  }
loc_409C50C:
  if ((*(byte *)(unaff_A6 + -0xe8) & 0x80) != 0) {
    if ((*(byte *)(unaff_A6 + -0xe8) & 0x20) != 0) {
      if ((*(byte *)(unaff_A6 + -0xe4) & 0x10) == 0) {
        wVar3 = 0x3f81;
      }
      else {
        wVar3 = 0x3c01;
      }
      if ((*(byte *)(unaff_A6 + -0xcc) & 0x80) != 0) {
        wVar3 = wVar3 | 0x8000;
      }
      *(word *)(unaff_A6 + -0xcc) = wVar3;
      *(word *)(unaff_A6 + -0xe4) = *(word *)(unaff_A6 + -0xe4) & 0xe3ff | 0x800;
      uVar2 = sub_409C646();
      *(undefined *)(unaff_A6 + -0xe8) = *(undefined *)(unaff_A6 + -0x54);
      return uVar2;
    }
    uVar2 = CONCAT22((sword)(uVar2 >> 0x10),*(word *)(unaff_A6 + -0xcc)) & 0xffff7fff;
    if ((*(word *)(unaff_A6 + -0xcc) & 0x7fff) != 0) {
      uVar2 = sub_409C646();
      *(undefined *)(unaff_A6 + -0xe8) = *(undefined *)(unaff_A6 + -0x54);
      return uVar2;
    }
  }
  return uVar2;
}
