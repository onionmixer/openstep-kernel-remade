
void sub_401C58A(undefined4 param_1,sword param_2,sword param_3)

{
  int iVar1;
  int iVar2;
  undefined auStack_204 [512];
  
  iVar1 = _nb_map(param_1);
  if (param_2 < 0x201) {
    iVar2 = (int)param_2;
    _nb_read(param_1,0xe,iVar2,auStack_204);
    _bcopy(iVar1 + 0x12 + iVar2,iVar1 + 0xe,(int)param_3);
    _bcopy(auStack_204,iVar1 + 0xe + (int)param_3,iVar2);
  }
  else {
    iVar2 = (int)param_3;
    _nb_read(param_1,param_2 + 0x12,iVar2,auStack_204);
    _bcopy(iVar1 + 0xe,iVar1 + 0xe + iVar2,(int)param_2);
    _bcopy(auStack_204,iVar1 + 0xe,iVar2);
  }
  _nb_shrink_bot(param_1,4);
  return;
}
