
void sub_408AA58(int param_1)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  undefined *puVar8;
  undefined *puVar9;
  undefined *puVar10;
  uint uStack_8;
  
  if (_dma_chip == 0x139) {
    puVar10 = (undefined *)(_slot_id_bmap + 0x2018100);
    puVar9 = (undefined *)(_slot_id_bmap + 0x2018101);
    puVar8 = (undefined *)(_slot_id_bmap + 0x2018103);
  }
  else {
    puVar10 = (undefined *)(_slot_id + 0x201c000);
    puVar9 = (undefined *)(_slot_id + 0x201c001);
    puVar8 = (undefined *)(_slot_id + 0x201c003);
  }
  uVar6 = (uint)(param_1 << 6) / 0x3d;
  iVar4 = 0;
  iVar7 = 0;
  do {
    uStack_8 = (uint)(byte)unk_40B2310[iVar7];
    uVar5 = uVar6 * uStack_8 >> 6;
    uVar3 = uVar6 * (byte)unk_40B2320[iVar7] >> 6;
    uVar2 = uVar6 * (byte)unk_40B2330[iVar7] >> 6;
    if (0xff < uVar5) {
      uVar5 = 0xff;
    }
    if (0xff < uVar3) {
      uVar3 = 0xff;
    }
    if (0xff < uVar2) {
      uVar2 = 0xff;
    }
    iVar1 = 0;
    do {
      *puVar10 = (char)iVar4;
      *puVar9 = (char)((uint)iVar4 >> 8);
      *puVar8 = (char)uVar5;
      *puVar8 = (char)uVar3;
      *puVar8 = (char)uVar2;
      iVar4 = iVar4 + 1;
      iVar1 = iVar1 + 1;
    } while (iVar1 < 0x10);
    iVar7 = iVar7 + 1;
  } while (iVar7 < 0x10);
  return;
}
