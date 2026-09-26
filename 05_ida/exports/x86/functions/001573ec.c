/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1573ec. */
int __cdecl exception_parse_reply(_DWORD *a1)
{
  int v2; // ebx

  if ( a1[5] == 18 && a1[6] == 32 && a1[10] == 2500 && a1[11] == exc_code_proto ) /*0x157410*/
  {
    v2 = a1[12]; /*0x157428*/
    if ( a1[2] != 256 || ipc_kmsg_cache ) /*0x15743b*/
    {
      if ( (int)a1[2] > 0 ) /*0x157459*/
        kfree((int)a1, a1[2]); /*0x15744a*/
      else
        ipc_kmsg_free((int)a1); /*0x15745c*/
    }
    else
    {
      ipc_kmsg_cache = (int)a1; /*0x15743d*/
    }
    return v2; /*0x157461*/
  }
  else
  {
    a1[7] = 0; /*0x157412*/
    ipc_kmsg_destroy(a1); /*0x15741a*/
    return -301; /*0x15741f*/
  }
}
