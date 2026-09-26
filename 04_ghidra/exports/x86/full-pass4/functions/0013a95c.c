/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0013a95c */

uint _uncompress_data(int param_1,undefined4 param_2,undefined4 *param_3,int param_4)

{
  char cVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  undefined4 *puVar5;
  undefined4 local_10;
  char *local_c;
  
  uVar4 = param_4 + 3U >> 2;
  local_c = (char *)(param_1 + 4);
  puVar5 = (undefined4 *)(param_1 + 4 + (param_4 + 3U >> 5));
  local_10 = 0;
  iVar3 = 0;
  if (uVar4 != 0) {
    do {
      cVar1 = *local_c;
      local_c = local_c + 1;
      uVar2 = 0;
      do {
        if ((int)uVar4 <= iVar3) {
          return uVar4;
        }
        if (cVar1 < '\0') {
          local_10 = *puVar5;
          *param_3 = local_10;
          puVar5 = puVar5 + 1;
        }
        else {
          *param_3 = local_10;
        }
        param_3 = param_3 + 1;
        cVar1 = cVar1 * '\x02';
        uVar2 = uVar2 + 1;
        iVar3 = iVar3 + 1;
      } while (uVar2 < 8);
    } while (iVar3 < (int)uVar4);
  }
  return uVar4;
}

