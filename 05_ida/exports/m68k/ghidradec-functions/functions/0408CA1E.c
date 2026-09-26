
byte sub_408CA1E(int param_1)

{
  undefined4 uVar1;
  uint uVar2;
  word wVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  char cVar8;
  char cVar9;
  char cVar10;
  char cVar11;
  byte bVar12;
  undefined auStack_c [8];
  
  iVar5 = _ttynty(param_1);
  wVar3 = *(word *)(param_1 + 0x38);
  uVar4 = wVar3 & 0x1f;
  iVar6 = uVar4 * 0x164;
  cVar8 = '\0';
  uVar7 = *(uint *)(param_1 + 0x3e);
  cVar11 = '\0';
  bVar12 = 0;
  cVar9 = '\0';
  cVar10 = '\0';
  if ((uVar7 & 0x121) == 0) {
    cVar8 = (uint)(int)*(sword *)(_ttlowat + (*(byte *)(param_1 + 0x48) & 0x1f) * 2) <
            *(uint *)(param_1 + 0x18);
    if ((int)*(uint *)(param_1 + 0x18) <=
        (int)*(sword *)(_ttlowat + (*(byte *)(param_1 + 0x48) & 0x1f) * 2)) {
      if ((uVar7 & 0x40) != 0) {
        *(uint *)(param_1 + 0x3e) = uVar7 & 0xffffffbf;
        _wakeup(param_1 + 0x18);
      }
      if (*(int *)(param_1 + 0x2c) != 0) {
        _selwakeup(*(int *)(param_1 + 0x2c),*(uint *)(param_1 + 0x3e) & 0x1000);
        _thread_deallocate_interrupt(*(undefined4 *)(param_1 + 0x2c));
        *(undefined4 *)(param_1 + 0x2c) = 0;
        *(word *)(param_1 + 0x40) = *(word *)(param_1 + 0x40) & 0xefff;
      }
    }
    cVar11 = '\0';
    bVar12 = 0;
    cVar9 = *(int *)(param_1 + 0x18) < 0;
    cVar10 = *(int *)(param_1 + 0x18) == 0;
    if (!(bool)cVar10) {
      if ((((*(uint *)(param_1 + 0x3a) & 0x2200020) == 0) &&
          ((*(uint *)(iVar5 + 0x10) & 0x10000000) != 0)) &&
         (uVar7 = *(uint *)(iVar5 + 0x10) & 0x300, cVar8 = uVar7 < 0x300, uVar7 != 0x300)) {
        uVar7 = _ndqb(param_1 + 0x18,0x80);
        if (uVar7 == 0) {
          uVar7 = _getc(param_1 + 0x18);
          _ticks_to_timeval((uVar7 & 0x7f) + 6,auStack_c);
          _us_timeout(_ttrstrt,param_1,auStack_c,0);
          cVar11 = '\0';
          bVar12 = 0;
          uVar7 = *(uint *)(param_1 + 0x3e) | 1;
          *(uint *)(param_1 + 0x3e) = uVar7;
          cVar9 = (int)uVar7 < 0;
          cVar10 = uVar7 == 0;
          goto loc_408CB9E;
        }
      }
      else {
        uVar7 = _ndqb(param_1 + 0x18,0);
      }
      *(uint *)(param_1 + 0x3e) = *(uint *)(param_1 + 0x3e) | 0x20;
      uVar1 = *(undefined4 *)(param_1 + 0x1c);
      *(undefined4 *)(unk_40B52E0 + iVar6 + 0x100) = uVar1;
      *(undefined4 *)(unk_40B52E0 + iVar6 + 0x28) = uVar1;
      *(undefined4 *)(unk_40B52E0 + iVar6 + 0xfc) = *(undefined4 *)(unk_40B52E0 + iVar6 + 0x28);
      uVar2 = *(uint *)(unk_40B52E0 + iVar6 + 0x100);
      cVar8 = CARRY4(uVar7,uVar2);
      *(uint *)(unk_40B52E0 + iVar6 + 0x100) = uVar7 + uVar2;
      if ((unk_40B52E0[iVar6 + 0x123] & 1) == 0) {
        cVar8 = '\0';
        cVar9 = '\0';
        cVar10 = (wVar3 & 0x1f) == 0;
        cVar11 = '\0';
        bVar12 = 0;
        sub_408CBAC(uVar4);
      }
      else {
        cVar9 = '\0';
        cVar10 = '\x01';
        cVar11 = '\0';
        bVar12 = 0;
        _dma_start(unk_40B52E0 + iVar6,iVar6 + 0x40b53d8,0);
      }
    }
  }
loc_408CB9E:
  return cVar8 << 4 | cVar9 << 3 | cVar10 << 2 | cVar11 << 1 | bVar12;
}
