/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00110fdc */

void _ttyretype(undefined4 *param_1)

{
  undefined1 *puVar1;
  undefined4 uVar2;
  int iVar3;
  undefined4 local_8;
  
  puVar1 = (undefined1 *)*param_1;
  if (puVar1[0x57] != -1) {
    _ttyecho(puVar1[0x57],param_1);
  }
  _ttyoutput(10,puVar1);
  uVar2 = _spltty();
  iVar3 = *(int *)(puVar1 + 0x10) + -1;
  while( true ) {
    iVar3 = _nextc3(puVar1 + 0xc,iVar3,&local_8);
    if (iVar3 == 0) break;
    _ttyecho(local_8,param_1);
  }
  iVar3 = *(int *)(puVar1 + 4) + -1;
  while( true ) {
    iVar3 = _nextc3(puVar1,iVar3,&local_8);
    if (iVar3 == 0) break;
    _ttyecho(local_8,param_1);
  }
  *(uint *)(puVar1 + 0x40) = *(uint *)(puVar1 + 0x40) & 0xfffbffff;
  _splx(uVar2);
  puVar1[0x4b] = *puVar1;
  puVar1[0x4c] = 0;
  return;
}

