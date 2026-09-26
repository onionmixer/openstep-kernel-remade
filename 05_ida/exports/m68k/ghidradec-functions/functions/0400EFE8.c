
undefined4 _ttycheckoutq(int param_1,int param_2)

{
  int iVar1;
  
  iVar1 = (int)*(sword *)(_tthiwat + (*(byte *)(param_1 + 0x48) & 0x1f) * 2);
  if ((iVar1 + 200 < *(int *)(param_1 + 0x18)) && (iVar1 < *(int *)(param_1 + 0x18))) {
    do {
      _ttstart(param_1);
      if (param_2 == 0) {
        return 0;
      }
      *(uint *)(param_1 + 0x3e) = *(uint *)(param_1 + 0x3e) | 0x40;
      _sleep((int *)(param_1 + 0x18),0x1d);
    } while (iVar1 < *(int *)(param_1 + 0x18));
  }
  return 1;
}
