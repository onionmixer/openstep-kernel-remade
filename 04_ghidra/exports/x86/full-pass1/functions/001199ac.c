/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001199ac */

int _vafsidtovfs(int param_1,undefined4 *param_2)

{
  undefined4 *puVar1;
  int iVar2;
  int local_48;
  undefined1 local_44 [12];
  int local_38;
  
  puVar1 = _rootvfs;
  while( true ) {
    if (puVar1 == (undefined4 *)0x0) {
      return 0x16;
    }
    iVar2 = (**(code **)(puVar1[1] + 8))(puVar1,&local_48);
    if (iVar2 != 0) {
      return iVar2;
    }
    iVar2 = (**(code **)(*(int *)(local_48 + 0x1c) + 0x14))
                      (local_48,local_44,*(undefined4 *)(_active_u + 0x1c));
    if (iVar2 != 0) {
      return iVar2;
    }
    if (local_38 == param_1) break;
    puVar1 = (undefined4 *)*puVar1;
  }
  *param_2 = puVar1;
  return 0;
}

