
void pwrten(void)

{
  int in_D1;
  uint *in_A0;
  
  if (in_D1 < 0) {
    in_D1 = -in_D1;
    *in_A0 = *in_A0 | 0x40000000;
  }
  do {
    in_D1 = in_D1 >> 1;
  } while (in_D1 != 0);
  return;
}

