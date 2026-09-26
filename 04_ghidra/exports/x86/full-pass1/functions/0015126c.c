/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0015126c */

/* WARNING: Removing unreachable block (ram,0x00151390) */
/* WARNING: Removing unreachable block (ram,0x00151396) */
/* WARNING: Removing unreachable block (ram,0x00151367) */
/* WARNING: Removing unreachable block (ram,0x0015136d) */

void _ipc_splay_tree_join(int *param_1,int param_2)

{
  int iVar1;
  undefined4 *puVar2;
  int iVar3;
  int iVar4;
  int *local_1c;
  int *local_18;
  int local_8;
  
  iVar1 = *(int *)(param_2 + 4);
  if (iVar1 != 0) {
    puVar2 = *(undefined4 **)(param_2 + 0x14);
    **(undefined4 **)(param_2 + 0xc) = *(undefined4 *)(iVar1 + 0x18);
    *puVar2 = *(undefined4 *)(iVar1 + 0x1c);
    *(undefined4 *)(iVar1 + 0x18) = *(undefined4 *)(param_2 + 8);
    *(undefined4 *)(iVar1 + 0x1c) = *(undefined4 *)(param_2 + 0x10);
    *(undefined4 *)(param_2 + 4) = 0;
    local_8 = param_1[1];
    if (local_8 != 0) {
      if (*param_1 != 0) {
        puVar2 = (undefined4 *)param_1[5];
        *(undefined4 *)param_1[3] = *(undefined4 *)(local_8 + 0x18);
        *puVar2 = *(undefined4 *)(local_8 + 0x1c);
        *(int *)(local_8 + 0x18) = param_1[2];
        *(int *)(local_8 + 0x1c) = param_1[4];
        local_1c = param_1 + 2;
        local_18 = param_1 + 4;
        iVar3 = *(int *)(local_8 + 0x10);
        while (iVar3 != 0) {
          if (iVar3 == 0) {
            iVar3 = *(int *)(local_8 + 0x1c);
            if (iVar3 == 0) break;
            iVar4 = *(int *)(iVar3 + 0x10);
            *local_1c = local_8;
            local_1c = (int *)(local_8 + 0x1c);
            local_8 = *(int *)(local_8 + 0x1c);
            if ((iVar4 != 0) && (*(int *)(iVar3 + 0x18) != 0)) {
              *local_18 = local_8;
              local_18 = (int *)(local_8 + 0x18);
              local_8 = *(int *)(local_8 + 0x18);
            }
          }
          else {
            iVar3 = *(int *)(local_8 + 0x18);
            if (iVar3 == 0) break;
            if ((*(int *)(iVar3 + 0x10) != 0) && (*(int *)(iVar3 + 0x18) != 0)) {
              *(undefined4 *)(local_8 + 0x18) = *(undefined4 *)(iVar3 + 0x1c);
              *(int *)(iVar3 + 0x1c) = local_8;
              local_8 = iVar3;
            }
            *local_18 = local_8;
            local_18 = (int *)(local_8 + 0x18);
            local_8 = *(int *)(local_8 + 0x18);
          }
          iVar3 = *(int *)(local_8 + 0x10);
        }
        param_1[3] = (int)local_1c;
        param_1[5] = (int)local_18;
      }
      puVar2 = (undefined4 *)param_1[5];
      *(undefined4 *)param_1[3] = *(undefined4 *)(local_8 + 0x18);
      *puVar2 = *(undefined4 *)(local_8 + 0x1c);
      *(int *)(local_8 + 0x18) = param_1[2];
      *(int *)(local_8 + 0x1c) = param_1[4];
      *(int *)(local_8 + 0x18) = iVar1;
      iVar1 = local_8;
    }
    local_8 = iVar1;
    param_1[1] = local_8;
    *param_1 = *(int *)(local_8 + 0x10);
    param_1[3] = (int)(param_1 + 2);
    param_1[5] = (int)(param_1 + 4);
  }
  return;
}

