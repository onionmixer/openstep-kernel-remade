/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x10ca6c. */
void __noreturn panic(const char *a1, ...)
{
  int v1; // ebx

  v1 = 0; /*0x10ca74*/
  do /*0x10ca91*/
  {
    while ( panic_lock ) /*0x10ca7f*/
      ; /*0x10ca7d*/
  }
  while ( _InterlockedExchange(&panic_lock, 1) == 1 ); /*0x10ca91*/
  if ( panicstr ) /*0x10ca9a*/
  {
    if ( paniccpu ) /*0x10caa3*/
    {
      _InterlockedExchange(&panic_lock, 0); /*0x10caae*/
      halt_cpu(); /*0x10cab4*/
    }
    else
    {
      LOBYTE(v1) = 4; /*0x10caa5*/
    }
  }
  else
  {
    panicstr = (int)a1; /*0x10cabc*/
    paniccpu = 0; /*0x10cac2*/
  }
  _InterlockedExchange(&panic_lock, 0); /*0x10cace*/
  printf("panic: (Cpu %d) %s\n", paniccpu, a1);
  printf("panic: %s\n", version);
  mini_mon(aPanic, aSystemPanic, boothowto); /*0x10cb06*/
  boot(0, v1, (int)&unk_1DAC66); /*0x10cb16*/
}
