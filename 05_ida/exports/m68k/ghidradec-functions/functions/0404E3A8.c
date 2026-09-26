
void _ns_callout_init(void)

{
  int *piVar1;
  uint uVar2;
  uint uVar3;
  
  uVar2 = _ncallout;
  _ns_callfree = _ns_callout;
  uVar3 = 1;
  piVar1 = _ns_callout;
  if (1 < _ncallout) {
    do {
      *piVar1 = (int)(piVar1 + 6);
      uVar3 = uVar3 + 1;
      piVar1 = piVar1 + 6;
    } while (uVar3 < uVar2);
  }
  _ns_callout[_ncallout * 6 + -6] = 0;
  return;
}
