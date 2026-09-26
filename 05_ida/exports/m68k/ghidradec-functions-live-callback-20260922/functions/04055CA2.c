
void _zchange(int param_1,char param_2,byte param_3,byte param_4,int param_5)

{
  *(byte *)(param_1 + 0x28) =
       *(byte *)(param_1 + 0x28) & 0x1f | param_2 << 7 | (param_3 & 1) << 6 | (param_4 & 1) << 5;
  if (param_5 == 0) {
    *(undefined8 **)(param_1 + 0x32) = &__zone_default_space;
  }
  if (*(char *)(param_1 + 0x28) < '\0') {
    _lock_init(param_1 + 0x2a,1);
  }
  return;
}

