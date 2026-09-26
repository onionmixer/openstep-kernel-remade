
void dest_dbl(void)

{
  uint uVar1;
  uint *in_A1;
  
  if (*(sword *)in_A1 == 0x7fff) {
    uVar1 = 0x7ff00000;
    in_A1[1] = 0;
    if (*(char *)((int)in_A1 + 2) != '\0') {
      uVar1 = 0xfff00000;
    }
    *in_A1 = uVar1;
  }
  else {
    uVar1 = (uint)(word)(*(sword *)in_A1 + 0xc400) << 0x14;
    if (*(char *)((int)in_A1 + 2) != '\0') {
      uVar1 = uVar1 | 0x80000000;
    }
    *in_A1 = (in_A1[1] & 0x7fffffff) >> 0xb | uVar1;
    in_A1[1] = in_A1[1] << 0x15;
    in_A1[1] = in_A1[2] >> 0xb | in_A1[1];
  }
  mem_write();
  return;
}
