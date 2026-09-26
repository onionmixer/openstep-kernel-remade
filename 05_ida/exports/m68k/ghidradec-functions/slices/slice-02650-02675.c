/* GHIDRADEC_FUNCTION index=2650 start=0x409b97c */

void sslognd(void)

{
  byte *in_A0;
  
  if ((*in_A0 & 0x80) != 0) {
    t_operr();
    return;
  }
  return;
}
/* GHIDRADEC_FUNCTION index=2651 start=0x409b98e */

float10 sslog10(void)

{
  byte *in_A0;
  float10 in_FP0;
  
  if ((*in_A0 & 0x80) != 0) {
    return in_FP0;
  }
  if (((*(sword *)in_A0 == 0x3fff) && (*(int *)(in_A0 + 4) == -0x80000000)) &&
     (*(int *)(in_A0 + 8) == 0)) {
    return (float10)tbyte_409B7BC;
  }
  return in_FP0;
}
/* GHIDRADEC_FUNCTION index=2652 start=0x409b9c8 */

void sslog10d(void)

{
  byte *in_A0;
  
  if ((*in_A0 & 0x80) != 0) {
    t_operr();
    return;
  }
  return;
}
/* GHIDRADEC_FUNCTION index=2653 start=0x409b9da */

float10 sslog2(void)

{
  byte *in_A0;
  float10 in_FP0;
  
  if ((*in_A0 & 0x80) != 0) {
    return in_FP0;
  }
  if (((*(sword *)in_A0 == 0x3fff) && (*(int *)(in_A0 + 4) == -0x80000000)) &&
     (*(int *)(in_A0 + 8) == 0)) {
    return (float10)tbyte_409B7BC;
  }
  return in_FP0;
}
/* GHIDRADEC_FUNCTION index=2654 start=0x409ba14 */

void sslog2d(void)

{
  byte *in_A0;
  
  if ((*in_A0 & 0x80) != 0) {
    t_operr();
    return;
  }
  return;
}
/* GHIDRADEC_FUNCTION index=2655 start=0x409ba66 */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Control flow encountered unimplemented instructions */

void pmod(void)

