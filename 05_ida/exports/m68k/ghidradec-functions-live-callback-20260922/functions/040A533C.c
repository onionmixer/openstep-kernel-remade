
void sub_40A533C(void)

{
  byte bVar1;
  word wVar2;
  char cVar3;
  byte *pbVar4;
  sword *extraout_A0;
  byte *extraout_A0_00;
  int unaff_A6;
  int iVar5;
  
  wVar2 = g_rndpr();
  iVar5 = (uint)wVar2 << 0x10;
  if ((*(byte *)(unaff_A6 + -0xdc) & 2) == 0) {
    pbVar4 = (byte *)(unaff_A6 + -0xd8);
  }
  else {
    pbVar4 = (byte *)(unaff_A6 + -0x10c);
    wVar2 = *(word *)(unaff_A6 + -0xf0) & 0x7f;
    if ((wVar2 == 0x30) || (wVar2 == 0x33)) {
      iVar5 = 0x10000;
    }
  }
  bVar1 = *pbVar4;
  *pbVar4 = bVar1 & 0x7f;
  pbVar4[2] = -((bVar1 & 0x80) != 0);
  denorm(iVar5);
  round();
  cVar3 = g_opcls();
  if (cVar3 == '\x03') {
    cVar3 = g_dfmtou();
    if ((cVar3 != '\0') && (-1 < *(char *)(extraout_A0 + 2))) {
      *extraout_A0 = *extraout_A0 + -1;
    }
    store();
  }
  else {
    store();
    if ((*(int *)(extraout_A0_00 + 4) == 0) && (*(int *)(extraout_A0_00 + 8) == 0)) {
      *(byte *)(unaff_A6 + -0x7c) = *(byte *)(unaff_A6 + -0x7c) | 4;
    }
    if ((*extraout_A0_00 & 0x80) != 0) {
      *(byte *)(unaff_A6 + -0x7c) = *(byte *)(unaff_A6 + -0x7c) | 8;
    }
  }
  if ((*(byte *)(unaff_A6 + -0x7a) & 2) != 0) {
    *(byte *)(unaff_A6 + -0x79) = *(byte *)(unaff_A6 + -0x79) | 0x20;
  }
  return;
}

