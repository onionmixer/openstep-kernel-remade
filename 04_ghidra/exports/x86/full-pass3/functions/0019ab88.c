/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0019ab88 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0019ab88(int param_1,uint param_2,int param_3,undefined4 param_4,undefined4 param_5)

{
  byte bVar1;
  uint *puVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  undefined1 *puVar6;
  byte bVar7;
  int iVar8;
  undefined1 uVar9;
  undefined1 *puVar10;
  int iVar11;
  undefined4 uVar12;
  undefined4 uVar13;
  undefined4 uVar14;
  
  puVar2 = *(uint **)(param_1 + 0x1c);
  puVar2[0x2c] = 3;
  puVar2[0x2f] = 2;
  puVar2[0x2e] = 1;
  puVar2[0x2d] = 0;
  puVar2[0x2b] = puVar2[0x2e];
  puVar2[0x3d] = 0;
  iVar11 = 2;
  do {
    *(undefined1 *)(iVar11 + 0xf8 + (int)puVar2) = 0;
    iVar11 = iVar11 + -1;
  } while (-1 < iVar11);
  puVar2[0x3f] = (int)puVar2 + 0xf9;
  iVar11 = 0;
  do {
    out(0x3ce,(char)iVar11);
    LOCK();
    _DAT_001e8654 = _DAT_001e8654 + 1;
    UNLOCK();
    uVar9 = in(0x3cf);
    *(undefined1 *)((int)puVar2 + iVar11 + 0xd8) = uVar9;
    iVar11 = iVar11 + 1;
  } while (iVar11 < 9);
  out(0x3c4,2);
  LOCK();
  _DAT_001e8654 = _DAT_001e8654 + 1;
  UNLOCK();
  uVar9 = in(0x3c5);
  *(undefined1 *)((int)puVar2 + 0xe3) = uVar9;
  if ((param_2 - 1 < 2) && (param_3 != 0)) {
    _VGASetGraphicsMode();
  }
  bVar7 = DAT_001e4685;
  out(0x3c4,2);
  LOCK();
  UNLOCK();
  out(0x3c5,0xf);
  LOCK();
  _DAT_001e8654 = _DAT_001e8654 + 2;
  UNLOCK();
  iVar11 = 0;
  do {
    iVar8 = _DAT_001e8654;
    out(0x3ce,(char)iVar11);
    LOCK();
    UNLOCK();
    out(0x3cf,(&DAT_001e467c)[iVar11]);
    LOCK();
    _DAT_001e8654 = _DAT_001e8654 + 2;
    UNLOCK();
    iVar11 = iVar11 + 1;
  } while (iVar11 < 9);
  if ((param_3 != 0) && (*puVar2 != 3)) {
    uVar3 = puVar2[2];
    uVar4 = puVar2[4];
    out(0x3ce,0);
    LOCK();
    UNLOCK();
    out(0x3cf,(char)puVar2[0x2b]);
    LOCK();
    UNLOCK();
    out(0x3ce,8);
    LOCK();
    _DAT_001e8654 = iVar8 + 5;
    UNLOCK();
    uVar5 = puVar2[3];
    bVar1 = (&DAT_001e468d)[puVar2[3] & 7];
    puVar10 = (undefined1 *)puVar2[6];
    if ((int)uVar5 >> 3 == 0) {
      out(0x3cf,bVar1 & DAT_001e4685);
      LOCK();
      _DAT_001e8654 = iVar8 + 6;
      UNLOCK();
      while (uVar3 = uVar3 - 1, -1 < (int)uVar3) {
        *puVar10 = 0xff;
        puVar10 = puVar10 + uVar4;
      }
    }
    else {
      while (uVar3 = uVar3 - 1, -1 < (int)uVar3) {
        out(0x3cf,bVar7);
        LOCK();
        _DAT_001e8654 = _DAT_001e8654 + 1;
        UNLOCK();
        *puVar10 = 0xff;
        out(0x3cf,0xff);
        LOCK();
        _DAT_001e8654 = _DAT_001e8654 + 1;
        UNLOCK();
        puVar6 = puVar10;
        for (iVar11 = ((int)uVar5 >> 3) + -2; puVar6 = puVar6 + 1, -1 < iVar11; iVar11 = iVar11 + -1
            ) {
          *puVar6 = 0xff;
        }
        out(0x3cf,bVar1);
        LOCK();
        _DAT_001e8654 = _DAT_001e8654 + 1;
        UNLOCK();
        *puVar6 = 0xff;
        puVar10 = puVar10 + uVar4;
      }
    }
    out(0x3cf,0xff);
    LOCK();
    _DAT_001e8654 = _DAT_001e8654 + 1;
    UNLOCK();
  }
  *puVar2 = param_2;
  if (param_2 != 2) {
    if (param_2 < 3) {
      if (param_2 != 1) {
LAB_0019adf8:
                    /* WARNING: Subroutine does not return */
        _panic(s_VGAConsole_VGAInitConsole__can_t_001e46b9);
      }
      uVar14 = 0;
      uVar13 = 0x1c2;
      uVar12 = 600;
    }
    else {
      if (param_2 != 3) goto LAB_0019adf8;
      uVar14 = 1;
      uVar13 = 200;
      uVar12 = 0x140;
    }
    FUN_001995a4(puVar2,uVar12,uVar13,param_5,param_4,uVar14);
  }
  return;
}

