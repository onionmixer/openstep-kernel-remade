
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
    sub_402FD84(puVar2);
  }
  _drmru = puVar2;
  *puVar2 = *(uint *)(*(int *)(param_1[7] + 0x2e) + 4);
  puVar2[7] = *param_1;
  puVar2[6] = param_1[1];
  puVar2[5] = param_1[2];
  uVar1 = param_1[7];
  puVar2[1] = *(uint *)(uVar1 + 0xe);
  puVar2[2] = *(uint *)(uVar1 + 0x12);
  puVar2[3] = *(uint *)(uVar1 + 0x16);
  puVar2[4] = *(uint *)(uVar1 + 0x1a);
  puVar2[9] = *(uint *)(_drhashtbl + (*puVar2 & 0x1f) * 4);
  *(uint **)(_drhashtbl + (*puVar2 & 0x1f) * 4) = puVar2;
  return;
}

