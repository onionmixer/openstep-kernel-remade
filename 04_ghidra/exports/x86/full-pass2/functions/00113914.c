/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00113914 */

void _domaininit(void)

{
  uint uVar1;
  undefined4 *puVar2;
  
  DAT_001db2d4 = _domains;
  DAT_001dbcd0 = &_unixdomain;
  _domains = &_inetdomain;
  puVar2 = &_inetdomain;
  do {
    if ((code *)puVar2[2] != (code *)0x0) {
      (*(code *)puVar2[2])();
    }
    uVar1 = puVar2[5];
    if (uVar1 < (uint)puVar2[6]) {
      do {
        if (*(code **)(uVar1 + 0x20) != (code *)0x0) {
          (**(code **)(uVar1 + 0x20))();
        }
        uVar1 = uVar1 + 0x30;
      } while (uVar1 < (uint)puVar2[6]);
    }
    puVar2 = (undefined4 *)puVar2[7];
  } while (puVar2 != (undefined4 *)0x0);
  _null_init();
  _pffasttimo();
  _pfslowtimo();
  return;
}

