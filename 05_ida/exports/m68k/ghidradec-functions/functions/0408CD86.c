
byte sub_408CD86(int param_1)

{
  undefined *puVar1;
  int iVar2;
  uint uVar3;
  word *pwVar4;
  char cVar5;
  char cVar6;
  char cVar7;
  char cVar8;
  byte bVar9;
  word wStack_6;
  
  iVar2 = param_1 * 0x164;
  puVar1 = *(undefined **)(DAT_40b52d0 + iVar2 + 0xc);
  cVar5 = '\0';
  _delay(1);
  uVar3 = sub_408CE7E(*puVar1);
  wStack_6 = (word)(byte)uVar3;
  if (((*(uint *)(DAT_40b5420 + iVar2) ^ uVar3) & 8) != 0) {
    *(uint *)(DAT_40b5420 + iVar2) = *(uint *)(DAT_40b5420 + iVar2) ^ 8;
    if (((&DAT_40b5403)[iVar2] & 0x40) != 0) {
      sub_408CFC8(param_1);
    }
    if (((*(uint *)(DAT_40b5420 + iVar2) ^ uVar3 & 0xff) & 0x38) == 0) {
      return cVar5 << 4 | 4;
    }
  }
  pwVar4 = *(word **)(DAT_40b52d0 + iVar2 + 4) + 1;
  if (*(word **)(DAT_40b52d0 + iVar2) + dword_40B51A8 <= pwVar4) {
    pwVar4 = *(word **)(DAT_40b52d0 + iVar2);
  }
  cVar5 = pwVar4 < *(word **)(DAT_40b52d0 + iVar2 + 8);
  if (pwVar4 == *(word **)(DAT_40b52d0 + iVar2 + 8)) {
    *(uint *)(unk_40B5404 + iVar2) = *(uint *)(unk_40B5404 + iVar2) | 1;
  }
  else {
    **(word **)(DAT_40b52d0 + iVar2 + 4) = wStack_6;
    *(word **)(DAT_40b52d0 + iVar2 + 4) = pwVar4;
  }
  cVar8 = '\0';
  bVar9 = 0;
  cVar6 = *(int *)(unk_40B5404 + iVar2 + 0xc) < 0;
  cVar7 = '\0';
  if (*(int *)(unk_40B5404 + iVar2 + 0xc) == 0) {
    *(int *)(unk_40B5404 + iVar2 + 0xc) = (_hz / _hz) * 3;
    cVar6 = '\0';
    cVar7 = '\x01';
    cVar8 = '\0';
    bVar9 = 0;
    _callout_dispatch(0,sub_408C4D2,param_1);
  }
  return cVar5 << 4 | cVar6 << 3 | cVar7 << 2 | cVar8 << 1 | bVar9;
}
