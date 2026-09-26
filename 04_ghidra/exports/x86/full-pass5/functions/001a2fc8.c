/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001a2fc8 */

undefined4 FUN_001a2fc8(int param_1,int param_2)

{
  uint uVar1;
  int *piVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  int in_FS_OFFSET;
  undefined2 *local_1c;
  int local_18;
  undefined2 local_14 [5];
  undefined2 uStack_a;
  undefined1 local_8;
  undefined1 uStack_5;
  
  if ((*(ushort *)(param_2 + 0x48) & 4) != 0) {
    piVar2 = *(int **)(*(int *)(param_1 + 0x28) + 0xec);
    iVar4 = 0;
    if (piVar2 != (int *)0x0) {
      iVar4 = *piVar2;
    }
    uVar1 = (uint)(*(ushort *)(param_2 + 0x48) >> 3) * 8;
    if (uVar1 < *(uint *)(iVar4 + 0x3c)) {
      iVar4 = uVar1 + *(int *)(iVar4 + 0x38);
      *(code **)(param_1 + 0x74) = __analysis_fragment_001a303c;
      uStack_a = (undefined2)((uint)*(undefined4 *)(in_FS_OFFSET + iVar4) >> 0x10);
      uVar1 = *(uint *)(in_FS_OFFSET + iVar4 + 4);
      local_8 = (undefined1)uVar1;
      uStack_5 = (undefined1)(uVar1 >> 0x18);
      *(undefined4 *)(param_1 + 0x74) = 0;
      uVar5 = *(int *)(param_2 + 0x44) - 8;
      local_1c = local_14;
      local_18 = 8;
      uVar3 = 0xffff;
      if ((uVar1 & 0x400000) != 0) {
        uVar3 = 0xffffffff;
      }
      *(code **)(param_1 + 0x74) = __analysis_fragment_001a311c;
      do {
        *(undefined2 *)
         (in_FS_OFFSET + (uVar5 & uVar3) + CONCAT13(uStack_5,CONCAT12(local_8,uStack_a))) =
             *local_1c;
        local_1c = local_1c + 1;
        uVar5 = (uVar5 & uVar3) + 2;
        local_18 = local_18 + -2;
      } while (local_18 != 0);
      *(undefined4 *)(param_1 + 0x74) = 0;
      if ((uVar1 & 0x400000) == 0) {
        *(uint *)(param_2 + 0x44) = (uint)(ushort)(*(short *)(param_2 + 0x44) - 8);
      }
      else {
        *(int *)(param_2 + 0x44) = *(int *)(param_2 + 0x44) + -8;
      }
      return 1;
    }
  }
  return 0;
}

