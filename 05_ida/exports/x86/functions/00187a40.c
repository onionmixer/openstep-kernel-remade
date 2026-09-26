/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x187a40. */
int clock_timer_init()
{
  unsigned int v0; // esi
  int v1; // ebx
  int v2; // ebx
  int v4; // [esp+Ch] [ebp-14h]
  unsigned __int64 v5; // [esp+10h] [ebp-10h]
  int v6[2]; // [esp+18h] [ebp-8h] BYREF

  intr_register_irq(0, system_timer_dispatch, 0, 6); /*0x187a54*/
  intr_enable_irq(0); /*0x187a5b*/
  v6[1] = 0; /*0x187a60*/
  readtodc(v6); /*0x187a6b*/
  time_of_boot = timeval_to_ns_time(v6); /*0x187a7a*/
  v4 = splusclock(); /*0x187a8b*/
  __outbyte(0x43u, 0x34u); /*0x187a9a*/
  _InterlockedIncrement(&dword_1E75C4); /*0x187a9b*/
  v5 = 10000000; /*0x187aa8*/
  v0 = 1193167; /*0x187ab4*/
  v1 = 0; /*0x187ab9*/
  while ( v5 > 1 ) /*0x187ae5*/
  {
    v5 /= 0xAu; /*0x187ad2*/
    ++v1; /*0x187ad8*/
  }
  if ( !(_DWORD)v5 ) /*0x187aeb*/
    panic(aClockTimerCons); /*0x187af8*/
  v2 = 9 - v1; /*0x187b07*/
  if ( (unsigned int)v2 > 5 ) /*0x187b0c*/
    panic(aClockTimerCons_0); /*0x187b13*/
  while ( v2 > 0 ) /*0x187b30*/
  {
    v0 /= 0xAu; /*0x187b2b*/
    --v2; /*0x187b2d*/
  }
  if ( v0 > 0xFFFF ) /*0x187b38*/
    panic(aClockTimerCons_1); /*0x187b3f*/
  word_1E75D8 = v0; /*0x187b47*/
  word_1E75DA = v0; /*0x187b50*/
  __outbyte(0x40u, v0); /*0x187b67*/
  _InterlockedIncrement(&dword_1E75C4); /*0x187b68*/
  __outbyte(0x40u, HIBYTE(word_1E75D8)); /*0x187b7c*/
  _InterlockedIncrement(&dword_1E75C4); /*0x187b7d*/
  return splx(v4); /*0x187b90*/
}
