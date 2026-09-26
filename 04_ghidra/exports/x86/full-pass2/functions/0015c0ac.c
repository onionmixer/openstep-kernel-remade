/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0015c0ac */

void FUN_0015c0ac(int param_1)

{
  code *pcVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  
  uVar3 = _splsched();
  do {
  } while (DAT_001e5ba8 != 0);
  LOCK();
  UNLOCK();
  pcVar1 = *(code **)(param_1 + 0x20);
  uVar2 = *(undefined4 *)(param_1 + 0x24);
  *(undefined4 *)(param_1 + 0x2c) = 0;
  LOCK();
  DAT_001e5ba8 = 0;
  UNLOCK();
  _splx(uVar3);
  (*pcVar1)(uVar2);
  return;
}