{
  int unaff_A6;
  
  switch((byte)((uint)*(undefined4 *)(unaff_A6 + -0xe8) >> 0x1d) & 0xfb |
         ((byte)((uint)*(undefined4 *)(unaff_A6 + -0xe0) >> 0x1d) & 0xfb) << 2) {
  case :
    return;
  case :
  case :
  case :
  case :
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
  case :
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
  case :
  case :
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
  case :
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
  case :
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
  case :
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
  case :
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
  case :
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
  case :
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
  case :
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
  case :
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
  case :
  case :
  case :
  case :
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
    return;
  case :
  case :
  case :
  case :
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
  case :
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
  case :
  case :
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
  case :
    return;
  case :
  case :
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
  case :
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
  case :
  case :
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
  case :
  case :
  case :
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
  case :
  case :
  case :
  case :
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
  case :
                    /* WARNING: Unimplemented instruction - Truncating control flow here */
    halt_unimplemented();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Unimplemented instruction - Truncating control flow here */
    halt_unimplemented();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Unimplemented instruction - Truncating control flow here */
    halt_unimplemented();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Unimplemented instruction - Truncating control flow here */
    halt_unimplemented();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
  case :
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
  case :
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
    return;
  case :
  case :
  case :
    return;
  case :
  case :
    return;
  case :
  case :
    return;
  case :
    return;
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
  case :
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
}
/* GHIDRADEC_FUNCTION index=2656 start=0x409bb42 */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Control flow encountered unimplemented instructions */

void prem(void)

{
  int unaff_A6;
  
  switch((byte)((uint)*(undefined4 *)(unaff_A6 + -0xe8) >> 0x1d) & 0xfb |
         ((byte)((uint)*(undefined4 *)(unaff_A6 + -0xe0) >> 0x1d) & 0xfb) << 2) {
  case :
    return;
  case :
  case :
  case :
  case :
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
  case :
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
  case :
  case :
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
  case :
  case :
  case :
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
  case :
    return;
  case :
  case :
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
  case :
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
  case :
  case :
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
  case :
  case :
  case :
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
  case :
  case :
  case :
  case :
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
  case :
                    /* WARNING: Unimplemented instruction - Truncating control flow here */
    halt_unimplemented();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Unimplemented instruction - Truncating control flow here */
    halt_unimplemented();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Unimplemented instruction - Truncating control flow here */
    halt_unimplemented();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Unimplemented instruction - Truncating control flow here */
    halt_unimplemented();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
  case :
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
  case :
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
    return;
  case :
  case :
  case :
    return;
  case :
  case :
    return;
  case :
  case :
    return;
  case :
    return;
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
  case :
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
  case :
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
  case :
  case :
  case :
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
    return;
  case :
    return;
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
}
/* GHIDRADEC_FUNCTION index=2657 start=0x409bc1e */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Control flow encountered unimplemented instructions */

void pscale(void)

{
  int unaff_A6;
  
  switch((byte)((uint)*(undefined4 *)(unaff_A6 + -0xe8) >> 0x1d) & 0xfb |
         ((byte)((uint)*(undefined4 *)(unaff_A6 + -0xe0) >> 0x1d) & 0xfb) << 2) {
  case :
  case :
    return;
  case :
  case :
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
  case :
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
  case :
  case :
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
  case :
  case :
  case :
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
  case :
  case :
  case :
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
  case :
  case :
  case :
  case :
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
  case :
                    /* WARNING: Unimplemented instruction - Truncating control flow here */
    halt_unimplemented();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Unimplemented instruction - Truncating control flow here */
    halt_unimplemented();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Unimplemented instruction - Truncating control flow here */
    halt_unimplemented();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Unimplemented instruction - Truncating control flow here */
    halt_unimplemented();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
  case :
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
  case :
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
    return;
  case :
  case :
  case :
    return;
  case :
  case :
    return;
  case :
  case :
    return;
  case :
    return;
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
  case :
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
  case :
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
  case :
  case :
  case :
  case :
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
    return;
  case :
    return;
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
}
/* GHIDRADEC_FUNCTION index=2658 start=0x409bc78 */

void ssincosz(void)

{
  sto_cos();
  return;
}
/* GHIDRADEC_FUNCTION index=2659 start=0x409bca8 */

void ssincosi(void)

{
  sto_cos();
  t_operr();
  return;
}
/* GHIDRADEC_FUNCTION index=2660 start=0x409bcc4 */

void ssincosnan(void)

{
  int unaff_A6;
  
  *(undefined4 *)(unaff_A6 + -0x74) = *(undefined4 *)(unaff_A6 + -0xcc);
  *(undefined4 *)(unaff_A6 + -0x70) = *(undefined4 *)(unaff_A6 + -200);
  *(undefined4 *)(unaff_A6 + -0x6c) = *(undefined4 *)(unaff_A6 + -0xc4);
  *(byte *)(unaff_A6 + -0x70) = *(byte *)(unaff_A6 + -0x70) | 0x40;
  sto_cos();
  src_nan();
  return;
}
/* GHIDRADEC_FUNCTION index=2661 start=0x409bcee */

void ld_ppi2(void)

{
  t_inx2();
  return;
}
/* GHIDRADEC_FUNCTION index=2662 start=0x409bcfc */

void ld_mpi2(void)

{
  int unaff_A6;
  
  *(uint *)(unaff_A6 + -0x7c) = *(uint *)(unaff_A6 + -0x7c) | 0x8000000;
  t_inx2();
  return;
}
/* GHIDRADEC_FUNCTION index=2663 start=0x409bd12 */

float10 ld_pinf(void)

{
  float10 fVar1;
  int unaff_A6;
  
  fVar1 = (float10)tbyte_409B7D4;
  *(uint *)(unaff_A6 + -0x7c) = *(uint *)(unaff_A6 + -0x7c) | 0x2000000;
  return fVar1;
}
/* GHIDRADEC_FUNCTION index=2664 start=0x409bd24 */

float10 ld_minf(void)

{
  float10 fVar1;
  int unaff_A6;
  
  fVar1 = (float10)tbyte_409B7E0;
  *(uint *)(unaff_A6 + -0x7c) = *(uint *)(unaff_A6 + -0x7c) | 0xa000000;
  return fVar1;
}
/* GHIDRADEC_FUNCTION index=2665 start=0x409bd36 */

float10 ld_pone(void)

{
  return (float10)tbyte_409B7A4;
}
/* GHIDRADEC_FUNCTION index=2666 start=0x409bd40 */

float10 ld_mone(void)

{
  float10 fVar1;
  int unaff_A6;
  
  fVar1 = (float10)tbyte_409B7B0;
  *(uint *)(unaff_A6 + -0x7c) = *(uint *)(unaff_A6 + -0x7c) | 0x8000000;
  return fVar1;
}
/* GHIDRADEC_FUNCTION index=2667 start=0x409bd52 */

float10 ld_pzero(void)

{
  float10 fVar1;
  int unaff_A6;
  
  fVar1 = (float10)tbyte_409B7BC;
  *(uint *)(unaff_A6 + -0x7c) = *(uint *)(unaff_A6 + -0x7c) | 0x4000000;
  return fVar1;
}
/* GHIDRADEC_FUNCTION index=2668 start=0x409bd64 */

float10 ld_mzero(void)

{
  float10 fVar1;
  int unaff_A6;
  
  fVar1 = (float10)tbyte_409B7C8;
  *(uint *)(unaff_A6 + -0x7c) = *(uint *)(unaff_A6 + -0x7c) | 0xc000000;
  return fVar1;
}
/* GHIDRADEC_FUNCTION index=2669 start=0x409bd9a */

/* WARNING: Control flow encountered bad instruction data */

void gen_except(undefined4 param_1)

{
  byte bVar1;
  undefined4 *puVar2;
  sword sVar3;
  undefined *puVar4;
  undefined4 *unaff_A6;
  undefined *puVar5;
  undefined4 *puVar6;
  undefined4 *puVar7;
  undefined *puVar8;
  uint in_FPSR;
  undefined4 uVar9;
  char in_stack_00000001;
  undefined4 in_stack_00000024;
  uint in_stack_00000034;
  undefined4 in_stack_00000040;
  uint in_stack_00000048;
  undefined4 in_stack_00000058;
  undefined4 in_stack_0000005c;
  undefined4 in_stack_00000060;
  char acStack_8 [8];
  
  if (in_stack_00000001 != '\0') {
    puVar7 = (undefined4 *)register0x0000003c;
    if ((in_stack_00000001 == '(') || (in_stack_00000001 == '0')) {
      if (in_stack_00000001 == '(') {
        puVar4 = &stack0x000000ec;
      }
      else {
        if (in_stack_00000001 != '0') {
          return;
        }
        puVar4 = &stack0x000000f4;
      }
      *(undefined4 *)(puVar4 + -0xe4) = unaff_A6[-0x39];
      unaff_A6[-0x1f] = in_FPSR | unaff_A6[-0x1f];
    }
    else {
      if (in_stack_00000001 != '`') {
        return;
      }
      in_stack_00000058 = unaff_A6[-0x33];
      in_stack_0000005c = unaff_A6[-0x32];
      in_stack_00000060 = unaff_A6[-0x31];
      in_stack_00000040 = unaff_A6[-0x39];
      in_stack_00000034 =
           ((unaff_A6[-0x39] & 0x3fffff) >> 0x13) << 0x12 |
           ((unaff_A6[-0x39] & 0x7ffff) >> 0x12) << 0x15 | unaff_A6[-0x39] & 0x3c30000;
      unaff_A6[-0x1f] = in_FPSR | unaff_A6[-0x1f];
      in_stack_00000024 = unaff_A6[-0x1f];
      in_stack_00000048 = in_stack_00000048 | 0x1800000;
    }
    goto loc_409C064;
  }
  puVar6 = &param_1;
  puVar7 = &param_1;
  unaff_A6[-0x1f] = in_FPSR | unaff_A6[-0x1f];
  if (param_1._1_1_ == '`') {
    *(undefined2 *)(unaff_A6 + -0x3b) = 0;
    if ((*(byte *)(unaff_A6 + -0x39) & 0x20) == 0) {
      unaff_A6[-0x40] = unaff_A6[-0x1f];
      unaff_A6[-0x37] = unaff_A6[-0x37] | 0x1800000;
    }
  }
  else if (param_1._1_1_ != '(') {
    *(undefined2 *)(unaff_A6 + -0x3b) = 0;
  }
  bVar1 = *(byte *)((int)unaff_A6 + -0x7a) & *(byte *)((int)unaff_A6 + -0x7e);
  switch((bVar1 != 0) * (char)LZCOUNT((uint)bVar1 << 0x18) + (bVar1 == 0) * ' ') {
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
  case :
  case :
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
  case :
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
    break;
  case :
  case :
  case :
    *(byte *)(unaff_A6 + -0x37) = *(byte *)(unaff_A6 + -0x37) | 4;
    goto loc_409BF32;
  case :
  case :
loc_409BF8A:
    if (*(char *)((int)unaff_A6 + -0x47) == '\0') {
      *(char *)((int)unaff_A6 + -0x45) = param_1._0_1_;
      if (param_1._1_1_ != '`') {
        if (param_1._0_1_ == '@') {
          sVar3 = 0xd;
        }
        else {
          if (param_1._0_1_ != 'A') {
            return;
          }
          sVar3 = 0xb;
        }
        param_1 = 0;
        puVar7 = &param_1;
        do {
          puVar5 = (undefined *)puVar7;
          puVar6 = (undefined4 *)(puVar5 + -4);
          *(undefined4 *)(puVar5 + -4) = 0;
          sVar3 = sVar3 + -1;
          puVar7 = (undefined4 *)(puVar5 + -4);
        } while (sVar3 != -1);
        puVar5[-4] = *(undefined *)((int)unaff_A6 + -0x45);
        puVar5[-3] = 0x60;
      }
      unaff_A6[-0x43] = unaff_A6[-0x1d];
      unaff_A6[-0x42] = unaff_A6[-0x1c];
      unaff_A6[-0x41] = unaff_A6[-0x1b];
      *(byte *)(unaff_A6 + -0x37) = *(byte *)(unaff_A6 + -0x37) | 2;
      *(byte *)(unaff_A6 + -0x37) = *(byte *)(unaff_A6 + -0x37) & 0xfb;
      *(byte *)((int)unaff_A6 + -0xdb) = *(byte *)((int)unaff_A6 + -0xdb) & 0xdf;
      unaff_A6[-0x40] = unaff_A6[-0x1f];
      unaff_A6[-0x37] = unaff_A6[-0x37] | 0x1800000;
      unaff_A6[-0x3c] =
           ((unaff_A6[-0x39] & 0x3fffff) >> 0x13) << 0x12 |
           ((unaff_A6[-0x39] & 0x7ffff) >> 0x12) << 0x15 | unaff_A6[-0x39] & 0x3c30000;
      puVar7 = puVar6;
    }
    else {
      if (*(char *)((int)unaff_A6 + -0x46) == '\0') goto loc_409BEF6;
      *(undefined *)(unaff_A6 + -0x47) = 0;
      *(byte *)(unaff_A6 + -0x37) = *(byte *)(unaff_A6 + -0x37) | 4;
      *(undefined2 *)(unaff_A6 + -0x36) = *(undefined2 *)(unaff_A6 + -0x33);
      unaff_A6[-0x35] = unaff_A6[-0x32];
      unaff_A6[-0x34] = unaff_A6[-0x31];
      *(byte *)(unaff_A6 + -0x38) = *(byte *)(unaff_A6 + -0x38) | 0x10;
      *(byte *)((int)unaff_A6 + -0xdb) = *(byte *)((int)unaff_A6 + -0xdb) & 0xdf;
      puVar7 = &param_1;
    }
    break;
  case :
  case :
    if (*(char *)((int)unaff_A6 + -0x47) == '\0') {
      *(byte *)(unaff_A6 + -0x37) = *(byte *)(unaff_A6 + -0x37) | 2;
      *(byte *)(unaff_A6 + -0x37) = *(byte *)(unaff_A6 + -0x37) & 0xfb;
    }
    else {
loc_409BEF6:
      if (*(char *)((int)unaff_A6 + -0x49) == '\0') {
        *(byte *)(unaff_A6 + -0x37) = *(byte *)(unaff_A6 + -0x37) | 2;
      }
      *(byte *)(unaff_A6 + -0x37) = *(byte *)(unaff_A6 + -0x37) & 0xfb;
      unaff_A6[-0x3c] =
           ((unaff_A6[-0x39] & 0x3fffff) >> 0x13) << 0x12 |
           ((unaff_A6[-0x39] & 0x7ffff) >> 0x12) << 0x15 | unaff_A6[-0x39] & 0x3c30000;
    }
loc_409BF32:
    *(byte *)((int)unaff_A6 + -0xdb) = *(byte *)((int)unaff_A6 + -0xdb) & 0xdf;
    puVar7 = &param_1;
    break;
  case :
    if (((*(byte *)((int)unaff_A6 + -0x7e) & 2) != 0) &&
       ((*(byte *)((int)unaff_A6 + -0x7a) & 0x10) != 0)) goto loc_409BF8A;
    if ((*(char *)((int)unaff_A6 + -0x47) == '\0') ||
       (puVar7 = &param_1, *(char *)((int)unaff_A6 + -0x49) == '\0')) {
      uVar9 = *(undefined4 *)(unaff_A6[-0x20] + 0x18);
      goto loc_409C0E2;
    }
    break;
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
  case :
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
  case :
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
  case :
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
  case :
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
  case :
  case :
  case :
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
  case :
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
  case :
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
    return;
  case :
    return;
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
loc_409C064:
  if (*(char *)((int)puVar7 + 1) == '(') {
    sVar3 = 0xd;
loc_409C086:
    *(undefined *)((int)unaff_A6 + -0x45) = *(undefined *)puVar7;
    *puVar7 = 0;
    puVar2 = puVar7;
    do {
      puVar8 = (undefined *)puVar2;
      puVar7 = (undefined4 *)(puVar8 + -4);
      *(undefined4 *)(puVar8 + -4) = 0;
      sVar3 = sVar3 + -1;
      puVar2 = (undefined4 *)(puVar8 + -4);
    } while (sVar3 != -1);
    puVar8[-4] = *(undefined *)((int)unaff_A6 + -0x45);
    puVar8[-3] = 0x60;
    *(undefined4 *)(puVar8 + 0x14) = unaff_A6[-0x1d];
    *(undefined4 *)(puVar8 + 0x18) = unaff_A6[-0x1c];
    *(undefined4 *)(puVar8 + 0x1c) = unaff_A6[-0x1b];
    *(uint *)(puVar8 + 0x35) =
         *(uint *)(puVar8 + 0x35) & 0xf0ffffff | ((unaff_A6[-0x1f] & 0x7fff) >> 0xb) << 0x18;
    *(undefined4 *)(puVar8 + 0x20) = unaff_A6[-0x1f];
    *(uint *)(puVar8 + 0x44) = *(uint *)(puVar8 + 0x44) | 0x1800000;
  }
  else if (*(char *)((int)puVar7 + 1) == '0') {
    sVar3 = 0xb;
    goto loc_409C086;
  }
  uVar9 = *(undefined4 *)(unaff_A6[-0x20] + 0x18);
  restoreFPUStateFrame(*puVar7);
loc_409C0E2:
  if (((*(byte *)(unaff_A6 + 1) & 0x80) == 0) && ((*(byte *)(unaff_A6 + 1) & 0x40) == 0)) {
    fpsp_done();
    return;
  }
  puVar7 = unaff_A6 + 1;
  if (*(uint *)((int)unaff_A6 + 10) >> 0x1c == 0) {
    *unaff_A6 = unaff_A6[1];
    unaff_A6[1] = unaff_A6[2];
    saveFPUStateFrame(unaff_A6[-0x19]);
    unaff_A6[2] = uVar9;
    restoreFPUStateFrame(unaff_A6[-0x19]);
    puVar7 = unaff_A6;
  }
  *(undefined2 *)((int)puVar7 + 6) = 0x2024;
  real_trace();
  return;
}
/* GHIDRADEC_FUNCTION index=2670 start=0x409c44a */

void get_op(void)

{
  int unaff_A6;
  
  *(undefined *)(unaff_A6 + -0x48) = 0;
  if (*(char *)(unaff_A6 + -0x47) != '\0') {
    return;
  }
  return;
}
/* GHIDRADEC_FUNCTION index=2671 start=0x409c458 */

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
/* GHIDRADEC_FUNCTION index=2672 start=0x409c4a2 */

uint uni_getop(void)

{
  byte bVar1;
  uint uVar2;
  word wVar3;
  int unaff_A6;
  
  if (*(uint *)(unaff_A6 + -0xe4) >> 0x1a == 0x17) {
    return 0x17;
  }
  if ((*(byte *)(unaff_A6 + -0xdc) & 4) == 0) {
    bVar1 = *(byte *)(unaff_A6 + -0xe0) | *(byte *)(unaff_A6 + -0xe8);
    uVar2 = (uint)bVar1;
    if (-1 < (sword)((word)bVar1 << 8)) {
      return uVar2;
    }
    if (((*(byte *)(unaff_A6 + -0xe0) & 0x80) == 0) ||
       (uVar2 = sub_409C614(), *(char *)(unaff_A6 + -0x48) == '\0')) goto loc_409C50C;
  }
  else {
    *(undefined4 *)(unaff_A6 + -0xcc) = *(undefined4 *)(unaff_A6 + -0xd0);
    sub_409C614();
    uVar2 = sub_409C714();
    if (*(char *)(unaff_A6 + -0x48) == '\0') {
      return uVar2;
    }
    uVar2 = 1 << (7 - ((*(uint *)(unaff_A6 + -0xe4) & 0x3ffffff) >> 0x17) & 0x1f);
    fmovem(*(undefined4 *)(unaff_A6 + -0xd8),uVar2);
    if ((*(byte *)(unaff_A6 + -0xe0) & 0x80) == 0) {
      if ((*(byte *)(unaff_A6 + -0xe0) & 0xf0) != 0) {
        return CONCAT31((int3)(uVar2 >> 8),*(byte *)(unaff_A6 + -0xe0)) & 0xfffffff0;
      }
      uVar2 = CONCAT22((sword)(uVar2 >> 0x10),*(word *)(unaff_A6 + -0xd8)) & 0xffff7fff;
      if (0x3ffe < (*(word *)(unaff_A6 + -0xd8) & 0x7fff)) {
        return uVar2;
      }
      *(byte *)(unaff_A6 + -0xe0) = *(byte *)(unaff_A6 + -0xe0) | 0x10;
      return uVar2;
    }
  }
  uVar2 = CONCAT22((sword)(uVar2 >> 0x10),*(word *)(unaff_A6 + -0xd8)) & 0xffff7fff;
  if ((*(word *)(unaff_A6 + -0xd8) & 0x7fff) != 0) {
    uVar2 = sub_409C646();
    *(undefined *)(unaff_A6 + -0xe0) = *(undefined *)(unaff_A6 + -0x54);
  }
loc_409C50C:
  if ((*(byte *)(unaff_A6 + -0xe8) & 0x80) != 0) {
    if ((*(byte *)(unaff_A6 + -0xe8) & 0x20) != 0) {
      if ((*(byte *)(unaff_A6 + -0xe4) & 0x10) == 0) {
        wVar3 = 0x3f81;
      }
      else {
        wVar3 = 0x3c01;
      }
      if ((*(byte *)(unaff_A6 + -0xcc) & 0x80) != 0) {
        wVar3 = wVar3 | 0x8000;
      }
      *(word *)(unaff_A6 + -0xcc) = wVar3;
      *(word *)(unaff_A6 + -0xe4) = *(word *)(unaff_A6 + -0xe4) & 0xe3ff | 0x800;
      uVar2 = sub_409C646();
      *(undefined *)(unaff_A6 + -0xe8) = *(undefined *)(unaff_A6 + -0x54);
      return uVar2;
    }
    uVar2 = CONCAT22((sword)(uVar2 >> 0x10),*(word *)(unaff_A6 + -0xcc)) & 0xffff7fff;
    if ((*(word *)(unaff_A6 + -0xcc) & 0x7fff) != 0) {
      uVar2 = sub_409C646();
      *(undefined *)(unaff_A6 + -0xe8) = *(undefined *)(unaff_A6 + -0x54);
      return uVar2;
    }
  }
  return uVar2;
}
/* GHIDRADEC_FUNCTION index=2673 start=0x409c9b2 */

void t_dz2(void)

{
  int unaff_A6;
  
  *(byte *)(unaff_A6 + -0x7c) = *(byte *)(unaff_A6 + -0x7c) | 8;
  if ((*(byte *)(unaff_A6 + -0x7e) & 4) == 0) {
    func_0x0409c9f2();
    return;
  }
  return;
}
/* GHIDRADEC_FUNCTION index=2674 start=0x409c9d2 */

unkbyte10 t_dz(void)

{
  unkbyte10 Var1;
  int unaff_A6;
  unkbyte10 in_FP0;
  unkbyte10 Var2;
  
  Var1 = tbyte_409C982._0_10_;
  if ((*(byte *)(unaff_A6 + -0x7e) & 4) != 0) {
    if ((*(byte *)(unaff_A6 + -0xcc) & 0x80) != 0) {
      *(byte *)(unaff_A6 + -0x7c) = *(byte *)(unaff_A6 + -0x7c) | 8;
    }
    *(uint *)(unaff_A6 + -0x7c) = *(uint *)(unaff_A6 + -0x7c) | 0x2000410;
    *(undefined *)(unaff_A6 + -0x4c) = 0xff;
    return in_FP0;
  }
  Var2 = tbyte_409C98E._0_10_;
  if ((*(byte *)(unaff_A6 + -0xcc) & 0x80) != 0) {
    *(byte *)(unaff_A6 + -0x7c) = *(byte *)(unaff_A6 + -0x7c) | 8;
    Var2 = Var1;
  }
  *(uint *)(unaff_A6 + -0x7c) = *(uint *)(unaff_A6 + -0x7c) | 0x2000410;
  return Var2;
}

