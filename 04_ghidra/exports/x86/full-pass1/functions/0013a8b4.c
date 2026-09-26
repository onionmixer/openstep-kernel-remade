/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0013a8b4 */

int _compress_data(int *param_1,int param_2,int *param_3)

{
  int iVar1;
  byte bVar2;
  int iVar3;
  int *piVar4;
  uint uVar5;
  uint local_18;
  int local_14;
  byte *local_10;
  int *local_8;
  
  local_8 = param_1;
  uVar5 = param_2 + 3U >> 2;
  local_10 = (byte *)(param_3 + 1);
  piVar4 = (int *)((int)param_3 + (param_2 + 3U >> 5) + 4);
  bVar2 = 0;
  local_14 = 0;
  iVar3 = 0;
  if (uVar5 != 0) {
    do {
      local_18 = 0;
      do {
        if ((int)uVar5 <= iVar3) break;
        bVar2 = bVar2 * '\x02';
        iVar1 = *local_8;
        if (local_14 != iVar1) {
          bVar2 = bVar2 | 1;
          *piVar4 = iVar1;
          piVar4 = piVar4 + 1;
          local_14 = iVar1;
          if (param_2 == (int)piVar4 - (int)param_3) {
            return param_2;
          }
        }
        local_8 = local_8 + 1;
        local_18 = local_18 + 1;
        iVar3 = iVar3 + 1;
      } while (local_18 < 8);
      *local_10 = bVar2;
      local_10 = local_10 + 1;
    } while (iVar3 < (int)uVar5);
  }
  *param_3 = param_2;
  return (int)piVar4 - (int)param_3;
}

