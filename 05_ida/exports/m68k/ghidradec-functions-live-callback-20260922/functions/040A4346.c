
uint g_rndpr(void)

{
  word wVar1;
  sword sVar3;
  uint uVar2;
  int unaff_A6;
  
  sVar3 = g_opcls();
  if (sVar3 == 3) {
    uVar2 = g_dfmtou();
    return uVar2;
  }
  if ((*(byte *)(unaff_A6 + -0xdc) & 2) == 0) {
    uVar2 = *(uint *)(unaff_A6 + -0xe4) & 0x440000;
    if (uVar2 == 0x400000) {
      return 1;
    }
    if (uVar2 == 0x440000) {
      return 2;
    }
    uVar2 = *(uint *)(unaff_A6 + -0xe4) & 0x7f0000;
    if (uVar2 == 0x270000) {
      return 0;
    }
    if (uVar2 == 0x240000) {
      return 0;
    }
  }
  else {
    uVar2 = (*(uint *)(unaff_A6 + -0xf0) & 0x7fffff) >> 0x15;
    if (uVar2 == 2) {
      return 1;
    }
    if (uVar2 == 3) {
      return 2;
    }
    wVar1 = *(word *)(unaff_A6 + -0xf0) & 0x7f;
    if ((wVar1 == 0x33) || (wVar1 == 0x30)) {
      return 0;
    }
  }
  return (*(uint *)(unaff_A6 + -0x80) & 0xff) >> 6;
}

