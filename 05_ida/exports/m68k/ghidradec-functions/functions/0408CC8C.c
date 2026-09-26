
undefined4 sub_408CC8C(uint param_1)

{
  int iVar1;
  undefined *puVar2;
  uint uVar3;
  char cVar4;
  undefined2 extraout_D0u;
  undefined2 extraout_D0u_00;
  undefined2 uVar5;
  undefined4 uVar6;
  int iVar7;
  char cVar8;
  bool bVar9;
  char cVar10;
  char cVar11;
  char cVar12;
  byte bVar13;
  
  cVar12 = param_1 * 0x44 < param_1;
  iVar1 = param_1 * 0x86;
  puVar2 = unk_40B51BC + iVar1;
  iVar7 = param_1 * 0x164;
  *(undefined4 *)(DAT_40b540c + iVar7) = 0;
  bVar9 = (DAT_40b5308[iVar7 + 0xfa] & 1) == 0;
  if (bVar9) {
    uVar6 = CONCAT22((sword)(param_1 * 0x43 >> 0x10),(word)(byte)(cVar12 << 4 | bVar9 << 2));
  }
  else {
    uVar3 = *(uint *)(unk_40B51BC + iVar1 + 0x3e);
    *(uint *)(unk_40B51BC + iVar1 + 0x3e) = uVar3 & 0xffffffdf;
    if ((uVar3 & 8) == 0) {
      cVar12 = *(uint *)(DAT_40b5308 + iVar7) < *(uint *)(unk_40B51BC + iVar1 + 0x1c);
      _ndflush(iVar1 + 0x40b51d4,
               *(uint *)(DAT_40b5308 + iVar7) - *(uint *)(unk_40B51BC + iVar1 + 0x1c));
    }
    else {
      *(uint *)(unk_40B51BC + iVar1 + 0x3e) = uVar3 & 0xffffffd7;
    }
    cVar4 = unk_40B51BC[iVar1 + 0x45];
    if (cVar4 == '\0') {
      cVar8 = (int)puVar2 < 0;
      cVar10 = puVar2 == (undefined *)0x0;
      cVar11 = '\0';
      bVar13 = 0;
      sub_408CA1E(puVar2);
      uVar5 = extraout_D0u_00;
    }
    else {
      cVar12 = ((uint)(cVar4 * 3) >> 0x1c & 1) != 0;
      cVar8 = (int)puVar2 < 0;
      cVar10 = puVar2 == (undefined *)0x0;
      cVar11 = '\0';
      bVar13 = 0;
      (**(code **)(DAT_40ae4cc + cVar4 * 0x30))(puVar2);
      uVar5 = extraout_D0u;
    }
    uVar6 = CONCAT22(uVar5,(word)(byte)(cVar12 << 4 | cVar8 << 3 | cVar10 << 2 | cVar11 << 1 |
                                       bVar13));
  }
  return uVar6;
}
