
undefined4 _install_scanned_intr(uint param_1,undefined4 param_2,undefined4 param_3)

{
  uint uVar1;
  undefined *puVar2;
  undefined *puVar3;
  
  uVar1 = (param_1 & 0x7f) >> 4;
  if (uVar1 == 4) {
    puVar3 = (undefined *)&_ipl4_scan;
    puVar2 = (undefined *)&_ipl4_arg;
  }
  else if (uVar1 < 5) {
    if (uVar1 != 3) {
loc_406601A:
      _printf(aIllegalScannin,uVar1);
      return 0xffffffff;
    }
    puVar3 = _ipl3_scan;
    puVar2 = _ipl3_arg;
  }
  else if (uVar1 == 6) {
    puVar3 = _ipl6_scan;
    puVar2 = _ipl6_arg;
  }
  else {
    if (uVar1 != 7) goto loc_406601A;
    puVar3 = (undefined *)&_ipl7_scan;
    puVar2 = (undefined *)&_ipl7_arg;
  }
  *(undefined4 *)((int)puVar3 + (param_1 & 0xf) * 4) = param_2;
  *(undefined4 *)((int)puVar2 + (param_1 & 0xf) * 4) = param_3;
  uVar1 = 1 << ((param_1 & 0x1fff) >> 8);
  _intr_mask = uVar1 | _intr_mask;
  *_intrmask = uVar1 | *_intrmask;
  return 0;
}
