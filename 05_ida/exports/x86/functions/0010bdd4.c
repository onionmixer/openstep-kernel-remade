/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x10bdd4. */
int logclose()
{
  int v0; // ebx
  int v1; // eax
  int v2; // ebx
  int result; // eax

  log_open = 0; /*0x10bdd8*/
  v0 = dword_1E97CC; /*0x10bde2*/
  dword_1E97CC = 0; /*0x10bde8*/
  calloutEntryRemove(v0); /*0x10bdf3*/
  calloutEntryFree(v0); /*0x10bdf9*/
  logsoftc = 0; /*0x10bdfe*/
  v1 = splhigh(); /*0x10be08*/
  v2 = dword_1E97C4; /*0x10be0d*/
  dword_1E97C4 = 0; /*0x10be13*/
  result = splx(v1); /*0x10be1e*/
  if ( v2 ) /*0x10be28*/
    result = thread_deallocate(v2); /*0x10be2b*/
  dword_1E97C8 = 0; /*0x10be30*/
  return result; /*0x10be3a*/
}
