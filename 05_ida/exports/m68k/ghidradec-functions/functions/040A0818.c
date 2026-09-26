
float10 sgetman(void)

{
  undefined (*in_A0) [12];
  
  *(word *)*in_A0 = (*(word *)*in_A0 | 0x7fff) & 0xbfff;
  return (float10)*in_A0;
}
