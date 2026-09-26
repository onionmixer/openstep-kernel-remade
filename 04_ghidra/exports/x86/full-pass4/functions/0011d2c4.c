/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0011d2c4 */

int _getfakedirentries(int param_1,int param_2)

{
  ushort *puVar1;
  char cVar2;
  int iVar3;
  ushort uVar4;
  undefined4 *puVar5;
  int iVar6;
  int iVar7;
  undefined4 *puVar8;
  uint uVar9;
  char *pcVar10;
  ushort local_124;
  int local_120;
  int local_11c;
  uint local_110;
  
  local_120 = *(int *)(param_1 + 0x10);
  if (local_120 != 0) {
    iVar3 = *(int *)(param_2 + 0x14);
    local_110 = -*(int *)(param_2 + 8) - 0x400;
    if (iVar3 != 0) {
      uVar9 = 0;
      if (local_110 != 0) {
        do {
          if (local_120 == 0) {
            return 0;
          }
          iVar6 = -1;
          pcVar10 = (char *)(local_120 + 0x20);
          do {
            if (iVar6 == 0) break;
            iVar6 = iVar6 + -1;
            cVar2 = *pcVar10;
            pcVar10 = pcVar10 + 1;
          } while (cVar2 != '\0');
          local_124 = ~(ushort)iVar6;
          iVar6 = ((ushort)(local_124 - 1) + 4 & 0xfffffffc) + 8;
          if (iVar6 + (uVar9 & 0xfffffc00) < 0x401) {
            uVar9 = uVar9 + iVar6;
          }
          else {
            uVar9 = (uVar9 & 0xfffffc00) + 0x400;
          }
          local_120 = *(int *)(local_120 + 0x120);
        } while (uVar9 < local_110);
      }
      if (local_120 != 0) {
        puVar5 = (undefined4 *)_kalloc(iVar3);
        iVar6 = 0;
        puVar8 = puVar5;
        for (local_11c = iVar3; local_11c != 0; local_11c = local_11c - (uint)*puVar1) {
          *puVar8 = 0xffffffff;
          iVar7 = -1;
          pcVar10 = (char *)(local_120 + 0x20);
          do {
            if (iVar7 == 0) break;
            iVar7 = iVar7 + -1;
            cVar2 = *pcVar10;
            pcVar10 = pcVar10 + 1;
          } while (cVar2 != '\0');
          local_124 = ~(ushort)iVar7;
          *(ushort *)((int)puVar8 + 6) = local_124 - 1;
          _strcpy((char *)(puVar8 + 2),(char *)(local_120 + 0x20));
          local_120 = *(int *)(local_120 + 0x120);
          if (local_120 == 0) {
            uVar4 = 0x400 - (short)iVar6;
            *(ushort *)(puVar8 + 1) = uVar4;
            local_11c = local_11c - (uint)uVar4;
            local_110 = local_110 + uVar4;
            break;
          }
          iVar7 = -1;
          pcVar10 = (char *)(local_120 + 0x20);
          do {
            if (iVar7 == 0) break;
            iVar7 = iVar7 + -1;
            cVar2 = *pcVar10;
            pcVar10 = pcVar10 + 1;
          } while (cVar2 != '\0');
          local_124 = ~(ushort)iVar7;
          if (iVar6 + 0x10 + ((ushort)(local_124 - 1) + 4 & 0xfffffffc) +
              (*(ushort *)((int)puVar8 + 6) + 4 & 0xfffffffc) < 0x401) {
            *(ushort *)(puVar8 + 1) = (*(ushort *)((int)puVar8 + 6) + 4 & 0xfffc) + 8;
            iVar6 = (*(ushort *)((int)puVar8 + 6) + 4 & 0xfffffffc) + 8 + iVar6;
          }
          else {
            *(short *)(puVar8 + 1) = 0x400 - (short)iVar6;
            iVar6 = 0;
          }
          puVar1 = (ushort *)(puVar8 + 1);
          local_110 = local_110 + *puVar1;
          puVar8 = (undefined4 *)((int)puVar8 + (uint)*(ushort *)(puVar8 + 1));
        }
        iVar6 = _uiomove(puVar5,*(int *)(param_2 + 0x14) - local_11c,0,param_2);
        _kfree(puVar5,iVar3);
        if (iVar6 != 0) {
          return iVar6;
        }
        *(uint *)(param_2 + 8) = -(local_110 + 0x400);
      }
    }
  }
  return 0;
}

