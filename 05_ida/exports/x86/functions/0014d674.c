/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x14d674. */
int __cdecl ipc_pset_alloc_name(unsigned int a1, unsigned int a2, _DWORD *a3)
{
  int result; // eax
  int v4; // eax
  int v5; // [esp+8h] [ebp-4h] BYREF

  result = ipc_object_alloc_name(a1, 1, 0x80000, 0, a2, &v5); /*0x14d694*/
  if ( !result ) /*0x14d69e*/
  {
    v4 = v5; /*0x14d6a0*/
    *(_DWORD *)(v5 + 12) = a2; /*0x14d6a3*/
    ipc_mqueue_init((_DWORD *)(v4 + 16)); /*0x14d6aa*/
    *a3 = v5; /*0x14d6b2*/
    return 0; /*0x14d6b4*/
  }
  return result; /*0x14d6b9*/
}
