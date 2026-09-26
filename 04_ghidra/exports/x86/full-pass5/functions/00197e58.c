/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00197e58 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 FUN_00197e58(int param_1,char param_2)

{
  int iVar1;
  byte bVar2;
  byte bVar3;
  char cVar4;
  uint uVar5;
  undefined4 uVar6;
  int iVar7;
  int iVar8;
  char *pcVar9;
  int iVar10;
  undefined1 *puVar11;
  undefined1 *local_28;
  
  iVar10 = _DAT_001e8654;
  uVar5 = *(int *)(param_1 + 0xa8) * 8 + *(int *)(param_1 + 0x8c);
  iVar7 = *(int *)(param_1 + 0x10);
  out(0x3ce,0);
  LOCK();
  UNLOCK();
  out(0x3cf,*(undefined1 *)(param_1 + 0xb0));
  LOCK();
  UNLOCK();
  out(0x3ce,8);
  LOCK();
  _DAT_001e8654 = _DAT_001e8654 + 3;
  UNLOCK();
  bVar2 = (&DAT_001e4685)[uVar5 & 7];
  bVar3 = (&DAT_001e468d)[uVar5 + 8 & 7];
  local_28 = (undefined1 *)
             ((*(int *)(param_1 + 0x90) + *(int *)(param_1 + 0xa4) * 0xc) * iVar7 +
              *(int *)(param_1 + 0x18) + ((int)uVar5 >> 3));
  iVar8 = ((int)(uVar5 + 8) >> 3) - ((int)uVar5 >> 3);
  if (iVar8 == 0) {
    out(0x3cf,bVar3 & bVar2);
    LOCK();
    _DAT_001e8654 = iVar10 + 4;
    UNLOCK();
    iVar10 = 0xb;
    do {
      *local_28 = 0xff;
      local_28 = local_28 + iVar7;
      iVar10 = iVar10 + -1;
    } while (-1 < iVar10);
  }
  else {
    iVar10 = 0xb;
    do {
      out(0x3cf,bVar2);
      LOCK();
      _DAT_001e8654 = _DAT_001e8654 + 1;
      UNLOCK();
      *local_28 = 0xff;
      out(0x3cf,0xff);
      LOCK();
      _DAT_001e8654 = _DAT_001e8654 + 1;
      UNLOCK();
      puVar11 = local_28;
      for (iVar1 = iVar8 + -2; puVar11 = puVar11 + 1, -1 < iVar1; iVar1 = iVar1 + -1) {
        *puVar11 = 0xff;
      }
      out(0x3cf,bVar3);
      LOCK();
      _DAT_001e8654 = _DAT_001e8654 + 1;
      UNLOCK();
      *puVar11 = 0xff;
      local_28 = local_28 + iVar7;
      iVar10 = iVar10 + -1;
    } while (-1 < iVar10);
  }
  iVar10 = _DAT_001e8654;
  uVar6 = CONCAT31((int3)((uint)iVar7 >> 8),0xff);
  out(0x3cf,0xff);
  LOCK();
  _DAT_001e8654 = _DAT_001e8654 + 1;
  UNLOCK();
  if ('\x1f' < param_2) {
    pcVar9 = s_Prima_di_spegnere_il_computer__a_001e406e + param_2 * 0xc + 0xe;
    out(0x3ce,0);
    LOCK();
    UNLOCK();
    out(0x3cf,*(undefined1 *)(param_1 + 0xb4));
    LOCK();
    UNLOCK();
    puVar11 = (undefined1 *)
              ((*(int *)(param_1 + 0x90) + *(int *)(param_1 + 0xa4) * 0xc) *
               *(int *)(param_1 + 0x10) + *(int *)(param_1 + 0x18) +
              (*(int *)(param_1 + 0xa8) * 8 + *(int *)(param_1 + 0x8c) >> 3));
    out(0x3ce,8);
    LOCK();
    _DAT_001e8654 = iVar10 + 4;
    UNLOCK();
    iVar7 = 0xc;
    do {
      cVar4 = *pcVar9;
      pcVar9 = pcVar9 + 1;
      out(0x3cf,cVar4);
      LOCK();
      _DAT_001e8654 = _DAT_001e8654 + 1;
      UNLOCK();
      *puVar11 = 0xff;
      puVar11 = puVar11 + *(int *)(param_1 + 0x10);
      iVar7 = iVar7 + -1;
    } while (iVar7 != 0);
    uVar6 = 0xff;
    out(0x3cf,0xff);
    LOCK();
    _DAT_001e8654 = _DAT_001e8654 + 1;
    UNLOCK();
    *(int *)(param_1 + 0xa8) = *(int *)(param_1 + 0xa8) + 1;
  }
  return CONCAT44(0x3cf,uVar6);
}

