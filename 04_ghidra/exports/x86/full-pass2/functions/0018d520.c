/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0018d520 */

void _pcb_init(int param_1)

{
  int *piVar1;
  int iVar2;
  int *piVar3;
  int *piVar4;
  
  piVar1 = (int *)_zalloc(_pcb_zone);
  *(int **)(param_1 + 0x28) = piVar1;
  piVar3 = &DAT_001d14ec;
  piVar4 = piVar1;
  for (iVar2 = 0x3d; iVar2 != 0; iVar2 = iVar2 + -1) {
    *piVar4 = *piVar3;
    piVar3 = piVar3 + 1;
    piVar4 = piVar4 + 1;
  }
  *piVar1 = (int)(piVar1 + 2);
  piVar1[1] = 0x68;
  piVar1[9] = *(int *)(*(int *)(*(int *)(*(int *)(param_1 + 0xc) + 0xc) + 0x24) + 4);
  piVar1[0x1d] = (int)(_ldt + -0x40000000);
  piVar1[0x1e] = 0x18;
  *(undefined2 *)(piVar1 + 0x1a) = 0x20;
  *(undefined2 *)(piVar1 + 4) = 0x10;
  piVar1[0xb] = 0x200;
  *(undefined2 *)(piVar1 + 0x16) = 0x10;
  *(undefined2 *)(piVar1 + 0x15) = 8;
  *(undefined2 *)(piVar1 + 0x17) = 0x10;
  *(undefined2 *)(piVar1 + 0x14) = 0x10;
  *(undefined2 *)(piVar1 + 0x18) = 0x50;
  *(undefined2 *)(piVar1 + 0x19) = 0;
  *(undefined2 *)((int)piVar1 + 0x6e) = 0x68;
  return;
}

