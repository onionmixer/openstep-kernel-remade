
/* WARNING: Removing unreachable block (ram,0x0409b91c) */

void sslognp1(void)

{
  float10 *in_A0;
  
  if (*in_A0 - (float10)-1 == FLOAT_UNKNOWN || *in_A0 - (float10)-1 < FLOAT_UNKNOWN) {
    t_operr();
    return;
  }
  slognp1();
  return;
}
