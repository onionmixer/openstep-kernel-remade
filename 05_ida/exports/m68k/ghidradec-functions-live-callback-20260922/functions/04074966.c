
int _np_probe(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  
  _bzero(_np_softc + param_2 * 0x14c,0x14c);
  param_1 = _slot_id + param_1;
  *(int *)(_np_softc + param_2 * 0x14c) = param_1;
  iVar1 = _probe_rb(*(undefined *)(param_1 + 3));
  iVar2 = 0;
  if (iVar1 != 0) {
    iVar2 = param_1;
  }
  return iVar2;
}

