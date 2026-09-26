
byte _intr_disbl(void)

{
  byte in_IF;
  
  return in_IF & 1;
}

