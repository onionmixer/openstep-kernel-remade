/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0010d614 */

int _selscan(int param_1,int param_2,int param_3)

{
  uint *puVar1;
  undefined4 uVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  uint local_20;
  int local_1c;
  int local_14;
  uint local_c;
  int local_8;
  
  local_14 = 0;
  local_8 = 0;
  local_1c = 0;
  do {
    uVar2 = *(undefined4 *)(&DAT_001daca8 + local_8 * 4);
    local_c = 0;
    if (0 < param_3) {
      do {
        uVar5 = *(uint *)(param_1 + local_1c + (local_c >> 5) * 4);
        if (uVar5 != 0) {
          local_20 = 0;
          do {
            uVar4 = uVar5 & 1;
            uVar5 = (int)uVar5 >> 1;
            if (uVar4 != 0) {
              uVar4 = local_c + local_20;
              if ((param_3 <= (int)uVar4) || (*(int *)(_active_u + 0x15c) <= (int)uVar4)) break;
              iVar3 = *(int *)(*(int *)(_active_u + 0x150) + uVar4 * 4);
              if (iVar3 == 0) {
                *(undefined1 *)(DAT_001e875c + 0x68) = 9;
                break;
              }
              iVar3 = (**(code **)(*(int *)(iVar3 + 0x14) + 8))(iVar3,uVar2);
              if (iVar3 != 0) {
                puVar1 = (uint *)(param_2 + local_1c + (uVar4 >> 5) * 4);
                *puVar1 = *puVar1 | 1 << ((byte)uVar4 & 0x1f);
                local_14 = local_14 + 1;
              }
              if (uVar5 == 0) break;
            }
            local_20 = local_20 + 1;
          } while (local_20 < 0x20);
        }
        local_c = local_c + 0x20;
      } while ((int)local_c < param_3);
    }
    local_1c = local_1c + 0x20;
    local_8 = local_8 + 1;
    if (2 < local_8) {
      return local_14;
    }
  } while( true );
}

