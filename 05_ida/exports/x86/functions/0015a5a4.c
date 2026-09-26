/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x15a5a4. */
void __cdecl object_copyout(int a1, int a2, int a3, _DWORD *a4)
{
  int v4; // ebx

  if ( !a2 ) /*0x15a5b5*/
    panic(aObjectCopyout); /*0x15a5bc*/
  if ( a3 == 5 ) /*0x15a5c7*/
    v4 = 16; /*0x15a5c9*/
  else
    v4 = 17; /*0x15a5d0*/
  if ( ipc_object_copyout_compat(*(_DWORD *)(a1 + 136), a2, v4, a4) ) /*0x15a5e6*/
    *a4 = 0; /*0x15a5ef*/
}
