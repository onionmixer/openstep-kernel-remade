/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0018335c */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void _sd_init_idmap(void)

{
  undefined4 *puVar1;
  undefined **ppuVar2;
  ushort uVar3;
  int *piVar4;
  ushort *puVar5;
  int iVar6;
  undefined4 *puVar7;
  
  puVar7 = &DAT_001e1268;
  for (piVar4 = &_bdevsw; piVar4 < &_bdevsw + _nblkdev * 6; piVar4 = piVar4 + 6) {
    if ((code *)*piVar4 == _sdopen) {
      DAT_001e7564 = (int)(piVar4 + -0x78b3d) * -0x55555555 >> 3;
      break;
    }
  }
  ppuVar2 = &_cdevsw;
  do {
    if (&_cdevsw + _nchrdev * 0xb <= ppuVar2) {
LAB_00183417:
      _bzero(&DAT_001e7324,0x240);
      iVar6 = 0;
      puVar5 = &DAT_001e7346;
      do {
        uVar3 = (short)iVar6 << 3;
        puVar5[-1] = DAT_001e7568 << 8 | uVar3;
        *puVar5 = (short)DAT_001e7564 << 8 | uVar3;
        puVar5 = puVar5 + 0x12;
        puVar1 = (undefined4 *)_IOMalloc(0x44);
        *puVar7 = puVar1;
        *puVar1 = 0;
        puVar7 = puVar7 + 1;
        iVar6 = iVar6 + 1;
      } while (iVar6 < 0x10);
      return;
    }
    if ((code *)*ppuVar2 == _sdopen) {
      _DAT_001e7568 = (int)(ppuVar2 + -0x78bce) * -0x45d1745d >> 2;
      goto LAB_00183417;
    }
    ppuVar2 = ppuVar2 + 0xb;
  } while( true );
}

