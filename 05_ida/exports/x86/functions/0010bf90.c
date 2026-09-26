/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x10bf90. */
void sub_10BF90()
{
  int v0; // eax
  int v1; // ebx

  if ( log_open ) /*0x10bf9b*/
  {
    v0 = splhigh(); /*0x10bf9d*/
    v1 = dword_1E97C4; /*0x10bfa2*/
    dword_1E97C4 = 0; /*0x10bfa8*/
    splx(v0); /*0x10bfb3*/
    if ( v1 ) /*0x10bfbd*/
    {
      selwakeup(v1, 0); /*0x10bfc2*/
      thread_deallocate_interrupt(v1); /*0x10bfc8*/
    }
    if ( (logsoftc & 4) != 0 ) /*0x10bfd7*/
      gsignal((_DWORD *)dword_1E97C8, (char *)0x17); /*0x10bfe2*/
    if ( (logsoftc & 8) != 0 ) /*0x10bff1*/
    {
      wakeup(pmsgbuf); /*0x10bffa*/
      logsoftc &= ~8u; /*0x10bfff*/
    }
  }
}
