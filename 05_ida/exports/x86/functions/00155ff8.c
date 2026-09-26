/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x155ff8. */
int __cdecl port_deallocate(unsigned int a1, unsigned int a2)
{
  int v3; // [esp+8h] [ebp-Ch] BYREF
  int v4; // [esp+Ch] [ebp-8h] BYREF
  int *v5; // [esp+10h] [ebp-4h] BYREF

  if ( !a1 || ipc_right_lookup_write(a1, a2, &v5) || ipc_right_info(a1, a2, v5, &v4, &v3) ) /*0x15602a*/
    return 4; /*0x156036*/
  if ( (v4 & 0x170000) != 0 ) /*0x156044*/
  {
    ipc_right_destroy(a1, a2, (int)v5); /*0x15604c*/
    return 0; /*0x156051*/
  }
  else
  {
    _InterlockedExchange((volatile __int32 *)(a1 + 8), 0); /*0x15605a*/
    return 4; /*0x15605d*/
  }
}
