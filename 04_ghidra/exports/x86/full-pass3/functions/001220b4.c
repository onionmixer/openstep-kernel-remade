/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001220b4 */

void _arptimer(void)

{
  byte bVar1;
  byte *pbVar2;
  int iVar3;
  undefined *puVar4;
  
  _timeout(0x1220b4);
  puVar4 = &_arptab;
  iVar3 = 0;
  pbVar2 = &DAT_001e9c8b;
  do {
    if ((*pbVar2 != 0) && ((*pbVar2 & 4) == 0)) {
      bVar1 = pbVar2[-1];
      pbVar2[-1] = bVar1 + 1;
      bVar1 = bVar1 + 1;
      if ((*pbVar2 & 2) == 0) {
        if (2 < bVar1) goto LAB_00122111;
      }
      else if (0x13 < bVar1) {
LAB_00122111:
        _arptfree(puVar4);
      }
    }
    iVar3 = iVar3 + 1;
    pbVar2 = pbVar2 + 0x14;
    puVar4 = puVar4 + 0x14;
    if (0xaa < iVar3) {
      return;
    }
  } while( true );
}

