
void _m_cat(int *param_1,int param_2)

{
  int iVar1;
  uint uVar2;
  
  iVar1 = *param_1;
  while (iVar1 != 0) {
    param_1 = (int *)*param_1;
    iVar1 = *param_1;
  }
  while( true ) {
    if (param_2 == 0) {
      return;
    }
    uVar2 = param_1[1];
    if (0x7b < uVar2) break;
    if (0x7c < (int)*(sword *)(param_2 + 8) + (int)*(sword *)(param_1 + 2) + uVar2) break;
    _bcopy(*(int *)(param_2 + 4) + param_2,(int)param_1 + (int)*(sword *)(param_1 + 2) + uVar2,
           (int)*(sword *)(param_2 + 8));
    *(sword *)(param_1 + 2) = *(sword *)(param_2 + 8) + *(sword *)(param_1 + 2);
    param_2 = _m_free(param_2);
  }
  *param_1 = param_2;
  return;
}

