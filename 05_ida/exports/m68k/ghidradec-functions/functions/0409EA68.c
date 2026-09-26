
/* WARNING: Removing unreachable block (ram,0x0409eb56) */
/* WARNING: Removing unreachable block (ram,0x0409eaf0) */

sqword dnrm_lp(void)

{
  sword sVar1;
  int in_D0;
  uint uVar2;
  undefined2 uVar3;
  undefined3 uVar4;
  undefined4 in_D1;
  sword sVar8;
  uint uVar6;
  undefined4 uVar7;
  uint *in_A0;
  int unaff_A6;
  int iVar5;
  
  if ((*(byte *)(unaff_A6 + -0xdc) & 2) != 0) {
    in_D0 = (*(uint *)(unaff_A6 + -0xe8) & 0x3800000) << 6;
  }
  *(uint *)(unaff_A6 + -0x5c) = in_A0[2];
  *(int *)(unaff_A6 + -0x58) = in_D0;
  sVar8 = (sword)in_D1;
  sVar1 = sVar8 - *(sword *)in_A0;
  uVar3 = (undefined2)((uint)in_D1 >> 0x10);
  iVar5 = CONCAT22(uVar3,sVar1);
  uVar4 = (undefined3)((uint)iVar5 >> 8);
  if (sVar1 == 0 || sVar8 < *(sword *)in_A0) {
    return (qword)CONCAT43(*(undefined4 *)(unaff_A6 + -0x58),uVar4) << 8;
  }
  if (sVar1 < 0x20) {
    *(sword *)in_A0 = sVar8;
    in_A0[1] = (uint)(0 << iVar5) >> 0x20 - (uint)(word)(0x20 - sVar1);
    in_A0[2] = 0;
    uVar2 = 0;
    if ((*(uint *)(unaff_A6 + -0x58) & 0xe0000000) != 0) {
      uVar2 = 0x20000000;
    }
    return (qword)uVar2 << 0x20;
  }
  if (sVar1 < 0x40) {
    *(sword *)in_A0 = sVar8;
    uVar2 = 0;
    in_A0[1] = 0;
    in_A0[2] = (uint)(0 << CONCAT22(uVar3,sVar1 + -0x20)) >>
               0x20 - (uint)(word)(0x20 - (sVar1 + -0x20));
    if ((*(uint *)(unaff_A6 + -0x58) & 0xe0000000) != 0) {
      uVar2 = 0x20000000;
    }
    return (qword)uVar2 << 0x20;
  }
  *(sword *)in_A0 = sVar8;
  if ((sword)*in_A0 < 0) {
    *in_A0 = *in_A0 | 0x80000000;
  }
  if (sVar1 == 0x40) {
    uVar6 = in_A0[1] & 0x3fffffff;
    uVar2 = in_A0[1] & 0xc0000000;
  }
  else {
    if (sVar1 != 0x41) {
      in_A0[1] = 0;
      in_A0[2] = 0;
      return CONCAT44(0x20000000,CONCAT31(uVar4,0xff));
    }
    uVar6 = in_A0[1] & 0x7fffffff;
    uVar2 = (in_A0[1] & 0x80000000) >> 1;
  }
  if (((uVar6 == 0) && (in_A0[2] == 0)) && (*(char *)(unaff_A6 + -0x58) == '\0')) {
    uVar7 = 0;
  }
  else {
    uVar2 = uVar2 | 0x20000000;
    uVar7 = CONCAT31((int3)(uVar6 >> 8),0xff);
  }
  in_A0[1] = 0;
  in_A0[2] = 0;
  return CONCAT44(uVar2,uVar7);
}
