
int _stillopen(word param_1,int param_2)

{
  undefined4 *puVar1;
  int iVar2;
  
  iVar2 = 0;
  for (puVar1 = *(undefined4 **)(_stable + ((uint)(byte)param_1 + (uint)(param_1 >> 8) & 0xf) * 4);
      puVar1 != (undefined4 *)0x0; puVar1 = (undefined4 *)*puVar1) {
    if ((param_1 == *(word *)(puVar1 + 0x10)) && (param_2 == puVar1[0xb])) {
      iVar2 = *(int *)((int)puVar1 + 0x62) + iVar2;
    }
  }
  return -(int)-(iVar2 != 0);
}

