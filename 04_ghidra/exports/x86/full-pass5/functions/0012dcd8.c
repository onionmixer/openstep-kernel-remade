/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0012dcd8 */

bool FUN_0012dcd8(int param_1,int param_2,int param_3)

{
  ushort uVar1;
  short sVar2;
  char *pcVar3;
  int iVar4;
  uint uVar5;
  undefined2 *puVar6;
  short *psVar7;
  undefined2 *puVar8;
  bool bVar9;
  
  if ((_nfs_portmon != 0) &&
     (uVar1 = *(ushort *)(*(int *)(param_2 + 0x1c) + 0x12),
     0x3ff < (ushort)(uVar1 >> 8 | uVar1 << 8))) {
    pcVar3 = _inet_ntoa((in_addr)(*(int *)(param_2 + 0x1c) + 0x14));
    _printf(s_NFS_request_from_unprivileged_po_001dc292,pcVar3);
    return false;
  }
  iVar4 = *(int *)(param_2 + 0xc);
  if (*(int *)(param_1 + 8) != iVar4) {
    iVar4 = 0;
  }
  if (iVar4 != 0) {
    if (iVar4 != 1) {
      return false;
    }
    iVar4 = *(int *)(param_2 + 0x18);
    if (*(int *)(iVar4 + 8) != 0) {
LAB_0012ddc0:
      *(undefined2 *)(param_3 + 2) = *(undefined2 *)(iVar4 + 8);
      *(undefined2 *)(param_3 + 4) = *(undefined2 *)(iVar4 + 0xc);
      puVar8 = (undefined2 *)(param_3 + 10);
      puVar6 = *(undefined2 **)(iVar4 + 0x14);
      if (puVar8 < (undefined2 *)(param_3 + 10 + *(int *)(iVar4 + 0x10) * 2)) {
        do {
          *puVar8 = *puVar6;
          puVar6 = puVar6 + 2;
          puVar8 = puVar8 + 1;
        } while (puVar8 < (undefined2 *)(param_3 + 10 + *(int *)(iVar4 + 0x10) * 2));
      }
      goto LAB_0012de14;
    }
    uVar5 = 0;
    if (*(int *)(param_1 + 0xc) != 0) {
      sVar2 = *(short *)(*(int *)(param_2 + 0x1c) + 0x10);
      psVar7 = *(short **)(param_1 + 0x10);
      do {
        if (*psVar7 == sVar2) {
          if (sVar2 == 2) {
            bVar9 = *(int *)(*(int *)(param_2 + 0x1c) + 0x14) == *(int *)(psVar7 + 2);
          }
          else {
            bVar9 = false;
          }
          if (bVar9) goto LAB_0012ddc0;
        }
        psVar7 = psVar7 + 8;
        uVar5 = uVar5 + 1;
      } while (uVar5 < *(uint *)(param_1 + 0xc));
    }
  }
  *(undefined2 *)(param_3 + 2) = *(undefined2 *)(param_1 + 4);
  *(undefined2 *)(param_3 + 4) = *(undefined2 *)(param_1 + 4);
  puVar8 = (undefined2 *)(param_3 + 10);
LAB_0012de14:
  for (; puVar8 < (undefined2 *)(param_3 + 0x2a); puVar8 = puVar8 + 1) {
    *puVar8 = 0xffff;
  }
  return *(short *)(param_3 + 2) != -1;
}

