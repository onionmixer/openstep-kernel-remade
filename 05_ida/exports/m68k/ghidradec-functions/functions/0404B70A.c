
int _nextseg(int param_1)

{
  int iVar1;
  
  iVar1 = _nextsegfromheader(0x4000000,param_1);
  if ((iVar1 == 0) && (_fvm_seg != param_1)) {
    iVar1 = _fvm_seg;
  }
  return iVar1;
}
