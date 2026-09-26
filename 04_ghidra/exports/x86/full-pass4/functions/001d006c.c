/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001d006c */

undefined4 _sel_isMapped(uint param_1)

{
  undefined4 *puVar1;
  undefined *puVar2;
  uint uVar3;
  
  puVar2 = PTR_DAT_001e5640;
  if (param_1 != 0) {
    for (; puVar2 != (undefined *)0x0; puVar2 = *(undefined **)(puVar2 + 0x18)) {
      if ((*(uint *)(puVar2 + 0xc) <= param_1) && (param_1 < *(uint *)(puVar2 + 0x10))) {
        return 1;
      }
      if ((puVar2 == &DAT_001e5624) && (uVar3 = 0, DAT_001e5628 != 0)) {
        do {
          for (puVar1 = *(undefined4 **)(PTR_DAT_001e5638 + uVar3 * 4); puVar1 != (undefined4 *)0x0;
              puVar1 = (undefined4 *)*puVar1) {
            if (puVar1[1] == param_1) {
              return 1;
            }
          }
          uVar3 = uVar3 + 1;
        } while (uVar3 < DAT_001e5628);
      }
    }
  }
  return 0;
}

