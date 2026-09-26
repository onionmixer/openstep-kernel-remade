/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00137814 */

void _svckudp_dupsave(uint *param_1)

{
  uint uVar1;
  uint *puVar2;
  
  if (_ndupreqs < 400) {
    puVar2 = (uint *)_kalloc(0x28);
    if (_drmru == (uint *)0x0) {
      puVar2[8] = (uint)puVar2;
    }
    else {
      puVar2[8] = *(uint *)((int)_drmru + 0x20);
      *(uint **)((int)_drmru + 0x20) = puVar2;
    }
    _ndupreqs = _ndupreqs + 1;
  }
  else {
    puVar2 = *(uint **)((int)_drmru + 0x20);
    FUN_00137944(puVar2);
  }
  _drmru = puVar2;
  *puVar2 = *(uint *)(*(int *)(param_1[7] + 0x30) + 4);
  puVar2[7] = *param_1;
  puVar2[6] = param_1[1];
  puVar2[5] = param_1[2];
  uVar1 = param_1[7];
  puVar2[1] = *(uint *)(uVar1 + 0x10);
  puVar2[2] = *(uint *)(uVar1 + 0x14);
  puVar2[3] = *(uint *)(uVar1 + 0x18);
  puVar2[4] = *(uint *)(uVar1 + 0x1c);
  puVar2[9] = *(uint *)(&_drhashtbl + (*puVar2 & 0x1f) * 4);
  *(uint **)(&_drhashtbl + (*puVar2 & 0x1f) * 4) = puVar2;
  return;
}

