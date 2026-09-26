
void dest_sgl(void)

{
  uint uVar1;
  int in_A0;
  sword *in_A1;
  int unaff_A6;
  
  if (*in_A1 == 0x7fff) {
    uVar1 = 0x7f800000;
    if (*(char *)(in_A1 + 1) != '\0') {
      uVar1 = 0xff800000;
    }
  }
  else {
    uVar1 = (uint)(word)(*in_A1 + 0xc080) << 0x17;
    if (*(char *)(in_A1 + 1) != '\0') {
      uVar1 = uVar1 | 0x80000000;
    }
    uVar1 = (*(uint *)(in_A1 + 2) & 0x7fffffff) >> 8 | uVar1;
  }
  *(uint *)(unaff_A6 + -0x54) = uVar1;
  if (in_A0 != 0) {
    mem_write();
    return;
  }
  get_fline();
  reg_dest();
  return;
}

