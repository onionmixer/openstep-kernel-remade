/* GHIDRADEC_FUNCTION index=3200 start=0x409d60e */

void sub_409D60E(void)

{
  func_0x0409d61c();
  return;
}
/* GHIDRADEC_FUNCTION index=3201 start=0x409d618 */

undefined4 sub_409D618(void)

{
  byte bVar1;
  int unaff_A6;
  
  bVar1 = *(byte *)(unaff_A6 + -0xe0) & 0x60;
  if (((bVar1 != 0x40) && (bVar1 != 0x60)) && (bVar1 != 0x20)) {
    return 0;
  }
  return 0xffffffff;
}
/* GHIDRADEC_FUNCTION index=3202 start=0x409dfc6 */

/* WARNING: Control flow encountered unimplemented instructions */

void sub_409DFC6(void)

{
                    /* WARNING: Unimplemented instruction - Truncating control flow here */
  halt_unimplemented();
}
/* GHIDRADEC_FUNCTION index=3203 start=0x409e534 */

void sub_409E534(void)

{
  sword *extraout_A0;
  
  dnrm_lp();
  round();
  *extraout_A0 = *extraout_A0 + -1;
  return;
}
/* GHIDRADEC_FUNCTION index=3204 start=0x409e564 */

void sub_409E564(void)

{
  uint uVar1;
  undefined4 *in_A0;
  int unaff_A6;
  
  *(undefined4 *)(unaff_A6 + -0x10c) = *in_A0;
  *(undefined4 *)(unaff_A6 + -0x108) = in_A0[1];
  *(undefined4 *)(unaff_A6 + -0x104) = in_A0[2];
  uVar1 = *(uint *)(unaff_A6 + -0x10a) >> 0x18;
  *(uint *)(unaff_A6 + -0x10a) = uVar1;
  if (uVar1 != 0) {
    *(byte *)(unaff_A6 + -0x10c) = *(byte *)(unaff_A6 + -0x10c) | 0x80;
  }
  *(uint *)(unaff_A6 + -0xe8) = (*(uint *)(unaff_A6 + -0xe8) & 0x7ffffff) >> 0x17;
  return;
}
/* GHIDRADEC_FUNCTION index=3205 start=0x409e6d4 */

/* WARNING: Control flow encountered unimplemented instructions */

void sub_409E6D4(void)

{
                    /* WARNING: Unimplemented instruction - Truncating control flow here */
  halt_unimplemented();
}
/* GHIDRADEC_FUNCTION index=3206 start=0x409e736 */

void sub_409E736(void)

{
  return;
}
/* GHIDRADEC_FUNCTION index=3207 start=0x409e7be */

/* WARNING: Control flow encountered unimplemented instructions */

void sub_409E7BE(void)

{
                    /* WARNING: Unimplemented instruction - Truncating control flow here */
  halt_unimplemented();
}
/* GHIDRADEC_FUNCTION index=3208 start=0x40a0858 */

void sub_40A0858(void)

{
  return;
}
/* GHIDRADEC_FUNCTION index=3209 start=0x40a4b34 */

void sub_40A4B34(void)

{
  undefined4 in_D0;
  uint uVar1;
  int unaff_A6;
  
  *(undefined4 *)(unaff_A6 + -0x54) = in_D0;
  uVar1 = get_fline();
  if ((uVar1 & 0x3f) >> 3 != 0) {
    mem_write();
    return;
  }
  reg_dest();
  return;
}
/* GHIDRADEC_FUNCTION index=3210 start=0x40a4b96 */

undefined4 sub_40A4B96(void)

{
  int unaff_A6;
  
  if ((*(int *)(unaff_A6 + -0xd4) == -1) &&
     ((*(sword *)(unaff_A6 + -0xd8) == -0x4000 || (*(sword *)(unaff_A6 + -0xd8) == -0x4001)))) {
    return 0;
  }
  return 1;
}
/* GHIDRADEC_FUNCTION index=3211 start=0x40a4d76 */

void sub_40A4D76(void)

{
  byte bVar1;
  sword sVar2;
  byte *pbVar3;
  int unaff_A6;
  
  if ((*(byte *)(unaff_A6 + -0xdc) & 2) == 0) {
    pbVar3 = (byte *)(unaff_A6 + -0xcc);
  }
  else {
    pbVar3 = (byte *)(unaff_A6 + -0x10c);
  }
  bVar1 = *pbVar3;
  *pbVar3 = bVar1 & 0x7f;
  pbVar3[2] = -((bVar1 & 0x80) != 0);
  sVar2 = g_opcls();
  if (sVar2 == 3) {
    *(undefined *)(unaff_A6 + -0x54) = *(undefined *)(unaff_A6 + -0x7c);
    ovf_r_x3();
    *(undefined *)(unaff_A6 + -0x7c) = *(undefined *)(unaff_A6 + -0x54);
    store();
    return;
  }
  ovf_r_x2();
  store();
  return;
}
/* GHIDRADEC_FUNCTION index=3212 start=0x40a4eec */

void sub_40A4EEC(void)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  int unaff_A6;
  
  iVar1 = *(int *)(unaff_A6 + 0xc);
  uVar3 = (*(uint *)(unaff_A6 + -0xe4) & 0x1fffffff) >> 0x1a;
  if (uVar3 == 0) {
    iVar2 = 4;
    uVar3 = *(uint *)(unaff_A6 + -200) | 0x40000000;
    if (iVar1 != 0) {
      mem_write(uVar3);
      return;
    }
  }
  else if (uVar3 == 4) {
    iVar2 = 2;
    uVar3 = *(uint *)(unaff_A6 + -200) | 0x40000000;
    if (iVar1 != 0) {
      mem_write(uVar3);
      return;
    }
  }
  else {
    if (uVar3 != 6) {
      return;
    }
    iVar2 = 1;
    uVar3 = *(uint *)(unaff_A6 + -200) | 0x40000000;
    if (iVar1 != 0) {
      mem_write(uVar3);
      return;
    }
  }
  *(uint *)(unaff_A6 + -0x54) = uVar3;
  get_fline();
  if (iVar2 == 4) {
    reg_dest();
    return;
  }
  if (iVar2 == 2) {
    reg_dest();
    return;
  }
  reg_dest();
  return;
}
/* GHIDRADEC_FUNCTION index=3213 start=0x40a533c */

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

