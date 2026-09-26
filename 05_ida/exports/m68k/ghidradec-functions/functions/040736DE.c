
undefined4 _np_dev_intr(int *param_1)

{
  uint *puVar1;
  char cVar2;
  undefined4 uVar3;
  
  puVar1 = (uint *)*param_1;
  if ((*puVar1 & 0x20000000) != 0) {
    if (((*(int *)((int)param_1 + 0x126) == 4) &&
        (*(int *)((int)param_1 + 0x12a) != *(int *)(param_1[8] + 0x4000))) &&
       (*(int *)((int)param_1 + 0x12a) != *(int *)(param_1[8] + 0x4008))) {
      _np_printing_shutdown(param_1);
      _np_setstate(param_1,8);
    }
    else if (*(int *)((int)param_1 + 0x126) == 4) {
      _np_printing_shutdown(param_1);
    }
    _lpr_csr_or(0x20);
  }
  if ((*puVar1 & 0x2000000) != 0) {
    _printf(aNpDSpuriousDma,(int)(param_1 + -0x1030e89) * 0x2b2e43db >> 2);
    _lpr_csr_or(2);
  }
  if (((*puVar1 & 0x20000) == 0) && ((*puVar1 & 0x40000) == 0)) {
    return 0;
  }
  if ((*puVar1 & 0x20000) != 0) {
    *(byte *)((int)puVar1 + 1) = *(byte *)((int)puVar1 + 1) | 2;
  }
  cVar2 = (char)*puVar1;
  if (cVar2 != -0x3c) {
    if (cVar2 == -0x3a) {
      return 0;
    }
    _printf(aNpDSpuriousPac,(int)(param_1 + -0x1030e89) * 0x2b2e43db >> 2,cVar2);
    return 0;
  }
  *(byte *)((int)param_1 + 0x11b) = ~(byte)(puVar1[1] >> 0x18) & 0x3f;
  if (((*(byte *)((int)param_1 + 0x11b) & 0x10) == 0) && (*(int *)((int)param_1 + 0x126) != 1)) {
    if (*(int *)((int)param_1 + 0x126) == 4) {
      _np_printing_shutdown(param_1);
    }
    uVar3 = 1;
  }
  else if (*(int *)((int)param_1 + 0x126) == 2) {
    if ((*(byte *)((int)param_1 + 0x11b) & 8) != 0) goto loc_4073880;
    uVar3 = 6;
  }
  else {
    if ((*(int *)((int)param_1 + 0x126) != 6) || ((*(byte *)((int)param_1 + 0x11b) & 8) == 0))
    goto loc_4073880;
    uVar3 = 2;
  }
  _np_setstate(param_1,uVar3);
loc_4073880:
  _thread_wakeup_prim((int)param_1 + 0x11b,0,0);
  return 0;
}
