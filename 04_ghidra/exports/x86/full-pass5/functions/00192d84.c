/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00192d84 */

void _byte_swap_disklabel_out(uint *param_1)

{
  uint uVar1;
  uint *puVar2;
  int iVar3;
  
  if ((int)*param_1 < 0x646c5633) {
    iVar3 = 0;
    puVar2 = param_1 + 0x90;
    do {
      uVar1 = *puVar2;
      *puVar2 = uVar1 >> 0x18 | (uVar1 & 0xff0000) >> 8 | (uVar1 & 0xff00) << 8 | uVar1 << 0x18;
      puVar2 = puVar2 + 1;
      iVar3 = iVar3 + 1;
    } while (iVar3 < 0x686);
  }
  else {
    *(ushort *)(param_1 + 0x90) = (ushort)param_1[0x90] >> 8 | (ushort)param_1[0x90] << 8;
  }
  uVar1 = *param_1;
  *param_1 = uVar1 >> 0x18 | (uVar1 & 0xff0000) >> 8 | (uVar1 & 0xff00) << 8 | uVar1 << 0x18;
  uVar1 = param_1[1];
  param_1[1] = uVar1 >> 0x18 | (uVar1 & 0xff0000) >> 8 | (uVar1 & 0xff00) << 8 | uVar1 << 0x18;
  uVar1 = param_1[2];
  param_1[2] = uVar1 >> 0x18 | (uVar1 & 0xff0000) >> 8 | (uVar1 & 0xff00) << 8 | uVar1 << 0x18;
  uVar1 = param_1[9];
  param_1[9] = uVar1 >> 0x18 | (uVar1 & 0xff0000) >> 8 | (uVar1 & 0xff00) << 8 | uVar1 << 0x18;
  uVar1 = param_1[10];
  param_1[10] = uVar1 >> 0x18 | (uVar1 & 0xff0000) >> 8 | (uVar1 & 0xff00) << 8 | uVar1 << 0x18;
  *(ushort *)(param_1 + 0x716) = (ushort)param_1[0x716] >> 8 | (ushort)param_1[0x716] << 8;
  _byte_swap_disktab_out(param_1 + 0xb);
  uVar1 = 0;
  do {
    *(undefined1 *)((int)param_1 + uVar1 + 0x22e) = *(undefined1 *)((int)param_1 + uVar1 + 0x240);
    uVar1 = uVar1 + 1;
  } while (uVar1 < 0x1a1a);
  return;
}

