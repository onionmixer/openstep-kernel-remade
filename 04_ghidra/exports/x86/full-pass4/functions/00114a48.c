/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00114a48 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void _mclput(int param_1)

{
  char cVar1;
  int iVar2;
  undefined4 *puVar3;
  
  if (*(short *)(param_1 + 0xc) == 1) {
    puVar3 = (undefined4 *)(param_1 + *(int *)(param_1 + 4) & 0xfffffc00);
    iVar2 = (int)puVar3 - __mbutl >> 10;
    cVar1 = (&_mclrefcnt)[iVar2];
    (&_mclrefcnt)[iVar2] = cVar1 + -1;
    if (cVar1 == '\x01') {
      *puVar3 = _mclfree;
      _DAT_001e916c = _DAT_001e916c + 1;
      _mclfree = puVar3;
    }
  }
  else {
    if (*(short *)(param_1 + 0xc) != 2) {
                    /* WARNING: Subroutine does not return */
      _panic(s_mclput_001db219);
    }
    (**(code **)(param_1 + 0x10))(*(undefined4 *)(param_1 + 0x14));
  }
  return;
}

