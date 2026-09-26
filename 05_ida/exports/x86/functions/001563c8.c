/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1563c8. */
int __cdecl port_set_deallocate(unsigned int a1, unsigned int a2)
{
  int result; // eax
  int *v3; // [esp+8h] [ebp-4h] BYREF

  if ( !a1 ) /*0x1563d8*/
    return 4; /*0x1563da*/
  result = ipc_right_lookup_write(a1, a2, &v3); /*0x1563ea*/
  if ( !result ) /*0x1563f4*/
  {
    if ( (*((_BYTE *)v3 + 2) & 8) != 0 ) /*0x1563fd*/
    {
      return ipc_right_destroy(a1, a2, (int)v3); /*0x156402*/
    }
    else
    {
      _InterlockedExchange((volatile __int32 *)(a1 + 8), 0); /*0x15640e*/
      return 4; /*0x156411*/
    }
  }
  return result; /*0x156419*/
}
