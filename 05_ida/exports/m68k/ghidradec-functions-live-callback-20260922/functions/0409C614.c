
void sub_409C614(void)

{
  word wVar1;
  int unaff_A6;
  
  wVar1 = *(word *)(unaff_A6 + -0xe4);
  if (((wVar1 & 0x20) != 0) && (((wVar1 & 0x10) == 0 || ((wVar1 & 0x7f) == 0x38)))) {
    *(undefined *)(unaff_A6 + -0x48) = 0xff;
    return;
  }
  *(undefined *)(unaff_A6 + -0x48) = 0;
  return;
}

