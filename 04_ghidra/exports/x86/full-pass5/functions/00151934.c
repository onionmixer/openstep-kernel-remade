/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00151934 */

void _ipc_table_fill(int param_1,uint param_2,int param_3,uint param_4)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  undefined4 local_c;
  
  uVar3 = _page_size;
  uVar2 = 0;
  local_c = 1;
  uVar1 = _page_size;
  if (param_2 != 0) {
    do {
      uVar1 = _page_size;
      if (uVar3 <= local_c) break;
      if (param_4 * param_3 <= local_c) {
        *(uint *)(param_1 + uVar2 * 4) = local_c / param_4;
        uVar2 = uVar2 + 1;
      }
      local_c = local_c << 1;
      uVar1 = _page_size;
    } while (uVar2 < param_2);
  }
  do {
    if (param_2 <= uVar2) {
      return;
    }
    uVar3 = 0;
    do {
      if (param_2 <= uVar2) break;
      if (param_4 * param_3 <= local_c) {
        *(uint *)(param_1 + uVar2 * 4) = local_c / param_4;
        uVar2 = uVar2 + 1;
      }
      uVar3 = uVar3 + 1;
      local_c = local_c + uVar1;
    } while (uVar3 < 0xf);
    uVar1 = uVar1 * 2;
  } while( true );
}

