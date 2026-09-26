
byte _intr_enbl(void)

{
  byte in_IF;
  
  return in_IF & 1;
}

