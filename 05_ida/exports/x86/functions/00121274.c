/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x121274. */
int netisr_thread_continue()
{
  int v0; // eax
  int v1; // eax

  splnet(); /*0x121277*/
  while ( netisr ) /*0x121283*/
  {
    v0 = netisr; /*0x121285*/
    if ( (netisr & 4) != 0 ) /*0x12128c*/
    {
      LOBYTE(v0) = netisr & 0xFB; /*0x12128e*/
      netisr = v0; /*0x121290*/
      ipintr(); /*0x121295*/
    }
    v1 = netisr; /*0x12129a*/
    if ( (netisr & 1) != 0 ) /*0x1212a1*/
    {
      LOBYTE(v1) = netisr & 0xFE; /*0x1212a3*/
      netisr = v1; /*0x1212a5*/
      rawintr(); /*0x1212aa*/
    }
  }
  assert_wait(&soft_net_wakeup, 0); /*0x1212bb*/
  return thread_block_with_continuation(netisr_thread_continue); /*0x1212cc*/
}
