/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001420e4 */

uint FUN_001420e4(uint param_1)

{
  uint *puVar1;
  uint uVar2;
  uint *puVar3;
  int iVar4;
  uint *puVar5;
  
  iVar4 = (param_1 & 0x3f) * 4;
  puVar1 = (uint *)(&_lf_svnode_hash + iVar4);
  uVar2 = *(uint *)(&_lf_svnode_hash + iVar4);
  puVar3 = puVar1;
  do {
    if (uVar2 == 0) {
      puVar5 = (uint *)_kalloc(0x10);
      *puVar5 = param_1;
      puVar5[1] = 0;
      puVar5[2] = 0;
      *(short *)(param_1 + 6) = *(short *)(param_1 + 6) + 1;
LAB_00142140:
      puVar5[3] = *puVar1;
      *puVar1 = (uint)puVar5;
LAB_00142147:
      return *puVar1;
    }
    puVar5 = (uint *)*puVar3;
    if (*puVar5 == param_1) {
      if (puVar3 == puVar1) goto LAB_00142147;
      *puVar3 = puVar5[3];
      goto LAB_00142140;
    }
    puVar3 = puVar5 + 3;
    uVar2 = puVar5[3];
  } while( true );
}

