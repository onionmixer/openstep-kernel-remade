/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0015b9b0 */

undefined4 _lock_write_to_read(int param_1)

{
  int *piVar1;
  int iVar2;
  undefined4 uVar3;
  ushort uVar4;
  byte bVar5;
  
  piVar1 = (int *)(param_1 + 8);
  do {
    do {
    } while (*piVar1 != 0);
    LOCK();
    iVar2 = *piVar1;
    *piVar1 = 1;
    UNLOCK();
  } while (iVar2 == 1);
  *(short *)(param_1 + 4) = *(short *)(param_1 + 4) + 1;
  uVar4 = *(ushort *)(param_1 + 6);
  if ((uVar4 & 0xfff0) == 0) {
    if ((*(byte *)(param_1 + 6) & 1) == 0) {
      bVar5 = 0xfd;
    }
    else {
      bVar5 = 0xfe;
    }
    *(byte *)(param_1 + 6) = *(byte *)(param_1 + 6) & bVar5;
  }
  else {
    *(ushort *)(param_1 + 6) = uVar4 & 0xf | (uVar4 & 0xfff0) - 0x10;
  }
  if ((*(byte *)(param_1 + 6) & 4) != 0) {
    *(byte *)(param_1 + 6) = *(byte *)(param_1 + 6) & 0xfb;
    _thread_wakeup_prim(param_1,0,0);
  }
  LOCK();
  uVar3 = *(undefined4 *)(param_1 + 8);
  *(undefined4 *)(param_1 + 8) = 0;
  UNLOCK();
  return uVar3;
}

