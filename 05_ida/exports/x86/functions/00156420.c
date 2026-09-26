/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x156420. */
int __cdecl port_set_add(unsigned int a1, unsigned int a2, unsigned int a3)
{
  int v3; // edx
  int v5; // esi
  int *v6; // eax
  int v7; // [esp+8h] [ebp-Ch] BYREF
  int v8; // [esp+Ch] [ebp-8h] BYREF
  int *v9; // [esp+10h] [ebp-4h] BYREF

  if ( !a1 || ipc_right_lookup_write(a1, a3, &v9) || ipc_right_info(a1, a3, v9, &v8, &v7) ) /*0x156452*/
    return 4; /*0x15645c*/
  v3 = v8; /*0x15645e*/
  if ( (v8 & 0x20000) == 0 ) /*0x156467*/
  {
    _InterlockedExchange((volatile __int32 *)(a1 + 8), 0); /*0x15646b*/
    if ( (v3 & 0x170000) != 0 ) /*0x156474*/
      return 7; /*0x15647b*/
    return 4; /*0x156474*/
  }
  v5 = v9[1]; /*0x156483*/
  v6 = ipc_entry_lookup((_DWORD *)a1, a2); /*0x15648b*/
  v9 = v6; /*0x156490*/
  if ( !v6 || (*((_BYTE *)v6 + 2) & 8) == 0 ) /*0x15649e*/
  {
    _InterlockedExchange((volatile __int32 *)(a1 + 8), 0); /*0x1564a2*/
    return 4; /*0x1564aa*/
  }
  return ipc_pset_move(a1, v5, v6[1]); /*0x1564ba*/
}
