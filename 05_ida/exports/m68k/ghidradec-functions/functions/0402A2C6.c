
int sub_402A2C6(int param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  byte bVar2;
  byte bVar3;
  int iVar4;
  int iVar5;
  undefined4 uVar6;
  undefined *puVar7;
  int iStack_194;
  undefined4 uStack_190;
  undefined auStack_18c [4];
  undefined4 uStack_188;
  undefined4 uStack_184;
  undefined2 uStack_180;
  byte bStack_17e;
  byte bStack_17d;
  undefined2 uStack_17c;
  undefined uStack_17a;
  undefined uStack_179;
  int iStack_178;
  int iStack_174;
  int iStack_170;
  undefined4 uStack_16c;
  int iStack_168;
  uint uStack_164;
  int iStack_160;
  uint uStack_15c;
  undefined4 uStack_158;
  undefined auStack_154 [256];
  undefined auStack_54 [32];
  sword asStack_34 [8];
  undefined auStack_24 [32];
  
  iStack_194 = 0;
  if ((*(byte *)(param_1 + 0xf) & 0x40) != 0) {
    return 0;
  }
  iVar4 = _copyinmsg(param_3,&uStack_188,0x34);
  if (iVar4 != 0) goto loc_402A552;
  iVar4 = _copyinmsg(uStack_188,asStack_34,0x10);
  if (iVar4 != 0) goto loc_402A552;
  if (asStack_34[0] != 2) {
    iVar4 = 0x2e;
    goto loc_402A552;
  }
  iVar4 = _copyinmsg(uStack_184,auStack_24,0x20);
  if (iVar4 != 0) goto loc_402A552;
  if ((bStack_17d & 0x20) == 0) {
    sub_402A990(asStack_34,auStack_54);
  }
  else {
    iVar4 = _copyinstr(uStack_16c,auStack_54,0x20,auStack_18c);
    if (iVar4 != 0) goto loc_402A552;
  }
  if ((bStack_17e & 0x10) == 0) {
    uStack_190 = 0xffffffff;
  }
  else {
    _copyinstr(uStack_158,auStack_154,0x100,&uStack_190);
  }
  iVar4 = sub_402A56C(&iStack_194,param_1,asStack_34,auStack_24,auStack_54,auStack_154,uStack_190,
                      CONCAT31(CONCAT21(uStack_180,bStack_17e),bStack_17d));
  if (iVar4 != 0) {
    return iVar4;
  }
  iVar1 = *(int *)(*(int *)(iStack_194 + 0x24) + 0x126);
  bVar2 = *(byte *)(iVar1 + 0x14);
  bVar3 = (bStack_17d >> 7) << 3;
  *(byte *)(iVar1 + 0x14) = bVar2 & 0xf7 | bVar3;
  *(byte *)(iVar1 + 0x14) =
       bVar2 & 0xf3 | bVar3 |
       (byte)(((CONCAT22(CONCAT11(bStack_17e,bStack_17d),uStack_17c) & 0x3fffffff) >> 0x1d) << 2);
  if ((((bStack_17d & 0x10) != 0) && (*(int *)(iVar1 + 0x2e) = iStack_170, iStack_170 < 0)) ||
     (((bStack_17d & 8) != 0 && (*(int *)(iVar1 + 0x2a) = iStack_174, iStack_174 < 1)))) {
loc_402A448:
    iVar4 = 0x16;
    goto loc_402A552;
  }
  if ((bStack_17d & 4) != 0) {
    if (iStack_178 < 1) goto loc_402A448;
    iVar4 = *(int *)(iVar1 + 0x1a);
    if (iStack_178 < *(int *)(iVar1 + 0x1a)) {
      iVar4 = iStack_178;
    }
    *(int *)(iVar1 + 0x1a) = iVar4;
  }
  if ((bStack_17d & 2) != 0) {
    iVar4 = CONCAT31(CONCAT21(uStack_17c,uStack_17a),uStack_179);
    if (iVar4 < 1) goto loc_402A448;
    iVar5 = *(int *)(iVar1 + 0x1e);
    if (iVar4 < *(int *)(iVar1 + 0x1e)) {
      iVar5 = iVar4;
    }
    *(int *)(iVar1 + 0x1e) = iVar5;
  }
  if ((bStack_17e & 1) == 0) {
loc_402A496:
    if ((bStack_17e & 2) != 0) {
      if ((int)uStack_164 < 0) {
        *(undefined4 *)(iVar1 + 0x62) = 36000;
      }
      else {
        if (uStack_164 < *(uint *)(iVar1 + 0x5e)) {
          puVar7 = aNfsMountAcregm_0;
          goto loc_402A530;
        }
        uVar6 = _min(uStack_164,36000);
        *(undefined4 *)(iVar1 + 0x62) = uVar6;
      }
    }
    if ((bStack_17e & 4) != 0) {
      if (iStack_160 < 0) {
        *(undefined4 *)(iVar1 + 0x66) = 0xe10;
      }
      else {
        if (iStack_160 == 0) {
          puVar7 = aNfsMountAcdirm;
          goto loc_402A530;
        }
        uVar6 = _min(iStack_160,0xe10);
        *(undefined4 *)(iVar1 + 0x66) = uVar6;
      }
    }
    iVar4 = 0;
    if ((bStack_17e & 8) != 0) {
      if ((int)uStack_15c < 0) {
        *(undefined4 *)(iVar1 + 0x6a) = 36000;
      }
      else {
        if (uStack_15c < *(uint *)(iVar1 + 0x66)) {
          puVar7 = aNfsMountAcdirm_0;
          goto loc_402A530;
        }
        uVar6 = _min(uStack_15c,36000);
        *(undefined4 *)(iVar1 + 0x6a) = uVar6;
      }
    }
  }
  else {
    if (iStack_168 < 0) {
      *(undefined4 *)(iVar1 + 0x5e) = 0xe10;
      goto loc_402A496;
    }
    if (iStack_168 != 0) {
      uVar6 = _min(iStack_168,0xe10);
      *(undefined4 *)(iVar1 + 0x5e) = uVar6;
      goto loc_402A496;
    }
    puVar7 = aNfsMountAcregm;
loc_402A530:
    iVar4 = 0x16;
    _printf(puVar7);
  }
  if (iVar4 == 0) {
    return 0;
  }
loc_402A552:
  if (iStack_194 != 0) {
    _vn_rele(iStack_194);
  }
  return iVar4;
}
