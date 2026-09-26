/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00187d48 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

longlong FUN_00187d48(void)

{
  ushort uVar1;
  undefined1 uVar2;
  undefined1 uVar3;
  undefined4 uVar4;
  uint uVar5;
  int iVar6;
  ushort uVar7;
  int iVar8;
  longlong lVar9;
  uint local_14;
  int local_10;
  
  uVar4 = _splusclock();
  uVar1 = DAT_001e75d8;
  local_10 = DAT_001e75d4;
  uVar5 = DAT_001e75d0;
  local_14 = DAT_001e75d0;
  out(0x43,0);
  LOCK();
  _DAT_001e75c4 = _DAT_001e75c4 + 1;
  UNLOCK();
  uVar2 = in(0x40);
  uVar3 = in(0x40);
  uVar7 = CONCAT11(uVar3,uVar2);
  DAT_001e75d8 = uVar7;
  _splx(uVar4);
  if (uVar1 < uVar7) {
    local_14 = uVar5 + 10000000;
    local_10 = local_10 + (uint)(0xff67697f < uVar5);
  }
  uVar5 = (uint)DAT_001e75da - (uint)uVar7;
  iVar6 = (int)uVar5 >> 0x1f;
  iVar8 = ((iVar6 << 5 | uVar5 >> 0x1b) - iVar6) - (uint)(uVar5 * 0x20 < uVar5);
  iVar6 = ((((iVar8 * 0x40 | uVar5 * 0x1f >> 0x1a) - iVar8) - (uint)(uVar5 * 0x7c0 < uVar5 * 0x1f))
           * 8 | uVar5 * 0x7a1 >> 0x1d) + iVar6 + (uint)CARRY4(uVar5 * 0x3d08,uVar5);
  iVar6 = iVar6 + (iVar6 * 4 | uVar5 * 0x3d09 >> 0x1e) + (uint)CARRY4(uVar5 * 0x3d09,uVar5 * 0xf424)
  ;
  iVar6 = iVar6 + (iVar6 * 4 | uVar5 * 0x1312d >> 0x1e) +
          (uint)CARRY4(uVar5 * 0x1312d,uVar5 * 0x4c4b4);
  lVar9 = __udivdi3(uVar5 * 1000000000,
                    ((iVar6 * 4 | uVar5 * 0x5f5e1 >> 0x1e) + iVar6 +
                    (uint)CARRY4(uVar5 * 0x17d784,uVar5 * 0x5f5e1)) * 0x200 |
                    uVar5 * 0x1dcd65 >> 0x17,0x1234cf,0);
  return lVar9 + CONCAT44(local_10,local_14);
}

