/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00120ff4 */

void _if_registervirtual(code *param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 *puVar2;
  int *piVar3;
  
  piVar3 = &DAT_001e58d8;
  puVar2 = (undefined4 *)_kalloc(0xc);
  *puVar2 = param_1;
  puVar2[1] = param_2;
  puVar2[2] = 0;
  for (iVar1 = DAT_001e58d8; iVar1 != 0; iVar1 = *(int *)(iVar1 + 8)) {
    iVar1 = *piVar3;
    piVar3 = (int *)(iVar1 + 8);
  }
  *piVar3 = (int)puVar2;
  for (iVar1 = _ifnet; iVar1 != 0; iVar1 = *(int *)(iVar1 + 0x5c)) {
    if (*(int *)(iVar1 + 0x14) == 0) {
      (*param_1)(param_2,iVar1);
    }
  }
  return;
}

