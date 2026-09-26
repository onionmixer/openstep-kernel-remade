/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0011dd98 */

void _vhangup(void)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  undefined4 auStack_9c [34];
  undefined4 uStack_14;
  int iStack_10;
  
  iStack_10 = 0x11dda2;
  iVar1 = _suser();
  if ((iVar1 != 0) && (*(int *)(_active_u + 0x168) != 0)) {
    iStack_10 = (int)*(short *)(_active_u + 0x16c);
    uStack_14 = 0x11ddc1;
    _forceclose();
    uStack_14 = 1;
    puVar2 = *(undefined4 **)(_active_u + 0x168);
    puVar3 = auStack_9c;
    for (iVar1 = 0x22; iVar1 != 0; iVar1 = iVar1 + -1) {
      *puVar3 = *puVar2;
      puVar2 = puVar2 + 1;
      puVar3 = puVar3 + 1;
    }
    _gsignal();
  }
  return;
}

