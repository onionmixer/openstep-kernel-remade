/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001cf3f4 */

undefined4 FUN_001cf3f4(undefined4 param_1,int param_2)

{
  int iVar1;
  int *piVar2;
  int *piVar3;
  uint uVar4;
  uint local_c;
  
  iVar1 = *(int *)(param_2 + 4);
  local_c = 0;
  if (*(int *)(param_2 + 8) != 0) {
    do {
      if ((*(int *)(iVar1 + 0xc + local_c * 0x10) != 0) &&
         (uVar4 = 0, *(short *)(*(int *)(iVar1 + 0xc + local_c * 0x10) + 8) != 0)) {
        do {
          piVar2 = (int *)_NXHashInsert(param_1,*(undefined4 *)
                                                 (*(int *)(iVar1 + 0xc + local_c * 0x10) + 0xc +
                                                 uVar4 * 4));
          if (piVar2 == (int *)0x0) {
            piVar3 = *(int **)(*(int *)(iVar1 + 0xc + local_c * 0x10) + 0xc + uVar4 * 4);
          }
          else {
            FUN_001cf348(param_1,piVar2,
                         *(undefined4 *)(*(int *)(iVar1 + 0xc + local_c * 0x10) + 0xc + uVar4 * 4));
            piVar3 = (int *)_objc_lookUpClass(piVar2[2]);
          }
          if (piVar2 != piVar3) {
            *(undefined4 *)(*piVar3 + 0xc) = *(undefined4 *)(iVar1 + local_c * 0x10);
          }
          FUN_001cf0d4(piVar3);
          uVar4 = uVar4 + 1;
        } while (uVar4 < *(ushort *)(*(int *)(iVar1 + 0xc + local_c * 0x10) + 8));
      }
      local_c = local_c + 1;
    } while (local_c < *(uint *)(param_2 + 8));
  }
  return param_1;
}

