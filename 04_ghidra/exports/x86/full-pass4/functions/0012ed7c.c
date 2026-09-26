/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0012ed7c */

void _nfs_netboot_prealloc(undefined4 param_1)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  int aiStack_1c [6];
  
  _MAXCLIENTS = _MAXCLIENTS + 3;
  uVar2 = 0;
  if (_MAXCLIENTS != 0) {
    do {
      iVar1 = FUN_0012ea98(param_1,*(undefined4 *)(_active_u + 0x1c));
      aiStack_1c[uVar2] = iVar1;
      uVar2 = uVar2 + 1;
    } while (uVar2 < _MAXCLIENTS);
  }
  uVar2 = 0;
  if (_MAXCLIENTS != 0) {
    do {
      if (aiStack_1c[uVar2] != 0) {
        FUN_0012ee3c(aiStack_1c[uVar2]);
      }
      uVar2 = uVar2 + 1;
    } while (uVar2 < _MAXCLIENTS);
  }
  iVar1 = _kalloc(_MAXCLIENTS * 0x2260);
  uVar2 = 0;
  if (_MAXCLIENTS != 0) {
    iVar3 = 0;
    do {
      _clntkudp_realloc(*(undefined4 *)((int)&DAT_001eef38 + iVar3),iVar1);
      iVar1 = iVar1 + 0x2260;
      iVar3 = iVar3 + 0xc;
      uVar2 = uVar2 + 1;
    } while (uVar2 < _MAXCLIENTS);
  }
  return;
}

