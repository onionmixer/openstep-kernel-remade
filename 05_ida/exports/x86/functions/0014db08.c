/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x14db08. */
int __cdecl ipc_right_lookup_write(int a1, unsigned int a2, int **a3)
{
  volatile __int32 *v3; // edx
  int *v5; // eax

  v3 = (volatile __int32 *)(a1 + 8); /*0x14db13*/
  do /*0x14db2a*/
  {
    while ( *v3 ) /*0x14db18*/
      ; /*0x14db1a*/
  }
  while ( _InterlockedExchange(v3, 1) == 1 ); /*0x14db2a*/
  if ( *(_DWORD *)(a1 + 12) ) /*0x14db2c*/
  {
    v5 = ipc_entry_lookup((_DWORD *)a1, a2); /*0x14db45*/
    if ( v5 ) /*0x14db4c*/
    {
      *a3 = v5; /*0x14db4e*/
      return 0; /*0x14db50*/
    }
    else
    {
      _InterlockedExchange((volatile __int32 *)(a1 + 8), 0); /*0x14db56*/
      return 15; /*0x14db59*/
    }
  }
  else
  {
    _InterlockedExchange((volatile __int32 *)(a1 + 8), 0); /*0x14db34*/
    return 16; /*0x14db37*/
  }
}
