/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x15656c. */
int __cdecl port_insert_send(unsigned int a1, unsigned int a2, unsigned int a3)
{
  int result; // eax

  if ( !a1 || !a3 || a3 == -1 || !a2 || a2 == -1 ) /*0x15658c*/
    return 4; /*0x156596*/
  result = ipc_object_copyout_name_compat(a1, a2, 17, a3); /*0x15659d*/
  if ( result != 6 ) /*0x1565a5*/
  {
    if ( result <= 6 ) /*0x1565a7*/
    {
      if ( !result ) /*0x1565be*/
        return result; /*0x1565be*/
    }
    else
    {
      if ( result == 13 ) /*0x1565ac*/
        return result; /*0x1565ac*/
      if ( result == 21 ) /*0x1565b1*/
        return 5; /*0x1565bb*/
    }
    return 4; /*0x1565c0*/
  }
  return result; /*0x156595*/
}
