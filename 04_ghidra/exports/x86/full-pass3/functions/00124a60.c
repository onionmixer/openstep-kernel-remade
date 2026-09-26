/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00124a60 */

undefined4 FUN_00124a60(void)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  undefined4 local_3c [14];
  
  uVar1 = 0;
  if (DAT_001dbaac == 0) {
    puVar3 = (undefined4 *)(DAT_001e875c + 0x28);
    puVar4 = local_3c;
    for (iVar2 = 0xe; iVar2 != 0; iVar2 = iVar2 + -1) {
      *puVar4 = *puVar3;
      puVar3 = puVar3 + 1;
      puVar4 = puVar4 + 1;
    }
    uVar1 = _alert(0x3c,8,s_Configuring_Network_001dbb45,&DAT_001dbb42,0,0,0,0,0,0,0);
    DAT_001dbaac = 1;
    puVar3 = local_3c;
    puVar4 = (undefined4 *)(DAT_001e875c + 0x28);
    for (iVar2 = 0xe; iVar2 != 0; iVar2 = iVar2 + -1) {
      *puVar4 = *puVar3;
      puVar3 = puVar3 + 1;
      puVar4 = puVar4 + 1;
    }
  }
  return uVar1;
}

