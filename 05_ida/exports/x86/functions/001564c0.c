/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1564c0. */
int __cdecl port_set_remove(unsigned int a1, unsigned int a2)
{
  int v2; // edx
  int v4; // [esp+8h] [ebp-Ch] BYREF
  int v5; // [esp+Ch] [ebp-8h] BYREF
  int *v6; // [esp+10h] [ebp-4h] BYREF

  if ( !a1 || ipc_right_lookup_write(a1, a2, &v6) || ipc_right_info(a1, a2, v6, &v5, &v4) ) /*0x1564f2*/
    return 4; /*0x156525*/
  v2 = v5; /*0x1564fe*/
  if ( (v5 & 0x20000) == 0 ) /*0x156507*/
  {
    _InterlockedExchange((volatile __int32 *)(a1 + 8), 0); /*0x15650b*/
    if ( (v2 & 0x170000) != 0 ) /*0x156514*/
      return 7; /*0x15651b*/
    return 4; /*0x156514*/
  }
  return ipc_pset_move(a1, v6[1], 0); /*0x15653a*/
}
