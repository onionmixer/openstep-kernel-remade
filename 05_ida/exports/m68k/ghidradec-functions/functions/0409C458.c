
void uns_getop(void)

{
  int unaff_A6;
  
  if ((*(byte *)(unaff_A6 + -0xe4) & 0x20) != 0) {
    return;
  }
  if (((*(byte *)(unaff_A6 + -0xe4) & 0x40) != 0) &&
     ((byte)((uint)(*(int *)(unaff_A6 + -0xe4) << 3) >> 0x1d) == 3)) {
    return;
  }
  sub_409C614();
  if ((*(char *)(unaff_A6 + -0x48) != '\0') && ((*(byte *)(unaff_A6 + -0xe0) & 0x80) != 0)) {
    func_0x0409c4ee();
    return;
  }
  return;
}
