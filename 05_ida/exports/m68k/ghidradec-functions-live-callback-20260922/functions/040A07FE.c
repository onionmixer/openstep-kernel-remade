
float10 sgetexpd(void)

{
  byte *in_A0;
  sword *extraout_A0;
  
  *in_A0 = *in_A0 & 0x7f;
  nrm_set();
  return (float10)(*extraout_A0 + -0x3fff);
}

