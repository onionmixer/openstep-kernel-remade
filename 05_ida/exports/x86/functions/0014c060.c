/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x14c060. */
int __cdecl ipc_object_rename(unsigned int a1, unsigned int a2, unsigned int a3)
{
  int result; // eax
  int *v4; // eax
  unsigned int *v5; // [esp+Ch] [ebp-4h] BYREF

  result = ipc_entry_alloc_name(a1, a3, &v5); /*0x14c078*/
  if ( !result ) /*0x14c082*/
  {
    if ( ipc_right_inuse(a1, a3, v5) ) /*0x14c08a*/
    {
      return 13; /*0x14c096*/
    }
    else if ( a2 != a3 && (v4 = ipc_entry_lookup((_DWORD *)a1, a2)) != nullptr ) /*0x14c0b0*/
    {
      return ipc_right_rename(a1, a2, v4, a3, v5); /*0x14c0d4*/
    }
    else
    {
      ipc_entry_dealloc((_DWORD *)a1, a3, (int *)v5); /*0x14c0b8*/
      _InterlockedExchange((volatile __int32 *)(a1 + 8), 0); /*0x14c0bf*/
      return 15; /*0x14c0c2*/
    }
  }
  return result; /*0x14c0dc*/
}
