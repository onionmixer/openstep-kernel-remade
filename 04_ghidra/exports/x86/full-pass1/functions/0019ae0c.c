/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0019ae0c */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_0019ae0c(int param_1)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  byte bVar4;
  undefined4 uVar5;
  int iVar6;
  undefined1 *puVar7;
  undefined1 *puVar8;
  int local_28;
  undefined1 *local_24;
  int local_20;
  undefined1 *local_10;
  
  piVar1 = *(int **)(param_1 + 0x1c);
  if (*piVar1 == 3) {
    if (piVar1[0x40] == 0) {
      puVar7 = (undefined1 *)piVar1[0x31];
      puVar8 = (undefined1 *)piVar1[0x35];
      out(0x3ce,5);
      LOCK();
      UNLOCK();
      bVar4 = in(0x3cf);
      out(0x3ce,5);
      LOCK();
      UNLOCK();
      out(0x3cf,bVar4 & 0xfc | 1);
      LOCK();
      _DAT_001e8654 = _DAT_001e8654 + 3;
      UNLOCK();
      local_20 = piVar1[0x32];
      if (local_20 != 0) {
        iVar2 = piVar1[0x33];
        iVar3 = piVar1[4];
        iVar6 = iVar2;
        local_10 = puVar7;
        local_24 = puVar8;
        do {
          for (; iVar6 != 0; iVar6 = iVar6 + -1) {
            *puVar8 = *puVar7;
            puVar7 = puVar7 + 1;
            puVar8 = puVar8 + 1;
          }
          puVar8 = local_24 + iVar3;
          puVar7 = local_10 + iVar2;
          local_20 = local_20 + -1;
          iVar6 = iVar2;
          local_10 = puVar7;
          local_24 = puVar8;
        } while (local_20 != 0);
      }
    }
    else {
      puVar7 = (undefined1 *)piVar1[0x31];
      out(0x3ce,5);
      LOCK();
      UNLOCK();
      bVar4 = in(0x3cf);
      out(0x3ce,5);
      LOCK();
      UNLOCK();
      out(0x3cf,bVar4 & 0xfc);
      LOCK();
      UNLOCK();
      out(0x3ce,1);
      LOCK();
      UNLOCK();
      out(0x3cf,0);
      LOCK();
      UNLOCK();
      out(0x3ce,8);
      LOCK();
      UNLOCK();
      out(0x3cf,0xff);
      LOCK();
      UNLOCK();
      out(0x3c4,2);
      LOCK();
      UNLOCK();
      out(0x3c5,1);
      LOCK();
      _DAT_001e8654 = _DAT_001e8654 + 9;
      UNLOCK();
      puVar8 = (undefined1 *)piVar1[0x35];
      local_20 = piVar1[0x32];
      local_10 = puVar7;
      if (local_20 != 0) {
        iVar2 = piVar1[0x33];
        iVar3 = piVar1[4];
        iVar6 = iVar2;
        local_24 = puVar8;
        do {
          for (; iVar6 != 0; iVar6 = iVar6 + -1) {
            *puVar8 = *puVar7;
            puVar7 = puVar7 + 1;
            puVar8 = puVar8 + 1;
          }
          puVar8 = local_24 + iVar3;
          puVar7 = local_10 + iVar2;
          local_20 = local_20 + -1;
          iVar6 = iVar2;
          local_10 = puVar7;
          local_24 = puVar8;
        } while (local_20 != 0);
      }
      out(0x3c4,2);
      LOCK();
      UNLOCK();
      out(0x3c5,2);
      LOCK();
      _DAT_001e8654 = _DAT_001e8654 + 2;
      UNLOCK();
      puVar8 = (undefined1 *)piVar1[0x35];
      local_20 = piVar1[0x32];
      if (local_20 != 0) {
        iVar2 = piVar1[0x33];
        iVar3 = piVar1[4];
        iVar6 = iVar2;
        puVar7 = local_10;
        local_24 = puVar8;
        do {
          for (; iVar6 != 0; iVar6 = iVar6 + -1) {
            *puVar8 = *puVar7;
            puVar7 = puVar7 + 1;
            puVar8 = puVar8 + 1;
          }
          puVar8 = local_24 + iVar3;
          puVar7 = local_10 + iVar2;
          local_20 = local_20 + -1;
          iVar6 = iVar2;
          local_10 = puVar7;
          local_24 = puVar8;
        } while (local_20 != 0);
      }
    }
    local_28 = 0;
    do {
      iVar2 = _DAT_001e8654;
      out(0x3ce,(char)local_28);
      LOCK();
      UNLOCK();
      out(0x3cf,*(undefined1 *)((int)piVar1 + local_28 + 0xd8));
      LOCK();
      _DAT_001e8654 = _DAT_001e8654 + 2;
      UNLOCK();
      local_28 = local_28 + 1;
    } while (local_28 < 9);
    out(0x3c4,2);
    LOCK();
    UNLOCK();
    out(0x3c5,*(undefined1 *)((int)piVar1 + 0xe3));
    LOCK();
    _DAT_001e8654 = iVar2 + 4;
    UNLOCK();
    *piVar1 = 0;
    uVar5 = 0;
  }
  else {
    _IOLog(s_VGAConsole__bogus_restore__mode___001e46df,*piVar1);
    uVar5 = 0xffffffff;
  }
  return uVar5;
}

