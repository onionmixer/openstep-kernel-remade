/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001d03c8 */

void __sel_init(undefined4 param_1,int param_2,int param_3,undefined4 param_4)

{
  undefined *puVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 *puVar4;
  undefined **ppuVar5;
  
  iVar2 = _NXDefaultMallocZone();
  uVar3 = _NXDefaultMallocZone(0x1c);
  puVar4 = (undefined4 *)(**(code **)(iVar2 + 4))(uVar3);
  *puVar4 = param_1;
  puVar4[1] = 0x335;
  puVar4[2] = 0;
  puVar4[3] = param_2;
  puVar4[4] = param_2 + param_3;
  puVar4[5] = param_4;
  ppuVar5 = &PTR_DAT_001e5640;
  puVar1 = PTR_DAT_001e5640;
  while( true ) {
    if (puVar1 == (undefined *)0x0) {
      return;
    }
    if (*ppuVar5 == &DAT_001e5624) break;
    ppuVar5 = (undefined **)(*ppuVar5 + 0x18);
    puVar1 = *ppuVar5;
  }
  puVar4[6] = &DAT_001e5624;
  *ppuVar5 = (undefined *)puVar4;
  return;
}

