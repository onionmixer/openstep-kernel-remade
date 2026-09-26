/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x14d61c. */
int __cdecl ipc_pset_alloc(int a1, _DWORD *a2, _DWORD *a3)
{
  int result; // eax
  int v4; // eax
  int v5; // [esp+8h] [ebp-8h] BYREF
  int v6; // [esp+Ch] [ebp-4h] BYREF

  result = ipc_object_alloc(a1, 1, 0x80000, 0, &v6, &v5); /*0x14d63f*/
  if ( !result ) /*0x14d649*/
  {
    v4 = v5; /*0x14d64b*/
    *(_DWORD *)(v5 + 12) = v6; /*0x14d651*/
    ipc_mqueue_init((_DWORD *)(v4 + 16)); /*0x14d658*/
    *a2 = v6; /*0x14d660*/
    *a3 = v5; /*0x14d665*/
    return 0; /*0x14d667*/
  }
  return result; /*0x14d66c*/
}
