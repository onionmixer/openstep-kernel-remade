
void mem_write(void)

{
  int in_D0;
  undefined *in_A0;
  undefined *in_A1;
  int unaff_A6;
  
  if ((*(byte *)(unaff_A6 + 4) & 0x20) != 0) {
    do {
      *in_A1 = *in_A0;
      in_D0 = in_D0 + -1;
      in_A0 = in_A0 + 1;
      in_A1 = in_A1 + 1;
    } while (in_D0 != 0);
    return;
  }
  _copyoutmsg();
  return;
}
