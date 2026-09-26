/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x156600. */
int __cdecl port_insert_receive(unsigned int a1, unsigned int a2, unsigned int a3)
{
  int result; // eax

  if ( !a1 || !a3 || a3 == -1 || !a2 || a2 == -1 ) /*0x156620*/
    return 4; /*0x15662a*/
  result = ipc_object_copyout_name_compat(a1, a2, 16, a3); /*0x156631*/
  if ( result != 6 ) /*0x156639*/
  {
    if ( result <= 6 ) /*0x15663b*/
    {
      if ( !result ) /*0x156652*/
        return result; /*0x156652*/
    }
    else
    {
      if ( result == 13 ) /*0x156640*/
        return result; /*0x156640*/
      if ( result == 21 ) /*0x156645*/
        return 5; /*0x15664f*/
    }
    return 4; /*0x156654*/
  }
  return result; /*0x156629*/
}
