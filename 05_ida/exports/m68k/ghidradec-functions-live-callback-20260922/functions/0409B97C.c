
void sslognd(void)

{
  byte *in_A0;
  
  if ((*in_A0 & 0x80) != 0) {
    t_operr();
    return;
  }
  return;
}

