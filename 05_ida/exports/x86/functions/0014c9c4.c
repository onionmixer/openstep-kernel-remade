/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x14c9c4. */
int __cdecl ipc_port_alloc(int a1, _DWORD *a2, _DWORD *a3)
{
  int result; // eax
  _DWORD *v4; // ebx
  int v5; // eax
  _DWORD *v6; // [esp+Ch] [ebp-8h] BYREF
  int v7; // [esp+10h] [ebp-4h] BYREF

  result = ipc_object_alloc(a1, 0, 0x20000, 0, &v7, (int *)&v6); /*0x14c9e5*/
  if ( !result ) /*0x14c9ef*/
  {
    v4 = v6; /*0x14c9f1*/
    v5 = v7; /*0x14c9f4*/
    v6[3] = a1; /*0x14c9f7*/
    v4[4] = v5; /*0x14c9fa*/
    v4[6] = 0; /*0x14c9fd*/
    v4[7] = 0; /*0x14ca04*/
    v4[8] = 0; /*0x14ca0b*/
    v4[9] = 0; /*0x14ca12*/
    v4[10] = 0; /*0x14ca19*/
    v4[11] = 0; /*0x14ca20*/
    v4[12] = 0; /*0x14ca27*/
    v4[13] = 0; /*0x14ca2e*/
    v4[14] = 0; /*0x14ca35*/
    v4[15] = 5; /*0x14ca3c*/
    ipc_mqueue_init(v4 + 16); /*0x14ca47*/
    v4[19] = 0; /*0x14ca4c*/
    *a2 = v7; /*0x14ca56*/
    *a3 = v6; /*0x14ca5e*/
    return 0; /*0x14ca60*/
  }
  return result; /*0x14ca65*/
}
