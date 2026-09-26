/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00197ca0 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 FUN_00197ca0(int param_1)

{
  byte bVar1;
  uint uVar2;
  byte *pbVar3;
  int iVar4;
  int iVar5;
  
  iVar5 = *(int *)(param_1 + 0x90) + *(int *)(param_1 + 0xa4) * 0xc;
  iVar4 = iVar5 + 0xc;
  out(0x3ce,7);
  LOCK();
  UNLOCK();
  out(0x3cf,0xf);
  LOCK();
  UNLOCK();
  out(0x3ce,5);
  LOCK();
  UNLOCK();
  out(0x3cf,8);
  LOCK();
  UNLOCK();
  out(0x3ce,2);
  LOCK();
  UNLOCK();
  out(0x3cf,*(undefined1 *)(param_1 + 0xb0));
  LOCK();
  _DAT_001e8654 = _DAT_001e8654 + 6;
  UNLOCK();
  uVar2 = iVar5 * *(int *)(param_1 + 0x10) + *(int *)(param_1 + 0x18);
  pbVar3 = (byte *)((*(int *)(param_1 + 0xa8) * 8 + *(int *)(param_1 + 0x8c) >> 3) + uVar2);
  for (; iVar5 < iVar4; iVar5 = iVar5 + 1) {
    bVar1 = *pbVar3;
    out(0x3ce,0);
    LOCK();
    UNLOCK();
    out(0x3cf,*(undefined1 *)(param_1 + 0xb0));
    LOCK();
    UNLOCK();
    out(0x3ce,8);
    LOCK();
    UNLOCK();
    out(0x3cf,~bVar1);
    LOCK();
    _DAT_001e8654 = _DAT_001e8654 + 4;
    UNLOCK();
    *pbVar3 = 0xff;
    out(0x3ce,0);
    LOCK();
    UNLOCK();
    out(0x3cf,*(undefined1 *)(param_1 + 0xb4));
    LOCK();
    UNLOCK();
    out(0x3ce,8);
    LOCK();
    UNLOCK();
    out(0x3cf,bVar1);
    LOCK();
    _DAT_001e8654 = _DAT_001e8654 + 4;
    UNLOCK();
    uVar2 = uVar2 & 0xffffff00;
    *pbVar3 = 0xff;
    pbVar3 = pbVar3 + *(int *)(param_1 + 0x10);
  }
  out(0x3ce,5);
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
  _DAT_001e8654 = _DAT_001e8654 + 4;
  UNLOCK();
  return CONCAT44(0x3cf,CONCAT31((int3)(uVar2 >> 8),0xff));
}

