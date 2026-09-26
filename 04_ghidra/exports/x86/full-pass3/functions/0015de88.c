/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0015de88 */

undefined4 _xxx_slot_info(undefined4 param_1,int param_2,undefined4 *param_3)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 *puVar3;
  
  if ((param_2 < 0) || (0 < param_2)) {
    uVar1 = 4;
  }
  else {
    puVar3 = &_machine_slot + param_2 * 8;
    for (iVar2 = 8; iVar2 != 0; iVar2 = iVar2 + -1) {
      *param_3 = *puVar3;
      puVar3 = puVar3 + 1;
      param_3 = param_3 + 1;
    }
    uVar1 = 0;
  }
  return uVar1;
}

