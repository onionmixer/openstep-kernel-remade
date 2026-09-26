
/* WARNING: Removing unreachable block (ram,0xf002f438) */
/* WARNING: Removing unreachable block (ram,0xf002f3f8) */
/* WARNING: Removing unreachable block (ram,0xf002f3ec) */
/* WARNING: Removing unreachable block (ram,0xf002f41c) */
/* WARNING: Removing unreachable block (ram,0xf002f450) */
/* WARNING: Removing unreachable block (ram,0xf002f3d4) */

undefined8 _inet_ntoa(undefined4 *param_1,undefined4 param_2)

{
  byte bVar2;
  uint uVar1;
  undefined4 unaff_l0;
  undefined *puVar3;
  char *pcVar4;
  undefined4 unaff_l1;
  byte *pbVar5;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  int iVar6;
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
  byte abStack_c [12];
  
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
  puVar3 = unk_F012F430;
  pbVar5 = (byte *)((int)register0x00000038 + -0xc);
  iVar6 = 0;
  *(undefined4 *)((int)register0x00000038 + -0xc) = *param_1;
  do {
    if (iVar6 != 0) {
      *puVar3 = '.';
      puVar3 = puVar3 + 1;
    }
    bVar2 = *pbVar5;
    pcVar4 = puVar3;
    if (99 < bVar2) {
      .udiv(bVar2,100);
      *puVar3 = bVar2 + 0x30;
      pcVar4 = puVar3 + 1;
      uVar1 = (uint)*pbVar5;
      .urem(uVar1,100);
      uVar1 = uVar1 & 0xff;
      .udiv(uVar1,10);
      if ((uVar1 & 0xff) == 0) {
        *pcVar4 = '0';
        pcVar4 = puVar3 + 2;
        bVar2 = *pbVar5;
      }
      else {
        bVar2 = *pbVar5;
      }
      .urem(bVar2,100);
      *pbVar5 = bVar2;
      bVar2 = *pbVar5;
    }
    if (9 < bVar2) {
      .udiv(bVar2,10);
      *pcVar4 = bVar2 + 0x30;
      pcVar4 = pcVar4 + 1;
      bVar2 = *pbVar5;
      .urem(bVar2,10);
      *pbVar5 = bVar2;
    }
    iVar6 = iVar6 + 1;
    *pcVar4 = *pbVar5 + 0x30;
    puVar3 = pcVar4 + 1;
    pbVar5 = pbVar5 + 1;
  } while (iVar6 < 4);
  *puVar3 = '\0';
  return CONCAT44(param_2,unk_F012F430);
}
