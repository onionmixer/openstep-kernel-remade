
/* WARNING: Removing unreachable block (ram,0xf00303a8) */
/* WARNING: Removing unreachable block (ram,0xf0030338) */
/* WARNING: Removing unreachable block (ram,0xf0030350) */
/* WARNING: Removing unreachable block (ram,0xf00303bc) */
/* WARNING: Removing unreachable block (ram,0xf0030314) */

undefined8 sub_F0030300(undefined4 param_1,int param_2,int param_3)

{
  byte bVar1;
  uint uVar2;
  int iVar3;
  char cVar4;
  undefined4 unaff_l0;
  char *pcVar5;
  undefined4 unaff_l1;
  int iVar6;
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
  *(undefined4 *)((int)register0x00000038 + -0xc) = 1;
  iVar6 = 0;
  uVar2 = param_3 + 0xf4U;
  _strlen();
  if (0x37 < uVar2) {
    *(undefined *)(param_3 + 299) = 0;
  }
  _printf(&aS_1,param_3 + 0xf4U);
  iVar3 = 0;
  _kmioctl(0,0x80047410,(undefined *)((int)register0x00000038 + -0xc),0);
  if (iVar3 != 0) goto locret_F003042C;
  bVar1 = *(byte *)(param_3 + 0xf2);
  if (bVar1 == 2) {
    iVar6 = 1;
  }
  else {
    if (2 < bVar1) {
      if (bVar1 == 3) {
        *(undefined4 *)(param_2 + 0x10) = 0xffffffff;
        *(undefined *)(param_2 + 0x10e) = 0;
        *(undefined *)(param_2 + 0x10f) = 0;
      }
      goto locret_F003042C;
    }
    if (bVar1 != 1) goto locret_F003042C;
  }
  iVar3 = 0;
  pcVar5 = (char *)(param_2 + 0x110);
  sub_F003059C(pcVar5,pcVar5,iVar6);
  if (iVar6 != 0) {
    _printf(&asc_F010C598);
  }
  if (*(char *)(param_2 + 0x110) != '\0') {
    cVar4 = *pcVar5;
    do {
      if ((cVar4 == '\n') || (cVar4 == '\r')) {
        *pcVar5 = '\0';
        break;
      }
      pcVar5 = pcVar5 + 1;
      cVar4 = *pcVar5;
    } while (cVar4 != '\0');
  }
  *(undefined4 *)(param_2 + 0x10) = *(undefined4 *)(param_3 + 0x14);
  *(undefined *)(param_2 + 0x10e) = *(undefined *)(param_3 + 0xf2);
  *(undefined *)(param_2 + 0x10f) = *(undefined *)(param_3 + 0xf3);
locret_F003042C:
  return CONCAT44(param_2,iVar3);
}

