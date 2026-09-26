
undefined2 * _sonewconn(undefined2 *param_1)

{
  int iVar1;
  int iVar2;
  undefined2 *puVar3;
  
  iVar1 = (sword)param_1[0x10] * 3;
  if (iVar1 < 0) {
    iVar1 = iVar1 + 1;
  }
  if (((int)(sword)param_1[0xc] + (int)(sword)param_1[0xf] <= iVar1 >> 1) &&
     (iVar1 = _m_getclr(0,3), iVar1 != 0)) {
    puVar3 = (undefined2 *)(*(int *)(iVar1 + 4) + iVar1);
    *puVar3 = *param_1;
    puVar3[1] = param_1[1] & 0xfffd;
    puVar3[2] = param_1[2];
    puVar3[3] = param_1[3] | 1;
    *(undefined4 *)(puVar3 + 6) = *(undefined4 *)(param_1 + 6);
    puVar3[0x27] = param_1[0x27];
    puVar3[0x2a] = param_1[0x2a];
    _soqinsque(param_1,puVar3,0);
    iVar2 = (**(code **)(*(int *)(puVar3 + 6) + 0x1a))(puVar3,0,0,0,0);
    if (iVar2 == 0) {
      return puVar3;
    }
    if (*(int *)(puVar3 + 8) != 0) {
      _soqremque(puVar3,0);
    }
    _m_free(iVar1);
  }
  return (undefined2 *)0x0;
}
