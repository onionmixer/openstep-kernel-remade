/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x15637c. */
int __cdecl port_set_allocate(int a1, _DWORD *a2)
{
  int v3; // eax
  int v4; // ecx
  volatile __int32 *v5; // [esp+4h] [ebp-4h] BYREF

  if ( !a1 ) /*0x156388*/
    return 4; /*0x15638a*/
  v3 = ipc_pset_alloc(a1, a2, &v5); /*0x15639d*/
  v4 = v3; /*0x1563a2*/
  if ( v3 ) /*0x1563a6*/
  {
    if ( v3 != 6 ) /*0x1563b7*/
      return 4; /*0x1563b9*/
  }
  else
  {
    _InterlockedExchange(v5, 0); /*0x1563ad*/
  }
  return v4; /*0x1563c0*/
}
