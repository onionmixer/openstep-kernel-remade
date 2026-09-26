
void dest_ext(void)

{
  byte *in_A1;
  
  if (in_A1[2] != 0) {
    *in_A1 = *in_A1 | 0x80;
  }
  in_A1[2] = 0;
  mem_write();
  return;
}

